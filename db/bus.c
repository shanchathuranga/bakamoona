#include <my_global.h>
#include <mysql.h>
#include "bus.h"
#include <stdio.h>
#include <string.h>

BUS * get_bus_by_id (int bus_id)
{
	MYSQL * conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	MYSQL_FIELD	* column;
	BUS * bus = NULL;
	char query[512];

	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	printf ("conneced .... \n");

	sprintf (query, "SELECT * FROM Bus WHERE bus_id = %d", bus_id);

	mysql_query (conn, query);
	result = mysql_store_result (conn);

	if (mysql_num_rows (result) != 1)
	{
		printf ("row count should be ONE");
		return NULL;
	}

	bus = malloc ( sizeof (BUS) );

	int num_columns = mysql_num_fields(result);
	int i;

	while((row = mysql_fetch_row(result))) 
	{
		unsigned long * lengths = mysql_fetch_lengths(result);

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
				sprintf (bus->bus_reg_no, "%s", row[i]);
			}
			else if (strcmp (column->name, "bus_model") == 0)
			{
				sprintf (bus->bus_model, "%s", row[i]);
			}
			else if (strcmp (column->name, "ts") == 0)
			{
				// We may need timestamp someday....
			}
		}
	}
	
	mysql_free_result (result);
	mysql_close (conn);

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
