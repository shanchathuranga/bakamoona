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
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				bus->bus_id = atoi(buf);
			}
			else if (strcmp (column->name, "owner_id") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				bus->owner_id = atoi(buf);
			}
			else if (strcmp (column->name, "bus_reg_no") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (bus->bus_reg_no, buf);
			}
			else if (strcmp (column->name, "bus_model") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (bus->bus_model, buf);
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
	MYSQL * conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	MYSQL_FIELD	* column;
	BUS * bus = NULL;
	char query[512];

	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	sprintf (query, "SELECT * FROM Bus WHERE bus_reg_no = %s", bus_reg_no);

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
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				bus->bus_id = atoi(buf);
			}
			else if (strcmp (column->name, "owner_id") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				bus->owner_id = atoi(buf);
			}
			else if (strcmp (column->name, "bus_reg_no") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (bus->bus_reg_no, buf);
			}
			else if (strcmp (column->name, "bus_model") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (bus->bus_model, buf);
			}
			else if (strcmp (column->name, "ts") == 0)
			{
				// We may need timestamp someday ...
			}
		}
	}
	
	mysql_free_result (result);
	mysql_close (conn);

	return bus;
}

BUSLIST * get_bus_by_owner_id (int owner_id)
{
	MYSQL * conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	MYSQL_FIELD	* column;
	BUSLIST * bus_list = NULL;
	char query[512];

	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	sprintf (query, "SELECT * FROM Bus WHERE owner_id = %d", owner_id);

	mysql_query (conn, query);
	result = mysql_store_result (conn);

	bus_list = make_bus_list ();
	
	int num_columns = mysql_num_fields(result);
	int i;

	while((row = mysql_fetch_row(result))) 
	{
		BUS * bus = malloc (sizeof (BUS));
		unsigned long * lengths = mysql_fetch_lengths(result);
	
		for(i = 0; i < num_columns; i++)
		{
			column = mysql_fetch_field_direct(result, i);
			if (strcmp (column->name, "bus_id") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				bus->bus_id = atoi(buf);
			}
			else if (strcmp (column->name, "owner_id") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				bus->owner_id = atoi(buf);
			}
			else if (strcmp (column->name, "bus_reg_no") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (bus->bus_reg_no, buf);
			}
			else if (strcmp (column->name, "bus_model") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (bus->bus_model, buf);
			}
			else if (strcmp (column->name, "ts") == 0)
			{			
				// We may need timestamp someday....
			}
		}
		add_bus_to_list (bus_list, bus);
	}
	mysql_free_result (result);
	mysql_close (conn);

	return bus_list;
}

BUSLIST * get_bus_by_model (char * bus_model)
{
	MYSQL * conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	MYSQL_FIELD	* column;
	BUSLIST * bus_list = NULL;
	char query[512];

	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	sprintf (query, "SELECT * FROM Bus WHERE bus_model = %s", bus_model);

	mysql_query (conn, query);
	result = mysql_store_result (conn);

	bus_list = make_bus_list ();
	
	int num_columns = mysql_num_fields(result);
	int i;

	while((row = mysql_fetch_row(result))) 
	{
		BUS * bus = malloc (sizeof (BUS));
		unsigned long * lengths = mysql_fetch_lengths(result);

		for(i = 0; i < num_columns; i++)
		{
			column = mysql_fetch_field_direct(result, i);
			if (strcmp (column->name, "bus_id") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				bus->bus_id = atoi(buf);
			}
			else if (strcmp (column->name, "owner_id") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				bus->owner_id = atoi(buf);
			}
			else if (strcmp (column->name, "bus_reg_no") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (bus->bus_reg_no, buf);
			}
			else if (strcmp (column->name, "bus_model") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (bus->bus_model, buf);
			}
			else if (strcmp (column->name, "ts") == 0)
			{		
				// We may need timestamp someday....
			}
		}
		add_bus_to_list (bus_list, bus);
	}
	mysql_free_result (result);
	mysql_close (conn);

	return bus_list;
}

void insert_bus (BUS * bus)
{
	if (!bus)
		return;

	MYSQL * conn;
	char query[1024];

	int owner_id = bus->owner_id;
	char bus_reg_no[20];
	if (bus->bus_reg_no)
		strcpy (bus_reg_no, bus->bus_reg_no);
	else
		strcpy (bus_reg_no, "NULL");

	char bus_model[64];
	if (bus->bus_model)
		strcpy (bus_model, bus->bus_model);
	else
		strcpy (bus_model, "NULL");

	sprintf (query, "INSERT INTO Bus (owner_id, bus_reg_no, bus_model) VALUES (%d, \"%s\", \"%s\")", owner_id, bus_reg_no, bus_model);

	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	mysql_query (conn, query);
	mysql_close (conn);
}

void update_bus (BUS * bus)
{
	if (!bus)
		return;

	char query[1024];

	int owner_id = bus->owner_id;
	char bus_reg_no[20];
	if (bus->bus_reg_no)
		strcpy (bus_reg_no, bus->bus_reg_no);
	else
		strcpy (bus_reg_no, "NULL");

	char bus_model[64];
	if (bus->bus_model)
		strcpy (bus_model, bus->bus_model);
	else
		strcpy (bus_model, "NULL");

	change_bus_reg_no (bus->bus_id, bus_reg_no);
	change_bus_owner_id (bus->bus_id, owner_id);
	change_bus_model (bus->bus_id, bus_model);
}

void change_bus_reg_no (int bus_id, char * bus_reg_no)
{
	MYSQL * conn;
	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	char query[512];
	sprintf (query, "UPDATE Bus SET bus_reg_no=\"%s\" WHERE bus_id=%d", bus_reg_no, bus_id);

	mysql_query (conn, query);
	mysql_close (conn);	
}

void change_bus_owner_id (int bus_id, int owner_id)
{
	MYSQL * conn;
	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	char query[512];
	sprintf (query, "UPDATE Bus SET owner_id=%d WHERE bus_id=%d", owner_id, bus_id);

	mysql_query (conn, query);
	mysql_close (conn);
}

void change_bus_model (int bus_id, char * bus_model)
{
	MYSQL * conn;
	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	char query[512];
	sprintf (query, "UPDATE Bus SET bus_model=\"%s\" WHERE bus_id=%d", bus_model, bus_id);

	mysql_query (conn, query);
	mysql_close (conn);
}

void delete_bus (BUS * bus)
{
	if (!bus)
		return;

	delete_bus_by_id (bus->bus_id);
}

void delete_bus_by_id (int bus_id)
{
	MYSQL * conn;
	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	char query[512];
	sprintf (query, "DELETE FROM Bus WHERE bus_id=%d", bus_id);

	mysql_query (conn, query);
	mysql_close (conn);
}

