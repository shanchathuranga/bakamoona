#ifndef _MAINWIN_UI_H_
#define _MAINWIN_UI_H_

#include <gtk/gtk.h>

GtkWidget * mainwin;
GtkWidget * layout;
GtkWidget * menubar;
// System menu
GtkWidget * sysmenu;
GtkWidget * sys_menu_item;
// bus
GtkWidget * bus_item;
GtkWidget * busmenu;
GtkWidget * addbus;
GtkWidget * updatebus;
GtkWidget * deletebus;
// owner
GtkWidget * owner_item;
GtkWidget * ownermenu;
GtkWidget * addowner;
GtkWidget * updateowner;
GtkWidget * deleteowner;
// sparepart
GtkWidget * sp_item;
GtkWidget * spmenu;
GtkWidget * addsp;
GtkWidget * updatesp;
GtkWidget * deletesp;
// worker
GtkWidget * worker_item;
GtkWidget * workermenu;
GtkWidget * addworker;
GtkWidget * updateworker;
GtkWidget * deleteworker;

GtkWidget * add_sparepart;
GtkWidget * quit;

GtkWidget * toolbar;
GtkToolItem * quit_tool;
GtkToolItem * new_tool;
GtkToolItem * open_tool;
GtkToolItem * save_tool;

#endif
