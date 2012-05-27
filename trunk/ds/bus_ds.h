#ifndef _BUS_DS_H_
#define _BUS_DS_H_

typedef struct bus
{
	int bus_id;
	int owner_id;
	char bus_reg_no[8];
	char bus_model[64];
	int error;
} BUS;

typedef struct bus_list
{
	BUS * bus;
	struct bus_list * next;
} BUSLIST;

typedef BUSLIST BUSNODE;

BUSLIST * make_bus_list();
void add_bus_to_list (BUSLIST * list, BUS * bus);
BUSLIST * delete_bus_list (BUSLIST * list);
static void recursive_delete (BUSLIST * list);
void debug_bus_list (BUSLIST * list);

#endif
