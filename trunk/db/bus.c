#include "bus.h"
#include "db_man.h"
#include <stdio.h>
#include <string.h>

BUS * get_bus_by_id (int bus_id)
{
	bakamoona_wakeup ( "localhost", "root", "root");

	char query[512];
	MYSQL_RES * result;
	MYSQL_ROW row;
	MYSQL_FIELD * column;
	int num_columns;
	unsigned long * lengths;
	int i;
	BUS * bus = NULL;

	sprintf (query, "SELECT * FROM Bus WHERE bus_id = %d", bus_id);

	mysql_query(conn, query);

	result = mysql_store_result(conn);

	if (mysql_num_rows(result) != 1)
	{
		printf ("row count should be 1");
		return NULL;
	}

	bus = malloc ( sizeof (BUS) );

	num_columns = mysql_num_fields(result);
	lengths = mysql_fetch_lengths(result);

	while((row = mysql_fetch_row(result))) 
	{
		for(i = 0; i < num_columns; i++)
		{
			column = mysql_fetch_field_direct(result, i);
			if (strcmp (column->name, "bus_id") == 0)
			{
				bus->bus_id = atoi(row[i]);
			}
			else if (strcmp (column->name, "owner_id") == 0)
			{
				bus->owner_id = atoi(row[i]);
			}
			else if (strcmp (column->name, "bus_reg_no") == 0)
			{
				char buf [256];
				//strncpy (buf, row[i], lengths[i]);
			}
			else if (strcmp (column->name, "bus_model") == 0)
			{
				char buf [256];
				//strncpy (buf, row[i], lengths[i]);
			}
			else if (strcmp (column->name, "ts") == 0)
			{	char buf [256];
				//s/trncpy (buf, row[i], lengths[i]);
			}
		}
	}

	bakamoona_sleep ();

	return bus;
}

BUS * get_bus_by_reg_no (char * bus_reg_no)
{

}

BUSLIST * get_bus_by_owner_id (int owner_id)
{

}

BUSLIST * get_bus_by_model (char * bus_model)
{

}
