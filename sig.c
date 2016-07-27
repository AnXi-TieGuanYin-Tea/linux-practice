#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

void sigint(int signo) { puts(signo == SIGINT ? "SIGINT" : "ELSE"); }

int main()
{
  void (*f)(int) = signal(SIGINT, sigint);
  while(1) { puts("sleep"); f(SIGINT);sleep(1); }

  return 0;
}
