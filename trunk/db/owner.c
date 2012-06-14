#include <my_global.h>
#include <mysql.h>
#include "owner.h"
#include <stdio.h>
#include <string.h>

OWNER * get_owner_by_id (int owner_id)
{
	MYSQL * conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	MYSQL_FIELD	* column;
	OWNER * owner = NULL;
	char query[512];

	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	sprintf (query, "SELECT * FROM Owner WHERE owner_id = %d", owner_id);

	mysql_query (conn, query);
	result = mysql_store_result (conn);

	if (mysql_num_rows (result) != 1)
	{
		printf ("row count should be ONE\n");
		return NULL;
	}

	owner = malloc ( sizeof (OWNER) );

	int num_columns = mysql_num_fields(result);
	int i;

	while((row = mysql_fetch_row(result))) 
	{
		unsigned long * lengths = mysql_fetch_lengths(result);

		for(i = 0; i < num_columns; i++)
		{
			column = mysql_fetch_field_direct(result, i);
			if (strcmp (column->name, "owner_id") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				owner->owner_id = atoi(buf);
			}
			else if (strcmp (column->name, "owner_name") == 0)
			{
				char buf[128];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->owner_name, buf);
			}
			else if (strcmp (column->name, "owner_reg_no") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->owner_reg_no, buf);
			}
			else if (strcmp (column->name, "phone1") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->phone1, buf);
			}
			else if (strcmp (column->name, "phone2") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->phone2, buf);
			}
			else if (strcmp (column->name, "address1") == 0)
			{
				char buf[255];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->address1, buf);
			}
			else if (strcmp (column->name, "city1") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->city1, buf);
			}
			else if (strcmp (column->name, "address2") == 0)
			{
				char buf[255];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->address2, buf);
			}
			else if (strcmp (column->name, "city2") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->city2, buf);
			}
			else if (strcmp (column->name, "email") == 0)
			{
				char buf[128];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->email, buf);
			}
			else if (strcmp (column->name, "ts") == 0)
			{
				// We may need timestamp someday....
			}
		}
	}

	mysql_free_result (result);
	mysql_close (conn);

	return owner;
}

OWNER * get_owner_by_reg_no (char * owner_reg_no)
{
	MYSQL * conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	MYSQL_FIELD	* column;
	OWNER * owner = NULL;
	char query[512];

	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	sprintf (query, "SELECT * FROM Owner WHERE owner_reg_no = %s", owner_reg_no);

	mysql_query (conn, query);
	result = mysql_store_result (conn);

	if (mysql_num_rows (result) != 1)
	{
		printf ("row count should be ONE\n");
		return NULL;
	}

	owner = malloc ( sizeof (OWNER) );

	int num_columns = mysql_num_fields(result);
	int i;

	while((row = mysql_fetch_row(result))) 
	{
		unsigned long * lengths = mysql_fetch_lengths(result);

		for(i = 0; i < num_columns; i++)
		{
			column = mysql_fetch_field_direct(result, i);
			if (strcmp (column->name, "owner_id") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				owner->owner_id = atoi(buf);
			}
			else if (strcmp (column->name, "owner_name") == 0)
			{
				char buf[128];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->owner_name, buf);
			}
			else if (strcmp (column->name, "owner_reg_no") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->owner_reg_no, buf);
			}
			else if (strcmp (column->name, "phone1") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->phone1, buf);
			}
			else if (strcmp (column->name, "phone2") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->phone2, buf);
			}
			else if (strcmp (column->name, "address1") == 0)
			{
				char buf[255];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->address1, buf);
			}
			else if (strcmp (column->name, "city1") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->city1, buf);
			}
			else if (strcmp (column->name, "address2") == 0)
			{
				char buf[255];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->address2, buf);
			}
			else if (strcmp (column->name, "city2") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->city2, buf);
			}
			else if (strcmp (column->name, "email") == 0)
			{
				char buf[128];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->email, buf);
			}
			else if (strcmp (column->name, "ts") == 0)
			{
				// We may need timestamp someday....
			}
		}
	}

	mysql_free_result (result);
	mysql_close (conn);

	return owner;
}

GSList * get_owner_by_owner_name (char * owner_name)
{
	return NULL;
}

GSList * get_all_owners ()
{
	MYSQL * conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	MYSQL_FIELD	* column;
	GSList * owner_list = NULL;
	char query[512];

	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	sprintf (query, "SELECT * FROM Owner");

	mysql_query (conn, query);
	result = mysql_store_result (conn);

	int all = mysql_num_rows (result);

	printf ("row count = %d\n", all);

	int num_columns = mysql_num_fields(result);
	int i;

	while((row = mysql_fetch_row(result))) 
	{
		OWNER * owner = malloc (sizeof (OWNER));
		unsigned long * lengths = mysql_fetch_lengths(result);

		for(i = 0; i < num_columns; i++)
		{
			column = mysql_fetch_field_direct(result, i);
			if (strcmp (column->name, "owner_id") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				owner->owner_id = atoi(buf);
			}
			else if (strcmp (column->name, "owner_name") == 0)
			{
				char buf[128];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->owner_name, buf);
			}
			else if (strcmp (column->name, "owner_reg_no") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->owner_reg_no, buf);
			}
			else if (strcmp (column->name, "phone1") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->phone1, buf);
			}
			else if (strcmp (column->name, "phone2") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->phone2, buf);
			}
			else if (strcmp (column->name, "address1") == 0)
			{
				char buf[255];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->address1, buf);
			}
			else if (strcmp (column->name, "city1") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->city1, buf);
			}
			else if (strcmp (column->name, "address2") == 0)
			{
				char buf[255];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->address2, buf);
			}
			else if (strcmp (column->name, "city2") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->city2, buf);
			}
			else if (strcmp (column->name, "email") == 0)
			{
				char buf[128];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (owner->email, buf);
			}
			else if (strcmp (column->name, "ts") == 0)
			{
				// We may need timestamp someday....
			}
		}
		owner_list = g_slist_append(owner_list, owner);
	}
	mysql_free_result (result);
	mysql_close (conn);

	return owner_list;
}

void insert_owner (OWNER * owner)
{
	if (!owner)
		return;

	MYSQL * conn;
	char query[1024];

	sprintf (query, "INSERT INTO Owner (owner_name, owner_reg_no, phone1, phone2, address1, \
		city1, address2, city2, email) VALUES (\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\")", 
			owner->owner_name, 
			owner->owner_reg_no,
			owner->phone1, 
			owner->phone2, 
			owner->address1,
			owner->city1, 
			owner->address2, 
			owner->city2, 
			owner->email
			);

	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);
	mysql_query (conn, query);
	mysql_close (conn);
}

/*
// update
void update_owner (OWNER * owner);
void change_owner_reg_no (int owner_id, char * owner_reg_no);
void change_owner_owner_name (int owner_id, char * owner_name);
void change_owner_phone (int owner_id, char * owner_phone);

// delete
void delete_owner (OWNER * owner);
void delete_owner_by_id (int owner_id);
 */


