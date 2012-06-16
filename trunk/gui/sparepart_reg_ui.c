#include "sparepart_reg_ui.h"
#include <stdlib.h>

static void ok_button_clicked(GtkWidget * widget, gpointer data)
{
}

static void clear_button_clicked(GtkWidget * widget, gpointer data)
{
}

static void cancel_button_clicked(GtkWidget * widget, gpointer data)
{
	gtk_widget_destroy (spui->window);
}

sparepart_ui * create_sparepart_reg_window ()
{
	spui = malloc (sizeof(sparepart_ui));

	spui->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(spui->window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(spui->window), 500, 280);
	gtk_window_set_title(GTK_WINDOW(spui->window), "Spare Part Registration");
	gtk_container_set_border_width(GTK_CONTAINER(spui->window), 10);

	spui->vbox = gtk_vbox_new(FALSE, 5);  // hama kotuwakma 1ka =i ,true dapuwama
	gtk_box_set_spacing (GTK_BOX(spui->vbox), 5);
	gtk_container_add(GTK_CONTAINER(spui->window), spui->vbox);

	spui->header_label = gtk_label_new("Spare Part Registration");
	gtk_box_pack_start(GTK_BOX(spui->vbox), spui->header_label, FALSE, FALSE, 0);

	spui->layout = gtk_table_new(6, 2, FALSE);
	gtk_table_set_row_spacings(GTK_TABLE(spui->layout), 5);
	gtk_table_set_col_spacings(GTK_TABLE(spui->layout), 5);

	spui->code_label = gtk_label_new("SP Code : ");
	spui->code_txt = gtk_entry_new(); 

	spui->sp_name_label = gtk_label_new("SP Name : ");
	spui->sp_name_txt = gtk_entry_new(); 

	spui->unitcost_label = gtk_label_new("Unit Cost : ");
	spui->unitcost_txt = gtk_entry_new(); 

	spui->mincost_label = gtk_label_new("Min Cost : ");
	spui->mincost_txt = gtk_entry_new(); 

	spui->maxcost_label = gtk_label_new("Max Cost : ");
	spui->maxcost_txt = gtk_entry_new();

	spui->desc_label = gtk_label_new("Description : ");
	spui->desc_txt = gtk_entry_new(); 

	gtk_misc_set_alignment (GTK_MISC (spui->code_label), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (spui->sp_name_label), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (spui->unitcost_label), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (spui->mincost_label), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (spui->maxcost_label), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (spui->desc_label), 1, 0.5);

	gtk_table_attach (GTK_TABLE(spui->layout), spui->code_label,0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(spui->layout), spui->code_txt, 1, 2, 0, 1);

	gtk_table_attach (GTK_TABLE(spui->layout), spui->sp_name_label,0, 1, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(spui->layout), spui->sp_name_txt, 1, 2, 1, 2);

	gtk_table_attach (GTK_TABLE(spui->layout), spui->unitcost_label, 0, 1, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(spui->layout), spui->unitcost_txt, 1, 2, 2, 3);

	gtk_table_attach (GTK_TABLE(spui->layout), spui->mincost_label, 0, 1, 3, 4, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(spui->layout), spui->mincost_txt, 1, 2, 3, 4);

	gtk_table_attach (GTK_TABLE(spui->layout), spui->maxcost_label, 0, 1, 4, 5, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(spui->layout), spui->maxcost_txt, 1, 2, 4, 5);

	gtk_table_attach (GTK_TABLE(spui->layout), spui->desc_label,0, 1, 5, 6, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(spui->layout), spui->desc_txt, 1, 2, 5, 6);

	gtk_box_pack_start(GTK_BOX(spui->vbox), spui->layout, FALSE, FALSE, 0);

	spui->hbox = gtk_hbox_new (FALSE, 5);
	spui->clear_button = gtk_button_new_with_label ("Clear");
	gtk_widget_set_size_request (spui->clear_button, 100, 30);
	spui->ok_button = gtk_button_new_with_label ("Ok");
	gtk_widget_set_size_request (spui->ok_button, 100, 30);
	spui->cancel_button = gtk_button_new_with_label ("Cancel");
	gtk_widget_set_size_request (spui->cancel_button, 100, 30);

	gtk_box_pack_start(GTK_BOX(spui->hbox), spui->clear_button, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(spui->hbox), spui->cancel_button, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(spui->hbox), spui->ok_button, FALSE, FALSE, 0);

	gtk_box_pack_end(GTK_BOX(spui->vbox), spui->hbox, FALSE, FALSE, 0);

	g_signal_connect_swapped(G_OBJECT(spui->window), "destroy",
			G_CALLBACK(gtk_widget_destroy), G_OBJECT(spui->window));

	g_signal_connect (G_OBJECT(spui->ok_button), "clicked",
			G_CALLBACK(ok_button_clicked), G_OBJECT(spui->window));

	g_signal_connect (G_OBJECT(spui->clear_button), "clicked",
			G_CALLBACK(clear_button_clicked), G_OBJECT(spui->window));

	g_signal_connect (G_OBJECT(spui->cancel_button), "clicked",
			G_CALLBACK(cancel_button_clicked), G_OBJECT(spui->window));

	gtk_window_set_modal (GTK_WINDOW(spui->window), TRUE);

	gtk_widget_show_all(spui->window);

	return spui;
}

