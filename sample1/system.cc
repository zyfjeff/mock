#include "sample1/system.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <assert.h>
#include <stdio.h>

namespace base {

System* System::instance_ = nullptr;
System* System::GetInstance() {
  if (!instance_) {
    instance_ = FileOps::GetInstance();
  }
  assert(instance_);
  return instance_;
}

int FileOps::open(const char *path, int oflag, ...) {
  return ::open(path, oflag, 0777);
}

ssize_t FileOps::read(int fildes, void *buf, size_t nbyte) {
  return ::read(fildes, buf, nbyte);
}

ssize_t FileOps::write(int fildes, const void *buf, size_t nbyte) {
  return ::write(fildes, buf, nbyte);
}

int FileOps::close(int fildes) {
  return ::close(fildes);
}

FileOps* FileOps::GetInstance() {
  static FileOps sys;
  return &sys;
}

}  // namespace base