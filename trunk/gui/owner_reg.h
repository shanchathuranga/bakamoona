#ifndef _OWNER_REG_H_
#define _OWNER_REG_H_

#include <gtk/gtk.h>

typedef struct _owner_ui
{
	GtkWidget * window;
	GtkWidget * title;
	GtkWidget * vbox;
	GtkWidget * hbox;
	GtkWidget * hspace;
	GtkWidget * table;
	GtkWidget * clear;
	GtkWidget * ok;
	GtkWidget * cancel;
	GtkWidget * lname, * tname;
	GtkWidget * lregno, * tregno;
	GtkWidget * lph1, * tph1;
	GtkWidget * lph2, * tph2;
	GtkWidget * laddress1, * taddress1;
	GtkWidget * lcity1, * tcity1;
	GtkWidget * laddress2, * taddress2;
	GtkWidget * lcity2, * tcity2; 
	GtkWidget * lemail, * temail;
} owner_ui;

owner_ui * ownui;

owner_ui * create_owner_reg_window ();

#endif
