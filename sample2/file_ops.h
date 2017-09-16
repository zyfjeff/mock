#ifndef MOCK_SAMPLE2_SYSTEM_H_
#define MOCK_SAMPLE2_SYSTEM_H_

#include <sys/types.h>

namespace FileOps {
  int  open(const char *path, int oflag, ...);
  ssize_t read(int fildes, void *buf, size_t nbyte);
  ssize_t write(int fildes, const void *buf, size_t nbyte);
  int close(int fildes);
}  // namespace FileOps

#endif  // MOCK_SAMPLE2_SYSTEM_H_