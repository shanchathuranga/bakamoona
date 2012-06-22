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
	bus_reg_no VARCHAR (20), \
	bus_eng_no VARCHAR (64), \
	bus_chs_no VARCHAR (64), \
	bus_model VARCHAR (64), \
	bus_desc VARCHAR (255), \
	deleted INT, \
	ts TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, \
	PRIMARY KEY (bus_id) \
);"

#define BKM_QUERY_OWNER "CREATE TABLE IF NOT EXISTS Owner ( \
  	owner_id INT NOT NULL AUTO_INCREMENT, \
  	owner_name VARCHAR (125), \
  	owner_reg_no VARCHAR (64), \
  	phone1 VARCHAR (10), \
  	phone2 VARCHAR (10), \
  	address1 VARCHAR (255), \
  	city1 VARCHAR (64), \
  	address2 VARCHAR (255), \
  	city2 VARCHAR (64), \
  	email VARCHAR (128), \
  	PRIMARY KEY (owner_id) \
);"

#define BKM_QUERY_SPARE_PART "CREATE TABLE IF NOT EXISTS SparePart ( \
	sp_id INT NOT NULL AUTO_INCREMENT, \
	sp_code VARCHAR (32), \
	sp_name VARCHAR (255), \
	unit_cost FLOAT (10,2), \
	min_cost FLOAT (10,2), \
	max_cost FLOAT (10,2), \
	sp_desc VARCHAR (255), \
	ts TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, \
	PRIMARY KEY (sp_id) \
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
