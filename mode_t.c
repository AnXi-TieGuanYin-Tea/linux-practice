#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  struct stat *buf = malloc(sizeof(struct stat));
  int fd = stat(".", buf);

  printf("%o\n", buf->st_mode);

  return 0;
}
