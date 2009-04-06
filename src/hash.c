#if defined(macintosh)
#include <types.h>
#else
#include <sys/types.h>
#endif
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "merc.h"
#include "hash.h"


/*
 * Deals with generic hashing tables.
 */
hash_entry *hash_free = NULL;


void * get_hash_entry(hash_table * hash_head,int key)
{
 int a;
 hash_entry * rvalue;
 hash_entry ** hash_table;
 
 a=key % hash_head->max_hash;
 hash_table=hash_head->table;
 
 
 for (rvalue=hash_table[a]; rvalue != NULL; rvalue=rvalue->next)
  if (rvalue->key == key)
   break;
   
 if ( rvalue != NULL)
  return rvalue->reference;
 else 
  return NULL;
}
 
void add_hash_entry(hash_table * hash_head,int key,void * entry)
{
 int a;
 hash_entry * temp;
 hash_entry ** hash_table;

 a=key % hash_head->max_hash;
 hash_table=hash_head->table;

 GET_FREE(temp, hash_free);
 temp->key=key;
 temp->reference=entry;
 temp->next=hash_table[a];
 
 hash_table[a]=temp;
}

void del_hash_entry(hash_table * hash_head,int key)
{
 int a;
 hash_entry * prev_entry;
 hash_entry * search_entry;
 hash_entry ** hash_table;

 a=key % hash_head->max_hash;
 hash_table=hash_head->table;
 
 prev_entry=NULL;
 for (search_entry=hash_table[a]; search_entry != NULL; search_entry = search_entry->next)
 {
  if (search_entry->key==key)
   break;
  prev_entry=search_entry;
 }

 if (search_entry != NULL)
 {
  if (prev_entry == NULL)
   hash_table[a]=NULL;
  else
   prev_entry->next=search_entry->next;
  PUT_FREE(search_entry, hash_free);
 }
}

hash_table * create_hash_table(int max_hash)
{
 int a;
 hash_table * hash_head;
 hash_entry ** hash_table;

 hash_table=getmem(sizeof(hash_entry *)*max_hash);
 hash_head=getmem(sizeof(struct hash_table_tp));

 hash_head->max_hash=max_hash;
 hash_head->table=hash_table;

 for (a=0; a < max_hash; a++)
  hash_table[a]=NULL;
  
 return hash_head;
  
} 
   
void clear_hash_table(hash_table * hash_head)
{
 int a;
 hash_entry * entry, * next_entry;
 hash_entry ** hash_table;
 
 hash_table=hash_head->table;
 
 for (a=0; a < hash_head->max_hash; a++)
 {
  if (hash_table[a] != NULL)
  {
   for (entry=hash_table[a]; entry != NULL; entry=next_entry)
   {
    next_entry=entry->next;
    PUT_FREE(entry, hash_free);
   }
   hash_table[a]=NULL;
  }
 }
} 

void delete_hash_table(hash_table * hash_head)
{

 int a;
 hash_entry * entry, * next_entry;
 hash_entry ** hash_table;
 hash_table=hash_head->table;
 
 for (a=0; a < hash_head->max_hash; a++)
 {
  if (hash_table[a] != NULL)
  {
   for (entry=hash_table[a]; entry != NULL; entry=next_entry)
   {
    next_entry=entry->next;
    PUT_FREE(entry, hash_free);
   }
   hash_table[a]=NULL;
  }
 }
 dispose(hash_table, sizeof(hash_entry *) * hash_head->max_hash);
 dispose(hash_head, sizeof(*hash_head));
}
