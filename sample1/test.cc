#include "sample1/system.h"

#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

using namespace base;

class MockFileOps : public System {
public:
 int open(const char *path, int oflag, ...) override;
 ssize_t read(int fildes, void *buf, size_t nbyte) override;
 ssize_t write(int fildes, const void *buf, size_t nbyte) override;
 int close(int fildes) override;
 static MockFileOps* GetInstance();
};

int MockFileOps::open(const char *path, int oflag, ...) {
  return ::open(path, oflag, 0777);
}

ssize_t MockFileOps::read(int fildes, void *buf, size_t nbyte) {
  return ::read(fildes, buf, nbyte);
}

ssize_t MockFileOps::write(int fildes, const void *buf, size_t nbyte) {
  errno = EIO;
  return -1;
}

int MockFileOps::close(int fildes) {
  return ::close(fildes);
}

MockFileOps* MockFileOps::GetInstance() {
  static MockFileOps sys;
  return &sys;
}

int main() {
  System::set_instance(MockFileOps::GetInstance());
  assert(System::GetInstance() != nullptr);
  int fd = System::GetInstance()->open("txt", O_RDWR|O_CREAT, 0777);
  assert(fd > 0);
  int ret = System::GetInstance()->write(fd, "12345", 5);
  assert(ret ==  -1);
  perror("write");
  ret = System::GetInstance()->close(fd);
  assert(ret == 0);

  return 0;
}
