#ifndef _BUS_H_
#define _BUS_H_

#include "bus_ds.h"

BUS * get_bus_by_id (int bus_id);
BUS * get_bus_by_reg_no (char * bus_reg_no);
BUSLIST * get_bus_by_owner_id (int owner_id);
BUSLIST * get_bus_by_model (char * bus_model);

#endif
