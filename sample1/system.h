#ifndef MOCK_SAMPLE1_SYSTEM_H_
#define MOCK_SAMPLE1_SYSTEM_H_

#include <sys/types.h>

namespace base {

class System {
 public:
  virtual int  open(const char *path, int oflag, ...) = 0;
  virtual ssize_t read(int fildes, void *buf, size_t nbyte) = 0;
  virtual ssize_t write(int fildes, const void *buf, size_t nbyte) = 0;
  virtual int close(int fildes) = 0;

  static System* GetInstance();
  static void set_instance(System* instance) {
    instance_ = instance;
  }

 private:
  static System* instance_;
};

class FileOps : public System {
 public:
  int open(const char *path, int oflag, ...) override;
  ssize_t read(int fildes, void *buf, size_t nbyte) override;
  ssize_t write(int fildes, const void *buf, size_t nbyte) override;
  int close(int fildes) override;
  static FileOps* GetInstance();
};

}  // namespace base

#endif  // MOCK_SAMPLE1_SYSTEM_H_