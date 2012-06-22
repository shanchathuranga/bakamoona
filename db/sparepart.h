#ifndef _SPAREPART_H_
#define _SPAREPART_H_

#include <glib.h>

typedef struct sparepart
{
	int sp_id;
	char sp_code[32];
	char sp_name[255];
	float unit_cost;
	float min_cost;
	float max_cost;
	char sp_desc[255];
	int deleted;
	int error;
} SPAREPART;

// select
SPAREPART * get_sparepart_by_id (int sp_id);
SPAREPART * get_sparepart_by_code (char * sp_code);

// insert
void insert_sparepart (SPAREPART * sp);

#endif
