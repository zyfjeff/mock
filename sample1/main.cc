#include "sample1/system.h"

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>

using namespace base;

int main() {
  assert(System::GetInstance() != nullptr);
  int fd = System::GetInstance()->open("txt", O_RDWR|O_CREAT, 0777);
  assert(fd > 0);
  int ret = System::GetInstance()->write(fd, "12345", 5);
  assert(ret > 0);
  ret = System::GetInstance()->close(fd);
  assert(ret == 0);

  return 0;
}
