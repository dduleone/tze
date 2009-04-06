/* copies one file from unix to dos */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "doshack.h"

int main(int argc, char ** argv)
{
 char * temp;
 FILE * temp_file;
 char buffer[2048];
 char src[256],dest[256];

 if (argc < 3)
 { 
  printf("Usage: mydos <unix-file> <dos-file>\n");
  return 1;
 }
 
 strcpy(src,argv[1]);
 strcpy(dest,argv[2]);
 
 temp_file=fopen(src,"r");
 if (temp_file==NULL)
 {
  fprintf(stderr,"Cannot open file %s.\n",argv[1]);
  return 1;
 }
 else
  fclose(temp_file);
  
 temp=dos_fname(dest,ACT_CREATE);
 
 if (temp==NULL)
 {
  fprintf(stderr,"Cannot create a destination file.\n");
  return 1;
 }
 
 strcpy(buffer,"cp -v ");
 strcat(buffer,argv[1]);
 strcat(buffer," ");
 strcat(buffer,temp);

 system(buffer);

 exit (0); 
 return 0;
}
 
  
 
 