#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bus.h"
#include "owner.h"
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

	OWNER * owner = get_owner_by_id (1);

	if (!owner)
		printf ("owner null\n");
	
	printf ("owner_id = %d\n", owner->owner_id);
	printf ("owner_reg_no = %s\n", owner->owner_reg_no);
	printf ("owner_name = %s\n", owner->owner_name);
	printf ("phone1 = %s\n", owner->phone1);
	printf ("phone2 = %s\n", owner->phone2);
	printf ("address1 = %s\n", owner->address1);
	printf ("city1 = %s\n", owner->city1);
	printf ("address2 = %s\n", owner->address2);
	printf ("city2 = %s\n", owner->city2);
	printf ("email = %s\n", owner->email);

	OWNER * ow = malloc (sizeof(OWNER));

	strcpy (ow->owner_name, "Kamal");
	strcpy (ow->owner_reg_no, "RH-89-0003-332");
	strcpy (ow->phone1, "0772922992");
	strcpy (ow->phone2, "");
	strcpy (ow->address1, "3/1, sarana mawatha, didheniya");
	strcpy (ow->city1, "Nugegoda");
	strcpy (ow->address2, "");
	strcpy (ow->city2, "");
	strcpy (ow->email, "slls@fix.com");

	insert_owner (ow);

	return 0;
}
