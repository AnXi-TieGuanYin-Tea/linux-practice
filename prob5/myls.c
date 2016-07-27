#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <inttypes.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  DIR *dirp = opendir(".");
  struct dirent *dir = readdir(dirp);
  struct stat st;

  for(; dir!=NULL; dir=readdir(dirp))
    if(argc == 1)
      printf("%s\n", dir->d_name);
    else if (argv[1][1] == 'i')
      printf("%7ju %s\n", (uintmax_t) dir->d_ino, dir->d_name);
    else
      {
        if(stat((const char*) dir->d_name, &st)!=0) exit(-1);
        printf( (S_ISDIR(st.st_mode)) ? "d" : "-");
        printf( (st.st_mode & S_IRUSR) ? "r" : "-");
        printf( (st.st_mode & S_IWUSR) ? "w" : "-");
        printf( (st.st_mode & S_IXUSR) ? "x" : "-");
        printf( (st.st_mode & S_IRGRP) ? "r" : "-");
        printf( (st.st_mode & S_IWGRP) ? "w" : "-");
        printf( (st.st_mode & S_IXGRP) ? "x" : "-");
        printf( (st.st_mode & S_IROTH) ? "r" : "-");
        printf( (st.st_mode & S_IWOTH) ? "w" : "-");
        printf( (st.st_mode & S_IXOTH) ? "x" : "-");
        printf( "%4ju%4ju %s\n", (uintmax_t) st.st_nlink, (uintmax_t) st.st_nlink, dir->d_name);
      }
  closedir(dirp);
  return 0;
}
