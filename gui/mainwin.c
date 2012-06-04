#include "mainwin.h"

void open_mainwindow ()
{
	mainwin = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(mainwin), GTK_WIN_POS_CENTER);
  	gtk_window_set_default_size(GTK_WINDOW(mainwin), 250, 200);
  	gtk_window_set_title(GTK_WINDOW(mainwin), "StockCycle v 0.1");

	layout = gtk_vbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (mainwin), layout);

	menubar = gtk_menu_bar_new ();
	addmenu = gtk_menu_new ();

	add = gtk_menu_item_new_with_label("Add");
	add_bus = gtk_menu_item_new_with_label ("Add Bus");
	add_owner = gtk_menu_item_new_with_label ("Add Owner");
	add_sparepart = gtk_menu_item_new_with_label ("Add Spare part");
 	quit = gtk_menu_item_new_with_label("Quit");

	gtk_menu_item_set_submenu (GTK_MENU_ITEM(add), addmenu);
	gtk_menu_shell_append (GTK_MENU_SHELL(addmenu), add_bus);
	gtk_menu_shell_append (GTK_MENU_SHELL(addmenu), add_owner);
	gtk_menu_shell_append (GTK_MENU_SHELL(addmenu), add_sparepart);
  	gtk_menu_shell_append (GTK_MENU_SHELL(addmenu), quit);
  	gtk_menu_shell_append (GTK_MENU_SHELL(menubar), add);
  	gtk_box_pack_start (GTK_BOX(layout), menubar, FALSE, FALSE, 3);

	g_signal_connect_swapped(G_OBJECT(mainwin), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

  	g_signal_connect(G_OBJECT(quit), "activate",
        G_CALLBACK(gtk_main_quit), NULL);

	gtk_window_maximize (GTK_WINDOW(mainwin));
  	gtk_widget_show_all(mainwin);

}
