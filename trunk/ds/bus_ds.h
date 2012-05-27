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

typedef struct buslist
{

} BUSLIST;

#endif
