#include "db_man.h"
#include "bus.h"
#include <stdio.h>

int main()
{
	bakamoona_wakeup ("localhost", "root", "root");

	printf("DEBUG : bakamoona ok\n");

	bakamoona_init_db ();

	printf("DEBUG : bakamoona init ok\n");

	bakamoona_sleep();

	BUS * bus = get_bus_by_id (3);

	printf ("bus id = %d\n", bus->bus_id);
	printf ("bus id = %d\n", bus->owner_id);

	return 0;
}

