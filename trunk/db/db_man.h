#ifndef _DB_MAN_H_
#define _DB_MAN_H_

#include <my_global.h>
#include <mysql.h>

#define NO_RESULT        100
#define SUCCESS          101
#define MULTIPLE_RESULT  102

#define BKM_CREATE_QUERY_JOBDETAILS "CREATE TABLE IF NOT EXISTS JobDetails ( \
	jobdetail_id INT NOT NULL AUTO_INCREMENT, \
	bus_id INT NOT NULL, \
	spare_part_id INT, \
	job_description VARCHAR (255), \
	job_fee FLOAT (10,2), \
	ts TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, \
	PRIMARY KEY (jobdetail_id) \
);"

#define BKM_CREATE_QUERY_BUS "CREATE TABLE IF NOT EXISTS Bus ( \
	bus_id INT NOT NULL AUTO_INCREMENT, \
	owner_id INT NOT NULL, \
	bus_reg_no VARCHAR (8), \
	bus_model VARCHAR (64), \
	ts TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, \
	PRIMARY KEY (bus_id) \
);"

#define BKM_CREATE_QUERY_OWNER "CREATE TABLE IF NOT EXISTS Owner ( \
	owner_id INT NOT NULL AUTO_INCREMENT, \
	owner_name VARCHAR (128), \
	company_name VARCHAR (64), \
	ts TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, \
	PRIMARY KEY (owner_id) \
);"

#define BKM_CREATE_QUERY_UNREGISTEREDJOBDETAILS "CREATE TABLE UnregistredJobDetails ( \
	unreg_jobdetail_id INT NOT NULL AUTO_INCREMENT, \
	bus_reg_no VARCHAR (8), \
	bus_model VARCHAR (64), \
	owner_name VARCHAR (128), \
	company_name VARCHAR (64), \
	spare_part_id INT, \
	job_description VARCHAR (255), \
	job_fee FLOAT (10,2), \
	ts TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, \
	PRIMARY KEY (unreg_jobdetail_id) \
);"

static MYSQL * conn = NULL;

void bakamoona_wakeup ( const char * url, const char * username, const char * password);
void bakamoona_init_db ();
void bakamoona_sleep ();

#endif
