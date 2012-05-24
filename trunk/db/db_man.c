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
		printf("ERROR : bakamoona wakeup error");
		exit(1);
	}
}

void bakamoona_sleep ()
{
	mysql_close(conn);
}