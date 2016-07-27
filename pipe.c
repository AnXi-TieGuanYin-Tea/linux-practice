#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

#define SIZ 512

int main(void)
{
  char *msg[] = {"message1", "message2", "message3"};
  char buf[SIZ];
  int fd[2], i;
  pid_t pid;

  if(pipe(fd) == -1) exit(1);
  if((pid=fork()) == -1) exit(2);

  if(pid>0)
    {
      for(i=0;i<3;++i)
        {
          write(fd[1], msg[i], SIZ);
          printf("PARENT WRITE   %d\n", i);
          printf("PARENT READ(%ld) %s\n", read(fd[0], buf, SIZ), buf);
          write(fd[1], msg[i], SIZ);
          printf("PARENT REWRITE %d\n", i);
        }
      wait(NULL);
    }
  else
    {
      for(i=0;i<3;++i)
        {
          printf("CHILD  %d(%ld) %s\n", fd[0], read(fd[0], buf, SIZ), buf);
        }
    }
  return 0;
}
