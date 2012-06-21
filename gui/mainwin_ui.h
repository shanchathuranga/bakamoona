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
// package
GtkWidget * package_item;
GtkWidget * packagemenu;
GtkWidget * addpackage;
GtkWidget * updatepackage;
GtkWidget * deletepackage;

GtkWidget * sep;
GtkWidget * quit;

// Maintenance
GtkWidget * mntmenu;
GtkWidget * mnt_menu_item;

GtkWidget * addmnt;
GtkWidget * updatemnt;

// Finance
GtkWidget * finmenu;
GtkWidget * fin_menu_item;

GtkWidget * addfin;
GtkWidget * updatefin;

// Search
GtkWidget * searchmenu;
GtkWidget * search_menu_item;

GtkWidget * search_bus;
GtkWidget * search_own;
GtkWidget * search_worker;
GtkWidget * search_sp;
GtkWidget * search_bill;
GtkWidget * search_mnt;

// About
GtkWidget * aboutmenu;
GtkWidget * about_menu_item;

GtkWidget * devteam;

GtkWidget * toolbar;
GtkToolItem * quit_tool;
GtkToolItem * new_tool;
GtkToolItem * open_tool;
GtkToolItem * save_tool;

#endif
