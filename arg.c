#include <stdio.h>

int
main(int argc, char **argv)
{
  int tot = 0, i;
  for(i=1;i<argc;++i)
    {
      int tmp;
      sscanf(argv[i], "%d", &tmp);
      tot += tmp;
    }
  printf("%d\n",tot);

  return 0;
}
