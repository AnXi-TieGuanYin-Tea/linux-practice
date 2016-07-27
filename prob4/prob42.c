#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int
main (int argc, char **argv)
{
  int fd1 = open(argv[1], O_RDONLY);
  int fd2 = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
  unsigned char c;

  while(read(fd1, &c, 1)==1)
    {
      if(islower(c))
        c = toupper(c);
      if(c==' ' || isalpha(c))
        write(fd2, &c, 1);
    }

  close(fd1);
  close(fd2);

  return 0;
}
