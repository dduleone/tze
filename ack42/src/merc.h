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
 *                                                 Version #: 2.01         *
 *                                                                         *
 *  Much time and thought has gone into this software and you are          *
 *  benefitting.  We hope that you share your changes too.  What goes      *
 *  around, comes around.                                                  *
 ***************************************************************************/


/*
 * Accommodate old non-Ansi compilers.
 */
#define args( list )                    list
#define DECLARE_DO_FUN( fun )           DO_FUN    fun
#define DECLARE_SPEC_FUN( fun )         SPEC_FUN  fun
#define DECLARE_SPELL_FUN( fun )        SPELL_FUN fun
#define DECLARE_OBJ_FUN( fun )          OBJ_FUN   fun


/*
 * Short scalar types.
 * Diavolo reports AIX compiler has bugs with short types.
 */
#if     !defined(NOWHERE)
#define NOWHERE -1
#endif

#if     !defined(FALSE)
#define FALSE    0
#endif

#if     !defined(TRUE)
#define TRUE     1
#endif

typedef unsigned char                   bool;

/*
 *  Your mud info here :) Zen
 */

#define mudnamecolor  "@@lYour Mud Name@@N"
#define mudnamenocolor  "Your Mud name"
#define sacgodname  "Cyberlich"
#define goodgodname  "Freyja"
#define neutralgodname  "Zenithar"
#define evilgodname  "Oderus"

/*
 * String and memory management parameters.
 */
#define MAX_KEY_HASH             2048
#define MAX_STRING_LENGTH        8192
#define MSL			MAX_STRING_LENGTH
#define MAX_INPUT_LENGTH          640
#define MAX_AREAS                 200
#define MAX_VNUM 32767

#define BOOT_DB_ABORT_THRESHOLD			  25
#define RUNNING_ABORT_THRESHOLD			  10
#define ALARM_FREQUENCY                           20

/*
 * Game parameters.
 * Increase the max'es if you add more of something.
 * Adjust the pulse numbers to suit yourself.
 */

#define MAX_CLAN_EQ		     6  /* Number of clan eq items */
#define MAX_COLOUR		    15  /* eg look, prompt, shout */
#define MAX_ANSI		    20  /* eg red, black, etc (was 11) */
#define MAX_ALIASES		     6
#define MAX_IGNORES		     3
#define MAX_RACE                     14
#define MAX_CLAN                     9  /* number of clans */
#define EXP_LEVEL                 1000  /* exp per level */
#define MAX_SKILL                  300
#define MAX_CLASS                    5
#define MAX_LEVEL                   85
#define MOUNT_COST                  10
#define LEVEL_HERO                 (MAX_LEVEL - 4)
#define LEVEL_IMMORTAL             (MAX_LEVEL - 3)
#define MAX_VAMP_LEVEL              20
#define MAX_WOLF_LEVEL		    20
#define ADVANCE_VAMP                16
#define ADVANCE_ADEPT               32
#define ADVANCE_WOLF		    64
#define MAX_FAMILY                   5
#define MAX_TRIBE		     5
#define MAX_SUPER                    4
#define MAX_STANCE		11
                     /* total number of supernatural types in the game  */
#define QUORUM_NUMBER			4
                     /* number of members to be a quorum for a council */

/*
 * Well known mob virtual numbers.
 * Defined in #MOBILES.
 */
#define MOB_VNUM_CITYGUARD         3060
#define MOB_VNUM_VAMPIRE           3404
#define MOB_VNUM_DOGGY             99
#define MOB_VNUM_ZOMBIE 	  11004
#define MOB_VNUM_STALKER	   32
#define MOB_VNUM_WATERELEM        1028
#define MOB_VNUM_SKELETON         1028
#define MOB_VNUM_FIREELEM         1028
#define MOB_VNUM_TRAINER		1042
#define MOB_VNUM_EARTHELEM		1028
#define MOB_VNUM_IRON_GOLEM		1029
#define MOB_VNUM_SOUL_THIEF		1030
#define MOB_VNUM_HOLY_AVENGER		1031
#define MOB_VNUM_PEGASUS		1037
#define MOB_VNUM_NIGHTMARE		1038
#define MOB_VNUM_ELEM_BEAST		1039
#define MOB_VNUM_INT_DEVOURER		1040
#define MOB_VNUM_SHADOW_HOUND		1041


#define MOB_VNUM_DIAMOND_GOLEM	1032
#define MOB_VNUM_COMBAT_ELEMENTAL 1036   /* this needs to be a new mob ZENFIX */

/*
 * vnums for quest items.
 * One of these will be picked at random and placed onto a random mob
 * (one the player has a chance of killing!).
 * Reserve vnums 40-60 for this.
 * We'll define a range of possible vnums here - easier to expand (:
 */

#define OBJ_VNUM_QUEST_MIN		18181
#define OBJ_VNUM_QUEST_MAX		18192   /* more to follow, up to 18199  */


#define PULSE_PER_SECOND             8
#define PULSE_VIOLENCE            (  2 * PULSE_PER_SECOND )
#define PULSE_MOBILE              (  4 * PULSE_PER_SECOND )
#define PULSE_OBJFUN		  (  4 * PULSE_PER_SECOND )
#define PULSE_TICK                ( 60 * PULSE_PER_SECOND )
#define PULSE_MESSAGE		  ( 12 * PULSE_PER_SECOND )
#define PULSE_ROOMS		  ( 30 * PULSE_PER_SECOND )
#define PULSE_AREA                ( 80 * PULSE_PER_SECOND )
#define PULSE_AUCTION		  ( 30 * PULSE_PER_SECOND )
#define PULSE_RAUCTION            ( 30 * PULSE_PER_SECOND )
#define PULSE_MAUCTION            ( 30 * PULSE_PER_SECOND )

#define VAMPIRE_RECALL		 9001
#define LIQUID_BLOOD		 13
#define WOLF_RECALL          3001

/*
 * Well known object virtual numbers.
 * Defined in #OBJECTS.
 */
#define OBJ_VNUM_MONEY_ONE            2
#define OBJ_VNUM_MONEY_SOME           3

#define OBJ_VNUM_CORPSE_NPC          10
#define OBJ_VNUM_CORPSE_PC           11
#define OBJ_VNUM_SEVERED_HEAD        12
#define OBJ_VNUM_TORN_HEART          13
#define OBJ_VNUM_SLICED_ARM          14
#define OBJ_VNUM_SLICED_LEG          15
#define OBJ_VNUM_FINAL_TURD          16

#define OBJ_VNUM_MUSHROOM            20
#define OBJ_VNUM_LIGHT_BALL          21
#define OBJ_VNUM_SPRING              19

#define OBJ_VNUM_BOARD               23
#define OBJ_VNUM_FOOD		     30
#define OBJ_VNUM_FIREBLADE	     31
#define OBJ_VNUM_TOKEN		     32	/* For old chars */
#define OBJ_VNUM_WINDOW		     33
#define OBJ_VNUM_PORTAL		     34
#define OBJ_VNUM_BEACON		     35 

#define OBJ_VNUM_SCHOOL_MACE       3700
#define OBJ_VNUM_SCHOOL_DAGGER     3701
#define OBJ_VNUM_SCHOOL_SWORD      3702
#define OBJ_VNUM_SCHOOL_VEST       3703
#define OBJ_VNUM_SCHOOL_SHIELD     3704
#define OBJ_VNUM_SCHOOL_BANNER     3716
#define OBJ_VNUM_SOUL_POTION       37
#define OBJ_VNUM_CAPTURED_SOUL     38
#define OBJ_VNUM_CONFLAGRATION	   1036   /* need a staff here  ZENFIX */

/*
 * Well known room virtual numbers.
 * Defined in #ROOMS.
 */
#define ROOM_VNUM_LIMBO               2
#define ROOM_VNUM_CHAT             1200
#define ROOM_VNUM_TEMPLE           3001
#define ROOM_VNUM_ALTAR            3054
#define ROOM_VNUM_SCHOOL           3700
#define ROOM_VNUM_DONATION         3206
#define ROOM_VNUM_MORGUE           3300
#define ROOM_VNUM_MORIBUND         3301
#define ROOM_VNUM_BUILDER	   1019 /* Bulder-flagged players only */
#define ROOM_VNUM_BODIES	   30   /* for morphed players */
#define ROOM_VNUM_CLAN		   1022 /* for leaders only */
#define ROOM_VNUM_DM_RECALL       3001
#define ROOM_VNUM_ETHEREAL_PLANE  3850
#define ROOM_VNUM_INT_HEAL		3871
#define ROOM_VNUM_MID_BOTTOM		3001
#define ROOM_VNUM_MID_TOP		3200
#define ROOM_VNUM_JAIL                  2



#define STANCE_WARRIOR		0
#define STANCE_CASTER		1
#define STANCE_AMBUSH		2
#define STANCE_AC_BEST		3
#define STANCE_HR_BEST		4
#define STANCE_DR_BEST		5
#define STANCE_AC_WORST		6
#define STANCE_HR_WORST		7
#define STANCE_DR_WORST		8
#define STANCE_SUPER_FIGHTER	9
#define STANCE_SUPER_SPEED	10



/*
 *  SSM stuff
 */

#define STR(x) #x
#define SX(x) STR(x)
#define _caller __FILE__ ":" SX(__LINE__)

#define fread_string(x) _fread_string((x), _caller)
char *_fread_string args((FILE * fp, const char *caller));
#define str_dup(x) _str_dup((x), _caller)
char *_str_dup args((const char *str, const char *caller));
#define fread_string_eol(x) _fread_string_eol((x), _caller)
char *_fread_string_eol args((FILE * fp, const char *caller));
#define free_string(x) _free_string((x), _caller)
void _free_string args((char *pstr, const char *caller));




/* YUCK! */
extern char *target_name;


/*
 * Structure types.
 */
typedef struct  portal_data		PORTAL_DATA;
typedef struct  affect_data             AFFECT_DATA;
typedef struct  room_affect_data	ROOM_AFFECT_DATA;
typedef struct  area_data               AREA_DATA;
typedef struct  ban_data                BAN_DATA;
typedef struct  char_data               CHAR_DATA;
typedef struct  descriptor_data         DESCRIPTOR_DATA;
typedef struct  exit_data               EXIT_DATA;
typedef struct  extra_descr_data        EXTRA_DESCR_DATA;
typedef struct  help_data               HELP_DATA;
typedef struct  kill_data               KILL_DATA;
typedef struct  mob_index_data          MOB_INDEX_DATA;
typedef struct  note_data               NOTE_DATA;
typedef struct  obj_data                OBJ_DATA;
typedef struct  obj_index_data          OBJ_INDEX_DATA;
typedef struct  pc_data                 PC_DATA;
typedef struct  reset_data              RESET_DATA;
typedef struct  room_index_data         ROOM_INDEX_DATA;
typedef struct  shop_data               SHOP_DATA;
typedef struct  time_info_data          TIME_INFO_DATA;
typedef struct  weather_data            WEATHER_DATA;
typedef struct  mob_prog_data           MPROG_DATA;         /* MOBprogram */
typedef struct  mob_prog_act_list       MPROG_ACT_LIST;     /* MOBprogram */
/* MAG Mod */
typedef struct  build_data_list         BUILD_DATA_LIST; /* Online Building */
typedef struct  mobprog_item            MOBPROG_ITEM;    /* Mobprogs */

/* Zen Mod */
typedef struct  vamp_exp_table          VAMP_EXP_TABLE;
typedef struct  magic_shield            MAGIC_SHIELD;
typedef struct  politics_data_type      POL_DATA;
typedef struct  council_data		COUNCIL_DATA;
typedef struct  member_data		MEMBER_DATA;
typedef struct  trigger_data		TRIGGER_DATA;
typedef struct  corpse_data		CORPSE_DATA;
typedef	struct	mark_data		MARK_DATA;
typedef struct	mark_list_member	MARK_LIST_MEMBER;

typedef struct  message_data            MESSAGE_DATA;
typedef struct  board_data              BOARD_DATA;
typedef struct	control_data		CONTROL_DATA;
typedef struct	ruler_data		RULER_DATA;
typedef struct	influence_data		INFLUENCE_DATA;
typedef struct	interact_data		INTERACT_DATA;
typedef	struct	influence_list		INFLUENCE_LIST;
typedef struct	control_list		CONTROL_LIST;
typedef struct	queued_interact_list	QUEUED_INTERACT_LIST;
typedef	struct	ruler_list		RULER_LIST;
typedef struct	dl_list			DL_LIST;
typedef struct	brand_data		BRAND_DATA;




/* Llolth were code <--replaced with Ackmud 4.0 upgrade 
typedef struct  were_exp_table          WERE_EXP_TABLE;

*/

/* Use these for bitvectors..saves having to recalculate each time :) Zen */

#define		BIT_0		0
#define		BIT_1		1
#define		BIT_2		2
#define		BIT_3		4
#define		BIT_4		8
#define		BIT_5		16
#define		BIT_6		32
#define		BIT_7		64
#define		BIT_8		128
#define		BIT_9		256
#define		BIT_10		512
#define		BIT_11		1024
#define		BIT_12		2048
#define		BIT_13		4096
#define		BIT_14		8192
#define		BIT_15		16384
#define		BIT_16		32768
#define		BIT_17		65536
#define		BIT_18		131072
#define		BIT_19		262144
#define		BIT_20		524288
#define		BIT_21		1048576
#define		BIT_22		2097152
#define		BIT_23		4194304
#define		BIT_24		8388608
#define		BIT_25		16777216
#define		BIT_26		33554432
#define		BIT_27		67108864
#define		BIT_28		134217728
#define		BIT_29		268435456
#define		BIT_30		536870912
#define		BIT_31		1073741824
#define		BIT_32		2147483648

/*
 * Function types.
 */
typedef void DO_FUN     args( ( CHAR_DATA *ch, char *argument ) );
typedef bool SPEC_FUN   args( ( CHAR_DATA *ch ) );
typedef bool SPELL_FUN  args( ( int sn, int level, CHAR_DATA *ch, void *vo, OBJ_DATA *obj ) );
typedef void OBJ_FUN    args( ( OBJ_DATA *obj, CHAR_DATA *keeper ) );



#define SUPER_NONE			0
#define SUPER_VAMP			1
#define SUPER_WOLF			2
#define SUPER_BLESSED			3

/* defines for enchant.c  */
#define ENCHANT_EXTRA_FLAGS	-1
#define ENCHANT_APPLY_FLAGS	-2
#define ENCHANT_OBJFUNS		-3



/* These are for skill_table lookup funcs... to save writing 2 functions */
#define RETURN_BEST_LEVEL	1
#define RETURN_BEST_CLASS	2

/*
 * God Levels
 */
#define L_GOD           MAX_LEVEL
#define L_SUP           L_GOD - 1
#define L_DEI           L_SUP - 1
#define L_ANG           L_DEI - 1
#define L_HER           L_ANG - 1

#define CLAN_ONLY	 -1
#define BOSS_ONLY	 -2
#define VAMP_ONLY	 -3
#define WOLF_ONLY	 -4





/*
 * Updated pointer referencing, curtesy of Spectrum, from Beyond the Veil
 *
 */

#define OBJ_NEXT          1
#define OBJ_NEXTCONTENT   2
#define OBJ_NULL          3

struct obj_ref_type
{
  bool inuse;
  struct obj_ref_type *next;
  OBJ_DATA **var;
  int type;                    /* OBJ_xxxx */
};

#define CHAR_NEXT         1
#define CHAR_NEXTROOM     2
#define CHAR_NULL         3

struct char_ref_type
{
  bool inuse;
  struct char_ref_type *next;
  CHAR_DATA **var;
  int type;
};

#define OREF(v, type) do { \
static struct obj_ref_type s={FALSE,NULL,NULL,type}; s.var=&v; \
obj_reference(&s); } while(0)
#define OUREF(var) obj_unreference(&var);

#define CREF(v, type) do { \
static struct char_ref_type s={FALSE,NULL,NULL,type}; s.var=&v; \
char_reference(&s); } while(0)
#define CUREF(var) char_unreference(&var);


struct board_data
{
    bool	    is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    BOARD_DATA   *  next;
    BOARD_DATA	 *  prev;
    int             vnum;
    MESSAGE_DATA *  first_message;
    MESSAGE_DATA *  last_message;
    int             min_read_lev;
    int             min_write_lev;
    int             expiry_time;
    int             clan; 
};

struct message_data
{
    bool	    is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    MESSAGE_DATA *  next;
    MESSAGE_DATA *  prev;        /* Only used in save_board */
    BOARD_DATA   *  board;
    time_t          datetime;
    char         *  author;
    char         *  title;
    char         *  message;
    
};



/*
 * Colour look-up table structure thingy.
 */

struct colour_type
{
   char *      name;		/* eg, gossip, say, look */
   int        index;		/* unique index */
};

struct ansi_type
{
   char *	name;
   char	*	value;		/* escape sequence, or whatever */
   int 		index;
   char         letter;
   int          stlen;
};

#define COLOUR_NORMAL "\033[0m"

/* Structure for material/strengths */
struct	material_type
{
   char *	name;		/* Name of the material */
   char *	descrip;	/* Descr. of how strong it is */
   int		quality;	/* 0 = crap, 100 = non-breakable */
};

#define NO_MATERIAL	10	/* Number of materials */   

struct dl_list
{
  bool		is_free;
  DL_LIST *	next;
  DL_LIST *	prev;
  void *	this_one;
};

/*
 * Site ban structure.
 */
struct  ban_data
{
    bool	is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    BAN_DATA *  next;
    BAN_DATA *	prev;
    char *      name;
    char *	banned_by;
    bool	newbie;
};

struct brand_data
{
  bool		is_free;
  BRAND_DATA *	next;
  BRAND_DATA *	prev;
  char *	branded;
  char *	branded_by;
  char *	dt_stamp;
  char *	message;
  char *	priority;
};


/*
 * Time and weather stuff.
 */
#define SUN_DARK                    0
#define SUN_RISE                    1
#define SUN_LIGHT                   2
#define SUN_SET                     3

#define SKY_CLOUDLESS               0
#define SKY_CLOUDY                  1
#define SKY_RAINING                 2
#define SKY_LIGHTNING               3

#define MOON_DOWN	0
#define MOON_RISE	1
#define MOON_LOW	2
#define MOON_PEAK	3
#define MOON_FALL	4
#define MOON_SET	5


#define MOON_NEW	0
#define MOON_WAX_CRE	1
#define MOON_WAX_HALF	2
#define MOON_WAX_GIB	3
#define MOON_FULL	4
#define MOON_WAN_GIB	5
#define MOON_WAN_HALF	6
#define MOON_WAN_CRE	7



struct  time_info_data
{
    int         hour;
    int         day;
    int         month;
    int         year;
    int		moon;
};

struct  weather_data
{
    int         mmhg;
    int         change;
    int         sky;
    int         sunlight;
    int		moon_phase;
    int		moon_loc;
    bool	phase_changed;
};

struct corpse_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    CORPSE_DATA *	next;
    CORPSE_DATA *	prev;
    OBJ_DATA *		this_corpse;
};

struct member_data
{
    bool	is_free; /* Ramias:for run-time checks of LINK/UNLINK */
  CHAR_DATA   * this_member;
  MEMBER_DATA * next;
  MEMBER_DATA * prev;
};

struct mark_data
{
  bool		is_free;
  int		room_vnum;
  char		*message;
  char		*author;
  short	duration;
  short	type;    /* VAMP, WOLF */
  MARK_DATA *	next;
  MARK_DATA *	prev; /* for freelist only */
};

struct mark_list_member
{
  bool		is_free;
  MARK_LIST_MEMBER *	next;
  MARK_LIST_MEMBER *	prev;
  MARK_DATA	*	mark;
};


struct council_data
{
      char		* council_name;
	MEMBER_DATA	* first_member;
      MEMBER_DATA	* last_member;   
      bool		  quorum;
      short	  council_time;
};



/*
 * Connected state for a channel.
 */

/* These values referenced by users command, BTW */

#define CON_PLAYING                      0
#define CON_GET_NAME                     -1
						/* All non connected */
#define CON_GET_OLD_PASSWORD             -2
						/* states changed to  */
#define CON_CONFIRM_NEW_NAME             -3
						/* negative so that   */
#define CON_GET_NEW_PASSWORD             -4
						/* Hotboot can shut out */
#define CON_CONFIRM_NEW_PASSWORD         -5
						/* All nonplaying chars */
#define CON_GET_NEW_SEX                  -6
						/* ---Flar */
#define CON_GET_NEW_CLASS                -7
#define CON_GET_RACE                     -9
#define CON_READ_MOTD                   -10
#define CON_GET_STATS                   -11
#define CON_FINISHED			-12
#define CON_MENU		        -13
#define CON_COPYOVER_RECOVER		-14
						/* For Hotreboot */
#define CON_QUITTING			-15
#define CON_RECONNECTING                -16
#define CON_SETTING_STATS		1

/* values used to check a new player has selected all options.... */
#define CHECK_RACE			  1
#define CHECK_CLASS			  2
#define CHECK_SEX			  4
#define CHECK_STATS			  8



/*
 * Descriptor (channel) structure.
 */
struct  descriptor_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    DESCRIPTOR_DATA *   next;
    DESCRIPTOR_DATA *	prev;
    DESCRIPTOR_DATA *   snoop_by;
    CHAR_DATA *         character;
    CHAR_DATA *         original;
    char *              host;
    short              descriptor;
    short              connected;
    bool                fcommand;
    char                inbuf           [4 * MAX_INPUT_LENGTH];
    char                incomm          [MAX_INPUT_LENGTH];
    char                inlast          [MAX_INPUT_LENGTH];
    int                 repeat;
    char *              showstr_head;
    char *              showstr_point;
    char *              outbuf;
    int                 outsize;
    int                 outtop;
    unsigned int	remote_port;	/* 'Pair Port' ? -S- */
    int			check;		/* For new players*/
    int                 flags;
    int                 childpid;     /* Child process id */
    time_t		timeout;
};

#define DESC_FLAG_PASSTHROUGH 1     /* Used when data is being passed to */
				     /*	Another prog.                     */



struct family_name_type
{
     char * name;
     short clan_enemy;

};

struct politics_data_type
{

  short	diplomacy[MAX_CLAN] [MAX_CLAN];
  bool	daily_negotiate_table[MAX_CLAN] [MAX_CLAN];
  long int	treasury[MAX_CLAN];
  bool      end_current_state[MAX_CLAN][MAX_CLAN];
};

struct	stance_app_type
{
  char *	name;
  short	ac_mod;
  short	dr_mod;
  short	hr_mod;
  short	speed_mod;
};


/*
 * Attribute bonus structures.
 */
struct  str_app_type
{
    short      tohit;
    short      todam;
    short      carry;
    short      wield;
};

struct  int_app_type
{
    short      learn;
    short	spell_mod;
    short	mana_regen;
};

struct  wis_app_type
{
    short      practice;
    short	spell_save;
};

struct  dex_app_type
{
    short      defensive;
};

struct  con_app_type
{
    short      hitp;
    short      shock;
};



/*
 * TO types for act.
 */
#define TO_ROOM             0
#define TO_NOTVICT          1
#define TO_VICT             2
#define TO_CHAR             3



/*
 * Help table types.
 */
struct  help_data
{
    bool	is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    HELP_DATA * next;
    HELP_DATA *	prev;
    short      level;
    char *      keyword;
    char *      text;
};



/*
 * Shop types.
 */
#define MAX_TRADE        5

struct  shop_data
{
    bool	is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    SHOP_DATA * next;                   /* Next shop in list            */
    SHOP_DATA *	prev;			/* Prev shop in list		*/
    short      keeper;                 /* Vnum of shop keeper mob      */
    short      buy_type [MAX_TRADE];   /* Item types shop will buy     */
    short      profit_buy;             /* Cost multiplier for buying   */
    short      profit_sell;            /* Cost multiplier for selling  */
    short      open_hour;              /* First opening hour           */
    short      close_hour;             /* First closing hour           */
};






/*
 * Per-class stuff.
 */
struct  class_type
{
    char        who_name        [4];    /* Three-letter name for 'who'  */
    char     *  class_name;             /* Full name                    */
    short      attr_prime;             /* Prime attribute              */
    char     *  attr;			/* Prime 			*/
    short      weapon;                 /* First weapon                 */
    short      guild;                  /* Vnum of guild room           */
    short      skill_adept;            /* Maximum skill level          */
    short      thac0_00;               /* Thac0 for level  0           */
    short      thac0_32;               /* Thac0 for level 32           */
    short      hp_min;                 /* Min hp gained on leveling    */
    short      hp_max;                 /* Max hp gained on leveling    */
    bool        fMana;                  /* Class gains mana on level    */
    char     *  skill1;			/* Auto-learnt skill if any     */
};
#define RACE_MOD_NONE		BIT_0
#define RACE_MOD_FAST_HEAL	BIT_1
#define RACE_MOD_SLOW_HEAL	BIT_2
#define RACE_MOD_STRONG_MAGIC	BIT_3
#define RACE_MOD_WEAK_MAGIC	BIT_4
#define RACE_MOD_NO_MAGIC	BIT_5
#define RACE_MOD_IMMUNE_POISON  BIT_6
#define RACE_MOD_RESIST_SPELL	BIT_7
#define RACE_MOD_WOODLAND	BIT_8
#define RACE_MOD_DARKNESS	BIT_9
#define RACE_MOD_HUGE		BIT_10
#define RACE_MOD_LARGE		BIT_11
#define RACE_MOD_TINY		BIT_12
#define RACE_MOD_SMALL		BIT_13
#define RACE_MOD_TAIL		BIT_14



struct race_type
{
    char        race_name       [4];    /* Three letter name for race */
    char    *   race_title;             /* Full race name */
    short      recall;                 /* Race's recall location */
    short      race_room;              /* vnum of race-only room */
    short      race_str;               /* max_str to use for race */
    short      race_int;
    short      race_wis;
    short      race_dex;
    short      race_con;
    int         race_flags;               /* flags for the various racial stuff    */
    int         classes;                /* Number of classes for race   */
    short      limit[MAX_CLASS];        /* Max for each class */    
    char   *    comment;		/* comments shown for new players */
    char   *    skill1;
    
};

struct clan_type
{
    char    *   clan_name;              /* The name of the Clan */
    char    *   clan_abbr;              /* Abbrev. name - FIVE CHARS */   
    short      donat_room;             /* clan donation */
    short      clan_room;              /* Clan-only room */
    char    *   leader;                 /* Clan leader */
    char    *   enemies;		/* Enemies (if any) */
    int		eq[MAX_CLAN_EQ];	/* vnums of objects to load */

};


struct exp_type
{
   int          mob_base;               /* Base exp for mob of level x  */
   int          exp_base[MAX_CLASS];    /* Cost for each class of level */
};



/*
 * Data structure for notes.
 */
struct  note_data
{
    bool	is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    NOTE_DATA * next;
    NOTE_DATA *	prev;
    char *      sender;
    char *      date;
    char *      to_list;
    char *      subject;
    char *      text;
    time_t      date_stamp;
};

/*
 *   Spell Damage Types
 *
 */

#define SPELL_DAM_UNDEFINED	0
#define SPELL_DAM_FIRE		1
#define SPELL_DAM_SHOCK		2
#define SPELL_DAM_LIGHT		3
#define SPELL_DAM_GAS		4
#define SPELL_DAM_POISON	5
#define SPELL_DAM_COLD		6
#define SPELL_DAM_SOUND		7
#define SPELL_DAM_ACID		8


/*
 * An affect.
 */
struct  affect_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    AFFECT_DATA *       next;
    AFFECT_DATA *	prev;
    short              type;
    short              duration;
    short              location;
    short              modifier;
    int                 bitvector;
    CHAR_DATA 	*	caster;
    int			level;	
};

struct  room_affect_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    ROOM_AFFECT_DATA *	next;
    ROOM_AFFECT_DATA *	prev;
    short		duration;
    short		level;
    int		type;
    int		bitvector;
    int           applies_spell;  /* what spell is cast on a ch by the room..a sn */
    short        modifier;
    short        location;
    CHAR_DATA   * caster;

};
		


/*
 * A kill structure (indexed by level).
 */
struct  kill_data
{
    short              number;
    short              killed;
};

/* Magic Shield types
	-Damane 4/27/96 */
#define SHIELD_NONE	0
#define FLAME_SHIELD	1
#define SHOCK_SHIELD	2
#define SHADOW_SHIELD	3
#define ICE_SHIELD	4
#define PSI_SHIELD	5

struct magic_shield
{
    bool	is_free; /* Ramias:for run-time checks of LINK/UNLINK */
  MAGIC_SHIELD *next;
  MAGIC_SHIELD *prev;
  short 	type;		/* what kind is it? Electric, Fire, etc... */
  bool 		harmfull;	/* does the shield damage the attacker? */
  short	attack_dam;		/* then hurt the attacker ;) */
  short	percent;	/* percent of damage it absorbs per attack */
  short	hits;		/* Shield hitpoints */
  int		sn;
  char		* absorb_message_room;
  char		* absorb_message_victim;
  char		* absorb_message_self;
  char		* name;
  char		* wearoff_room;
  char		* wearoff_self;
  
};


/***************************************************************************
 *                                                                         *
 *                   VALUES OF INTEREST TO AREA BUILDERS                   *
 *                   (Start of section ... start here)                     *
 *                                                                         *
 ***************************************************************************/


/********************* Define Flags for hunting *************************/
#define ACT_HUNT_CHAR		1  /* Hunting a character		*/
#define ACT_HUNT_OBJ		2  /* Hunting an object			*/
#define ACT_HUNT_INFORM		4  /* Mob will gossip when hunting 	*/
#define ACT_HUNT_CR		8  /* Mob is doing a corpse retrival	*/
#define ACT_HUNT_MOVE	       16  /* Just walking somewhere		*/

#define NO_VNUM		       -1  /* For ch->move_to thingy		*/

/************************************************************************/ 

/** Define what is calling the trigger handler for objects ******/
#define TRIGGER_OPEN		1
				  /* Opening a container   	*/
#define TRIGGER_CLOSE		2
				  /* Closing a container	*/
#define TRIGGER_EAT		3
				  /* Eating some food		*/
#define TRIGGER_C_DRINK		4
				  /* Drinking from container	*/
#define TRIGGER_F_DRINK		5
				  /* Drinking from fountain	*/
#define TRIGGER_WEAR		6
				  /* Wearing an object		*/
#define TRIGGER_GET		7
				  /* Picking up an object	*/
#define TRIGGER_DROP		8
				  /* Dropping an object		*/
#define TRIGGER_EXAMINE		9
				  /* Examining an object	*/
/** Define what actions the triggered object can do *************/  
#define ACTION_TRANSPORT	1
				  /* Transports victim to room	*/
#define ACTION_RESTORE		2
				  /* Restores victim		*/
#define ACTION_SLAY		3
				  /* Kills victim		*/
#define ACTION_TRANSFORM	4
				  /* Loads mob(s) in its place	*/
/****************************************************************/ 

/* BitVector flags for room-affect spells.  These are used in the
   ROOM_AFFECT_DATA structure, and passes to the major handling
   functions.  They MUST be used whenever a room-affect spell is
   being cast (from within code) */

#define ROOM_BV_NONE		0
#define ROOM_BV_SILENCE		1	/* Like silence room flag 	*/
#define ROOM_BV_SAFE		2	/* Like safe room flag		*/
#define ROOM_BV_ENCAPS		4       /* Magically blocks exits	*/
#define ROOM_BV_SHADE		8       /* Room is darkened		*/
#define ROOM_BV_HEAL_REGEN    16   /* room heals hits quicker     */
#define ROOM_BV_HEAL_STEAL    32   /* room takes hits instead of giving */
#define ROOM_BV_MANA_REGEN    64   /* room heals mana quicker     */
#define ROOM_BV_MANA_STEAL    128  /* room saps mana              */
#define ROOM_BV_FIRE_RUNE     256  /* room does fire damage       */
#define ROOM_BV_FIRE_TRAP     512  /* room is fire trapped        */
#define ROOM_BV_DAMAGE_TRAP   1024 /* room is physical damage trapped */
#define ROOM_BV_SHOCK_RUNE    2048 /* room is shock runed         */
#define ROOM_BV_SHOCK_TRAP    4096 /* room is shock trapped       */
#define ROOM_BV_SPELL_ON_ENTER 8192 /* room spell cast on entrance */
#define ROOM_BV_SPELL_ALWAYS   16384 /* room casts spell continuously */
#define ROOM_BV_HOLD           32768 /* room lets you in, but not out..recall works */
#define ROOM_BV_POISON_RUNE    65536 /* room gives poison to entering ch */
#define ROOM_BV_SOUL_NET	131072 /* makes soul instead of corpse */





/*
 * ACT bits for mobs.
 * Used in #MOBILES.
 */
#define ACT_IS_NPC                    1         /* Auto set for mobs    */
#define ACT_SENTINEL                  2         /* Stays in one room    */
#define ACT_SCAVENGER                 4         /* Picks up objects     */
#define ACT_REMEMBER                  8         /* remembers target     */
#define ACT_NO_FLEE                  16         /* can't flee from mob  */
#define ACT_AGGRESSIVE               32         /* Attacks PC's         */
#define ACT_STAY_AREA                64         /* Won't leave area     */
#define ACT_WIMPY                   128         /* Flees when hurt      */
#define ACT_PET                     256         /* Auto set for pets    */
#define ACT_TRAIN                   512         /* Can train PC's       */
#define ACT_PRACTICE               1024         /* Can practice PC's    */
#define ACT_MERCENARY              2048         /* Is a mercenary       */
#define ACT_HEAL                   4096         /* Sells spells         */
#define ACT_ADAPT                  8192         /* Adapts weapons       */
#define ACT_UNDEAD                16384         /* Mob is undead	*/
#define ACT_BANKER                32768         /* Is a *B*anker :P     */
#define ACT_NO_BODY               65536         /* no body for damage   */
#define ACT_HUNTER		 131072		/* hunts attackers      */
#define ACT_NOMIND		 262144         /* Psi attack no-no     */
#define ACT_POSTMAN		 524288		/* Postmaster 		*/
#define ACT_REWIELD	 	1048576		/* Uses better weapons  */
#define ACT_RE_EQUIP	 	2097152		/* Uses better equipment*/
#define ACT_INTELLIGENT		4194304		/* For shitkicking mobs */
#define ACT_VAMPIRE             8388608		/* Vampire mob		*/
#define ACT_BREEDER          16777216		/* Mob can breed        */	
#define ACT_SOLO   	       33554432		/* Mob is buffed for solo combat */
#define ACT_WEREWOLF           67108864         /* Werewolf mob         */ /* doesn't do anything in ack4.0 ZENFIX */
#define ACT_MOUNT             134217728         /* Mountable MOB */
#define ACT_NOBLOOD		BIT_29

/* build bits for OLC -S- */
#define ACT_BUILD_NOWT                0         /* not doing anything   */
#define ACT_BUILD_REDIT               1         /* editing rooms        */
#define ACT_BUILD_OEDIT               2         /* editing objects      */
#define ACT_BUILD_MEDIT               3         /* editing mobiles      */

#define NO_USE			   -999		/* this table entry can	*/
						/* NOT be used, except  */
						/* by a Creator		*/


/*
 * New bits to determine what skills a mob can do in combat -S-
 */
 
#define MOB_NONE		      	     1
#define MOB_SECOND			     2
#define MOB_THIRD			     4
#define MOB_FOURTH			     8
#define MOB_PUNCH			    16
#define MOB_HEADBUTT			    32
#define MOB_KNEE			    64
#define MOB_DISARM			   128
#define MOB_TRIP			   256
#define MOB_NODISARM			   512
#define MOB_NOTRIP			  1024
#define MOB_DODGE			  2048
#define MOB_PARRY			  4096
#define MOB_MARTIAL			  8192
#define MOB_ENHANCED			 16384 
#define MOB_DUALWIELD			 32768
#define MOB_DIRT			 65536
#define MOB_FIFTH			131072
#define MOB_SIXTH			262144
#define MOB_CHARGE			524288

/*
 * New bits to determine what spells a mob will cast in combat -S-
 * These are for offensive spells.
 * Remember spec_funs may still cast as well! - but spells cast 
 *  this way WILL reduce the mob's mana <g>
 */

#define CAST_NONE			     1
#define CAST_MAGIC_MISSILE		     2
#define CAST_SHOCKING_GRASP		     4
#define CAST_BURNING_HANDS		     8
#define CAST_COLOUR_SPRAY		    16
#define CAST_FIREBALL			    32
#define CAST_HELLSPAWN			    64
#define CAST_ACID_BLAST			   128
#define CAST_CHAIN_LIGHTNING		   256
#define CAST_FLARE			  1024
#define CAST_FLAMESTRIKE		  2048
#define CAST_EARTHQUAKE			  4096
#define CAST_MIND_FLAIL			  8192
#define CAST_PLANERGY			 16384
#define CAST_PHOBIA			 32768
#define CAST_MIND_BOLT			 65536
#define CAST_STATIC			131072
#define CAST_EGO_WHIP			262144
#define CAST_BLOODY_TEARS		524288
#define CAST_MINDFLAME		       1048576
#define CAST_SUFFOCATE		       2097152
#define CAST_NERVE_FIRE		       4194304
#define CAST_LIGHTNING_BOLT	       8388608
#define CAST_HEAT_ARMOR			16777216
#define CAST_LAVA_BURST			33554432

/*
 * New bits to determine the defensive spells available to
 * mobs.  May be used in fights (cure light, heal, etc)
 *  will deduct mana from the mob when cast.
 */

#define DEF_NONE		1
#define DEF_CURE_LIGHT		2
#define DEF_CURE_SERIOUS	4
#define DEF_CURE_CRITIC		8
#define DEF_CURE_HEAL		16
#define DEF_SHIELD_FIRE		32
#define DEF_SHIELD_ICE		64
#define DEF_SHIELD_SHOCK	128

/*
 * Bits for 'affected_by'.
 * Used in #MOBILES.
 */
#define AFF_BLIND                     1
#define AFF_INVISIBLE                 2
#define AFF_DETECT_EVIL               4
#define AFF_DETECT_INVIS              8
#define AFF_DETECT_MAGIC             16
#define AFF_DETECT_HIDDEN            32
#define AFF_CLOAK_REFLECTION         64         
#define AFF_SANCTUARY               128
#define AFF_FAERIE_FIRE             256
#define AFF_INFRARED                512
#define AFF_CURSE                  1024
#define AFF_CLOAK_FLAMING          2048        
#define AFF_POISON                 4096
#define AFF_PROTECT                8192
#define AFF_CLOAK_ABSORPTION      16384         /* Unused       */
#define AFF_SNEAK                 32768
#define AFF_HIDE                  65536
#define AFF_SLEEP                131072
#define AFF_CHARM                262144
#define AFF_FLYING               524288
#define AFF_PASS_DOOR           1048576
#define AFF_ANTI_MAGIC          2097152         /* -S- no magic hurts ch */
#define AFF_DETECT_UNDEAD       4194304	  
#define AFF_BESERK		8388608
#define AFF_VAMP_BITE          16777216		/* Yumm! */
#define AFF_VAMP_HEALING       33554432		/* DO NOT USE IN OLC! */
#define AFF_HOLD			67108864
#define AFF_PARALYSIS	      134217728
#define AFF_CLOAK_ADEPT		268435456
#define AFF_CLOAK_REGEN		536870912

/* VAMP_HEALING is used to show that a vamp is currently healing after death*/

/*
 * Sex.
 * Used in #MOBILES.
 */
#define SEX_NEUTRAL                   0
#define SEX_MALE                      1
#define SEX_FEMALE                    2





/*
 * Item types.
 * Used in #OBJECTS.
 */
#define ITEM_LIGHT                    1
#define ITEM_SCROLL                   2
#define ITEM_WAND                     3
#define ITEM_STAFF                    4
#define ITEM_WEAPON                   5
#define ITEM_BEACON                   6  /* for portals, etc */
#define ITEM_PORTAL		      7
#define ITEM_TREASURE                 8
#define ITEM_ARMOR                    9
#define ITEM_POTION                  10
#define ITEM_CLUTCH                  11  /* for clutch location only! */
#define ITEM_FURNITURE               12
#define ITEM_TRASH                   13
#define ITEM_TRIGGER		     14
#define ITEM_CONTAINER               15
#define ITEM_QUEST		     16
#define ITEM_DRINK_CON               17
#define ITEM_KEY                     18
#define ITEM_FOOD                    19
#define ITEM_MONEY                   20
#define ITEM_STAKE		     21
#define ITEM_BOAT                    22
#define ITEM_CORPSE_NPC              23
#define ITEM_CORPSE_PC               24
#define ITEM_FOUNTAIN                25
#define ITEM_PILL                    26
#define ITEM_BOARD                   27
#define ITEM_SOUL				 28
#define ITEM_PIECE			 29
#define ITEM_SPELL_MATRIX		30
#define ITEM_ENCHANTMENT		31

/*
 * Extra flags.
 * Used in #OBJECTS.
 */
#define ITEM_GLOW				1
#define ITEM_HUM				2
#define ITEM_DARK				4
#define ITEM_NODISARM				4
#define ITEM_LOCK				8
#define ITEM_EVIL				16
#define ITEM_INVIS			32
#define ITEM_MAGIC			64
#define ITEM_NODROP			128
#define ITEM_BLESS			256
#define ITEM_ANTI_GOOD			512
#define ITEM_ANTI_EVIL			1024
#define ITEM_ANTI_NEUTRAL		2048
#define ITEM_NOREMOVE			4096
#define ITEM_INVENTORY			8192
#define ITEM_NOSAVE			16384   /* For "quest" items :) */
#define ITEM_CLAN_EQ		 	32768   /* only leaders and creators may load */
#define ITEM_TRIG_DESTROY	 	65536	  /* Trigger object that destroy after use */
#define ITEM_NO_AUCTION			131072   /* Can't be auctioned */ 
#define ITEM_REMORT			262144   /* player must have a remort class of higher level than item level */
#define ITEM_ADEPT			524288
#define ITEM_RARE			1048576
#define ITEM_VAMP                       2097152  /* player must be a vampyre */
#define ITEM_NOLOOT			4194304
#define ITEM_NOSAC			8388608 
#define ITEM_UNIQUE			16777216
#define ITEM_LIFESTEALER	   BIT_26
#define ITEM_SILVER			BIT_27
 
/* Class-restricted stuff dropped. */

#define ITEM_APPLY_NONE                 1
#define ITEM_APPLY_INFRA                2
#define ITEM_APPLY_INV                  4
#define ITEM_APPLY_DET_INV              8
#define ITEM_APPLY_SANC                16 
#define ITEM_APPLY_SNEAK               32
#define ITEM_APPLY_HIDE                64
#define ITEM_APPLY_PROT               128
#define ITEM_APPLY_ENHANCED           256
#define ITEM_APPLY_DET_MAG            512
#define ITEM_APPLY_DET_HID           1024
#define ITEM_APPLY_DET_EVIL          2048
#define ITEM_APPLY_PASS_DOOR         4096
#define ITEM_APPLY_DET_POISON        8192
#define ITEM_APPLY_FLY              16384
#define ITEM_APPLY_KNOW_ALIGN       32768
#define ITEM_APPLY_DET_UNDEAD	    65536
#define ITEM_APPLY_HEATED	   131072


/* Class-restricted object stuff
 * So only warriors can use some swords, thieves daggers, etc
 * -- Stephen
 */

#define ITEM_CLASS_SOR          1
#define ITEM_CLASS_KNI          2
#define ITEM_CLASS_ASS          4
#define ITEM_CLASS_MON          8
#define ITEM_CLASS_NEC         16
#define ITEM_CLASS_PSI         32
#define ITEM_CLASS_CON         64
#define ITEM_CLASS_TEM        128
#define ITEM_CLASS_RAN        256

/*
 * Wear flags.
 * Used in #OBJECTS.
 */
#define ITEM_TAKE                     1
#define ITEM_WEAR_FINGER              2
#define ITEM_WEAR_NECK                4
#define ITEM_WEAR_BODY                8
#define ITEM_WEAR_HEAD               16
#define ITEM_WEAR_LEGS               32
#define ITEM_WEAR_FEET               64
#define ITEM_WEAR_HANDS             128
#define ITEM_WEAR_ARMS              256
#define ITEM_WEAR_SHIELD            512
#define ITEM_WEAR_ABOUT            1024
#define ITEM_WEAR_WAIST            2048
#define ITEM_WEAR_WRIST            4096
#define ITEM_WIELD                 8192
#define ITEM_HOLD                 16384
#define ITEM_WEAR_FACE            32768
#define ITEM_WEAR_EAR             65536
#define ITEM_HOLD_MAGIC          131072 
#define ITEM_HOLD_CLUTCH	 131072


/*
 * Apply types (for affects).
 * Used in #OBJECTS.
 */
#define APPLY_NONE                    0
#define APPLY_STR                     1
#define APPLY_DEX                     2
#define APPLY_INT                     3
#define APPLY_WIS                     4
#define APPLY_CON                     5
#define APPLY_SEX                     6
#define APPLY_CLASS                   7
#define APPLY_LEVEL                   8
#define APPLY_AGE                     9
#define APPLY_HEIGHT                 10
#define APPLY_WEIGHT                 11
#define APPLY_MANA                   12
#define APPLY_HIT                    13
#define APPLY_MOVE                   14
#define APPLY_GOLD                   15
#define APPLY_EXP                    16
#define APPLY_AC                     17
#define APPLY_HITROLL                18
#define APPLY_DAMROLL                19
#define APPLY_SAVING_PARA            20
#define APPLY_SAVING_ROD             21
#define APPLY_SAVING_PETRI           22
#define APPLY_SAVING_BREATH          23
#define APPLY_SAVING_SPELL           24



/*
 * Values for containers (value[1]).
 * Used in #OBJECTS.
 */
#define CONT_CLOSEABLE                1
#define CONT_PICKPROOF                2
#define CONT_CLOSED                   4
#define CONT_LOCKED                   8





/*
 * Room flags.
 * Used in #ROOMS.
 */
#define ROOM_DARK                     1
#define ROOM_REGEN                    2   /* increased regen in this room */
#define ROOM_NO_MOB                   4
#define ROOM_INDOORS                  8
#define ROOM_NO_MAGIC                16
#define ROOM_HOT                     32  /* players lose hp each tick   */
#define ROOM_COLD                    64  /* players lose hp each tick   */
#define ROOM_PK                     128  /* players may freely pk here  */
#define ROOM_QUIET                  256  /* room is quiet               */
#define ROOM_PRIVATE                512
#define ROOM_SAFE                  1024
#define ROOM_SOLITARY              2048
#define ROOM_PET_SHOP              4096
#define ROOM_NO_RECALL             8192
#define ROOM_NO_TELEPORT          16384
#define ROOM_HUNT_MARK	          32768  /* Dont ever set! */
#define ROOM_NOBLOODWALK	  65536
#define ROOM_NO_PORTAL		 131072
#define ROOM_NO_REPOP		BIT_19


/*
 * Directions.
 * Used in #ROOMS.
 */
#define DIR_NORTH                     0
#define DIR_EAST                      1
#define DIR_SOUTH                     2
#define DIR_WEST                      3
#define DIR_UP                        4
#define DIR_DOWN                      5



/*
 * Exit flags.
 * Used in #ROOMS.
 */
#define EX_ISDOOR                     1
#define EX_CLOSED                     2
#define EX_LOCKED                     4
#define EX_CLIMB		      8
#define EX_IMMORTAL		     16
#define EX_PICKPROOF                 32
#define EX_SMASHPROOF		     64
#define EX_PASSPROOF		    128
#define EX_NODETECT		    256



/*
 * Sector types.
 * Used in #ROOMS.
 */
#define SECT_INSIDE                   0
#define SECT_CITY                     1
#define SECT_FIELD                    2
#define SECT_FOREST                   3
#define SECT_HILLS                    4
#define SECT_MOUNTAIN                 5
#define SECT_WATER_SWIM               6
#define SECT_WATER_NOSWIM             7
#define SECT_RECALL_OK                8
#define SECT_AIR                      9
#define SECT_DESERT                  10
#define SECT_MAX                     11



/*
 * Equpiment wear locations.
 * Used in #RESETS.
 */
#define WEAR_NONE                    -1
#define WEAR_LIGHT                    0
#define WEAR_FINGER_L                 1
#define WEAR_FINGER_R                 2
#define WEAR_NECK_1                   3
#define WEAR_NECK_2                   4
#define WEAR_BODY                     5
#define WEAR_HEAD                     6
#define WEAR_LEGS                     7
#define WEAR_FEET                     8
#define WEAR_HANDS                    9
#define WEAR_ARMS                    10
#define WEAR_SHIELD                  11
#define WEAR_ABOUT                   12
#define WEAR_WAIST                   13
#define WEAR_WRIST_L                 14
#define WEAR_WRIST_R                 15
#define WEAR_WIELD                   16
#define WEAR_HOLD                    17
#define WEAR_FACE                    18
#define WEAR_EAR                     19
#define WEAR_MAGIC                   20
#define WEAR_WIELD_2		     21
#define MAX_WEAR                     22


/***************************************************************************
 *                                                                         *
 *                   VALUES OF INTEREST TO AREA BUILDERS                   *
 *                   (End of this section ... stop here)                   *
 *                                                                         *
 ***************************************************************************/

/*
 * Conditions.
 */
#define COND_DRUNK                    0
#define COND_FULL                     1
#define COND_THIRST                   2



/*
 * Positions.
 */
#define POS_DEAD                      0
#define POS_MORTAL                    1
#define POS_INCAP                     2
#define POS_STUNNED                   3
#define POS_SLEEPING                  4
#define POS_RESTING                   5
#define POS_FIGHTING                  6
#define POS_STANDING                  7
#define POS_WRITING                   8	
#define POS_BUILDING                  9
#define POS_RIDING                   10

/*
 * ACT bits for players.
 */
#define PLR_IS_NPC                    1         /* Don't EVER set.      */
#define PLR_BOUGHT_PET                2
#define PLR_CLAN_LEADER               4         /* Clan Leader!! */
#define PLR_AUTOEXIT                  8

#define PLR_AUTOLOOT                 16
#define PLR_AUTOSAC                  32
#define PLR_BLANK                    64
#define PLR_BRIEF                   128

#define PLR_NO_PRAY                 256
#define PLR_COMBINE                 512
#define PLR_PROMPT                 1024
#define PLR_TELNET_GA              2048

#define PLR_HOLYLIGHT              4096
#define PLR_WIZINVIS               8192
#define PLR_BUILDER               16384         /* Is able to use the OLC */
#define PLR_SILENCE               32768

#define PLR_NO_EMOTE              65536
#define PLR_COLOUR		 131072		/* Set this to get colour */
#define PLR_NO_TELL              262144
#define PLR_LOG                  524288

#define PLR_DENY                1048576
#define PLR_FREEZE              2097152
#define PLR_THIEF               4194304
#define PLR_KILLER              8388608

#define PLR_NOSUMMON           16777216
#define PLR_NOVISIT            33554432

#define PLR_QUESTING	       67108864		/* Player is on a quest */
#define PLR_AUTOSPLIT         134217728
#define PLR_AUTOASSIST        268435456
#define PLR_NOBLOOD	       536870912

#define PLR_INCOG			1073741824

/*
 * Obsolete bits.
 */
#if 0
#define PLR_AUCTION                   4 /* Obsolete     */
#define PLR_CHAT                    256 /* Obsolete     */
#define PLR_NO_SHOUT             131072 /* Obsolete     */
#endif

/* 
 * Player flags
 */
#define PFLAG_PKOK		1
#define PFLAG_AFK			2
#define PFLAG_AMBAS		4
#define PFLAG_VAMP		8
#define PFLAG_CLAN_DIPLOMAT	16
#define PFLAG_CLAN_BOSS		32
#define PFLAG_CLAN_TREASURER	64
#define PFLAG_CLAN_ARMOURER	128
#define PFLAG_CLAN_LEADER	256
#define PFLAG_SUPER_COUNCIL	512
#define PFLAG_WEREWOLF		1024
#define PFLAG_RAGED		2048
#define PFLAG_SHIFTED		4096
#define PFLAG_RULER		BIT_14
#define PFLAG_BLIND_PLAYER	BIT_15


/*
 * Channel bits.
 */
#define CHANNEL_AUCTION               1
#define CHANNEL_GOSSIP                2
#define CHANNEL_MUSIC                 4
#define CHANNEL_IMMTALK               8
#define CHANNEL_NEWBIE               16
#define CHANNEL_QUESTION             32
#define CHANNEL_SHOUT                64
#define CHANNEL_YELL                128
#define CHANNEL_FLAME               256
#define CHANNEL_ZZZ                 512
#define CHANNEL_RACE               1024
#define CHANNEL_CLAN               2048
#define CHANNEL_NOTIFY             4096
#define CHANNEL_INFO               8192
#define CHANNEL_LOG		  16384
#define CHANNEL_CREATOR		  32768
#define CHANNEL_ALLCLAN		  65536
#define CHANNEL_ALLRACE		 131072
#define CHANNEL_HERMIT		 262144		/* Turns off ALL channels */
#define CHANNEL_BEEP		 524288
#define CHANNEL_FAMILY		1048576
#define CHANNEL_DIPLOMAT	2097152
#define CHANNEL_CRUSADE		4194304
#define CHANNEL_REMORTTALK	8388608
#define CHANNEL_HOWL           BIT_25
#define CHANNEL_ADEPT	        BIT_26
/* #define CHANNEL_MAUCTION        67108864  */
#define CHANNEL_OOC            BIT_27
#define CHANNEL_QUEST          BIT_28
#define CHANNEL_LANG	        BIT_29
#define CHANNEL_GAME		BIT_30

  /* NOTE 32 is the last allowable channel ZEN */

/* Monitor channels - for imms to select what mud-based info they receive */
#define MONITOR_CONNECT		      1
#define MONITOR_AREA_UPDATE	      2
#define MONITOR_AREA_BUGS	      4
#define MONITOR_AREA_SAVING	      8
#define MONITOR_GEN_IMM		     16
#define MONITOR_GEN_MORT	     32
#define MONITOR_COMBAT		     64
#define MONITOR_HUNTING		    128
#define MONITOR_BUILD		    256
#define MONITOR_CLAN		    512
#define MONITOR_OBJ		   1024
#define MONITOR_MOB		   2048
#define MONITOR_ROOM		   4096
#define MONITOR_MAGIC		   8192
#define MONITOR_BAD		  16384

/*
 * Hunt flags for mobs
 */
#define HUNT_WORLD	0x00000001	/* Search the whole world	*/
#define HUNT_OPENDOOR	0x00000002	/* Can open obstructung doors	*/
#define HUNT_UNLOCKDOOR	0x00000004	/* Can unlock obstructing doors	*/
#define HUNT_PICKDOOR	0x00000008	/* Can pick obstructing doors	*/
#define HUNT_INFORM	0x00000010	/* Yells while hunting		*/
#define HUNT_CR		0x00000020	/* Is preforming a CR		*/
#define HUNT_MERC	0x00000040	/* Is gonna assassinate someone	*/
#define HUNT_ALL	0x0000001E      /* can hunt through anything    */
/*
 * Prototype for a mob.
 * This is the in-memory version of #MOBILES.
 */
struct  mob_index_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    MOB_INDEX_DATA *    next;
    SPEC_FUN *          spec_fun;
    SHOP_DATA *         pShop;
    AREA_DATA *         area; /* MAG Mod */
    char *              player_name;
    char *              short_descr;
    char *              long_descr;
    char *              description;
    short              vnum;
    short              count;
    short              killed;
    short              sex;
    short              level;
    int                 act;
    int                 affected_by;
    int			aggro_list;
    short              alignment;
    short              ac_mod;                 /* ac modifier */
    short              hr_mod;                 /* hitroll modifier */
    short              dr_mod;                 /* damroll modifier */
    char        *       target;                 /* last ch to attack */
    short              hitroll;                /* Unused */
    short              ac;                     /* Unused */
    short              hitnodice;              /* Unused */
    short              hitsizedice;            /* Unused */
    short              hitplus;                /* Unused */
    short              damnodice;              /* Unused */
    short              damsizedice;            /* Unused */
    short              damplus;                /* Unused */
    int                 gold;                   /* Unused */
    MPROG_DATA *        first_mprog;               /* Used by MOBprogram   */
    MPROG_DATA *	last_mprog;
    int                 progtypes;              /* Used by MOBprogram   */
    int			skills;			/* skill flags 		*/
    int			cast;			/* casting flags	*/
    int			def;			/* casting flags	*/
    short		class;
    short		clan;
    short		race;
    short		position;
    int			hunt_flags;
};



/*
 * One character (PC or NPC).
 */
struct  char_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    bool		is_quitting;
    CHAR_DATA *         next;
    CHAR_DATA *		prev;
    CHAR_DATA *         next_in_room;
    CHAR_DATA *		prev_in_room;
    CHAR_DATA *         master;
    CHAR_DATA *         leader;
    CHAR_DATA *         fighting;
    CHAR_DATA *         reply;

/*    CHAR_DATA *         hunting;
    char *              huntdirs;
    int                 huntdirno;
    int                 huntlastvnum;
    char *              huntname;
    int			act_hunt;
    OBJ_DATA	*	hunt_obj;
    int			move_to;
    char *		movename;*/

    CHAR_DATA *		hunting;	/* For hunting PC's/mobs	*/
    OBJ_DATA *		hunt_obj;	/* Looking for objects		*/
    CHAR_DATA *		hunt_for;	/* Employer (crs, mercs)	*/
    ROOM_INDEX_DATA *	hunt_home;	/* Return to after hunting	*/
    char *		searching;	/* For PC's that quit		*/
    int			hunt_flags;	/* Action flags			*/
    
    bool		switched; /* = not isnull(descriptor->original) */
    CHAR_DATA *		old_body; /* = descriptor->original */
    int                 poly_level;
    
    SPEC_FUN *          spec_fun;
    MOB_INDEX_DATA *    pIndexData;
    DESCRIPTOR_DATA *   desc;
    AFFECT_DATA *       first_affect;
    AFFECT_DATA *	last_affect;
    AFFECT_DATA *	first_saved_aff;
    AFFECT_DATA *	last_saved_aff;
    NOTE_DATA *         pnote;
    OBJ_DATA *          first_carry;
    OBJ_DATA *		last_carry;
    ROOM_INDEX_DATA *   in_room;
    ROOM_INDEX_DATA *   was_in_room;
    PC_DATA *           pcdata;
    char *              name;
    OBJ_DATA *		sitting;	/* What they're resting or sleeping on */
    char *              short_descr;
    char *              long_descr;
    char *              long_descr_orig;
    char *              description;
    char *              prompt;
    char *              old_prompt;     /* used to hold prompt when writing */
    short              sex;
    short		login_sex;
    short              class;
    short		clan;		/* need to convert from pcdata to this */
    short              race;
    short              level;          /* For m/c this = max of levels */
    int                 lvl[MAX_CLASS];  /* Holds details for m/c levels */
    int			lvl2[MAX_CLASS]; /* for remort (if any) */
    int			adept_level;
    int                 sentence;       /* For new legal system */
    short		invis;		/* For wizinvis imms - lvl invis to */
    short		incog;		/* Same as above except for incognito --Flar */
    short              trust;
    bool                wizbit;
    int                 played;
    time_t              logon;
    time_t              save_time;
    time_t              last_note;
    short              timer;
    short              wait;
    short              hit;
    short              max_hit;
    short              mana;
    short              max_mana;
    short              move;
    short              max_move;
    int                 gold;
    int                 balance;        /* Amount of gold (if any) in bank */
    int                 exp;
    int			intell_exp;
    int                 act;
    int                 act_build;      /* for setting what ya editing */
    int                 build_vnum;     /* the current vnum for w-y-e  */
    int                 affected_by;
    short              position;
    short              practice;
    short              carry_weight;
    short              carry_number;
    short              saving_throw;
    short              alignment;
    short              hitroll;
    short              damroll;
    short              armor;
    short              ac_mod;                 /* ac modifier */
    short		stance_ac_mod;
    short              hr_mod;                 /* hitroll modifier */
    short		stance_hr_mod;
    short              dr_mod;                 /* damroll modifier */
    short		stance_dr_mod;
    char        *       target;                 /* last ch to attack */
    short              wimpy;
    int                 deaf;
    MPROG_ACT_LIST *    first_mpact;                  /* Used by MOBprogram */
    MPROG_ACT_LIST *	last_mpact;
    int                 mpactnum;               /* Used by MOBprogram */
    int			skills;			/* Used for MOBs */
    int			cast;
    int			def;

    CHAR_DATA   *       riding;
    CHAR_DATA   *       rider;
    
/* Stuff to handle automatic quests for players */
    int			quest_points;		/* The reason to quest!	 */    

    MAGIC_SHIELD    *   first_shield;
    MAGIC_SHIELD    *	last_shield;
    int                 stunTimer;
    short		num_followers;
    short		extract_timer;  /* same as object timer, only use for charmies */
    BRAND_DATA	*	current_brand;
    int			stance;
    bool		using_named_door;


};

#ifdef IMC
   #include "imc.h"
#endif

/*
 * Data which only PC's have.
 */

struct  pc_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    PC_DATA *		next;
    PC_DATA *           prev;
    int			colour[MAX_COLOUR];
    char *              pwd;
    char *              bamfin;
    char * 		room_enter;
    char * 		room_exit;
    char *              bamfout;
    char *              title;
    char *              immskll;
    char *		host;	/* Used to tell PC last login site */
    short		failures;	/* Failed logins */
    short              clan;   /* will be used to denote clan membership */
    int			generation; /* Used for vamps */ /* were_age for wolves */
    short              perm_str;
    short              perm_int;
    short              perm_wis;
    short              perm_dex;
    short              perm_con;
    short              max_str;
    short              max_int;
    short              max_wis;
    short              max_dex;
    short              max_con;
    short              mod_str;
    short              mod_int;
    short              mod_wis;
    short              mod_dex;
    short              mod_con;
    short              condition       [3];
    int		bloodlust;	/* rage points for wolves */
    int           bloodlust_max;
    short              pagelen;
    short              learned         [MAX_SKILL];
    char        *       header;         /* header used for message */
    char        *       message;        /* message for board in progress */
    char	*	alias_name[MAX_ALIASES];
    char	*	alias[MAX_ALIASES];
    char	*	who_name;	/* To show on who name */
    int			pkills;
    int			pkilled;
    int			mkills;
    int			mkilled;
    int                 pflags;
    char	*	lastlogin;
    short		order[MAX_CLASS];	/* Class Order */
    short		index[MAX_CLASS];	/* the order of each class! */
    int			monitor;		/* monitor channel for imms */
    int       vamp_level; /* were level */
    int       vamp_bloodlust_max;
    int       vamp_skill_num;
    int       vamp_skill_max;
    int       vamp_bloodline;
    int       vamp_exp;
    int       vamp_pracs;
    short      has_exp_fix;
    short    quest_points;

    char        *       ignore_list[MAX_IGNORES];   /* Ignore this person */
    short    recall_vnum;
    int		mana_from_gain; /* saves non-item oriented mana total */
    int		hp_from_gain;  /* same for hitpoints */
    int		move_from_gain;
    
    char *    load_msg;
    char	hicol;
    char	dimcol;
    short	ruler_rank;
    char *	pedit_state;
    char *	pedit_string[5];
#ifdef IMC
    IMC_CHARDATA *imcchardata;
#endif

};

/*
 * MOBprogram block
*/

struct  mob_prog_act_list
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    MPROG_ACT_LIST *	next;
    MPROG_ACT_LIST *	prev;
    char *		buf;
    CHAR_DATA *		ch;
    OBJ_DATA *		obj;
    void *		vo;
};

struct  mob_prog_data
{
    bool	is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    MPROG_DATA *next;
    MPROG_DATA *prev;
    int         type;
    char *      arglist;
    char *      comlist;
    char *      filename;
};

extern	bool    MOBtrigger;

#define ERROR_PROG        -1
#define IN_FILE_PROG       0
#define ACT_PROG           1
#define SPEECH_PROG        2
#define RAND_PROG          4
#define FIGHT_PROG         8
#define DEATH_PROG        16
#define HITPRCNT_PROG     32
#define ENTRY_PROG        64
#define GREET_PROG       128
#define ALL_GREET_PROG   256
#define GIVE_PROG        512
#define BRIBE_PROG      1024

/*  Types of interactions to check  */
#define	CHECKS_NONE		BIT_0
#define	CHECKS_CLAN		BIT_1
#define	CHECKS_RACE		BIT_2
#define	CHECKS_LEVEL		BIT_3
#define	CHECKS_REP_GEN		BIT_4
#define	CHECKS_REP_SHOP		BIT_5
#define	CHECKS_REP_ROYAL	BIT_6
#define	CHECKS_REP_UNDEAD	BIT_7
#define	CHECKS_REP_NATURE	BIT_8
#define	CHECKS_REP_HOLY		BIT_9
#define	CHECKS_REP_CLAN		BIT_10
#define	CHECKS_REP_UNDERWORLD	BIT_11
#define	CHECKS_REP_LAW		BIT_12

#define	ACTION_NONE		BIT_0
#define	ACTION_ATTACK		BIT_1
#define	ACTION_HAIL		BIT_2
#define	ACTION_BLOCK		BIT_3
#define	ACTION_AID		BIT_4
#define	ACTION_HEAL		BIT_5
#define	ACTION_TRANSFER		BIT_6
#define	ACTION_FLEE		BIT_7
#define	ACTION_ALARM		BIT_8
#define	ACTION_COWER		BIT_9
#define	ACTION_REFUSE		BIT_10

/*
 * Liquids.
 */
#define LIQ_WATER        0
#define LIQ_MAX         17

struct  liq_type
{
    char *      liq_name;
    char *      liq_color;
    short      liq_affect[3];
};



/*
 * Extra description data for a room or object.
 */
struct  extra_descr_data
{
    bool		is_free;	/* Ramias:for run-time checks of LINK/UNLINK */
    EXTRA_DESCR_DATA *	next;		/* Next in list                     */
    EXTRA_DESCR_DATA *	prev;		/* Prev in list			    */
    char *		keyword;	/* Keyword in look/examine          */
    char *		description;	/* What to see                      */
};

struct trigger_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
  TRIGGER_DATA *	next;
  TRIGGER_DATA *	prev;
  char * 	message;  /* properly formatted act format string to use in a TO_ROOM */
  int		trigger;  /* command used on object  */
  int		event;    /* trigger function index to be called  */
  int		data;	    /* data used in the event call..vnum, spell index, etc. */
  int		register_data; /* for storing generic info  */
  int		on_value; /* for conditional triggers..happens when register is higher than 
                         on_value  */
  int		at_vnum;  /* for at another room triggers. event will happen there */
  bool	force_message;  /* Always does an act message, in addition to trigger */
  char *	spell_name;
};


struct  obj_index_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    OBJ_INDEX_DATA *    next;
    EXTRA_DESCR_DATA *  first_exdesc;
    EXTRA_DESCR_DATA *	last_exdesc;
    OBJ_FUN	*	obj_fun;
    AFFECT_DATA *       first_apply;
    AFFECT_DATA *	last_apply;
    /* MAG Mod */
    AREA_DATA *         area;
    char *              owner;
    char *              name;
    short              level;
    char *              short_descr;
    char *              description;
    short              vnum;
    int              item_type;
    int              extra_flags;
    int                 wear_flags;
    /* class_flags changed to item_apply for magic apply, etc */
    int              item_apply;
    short              count;
    short              weight;
    int                 cost;                   /* Unused */
    int                 value   [4];
    TRIGGER_DATA *	first_trigger;
    TRIGGER_DATA *	last_trigger;
};



/*
 * One object.
 */
struct  obj_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    OBJ_DATA *          next;
    OBJ_DATA *		prev;
    OBJ_DATA *          next_in_carry_list;   /* carry list is the list on a char, or in a container */
    OBJ_DATA *		prev_in_carry_list;
    OBJ_DATA *          first_in_carry_list;
    OBJ_DATA *		last_in_carry_list;
    OBJ_DATA *          next_in_room;
    OBJ_DATA *		prev_in_room;
    OBJ_DATA *          first_in_room;
    OBJ_DATA *		last_in_room;
    OBJ_DATA *		first_content;
    OBJ_DATA *		last_content;
    OBJ_DATA *		next_content;
    OBJ_DATA *		prev_content;
    OBJ_DATA *          in_obj;
    OBJ_FUN  *		obj_fun;
    CHAR_DATA *         carried_by;
    EXTRA_DESCR_DATA *  first_exdesc;
    EXTRA_DESCR_DATA *	last_exdesc;
    AFFECT_DATA *       first_apply;
    AFFECT_DATA *	last_apply;
    OBJ_INDEX_DATA *    pIndexData;
    ROOM_INDEX_DATA *   in_room;
    char *              owner;
    char *              name;
    char *              short_descr;
    char *              description;
    int              item_type;
    int                 extra_flags;
    int                 wear_flags;
    int	                item_apply;
    int                 wear_loc;
    short              weight;
    int                 cost;
    short              level;
    short              timer;
    int                 value   [4];
    short		condition;	/* % value for condition */
};



/*
 * Exit data.
 */
struct  exit_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    EXIT_DATA *		next;
    ROOM_INDEX_DATA *   to_room;
    short              vnum;
    short              exit_info;
    short              key;
    char *              keyword;
    char *              description;
};




/*
 * Reset commands:
 *   '*': comment
 *   'M': read a mobile
 *   'O': read an object
 *   'P': put object in object
 *   'G': give object to mobile
 *   'E': equip object to mobile
 *   'D': set state of door
 *   'R': randomize room exits
 *   'S': stop (end of list)
 */

/*
 * Area-reset definition.
 */
struct  reset_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    RESET_DATA *        next;
    RESET_DATA *	prev;
    char                command;
    short              ifflag;
    short              arg1;
    short              arg2;
    short              arg3;
    char *              notes;
    char *		auto_message;	/* Ugly - wasteful of space. */
};


#define AREA_PAYAREA  	    1
#define AREA_TELEPORT 	    2
#define AREA_BUILDING 	    4
#define AREA_NOSHOW	    8	/* Show area name on 'areas' command? */
#define AREA_NO_ROOM_AFF    16
/*
 * Area definition.
 */

/*
 *   Npc Interaction stuff  Zen
 */

struct queued_interact_list
{
  bool		is_free;
  QUEUED_INTERACT_LIST	* next;
  QUEUED_INTERACT_LIST	* prev;
  CHAR_DATA		* mob;
};




struct influence_list
{
  bool		is_free;
  INFLUENCE_LIST	* next;
  INFLUENCE_LIST	* prev;
  INFLUENCE_DATA	* this_one;
};


struct control_list
{
  bool		is_free;
  CONTROL_LIST	* next;
  CONTROL_LIST	* prev;
  CONTROL_DATA	* this_one;
};

struct ruler_list
{
  bool		is_free;
  RULER_LIST	* next;
  RULER_LIST	* prev;
  RULER_DATA	* this_one;
};


struct control_data
{
  bool		is_free;
  char	*	keyword;
  AREA_DATA *		area;
  RULER_DATA *		ruler; /* what entity controls the area */
  INFLUENCE_LIST *	first_influence; /* what current influences are for the area */
  INFLUENCE_LIST *	last_influence;
  INTERACT_DATA *	first_interact;  /* tells the mobs what to do */
  INTERACT_DATA *	last_interact;
};


struct influence_data
{
  bool		is_free;
  RULER_DATA *	actor;
  int		influence;
};


struct	interact_data
{
  bool		is_free;
  INTERACT_DATA	* next;
  INTERACT_DATA	* prev;
  int		type;
  int		min_value;
  int		max_value;
  int		action;
  char		* say;
  CHAR_DATA	* target;
};
#define	RULER_NONE	BIT_0
#define RULER_SOLO	BIT_1
#define RULER_GROUP	BIT_2
#define RULER_MALE	BIT_3
#define RULER_FEMALE	BIT_4
#define RULER_NEUTRAL	BIT_5



struct ruler_data
{
  bool		is_free;
  RULER_DATA	* next;
  RULER_DATA	* prev;
  char		* name;
  short	ruler_rank;
  char		* affiliation_name;
  short	affiliation_index;
  char		* keywords;
  short	flags;
  CONTROL_LIST	* first_control;
  CONTROL_LIST	* last_control;
};


struct  area_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    AREA_DATA *         next;
    AREA_DATA *		prev;
    RESET_DATA *        first_reset;
    RESET_DATA *        last_reset;
    char *              name;
    short              age;
    short              nplayer;
/* Saving to envy mod, to renumber vnums! */
    int			offset;

/* MAG mod */
    int                 modified;
    int                 min_vnum;
    int                 max_vnum;
    int                 area_num;
    char *              owner;
    char *              can_read;
    char *              can_write;
    int                 gold;
    char *              filename;
    int                 flags;
    int			aggro_list;
    BUILD_DATA_LIST *   first_area_room;
    BUILD_DATA_LIST *	last_area_room;
    BUILD_DATA_LIST *   first_area_help_text;
    BUILD_DATA_LIST *	last_area_help_text;
    BUILD_DATA_LIST *   first_area_object;
    BUILD_DATA_LIST *	last_area_object;
    BUILD_DATA_LIST *   first_area_mobile;
    BUILD_DATA_LIST *	last_area_mobile;
    BUILD_DATA_LIST *   first_area_mobprog;
    BUILD_DATA_LIST *	last_area_mobprog;
    BUILD_DATA_LIST *   first_area_shop;
    BUILD_DATA_LIST *	last_area_shop;
    BUILD_DATA_LIST *   first_area_specfunc;
    BUILD_DATA_LIST *	last_area_specfunc;
    BUILD_DATA_LIST *   first_area_objfunc;
    BUILD_DATA_LIST *	last_area_objfunc;
    /* BUILD_DATA_LIST *   spec_funs; in mob index data. */
    /* BUILD_DATA_LIST *   area_shops; in mob index data. */
    /* BUILD_DATA_LIST *   resets; already there! */
    CONTROL_DATA *	control;
    char *		keyword;
    short		min_level;
    short		max_level;
    char *		level_label;
    short		reset_rate;
    char *		reset_msg;
};



/*
 * Room type.
 */
struct  room_index_data
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
    ROOM_INDEX_DATA *   next;
    CHAR_DATA *         first_person;
    CHAR_DATA *		last_person;
    OBJ_DATA *          first_content;
    OBJ_DATA *		last_content;
    EXTRA_DESCR_DATA *  first_exdesc;
    EXTRA_DESCR_DATA *	last_exdesc;
    AREA_DATA *         area;
    EXIT_DATA *         exit    [6];
    char *              name;
    char *              description;
    char *		auto_message;  /* If != NULL, send_to_room each tick */
    short		block_timer;
    short              vnum;
    int                 room_flags;
    short              light;
    short              sector_type;
    BUILD_DATA_LIST *	first_room_reset;
    BUILD_DATA_LIST *	last_room_reset;
/* -S- mod... don't save this with OLC :P */
    ROOM_AFFECT_DATA *  first_room_affect;
    ROOM_AFFECT_DATA *	last_room_affect;
    int			affected_by;
/*    CHAR_DATA *  people;   */
     MARK_LIST_MEMBER	*first_mark_list;
    MARK_LIST_MEMBER	*last_mark_list;
   
};

/* Big MAG mod */
/* Area building stuff */

struct build_data_list  /* Used for storing area file data. */
{
    bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
   BUILD_DATA_LIST *    next;
   BUILD_DATA_LIST *	prev;
   void *               data;
};

struct mobprog_item      /* For re-creating #MOBPROGS section */
{
   MOB_INDEX_DATA *  mob;
   char *            filename;
};


struct lookup_type
{
     char *          text;
     unsigned long int             value;
     int             cost;	/* if == NO_USE, only creators can set. */
};

/*
 * Types of attacks.
 * Must be non-overlapping with spell/skill types,
 * but may be arbitrary beyond that.
 */
#define TYPE_MARTIAL		     -3		/* for martial arts */
#define TYPE_UNDEFINED               -2
#define TYPE_HIT                     1000



/*
 *  Target types.
 */
#define TAR_IGNORE                  0
#define TAR_CHAR_OFFENSIVE          1
#define TAR_CHAR_DEFENSIVE          2
#define TAR_CHAR_SELF               3
#define TAR_OBJ_INV                 4

/* Used as flags in skill_table */

#define MORTAL 1
#define REMORT 2
#define ADEPT  3

#define NORM   1
#define VAMP   2
#define WOLF   3

/*
 * Quest mob personalities
 */

#define QUEST_RUDE 	1
#define QUEST_NICE	2
#define QUEST_WIMPY	4
#define QUEST_COOL	8
#define QUEST_MEAN	16





/*
 * Skills include spells as a particular case.
 */
struct  skill_type
{
    short	flag1;			/* mort or remort?		*/
    short	flag2;			/* normal and/or vamp?		*/
    char *      name;                   /* Name of skill                */
    short      skill_level[MAX_CLASS]; /* Level needed by class        */
    SPELL_FUN * spell_fun;              /* Spell pointer (for spells)   */
    short      target;                 /* Legal targets                */
    short      minimum_position;       /* Position for caster / user   */
    short *    pgsn;                   /* Pointer to associated gsn    */
    short      slot;                   /* Slot for #OBJECT loading     */
    short      min_mana;               /* Minimum mana used            */
    short      beats;                  /* Waiting time after use       */
    char *      noun_damage;            /* Damage message               */
    char *      msg_off;                /* Wear off message             */
    char *	room_off;		/* Wear off msg TO_ROOM		*/
};



/*
 * These are skill_lookup return values for common skills and spells.
 */

extern  short  gsn_martial_arts;	/* For unarmed fighting */
extern  short  gsn_stake;
extern  short  gsn_dualwield;
extern  short  gsn_stun;
extern  short  gsn_feed;
extern  short	gsn_shadow;
extern  short	gsn_appraise;
extern  short  gsn_climb;
extern  short  gsn_find_doors;
extern  short  gsn_smash;
extern  short  gsn_notrip;
extern  short  gsn_nodisarm;
extern  short  gsn_trip;
extern  short  gsn_dirt;
extern  short  gsn_bash;

extern short   gsn_fourth_attack;
extern short   gsn_shield_block;
extern short   gsn_beserk;

extern  short  gsn_circle;
extern  short  gsn_backstab;
extern  short  gsn_dodge;
extern  short  gsn_hide;
extern  short  gsn_hunt;
extern  short  gsn_peek;
extern  short  gsn_pick_lock;
extern  short  gsn_sneak;
extern  short  gsn_steal;

extern short   gsn_punch;
extern short   gsn_headbutt;
extern short   gsn_knee;

extern  short  gsn_disarm;
extern  short  gsn_enhanced_damage;
extern  short  gsn_kick;
extern  short  gsn_parry;
extern  short  gsn_rescue;
extern  short  gsn_second_attack;
extern  short  gsn_third_attack;

extern  short  gsn_blindness;
extern  short  gsn_charm_person;
extern  short  gsn_curse;
extern  short  gsn_invis;
extern  short  gsn_mass_invis;
extern  short  gsn_poison;
extern  short  gsn_sleep;
extern   short  gsn_disguise;
extern   short  gsn_instruct;
extern   short  gsn_teach;
extern   short  gsn_adrenaline;
extern   short  gsn_frenzy;
extern   short  gsn_emotion_control;
extern   short  gsn_fifth_attack;
extern   short  gsn_sixth_attack;
extern   short  gsn_target;
extern   short  gsn_charge;
extern   short  gsn_unit_tactics;

extern   short  gsn_mount; /* for mount skill */
extern	short	gsn_imprint;
extern	short	gsn_scent;
extern  short	gsn_scout;
extern  short  gsn_decapitate;


/*
 * Utility macros.
 */
#define UMIN(a, b)              ((a) < (b) ? (a) : (b))
#define UMAX(a, b)              ((a) > (b) ? (a) : (b))
#define URANGE(a, b, c)         ((b) < (a) ? (a) : ((b) > (c) ? (c) : (b)))
#define LOWER(c)                ((c) >= 'A' && (c) <= 'Z' ? (c)+'a'-'A' : (c))
#define UPPER(c)                ((c) >= 'a' && (c) <= 'z' ? (c)+'A'-'a' : (c))
#define IS_SET(flag, bit)       ((flag) & (bit))
#define SET_BIT(var, bit)       ((var) |= (bit))
#define REMOVE_BIT(var, bit)    ((var) &= ~(bit))



/*
 * Character macros.
 */
#define IS_VAMP(ch) (IS_NPC(ch) ? IS_SET(ch->act, ACT_VAMPIRE) : IS_SET(ch->pcdata->pflags,PFLAG_VAMP) )
#define IS_UNDEAD(ch) (IS_NPC(ch) ? IS_SET(ch->act, ACT_UNDEAD ) : FALSE )
#define IS_NPC(ch)              (IS_SET((ch)->act, ACT_IS_NPC))
#define IS_IMMORTAL(ch)         (get_trust(ch) >= LEVEL_IMMORTAL)
#define IS_HERO(ch)             (get_trust(ch) >= LEVEL_HERO)
#define IS_AFFECTED(ch, sn)     (IS_SET((ch)->affected_by, (sn)))
/* #define IS_WERE(ch) (IS_NPC(ch) ? IS_SET(ch->act, ACT_WEREWOLF) : IS_SET(ch->pcdata->pflags,PFLAG_WEREWOLF) )
*/
#define IS_GOOD(ch)             (ch->alignment >= 350)
#define IS_EVIL(ch)             (ch->alignment <= -350)
#define IS_NEUTRAL(ch)          (!IS_GOOD(ch) && !IS_EVIL(ch))

#define IS_AWAKE(ch)            (ch->position > POS_SLEEPING)

#define GET_AC(ch)              ( IS_NPC(ch) ? (REAL_AC( ch ) + ch->ac_mod) : REAL_AC( ch ) + ch->stance_ac_mod )

#define REAL_AC(ch)             ((ch)->armor  + ( IS_AWAKE(ch) \
                                                ? ( IS_NPC( ch ) \
                                                ? ( dex_app[get_curr_dex(ch)].defensive * get_psuedo_level( ch )/20 ) \
                                                : ( dex_app[get_curr_dex(ch)].defensive * get_psuedo_level( ch )/10 ) ): 0 ))
#define IS_WOLF(ch) (IS_NPC(ch) ? FALSE : IS_SET(ch->pcdata->pflags, PFLAG_WEREWOLF) )
#define IS_SHIFTED(ch) (IS_NPC(ch) ? FALSE : IS_SET( ch->pcdata->pflags, PFLAG_SHIFTED ) ? TRUE : FALSE )
#define IS_RAGED(ch) (IS_NPC(ch) ? FALSE : IS_SET( ch->pcdata->pflags, PFLAG_RAGED ) ? TRUE : FALSE )

/* Added bonus to hit and dam for higher levl players */
/* High level naked players should still be able to fight ok */

#define GET_HITROLL(ch)         ( IS_NPC(ch) ? (REAL_HITROLL(ch) + ch->hr_mod + (get_psuedo_level( ch ) / 4 )) : REAL_HITROLL(ch)+(ch->level/8) + ch->stance_hr_mod )

#define REAL_HITROLL(ch)        ((ch)->hitroll+ (str_app[get_curr_str(ch)].tohit * get_psuedo_level( ch )/10) )

#define GET_DAMROLL(ch)         ( IS_NPC(ch) ? (REAL_DAMROLL(ch) + ch->dr_mod + (ch->level / 3 ))  : REAL_DAMROLL(ch)+(ch->level/10) + ch->stance_dr_mod )

#define REAL_DAMROLL(ch)        ((ch)->damroll+( str_app[get_curr_str(ch)].todam * get_psuedo_level( ch ) /10 ) )

#define IS_OUTSIDE(ch)          (!IS_SET( (ch)->in_room->room_flags, ROOM_INDOORS))

#define WAIT_STATE(ch, npulse)  ((ch)->wait = UMAX((ch)->wait, (npulse)))

#define MANA_COST(ch, sn)       (IS_NPC(ch) ? 0 : UMAX ( skill_table[sn].min_mana, 100 / (2 + ch->level - skill_table[sn].skill_level[ch->class] ) ) )

#define IS_RIDING(ch)           (!IS_NPC(ch) && ((ch)->riding))

/*
 * Object macros.
 */
#define CAN_WEAR(obj, part)     (IS_SET((obj)->wear_flags,  (part)))
#define IS_OBJ_STAT(obj, stat)  (IS_SET((obj)->extra_flags, (stat)))



/*
 * Description macros.
 */
#define PERS(ch, looker) ( can_see( looker, (ch) ) ? ( IS_NPC(ch) ? (ch)->short_descr : (IS_WOLF(ch) && (IS_SHIFTED(ch) || IS_RAGED(ch))) ? "A Large @@bWolf@@N" :(ch)->name ) : IS_IMMORTAL( ch ) ? "A Mystical Being" : "Someone" )
#define NAME(ch)		( IS_NPC(ch) ? (ch)->short_descr : (ch)->name ) 


/* Added stuff - Flar */
#define CH(descriptor)  ((descriptor)->original ? \
(descriptor)->original : (descriptor)->character)

/*
 * Linked list macros, -- Altrag
 */
/* Regular linking of double-linked list */
#define LINK(link, first, last, next, prev) \
do { \
  if ( (link)->is_free == TRUE ) hang("LINK: link is FREE!"); \
  if ( (link)->is_free != FALSE ) hang("LINK: link is corrupted!"); \
  if ( (link)->prev || (link)->next ) hang("LINK: link already in list?"); \
  if ( (last) && (last)->next ) hang("LINK: last->next NON-NULL!"); \
  if ( !(first) ) \
    (first) = (link); \
  else \
    (last)->next = (link); \
  (link)->next = NULL; \
  (link)->prev = (last); \
  (last) = (link); \
} while(0)

/* Link at the head of the list rather than the tail.  Double linked */
#define TOPLINK(link, first, last, next, prev) \
do { \
  if ( (link)->is_free == TRUE ) hang("TOPLINK: link is FREE!"); \
  if ( (link)->is_free != FALSE ) hang("TOPLINK: link is corrupted!"); \
  if ( (link)->prev || (link)->next ) hang("TOPLINK: link already in list?"); \
  if ( (first) && (first)->prev ) hang("TOPLINK: first->prev NON-NULL!"); \
  if ( !(last) ) \
    (last) = (link); \
  else \
    (first)->prev = (link); \
  (link)->prev = NULL; \
  (link)->next = (first); \
  (first) = (link); \
} while(0)

/* Insert link before ref link */
#define LINK_BEFORE(link, ref, first, last, next, prev) \
do { \
  if ( (link)->is_free == TRUE ) hang("LINK_BEFORE: link is FREE!"); \
  if ( (link)->is_free != FALSE ) hang("LINK_BEFORE: link is corrupted!"); \
  if ( (link)->prev || (link)->next ) hang("LINK_BEFORE: link already in list?"); \
  if ( !(ref) ) hang("LINK_BEFORE: ref is NULL!"); \
  if ( (ref)->is_free == TRUE ) hang("LINK_BEFORE: ref is FREE!"); \
  if ( (ref)->is_free != FALSE ) hang("LINK_BEFORE: ref is corrupted!"); \
  (link)->next = (ref); \
  (link)->prev = (ref)->prev; \
  if ( !(ref)->prev ) \
    (first) = (link); \
  else \
    ((ref)->prev)->next = (link); \
  (ref)->prev = (link); \
} while (0)

/* Insert link after ref link */
#define LINK_AFTER(link, ref, first, last, next, prev) \
do { \
  if ( (link)->is_free == TRUE ) hang("LINK_AFTER: link is FREE!"); \
  if ( (link)->is_free != FALSE ) hang("LINK_AFTER: link is corrupted!"); \
  if ( (link)->prev || (link)->next ) hang("LINK_AFTER: link already in list?"); \
  if ( !(ref) ) hang("LINK_AFTER: ref is NULL!"); \
  if ( (ref)->is_free == TRUE ) hang("LINK_AFTER: ref is FREE!"); \
  if ( (ref)->is_free != FALSE ) hang("LINK_AFTER: ref is corrupted!"); \
  (link)->prev = (ref); \
  (link)->next = (ref)->next; \
  if ( !(ref)->next ) \
    (last) = (link); \
  else \
    ((ref)->next)->prev = (link); \
  (ref)->next = (link); \
} while (0)

/* Unlink a double linked list */
#define UNLINK(link, first, last, next, prev) \
do { \
  if ( (link)->is_free == TRUE ) hang("UNLINK: link is FREE!"); \
  if ( (link)->is_free != FALSE ) hang("UNLINK: link is corrupted!"); \
  if ( (link)->prev && (((link)->prev)->next != (link)) ) \
    hang("UNLINK: link->prev->next corrupted!"); \
  if ( (link)->next && (((link)->next)->prev != (link)) ) \
    hang("UNLINK: link->next->prev corrupted!"); \
  if ( !(link)->next ) \
    (last) = (link)->prev; \
  else \
    (link)->next->prev = (link)->prev; \
  if ( !(link)->prev ) \
    (first) = (link)->next; \
  else \
    (link)->prev->next = (link)->next; \
  (link)->prev = NULL; \
  (link)->next = NULL; \
} while(0)

/* Link to the end of a single-linked list */
#define SING_LINK(link, first, next, DATA_TYPE) \
do { \
  if ( !(first) ) \
    (first) = (link); \
  else \
  { \
    DATA_TYPE *last; \
    for ( last = (first); last->next; last = last->next ) \
      ; \
    last->next = (link); \
  } \
  (link)->next = NULL; \
} while(0)

/* Link to head of a single-linked list (normal linking) */
#define SING_TOPLINK(link, first, next) \
do { \
  (link)->next = (first); \
  (first) = (link); \
} while(0)

/* Unlink a single linked list */
#define SING_UNLINK(link, first, next, DATA_TYPE) \
do { \
  if ( (link) == (first) ) \
    (first) = (link)->next; \
  else \
  { \
    DATA_TYPE *prev; \
    for ( prev = (first); prev; prev = prev->next ) \
      if ( prev->next == (link) ) \
        break; \
    if ( prev != NULL ) \
      prev->next = (link)->next; \
    else \
      bug("Sing_unlink: link not in list.", 0); \
  } \
} while(0)

/* Link to end of a half-linked list */
/* Half linked lists have a LAST pointer, but not a PREV pointer, making
   them approximately halfway between a single linked list and a double
   linked list. -- Altrag */
#define HALF_LINK(link, first, last, next) \
do { \
  if ( !(last) ) \
    (first) = (link); \
  else \
    (last)->next = (link); \
  (link)->next = NULL; \
  (last) = (link); \
} while(0)

/* Link to head of a half-linked list. */
#define HALF_TOPLINK(link, first, last, next) \
do { \
  if ( (last) == (first) ) \
    (last) = (link); \
  (link)->next = (first); \
  (first) = (link); \
} while(0)

/* Unlink a half-linked list. */
#define HALF_UNLINK(link, first, last, next, DATA_TYPE) \
do { \
  if ( (link) == (first) ) \
  { \
    (first) = (link)->next; \
    if ( (link) == (last) ) \
      (last) = NULL; \
  } \
  else \
  { \
    DATA_TYPE *prev; \
    for ( prev = (first); prev; prev = prev->next ) \
      if ( prev->next == (link) ) \
        break; \
    if ( prev != NULL ) \
    { \
      prev->next = (link)->next; \
      if ( (link) == (last) ) \
        (last) = prev; \
    } \
    else \
      bug("Half_unlink: link not in list.", 0); \
  } \
} while(0)

/*
 * Miscellaneous macros.
 */
 
/* spec: macro-ised getmem as a wrapper around _getmem for mem_log handling */
#define getmem(size) _getmem(size,_caller,1)
#define qgetmem(size) _getmem(size,_caller,0)

/* This one goes as a #define in merc.h.. dont worry.. itll work.. :) */
/* spec: log all dispose's if mem_log==TRUE - also nuke trailing ; */
/* spec: add dispose override, too */
#define _dispose(mem,size,log) \
do { \
  if ( ! (mem) ) \
  { \
    bug("Disposing NULL memory",0); \
    return; \
  } \
  if (log&&mem_log) log_printf("dispose(%p) from %s:%d", (mem), __FILE__, __LINE__); \
  free((mem)); \
  (mem) = NULL; \
} while(0)

#define dispose(mem,size) _dispose(mem,size,1)
#define qdispose(mem,size) _dispose(mem,size,0)

/*
 * Miscellaneous macros.
 */
 



/*
 * Structure for a command in the command lookup table.
 */
struct  cmd_type
{
    char * const        name;
    DO_FUN *            do_fun;
    short              position;
    short              level;
    short              log;
};



/*
 * Structure for a social in the socials table.
 */
struct  social_type
{
    char *         name;
    char *         char_no_arg;
    char *         others_no_arg;
    char *         char_found;
    char *         others_found;
    char *         vict_found;
    char *         char_auto;
    char *         others_auto;
};


/*
 * Global constants.
 */
extern  const   struct  str_app_type    str_app         [26];
extern  const   struct  int_app_type    int_app         [26];
extern  const   struct  wis_app_type    wis_app         [26];
extern  const   struct  dex_app_type    dex_app         [26];
extern  const   struct  con_app_type    con_app         [26];

extern  const   struct  colour_type     colour_table    [MAX_COLOUR];
extern  const   struct   ansi_type	ansi_table	[MAX_ANSI];
extern  const   struct  class_type      class_table     [MAX_CLASS];
extern  const	struct	class_type	remort_table	[MAX_CLASS];
extern  const   struct  race_type       race_table      [MAX_RACE];
extern  const   struct  exp_type        exp_table       [141];
extern  const   struct  clan_type       clan_table      [MAX_CLAN];
extern  const   struct  cmd_type        cmd_table       [];
extern  const   struct  liq_type        liq_table       [LIQ_MAX];
extern  const   struct  skill_type      skill_table     [MAX_SKILL];
extern	struct 	social_type		 *social_table;
extern  char *  const                   title_table     [MAX_CLASS]
							[36]
							[2];

/* spec: log all calls to getmem/dispose when set */
extern bool mem_log;

extern  const   struct    stance_app_type    stance_app [MAX_STANCE];

/*

extern  const   struct    family_name_type   family_name [MAX_FAMILY];

*/
/*
 * Global variables.
 */
extern          char                    bug_buf         [];
extern          time_t                  current_time;
extern          bool                    fLogAll;
extern          FILE *                  fpReserve;
extern          KILL_DATA               kill_table      [];
extern          char                    log_buf         [];
extern          TIME_INFO_DATA          time_info;
extern          WEATHER_DATA            weather_info;
extern          DESCRIPTOR_DATA   *     descriptor_list;
extern          CHAR_DATA         *     char_list;
extern          ROOM_INDEX_DATA   *     room_index_hash [ MAX_KEY_HASH ];
extern          OBJ_INDEX_DATA    *     obj_index_hash [ MAX_KEY_HASH ];

/* board junk */
extern BOARD_DATA   *  first_board;
extern BOARD_DATA   *	last_board;
extern BOARD_DATA   *	board_free;
extern MESSAGE_DATA *	message_free;
 


/* Various linked lists head/tail pointer declarations. -- Altrag */
#include "lists.h"



/*
 * Command functions.
 * Defined in act_*.c (mostly).
 */

/**************************
 * This bunch of commands *
 * added by Stephen ;)    *
 **************************/

DECLARE_DO_FUN( do_test		);

DECLARE_DO_FUN( do_exlist       );
DECLARE_DO_FUN( do_vlist        );
DECLARE_DO_FUN( do_rename       );

DECLARE_DO_FUN( do_sdelete      );

DECLARE_DO_FUN( do_accept       );
DECLARE_DO_FUN( do_adapt        );
DECLARE_DO_FUN( do_affected     );
DECLARE_DO_FUN( do_afk		);
DECLARE_DO_FUN( do_alias	);
DECLARE_DO_FUN( do_appraise	);
DECLARE_DO_FUN( build_arealist	);
DECLARE_DO_FUN( do_ask          );
DECLARE_DO_FUN( do_assassinate  );
DECLARE_DO_FUN( do_assist	);
DECLARE_DO_FUN( do_bamfin       );
DECLARE_DO_FUN( do_bamfout      );
DECLARE_DO_FUN( do_bank         );
DECLARE_DO_FUN( do_banish	);
DECLARE_DO_FUN( do_bash         );
DECLARE_DO_FUN( do_beep		);
DECLARE_DO_FUN( do_beserk	);
DECLARE_DO_FUN( do_bid		);
DECLARE_DO_FUN( do_rbid          );
DECLARE_DO_FUN( do_mbid          );
DECLARE_DO_FUN( do_cdonate      );
DECLARE_DO_FUN( do_circle       );
DECLARE_DO_FUN( do_clan         );
DECLARE_DO_FUN( do_clan_list    );
DECLARE_DO_FUN( do_clan_recall  );
DECLARE_DO_FUN( do_clutch	);
DECLARE_DO_FUN( do_clutchinfo   );
DECLARE_DO_FUN( do_colist	);
DECLARE_DO_FUN( do_colour	);
DECLARE_DO_FUN( do_creator	);
DECLARE_DO_FUN( do_cset         );
DECLARE_DO_FUN( do_cwhere       );
DECLARE_DO_FUN( do_deathmatc    );
DECLARE_DO_FUN( do_deathmatch   );
DECLARE_DO_FUN( do_diagnose     );
DECLARE_DO_FUN( do_dirt         );
DECLARE_DO_FUN( do_dog          );
DECLARE_DO_FUN( do_donate       );
DECLARE_DO_FUN( do_edit		);
DECLARE_DO_FUN( do_enter	);
DECLARE_DO_FUN( do_feed		);
DECLARE_DO_FUN( do_fights       );
DECLARE_DO_FUN( do_finger	);
DECLARE_DO_FUN( do_flame        );
DECLARE_DO_FUN( do_gain         );
DECLARE_DO_FUN( do_gold		);
DECLARE_DO_FUN( do_gossip       );
DECLARE_DO_FUN( do_ooc          );
DECLARE_DO_FUN( do_espanol      );
DECLARE_DO_FUN( do_francais     );
DECLARE_DO_FUN( do_quest2       );
DECLARE_DO_FUN( do_guild        );
DECLARE_DO_FUN( do_halls        );
DECLARE_DO_FUN( do_headbutt	);
DECLARE_DO_FUN( do_knee		);
DECLARE_DO_FUN( do_heal         );
DECLARE_DO_FUN( do_hunt         );
DECLARE_DO_FUN( do_resetpassword);
DECLARE_DO_FUN( do_iscore       );
DECLARE_DO_FUN( do_isnoop       );
DECLARE_DO_FUN( do_iwhere       );
DECLARE_DO_FUN( do_leav		);
DECLARE_DO_FUN( do_leave        );
DECLARE_DO_FUN( do_lhunt	);
DECLARE_DO_FUN( do_make		);
DECLARE_DO_FUN( do_monitor	);
DECLARE_DO_FUN( do_mpcr         );
DECLARE_DO_FUN( do_music        );
DECLARE_DO_FUN( do_newbie       );
DECLARE_DO_FUN( do_nopray       );
DECLARE_DO_FUN( do_pemote       );
DECLARE_DO_FUN( do_players      );
DECLARE_DO_FUN( do_pray         );
DECLARE_DO_FUN( do_punch	);
DECLARE_DO_FUN( do_quest	);
DECLARE_DO_FUN( do_race         );
DECLARE_DO_FUN( do_race_list    );
DECLARE_DO_FUN( do_retrieve	);
DECLARE_DO_FUN( do_scan         );
DECLARE_DO_FUN( do_setclass     );
DECLARE_DO_FUN( do_smash        );
DECLARE_DO_FUN( do_shadowform   );
DECLARE_DO_FUN( do_shelp	);
DECLARE_DO_FUN( do_sstat	);
DECLARE_DO_FUN( do_stake	);
DECLARE_DO_FUN( do_status       );
DECLARE_DO_FUN( do_stun		);
DECLARE_DO_FUN( do_togbuild     );
DECLARE_DO_FUN( do_togleader    );
DECLARE_DO_FUN( do_tongue       );
DECLARE_DO_FUN( do_trip         );
DECLARE_DO_FUN( do_whisper      );
DECLARE_DO_FUN( do_whois	);
DECLARE_DO_FUN( do_whoname	);
DECLARE_DO_FUN( do_worth	);
DECLARE_DO_FUN( do_zzz          );
DECLARE_DO_FUN( do_listspells   );
DECLARE_DO_FUN( do_reward       );
DECLARE_DO_FUN( do_togcouncil   );
DECLARE_DO_FUN( do_council	  );
DECLARE_DO_FUN( do_rename	);
DECLARE_DO_FUN( do_sdelete	);



/* And by MAG  
 *    
 */
DECLARE_DO_FUN( build_interpret );
DECLARE_DO_FUN( do_build        );
DECLARE_DO_FUN( do_delete       );
DECLARE_DO_FUN( do_read         );
DECLARE_DO_FUN( do_savearea     );
DECLARE_DO_FUN( do_write        );
DECLARE_DO_FUN( do_mfindlev     );
DECLARE_DO_FUN( do_check_areas  );
DECLARE_DO_FUN( do_check_area   );

DECLARE_DO_FUN( do_ofindlev     );
DECLARE_DO_FUN( do_howl         );

/****************************
 * Now the 'standard' stuff:*
 ****************************/

DECLARE_DO_FUN( do_advance      );
DECLARE_DO_FUN( do_allow        );
DECLARE_DO_FUN( do_answer       );
DECLARE_DO_FUN( do_areas        );
DECLARE_DO_FUN( do_at           );
DECLARE_DO_FUN( do_auction      );
DECLARE_DO_FUN( do_rauction     );
DECLARE_DO_FUN( do_mauction     );
DECLARE_DO_FUN( do_auto         );
DECLARE_DO_FUN( do_autoexit     );
DECLARE_DO_FUN( do_autoloot     );
DECLARE_DO_FUN( do_autosac      );
DECLARE_DO_FUN( do_autosplit    );
DECLARE_DO_FUN( do_autoassist   );
DECLARE_DO_FUN( do_backstab     );
DECLARE_DO_FUN( do_ban          );
DECLARE_DO_FUN( do_blank        );
DECLARE_DO_FUN( do_brandish     );
DECLARE_DO_FUN( do_brief        );
DECLARE_DO_FUN( do_bug          );
DECLARE_DO_FUN( do_buy          );
DECLARE_DO_FUN( do_cast         );
DECLARE_DO_FUN( do_channels     );
DECLARE_DO_FUN( do_close        );
DECLARE_DO_FUN( do_combine      );
DECLARE_DO_FUN( do_commands     );
DECLARE_DO_FUN( do_compare      );
DECLARE_DO_FUN( do_config       );
DECLARE_DO_FUN( do_consider     );
DECLARE_DO_FUN( do_credits      );
DECLARE_DO_FUN( do_deny         );
DECLARE_DO_FUN( do_description  );
DECLARE_DO_FUN( do_disarm       );
DECLARE_DO_FUN( do_disconnect   );
DECLARE_DO_FUN( do_down         );
DECLARE_DO_FUN( do_drink        );
DECLARE_DO_FUN( do_drop         );
DECLARE_DO_FUN( do_east         );
DECLARE_DO_FUN( do_eat          );
DECLARE_DO_FUN( do_echo         );
DECLARE_DO_FUN( do_emote        );
DECLARE_DO_FUN( do_equipment    );
DECLARE_DO_FUN( do_examine      );
DECLARE_DO_FUN( do_exits        );
DECLARE_DO_FUN( do_fill         );
DECLARE_DO_FUN( do_flee         );
DECLARE_DO_FUN( do_follow       );
DECLARE_DO_FUN( do_force        );
DECLARE_DO_FUN( do_freeze       );
DECLARE_DO_FUN( do_game		);
DECLARE_DO_FUN( do_get          );
DECLARE_DO_FUN( do_give         );
DECLARE_DO_FUN( do_goto         );
DECLARE_DO_FUN( do_group        );
DECLARE_DO_FUN( do_gtell        );
DECLARE_DO_FUN( do_help         );
DECLARE_DO_FUN( do_hide         );
DECLARE_DO_FUN( do_holylight    );
DECLARE_DO_FUN( do_idea         );
DECLARE_DO_FUN( do_immtalk      );
DECLARE_DO_FUN( do_incognito	  );
DECLARE_DO_FUN( do_inventory    );
DECLARE_DO_FUN( do_invis        );
DECLARE_DO_FUN( do_kick         );
DECLARE_DO_FUN( do_kill         );
DECLARE_DO_FUN( do_list         );
DECLARE_DO_FUN( do_lock         );
DECLARE_DO_FUN( do_log          );
DECLARE_DO_FUN( do_look         );
DECLARE_DO_FUN( do_loot		);
DECLARE_DO_FUN( do_memory       );
DECLARE_DO_FUN( do_mfind        );
DECLARE_DO_FUN( do_mload        );
DECLARE_DO_FUN( do_mpasound     );
DECLARE_DO_FUN( do_mpat         );
DECLARE_DO_FUN( do_mpecho       );
DECLARE_DO_FUN( do_mpechoaround );
DECLARE_DO_FUN( do_mpechoat     );
DECLARE_DO_FUN( do_mpforce      );
DECLARE_DO_FUN( do_mpgoto       );
DECLARE_DO_FUN( do_mpjunk       );
DECLARE_DO_FUN( do_mpkill       );
DECLARE_DO_FUN( do_mpmload      );
DECLARE_DO_FUN( do_mpoload      );
DECLARE_DO_FUN( do_mppurge      );
DECLARE_DO_FUN( do_mpstat       );
DECLARE_DO_FUN( do_mptransfer   );
DECLARE_DO_FUN( do_mset         );
DECLARE_DO_FUN( do_mstat        );
DECLARE_DO_FUN( do_mwhere       );
DECLARE_DO_FUN( do_murde        );
DECLARE_DO_FUN( do_murder       );
DECLARE_DO_FUN( do_noemote      );
DECLARE_DO_FUN( do_north        );
DECLARE_DO_FUN( do_note         );
DECLARE_DO_FUN( do_notell       );
DECLARE_DO_FUN( do_ofind        );
DECLARE_DO_FUN( do_oload        );
DECLARE_DO_FUN( do_open         );
DECLARE_DO_FUN( do_order        );
DECLARE_DO_FUN( do_oset         );
DECLARE_DO_FUN( do_ostat        );
DECLARE_DO_FUN( do_owhere       );
DECLARE_DO_FUN( do_pagelen      );
DECLARE_DO_FUN( do_pardon       );
DECLARE_DO_FUN( do_password     );
DECLARE_DO_FUN( do_peace        );
DECLARE_DO_FUN( do_pick         );
DECLARE_DO_FUN( do_pose         );
DECLARE_DO_FUN( do_practice     );
DECLARE_DO_FUN( do_prompt       );
DECLARE_DO_FUN( do_purge        );
DECLARE_DO_FUN( do_put          );
DECLARE_DO_FUN( do_quaff        );
DECLARE_DO_FUN( do_question     );
DECLARE_DO_FUN( do_quest2	);
DECLARE_DO_FUN( do_qui          );
DECLARE_DO_FUN( do_quit         );
DECLARE_DO_FUN( do_reboo        );
DECLARE_DO_FUN( do_reboot       );
DECLARE_DO_FUN( do_recall       );
DECLARE_DO_FUN( do_recho        );
DECLARE_DO_FUN( do_recite       );
DECLARE_DO_FUN( do_remove       );
DECLARE_DO_FUN( do_rent         );
DECLARE_DO_FUN( do_reply        );
DECLARE_DO_FUN( do_report       );
DECLARE_DO_FUN( do_rescue       );
DECLARE_DO_FUN( do_rest         );
DECLARE_DO_FUN( do_restore      );
DECLARE_DO_FUN( do_return       );
DECLARE_DO_FUN( do_rset         );
DECLARE_DO_FUN( do_rstat        );
DECLARE_DO_FUN( do_sacrifice    );
DECLARE_DO_FUN( do_save         );
DECLARE_DO_FUN( do_say          );
DECLARE_DO_FUN( do_score        );
DECLARE_DO_FUN( do_sell         );
DECLARE_DO_FUN( do_shout        );
DECLARE_DO_FUN( do_shutdow      );
DECLARE_DO_FUN( do_shutdown     );
DECLARE_DO_FUN( do_silence      );
DECLARE_DO_FUN( do_sla          );
DECLARE_DO_FUN( do_slay         );
DECLARE_DO_FUN( do_sleep        );
DECLARE_DO_FUN( do_slist        );
DECLARE_DO_FUN( do_slookup      );
DECLARE_DO_FUN( do_sneak        );
DECLARE_DO_FUN( do_snoop        );
DECLARE_DO_FUN( do_socials      );
DECLARE_DO_FUN( do_south        );
DECLARE_DO_FUN( do_spells       );
DECLARE_DO_FUN( do_split        );
DECLARE_DO_FUN( do_sset         );
DECLARE_DO_FUN( do_stand        );
DECLARE_DO_FUN( do_steal        );
DECLARE_DO_FUN( do_switch       );
DECLARE_DO_FUN( do_tell         );
DECLARE_DO_FUN( do_time         );
DECLARE_DO_FUN( do_title        );
DECLARE_DO_FUN( do_train        );
DECLARE_DO_FUN( do_transfer     );
DECLARE_DO_FUN( do_transdm      );
DECLARE_DO_FUN( do_trust        );
DECLARE_DO_FUN( do_typo         );
DECLARE_DO_FUN( do_unlock       );
DECLARE_DO_FUN( do_up           );
DECLARE_DO_FUN( do_users        );
DECLARE_DO_FUN( do_value        );
DECLARE_DO_FUN( do_visible      );
DECLARE_DO_FUN( do_wake         );
DECLARE_DO_FUN( do_wear         );
DECLARE_DO_FUN( do_weather      );
DECLARE_DO_FUN( do_west         );
DECLARE_DO_FUN( do_where        );
DECLARE_DO_FUN( do_who          );
DECLARE_DO_FUN( do_wimpy        );
DECLARE_DO_FUN( do_wizhelp      );
DECLARE_DO_FUN( do_wizify       );
DECLARE_DO_FUN( do_wizlist      );
DECLARE_DO_FUN( do_wizlock      );
DECLARE_DO_FUN( do_yell         );
DECLARE_DO_FUN( do_zap          );

/* from Titania@AA/Sylvana@LCN */
DECLARE_DO_FUN( do_otype );
DECLARE_DO_FUN( do_owhere );

/* Added by Eligan, July 10 */

DECLARE_DO_FUN( do_ignore       );

/*   
      NEW SKILLS  (SRZ)

*/
DECLARE_DO_FUN( do_family       );
DECLARE_DO_FUN( do_mount        );
DECLARE_DO_FUN( do_dismount     );
DECLARE_DO_FUN( do_qpspend	);
DECLARE_DO_FUN( do_disguise     );
DECLARE_DO_FUN( do_instruct     );
DECLARE_DO_FUN( do_frenzy     );
DECLARE_DO_FUN( do_adrenaline     );
DECLARE_DO_FUN( do_target     );
DECLARE_DO_FUN( do_charge    );
DECLARE_DO_FUN( do_connect    );
DECLARE_DO_FUN( do_stance	);
DECLARE_DO_FUN( do_enchant	);

/*
DECLARE_DO_FUN( do_teach      );
*/


/* 
 *  NEW CLAN COMMANDS (ZEN)
 */

DECLARE_DO_FUN( do_ctoggle );
DECLARE_DO_FUN( do_politics	);
DECLARE_DO_FUN( do_negotiate  );

/*
 *   New Channels (ZEN)
 */

DECLARE_DO_FUN( do_diptalk );
DECLARE_DO_FUN( do_familytalk );
DECLARE_DO_FUN( do_remorttalk );
DECLARE_DO_FUN( do_crusade );
DECLARE_DO_FUN(do_adepttalk      );  /* contrib by Hermes   */
DECLARE_DO_FUN( do_rulers	);
DECLARE_DO_FUN( do_scout	);


/* Llolth */
/* DECLARE_DO_FUN( do_tribetalk );
*/
/*
 *  New immcommands
 */

DECLARE_DO_FUN( do_alink );
DECLARE_DO_FUN( do_for		);    /* Flar */
DECLARE_DO_FUN( do_hotreboo	  );	/* Flar */
DECLARE_DO_FUN( do_hotreboot	  );	/* Flar */
DECLARE_DO_FUN( do_imtlset	  );  /* Flar */
DECLARE_DO_FUN( do_gain_stat_reset );
DECLARE_DO_FUN( do_sedit );
DECLARE_DO_FUN( do_olmsg	);
DECLARE_DO_FUN( do_scheck	);
DECLARE_DO_FUN( do_immbrand	);





/*
 * Werwolf
 */
DECLARE_DO_FUN( do_rage );
DECLARE_DO_FUN( do_howl );
DECLARE_DO_FUN( do_tribe );
DECLARE_DO_FUN( do_scent );
DECLARE_DO_FUN( do_imprint );


/*
 * Spell functions.
 * Defined in magic.c.
 */
DECLARE_SPELL_FUN(      spell_null              );

DECLARE_SPELL_FUN(	spell_ego_whip		);
DECLARE_SPELL_FUN(	spell_physic_thrust	);
DECLARE_SPELL_FUN(	spell_physic_crush	);
DECLARE_SPELL_FUN(	spell_mind_flail	);

DECLARE_SPELL_FUN(      spell_acid_blast        );
DECLARE_SPELL_FUN(	spell_animate		);
DECLARE_SPELL_FUN(      spell_armor             );
DECLARE_SPELL_FUN(      spell_badbreath         );
DECLARE_SPELL_FUN(	spell_bark_skin		);
DECLARE_SPELL_FUN(      spell_bless             );
DECLARE_SPELL_FUN(      spell_blindness         );
DECLARE_SPELL_FUN(	spell_bloody_tears	);
DECLARE_SPELL_FUN(      spell_burning_hands     );
DECLARE_SPELL_FUN(      spell_call_lightning    );
DECLARE_SPELL_FUN(	spell_calm		);
DECLARE_SPELL_FUN(      spell_cause_critical    );
DECLARE_SPELL_FUN(      spell_cause_light       );
DECLARE_SPELL_FUN(      spell_cause_serious     );
DECLARE_SPELL_FUN(      spell_change_sex        );
DECLARE_SPELL_FUN(      spell_charm_person      );
DECLARE_SPELL_FUN(      spell_chill_touch       );
DECLARE_SPELL_FUN(      spell_colour_spray      );
DECLARE_SPELL_FUN(      spell_continual_light   );
DECLARE_SPELL_FUN(      spell_control_weather   );
DECLARE_SPELL_FUN(      spell_create_food       );
DECLARE_SPELL_FUN(      spell_create_spring     );
DECLARE_SPELL_FUN(      spell_create_water      );
DECLARE_SPELL_FUN(      spell_cure_blindness    );
DECLARE_SPELL_FUN(      spell_cure_critical     );
DECLARE_SPELL_FUN(      spell_cure_light        );
DECLARE_SPELL_FUN(      spell_cure_poison       );
DECLARE_SPELL_FUN(      spell_cure_serious      );
DECLARE_SPELL_FUN(      spell_curse             );
DECLARE_SPELL_FUN(      spell_detect_evil       );
DECLARE_SPELL_FUN(      spell_detect_hidden     );
DECLARE_SPELL_FUN(      spell_detect_invis      );
DECLARE_SPELL_FUN(      spell_detect_magic      );
DECLARE_SPELL_FUN(      spell_detect_poison     );
DECLARE_SPELL_FUN(	spell_detect_undead	);
DECLARE_SPELL_FUN(	spell_detection		);
DECLARE_SPELL_FUN(	spell_dimension_blade	);
DECLARE_SPELL_FUN(      spell_dispel_evil       );
DECLARE_SPELL_FUN(      spell_dispel_magic      );
DECLARE_SPELL_FUN(      spell_earthquake        );
DECLARE_SPELL_FUN(      spell_enchant_weapon    );
DECLARE_SPELL_FUN(      spell_encumber          );
DECLARE_SPELL_FUN(	spell_enhance_weapon    );
DECLARE_SPELL_FUN(      spell_energy_drain      );
DECLARE_SPELL_FUN(      spell_faerie_fire       );
DECLARE_SPELL_FUN(      spell_faerie_fog        );
DECLARE_SPELL_FUN(	spell_fighting_trance	);
DECLARE_SPELL_FUN(      spell_fireball          );
DECLARE_SPELL_FUN(	spell_fire_blade	);
DECLARE_SPELL_FUN(      spell_flamestrike       );
DECLARE_SPELL_FUN(      spell_fly               );
DECLARE_SPELL_FUN(      spell_gate              );
DECLARE_SPELL_FUN(      spell_general_purpose   );
DECLARE_SPELL_FUN(      spell_giant_strength    );
DECLARE_SPELL_FUN(      spell_harm              );
DECLARE_SPELL_FUN(      spell_heal              );
DECLARE_SPELL_FUN(      spell_high_explosive    );
DECLARE_SPELL_FUN(	spell_hypnosis		);
DECLARE_SPELL_FUN(      spell_identify          );
DECLARE_SPELL_FUN(      spell_influx            );
DECLARE_SPELL_FUN(      spell_infravision       );
DECLARE_SPELL_FUN(      spell_invis             );
DECLARE_SPELL_FUN(      spell_know_alignment    );
DECLARE_SPELL_FUN(	spell_know_weakness	);
DECLARE_SPELL_FUN(	spell_know_critical	);
DECLARE_SPELL_FUN(	spell_know_item		);
DECLARE_SPELL_FUN(      spell_lightning_bolt    );
DECLARE_SPELL_FUN(      spell_locate_object     );
DECLARE_SPELL_FUN(      spell_magic_missile     );
DECLARE_SPELL_FUN(      spell_mass_invis        );
DECLARE_SPELL_FUN(	spell_mind_bolt		);
DECLARE_SPELL_FUN(      spell_nerve_fire	);
DECLARE_SPELL_FUN(      spell_night_vision	);
DECLARE_SPELL_FUN(      spell_pass_door         );
DECLARE_SPELL_FUN(	spell_phase		);
DECLARE_SPELL_FUN(      spell_poison            );
DECLARE_SPELL_FUN(	spell_produce_food	);
DECLARE_SPELL_FUN(      spell_protection        );
DECLARE_SPELL_FUN(      spell_refresh           );
DECLARE_SPELL_FUN(      spell_remove_curse      );
DECLARE_SPELL_FUN(      spell_sanctuary         );
DECLARE_SPELL_FUN(	spell_see_magic		);
DECLARE_SPELL_FUN(	spell_sense_evil	);
DECLARE_SPELL_FUN(      spell_shocking_grasp    );
DECLARE_SPELL_FUN(      spell_shield            );
DECLARE_SPELL_FUN(      spell_sleep             );
DECLARE_SPELL_FUN(	spell_stalker		);
DECLARE_SPELL_FUN(      spell_stone_skin        );
DECLARE_SPELL_FUN(	spell_suffocate		);
DECLARE_SPELL_FUN(      spell_summon            );
DECLARE_SPELL_FUN(      spell_teleport          );
DECLARE_SPELL_FUN(      spell_ventriloquate     );
DECLARE_SPELL_FUN(      spell_warcry            );  /* --Stephen */
DECLARE_SPELL_FUN(      spell_weaken            );
DECLARE_SPELL_FUN(	spell_window		);
DECLARE_SPELL_FUN(	spell_portal		);
DECLARE_SPELL_FUN(	spell_beacon		);
DECLARE_SPELL_FUN(      spell_word_of_recall    );
DECLARE_SPELL_FUN(      spell_acid_breath       );
DECLARE_SPELL_FUN(      spell_fire_breath       );
DECLARE_SPELL_FUN(      spell_frost_breath      );
DECLARE_SPELL_FUN(      spell_gas_breath        );
DECLARE_SPELL_FUN(      spell_lightning_breath  );
DECLARE_SPELL_FUN( spell_planergy               );
DECLARE_SPELL_FUN( spell_static                 );
DECLARE_SPELL_FUN( spell_visit                  );
DECLARE_SPELL_FUN( spell_chain_lightning        );
DECLARE_SPELL_FUN( spell_phobia                 );
DECLARE_SPELL_FUN( spell_barrier                );
DECLARE_SPELL_FUN( spell_mindflame              );
DECLARE_SPELL_FUN( spell_laserbolt		);
DECLARE_SPELL_FUN( spell_hellspawn		);
DECLARE_SPELL_FUN( spell_travel			);
DECLARE_SPELL_FUN( spell_flare			);
DECLARE_SPELL_FUN( spell_mystic_armor		);
DECLARE_SPELL_FUN( spell_blood_leach		);
DECLARE_SPELL_FUN( spell_seal_room		);
DECLARE_SPELL_FUN( spell_shade			); /* Slot 542 */
DECLARE_SPELL_FUN( spell_deflect_weapon         ); /* slot 600 */
DECLARE_SPELL_FUN( spell_black_hand             ); /* slot 601 */
DECLARE_SPELL_FUN( spell_throw_needle           ); /* slot 602 */
DECLARE_SPELL_FUN( spell_morale                 ); /* slot 603 */
DECLARE_SPELL_FUN( spell_leadership             ); /* slot 604 */
DECLARE_SPELL_FUN( spell_ice_bolt               ); /* slot 605 */
DECLARE_SPELL_FUN( spell_waterelem              ); /* slot 606 */
DECLARE_SPELL_FUN( spell_skeleton               ); /* slot 607 */
DECLARE_SPELL_FUN( spell_poison_weapon          ); /* slot 608 */
DECLARE_SPELL_FUN( spell_embrace                ); /* slot 609 */
DECLARE_SPELL_FUN( spell_mesmerise              ); /* slot 610 */
DECLARE_SPELL_FUN( spell_ethereal               ); /* slot 611 */
DECLARE_SPELL_FUN( spell_fireelem               ); /* slot 612 */
DECLARE_SPELL_FUN( spell_rune_fire              ); /* slot 613 */
DECLARE_SPELL_FUN( spell_rune_shock             ); /* slot 614 */
DECLARE_SPELL_FUN( spell_rune_poison            ); /* slot 615 */
DECLARE_SPELL_FUN( spell_healing_light          ); /* slot 616 */
DECLARE_SPELL_FUN( spell_wither_shadow          ); /* slot 617 */
DECLARE_SPELL_FUN( spell_mana_flare             ); /* slot 618 */
DECLARE_SPELL_FUN( spell_mana_drain             ); /* slot 619 */
DECLARE_SPELL_FUN( spell_cage                   ); /* slot 620 */
DECLARE_SPELL_FUN( spell_cloak_absorb		); /* slot 621 */
DECLARE_SPELL_FUN( spell_cloak_reflect          ); /* slot 622 */
DECLARE_SPELL_FUN( spell_cloak_flaming		); /* slot 623 */
DECLARE_SPELL_FUN( spell_cloak_darkness         ); /* slot 624 */
DECLARE_SPELL_FUN( spell_room_dispel		); /* slot 625 */
DECLARE_SPELL_FUN( spell_cloak_adept            ); /* slot 626 */
DECLARE_SPELL_FUN( spell_cloak_regen   		); /* slot 627 */
DECLARE_SPELL_FUN( spell_throw_star             ); /* slot 628 */
DECLARE_SPELL_FUN( spell_soul_net    		); /* slot 629 */
DECLARE_SPELL_FUN( spell_condense_soul          ); /* slot 630 */
DECLARE_SPELL_FUN( spell_blood_walk   		); /* slot 631 */
DECLARE_SPELL_FUN( spell_restoration   		); /* slot 632 */
DECLARE_SPELL_FUN( spell_infuse      		); /* slot 633 */
DECLARE_SPELL_FUN( spell_holy_light   		); /* slot 634 */
DECLARE_SPELL_FUN( spell_divine_intervention 	); /* slot 635 */
DECLARE_SPELL_FUN( spell_holy_armor      		); /* slot 636 */
DECLARE_SPELL_FUN( spell_earthelem   		); /* slot 637 */
DECLARE_SPELL_FUN( spell_iron_golem      		); /* slot 638 */
DECLARE_SPELL_FUN( spell_diamond_golem   		); /* slot 639 */
DECLARE_SPELL_FUN( spell_soul_thief		 	); /* slot 640 */
DECLARE_SPELL_FUN( spell_holy_avenger    		); /* slot 641 */
DECLARE_SPELL_FUN( spell_heat_armor	   		); /* slot 642 */
DECLARE_SPELL_FUN( spell_retri_strike		 	); /* slot 643 */
DECLARE_SPELL_FUN( spell_lava_burst	    		); /* slot 644 */
DECLARE_SPELL_FUN( spell_fireshield		 	); /* slot 645 */
DECLARE_SPELL_FUN( spell_iceshield	    		); /* slot 646 */
DECLARE_SPELL_FUN( spell_shockshield	   		); /* slot 647 */
DECLARE_SPELL_FUN( spell_shadowshield		 	); /* slot 648 */
DECLARE_SPELL_FUN( spell_thoughtshield	    		); /* slot 649 */
/* enraged holds slot 651-654   */
DECLARE_SPELL_FUN( spell_tribe_claw			); /* slot 655 */
DECLARE_SPELL_FUN( spell_wolf_mark				); /* slot 656 */
DECLARE_SPELL_FUN( spell_blood_sign			); /* 657 */
DECLARE_SPELL_FUN( spell_blood_sense			); /* 658 */
DECLARE_SPELL_FUN( spell_summon_pegasus			); /* slot 659 */
DECLARE_SPELL_FUN( spell_summon_nightmare		); /* slot 660 */
DECLARE_SPELL_FUN( spell_summon_beast			); /* 661 */
DECLARE_SPELL_FUN( spell_summon_devourer		); /* 662 */
DECLARE_SPELL_FUN( spell_summon_shadow			); /* 663 */
DECLARE_SPELL_FUN( spell_creature_bond			); /* 664 */
DECLARE_SPELL_FUN( spell_corrupt_bond			); /* 665 */

char *  crypt           args( ( const char *key, const char *salt ) );

/*
 * Data files used by the server.
 *
 * AREA_LIST contains a list of areas to boot.
 * All files are read in completely at bootup.
 * Most output files (bug, idea, typo, shutdown) are append-only.
 *
 * The NULL_FILE is held open so that we have a stream handle in reserve,
 *   so players can go ahead and telnet to all the other descriptors.
 * Then we close it whenever we need to open a file (e.g. a save file).
 */
#define PLAYER_DIR      "../player/"    /* Player files                 */
#define NPC_DIR		"../npcs/"
#define NULL_FILE       "/dev/null"     /* To reserve one stream        */
#define MOB_DIR         "MOBProgs/"     /* MOBProg files                */

#define AREA_LIST       "area.lst"      /* List of areas                */

#define BUG_FILE        "bugs.txt"      /* For 'bug' and bug( )         */
#define IDEA_FILE       "ideas.txt"     /* For 'idea'                   */
#define TYPO_FILE       "typos.txt"     /* For 'typo'                   */
#define NOTE_FILE       "notes.txt"     /* For 'notes'                  */
/* FIXME: boards.txt in here????? */
#define SHUTDOWN_FILE   "shutdown.txt"  /* For 'shutdown'               */

#define CLAN_FILE		"clandata.dat" /* stores clan diplomacy data   */
#define CORPSE_FILE	"corpses.lst"
#define MARKS_FILE	"roommarks.lst"
#define BANS_FILE	"bans.lst"
#define RULERS_FILE	"rulers.lst"
#define CONTROLS_FILE	"area_controls.lst"
#define BRANDS_FILE	"brands.lst"

#if !defined(WHO_HTML_FILE)
#define WHO_HTML_FILE   "whofile"  /* for ftping who list to html web page :) */
#define WHO_COUNT_FILE  "whocountfile"
#endif
/* Other Stuff - Flar */
#define COPYOVER_FILE	"COPYOVER.TXT"	/* Temp data file used for copyover */
#define EXE_FILE		"../src/merc"	/* The one that runs the ACK! */


/*
 * Our function prototypes.
 * One big lump ... this is every function in Merc.
 */
#define CD      CHAR_DATA
#define MID     MOB_INDEX_DATA
#define OD      OBJ_DATA
#define OID     OBJ_INDEX_DATA
#define RID     ROOM_INDEX_DATA
#define SF      SPEC_FUN
#define OF	OBJ_FUN

/* act_comm.c */
bool	is_note_to	args( ( CHAR_DATA *ch, NOTE_DATA *pnote ) );
void    add_follower    args( ( CHAR_DATA *ch, CHAR_DATA *master ) );
void    stop_follower   args( ( CHAR_DATA *ch ) );
void    die_follower    args( ( CHAR_DATA *ch ) );
bool    is_same_group   args( ( CHAR_DATA *ach, CHAR_DATA *bch ) );
bool    is_group_leader args( ( CHAR_DATA *ch ) );
char *  slur_text       args( ( char *argument ) );
void    send_to_room    args( ( char *message, ROOM_INDEX_DATA *room ) );
void    list_who_to_output   args(  ( void )   );

/* act_info.c */
void    set_title       args( ( CHAR_DATA *ch, char *title ) );
char *  colour_string   args( ( CHAR_DATA *CH, char *argument ) );
char *  get_family_name     args( ( CHAR_DATA *ch ) );
char *  get_tribe_name     args( ( CHAR_DATA *ch ) );

/* act_mob.c */
void 	int_combat_handler args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
void    int_handler	args( ( CHAR_DATA *ch ) );


/* act_move.c */
void    move_char       args( ( CHAR_DATA *ch, int door ) );

/* act_obj.c */

void    get_obj		args( ( CHAR_DATA *ch, OBJ_DATA *obj, OBJ_DATA *container ) );
bool can_wear_at(CHAR_DATA * ch, OBJ_DATA * obj, int location);



/* act_wiz.c */
ROOM_INDEX_DATA *       find_location   args( ( CHAR_DATA *ch, char *arg ) );

/* board.c */
BOARD_DATA * load_board(OBJ_INDEX_DATA * pObj);
void    do_show_contents        args( ( CHAR_DATA *ch, OBJ_DATA * obj ) );
void    do_show_message         args( ( CHAR_DATA *ch, int mess_num, OBJ_DATA * obj ) );
void    do_edit_message		args( ( CHAR_DATA *ch, int mess_num, OBJ_DATA * obj ) );
void    do_add_to_message       args( ( CHAR_DATA *ch, char *argument ) );
void    do_start_a_message      args( ( CHAR_DATA *ch, char *argument ) );
void    save_message_data       args( ( void ) );
void    load_messages           args( ( void ) );

/* comm.c */
void    close_socket    args( ( DESCRIPTOR_DATA *dclose ) );
void    show_menu_to	args( ( DESCRIPTOR_DATA *d ) ); /* Main */
void    show_amenu_to   args( ( DESCRIPTOR_DATA *d ) ); /* Attributes */
void    show_rmenu_to   args( ( DESCRIPTOR_DATA *d ) ); /* Race */
void    show_smenu_to   args( ( DESCRIPTOR_DATA *d ) ); /* Sex */
void    show_cmenu_to   args( ( DESCRIPTOR_DATA *d ) ); /* Class */
void    write_to_buffer args( ( DESCRIPTOR_DATA *d, const char *txt,
			    int length ) );
void    send_to_char    args( ( const char *txt, CHAR_DATA *ch ) );
void    show_string     args( ( DESCRIPTOR_DATA *d, char *input ) );
void    act             args( ( const char *format, CHAR_DATA *ch,
			    const void *arg1, const void *arg2, int type ) );
void    hang            args( ( const char *str ) );

/* db.c */
void	perm_update	args( ( void ) );
void    boot_db         args( ( bool fCopyOver ) );
void    area_update     args( ( void ) );
void    message_update  args( ( void ) );
CD *    create_mobile   args( ( MOB_INDEX_DATA *pMobIndex ) );
OD *    create_object   args( ( OBJ_INDEX_DATA *pObjIndex, int level ) );
void    clear_char      args( ( CHAR_DATA *ch ) );
void    free_char       args( ( CHAR_DATA *ch ) );
char *  get_extra_descr args( ( const char *name, EXTRA_DESCR_DATA *ed ) );
MID *   get_mob_index   args( ( int vnum ) );
OID *   get_obj_index   args( ( int vnum ) );
RID *   get_room_index  args( ( int vnum ) );
char    fread_letter    args( ( FILE *fp ) );
int     fread_number    args( ( FILE *fp ) );
char *  fread_string    args( ( FILE *fp ) );
void    fread_to_eol    args( ( FILE *fp ) );
char *  fsave_to_eol    args( ( FILE *fp ) );
char *  fread_word      args( ( FILE *fp ) );

/* void *  alloc_mem       args( ( int sMem ) );
void    check_freed     args( ( unsigned int first, unsigned int last) );
void    check_free_mem  args( ( void ) );
void *  alloc_perm      args( ( int sMem ) );
void    free_mem        args( ( void *pMem, int sMem ) );*/

/* spec: renamed getmem -> _getmem, nuked unused alloc_perm */
/* void *  alloc_perm      args( ( int sMem ) ); */
void *	_getmem		args( ( int size, const char *caller, int log ) );
void	dispose		args( ( void *mem, int size ) );
char *  str_dup         args( ( const char *str ) );
void    free_string     args( ( char *pstr ) );
int     number_fuzzy    args( ( int number ) );
int     number_range    args( ( int from, int to ) );
int     number_percent  args( ( void ) );
int     number_door     args( ( void ) );
int     number_bits     args( ( int width ) );
int     number_mm       args( ( void ) );
int     dice            args( ( int number, int size ) );
int     interpolate     args( ( int level, int value_00, int value_32 ) );
void    smash_tilde     args( ( char *str ) );
bool    str_cmp         args( ( const char *astr, const char *bstr ) );
bool    str_prefix      args( ( const char *astr, const char *bstr ) );
bool    str_infix       args( ( const char *astr, const char *bstr ) );
bool    str_suffix      args( ( const char *astr, const char *bstr ) );
char *  capitalize      args( ( const char *str ) );
void    append_file     args( ( CHAR_DATA *ch, char *file, char *str ) );
void    bug             args( ( const char *str, int param ) );
void    log_string      args( ( const char *str ) );
void    tail_chain      args( ( void ) );
void    safe_strcat     args( ( int max_len, char * dest,char * source ) );
void    send_to_descrips args( ( const char *message ) );
void    bug_string      args( ( const char *str, const char *str2) );
/* Added stuff -Flar */
void    bugf (char * fmt, ...) __attribute__ ((format(printf,1,2)));
void    log_printf (char * fmt, ...) __attribute__ ((format(printf,1,2)));

/* fight.c */
void    violence_update args( ( void ) );
void    multi_hit       args( ( CHAR_DATA *ch, CHAR_DATA *victim, int dt ) );
void    damage          args( ( CHAR_DATA *ch, CHAR_DATA *victim, int dam,
			    int dt ) );
void    update_pos      args( ( CHAR_DATA *victim ) );
void    stop_fighting   args( ( CHAR_DATA *ch, bool fBoth ) );
void    death_cry       args( ( CHAR_DATA *ch ) );
void    raw_kill        args( ( CHAR_DATA *victim, char *argument ) );
void    check_killer    args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );


/* handler.c */
bool    remove_obj	args( ( CHAR_DATA *ch, int iWear, bool fReplace ) );
int     get_trust       args( ( CHAR_DATA *ch 				) );
void	my_get_age	args( ( CHAR_DATA *ch, char * buf		) );
int     my_get_hours	args( ( CHAR_DATA *ch ) );
int     get_age         args( ( CHAR_DATA *ch ) );
int     get_curr_str    args( ( CHAR_DATA *ch ) );
int     get_curr_int    args( ( CHAR_DATA *ch ) );
int     get_curr_wis    args( ( CHAR_DATA *ch ) );
int     get_curr_dex    args( ( CHAR_DATA *ch ) );
int     get_curr_con    args( ( CHAR_DATA *ch ) );
int     can_carry_n     args( ( CHAR_DATA *ch ) );
int     can_carry_w     args( ( CHAR_DATA *ch ) );
bool    is_name         args( ( const char *str, char *namelist ) );

void    affect_to_room  args( ( ROOM_INDEX_DATA *room, ROOM_AFFECT_DATA *raf ) );
void    r_affect_remove args( ( ROOM_INDEX_DATA *room, ROOM_AFFECT_DATA *raf ) );

void    affect_to_char  args( ( CHAR_DATA *ch, AFFECT_DATA *paf ) );
void    affect_remove   args( ( CHAR_DATA *ch, AFFECT_DATA *paf ) );
void    affect_strip    args( ( CHAR_DATA *ch, int sn ) );
bool    is_affected     args( ( CHAR_DATA *ch, int sn ) );
void    affect_join     args( ( CHAR_DATA *ch, AFFECT_DATA *paf ) );
void    char_from_room  args( ( CHAR_DATA *ch ) );
void    char_to_room    args( ( CHAR_DATA *ch, ROOM_INDEX_DATA *pRoomIndex ) );
void    obj_to_char     args( ( OBJ_DATA *obj, CHAR_DATA *ch ) );
void    obj_from_char   args( ( OBJ_DATA *obj ) );
int     apply_ac        args( ( OBJ_DATA *obj, int iWear ) );
OD *    get_eq_char     args( ( CHAR_DATA *ch, int iWear ) );
void    equip_char      args( ( CHAR_DATA *ch, OBJ_DATA *obj, int iWear ) );
void    unequip_char    args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
int     count_obj_list  args( ( OBJ_INDEX_DATA *obj, OBJ_DATA *list ) );
int     count_obj_room  args( ( OBJ_INDEX_DATA *obj, OBJ_DATA *list ) );
void    obj_from_room   args( ( OBJ_DATA *obj ) );
void    obj_to_room     args( ( OBJ_DATA *obj, ROOM_INDEX_DATA *pRoomIndex ) );
void    obj_to_obj      args( ( OBJ_DATA *obj, OBJ_DATA *obj_to ) );
void    obj_from_obj    args( ( OBJ_DATA *obj ) );
void    extract_obj     args( ( OBJ_DATA *obj ) );
void    extract_char    args( ( CHAR_DATA *ch, bool fPull ) );
CD *    get_char_room   args( ( CHAR_DATA *ch, char *argument ) );
CD *    get_char_world  args( ( CHAR_DATA *ch, char *argument ) );
CD *    get_char_area   args( ( CHAR_DATA *ch, char *argument ) );
OD *    get_obj_type    args( ( OBJ_INDEX_DATA *pObjIndexData ) );
OD *    get_obj_list    args( ( CHAR_DATA *ch, char *argument,
			    OBJ_DATA *list ) );
OD *    get_obj_room    args( ( CHAR_DATA *ch, char *argument,
			    OBJ_DATA *list ) );

OD *    get_obj_carry   args( ( CHAR_DATA *ch, char *argument ) );
OD *    get_obj_wear    args( ( CHAR_DATA *ch, char *argument ) );
OD *    get_obj_here    args( ( CHAR_DATA *ch, char *argument ) );
OD *    get_obj_world   args( ( CHAR_DATA *ch, char *argument ) );
OD *    create_money    args( ( int amount ) );
int     get_obj_number  args( ( OBJ_DATA *obj ) );
int     get_obj_weight  args( ( OBJ_DATA *obj 			) );
bool    room_is_dark    args( ( ROOM_INDEX_DATA *pRoomIndex 	) );
bool    room_is_private args( ( ROOM_INDEX_DATA *pRoomIndex 	) );
bool    can_see         args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
bool    can_see_obj     args( ( CHAR_DATA *ch, OBJ_DATA *obj	) );
bool    can_drop_obj    args( ( CHAR_DATA *ch, OBJ_DATA *obj 	) );
bool 	can_sac_obj	args( ( CHAR_DATA *ch, OBJ_DATA *obj	) );
char *  item_type_name  args( ( OBJ_DATA *obj 			) );
char *  affect_loc_name args( ( int location 			) );
char *  affect_bit_name args( ( int vector 			) );
char *  raffect_bit_name args( ( int vector 			) );

char *  extra_bit_name  args( ( int extra_flags 		) );
char *  race_name       args( ( CHAR_DATA *ch 			) );
char *  short_race_name args( ( CHAR_DATA *ch 			) );
bool    can_use         args( ( CHAR_DATA *ch, OBJ_DATA *obj 	) );
char *  who_can_use     args( ( OBJ_DATA *obj 			) );
void    notify          args( ( char * message, int lv 		) );
void    info            args( ( char * message, int lv 		) );
void    auction		args( ( char * message 			) );
void    log_chan	args( ( const char * message, int lv 	) );
bool    item_has_apply  args( ( CHAR_DATA *ch, int bit 		) );
CD   *  switch_char	args( ( CHAR_DATA *victim, int mvnum, int poly_level ) );
CD   *  unswitch_char   args( ( CHAR_DATA *ch 			) );
int	best_class	args( ( CHAR_DATA *ch, int sn 		) );
int	best_level	args( ( CHAR_DATA *ch, int sn 		) );
char *  center_text	args( ( char *text, int width		) );
void    monitor_chan	args( ( const char *message, int channel ) );
void set_stun           args( ( CHAR_DATA * victim, int stunTime ) );
CD   *  get_char        args( ( CHAR_DATA *ch ) );
void mark_from_room	args( ( int this_room_vnum, MARK_DATA * mark ) );
void mark_to_room	args( ( int this_room_vnum, MARK_DATA * mark ) );
void char_reference	args( (struct char_ref_type *ref) );
void char_unreference	args( (CHAR_DATA **var) );
void obj_reference	args( (struct obj_ref_type *ref) );
void obj_unreference	args( (OBJ_DATA **var) );



/* interp.c */
void    interpret       args( ( CHAR_DATA *ch, char *argument )   );
bool    is_number       args( ( char *arg )                       );
int     number_argument args( ( char *argument, char *arg )       );
char *  one_argument    args( ( char *argument, char *arg_first ) );
bool    IS_SWITCHED     args( ( CHAR_DATA *ch )                   );
bool    is_shielded     args( ( CHAR_DATA *ch, short shield_type ) );
void    remove_shield   args( ( CHAR_DATA *ch, MAGIC_SHIELD *shield ) );
bool    authorized      args( ( CHAR_DATA *ch, char *skllnm ) );
bool	check_social	args( ( CHAR_DATA *ch, char *command, char *argument ) );




/* macros.c */
short get_remort_level args ( ( CHAR_DATA *ch )   );
short get_psuedo_level args ( ( CHAR_DATA *ch )   ) ;
bool	ok_to_use	args( ( CHAR_DATA *ch, int value	) );
bool	check_level_use args( ( CHAR_DATA *ch, int level	) );
char *  learnt_name     args( ( int learnt 			) );
int	exp_to_level	args( ( CHAR_DATA *ch, int class, int index	) );
int	exp_for_mobile	args( ( int level, CHAR_DATA *mob		) );
int 	my_strlen	args( ( char *text			) );
int	skill_table_lookup args( ( CHAR_DATA *ch, int sn, int return_type ) );
bool	is_remort	args( ( CHAR_DATA *ch 			) );
int   exp_to_level_vamp args( ( int level             ) );
int exp_to_level_adept  args ( ( CHAR_DATA * ch ) );
char * get_adept_name     args( ( CHAR_DATA * ch ) );
void reset_gain_stats	args( ( CHAR_DATA * ch ) );
int   exp_to_level_wolf args( ( int level             ) );
int   get_item_value    args( ( OBJ_DATA * obj ) );
char *get_tribe_standing_name args( ( int standing	) );
char *get_moon_phase_name args( ( void	) );

/* magic.c */
int     mana_cost       args( ( CHAR_DATA * ch, int sn		) );
int     skill_lookup    args( ( const char *name 		) );
int     slot_lookup     args( ( int slot 			) );
bool    saves_spell     args( ( int level, CHAR_DATA *victim 	) );
void    obj_cast_spell  args( ( int sn, int level, CHAR_DATA *ch,
				    CHAR_DATA *victim, OBJ_DATA *obj ) );
bool spell_identify( int sn, int level, CHAR_DATA *ch, void *vo, OBJ_DATA *obj );


/* mob_prog.c */
void    mprog_wordlist_check    args( ( char * arg, CHAR_DATA *mob, CHAR_DATA* actor, OBJ_DATA* object, void* vo, int type ) );
void    mprog_percent_check     args( ( CHAR_DATA *mob, CHAR_DATA* actor, OBJ_DATA* object, void* vo, int type ) );
void    mprog_act_trigger       args( ( char* buf, CHAR_DATA* mob, CHAR_DATA* ch, OBJ_DATA* obj, void* vo ) );
void    mprog_bribe_trigger     args( ( CHAR_DATA* mob, CHAR_DATA* ch, int amount ) );
void    mprog_entry_trigger     args( ( CHAR_DATA* mob ) );
void    mprog_give_trigger      args( ( CHAR_DATA* mob, CHAR_DATA* ch, OBJ_DATA* obj ) );
void    mprog_greet_trigger     args( ( CHAR_DATA* mob ) );
void    mprog_fight_trigger     args( ( CHAR_DATA* mob, CHAR_DATA* ch ) );
void    mprog_hitprcnt_trigger  args( ( CHAR_DATA* mob, CHAR_DATA* ch ) );
void    mprog_death_trigger     args( ( CHAR_DATA* mob ) );
void    mprog_random_trigger    args( ( CHAR_DATA* mob ) );
void    mprog_speech_trigger    args( ( char* txt, CHAR_DATA* mob ) );

			  /*-------*\
			  ) quest.c (
			  \*-------*/

void 	quest_inform		args( ( void ) );
void	quest_complete		args( ( CHAR_DATA *ch ) );
void    quest_cancel		args( ( void ) );
void  generate_auto_quest	args( ( void ) );


			   /*------*\
			   ) save.c (
			   \*------*/
void    save_char_obj   args( ( CHAR_DATA *ch ) );
bool    load_char_obj   args( ( DESCRIPTOR_DATA *d, char *name ) );
void	save_corpses	args( ( void ) );
void    fread_corpse	args( ( FILE * fp ) );
void	save_marks	args( ( void ) );
void	save_bans	args( ( void ) );
char	*initial	args( ( const char *str ) );


			 /*---------*\
			 ) special.c (
			 \*---------*/
SF    * spec_lookup          args( ( const char *name ) );
char  * rev_spec_lookup      args( ( void * func      ) );
void    print_spec_lookup    args( ( char * buf       ) );

/* social-edit.c  */

void load_social_table	args(  ( void )  );


 			 /*---------*\
			 ) obj_fun.c (
			 \*---------*/
OF    * obj_fun_lookup	     args( ( const char *name ) );
char  * rev_obj_fun_lookup    args( ( void *func       ) );
void    print_obj_fun_lookup  args( ( char *buf 	      ) );


			/*---------*\
			) trigger.c (
			\*---------*/
			
void	trigger_handler	args( ( CHAR_DATA *ch, OBJ_DATA *obj, int trigger ) );
			
			
			 /*--------*\
			 ) update.c# (
			 \*--------*/
void    advance_level   args( ( CHAR_DATA *ch, int class, bool show, bool remort ) );
void    gain_exp        args( ( CHAR_DATA *ch, int gain )             );
void    gain_bloodlust  args( ( CHAR_DATA *ch, int value )	      );
void    gain_condition  args( ( CHAR_DATA *ch, int iCond, int value ) );
void    update_handler  args( ( void )                                );
bool    check_rewield   args( ( CHAR_DATA *ch ) 		      );
bool    check_re_equip  args( ( CHAR_DATA *ch )                       );
void	auction_update  args( ( void )                                );
void	check_vamp	args( ( CHAR_DATA *ch )			      );

/* write.c */
void    write_start     args( ( char * * dest, void * retfunc, void * retparm, CHAR_DATA * ch ) );
void    write_interpret args( ( CHAR_DATA * ch, char * argument ) );

/* build.c */
void  build_strdup(char * * dest,char * src,bool freesrc,CHAR_DATA * ch);
char * build_simpstrdup( char * buf);  /* A plug in alternative to str_dup */
void build_save args( ( void ) );
extern const char * cDirs;
int  get_dir(char);
char * show_values( const struct lookup_type * table, int value, bool fBit );

/* buildtab.c  */
/*
int table_lookup	args( (const struct lookup_type * table,char * name) );
char * rev_table_lookup	args( (const struct lookup_type * table,int number) );
char * bit_table_lookup	args( (const struct lookup_type * table,int number) );
*/

/* buildare.c */
/* Area manipulation funcs in buildare.c */
int build_canread(AREA_DATA * Area,CHAR_DATA * ch,int showerror);
int build_canwrite(AREA_DATA * Area,CHAR_DATA * ch,int showerror);
#define AREA_NOERROR   0
#define AREA_SHOWERROR 1

/* areasave.c */
void area_modified(AREA_DATA *);
void build_save_flush(void);

/* hunt.c */
void    hunt_victim     args( ( CHAR_DATA *ch ) );
void    unhunt          args( ( CHAR_DATA *ch ) );
int     make_hunt       args( ( CHAR_DATA *ch, CHAR_DATA * victim) );
/* void	hunt_move	args( ( CHAR_DATA *ch ) ); */
void	hunt_obj	args( ( CHAR_DATA *ch ) );
bool    make_move	args( ( CHAR_DATA *ch, int vnum ) );
char *  find_path	args( ( int, int, CHAR_DATA *, int, int, int ) );

bool	mob_hunt	args( ( CHAR_DATA *mob ) );
void	char_hunt	args( ( CHAR_DATA *ch  ) );
 bool	set_hunt	args( ( CHAR_DATA *ch, CHAR_DATA *fch,
				CHAR_DATA *vch, OBJ_DATA *vobj,
				int set_flags, int rem_flags ) );  
void	end_hunt	args( ( CHAR_DATA *ch ) );  
short h_find_dir       args( ( ROOM_INDEX_DATA *room, ROOM_INDEX_DATA *target,
                   int h_flags ) );

  /* update.c */

void init_alarm_handler args(  ( void ) );
void alarm_update args( ( void ) );
/*    SSM   */
void temp_fread_string	args( (FILE * fp, char *buf) );


/*
 *      Rulers
 *
 */

void save_rulers	args( ( void ) );
void load_rulers	args( ( void ) );
char *get_ruler_title	args( ( int ruler_rank, int sex ) );

/*
 *	spendqp
 */
void save_brands	args( ( void ) );

#undef  CD
#undef  MID
#undef  OD
#undef  OID
#undef  RID
#undef  SF
#undef  OF
