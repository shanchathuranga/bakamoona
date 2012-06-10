#ifndef _BUS_REG_H_
#define _BUS_REG_H_

#include <gtk/gtk.h>

typedef struct _bus_ui
{
	GtkWidget * window;
	GtkWidget * vbox;
	GtkWidget * owner_table;
	GtkWidget * bus_table;
	GtkWidget * hbox;
	GtkWidget * select_owner;
	GtkWidget * clear;
	GtkWidget * ok;
	GtkWidget * cancel;
	GtkWidget * title;
	GtkWidget * owner_frame;
	GtkWidget * bus_frame;
	GtkWidget * lowner_name;
	GtkWidget * lowner_address;
	GtkWidget * lowner_city;
	GtkWidget * towner_name;
	GtkWidget * towner_address;
	GtkWidget * towner_city;
	GtkWidget * lbus_regno;
	GtkWidget * lengine_no;
	GtkWidget * lchassy_no;
	GtkWidget * lbus_model;
	GtkWidget * lbus_desc;
	GtkWidget * tbus_regno;
	GtkWidget * tengine_no;
	GtkWidget * tchassy_no;	
	GtkWidget * tbus_model;
	GtkWidget * tbus_desc;
} bus_ui;

bus_ui * bui;

bus_ui * create_bus_reg_window ();

#endif
