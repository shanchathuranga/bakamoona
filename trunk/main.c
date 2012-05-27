#include "db_man.h"
#include <stdio.h>

int main()
{
	bakamoona_wakeup ("localhost", "root", "root");

	printf("DEBUG : bakamoona ok\n");

	bakamoona_init_db ();

	printf("DEBUG : bakamoona init ok\n");

	bakamoona_sleep();

	return 0;
}

