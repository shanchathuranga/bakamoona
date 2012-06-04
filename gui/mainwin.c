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
	filemenu = gtk_menu_new ();

	file = gtk_menu_item_new_with_label("File");
 	quit = gtk_menu_item_new_with_label("Quit");

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
  	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
  	gtk_box_pack_start(GTK_BOX(layout), menubar, FALSE, FALSE, 3);

	g_signal_connect_swapped(G_OBJECT(mainwin), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

  	g_signal_connect(G_OBJECT(quit), "activate",
        G_CALLBACK(gtk_main_quit), NULL);

	gtk_window_maximize (GTK_WINDOW(mainwin));
  	gtk_widget_show_all(mainwin);

}
