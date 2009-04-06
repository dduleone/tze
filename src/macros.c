/***************************************************************************
 *  Original Diku Mud copyright (C) 1990, 1991 by Sebastian Hammer,        *
 *  Michael Seifert, Hans Henrik St{rfeldt, Tom Madsen, and Katja Nyboe.   *
 *                                                                         *
 *  Merc Diku Mud improvments copyright (C) 1992, 1993 by Michael          *
 *  Chastain, Michael Quan, and Mitchell Tse.                              *
 *                                                                         *
 *  In order to use any part of this Merc Diku Mud, you must comply with   *
 *  both the original Diku license in 'license.doc' as well the Merc       *
 *  license in 'license.txt'.  In particular, you may not remove either of *
 *  these copyright notices.                                               *
 *                                                                         *
 *       _/          _/_/_/     _/    _/     _/    ACK! MUD is modified    *
 *      _/_/        _/          _/  _/       _/    Merc2.0/2.1/2.2 code    *
 *     _/  _/      _/           _/_/         _/    (c)Stephen Dooley 1994  *
 *    _/_/_/_/      _/          _/  _/             "This mud has not been  *
 *   _/      _/      _/_/_/     _/    _/     _/      tested on animals."   *
 *                                                                         *
 *                                                                         *
 *  Much time and thought has gone into this software and you are          *
 *  benefitting.  We hope that you share your changes too.  What goes      *
 *  around, comes around.                                                  *
 ***************************************************************************/

#if defined(macintosh)
#include <types.h>
#else
#include <sys/types.h>
#endif
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "merc.h"
#include "tables.h"
#include <math.h>

void reset_gain_stats( CHAR_DATA * ch )
{
  short  index = 0;
  short  index2 = 0;
  short  add_move = 0;
  short  add_mana = 0;
  short  add_hp = 0;

  ch->pcdata->mana_from_gain = 100;
  ch->pcdata->hp_from_gain = 25;
  ch->pcdata->move_from_gain = 0;
  

  for ( index = 0; index < MAX_CLASS; index++ )
  {
    if ( ch->lvl[index] > 0 )
    for ( index2 = 1; index2 <= ch->lvl[index]; index2++ )
    {
       add_hp      = con_app[ch->pcdata->max_con].hitp + number_range(
  		     class_table[index].hp_min,
		     class_table[index].hp_max );
    
       add_mana    = class_table[index2].fMana
		     ? number_range(2, (2*ch->pcdata->max_int+ch->pcdata->max_wis)/16)
		     : 0;
       add_move    = number_range( 2, (ch->pcdata->max_con+ch->pcdata->max_dex)/5 );
       add_hp      = UMAX(  1, add_hp   );
       add_mana    = UMAX(  0, add_mana );
       add_move    = UMAX( 7, add_move );

       ch->pcdata->mana_from_gain += add_mana;
       ch->pcdata->hp_from_gain   += add_hp;
       ch->pcdata->move_from_gain += add_move;

    }
    if ( ch->lvl2[index] > 0 )
    for ( index2 = 1; index2 <= ch->lvl2[index]; index2++ )
    {
       add_hp      = con_app[ch->pcdata->max_con].hitp + number_range(
		     remort_table[index].hp_min,
		     remort_table[index].hp_max );
       add_mana    = remort_table[index].fMana
		     ? number_range(2, (2*ch->pcdata->max_int+ch->pcdata->max_wis)/16)
		     : 0;
       add_move    = number_range( 2, (ch->pcdata->max_con+ch->pcdata->max_dex)/5 );
       add_hp      = UMAX(  1, add_hp   );
       add_mana    = UMAX(  0, add_mana );
       add_move    = UMAX( 7, add_move );

       ch->pcdata->mana_from_gain += add_mana;
       ch->pcdata->hp_from_gain   += add_hp;
       ch->pcdata->move_from_gain += add_move;

    }
  
  }


  if ( ch->adept_level > 0 )
  for ( index2 = 1; index2 <= ch->adept_level; index2++ )
  {
     
     add_hp      = con_app[ch->pcdata->max_con].hitp + number_range(10, 50);
     add_mana    = number_range(10, (3 * ch->pcdata->max_int+ch->pcdata->max_wis)/4);
     add_hp      = UMAX(  1, add_hp   );
     add_mana    = UMAX(  0, add_mana );
 
     ch->pcdata->mana_from_gain += add_mana;
     ch->pcdata->hp_from_gain   += add_hp;

  }	
}	     
   
  

short get_remort_level( CHAR_DATA *ch )
{
   short index;
  short max_remort_level = 0;

  if ( !is_remort( ch ) )
   return 0;

  for ( index = 0; index < MAX_CLASS; index++ )
      if ( ch->lvl2[index] > max_remort_level )
         max_remort_level = ch->lvl2[index];
  return max_remort_level;
}



short get_psuedo_level( CHAR_DATA *ch )
{

   short   psuedo_level = 0;
   short   index, total_remort_level = 0;
   

  if ( !is_remort( ch ) || IS_NPC( ch ) )
   return ch->level;
  else
  {
    
   for ( index = 0; index < MAX_CLASS; index++ )
   
     if ( ch->lvl2[index] > 0 )
     
       total_remort_level += ch->lvl2[index];
     
   

    psuedo_level = ( ch->level +  ( total_remort_level / 4 ) );
  }
  return psuedo_level;

}
  

bool	ok_to_use( CHAR_DATA *ch, int value )
{
   if ( value == NO_USE 
   &&   get_trust(ch) < 85 )
   {
      send_to_char( "Only Creators may use this value.\n\r", ch );
      return FALSE;
   }
   return TRUE;
}

bool	check_level_use( CHAR_DATA *ch, int level )
{
   char buf[MAX_STRING_LENGTH];
   char out[MAX_STRING_LENGTH];
   
   if ( get_trust(ch) >= level )
      return TRUE;
   
   sprintf( out, "This option limited to " );
   
   switch ( level )
   {
      case 85:
         strcat( out, "Creators only.\n\r" );
         break;
      case 84:
         strcat( out, "Supremes or higher.\n\r" );
         break;
      case 83:
         strcat( out, "Dieties or higher.\n\r" );
         break;
      case 82:
         strcat( out, "Immortals or higher.\n\r" );
         break;
      case 81:
         strcat( out, "Adepts or higher.\n\r" );
         break;
      default:
         sprintf( buf, "level %d players and higher.\n\r", level );
         strcat( out, buf );
   }
   send_to_char( out, ch );
   return FALSE;
}   

char *learnt_name( int learnt )
{
   /* For skills/spells.  Return a string indicating how well the
      skill is learnt. */
      
        if ( learnt <   1 )  return "Unknown";
   else if ( learnt <  15 )  return "Awful";
   else if ( learnt <  30 )  return "Weak";
   else if ( learnt <  40 )  return "Poor";
   else if ( learnt <  50 )  return "Average";
   else if ( learnt <  60 )  return "Fair";
   else if ( learnt <  70 )  return "Good";
   else if ( learnt <  80 )  return "Great";
   else if ( learnt <  85 )  return "Superb";
   else if ( learnt <  90 )  return "Amazing";
   else if ( learnt < 101 )  return "Godlike";             
   else if ( learnt < 102 )  return "RACE";
   else                      return "Godlike";
}

int exp_to_level_adept( CHAR_DATA * ch )
{
   int   exp;

   exp = ( 30000 + ( ch->adept_level * 5000 ) );
   exp = UMAX( exp, exp * ch->adept_level/2 );
  return exp;
}

char *get_adept_name( CHAR_DATA * ch )

{
  /* this is weak for now..will eventually have like 200 total names, based on the remort 
     classes the adept has   */

  switch ( ch->adept_level )
  {

    case 1: return    "@@W    Mystic    @@N";
            break;
    case 2: return    "@@a   Templar    @@N";
            break;
    case 3: return    "@@l Illusionist  @@N";
            break;
    case 4: return    "@@e   Crusader   @@N";
            break;
    case 5: return    "@@d   Warlock    @@N";
            break;
    case 6: return    "@@a   Paladin    @@N";

    case 7: return    "@@r   Ranger     @@N";
            break;
    case 8: return    "@@c  Gladiator   @@N";
            break;
    case 9: return    "@@l   Shogun     @@N";
            break;
    case 10: return   "@@e   Shamen     @@N";
            break;
    case 11: return   "@@r    Druid     @@N";
            break;
    case 12: return   "@@b  Conjurer    @@N";

    case 13: return   "@@l Elementalist @@N";
            break;
    case 14: return   "@@m  Runemaster  @@N";

    case 15: return   "@@d Shadowmaster @@N";
            break;
    case 16: return   "@@b Beastmaster  @@N";
            break;
    case 17: return   "@@R   Warlord    @@N";
            break;
    case 18: return   "@@e  Dragonlord  @@N";
            break;
    case 19: return   "@@d  Demonlord   @@N";
            break;
    case 20: return   "@@m  Realm Lord  @@N";



  }
  return              "@@W    Adept     @@N";
}

  
int exp_to_level( CHAR_DATA *ch, int class, int index)
{
 
   /* To get remort costs, call with index==5 */
 
   int max_level = 0;
   int mult;
   int level, next_level_index;
   int totlevels=0,diff;
   int cost;
   int a;
   

   if (  ( index == 5 )
      && ( ch->lvl2[class] <= 0 )  )
     return 0;
 

   for ( a = 0; a < MAX_CLASS; a++ )
      if ( ch->lvl[a] > max_level )
         max_level = ch->lvl[a];
   
/*  Okay, here, we are setting up a cheat to have float mulitpliers..we will devide the total exp by 4 to get
      the proper values later.  */


   switch( index )
   {
      case 0:
         mult=3;
         break;
      case 1:
         mult=4;
         break;
      case 2:
         mult=5;
         break;
      case 3:
         mult=6;
         break;
      case 4:
         mult=7;
         break;
      default:
         mult = 23;	/* i.e. remort class */
         break;
   }
   
   if ( index == 5 )
      level = UMAX( 0, ch->lvl2[class] );
   else
      level = UMAX( 0, ch->lvl[class]);
   
    /* Adjust level to make costs higher */
    
   for (a=0; a < MAX_CLASS; a++)
   {
    totlevels+= ch->lvl[a];
    if ( ch->lvl2[a] > 0 )
       totlevels += ch->lvl2[a];
   }   
   if ( index != 5 )
     next_level_index = ch->lvl[class];
   else
     next_level_index = UMIN( ch->lvl2[class]+ 20, 79 );
 
   if ( next_level_index < 0 )
     next_level_index = 0;

   cost = exp_table[next_level_index].exp_base[class];
 
   /* Now multiply by a factor dependant on total number of levels */
   diff= ( totlevels / MAX_CLASS) - ( level + 20 );
    if ( index == 5)
    diff -= 30; 
   if ( diff < 10 )
    diff = 10 ;
   
   /* Discourage uneven levelling */

   
     cost *= ( diff / 10 );
   /* REALLY discourage uneven levelling :P  */
     if ( ( index != 5 ) && ( ( ch->level - ch->lvl[class] ) > 25 )  )
       cost *= (diff / 7 );

   
   /* Now multiply by order index/remort index...other factors will come here later, like race mod, etc. */
   cost *= mult;
/* now refudge the order multiplier... divide by some factor..6 works right now..  */

   cost /= 5.4;

   return( cost );
}

int exp_to_level_vamp( int level )
{

  int exp = 0;

  switch ( level )
  {
   case 0 :
   case 1 :
   case 3 :
   case 4 :
   case 5 :
            exp = ( 250 + level * 5 );
            break;
   case 6 :
   case 7 :
   case 8 :
   case 9 :
            exp = ( 300 + level * 6);
            break;
   case 10 : 
   case 11 :
   case 12 :
            exp = ( 350 + level * 5 );
            break;
   case 13 :
   case 14 :
   case 15 :
   case 16 :
            exp = ( 450 + level * 6 );
            break;
   case 17 :
   case 18 :
   case 19 :
   case 20 : 
            exp = ( 500 + level * 5 );
            break;

   }
   return ( exp );

}

int exp_to_level_wolf( int level )
{

  int exp = 0;

  switch ( level )
  {
   case 0 :
   case 1 :
   case 3 :
   case 4 :
   case 5 :
            exp = ( 250 + level * 5 );
            break;
   case 6 :
   case 7 :
   case 8 :
   case 9 :
            exp = ( 300 + level * 6);
            break;
   case 10 : 
   case 11 :
   case 12 :
            exp = ( 400 + level * 6 );
            break;
   case 13 :
   case 14 :
   case 15 :
   case 16 :
            exp = ( 550 + level * 6.5 );
            break;
   case 17 :
   case 18 :
   case 19 :
   case 20 : 
            exp = ( 500 + level * 7 );
            break;

   }
   return ( exp );

}



int exp_for_mobile( int level, CHAR_DATA *mob )
{
   
   int value, base_value;
   
   
   base_value = exp_table[level].mob_base;
   value = base_value;

/* now we have the base for the mobs level..let's add multipliers based on the skills it has 
   thse multpliers should add up to no more than 150% of the base, for a total of 2.5 times base
   max exp for the mob--that's with EVERY skill in the book :)   */
  
   
    if ( IS_SET( mob->skills, MOB_SECOND ) )
       value += .05 * base_value;
    if ( IS_SET( mob->skills, MOB_THIRD ) )
       value += .200 * base_value;
    if ( IS_SET( mob->skills, MOB_FOURTH ) )
       value += .1 * base_value;
    if ( IS_SET( mob->skills, MOB_FIFTH ) )
       value += .200 * base_value;
    if ( IS_SET( mob->skills, MOB_SIXTH ) )
       value += .1 * base_value;
    if ( IS_SET( mob->skills, MOB_PUNCH ) )
       value += .050 * base_value;
    if ( IS_SET( mob->skills, MOB_HEADBUTT ) )
       value += .100 * base_value;
    if ( IS_SET( mob->skills, MOB_KNEE ) )
       value += .050 * base_value;
    if ( IS_SET( mob->skills, MOB_DISARM ) )
       value += .050 * base_value;
    if ( IS_SET( mob->skills, MOB_TRIP  ) )
       value += .050 * base_value;
    if ( IS_SET( mob->skills, MOB_NODISARM ) )
       value += .150 * base_value;
    if ( IS_SET( mob->skills, MOB_DODGE ) )
       value += .150 * base_value;
    if ( IS_SET( mob->skills, MOB_PARRY ) )
       value += .05 * base_value;
    if ( IS_SET( mob->skills, MOB_MARTIAL ) )
       value += .200 * base_value;
    if ( IS_SET( mob->skills, MOB_ENHANCED ) )
       value += .300 * base_value;
    if ( IS_SET( mob->skills, MOB_NOTRIP ) )
       value += .100 * base_value;
    if ( IS_SET( mob->skills, MOB_DUALWIELD) )
       value += .050 * base_value;
    if ( IS_SET( mob->skills, MOB_DIRT ) )
       value += .150 * base_value;
    if ( IS_SET( mob->skills, MOB_CHARGE ) )
       value += .050 * base_value;
            

    if ( IS_AFFECTED( mob, AFF_SANCTUARY ) )
       value += .400 * base_value;
    if ( IS_AFFECTED( mob, AFF_INVISIBLE ) )
       value += .050 * base_value;
    if ( IS_AFFECTED( mob, AFF_DETECT_INVIS) )
       value += .100 * base_value;
    if ( IS_AFFECTED( mob, AFF_BESERK    ) )
       value += .300 * base_value;
    if ( IS_AFFECTED( mob, AFF_ANTI_MAGIC) )
       value += .350 * base_value;

    if ( IS_AFFECTED( mob, AFF_CLOAK_FLAMING) )
       value += .600 * base_value;
    if ( IS_AFFECTED( mob, AFF_CLOAK_ABSORPTION ) )
       value += .150 * base_value;
    if ( IS_AFFECTED( mob, AFF_CLOAK_REFLECTION ) )
       value += .350 * base_value;

    if (  ( IS_AFFECTED( mob, AFF_CLOAK_REFLECTION ) )
       && ( IS_AFFECTED( mob, AFF_CLOAK_ABSORPTION ) )
       && ( IS_AFFECTED( mob, AFF_CLOAK_FLAMING    ) )  )
       value += .200 * base_value;


    if ( IS_SET( mob->def, DEF_CURE_LIGHT ) )
       value += .100 * base_value;
    if ( IS_SET( mob->def, DEF_CURE_SERIOUS ) )
       value += .200 * base_value;
    if ( IS_SET( mob->def, DEF_CURE_CRITIC ) )
       value += .350 * base_value;
    if ( IS_SET( mob->def, DEF_CURE_HEAL ) )
       value += .400 * base_value;
    if ( IS_SET( mob->def, DEF_SHIELD_FIRE ) )
       value += .300 * base_value;
      if ( IS_SET( mob->def, DEF_SHIELD_SHOCK ) )
       value += .200 * base_value;
      if ( IS_SET( mob->def, DEF_SHIELD_ICE ) )
       value += .100 * base_value;
              
    if ( IS_SET( mob->act, ACT_SOLO ) )
      value += .500 * base_value;


    
   return( value );
}

/*
 * We need a replacement for strlen() which will take the colour
 * codes into account when reporting a string's length.
 * -- Stephen
 */
 
int my_strlen( char *text )
{
   char c;
   int i;
   int status;		
   int length;
   int strlen_size;
   
   status = 0;
   length = 0;
   strlen_size = strlen( text );
   
   for ( i = 0; i < strlen_size; i++ )
   {
      
      c = text[i];
      length++;
      
      switch( status )
      {
         case 0:
         case 1:
            if ( c == '@' )
               status++;
            else
               status = 0;
            break;
         case 2:   
            length -= 3; /* Subtract for '@@x' */
            status=0;
            break;
      }
   }
   return( length );
}

/*
 * Functions to return details regarding a PC and skill_table 
 * Uses 2 #defined values in merc.h to determine what to return
 * These also make adapting to remort classes a lot easier - all
 * the code goes here instead of in all the skills and do_cast()
 *
 * skill_table[] now includes flags to determine if for mortals
 * or remortals, so use that here, and use correct array.
 */

int skill_table_lookup( CHAR_DATA *ch, int sn, int return_type )
{
   int best_class = -1;
   int best_level = -1;
   int return_value;
   int cnt;
   
   if ( IS_NPC( ch ) )
   {
      best_class = ch->class;
      best_level = ch->level;
   }
   else
   {
      /* Check normal classes first */
   
      switch( skill_table[sn].flag1 )
      {
         case MORTAL:
            for ( cnt = 0; cnt < MAX_CLASS; cnt++ )
            {
               if (    ch->lvl[cnt] >= skill_table[sn].skill_level[cnt]
                    && ch->lvl[cnt] > best_level )
               {
                  best_level = ch->lvl[cnt];
                  best_class = cnt;
               }
            } 
            break;
         case REMORT:
            for ( cnt = 0; cnt < MAX_CLASS; cnt++ )
            {
               if (    ch->lvl2[cnt] >= skill_table[sn].skill_level[cnt]
                    && ch->lvl2[cnt] > best_level )
               {
                  best_level = ch->lvl2[cnt];
                  best_class = cnt;
               }
            }
         break;
      }
   }
   switch ( return_type )
   {
      case RETURN_BEST_CLASS: return_value = best_class; break;
      case RETURN_BEST_LEVEL: return_value = best_level; break;
      default: 
         bug( "skill_table_lookup: invalid return_type:%d", return_type );
         return_value = -1; break;
   }
   return( return_value );
}
         
bool is_remort( CHAR_DATA *ch )
{
   int cnt;
   
   if ( IS_NPC( ch ) )
      return FALSE;
      
   for ( cnt = 0; cnt < MAX_CLASS; cnt++ )
      if ( ch->lvl2[cnt] != -1 )
         return TRUE;
   
   return FALSE;
}


int get_item_value( OBJ_DATA * obj )
{
  AFFECT_DATA * this_aff;
  int		ac_mod = 0;
  int		dr_mod = 0;
  int		hp_mod = 0;
  int		hr_mod = 0;
  int		mana_mod = 0;
 /* int		move_mod = 0;  */
  int		save_mod = 0;
  int		cost = 0;
  short	wear_loc = WEAR_NONE;
  char		buf[MSL];



/* fix this up to use apply_ac by getting the wear loc */
  for (wear_loc = 1; wear_loc < MAX_WEAR ; wear_loc ++ )
  {
    if ( CAN_WEAR( obj, ( 1 << wear_loc ) ) )
      break;
  }
  if ( wear_loc == MAX_WEAR )
  {
   /* sprintf( buf, "Object has no wear loc" );
    monitor_chan( buf, MONITOR_OBJ );  */
    ac_mod = 0;
  }
  else
    ac_mod = apply_ac( obj, 1 << wear_loc );

  for ( this_aff = obj->first_apply ; this_aff != NULL; this_aff = this_aff->next )
  {
     switch (this_aff->location )
    {
    default:
	bug( "Get_item_value: unknown location %d.", this_aff->location );
	sprintf( buf, "Get_item_value called for unknown location %d.",
	   this_aff->location );
	monitor_chan( buf, MONITOR_OBJ );
        break;
    case APPLY_NONE:                                            break;
    case APPLY_STR:            break;
    case APPLY_DEX:            break;
    case APPLY_INT:            break;
    case APPLY_WIS:            break;
    case APPLY_CON:            break;
    case APPLY_SEX:            break;
    case APPLY_CLASS:                                           break;
    case APPLY_LEVEL:                                           break;
    case APPLY_AGE:                                             break;
    case APPLY_HEIGHT:                                          break;
    case APPLY_WEIGHT:                                          break;
    case APPLY_MANA:          mana_mod += this_aff->modifier;   break;
    case APPLY_HIT:           hp_mod += this_aff->modifier;    break;
    case APPLY_MOVE:          					 break;
    case APPLY_GOLD:                                            break;
    case APPLY_EXP:                                             break;
    case APPLY_AC:            ac_mod += this_aff->modifier;	 break;
    case APPLY_HITROLL:       hr_mod += this_aff->modifier;	 break;
    case APPLY_DAMROLL:       dr_mod += this_aff->modifier;	 break;
    case APPLY_SAVING_PARA:  
    case APPLY_SAVING_ROD:    
    case APPLY_SAVING_PETRI:  
    case APPLY_SAVING_BREATH: 
    case APPLY_SAVING_SPELL:  save_mod += this_aff->modifier;	 break;
    }
  }

  cost =
      obj->level *  1 +
      ac_mod     * -8 +
      dr_mod     *  5 +
      hr_mod     *  5 +
      save_mod   *  2 +
      hp_mod     *  4 +
      mana_mod   *  3;

  if ( IS_SET( obj->item_apply, ITEM_APPLY_ENHANCED ) )
    cost = cost * 1.3;

  if ( IS_SET( obj->item_apply, ITEM_APPLY_SANC )  )
    cost = cost * 1.3;

  sprintf( buf, "Cost computed for item %d.", cost );
/*  monitor_chan( buf, MONITOR_OBJ );  */

  if ( obj->item_type == ITEM_ENCHANTMENT )
   cost = abs( obj->value[1] * 100 );
  return UMAX( 10, cost );

  return -1;
}


char *get_tribe_standing_name( int standing )
{


  switch ( standing )
  {
    case 0: return    "@@mEternal@@N";
            break;
    case 1: return    "@@rEldest@@N";
            break;
    case 2: return    "@@rMate@@N";
            break;
    case 3: return    "@@eWarder@@N";
            break;
    case 4: return    "@@GGuardian@@N";
            break;
    case 5: return    "@@aSentry@@N";
            break;
    case 6: return    "@@yElder@@N";

    case 7: return    "@@rAdult@@N";
            break;
    case 8: return    "@@RYounger@@N";
            break;
    case 9: return    "@@bCub@@N";
            break;

  }
  return              "@@WCUB@@N";
}

char *get_moon_phase_name( void )
{



  switch ( weather_info.moon_phase )
  {
    case MOON_NEW     : return    "@@bDark@@N";
                        break;
    case MOON_WAX_CRE : return    "@@aWaxing @@dCresent@@N";
                        break;
    case MOON_WAX_HALF: return    "@@aWaxing @@gHalf@@N";
                        break;
    case MOON_WAX_GIB : return    "@@aWaxing @@WGibbous@@N";
                        break;
    case MOON_FULL    : return    "@@WFULL@@N";
                        break;
    case MOON_WAN_GIB : return    "@@cWaning @@WGibbous@@N";
                        break;
    case MOON_WAN_HALF: return    "@@cWaning @@gHalf@@N";
                        break;
    case MOON_WAN_CRE : return    "@@cWaning @@dCrescent@@N";
                        break;

  }
  return              "@@eDESTROYED!!!@@N";
}

