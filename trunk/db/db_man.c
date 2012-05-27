#include "db_man.h"
#include <stdio.h>
#include <stdlib.h>

void bakamoona_wakeup ( const char * url, const char * username, const char * password)
{
	conn = mysql_init(NULL);

	if (conn == NULL ){
		printf("ERROR : bakamoona wakeup error\n");
		exit(1);
	}

	if (mysql_real_connect(conn, url, username, password, "bakamoona", 0, NULL, 0) == NULL) {
		printf("ERROR : bakamoona wakeup error\n");
		exit(1);
	}
}

void bakamoona_init_db ()
{
	if (mysql_query(conn, BKM_CREATE_QUERY_JOBDETAILS)) {
		printf("ERROR : bakamoona create BKM_CREATE_QUERY_JOBDETAILS error\n");
		exit(1);
	}
	
	if (mysql_query(conn, BKM_CREATE_QUERY_BUS)) {
		printf("ERROR : bakamoona create BKM_CREATE_QUERY_BUS error\n");
		exit(1);
	}

	if (mysql_query(conn, BKM_CREATE_QUERY_OWNER)) {
		printf("ERROR : bakamoona create BKM_CREATE_QUERY_OWNER error\n");
		exit(1);
	}

	if (mysql_query(conn, BKM_CREATE_QUERY_UNREGISTEREDJOBDETAILS)) {
		printf("ERROR : bakamoona create BKM_CREATE_QUERY_UNREGISTEREDJOBDETAILS error\n");
		exit(1);
	}
}

void bakamoona_sleep ()
{
	mysql_close(conn);
}
