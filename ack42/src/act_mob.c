/***************************************************************************
 *                                                                         *
 *       _/          _/_/_/     _/    _/     _/    ACK! MUD is modified    *
 *      _/_/        _/          _/  _/       _/    Merc2.0/2.1/2.2 code    *
 *     _/  _/      _/           _/_/         _/    (c)Stephen Dooley 1994  *
 *    _/_/_/_/      _/          _/  _/             "This mud has not been  *
 *   _/      _/      _/_/_/     _/    _/     _/      tested on animals."   *
 *                                                                         *
 ***************************************************************************/

#if defined(macintosh)
#include <types.h>
#else
#include <sys/types.h>
#endif
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "merc.h"
#include <math.h>

bool able_to_level ( CHAR_DATA *ch );
void gain_level ( CHAR_DATA *ch );
int find_spell ( CHAR_DATA *ch, int type );
void hunt_move args(( CHAR_DATA *mob, short dir ));
short h_find_dir args(( ROOM_INDEX_DATA *room, ROOM_INDEX_DATA *target,
			 int h_flags ));
void mob_group_follow ( CHAR_DATA *ch, CHAR_DATA *target ); 
void get_mob_group ( CHAR_DATA *ch, CHAR_DATA *target );
bool ready_heal_room ( CHAR_DATA *ch );
void need_to_stand ( CHAR_DATA *ch );
void get_up ( CHAR_DATA *ch, int current_state );
void mob_regen_check ( CHAR_DATA *ch, CHAR_DATA *target, bool need_flee );
void mob_is_fighting ( CHAR_DATA *ch );
void power_up_mob ( CHAR_DATA *ch );
void mob_is_standing ( CHAR_DATA *ch );
bool valid_target ( CHAR_DATA *ch, CHAR_DATA *victim, int l );
void select_target ( CHAR_DATA *ch );
void int_handler ( CHAR_DATA *ch );
void int_combat_handler ( CHAR_DATA *ch, CHAR_DATA *victim );

bool able_to_level ( CHAR_DATA *ch )
{
   bool in_need = FALSE;

   if ( ch->intell_exp > ( 5 * exp_for_mobile( ch->level, ch ) ) )
      in_need = TRUE;

   return in_need;
}

void gain_level ( CHAR_DATA *ch )
{
   int cost;
   char buf[MAX_STRING_LENGTH];

   cost = 5 * exp_for_mobile ( ch->level, ch );
   if ( ch->intell_exp < cost )
      return;

   ch->intell_exp -= cost;
   ch->level = UMIN( 140, ch->level ++ );

   sprintf ( buf, "%s gains a level!", ch->short_descr );
   info( buf, 1 );
   return;
}

int find_spell ( CHAR_DATA *ch, int type )
{
   int sn;
   int bar;
   int level;
   int spell = -1;
   int spell_level = -1;

   for ( sn = 0; sn < MAX_SKILL; sn++ )
   {
      if ( skill_table[sn].name == NULL )
	 break;
      if ( skill_table[sn].slot == 0 )
	 continue;
      if ( skill_table[sn].target != type )
	 continue;

      level = -1;
      for ( bar = 0; bar < MAX_CLASS; bar++ )
	 if ( skill_table[sn].skill_level[bar] > level
	    && ch->level >= skill_table[sn].skill_level[bar] )
	    level = skill_table[sn].skill_level[bar];
  
      if ( level == -1 )   /* not high enough to use */
	 continue;

      if ( level > spell_level && mana_cost ( ch, sn ) < ch->mana )
      {
	 spell = sn;
	 spell_level = level;
      }
   }
   
   return spell;
}

void mob_group_follow ( CHAR_DATA *ch, CHAR_DATA *target ) 
{
   char    buf[MAX_STRING_LENGTH];
   CHAR_DATA *vch;
   int     num;
 
   sprintf ( buf, "Ok guys, let's all follow %s.",
		   target->short_descr );
   do_say ( ch, buf );
      
   for ( vch = ch->in_room->first_person; vch != NULL;
	 vch = vch->next_in_room  )
   {
      if (  ( ch != vch ) && is_same_group ( ch, vch )  )
      {
	 if (  vch->position != POS_STANDING  )
	    do_stand ( vch, "" );

	 num = number_percent();
	 
	 WAIT_STATE( vch, 12 );

	 if (  num > 85 )   
	    do_say ( vch, "Ok boss.  Whatever you say." );
	 else if ( num > 70 )
	    do_say ( vch, "Alright!  More people, more power!" );
	 else if ( num > 55 )
	    do_say ( vch, "Whoo Hooo!" );
	 else if ( num > 35 )   
	    do_say ( vch, "Sure thing." );
	 else if ( num > 29 )
	 {
	    if (  num > 32  )   
	       sprintf( buf, "Man I don't want to join %s's group!",
			      target->short_descr );
	    else
	       sprintf( buf, "I hate big groups." );
	    do_say ( vch, buf );
	    do_follow ( vch, vch->name );
	    do_say ( vch, "I'm outta here." );
	    do_recall ( vch, "" );
	    continue;
	 }
	  
	 if ( !can_see ( vch, target ) )
         {
            vch->master = target;
            vch->leader = NULL;
         }
         else
            do_follow ( vch, target->name );
         do_group ( target, "all" );

      }
   }   
   return;
}


void get_mob_group ( CHAR_DATA *ch, CHAR_DATA *target )
{
   CHAR_DATA   *vch;
   bool        ch_is_leader  = FALSE;
   bool        tar_is_leader = FALSE;
   bool        is_hunting    = FALSE;
   bool        ch_is_higher  = FALSE;
   char        buf[MAX_STRING_LENGTH];
   int         number_of_tar_group = 1;
   int         number_of_ch_group = 1;

   ch_is_leader = is_group_leader(ch);
   tar_is_leader = is_group_leader(target);

   if ( tar_is_leader == TRUE )
   {
      for (  vch = ch->in_room->first_person; vch != NULL;
	     vch = vch->next_in_room )
      {
	  if (  vch != target && is_same_group ( vch, target ) )
	  {
	     number_of_tar_group = number_of_tar_group + 1;
	     continue;      
	  }
	  if ( vch != ch && is_same_group ( ch, vch ) )
	  {
	     number_of_ch_group = number_of_ch_group + 1;
	     continue;
	  }
      }
   }

   do_say ( ch, "Hello there.  What are you up to?" );

   WAIT_STATE( target, 24 );
      
   if (  target->hunting != NULL )
   {   
      is_hunting = TRUE;
      if (  tar_is_leader == TRUE  )
	 sprintf ( buf, "We're planning on killing %s.",
			 target->hunting->short_descr );
      else
	 sprintf ( buf, "I'm planning on killing %s.",
			 target->hunting->short_descr );
      do_say ( target, buf );
   }
   else
      do_say ( target, "Nothing.  Just hanging around." );

   WAIT_STATE( ch, 24 );

   /* check to see which of the two is higher. the higher mob will lead */
   if (  get_psuedo_level (ch) >= get_psuedo_level (target)  )
      ch_is_higher = TRUE;

   /* if ch is higher in levels and victim is hunting, then say 
    * appropriate line. */
   if (  ( ch_is_higher == FALSE )
      && ( is_hunting == TRUE )  )
      do_say ( ch, "Oh really?  Cool!  Need any help?" );
   else if (  ( ch_is_higher == FALSE )
	   && ( is_hunting == FALSE )  )
      do_say ( ch, "Great!  Since you're not doing anything, wanna group?");
   else if (  ( ch_is_higher == TRUE )
	   && ( is_hunting == TRUE )  )
   {
      if (  ch_is_leader == TRUE  )  
      {
	 sprintf ( buf, "Want to help us kill %s instead?",
		      ch->hunting->short_descr );
	 do_say ( ch, buf );
      }
      else if (  ch_is_leader == FALSE  )
      {
	 sprintf ( buf, "Want to help me kill %s instead?",
		      ch->hunting->short_descr );  
	 do_say ( ch, buf );
      }
   }
   else if (  ( ch_is_higher == TRUE ) 
	   && ( ch->hunting == FALSE )  )
      do_say ( ch, "Want to group?" );

   WAIT_STATE( target, 24 );

   if (  ch_is_higher == TRUE )
   {
      do_say ( target, "Ok sure!  Thanks for asking." );

      if (  tar_is_leader == TRUE  )
	 mob_group_follow ( target, ch );

      do_follow ( target, ch->name );
      do_group ( ch, target->name );
   }
   else
   {
      do_say ( target, "Ok, why not!?  Follow me." );

      WAIT_STATE( ch, 24 );

      do_say ( ch, "Cool!" );

      if (  ch_is_leader == TRUE  )
	 mob_group_follow ( ch, target );
	 
      do_follow ( ch, target->name );
      do_group ( target, ch->name );
   }
   return;
}
  
   

/* returns false if mob needed to cast a room affect spell */
bool ready_heal_room ( CHAR_DATA *ch )
{
   bool    ready = TRUE;

   if (  ( !IS_SET( ch->in_room->affected_by, ROOM_BV_HEAL_REGEN ) )
      && ( ch->hit < ch->max_hit * 75/100 )  )
   {
      if (  ch->mana >= mana_cost( ch, skill_lookup ( "healing light" ) )  )
      {
	 ready = FALSE;
	 do_cast ( ch, "'healing light'" );
	 return ready;
      }
   }

   if (  ( !IS_SET( ch->in_room->affected_by, ROOM_BV_MANA_REGEN )  )
      && ( ch->mana < ch->max_mana * 75/100 )  )
   {
      if (  ch->mana >= mana_cost( ch, skill_lookup ( "mana flare" ) )  )
      {
	 ready = FALSE;
	 do_cast ( ch, "'mana flare'" );
	 return ready;
      }
   }    
 
   /* don't cast seal room in midgaard */
   if (  ( ch->in_room->vnum > ROOM_VNUM_MID_TOP
      ||   ch->in_room->vnum < ROOM_VNUM_MID_BOTTOM )   
      && ( !IS_SET( ch->in_room->affected_by, ROOM_BV_ENCAPS ) )  )
   {
      if ( ch->mana >= mana_cost( ch, skill_lookup ( "seal room" ) )  )
      {
	 ready = FALSE;
	 do_cast ( ch, "'seal room'" );
	 return ready;
      }
   }

   return ready;
}

/* checks to see if mob needs to stand up for any reason, if so then stand. */
void need_to_stand ( CHAR_DATA *ch )
{
   int  current_state;
   CHAR_DATA  *vch;

   current_state = ch->position;

   /* if someone in your group is fighting, get up */
   for (  vch = ch->in_room->first_person; vch != NULL;
	  vch = vch->next_in_room  )
   {
      if (  ( is_same_group ( ch, vch ) )
	 && ( vch->position == POS_FIGHTING )  )
      {
	 get_up ( ch, current_state );
	 return;
      }
   }
   
   /* if your leader is up and ready to move, get up */
   if (  ( ch->leader != NULL )
      && ( ch->in_room == ch->leader->in_room )  
      && ( ch->leader->position == POS_STANDING )
      && ( ch->leader->hit >= ch->leader->max_hit * 85/100 )
      && ( ch->leader->mana >= ch->leader->max_mana * 85/100 )  )
   {
      get_up ( ch, current_state );
      return;
   }


   /* Do you need heal? if so, can you heal? */
   if (  ch->hit < ch->max_hit * 85/100  )
   {
      if (  ( ch->mana >= mana_cost ( ch, skill_lookup ( "heal" ) ) )
	 || ( ch->mana >= mana_cost ( ch, skill_lookup ( "cure critical" ) ) )
	 || ( ch->mana >= mana_cost ( ch, skill_lookup ( "cure serious" ) ) )  ) 
      {
	 get_up ( ch, current_state );
	 return;
      }

   }

   /* if there is an int mob in the room stand so that you can group with 
    * it */
   if (  ch->leader == NULL  )
   {
      for (  vch = ch->in_room->first_person; vch != NULL; 
	       vch = vch->next_in_room  )
      {
	 if (  ( IS_NPC( vch )  )
            && ( vch->leader == NULL )
            && ( !is_same_group ( vch, ch ) )
	    && ( IS_SET( vch->act, ACT_INTELLIGENT ) )  
            && ( vch != ch )
	    && ( ( get_psuedo_level (vch) - get_psuedo_level (ch) <= 20 )
	      && ( get_psuedo_level (vch) - get_psuedo_level (ch) >= -20 )))
	 {
	       get_up ( ch, current_state );
	       return;
	 }
      }   
   }

   /* if you're ready to move, stand */
   if (  ( ch->hit >= ch->max_hit * 85/100 )
      && ( ch->mana >= ch->max_mana * 85/100 )  )
      get_up ( ch, current_state );

   return;
}   

void get_up ( CHAR_DATA *ch, int current_state )
{

   if (  current_state == POS_SLEEPING  )
      do_wake ( ch, "" );
   else if (  current_state == POS_RESTING  )
      do_stand ( ch, "" );
 
   return;
}


void mob_regen_check ( CHAR_DATA *ch, CHAR_DATA *target, bool need_flee )
{
   char  buf[MAX_STRING_LENGTH];

   if (  target == NULL  )
      target = ch;

   if (  ch->mana >= mana_cost ( ch, skill_lookup("heal") )  )
      sprintf ( buf, "'heal' %s", target->name );
   else if (  ch->mana >= mana_cost ( ch, skill_lookup("cure critical") )  )  
      sprintf ( buf, "'cure critical' %s", target->name );
   else if (  ch->mana >= mana_cost ( ch, skill_lookup("cure serious") )  )
      sprintf ( buf, "'cure serious' %s", target->name );
   else if (  need_flee == TRUE  )
   {
      do_flee( ch, "" );
      return;
   }
   else if ( need_flee == FALSE )
      return;

   do_cast ( ch, buf );
   return;
}

void mob_is_fighting ( CHAR_DATA *ch )
{
   CHAR_DATA  *vch;
   CHAR_DATA  *target           = NULL;
   bool       is_being_attacked = FALSE;
   bool       need_flee         = FALSE;
   
   /* check to see if you are the one being attacked */
   for (  vch = ch->in_room->first_person; vch != NULL; 
	  vch = vch->next_in_room  )
   {
      if (  vch->fighting == ch  )
      {
	 is_being_attacked = TRUE;
	 break;
      }
   }
   
   /* if you have a leader and he/she is present, they should rescue you if 
    * you are being attacked, else you should check on them in case they 
    * need heals */
   if (  ( ch->leader != NULL )
      && ( ch->leader->in_room == ch->in_room )  )

   {
      target = ch->leader;

      if ( is_being_attacked == TRUE && target != ch )   
	 do_rescue ( target, ch->name );
      else if (  target->hit < target->max_hit * 50/100  )
	 mob_regen_check ( ch, target, need_flee );
      else
      {
	 for (  vch = ch->in_room->first_person; vch != NULL;
		vch = vch->next_in_room  )
	 {
	    if (  ( is_same_group ( ch, vch ) )
	       && ( vch->hit < vch->max_hit * 20/100 )  )
	    {
	       mob_regen_check ( ch, vch, need_flee );
	       return;
	    }
	 }
      }
      
      return;
   }
   

   /* if flow reaches here, you are the tank */ 
   /* either heal yourself or flee */
   if (  ch->hit < ch->max_hit * 50/100  ) 
   {
      if (  ch->hit < ch->max_hit * 20/100  )
	 need_flee = TRUE;
      mob_regen_check ( ch, target, need_flee );
   }
   
   return;
}

void power_up_mob ( CHAR_DATA *ch )
{
   int       num_percent;   

   /* you can only have one cloak spell */
   if (  !IS_AFFECTED( ch, AFF_CLOAK_ABSORPTION )
      && !IS_AFFECTED( ch, AFF_CLOAK_REFLECTION )
      && !IS_AFFECTED( ch, AFF_CLOAK_FLAMING    )  )
   {
      num_percent = number_percent();
      
      if (  num_percent > 75  )
      {
	 if ( ch->mana >= mana_cost( ch, skill_lookup( "cloak:flaming")) )
	    do_cast ( ch, "'cloak:flaming'" );
	 return;
      }

      if (  num_percent > 50  )
      {
	 if ( ch->mana >= mana_cost( ch, skill_lookup( "cloak:reflection")) )
	    do_cast ( ch, "cloak:reflection" );
	 return;
      }
 
      if (  num_percent > 25  )
      {
	 if ( ch->mana >= mana_cost( ch, skill_lookup( "cloak:absorption")) )
	    do_cast ( ch, "cloak:absorption" );
	 return;
      }
   }

   /* usually i only have mobs do one thing per round but what they hell 
    * let the kids have their fun :) */
   if (  !IS_AFFECTED( ch, AFF_SANCTUARY )  )
      if (  ch->mana >= mana_cost( ch, skill_lookup( "sanctuary" ))  )
         do_cast ( ch, "sanctuary" );
   if (  !IS_AFFECTED( ch, AFF_PROTECT )  )
      if (  ch->mana >= mana_cost( ch, skill_lookup( "protection" ))  )
	 do_cast ( ch, "protection" );
   if (  !IS_AFFECTED( ch, skill_lookup( "bless" ) )  )
      if (  ch->mana >= mana_cost( ch, skill_lookup( "bless" ))  )
	 do_cast ( ch, "bless" );
   if ( !IS_AFFECTED( ch, skill_lookup( "stone skin" ) )  )
      if (  ch->mana >= mana_cost( ch, skill_lookup( "stone skin" ))  )
	 do_cast ( ch, "stone" );
   return;
}        

void mob_is_standing ( CHAR_DATA *ch )
{
   short    dir;
   CHAR_DATA  *vch;
   CHAR_DATA  *tch;
   bool    ready = TRUE;
   bool    prey_still_exist = FALSE;
   int     number_got_up = 0;
   int     number_of_group = 1;
   int     number_of_other_group = 1;  
   
   /* get a light source */
   if ( get_eq_char( ch, WEAR_LIGHT ) == NULL )
   {
      if (  ch->mana >= mana_cost( ch, skill_lookup("continual light") )  )
      {
         do_cast ( ch, "'continual light'" );
         do_get ( ch, "all" );
         do_wear ( ch, "all" );
         return;
      }
   }
   
   if (  ( IS_AFFECTED( ch, AFF_POISON ) ) 
      || ( IS_AFFECTED( ch, AFF_BLIND ) )  )
   {
      if (  IS_AFFECTED( ch, AFF_POISON )  )
	 if (  ch->mana >= mana_cost( ch, skill_lookup( "cure poison" ))  )
	    do_cast ( ch, "'cure poison'" );
      if (  IS_AFFECTED( ch, AFF_BLIND )  )
	 if ( ch->mana >= mana_cost( ch, skill_lookup( "cure blindness")) )
	    do_cast ( ch, "'cure blindness'" );
      return;
   }

   /* is anyone in group being attacked? if so, assist! */
   /* -leaders will be forced to rescue in the 'mob_is_fighting' function
    * already so no need to check for it here */
   for (  vch = ch->in_room->first_person; vch != NULL;
	  vch = vch->next_in_room   )
   {
      if (  ( is_same_group ( ch, vch ) )
	 && ( vch->fighting != NULL )
	 && ( vch != ch )  )
      {   
	 do_assist ( ch, "" );
	 return;
      }
   }
   if ( ch->leader == NULL )
   {
      for ( vch = ch->in_room->first_person; vch != NULL;
	    vch = vch->next_in_room )
      {
         if ( is_same_group ( ch, vch ) && ( ch != vch ) )
	 {
	    number_of_group = number_of_group + 1;
	 }
      }
      if ( number_of_group < 4 )
      {
	 for ( vch = ch->in_room->first_person; vch != NULL; 
	       vch = vch->next_in_room )
	 {
	    if (  vch->leader != NULL  )
               continue;

            if (  ( vch != ch ) && ( IS_NPC ( vch) )
	       && ( IS_SET( vch->act, ACT_INTELLIGENT ) )
	       && ( !is_same_group( ch, vch ) )  
	       && ( vch->position == POS_STANDING )
	       && (  (get_psuedo_level (vch) - get_psuedo_level (ch) <=20 
		 && get_psuedo_level (vch) - get_psuedo_level (ch) >= -20) 
		 || ( get_psuedo_level (ch) - get_psuedo_level (vch) <=20
		 && get_psuedo_level (ch) - get_psuedo_level (vch) >= -20))  
	       && ( can_see(vch, ch) )
	       && ( can_see(ch, vch) )  ) 
	       
	    {
	       if ( vch->leader == NULL )               
	       {
		  for (  tch = vch->in_room->first_person; tch != NULL;
			 tch = tch->next_in_room  )
		  {
		     if (  is_same_group (tch, vch) && (tch != vch )  )
		     {
			number_of_other_group = number_of_other_group + 1;
		     }
		  }
	       }
	    
	       if ( number_of_group + number_of_other_group <= 4 )
	       {
	       get_mob_group ( ch, vch );
	       return;
	       }
	    }
	 } 
      }
   } 

   /* do you need to heal? */
   if (  ch->hit < ch->max_hit * 85/100  )
   {
      if (  ( ch->mana >= mana_cost ( ch, skill_lookup ( "heal" ) ) )
	 || ( ch->mana >= mana_cost ( ch, skill_lookup ( "cure critical" ) ) )
	 || ( ch->mana >= mana_cost ( ch, skill_lookup ( "cure serious" ) ) )  )
      
	 mob_regen_check ( ch, NULL, FALSE );

      /* if leader is ready to move, just keep standing */
      if (  ( ch->leader != NULL )
	 && ( ch->leader->in_room == ch->in_room )
	 && ( ch->leader->position == POS_STANDING )
	 && ( ch->leader->mana >= ch->leader->max_mana * 85/100 )  
	 && ( ch->leader->hit >= ch->leader->max_hit * 85/100 )  )
	 return;
      else
      {
	 if (  ch->mana >= ch->max_mana * 75/100  )
	    ready = ready_heal_room ( ch );
	 
	 if (  ready == TRUE  )
	    do_sleep ( ch, "" );

	 return;
      }
   }
      

   if (  ch->mana < ch->max_mana * 85/100  )
   {
      do_sleep ( ch, "" );
      return;
   }


   /* do you need to level? if you have a group leader, have the leader 
    * find a the trainer. if you are the leader just go and find the
    * trainer */
   if (  able_to_level ( ch )  )
   {
      char_from_room( ch );
      char_to_room( ch, get_room_index( 3758 ) );
      gain_level ( ch );
      return;
/*
      dir = h_find_dir ( get_room_index(ch->in_room->vnum), 
			 get_room_index(ROOM_VNUM_INT_HEAL),
			 ch->hunt_flags );

      if (  dir == -1  )
	 gain_level ( ch );
      else 
      { 
	 if (  ( ch->leader != NULL )
	    && ( ch->leader->in_room == ch->in_room )  )
	 {
	    hunt_move ( ch->leader, dir );
	    end_hunt ( ch->leader );
	    return;
	 }
	 else
	 {
	    hunt_move ( ch, dir );
	    return;
	 }
      }  */
   }      
   
   /* if you're leader and you don't need to gain level, does anyone else 
    * in the group? */   
   /* actually, the above function will force the leader to find a trainer 
    * already.  but since i don't want the leader to select a new target 
    * until the group gains the needed level, i'll put this check here */   
   for (  vch = ch->in_room->first_person; vch != NULL;
	  vch = vch->next_in_room  )
   {
      if (  ( is_same_group ( vch, ch ) )
	 && ( vch->in_room == ch->in_room )
	 && ( vch->leader == ch )
	 && ( able_to_level ( vch ) )  )
      {
	 dir = h_find_dir ( get_room_index(ch->in_room->vnum),
	       get_room_index(ROOM_VNUM_INT_HEAL),
	       ch->hunt_flags );
	 hunt_move ( ch, dir );
	 return;
      }
   }

   /* if noone needs to heal or gain level, then let's hunt! */
   /* by the way, only leaders will hunt. followers will just follow and 
    * assist when needed */
   if (  ( ch->leader != NULL )
      && ( ch->leader->in_room == ch->in_room )  
      && ( ch->hunting != NULL )  )
   {
      end_hunt ( ch );
   }
   else if ( ( ch->leader != NULL ) 
	   && (ch->leader->in_room == ch->in_room)
	   && (ch->hunting == NULL ))
   {
      return;
   }
   else if ( is_group_leader ( ch ) )
   {
       for ( vch = ch->in_room->first_person; vch != NULL;
             vch = vch->next_in_room )
       {
          if (  ( vch != ch ) && ( is_same_group ( vch, ch ) )
             && ( vch->position != POS_STANDING )  )
          {
             get_up ( vch, vch->position );
             number_got_up = number_got_up + 1;
          }
       }
       if ( number_got_up != 0 )
          return;
   }
   else 
   {
      if (  ch->hunting != NULL  )
      {
	 for (  vch = first_char; vch != NULL; vch = vch->next )
	 {
	    if (  vch == ch->hunting  )
	    {
	       prey_still_exist = TRUE;
	       return;
	    }
	 }
	 
	 if (  prey_still_exist == FALSE  )
	 {
	    ch->hunting = NULL;
	 }
      }
      if (   ch->hunting == NULL && ch->leader == NULL )
      {
	 select_target ( ch );
	 return;
      }
   }

   /* power_up_mob ( ch ); */

   /* if (  ch->leader != NULL 
      && ch->in_room != ch->leader->in_room )
   {
      do_follow( ch, ch->name );
   }  */

   return;

}    
  

bool valid_target( CHAR_DATA *ch, CHAR_DATA *victim, int l )
{
   /* Return TRUE if victim is a valid target for ch to kill. */
 
   /* don't hunt people you can't even see */
   if ( !can_see( ch, victim ) )
      return FALSE;

  /* Don't attack group members or self! */
   if ( is_same_group( ch, victim ) )
      return FALSE;   

   /* Don't attack other int mobs! */
   if ( IS_NPC( victim ) && IS_SET( victim->act, ACT_INTELLIGENT ) )
      return FALSE;
  
   /* Don't attack players.... except for have spec_vamp_hunter */
   if (  ( !IS_NPC( victim ) )
      && ( ch->spec_fun != spec_lookup( "spec_vamp_hunter" ) )    )
      return FALSE;
  
   /* don't attack fairy godmother */
   if (  IS_NPC( victim )  )
      if (  victim->pIndexData->vnum == 1026  )
         return FALSE;


   /* if IS vamp_hunter, make sure target is a player vamp */
   
   if (  ( IS_VAMP( victim ) )
      && ( !IS_NPC( victim ) )
      && ( ch->spec_fun != spec_lookup( "spec_vamp_hunter" ) )    )
     return FALSE;
		
   /* don't attack NPC VAMPS (they can't die ) */
   if (  ( IS_VAMP( victim ) )
      && ( IS_NPC( victim ) )  )
     return FALSE;
 
   /* Only kill victims of similar level */
   if (  ( ( get_psuedo_level( victim ) - get_psuedo_level( ch ) ) > -3 )
      || ( ( get_psuedo_level( ch ) - get_psuedo_level( victim ) ) > 20 ) )
      return FALSE;

   if ( ( IS_GOOD( ch )    && IS_GOOD( victim    ) )
   || (   IS_EVIL( ch )    && IS_EVIL( victim    ) )
   || (   IS_NEUTRAL( ch ) && IS_NEUTRAL( victim ) ) )
      return FALSE;

  if (  ( ch->spec_fun == spec_lookup( "spec_vamp_hunter" ) )
     && (  IS_NPC( victim ) )
     && ( number_percent() < 20 )  )
     return FALSE;
      
  if (  ( IS_SET( victim->in_room->room_flags, ROOM_SAFE ) )
     || ( IS_SET( victim->act, ACT_SOLO ) )
   /*  || ( IS_SET( victim->in_room->room_flags, ROOM_JAIL_CELL ) ) */  )
     return FALSE;

   return TRUE;
}


void    select_target( CHAR_DATA *ch )
{
   /* Find a new target for the group to go after */
   int        average_level;
   int        tmp   = 0;
   CHAR_DATA  *vch;
   CHAR_DATA  *victim = NULL;
   char       buf[MAX_STRING_LENGTH];
   int        force_index = 0;
   bool       alone   = TRUE;
   bool       mob_is_leader = FALSE;   

   /* mobs were doing ethereal travel too much... i've now lowered it to 
    * 15% of the time and only if they are not hunting */
   mob_is_leader = is_group_leader( ch );
   if (  ( number_percent() < 15 )
      && ( ch->hunting == NULL )
      && ( ch->in_room->vnum != ROOM_VNUM_ETHEREAL_PLANE )  )
/* was victim == NULL, that's always true at this point.. Zen */
   {
      if (  mob_is_leader == TRUE  ) 
      {
	 for (  vch = ch->in_room->first_person; vch != NULL;
		vch = vch->next_in_room  )
	 {
	    if (  ( is_same_group ( ch, vch ) ) == TRUE  )
	    {
	       if (  vch->mana < mana_cost ( vch, skill_lookup ( "ethereal travel") )  )
	       {
		 return;
	       }
	    }
	 }
      }
      if (  ch->mana < mana_cost ( ch, skill_lookup( "ethereal travel" ) )  )
	 return;

      do_say( ch, "This place is boring! I am gonna go somewhere else!" );
      for ( vch=ch->in_room->first_person; vch != NULL;  
	    vch=vch->next_in_room )
      {
	 if (  ( is_same_group(vch,ch) )
	    && ( ch != vch )   )
	 {
	    do_say( vch, "Yeah, it is--we're outta here!" );
	    do_cast( vch, "ethereal" );
	 }
      }    
      do_cast( ch, "ethereal" );
   }
   else
   {
      /* keeps checking until you've found a valid target */
      while (  victim == NULL  )
      {
	 for (  vch = ch->in_room->first_person; vch != NULL; 
		vch = vch->next_in_room  )
	 {
	    if ( is_same_group( ch, vch ) )
	    {
	       tmp += get_psuedo_level( vch );
	    }
	 }   
	 average_level = get_psuedo_level(ch)
			 +  (tmp - get_psuedo_level(ch)) / 4; 
    

	 /* Now find a target */

	 /* find random place in queue to start searching for victim */
/* nice idea, but wasteful of cycles, try this...
	 for (  vch = first_char; vch != NULL; vch = vch->next )
	 {  
	    force_index = force_index + 1;
	 }

	 force_index = ( force_index * number_percent()/100 );
*/
	 force_index = number_range( 1, 1200 );
/* we currently have about 1300 mobs..this should get a random enough sample */

	 for ( vch = first_char; vch != NULL; vch = vch->next )  
	 {
	    if ( victim != NULL )
	       break;
	    force_index = force_index - 1;
	    if ( force_index > 0 )
	       continue;

	    if ( valid_target( ch, vch, average_level ) )
	    {
	       /* Trick used in  something else... */
	       if (  number_range ( 0, 1 ) == 0  )
		  victim = vch;
	       if ( victim == NULL )  /* screwed up somehow */
		  continue;

	       if (  !IS_NPC( victim )  )
	       {   
		  for (  vch = ch->in_room->first_person; vch != NULL;
			 vch = vch->next_in_room  )
		  {
		     if (  is_same_group ( ch, vch )  )
		     {
			alone = FALSE;
			break;
		     }
		  }
		  if (  alone == FALSE  )
		  {
		     sprintf ( buf, "%s We're coming for you!", vch->name );
		     do_tell ( ch, buf );
		  }
		  else 
		  {
		     sprintf ( buf, "%s I'm coming for you!", vch->name );
		     do_tell ( ch, buf );
		  }
	       }  
	    }  
	 }
      }
   
      if ( set_hunt(ch, NULL, victim, NULL, 
	     HUNT_WORLD|HUNT_PICKDOOR|HUNT_CR, HUNT_MERC ) )
      {
	 sprintf( buf, "Right!  %s is our new target!!", 
		  victim->short_descr );
	 do_say( ch, buf );

  /* i thought mobs couldn't lose their targets anymore */
  /*    if ( h_find_dir(ch->in_room, victim->in_room, ch->hunt_flags) < 0
	   && number_percent() < 30 )
	{
	   end_hunt(ch);
	   do_say(ch, "We must choose another target.");
	}*/
      }
      return;
   }
   return;
}


/* i have condensed this function to just three states: MOB_FIGHTING, 
 * MOB_RESTING/ MOB_SLEEPING, and MOB_STANDING. each of these three states 
 * will call it's appropriate function. */
void int_handler ( CHAR_DATA *ch ) 
{
   int        current_state;

   current_state = ch->position;

   /* if you're fighting check on your condition */
   if (  current_state == POS_FIGHTING  )
   {
      mob_is_fighting ( ch );
      return;
   }

   /* if you are resting or sleeping, check to see if you need to stand up */
   if (  current_state != POS_STANDING  )
   {
      need_to_stand ( ch );
      return;
   }

   /* cheat so that players cannot get easy xp from almost dead int mobs */
   /* not sure where to place this yet -- will look at this later */
   if (  ch->hit < 100  )
   {
      ch->hit = ch->max_hit * 50/100;
      ch->mana = ch->max_mana * 50/100;
   }

   /* by now you should be standing */
   mob_is_standing ( ch );
   return;
   do_gossip( ch, "i'm doing nothing!" );
}
 
/* i've never learned cases before so i'm pretty much leaving this one 
 * alone, except for taking out the one_arguement() function */
void int_combat_handler ( CHAR_DATA *ch, CHAR_DATA *victim )
{
   /* Called from fight.c during combat to enable mobs to use spells and
      skills.  ACT_INTELLIGENT mobs can call cast() now.
      --Stephen   */

   char arg[MAX_STRING_LENGTH];
   char buf[MAX_STRING_LENGTH];
   CHAR_DATA  *vch;
   int sn;
   int counter = 1;
	 
   if ( number_percent() < 65 )
      return;

   for (  vch = ch->in_room->first_person; vch != NULL;
	  vch = vch->next_in_room  )
   {
      if (  vch == victim  )      
      {
	 sprintf( buf, "%d.%s", counter, vch->name );
	 break;
      }
      
      counter = counter + 1;
   }
	 
   switch( number_range( 0, 5 ) )       /* Pick a skill or a spell */
   {
      case 0:
      case 1:
      case 2:
      case 3:
	 /*  Use a skill */ 
	 switch( number_range( 0, 5 ) )
	 {
	    case 0:
	       sprintf( arg, "frenzy" );
	       break;
	    case 1:
	       sprintf( arg, "punch %s",        buf  );
	       break;
	    case 2:
	       sprintf( arg, "knee %s",         buf  );
	       break;
	    case 3:
	       sprintf( arg, "headbutt %s",     buf  );
	       break;
	    case 4:
	       sprintf( arg, "punch %s",        buf  );
	       break;
	    case 5:
	       sprintf( arg, "dirt %s",         buf  );
	       break;
	 }
	 interpret( ch, arg );
	 do_say ( ch, buf );
	 break;  
      default:   
	 sn = find_spell( ch, TAR_CHAR_OFFENSIVE );
	 if ( ( sn != -1 ) && ( ch->mana > mana_cost( ch, sn ) )   )
	 {
	    sprintf( arg, "cast '%s' %s", skill_table[sn].name, buf );
	    interpret( ch, arg );
	 }
   }
   return;   
}



   
