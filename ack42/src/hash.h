

typedef struct hash_entry_tp  hash_entry;
struct hash_entry_tp {
	bool		is_free; /* Ramias:for run-time checks of LINK/UNLINK */
	hash_entry *	next;
	void       *	reference;
	int		key;
	};

typedef struct hash_table_tp  hash_table;

struct hash_table_tp {
                       int           max_hash;
                       hash_entry ** table;
                     };



hash_table * create_hash_table(int max_hash);
void del_hash_entry(hash_table * hash_head,int key);
void add_hash_entry(hash_table * hash_head,int key,void * entry);
void * get_hash_entry(hash_table * hash_head,int key);
void clear_hash_table(hash_table * hash_head);
void delete_hash_table(hash_table * hash_head);
