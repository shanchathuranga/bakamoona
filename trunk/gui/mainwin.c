#include "mainwin.h"
#include "owner_reg.h"

void add_bus_clicked (GtkWidget * widget, gpointer data)
{
	GtkWidget * w = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(w), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(w), "Bus Registration");
  	gtk_window_set_default_size(GTK_WINDOW(w), 300, 100);
	gtk_widget_show_all (w);
	g_signal_connect_swapped(G_OBJECT(w), "destroy",
        G_CALLBACK(gtk_widget_destroy), NULL);
}

void add_owner_clicked (GtkWidget * widget, gpointer data)
{
	create_owner_reg_window ();
}

void add_sparepart_clicked (GtkWidget * widget, gpointer data)
{
	GtkWidget * w = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(w), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(w), "Spare Part Registration");
  	gtk_window_set_default_size(GTK_WINDOW(w), 300, 100);
	gtk_widget_show_all (w);
	g_signal_connect_swapped(G_OBJECT(w), "destroy",
        G_CALLBACK(gtk_widget_destroy), NULL);
}

void quit_clicked (GtkWidget * widget, gpointer data)
{
	gtk_main_quit ();
}

GdkPixbuf *create_pixbuf(const gchar * filename)
{
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   if(!pixbuf) {
      fprintf(stderr, "%s\n", error->message);
      g_error_free(error);
   }

   return pixbuf;
}

void open_mainwindow ()
{
	mainwin = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(mainwin), GTK_WIN_POS_CENTER);
  	gtk_window_set_default_size(GTK_WINDOW(mainwin), 250, 200);
  	gtk_window_set_title(GTK_WINDOW(mainwin), "Bakamoona v 0.1");
	gtk_window_set_icon(GTK_WINDOW(mainwin), create_pixbuf("images/bkm.png"));

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

	toolbar = gtk_toolbar_new();
 	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
	gtk_container_set_border_width(GTK_CONTAINER(toolbar), 2);

	new_tool = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
  	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), new_tool, -1);

	open_tool = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), open_tool, -1);

	save_tool = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
  	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), save_tool, -1);

	gtk_box_pack_start(GTK_BOX(layout), toolbar, FALSE, FALSE, 3);

	g_signal_connect_swapped(G_OBJECT(mainwin), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

	g_signal_connect(G_OBJECT(add_bus), "activate",
        G_CALLBACK(add_bus_clicked), NULL);
	g_signal_connect(G_OBJECT(add_owner), "activate",
        G_CALLBACK(add_owner_clicked), NULL);
	g_signal_connect(G_OBJECT(add_sparepart), "activate",
        G_CALLBACK(add_sparepart_clicked), NULL);
  	g_signal_connect(G_OBJECT(quit), "activate",
        G_CALLBACK(gtk_main_quit), NULL);

	gtk_window_maximize (GTK_WINDOW(mainwin));
  	gtk_widget_show_all(mainwin);

}
