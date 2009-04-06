#if defined(macintosh)
#include <types.h>
#else
#include <sys/types.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include "merc.h"
#include "tables.h"
#include <math.h>
#include <ctype.h>

void do_sdelete( CHAR_DATA *ch, char *argument )
{
DESCRIPTOR_DATA *d;
char strsave[MAX_INPUT_LENGTH];
char arg1[MAX_INPUT_LENGTH];
char *pArg;
char cEnd;
char buf[MAX_INPUT_LENGTH];

	if ( IS_NPC(ch) )
	    return;
strcpy(buf,ch->name);
sprintf( strsave, "%s%s%s%s", PLAYER_DIR, initial( buf ), "/", capitalize( buf ) );

	pArg = arg1;
	while ( isspace(*argument) )
	    argument++;
	    
	cEnd = ' ';
	if ( *argument =='\'' || *argument == '"' )
	    cEnd = *argument++;
	    
	while ( *argument != '\0' )
	{
	    if ( *argument == cEnd )
	    {
	        argument++;
	        break;
	    }
	    *pArg++ = *argument++;
	}
	*pArg = '\0';
	
	if (  ( ch->pcdata->pwd != '\0' )
	   && ( arg1[0] == '\0' )  )
	{
	   send_to_char( "Syntax: pdelete <password>.\n\r", ch );
	   return;
	}
	if (  ( ch->pcdata->pwd != '\0' )
	   && ( strcmp( crypt( arg1, ch->pcdata->pwd ), ch->pcdata->pwd ) )  )
	{
	   WAIT_STATE( ch, 40 );
	   send_to_char( "Wrong password.  Wait 10 seconds.\n\r", ch );
	   return;
	}
	

unlink(strsave);
send_to_char("Character deleted.\n\r",ch);

    d = ch->desc;
    extract_char( ch, TRUE );
    if ( d != NULL )
        close_socket( d );
}
