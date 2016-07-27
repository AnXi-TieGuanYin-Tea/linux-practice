#include<stdio.h>

extern char **environ;
main()
{
  while(*environ) puts(*environ++);
}
