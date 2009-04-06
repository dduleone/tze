#if defined(macintosh)
#include <types.h>
#else
#include <sys/types.h>
#endif
#include <stdio.h>
#include <time.h>
#include "merc.h"

/*
 * All of the global linked lists, in one clump.  Variables here,
 * declarations in lists.h
 * -- Altrag
 */
AREA_DATA *		first_area = NULL;
AREA_DATA *		last_area = NULL;
BAN_DATA *		first_ban = NULL;
BAN_DATA *		last_ban = NULL;
CHAR_DATA *		first_char = NULL;
CHAR_DATA *		last_char = NULL;
DESCRIPTOR_DATA *	first_desc = NULL;
DESCRIPTOR_DATA *	last_desc = NULL;
HELP_DATA *		first_help = NULL;
HELP_DATA *		last_help = NULL;
NOTE_DATA *		first_note = NULL;
NOTE_DATA *		last_note = NULL;
OBJ_DATA *		first_obj = NULL;
OBJ_DATA *		last_obj = NULL;
SHOP_DATA *		first_shop = NULL;
SHOP_DATA *		last_shop = NULL;
CORPSE_DATA *		first_corpse = NULL;
CORPSE_DATA *		last_corpse = NULL;
MARK_DATA *		first_mark = NULL;
MARK_DATA *		last_mark = NULL;
MARK_LIST_MEMBER *	first_mark_list = NULL;
MARK_LIST_MEMBER *	last_mark_list = NULL;
CONTROL_LIST	*	first_control_list = NULL;
CONTROL_LIST	*	last_control_list = NULL;
QUEUED_INTERACT_LIST *	first_queued_interact = NULL;
QUEUED_INTERACT_LIST *	last_queued_interact = NULL;
INFLUENCE_LIST	*	first_influence_list = NULL;
INFLUENCE_LIST	*	last_influence_list = NULL;
RULER_LIST	*	first_ruler_list = NULL;
RULER_LIST	*	last_ruler_list = NULL;
DL_LIST		*	first_brand = NULL;
DL_LIST		*	last_brand = NULL;


PORTAL_DATA *		portal_free = NULL;
AFFECT_DATA *		affect_free = NULL;
ROOM_AFFECT_DATA *	raffect_free = NULL;
AREA_DATA *		area_free = NULL;
BAN_DATA *		ban_free = NULL;
CHAR_DATA *		char_free = NULL;
DESCRIPTOR_DATA *	desc_free = NULL;
EXIT_DATA *		exit_free = NULL;
EXTRA_DESCR_DATA *	exdesc_free = NULL;
HELP_DATA *		help_free = NULL;
MOB_INDEX_DATA *	mid_free = NULL;
NOTE_DATA *		note_free = NULL;
OBJ_DATA *		obj_free = NULL;
OBJ_INDEX_DATA *	oid_free = NULL;
PC_DATA *		pcd_free = NULL;
RESET_DATA *		reset_free = NULL;
ROOM_INDEX_DATA *	rid_free = NULL;
SHOP_DATA *		shop_free = NULL;
MPROG_DATA *		mprog_free = NULL;
MPROG_ACT_LIST *	mpact_free = NULL;
BUILD_DATA_LIST *	build_free = NULL;
MAGIC_SHIELD *		shield_free = NULL;
MEMBER_DATA *            member_free = NULL;
CORPSE_DATA *		corpse_free = NULL;
MARK_DATA *		mark_free = NULL;
MARK_LIST_MEMBER *	mark_list_free = NULL;
INTERACT_DATA *		interact_free = NULL;
INFLUENCE_DATA	*	influence_free= NULL;
RULER_DATA	*	ruler_data_free = NULL;
CONTROL_DATA	*	control_data_free = NULL;
CONTROL_LIST	*	control_list_free = NULL;
QUEUED_INTERACT_LIST *	queued_interact_free = NULL;
INFLUENCE_LIST	*	influence_list_free = NULL;
RULER_LIST	*	ruler_list_free = NULL;
DL_LIST		*	dl_list_free = NULL;
BRAND_DATA	*	brand_data_free = NULL;


CHAR_DATA *		violence_marker = NULL;



