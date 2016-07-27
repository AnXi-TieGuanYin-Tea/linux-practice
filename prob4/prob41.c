#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int
main (int argc, char **argv)
{
  int fd1;
  if((fd1 = open(argv[1], O_RDONLY))==-1)
    {
      const char *out = " not exists\n";
      write(STDERR_FILENO, argv[1], strlen(argv[1]));
      write(STDERR_FILENO, out, strlen(out));
      return -1;
    }

  int fd2 = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
  unsigned char c;

  while(read(fd1, &c, 1)==1)
    write(fd2, &c, 1);

  close(fd1);
  close(fd2);

  return 0;
}
