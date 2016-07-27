#include<unistd.h>
#include<stdio.h>
int main(void)
{
  char arr[1000];
  int fd = open("not", O_RDONLY);

  read(0, (void*)arr, 15);
  puts(arr);

  return 0;
}
