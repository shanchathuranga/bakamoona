#include <stdio.h>
#include <string.h>
#include "bus.h"

int main()
{
	printf ("starting ........ \n");
	BUS * bus = get_bus_by_id (3);	

	printf ("bus_id = %d\n", bus->bus_id);
	printf ("owner_id = %d\n", bus->owner_id);
	printf ("bus_reg_no = %s\n", bus->bus_reg_no);
	printf ("bus_model = %s\n", bus->bus_model);
	printf ("ts ??? \n");	

	delete_bus (bus);

	return 0;
}
