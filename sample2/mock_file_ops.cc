#include "sample2/file_ops.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <assert.h>
#include <stdio.h>

namespace FileOps {

int open(const char *path, int oflag, ...) {
  return ::open(path, oflag, 0777);
}

ssize_t read(int fildes, void *buf, size_t nbyte) {
  return ::read(fildes, buf, nbyte);
}

ssize_t write(int fildes, const void *buf, size_t nbyte) {
  errno = EIO;
  return -1;
}

int close(int fildes) {
  return ::close(fildes);
}

}  // namespace FileOps