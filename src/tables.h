
extern unsigned long int table_lookup(const struct lookup_type *,char *);
extern char * rev_table_lookup(const struct lookup_type *, unsigned long int);
extern char * bit_table_lookup(const struct lookup_type *, unsigned long int);
extern void table_printout(const struct lookup_type *,char *);
extern void wide_table_printout( const struct lookup_type *, char * );  /* -S- mod */

extern const struct lookup_type tab_mob_class[];
extern const struct lookup_type tab_value_meanings[];
extern const struct lookup_type tab_drink_types[];
extern const struct lookup_type tab_weapon_types[];
extern const struct lookup_type tab_mob_flags[];
extern const struct lookup_type tab_affected_by[];
extern const struct lookup_type tab_item_types[];
extern const struct lookup_type tab_obj_flags[];
extern const struct lookup_type tab_wear_flags[];
extern const struct lookup_type tab_item_apply[];
extern const struct lookup_type tab_wear_loc[];
extern const struct lookup_type tab_obj_aff[];
extern const struct lookup_type tab_room_flags[];
extern const struct lookup_type tab_sector_types[];
extern const struct lookup_type tab_door_types[];
extern const struct lookup_type tab_door_states[];
extern const struct lookup_type tab_player_flags[];
extern const struct lookup_type tab_mob_skill[];
extern const struct lookup_type tab_mob_cast[];
extern const struct lookup_type tab_cast_name[];
extern const struct lookup_type tab_mob_def[];
