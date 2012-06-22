#include <my_global.h>
#include <mysql.h>
#include "sparepart.h"
#include <stdio.h>
#include <string.h>

SPAREPART * get_sparepart_by_id (int sp_id)
{
	MYSQL * conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	MYSQL_FIELD	* column;
	SPAREPART * sp = NULL;
	char query[512];

	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	sprintf (query, "SELECT * FROM SparePart WHERE sp_id = %d", sp_id);

	mysql_query (conn, query);
	result = mysql_store_result (conn);

	if (mysql_num_rows (result) != 1)
	{
		printf ("row count should be ONE\n");
		return NULL;
	}

	sp = malloc ( sizeof (SPAREPART) );

	int num_columns = mysql_num_fields(result);
	int i;

	while((row = mysql_fetch_row(result))) 
	{
		unsigned long * lengths = mysql_fetch_lengths(result);

		for(i = 0; i < num_columns; i++)
		{
			column = mysql_fetch_field_direct(result, i);
			if (strcmp (column->name, "sp_id") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				sp->sp_id = atoi(buf);
			}
			else if (strcmp (column->name, "sp_code") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (sp->sp_code, buf);
			}
			else if (strcmp (column->name, "sp_name") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (sp->sp_name, buf);
			}
			if (strcmp (column->name, "unit_cost") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				sp->unit_cost = atof(buf);
			}
			if (strcmp (column->name, "min_cost") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				sp->sp_id = atof(buf);
			}
			if (strcmp (column->name, "max_cost") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				sp->sp_id = atof(buf);
			}
			else if (strcmp (column->name, "sp_desc") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (sp->sp_desc, buf);
			}
			else if (strcmp (column->name, "ts") == 0)
			{
				// We may need timestamp someday....
			}
		}
	}

	mysql_free_result (result);
	mysql_close (conn);

	return sp;
}

SPAREPART * get_sparepart_by_code (char * sp_code)
{

}

GSList * get_all_spareparts ()
{
	MYSQL * conn;
	MYSQL_RES * result;
	MYSQL_ROW row;
	MYSQL_FIELD	* column;
	GSList * sp_list = NULL;
	char query[512];

	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);

	sprintf (query, "SELECT * FROM SparePart");

	mysql_query (conn, query);
	result = mysql_store_result (conn);

	int all = mysql_num_rows (result);

	printf ("row count = %d\n", all);

	int num_columns = mysql_num_fields(result);
	int i;

	while((row = mysql_fetch_row(result))) 
	{
		SPAREPART * sp = malloc (sizeof (SPAREPART));
		unsigned long * lengths = mysql_fetch_lengths(result);

		for(i = 0; i < num_columns; i++)
		{
			column = mysql_fetch_field_direct(result, i);
			if (strcmp (column->name, "sp_id") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				sp->sp_id = atoi(buf);
			}
			else if (strcmp (column->name, "sp_code") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (sp->sp_code, buf);
			}
			else if (strcmp (column->name, "sp_name") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (sp->sp_name, buf);
			}
			if (strcmp (column->name, "unit_cost") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				sp->unit_cost = atof(buf);
			}
			if (strcmp (column->name, "min_cost") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				sp->sp_id = atof(buf);
			}
			if (strcmp (column->name, "max_cost") == 0)
			{
				char buf[64];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				sp->sp_id = atof(buf);
			}
			else if (strcmp (column->name, "sp_desc") == 0)
			{
				char buf[512];
				strncpy (buf, row[i], lengths[i]);
				buf[lengths[i]] = '\0';
				strcpy (sp->sp_desc, buf);
			}
			else if (strcmp (column->name, "ts") == 0)
			{
				// We may need timestamp someday....
			}
		}
		sp_list = g_slist_append(sp_list, sp);
	}
	mysql_free_result (result);
	mysql_close (conn);

	return sp_list;
}

void insert_sparepart (SPAREPART * sp)
{
	if (!sp)
		return;

	MYSQL * conn;
	char query[1024];

	sprintf (query, "INSERT INTO SparePart (sp_code, sp_name, unit_cost, min_cost, max_cost, \
		sp_desc) VALUES (\"%s\", \"%s\", \"%f\", \"%f\", \"%f\", \"%s\")", 
			sp->sp_code,
			sp->sp_name,
			sp->unit_cost,
			sp->min_cost,	
			sp->max_cost,
			sp->sp_desc
			);

	conn = mysql_init (NULL);
	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);
	mysql_query (conn, query);
	mysql_close (conn);
}
