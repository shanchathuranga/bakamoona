#include "mainwin_ui.h"
#include "owner_reg_ui.h"
#include "bus_reg_ui.h"
#include "worker_reg_ui.h"
#include "sparepart_reg_ui.h"
#include "maintenance_ui.h"

void add_bus_clicked (GtkWidget * widget, gpointer data)
{
	/*GtkWidget * w = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(w), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(w), "Bus Registration");
  	gtk_window_set_default_size(GTK_WINDOW(w), 300, 100);
	gtk_widget_show_all (w);
	g_signal_connect_swapped(G_OBJECT(w), "destroy",
        G_CALLBACK(gtk_widget_destroy), NULL);*/

	create_bus_reg_window ();
}

void add_bill_clicked (GtkWidget * widget, gpointer data)
{
	create_bill_window ();
}

void add_owner_clicked (GtkWidget * widget, gpointer data)
{
	create_owner_reg_window ();
}

void add_sparepart_clicked (GtkWidget * widget, gpointer data)
{
	create_sparepart_reg_window ();
}

void add_worker_clicked (GtkWidget * widget, gpointer data)
{
  	create_worker_reg_window ();
}

void quit_clicked (GtkWidget * widget, gpointer data)
{
	gtk_main_quit ();
}

void add_maintenance_clicked (GtkWidget * widget, gpointer data)
{
	create_maintenance_window ();
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

/*
  System | Maintenance | Finance | Search | Statistics | About
*/

    // System
    sysmenu = gtk_menu_new();
    sys_menu_item = gtk_menu_item_new_with_label ("System");
    gtk_menu_item_set_submenu (GTK_MENU_ITEM(sys_menu_item), sysmenu);

    // adding bus
    bus_item = gtk_menu_item_new_with_label ("Bus");
    gtk_menu_shell_append (GTK_MENU_SHELL(sysmenu), bus_item);

    busmenu = gtk_menu_new ();
    gtk_menu_item_set_submenu (GTK_MENU_ITEM(bus_item), busmenu);

    addbus = gtk_menu_item_new_with_label ("Add Bus");
    updatebus = gtk_menu_item_new_with_label ("Update Bus");
    deletebus = gtk_menu_item_new_with_label ("Delete Bus");

    gtk_menu_shell_append (GTK_MENU_SHELL(busmenu), addbus);
    gtk_menu_shell_append (GTK_MENU_SHELL(busmenu), updatebus);
    gtk_menu_shell_append (GTK_MENU_SHELL(busmenu), deletebus);

    // adding owner
    owner_item = gtk_menu_item_new_with_label ("Owner");
    gtk_menu_shell_append (GTK_MENU_SHELL(sysmenu), owner_item);

    ownermenu = gtk_menu_new ();
    gtk_menu_item_set_submenu (GTK_MENU_ITEM(owner_item), ownermenu);

    addowner = gtk_menu_item_new_with_label ("Add Owner");
    updateowner = gtk_menu_item_new_with_label ("Update Owner");
    deleteowner = gtk_menu_item_new_with_label ("Delete Owner");

    gtk_menu_shell_append (GTK_MENU_SHELL(ownermenu), addowner);
    gtk_menu_shell_append (GTK_MENU_SHELL(ownermenu), updateowner);
    gtk_menu_shell_append (GTK_MENU_SHELL(ownermenu), deleteowner);

    // adding sparepart 
    sp_item = gtk_menu_item_new_with_label ("Spare Part");
    gtk_menu_shell_append (GTK_MENU_SHELL(sysmenu), sp_item);

    spmenu = gtk_menu_new ();
    gtk_menu_item_set_submenu (GTK_MENU_ITEM(sp_item), spmenu);

    addsp = gtk_menu_item_new_with_label ("Add Spare Part");
    updatesp = gtk_menu_item_new_with_label ("Update Spare Part");
    deletesp = gtk_menu_item_new_with_label ("Delete Spare Part");

    gtk_menu_shell_append (GTK_MENU_SHELL(spmenu), addsp);
    gtk_menu_shell_append (GTK_MENU_SHELL(spmenu), updatesp);
    gtk_menu_shell_append (GTK_MENU_SHELL(spmenu), deletesp);
    
    // adding worker
    worker_item = gtk_menu_item_new_with_label ("Worker");
    gtk_menu_shell_append (GTK_MENU_SHELL(sysmenu), worker_item);

    workermenu = gtk_menu_new ();
    gtk_menu_item_set_submenu (GTK_MENU_ITEM(worker_item), workermenu);

    addworker = gtk_menu_item_new_with_label ("Add Worker");
    updateworker = gtk_menu_item_new_with_label ("Update Worker");
    deleteworker = gtk_menu_item_new_with_label ("Delete Worker");

    gtk_menu_shell_append (GTK_MENU_SHELL(workermenu), addworker);
    gtk_menu_shell_append (GTK_MENU_SHELL(workermenu), updateworker);
    gtk_menu_shell_append (GTK_MENU_SHELL(workermenu), deleteworker);

	sep = gtk_separator_menu_item_new();
    quit = gtk_menu_item_new_with_label("Quit");

    gtk_menu_shell_append (GTK_MENU_SHELL(sysmenu), sep);
    gtk_menu_shell_append (GTK_MENU_SHELL(sysmenu), quit);
        
    gtk_menu_shell_append (GTK_MENU_SHELL(menubar), sys_menu_item);

	mntmenu = gtk_menu_new();
    mnt_menu_item = gtk_menu_item_new_with_label ("Maintenance");
    gtk_menu_item_set_submenu (GTK_MENU_ITEM(mnt_menu_item), mntmenu);

	gtk_menu_shell_append (GTK_MENU_SHELL(menubar), mnt_menu_item);

	addmnt = gtk_menu_item_new_with_label ("Add Maintenance");
    updatemnt = gtk_menu_item_new_with_label ("Update Maintenance");

	gtk_menu_shell_append (GTK_MENU_SHELL(mntmenu), addmnt);
	gtk_menu_shell_append (GTK_MENU_SHELL(mntmenu), updatemnt);

	//

	finmenu = gtk_menu_new();
    fin_menu_item = gtk_menu_item_new_with_label ("Finance");
    gtk_menu_item_set_submenu (GTK_MENU_ITEM(fin_menu_item), finmenu);

	gtk_menu_shell_append (GTK_MENU_SHELL(menubar), fin_menu_item);

	addfin = gtk_menu_item_new_with_label ("Add Bill");
    updatefin = gtk_menu_item_new_with_label ("Update Bill");

	gtk_menu_shell_append (GTK_MENU_SHELL(finmenu), addfin);
	gtk_menu_shell_append (GTK_MENU_SHELL(finmenu), updatefin);
	
	//

	searchmenu = gtk_menu_new();
    search_menu_item = gtk_menu_item_new_with_label ("Search");
    gtk_menu_item_set_submenu (GTK_MENU_ITEM(search_menu_item), searchmenu);

	gtk_menu_shell_append (GTK_MENU_SHELL(menubar), search_menu_item);

	search_bus = gtk_menu_item_new_with_label ("Bus");
	search_own = gtk_menu_item_new_with_label ("Owner");
	search_worker = gtk_menu_item_new_with_label ("Worker");
	search_sp = gtk_menu_item_new_with_label ("Spare Part");
	search_bill = gtk_menu_item_new_with_label ("Bill");
	search_mnt = gtk_menu_item_new_with_label ("Maintenance");
	
	gtk_menu_shell_append (GTK_MENU_SHELL(searchmenu), search_bus);
	gtk_menu_shell_append (GTK_MENU_SHELL(searchmenu), search_own);
	gtk_menu_shell_append (GTK_MENU_SHELL(searchmenu), search_worker);
	gtk_menu_shell_append (GTK_MENU_SHELL(searchmenu), search_sp);
	gtk_menu_shell_append (GTK_MENU_SHELL(searchmenu), search_bill);
	gtk_menu_shell_append (GTK_MENU_SHELL(searchmenu), search_mnt);

	//

	aboutmenu = gtk_menu_new();
    about_menu_item = gtk_menu_item_new_with_label ("About");
    gtk_menu_item_set_submenu (GTK_MENU_ITEM(about_menu_item), aboutmenu);

	gtk_menu_shell_append (GTK_MENU_SHELL(menubar), about_menu_item);
	
	devteam = gtk_menu_item_new_with_label ("About DEV team");
	gtk_menu_shell_append (GTK_MENU_SHELL(aboutmenu), devteam);

// end

  	gtk_box_pack_start (GTK_BOX(layout), menubar, FALSE, FALSE, 0);

	toolbar = gtk_toolbar_new();
 	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
	gtk_container_set_border_width(GTK_CONTAINER(toolbar), 0);

	quit_tool = gtk_tool_button_new_from_stock (GTK_STOCK_QUIT);
	gtk_toolbar_insert (GTK_TOOLBAR(toolbar), quit_tool, -1);

	new_tool = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
  	gtk_toolbar_insert (GTK_TOOLBAR(toolbar), new_tool, -1);

	open_tool = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  	gtk_toolbar_insert (GTK_TOOLBAR(toolbar), open_tool, -1);

	save_tool = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
  	gtk_toolbar_insert (GTK_TOOLBAR(toolbar), save_tool, -1);

	gtk_box_pack_start (GTK_BOX(layout), toolbar, FALSE, FALSE, 0);

	g_signal_connect_swapped(G_OBJECT(mainwin), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

	g_signal_connect(G_OBJECT(addbus), "activate",
        G_CALLBACK(add_bus_clicked), NULL);
    g_signal_connect(G_OBJECT(addworker), "activate",
        G_CALLBACK(add_worker_clicked), NULL);
	g_signal_connect(G_OBJECT(addowner), "activate",
        G_CALLBACK(add_owner_clicked), NULL);
	g_signal_connect(G_OBJECT(addsp), "activate",
        G_CALLBACK(add_sparepart_clicked), NULL);
  	g_signal_connect(G_OBJECT(quit), "activate",
        G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(addmnt), "activate",
        G_CALLBACK(add_maintenance_clicked), NULL);

        g_signal_connect(G_OBJECT(addfin), "activate",
        G_CALLBACK(add_bill_clicked), NULL);

	gtk_window_maximize (GTK_WINDOW(mainwin));
  	gtk_widget_show_all(mainwin);

}
