#define ACT_READ 0
#define ACT_CREATE 1
#define ACT_DELETE 2

int dos_rename(char * old, char * new);
FILE * dos_fopen(char * filename, char * mode);
char * dos_fname( char * filename, int action);
