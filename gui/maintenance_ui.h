#ifndef MAINTENANCE_H_
#define MAINTENANCE_H_

#include <gtk/gtk.h>


GtkWidget * window;
GtkWidget * title;
GtkWidget * vbox;
GtkWidget * busframe;
GtkWidget * bustable;
GtkWidget * lname, * laddr, * lcity;
GtkWidget * tname, * taddr, * tcity;
GtkWidget * select_owner;
GtkWidget * lcombo, * ldriver, * lmodel, * ldate;
GtkWidget * select_bus, * tdriver, * tmodel, * tdate;

GtkWidget * pack_hbox;
GtkWidget * packframe;
GtkWidget * itemframe;

GtkWidget * packvbox, * itemvbox;
GtkWidget * packselect, * packcustom, * packdelete, * tmphbox;
GtkWidget * itemselect, * itemdelete;
GtkWidget * packbase, * itembase;
GtkWidget * packtv, * itemtv;
GtkWidget * btnbase, * ok, * clear, * cancel;

GtkWidget * pkg_list, * item_list;

void create_maintenance_window ();
#endif
