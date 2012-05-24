#ifndef _DB_MAN_H_
#define _DB_MAN_H_

#include <my_global.h>
#include <mysql.h>

    #define NO_RESULT 100
#define SUCCESS 101
#define MULTIPLE_RESULT 102

static MYSQL * conn = NULL;

void bakamoona_wakeup ( const char * url, const char * username, const char * password);
void bakamoona_sleep ();

#endif