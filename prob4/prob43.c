#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int
main (int argc, char **argv)
{
  int len, fd1, fd2 = STDOUT_FILENO;
  unsigned char buf[BUFSIZ];

  if(argc==2) fd1 = open(argv[1], O_RDONLY);
  else fd1 = STDIN_FILENO;

  while((len=read(fd1, buf, BUFSIZ))>0)
    write(fd2, buf, len);
  
  if(fd2 != STDIN_FILENO)
    close(fd2);
  
  return 0;
}
