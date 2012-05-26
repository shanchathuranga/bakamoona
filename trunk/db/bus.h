#ifndef _BUS_H_
#define _BUS_H_

typedef struct bus
{
	int bus_id;
	int owner_id;
	char bus_reg_no[8];
	char bus_model[64];
	int error;
} BUS;

typedef struct buslist
{

} BUSLIST;

BUS * get_bus_by_id (int bus_id);
BUS * get_bus_by_reg_no (char * bus_reg_no);
BUSLIST * get_bus_by_owner_id (int owner_id);
BUSLIST * get_bus_by_model (char * bus_model);

#endif
