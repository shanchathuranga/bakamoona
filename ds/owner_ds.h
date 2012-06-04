#ifndef _OWNER_DS_H_
#define _OWNER_DS_H_

typedef struct owner
{
	int owner_id;
	char owner_name[128];
	char company[64];
	int error;
} OWNER;

typedef struct ownerl_ist
{
	OWNER * owner;
	struct owner_list * next;
} OWNERLIST;

typedef OWNERLIST OWNERNODE;

OWNERLIST * make_owner_list ();
void add_owner_to_list (OWNERLIST * list, OWNER * owner);
OWNERLIST * delete_owner_list (OWNERLIST * list);
static void recursive_delete (OWNERLIST * list);
void delete_owner (OWNER * bus);
void debug_owner_list (OWNERLIST * list);

#endif
