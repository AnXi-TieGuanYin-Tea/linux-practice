#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigint(int signo) { puts(signo == SIGINT ? "SIGINT" : "ELSE"); }

int main(void)
{
  sigset_t set;
  static struct sigaction act;

  sigemptyset(&set);
  sigaddset(&set, SIGINT);
  act.sa_mask = set;
  act.sa_handler = sigint;
  sigaction(SIGINT, &act, NULL);
  while(1) sleep(1);
  return 0;
}
