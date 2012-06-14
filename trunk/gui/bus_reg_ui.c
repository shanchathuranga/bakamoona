#include "bus_reg_ui.h"
#include "bus.h"
#include <stdlib.h>
#include <string.h>

static void clear_fields ()
{
	gtk_entry_set_text(GTK_ENTRY(bui->tbus_regno), "");
	gtk_entry_set_text(GTK_ENTRY(bui->tengine_no), "");
	gtk_entry_set_text(GTK_ENTRY(bui->tchassy_no), "");
	gtk_entry_set_text(GTK_ENTRY(bui->tbus_model), "");
	gtk_entry_set_text(GTK_ENTRY(bui->tbus_desc), "");
}

static void clear_button_clicked (GtkWidget * widget, gpointer data)
{
	clear_fields ();
}

static void cancel_button_clicked (GtkWidget * widget, gpointer data)
{
	gtk_widget_destroy (bui->window);
}

static void ok_button_clicked (GtkWidget * widget, gpointer data)
{
	BUS * bus = malloc (sizeof(BUS));

	//insert_bus (bus);

	clear_fields ();
}

bus_ui * create_bus_reg_window ()
{
	bui = malloc (sizeof(bus_ui));
	bui->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(bui->window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(bui->window), "Bus Registration");
	gtk_window_set_default_size(GTK_WINDOW(bui->window), 500, 400);
	gtk_container_set_border_width(GTK_CONTAINER(bui->window), 10);

	bui->vbox = gtk_vbox_new(FALSE, 5);
	gtk_container_add(GTK_CONTAINER(bui->window), bui->vbox);
	gtk_box_set_spacing (GTK_BOX(bui->vbox), 5);

	bui->title = gtk_label_new ("Bus Registration");
	gtk_box_pack_start(GTK_BOX(bui->vbox), bui->title, FALSE, FALSE, 0);

	bui->owner_table = gtk_table_new (3, 3, FALSE);
	gtk_container_set_border_width(GTK_CONTAINER(bui->owner_table), 10);
	gtk_table_set_row_spacings(GTK_TABLE(bui->owner_table), 5);
	gtk_table_set_col_spacings(GTK_TABLE(bui->owner_table), 5);

	bui->lowner_name = gtk_label_new ("Owner Name : ");
	bui->lowner_address = gtk_label_new ("Owner Address : ");
	bui->lowner_city = gtk_label_new ("Owner City : ");
	gtk_misc_set_alignment (GTK_MISC (bui->lowner_name), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (bui->lowner_address), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (bui->lowner_city), 1, 0.5);

	bui->towner_name = gtk_label_new ("");
	bui->towner_address = gtk_label_new ("");
	bui->towner_city = gtk_label_new ("");
	gtk_label_set_markup (GTK_LABEL(bui->towner_name), "<i>--- Owner Name ---</i>");
	gtk_label_set_markup (GTK_LABEL(bui->towner_address), "<i>--- Owner Address ---</i>"); 
	gtk_label_set_markup (GTK_LABEL(bui->towner_city), "<i>--- Owner City ---</i>");
	gtk_misc_set_alignment (GTK_MISC (bui->towner_name), 0, 0.5);
	gtk_misc_set_alignment (GTK_MISC (bui->towner_address), 0, 0.5);
	gtk_misc_set_alignment (GTK_MISC (bui->towner_city), 0, 0.5);

	bui->select_owner = gtk_button_new_with_label ("Choose");

	gtk_table_attach (GTK_TABLE(bui->owner_table), bui->lowner_name, 0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach (GTK_TABLE(bui->owner_table), bui->lowner_address, 0, 1, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach (GTK_TABLE(bui->owner_table), bui->lowner_city, 0, 1, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);

	gtk_table_attach_defaults (GTK_TABLE(bui->owner_table), bui->towner_name, 1, 2, 0, 1);
	gtk_table_attach_defaults (GTK_TABLE(bui->owner_table), bui->towner_address, 1, 2, 1, 2);
	gtk_table_attach_defaults (GTK_TABLE(bui->owner_table), bui->towner_city, 1, 2, 2, 3);
	gtk_table_attach (GTK_TABLE(bui->owner_table), bui->select_owner, 2, 3, 0, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);

	bui->owner_frame = gtk_frame_new(" Owner Details ");
	gtk_frame_set_shadow_type(GTK_FRAME(bui->owner_frame), GTK_SHADOW_ETCHED_IN);

	gtk_container_add(GTK_CONTAINER(bui->owner_frame), bui->owner_table);
	gtk_box_pack_start(GTK_BOX(bui->vbox), bui->owner_frame, FALSE, FALSE, 0);

	bui->bus_table = gtk_table_new (4, 2, FALSE);
	gtk_container_set_border_width(GTK_CONTAINER(bui->bus_table), 10);
	gtk_table_set_row_spacings(GTK_TABLE(bui->bus_table), 5);
	gtk_table_set_col_spacings(GTK_TABLE(bui->bus_table), 5);

	bui->bus_frame = gtk_frame_new(" Bus Details ");
	gtk_frame_set_shadow_type(GTK_FRAME(bui->owner_frame), GTK_SHADOW_ETCHED_IN);

	gtk_container_add(GTK_CONTAINER(bui->bus_frame), bui->bus_table);
	gtk_box_pack_start(GTK_BOX(bui->vbox), bui->bus_frame, FALSE, FALSE, 0);

	bui->lbus_regno = gtk_label_new ("Bus Reg.No : ");
	bui->lengine_no = gtk_label_new ("Engine No : ");
	bui->lchassy_no = gtk_label_new ("Chassy No : ");
	bui->lbus_model = gtk_label_new ("Bus Model : ");
	bui->lbus_desc = gtk_label_new  ("Bus Description : ");

	gtk_table_attach (GTK_TABLE(bui->bus_table), bui->lbus_regno, 0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach (GTK_TABLE(bui->bus_table), bui->lengine_no, 0, 1, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach (GTK_TABLE(bui->bus_table), bui->lchassy_no, 0, 1, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach (GTK_TABLE(bui->bus_table), bui->lbus_model, 0, 1, 3, 4, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach (GTK_TABLE(bui->bus_table), bui->lbus_desc,  0, 1, 4, 5, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_misc_set_alignment (GTK_MISC (bui->lbus_regno), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (bui->lengine_no), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (bui->lchassy_no), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (bui->lbus_model), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (bui->lbus_desc),  1, 0.5);

	bui->tbus_regno = gtk_entry_new ();
	bui->tengine_no = gtk_entry_new ();
	bui->tchassy_no = gtk_entry_new ();
	bui->tbus_model = gtk_entry_new ();
	bui->tbus_desc  = gtk_entry_new ();

	gtk_table_attach_defaults (GTK_TABLE(bui->bus_table), bui->tbus_regno, 1, 2, 0, 1);
	gtk_table_attach_defaults (GTK_TABLE(bui->bus_table), bui->tengine_no, 1, 2, 1, 2);
	gtk_table_attach_defaults (GTK_TABLE(bui->bus_table), bui->tchassy_no, 1, 2, 2, 3);
	gtk_table_attach_defaults (GTK_TABLE(bui->bus_table), bui->tbus_model, 1, 2, 3, 4);
	gtk_table_attach_defaults (GTK_TABLE(bui->bus_table), bui->tbus_desc,  1, 2, 4, 5);

	bui->clear  = gtk_button_new_with_label ("Clear");
	bui->ok     = gtk_button_new_with_label ("OK");
	bui->cancel = gtk_button_new_with_label ("Cancel");
	gtk_widget_set_size_request (bui->clear, 100, 30);	
	gtk_widget_set_size_request (bui->ok, 100, 30);
	gtk_widget_set_size_request (bui->cancel, 100, 30);

	bui->hbox = gtk_hbox_new (FALSE, 5);
	gtk_box_pack_start(GTK_BOX(bui->hbox), bui->clear, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(bui->hbox), bui->cancel, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(bui->hbox), bui->ok, FALSE, FALSE, 0);

	gtk_box_pack_end(GTK_BOX(bui->vbox), bui->hbox, FALSE, FALSE, 0);

	g_signal_connect_swapped (G_OBJECT(bui->window), "destroy",
        G_CALLBACK(gtk_widget_destroy), G_OBJECT(bui->window));

	g_signal_connect (G_OBJECT(bui->ok), "clicked",
		G_CALLBACK(ok_button_clicked), G_OBJECT(bui->window));

	g_signal_connect (G_OBJECT(bui->clear), "clicked",
		G_CALLBACK(clear_button_clicked), G_OBJECT(bui->window));

	g_signal_connect (G_OBJECT(bui->cancel), "clicked",
		G_CALLBACK(cancel_button_clicked), G_OBJECT(bui->window));

	gtk_window_set_modal (GTK_WINDOW(bui->window), TRUE);

	gtk_widget_show_all (bui->window);
	
	return bui;
}

