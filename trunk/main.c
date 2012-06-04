#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bus.h"
#include "mainwin.h"

int main(int argc, char *argv[])
{
	printf ("starting ........ \n");
	
	gtk_init (&argc, &argv);
	open_mainwindow ();
	gtk_main ();

	init_db ();

	BUS * bus = get_bus_by_id (3);

	printf ("bus_id = %d\n", bus->bus_id);
	printf ("owner_id = %d\n", bus->owner_id);
	printf ("bus_reg_no = %s\n", bus->bus_reg_no);
	printf ("bus_model = %s\n", bus->bus_model);
	printf ("ts ??? \n");

	remove_bus (bus);

	BUSLIST * list = get_bus_by_owner_id (23201);
	debug_bus_list (list);

	BUS * b1 = malloc (sizeof(BUS));
	b1->owner_id = 38332;
	strcpy (b1->bus_reg_no, "62-5933");
	strcpy (b1->bus_model, "MITSUBISHI");

	//insert_bus (b1);
	BUS * b2 = get_bus_by_id (3);
	strcpy (b2->bus_model, "micro-SS9");

	update_bus (b2); 

	remove_bus (b1);

	delete_bus_by_id (16);

	return 0;
}
