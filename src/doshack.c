/* Hack for filenames under dos, use a file with unix->dos mappings */
#include <stdio.h>
#include <string.h>

/* functions are dos_fname,dos_fopen, dos_rename */
#define ACT_READ 0
#define ACT_CREATE 1
#define ACT_DELETE 2

#define REC_SIZE 280
#define DOS_OFFSET 250
#define SLASH_CHAR '\\'
#define SLASH_STRING "\\"


int check_file(char * name)
{
 FILE * temp_file;
 
 temp_file=fopen(name,"r");
 if (temp_file != NULL)
 {
  fclose(temp_file);
  return 0;
 }
 temp_file=fopen(name,"w");
 if (temp_file != NULL)
 {
  fclose(temp_file);
  return 1;
 }
 return 0;
}

char * dos_fname( char * filename, int action)
{
  char pathname[1024];
  char unix_filename[255];
  static char buffer[2048];
  char dos_filename[13];
  int a,b,slashpos,dos_dot_pos;
  char c;
  char * dest_ptr;
  char unix_name_len;
  FILE * dirlist;
  int num_recs,dir_size,pathpos,cur_len;
  int found, lastdeleted;
  int firstdot;
  

  /* first convert pathname */
  
  /* Split into pathname and filename. */
  slashpos=-1;

  b=0;
  dir_size=0;
  pathpos=0;
  firstdot=1;
  for (a=0; filename[a] != '\0'; a++)
  {
   c=filename[a];
   if (c=='/')
   {
    c=SLASH_CHAR;
    slashpos=a;
    pathpos=b;
    dir_size=-1;
   }
   if (c=='.')
   {
    if (firstdot)
     firstdot=0;
    else
     c='_';
   }
    
   if (dir_size < 8)
   {
    pathname[b++]=c;
    dir_size++;
   }
  }
  
  if (slashpos < 1)
  {
   pathname[0]='.';
   pathname[1]='\0';
  }
  else
   pathname[pathpos]='\0';
  
  dest_ptr=unix_filename;
  for (a=slashpos+1; filename[a] != '\0'; a++)
   *(dest_ptr++)=filename[a];
  
  *dest_ptr='\0';
  unix_name_len=a-(slashpos+1);
  
  /* Open dirlist */
  strcpy(buffer,pathname);
  strcat(buffer,SLASH_STRING "__unix.dir");
  dirlist=fopen(buffer,"rb");
  
  if ( (dirlist == NULL) && action != ACT_CREATE)
  {
   fprintf(stderr,"Could not find dirlist file.\n\r");
   return NULL;
  }
  
  found=0;
  lastdeleted=-1;
  num_recs=0;
  
  if ( dirlist != NULL )
  {
   fread( &num_recs, sizeof(int), 1, dirlist);
   if (num_recs > 0 )
   {
    for (a=1; a <= num_recs; a++)
    {
     fseek( dirlist, REC_SIZE * a, SEEK_SET);
     if (fgetc(dirlist) == 'D')
     {
      lastdeleted=a;
      break;
     }
     
     cur_len=fgetc(dirlist);
     if ( cur_len != unix_name_len )
      continue;
      
      
     found=1;
     for (b=slashpos+1; filename[b] != '\0'; b++)
     {
      if (fgetc(dirlist) != filename[b])
      {
       found=0;
       break;
      }
     }
     
     if (found && fgetc(dirlist) != ' ')
      found=0;
     
     if ( found )
      break;
    }
   }
   
   
   if (found)
   {
    fseek( dirlist, REC_SIZE * a + DOS_OFFSET, SEEK_SET);
    fread( &dos_filename, 12, 1, dirlist);
    dos_filename[12]='\0';
    for (a=11; a > -1; a--)  /* Remove blank spaces at end of filename */
    {
     if (dos_filename[a]==' ')
      dos_filename[a]='\0';
     else
      break;
    }
    
    if (a==-1) /* Blank dos filename */
    {
     fprintf(stderr,"Invalid dos filename in doshack for file %s, deleting\n\r",filename);
     fseek( dirlist, REC_SIZE * a, SEEK_SET);
     fputc( 'D', dirlist);
     found=0;
    }
    
    if (action == ACT_DELETE)
    {
     fseek( dirlist, REC_SIZE * a, SEEK_SET);
     fputc( 'D', dirlist);
    }
   }
   
   fclose(dirlist);
  }
   
  if (!found)
  {
   if (action != ACT_CREATE)
   {
    fprintf(stderr,"Could not find file %s.\n\r",filename);
    return NULL;
   }
   /* Create an entry for a new file. */
    
   /* Split name into prefix and suffix */
   for (a=0; a < 8; a++)
   {
    if (unix_filename[a]=='.' || unix_filename[a]=='\0')
     break;
    dos_filename[a]=unix_filename[a];
   }
   
   dos_dot_pos=a;
   b=a; /* b measures the pos in dos_filename */
   
   if (unix_filename[a] != '\0' )
   {
    if (unix_filename[a] == '.' )
     a++;
    dos_filename[b++]='.';
    
    for ( ; b < 12 ; b++)
    {
     if (unix_filename[a] == '\0' )
      break;
     else
     {
      if (unix_filename[a] == '.' )
       dos_filename[b] = '_';
      else
       dos_filename[b] = unix_filename[a];
      a++;
     }
    }
   }
   dos_filename[b]='\0';
    
   /* We now have a dosified original name. */
    
   strcpy(buffer, pathname);
   strcat(buffer, SLASH_STRING);
   slashpos=strlen(buffer);
   strcat(buffer, dos_filename);
   if ( ! check_file(buffer) )
   {
    /* now do some jiggery pokery */
    buffer[slashpos+dos_dot_pos]='.';
     
    for (a=0; a < 1000; a++)
    {
     sprintf(buffer+slashpos+dos_dot_pos+1,"%03i",a);  /* Replace suffix with 3 dig. number */
     if ( check_file(buffer) )
      break;
    }
     
    sprintf(dos_filename+dos_dot_pos+1,"%03i",a);
    if (a==1000)
    {
     fprintf(stderr,"Could not work out a dos filename for %s.\n\r",filename);
     return NULL;
    }
   }
     
     
   strcpy(buffer,pathname);
   strcat(buffer,SLASH_STRING "__unix.dir");
   dirlist=fopen(buffer,"r+b");
     
   if (dirlist == NULL)
    dirlist=fopen(buffer,"w+b");
    
   if (dirlist == NULL)
   {
    fprintf(stderr,"Could not create a dirlist file.\n\r");
    return NULL;
   }
      
   if (lastdeleted == -1)
   {
    num_recs++;
    lastdeleted=num_recs;
    fseek(dirlist,0,SEEK_SET);
    fwrite(&num_recs, sizeof(int), 1, dirlist);
   }
     
   fseek( dirlist, REC_SIZE * lastdeleted, SEEK_SET);
   fputc( ' ', dirlist);
   fputc( unix_name_len, dirlist);
   fprintf(dirlist, "%s ", unix_filename);
   fseek( dirlist, REC_SIZE * lastdeleted + DOS_OFFSET, SEEK_SET);
   fprintf(dirlist, "%s            \n\r", dos_filename);
   
   fclose(dirlist);
  }  
    
  strcpy(buffer,pathname);
  strcat(buffer,SLASH_STRING);
  strcat(buffer,dos_filename);
    
  fprintf(stderr,"Converted %s to %s\n\r",filename,buffer);

  return buffer;
}   

    
FILE * dos_fopen(char * filename, char * mode)
{
 /* Currently only deal with a, r, w */
 char * dos_filename;
 int action;
 
 if (!strcmp(filename,"nul"))
  return fopen(filename, mode);
 
 if (mode[0]=='r')
  action=ACT_READ;
 else
  action=ACT_CREATE;
  
 dos_filename=dos_fname(filename, action);
 
 if (dos_filename==NULL)
  return NULL;
  
 return fopen(dos_filename, mode);
}

int dos_rename(char * old, char * new)
{
 char * temp;
 char old_dos[255], new_dos[255];
 FILE * temp_file;
 
 if ( (temp=dos_fname(old, ACT_READ)) == NULL)
  return -1;
  
 strcpy(old_dos, temp);
  
 temp=dos_fname(new, ACT_CREATE);
 if ( temp == NULL)
  return -1;
  
 strcpy(new_dos, temp);
 
 if (rename (old_dos, new_dos) == -1)
 {
  if ( (temp_file=fopen(new_dos,"r"))!= NULL)
   fclose(temp_file);
  else
   dos_fname(new, ACT_DELETE);
  return -1;
 }
 
 dos_fname(old, ACT_DELETE);
 return 0;
}

