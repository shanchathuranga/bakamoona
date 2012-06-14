#ifndef _BUS_H_
#define _BUS_H_

#include <glib.h>

typedef struct bus
{
	int bus_id;
	int owner_id;
	char bus_reg_no[20];
	char bus_eng_no[64];
	char bus_chs_no[64];
	char bus_model[64];
	char bus_desc[255];
	int deleted;
	int error;
} BUS;

// select
BUS * get_bus_by_id (int bus_id);
BUS * get_bus_by_reg_no (char * bus_reg_no);
GSList * get_bus_by_owner_id (int owner_id);
GSList * get_bus_by_model (char * bus_model);
GSList * get_all_buses ();

// insert
void insert_bus (BUS * bus);

// update
void update_bus (BUS * bus);
void change_bus_reg_no (int bus_id, char * bus_reg_no);
void change_bus_owner_id (int bus_id, int owner_id);
void change_bus_model (int bus_id, char * bus_model);

// delete
void delete_bus (BUS * bus);
void delete_bus_by_id (int bus_id);

#endif
