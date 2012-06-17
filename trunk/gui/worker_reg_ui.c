#include "worker_reg_ui.h"
#include <stdlib.h>
#include <string.h>

static void ok_button_clicked (GtkWidget * widget, gpointer data)
{
	// do something
	gtk_widget_destroy (wrkui->window);
}

static void clear_button_clicked (GtkWidget * widget, gpointer data)
{
}

static void cancel_button_clicked (GtkWidget * widget, gpointer data)
{
	gtk_widget_destroy (wrkui->window);
}

worker_ui * create_worker_reg_window ()
{
	wrkui = malloc (sizeof(worker_ui));

	wrkui->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(wrkui->window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(wrkui->window), 500, 280);
	gtk_window_set_title(GTK_WINDOW(wrkui->window), "Worker Registration");
	gtk_container_set_border_width(GTK_CONTAINER(wrkui->window), 10);

	wrkui->vbox = gtk_vbox_new(FALSE, 1);  // hama kotuwakma 1ka =i ,true dapuwama
	gtk_box_set_spacing (GTK_BOX(wrkui->vbox), 5);
	gtk_container_add(GTK_CONTAINER(wrkui->window), wrkui->vbox);

	wrkui->header_label = gtk_label_new("Worker Registration");
	gtk_box_pack_start(GTK_BOX(wrkui->vbox), wrkui->header_label, FALSE, FALSE, 0);//
	/////////
	wrkui->layout = gtk_table_new(6, 2, FALSE);//
	gtk_table_set_row_spacings(GTK_TABLE(wrkui->layout), 5);
	gtk_table_set_col_spacings(GTK_TABLE(wrkui->layout), 5);

	wrkui->name_label = gtk_label_new("Name : ");
	wrkui->name_txt = gtk_entry_new(); 

	wrkui->address_label = gtk_label_new("Address : ");
	wrkui->address_txt = gtk_entry_new(); 

	wrkui->city_label = gtk_label_new("City : ");
	wrkui->city_txt = gtk_entry_new(); 

	wrkui->nicNo_label = gtk_label_new("NIC No : ");
	wrkui->nicNo_txt = gtk_entry_new(); 

	wrkui->phoneNo_label = gtk_label_new("Phone No : ");
	wrkui->phoneNo_txt = gtk_entry_new(); 

	wrkui->joinDate_label = gtk_label_new("Joined Date : ");
	wrkui->joinDate_txt = gtk_entry_new(); 

	gtk_misc_set_alignment (GTK_MISC (wrkui->name_label), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (wrkui->address_label), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (wrkui->city_label), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (wrkui->nicNo_label), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (wrkui->phoneNo_label), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (wrkui->joinDate_label), 1, 0.5);

	/*gtk_table_attach_defaults(GTK_TABLE(layout), name_label,0, 1, 0, 1);
	  gtk_table_attach_defaults(GTK_TABLE(layout), name_txt, 1, 2, 0, 1);
	  gtk_table_attach_defaults(GTK_TABLE(layout), address_label, 0, 1, 1, 2);
	  gtk_table_attach_defaults(GTK_TABLE(layout), address_txt, 1, 2, 1, 2);
	  gtk_table_attach_defaults(GTK_TABLE(layout), nicNo_label, 0, 1, 2, 3);
	  gtk_table_attach_defaults(GTK_TABLE(layout), nicNo_txt, 1, 2, 2, 3);
	  gtk_table_attach_defaults(GTK_TABLE(layout), phoneNo_label, 0, 1, 3, 4);
	  gtk_table_attach_defaults(GTK_TABLE(layout), phoneNo_txt, 1, 2, 3, 4);
	  gtk_table_attach_defaults(GTK_TABLE(layout), joinDate_label, 0, 1, 4, 5);
	  gtk_table_attach_defaults(GTK_TABLE(layout), joinDate_txt, 1, 2, 4, 5);*/

	gtk_table_attach (GTK_TABLE(wrkui->layout), wrkui->name_label,0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(wrkui->layout), wrkui->name_txt, 1, 2, 0, 1);

	gtk_table_attach (GTK_TABLE(wrkui->layout), wrkui->address_label, 0, 1, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(wrkui->layout), wrkui->address_txt, 1, 2, 1, 2);

	gtk_table_attach (GTK_TABLE(wrkui->layout), wrkui->city_label, 0, 1, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(wrkui->layout), wrkui->city_txt, 1, 2, 2, 3);

	gtk_table_attach (GTK_TABLE(wrkui->layout), wrkui->nicNo_label, 0, 1, 3, 4, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(wrkui->layout), wrkui->nicNo_txt, 1, 2, 3, 4);

	gtk_table_attach (GTK_TABLE(wrkui->layout), wrkui->phoneNo_label, 0, 1, 4, 5, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(wrkui->layout), wrkui->phoneNo_txt, 1, 2, 4, 5);

	gtk_table_attach (GTK_TABLE(wrkui->layout), wrkui->joinDate_label, 0, 1, 5, 6, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(wrkui->layout), wrkui->joinDate_txt, 1, 2, 5, 6);

	//gtk_box_pack_start(GTK_BOX(vbox), layout, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(wrkui->vbox), wrkui->layout, FALSE, FALSE, 0);
	/////////

	////////////////////

	wrkui->hbox = gtk_hbox_new (FALSE, 5);
	wrkui->clear_button = gtk_button_new_with_label ("Clear");
	gtk_widget_set_size_request (wrkui->clear_button, 100, 30);
	wrkui->ok_button = gtk_button_new_with_label ("Ok");
	gtk_widget_set_size_request (wrkui->ok_button, 100, 30);
	wrkui->cancel_button = gtk_button_new_with_label ("Cancel");
	gtk_widget_set_size_request (wrkui->cancel_button, 100, 30);

	gtk_box_pack_start(GTK_BOX(wrkui->hbox), wrkui->clear_button, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(wrkui->hbox), wrkui->cancel_button, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(wrkui->hbox), wrkui->ok_button, FALSE, FALSE, 0);

	gtk_box_pack_end(GTK_BOX(wrkui->vbox), wrkui->hbox, FALSE, FALSE, 0);


	////////////////////
	g_signal_connect_swapped(G_OBJECT(wrkui->window), "destroy",
			G_CALLBACK(gtk_widget_destroy), G_OBJECT(wrkui->window));

	g_signal_connect_swapped(G_OBJECT(wrkui->ok_button), "clicked",
			G_CALLBACK(ok_button_clicked), G_OBJECT(wrkui->window));

	g_signal_connect_swapped(G_OBJECT(wrkui->clear_button), "clicked",
			G_CALLBACK(clear_button_clicked), G_OBJECT(wrkui->window));

	g_signal_connect_swapped(G_OBJECT(wrkui->cancel_button), "clicked",
			G_CALLBACK(cancel_button_clicked), G_OBJECT(wrkui->window));

	gtk_window_set_modal (GTK_WINDOW(wrkui->window), TRUE);

	gtk_widget_show_all(wrkui->window);

	return wrkui;
}

