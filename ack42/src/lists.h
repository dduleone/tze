/*
 * All of the global linked lists, in one clump.  Declarations here,
 * actual variables in lists.c
 * -- Altrag
 */
extern	AREA_DATA *		first_area;
extern	AREA_DATA *		last_area;
extern	BAN_DATA *		first_ban;
extern	BAN_DATA *		last_ban;
extern	CHAR_DATA *		first_char;
extern	CHAR_DATA *		last_char;
extern	DESCRIPTOR_DATA *	first_desc;
extern	DESCRIPTOR_DATA *	last_desc;
extern	HELP_DATA *		first_help;
extern	HELP_DATA *		last_help;
extern	NOTE_DATA *		first_note;
extern	NOTE_DATA *		last_note;
extern	OBJ_DATA *		first_obj;
extern	OBJ_DATA *		last_obj;
extern	SHOP_DATA *		first_shop;
extern	SHOP_DATA *		last_shop;
extern	CORPSE_DATA *		first_corpse;
extern	CORPSE_DATA *		last_corpse;
extern	MARK_LIST_MEMBER *	first_mark_list;
extern	MARK_LIST_MEMBER *	last_mark_list;
extern	CONTROL_LIST	*	first_control_list;
extern	CONTROL_LIST	*	last_control_list;
extern	QUEUED_INTERACT_LIST *	first_queued_interact;
extern	QUEUED_INTERACT_LIST *	first_queued_interact;
extern	INFLUENCE_LIST	*	first_influence_list;
extern	INFLUENCE_LIST	*	last_influence_list;
extern	RULER_LIST	*	first_ruler_list;
extern	RULER_LIST	*	last_ruler_list;
extern	DL_LIST		*	first_brand;
extern	DL_LIST		*	last_brand;



extern	PORTAL_DATA *		portal_free;
extern	AFFECT_DATA *		affect_free;
extern	ROOM_AFFECT_DATA *	raffect_free;
extern	AREA_DATA *		area_free;
extern	BAN_DATA *		ban_free;
extern	CHAR_DATA *		char_free;
extern	DESCRIPTOR_DATA *	desc_free;
extern	EXIT_DATA *		exit_free;
extern	EXTRA_DESCR_DATA *	exdesc_free;
extern	HELP_DATA *		help_free;
extern	MOB_INDEX_DATA *	mid_free;
extern	NOTE_DATA *		note_free;
extern	OBJ_DATA *		obj_free;
extern	OBJ_INDEX_DATA *	oid_free;
extern	PC_DATA *		pcd_free;
extern	RESET_DATA *		reset_free;
extern	ROOM_INDEX_DATA *	rid_free;
extern	SHOP_DATA *		shop_free;
extern	MPROG_DATA *		mprog_free;
extern	MPROG_ACT_LIST *	mpact_free;
extern	BUILD_DATA_LIST *	build_free;
extern	MAGIC_SHIELD *		shield_free;
extern	MEMBER_DATA * 		member_free;
extern	CORPSE_DATA *		corpse_free;
extern	MARK_DATA *		mark_free;
extern	MARK_LIST_MEMBER *	mark_list_free;
extern  INTERACT_DATA *		interact_free;
extern  INFLUENCE_DATA	*	influence_free;
extern  RULER_DATA	*	ruler_data_free;
extern  CONTROL_DATA	*	control_data_free;
extern  CONTROL_LIST	*	control_list_free;
extern  QUEUED_INTERACT_LIST *	queued_interact_free;
extern  INFLUENCE_LIST	*	influence_list_free;
extern  RULER_LIST	*	ruler_list_free;
extern	DL_LIST *		dl_list_free;
extern	BRAND_DATA *		brand_data_free;




extern  bool			booting_up;

extern char *  const   dir_name        []; 
extern char *  const   rev_name        []; 

#define GET_FREE(item, freelist) \
do { \
  if ( !(freelist) ) \
    (item) = getmem(sizeof(*(item))); \
  else { \
    if ( !(freelist)->is_free ) { \
      bug("GET_FREE: freelist head is NOT FREE!  Hanging...", 0); \
      for (;;); \
    } \
    (item) = (freelist); \
    (freelist) = (item)->next; \
    memset((item), 0, sizeof(*(item))); /* This clears is_free flag */ \
  } \
} while(0)

#define PUT_FREE(item, freelist) \
do { \
  if ( (item)->is_free ) { \
    bug("PUT_FREE: item is ALREADY FREE!  Hanging...", 0); \
    for (;;); \
  } \
  (item)->next = (freelist); \
  (item)->is_free = TRUE; /* This sets is_free flag */ \
  (freelist) = (item); \
} while(0)
