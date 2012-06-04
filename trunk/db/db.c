#include "db.h"

void init_db ()
{
	MYSQL * conn;

	conn = mysql_init (NULL);

	mysql_real_connect (conn, "localhost", "root", "root", "bakamoona", 0, NULL, 0);
	
	mysql_query (conn, BKM_QUERY_JOBDETAILS);
	mysql_query (conn, BKM_QUERY_OWNER);
	mysql_query (conn, BKM_QUERY_BUS);
	mysql_query (conn, BKM_QUERY_UNREGISTEREDJOBDETAILS);

	mysql_close (conn);
}
