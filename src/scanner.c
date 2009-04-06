#include <stdio.h>


int main(int argc, char ** argv)
{
 char buffer[1024];
 char filename[1024];
 
 while (scanf("%s",filename) != EOF)
 {
  sprintf(buffer,"%s %s",argv[1],filename);
  system(buffer);
 }
 
 return 0;
}

 
 