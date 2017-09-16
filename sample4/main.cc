#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  int fd = ::open("txt", O_RDWR|O_CREAT, 0777);
  assert(fd > 0);
  int ret = ::write(fd, "12345", 5);
  if (ret == -1) {
    perror("write:");
  }
  ret = ::close(fd);
  assert(ret == 0);
  return 0;
}