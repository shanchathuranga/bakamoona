#ifndef _MAINWIN_H_
#define _MAINWIN_H_

#include <gtk/gtk.h>

GtkWidget * mainwin;
GtkWidget * layout;
GtkWidget * menubar;
GtkWidget * addmenu;

// Add menu
GtkWidget * add;
GtkWidget * add_bus;
GtkWidget * add_owner;
GtkWidget * add_sparepart;
GtkWidget * quit;

GtkWidget * toolbar;
GtkToolItem * new_tool;
GtkToolItem * open_tool;
GtkToolItem * save_tool;

#endif
