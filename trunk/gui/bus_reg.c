#include "bus_reg.h"

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
GtkWidget * lowner;
GtkWidget * lowner_name;
GtkWidget * lowner_address;
GtkWidget * towner;
GtkWidget * towner_name;
GtkWidget * towner_address;
GtkWidget * tcity;
GtkWidget * title_bus;
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

void create_bus_reg_window ()
{
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), "Bus Registration");
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 370);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    vbox = gtk_vbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_box_set_spacing (GTK_BOX(vbox), 5);

    title = gtk_label_new ("Bus Registration");
    gtk_box_pack_start(GTK_BOX(vbox), title, FALSE, FALSE, 0);

    owner_table = gtk_table_new (3, 3, FALSE);
	gtk_table_set_row_spacings(GTK_TABLE(owner_table), 5);
 	gtk_table_set_col_spacings(GTK_TABLE(owner_table), 5);

	bus_table = gtk_table_new (4, 2, FALSE);
	gtk_table_set_row_spacings(GTK_TABLE(bus_table), 5);
 	gtk_table_set_col_spacings(GTK_TABLE(bus_table), 5);
	
	lowner = gtk_label_new ("Owner");

	gtk_misc_set_alignment (GTK_MISC (lowner), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (lowner_name), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (lowner_address), 1, 0.5);

	towner = gtk_entry_new();
	towner_name = gtk_entry_new ();
	towner_address = gtk_entry_new ();
	tcity = gtk_entry_new ();

	select_owner = gtk_button_new_with_label ("Choose");

	gtk_table_attach (GTK_TABLE(owner_table), lowner, 0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(owner_table), towner_name, 1, 2, 0, 1);
    gtk_table_attach_defaults (GTK_TABLE(owner_table), towner_address, 1, 2, 1, 2);
	gtk_table_attach_defaults (GTK_TABLE(owner_table), select_owner, 2, 3, 0, 1);
	
	gtk_box_pack_start(GTK_BOX(vbox), owner_table, FALSE, FALSE, 0);

	gtk_widget_show_all (window);
}
