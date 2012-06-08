#ifndef _OWNER_H_
#define _OWNER_H_

#include "owner_ds.h"

// select
OWNER * get_owner_by_id (int owner_id);
OWNER * get_owner_by_reg_no (char * owner_reg_no);
OWNERLIST * get_owner_by_owner_name (char * owner_name);

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
