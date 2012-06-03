#ifndef _BUS_H_
#define _BUS_H_

#include "bus_ds.h"

// select
BUS * get_bus_by_id (int bus_id);
BUS * get_bus_by_reg_no (char * bus_reg_no);
BUSLIST * get_bus_by_owner_id (int owner_id);
BUSLIST * get_bus_by_model (char * bus_model);

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
