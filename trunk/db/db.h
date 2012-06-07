#ifndef _DB_H_
#define _DB_H_

#include <my_global.h>
#include <mysql.h>

#define BKM_QUERY_JOBDETAILS "CREATE TABLE IF NOT EXISTS JobDetails ( \
	jobdetail_id INT NOT NULL AUTO_INCREMENT, \
	bus_id INT NOT NULL, \
	spare_part_id INT, \
	job_description VARCHAR (255), \
	job_fee FLOAT (10,2), \
	ts TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, \
	PRIMARY KEY (jobdetail_id) \
);"

#define BKM_QUERY_BUS "CREATE TABLE IF NOT EXISTS Bus ( \
	bus_id INT NOT NULL AUTO_INCREMENT, \
	owner_id INT NOT NULL, \
	bus_reg_no VARCHAR (8), \
	bus_model VARCHAR (64), \
	ts TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, \
	PRIMARY KEY (bus_id) \
);"

#define BKM_QUERY_OWNER "CREATE TABLE IF NOT EXISTS Owner ( \
  owner_id INT (10) NOT NULL AUTO_INCREMENT PRIMARY KEY, \
  owner_name VARCHAR (100), \
  owner_reg_no INT (10), \
  phone1 INT (10), \
  phone2 INT (10), \
  phone3 INT (10), \
  address1 VARCHAR (200), \
  city1 VARCHAR (50), \
  address2 VARCHAR (200), \
  city2 VARCHAR (50), \
  email VARCHAR (50), \
  PRIMARY KEY (owner_id) \
);"

#define BKM_QUERY_UNREGISTEREDJOBDETAILS "CREATE TABLE IF NOT EXISTS UnregistredJobDetails ( \
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

void init_db ();

#endif
