#include "sample2/file_ops.h"

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>


int main() {
  int fd = FileOps::open("txt", O_RDWR|O_CREAT, 0777);
  assert(fd > 0);
  int ret = FileOps::write(fd, "12345", 5);
  if (ret == -1) {
    perror("write:");
  }
  ret = FileOps::close(fd);
  assert(ret == 0);
  return 0;
}