#ifndef _OWNER_H_
#define _OWNER_H_

#include <glib.h>

typedef struct owner
{
	int owner_id;
	char owner_name[128]; 
	char owner_reg_no[64]; 
	char phone1[32];
	char phone2[32]; 
	char address1[255];
	char city1[64];
	char address2[255];
	char city2[64]; 
	char email[128];
	int error;
} OWNER;

// select
OWNER * get_owner_by_id (int owner_id);
OWNER * get_owner_by_reg_no (char * owner_reg_no);
GSList * get_owner_by_owner_name (char * owner_name);
GSList * get_all_owners ();

// insert
void insert_owner (OWNER * owner);

// update
void update_owner (OWNER * owner);
void change_owner_reg_no (int owner_id, char * owner_reg_no);
void change_owner_owner_name (int owner_id, char * owner_name);
void change_owner_phone (int owner_id, char * owner_phone);

// delete
void delete_owner (OWNER * owner);
void delete_owner_by_id (int owner_id);

#endif
