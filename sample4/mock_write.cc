#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <dlfcn.h>

extern "C" ssize_t __real_write(int fildes, const void *buf, size_t nbyte);

extern "C" ssize_t __wrap_write(int fildes, const void *buf, size_t nbyte) {
  __real_write(fildes, buf, nbyte);
  errno = EIO;
  return -1;
}