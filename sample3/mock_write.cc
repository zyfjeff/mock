#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <dlfcn.h>


typedef ssize_t (*write_func_t)(int fildes, const void *buf, size_t nbyte);
write_func_t old_write_func =
    reinterpret_cast<write_func_t>(dlsym(RTLD_NEXT, "write"));

extern "C" ssize_t write(int fildes, const void *buf, size_t nbyte) {
  errno = EIO;
  return -1;
}