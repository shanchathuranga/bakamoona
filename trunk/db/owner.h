#ifndef _BUS_H_
#define _BUS_H_

typedef struct owner
{
	int owner_id;
	char owner_name[128];
	char company[64];
	int error;
} OWNER;

typedef struct ownerlist
{

} OWNERLIST;

OWNER * get_owner_by_id (int bus_id);
OWNERLIST * get_owner_by_name (char * owner_name);
OWNERLIST * get_owner_by_company (char * company);

#endif
