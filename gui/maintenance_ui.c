#include <gtk/gtk.h>
#include <stdlib.h>
#include "maintenance_ui.h"

mnt_ui * create_maintenance_window ()
{
	mntui = malloc (sizeof(mnt_ui));

	mntui->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(mntui->window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(mntui->window), "New Maintenance");
	gtk_window_set_default_size(GTK_WINDOW(mntui->window), 500, 400);
	gtk_container_set_border_width(GTK_CONTAINER(mntui->window), 10);
	mntui->vbox = gtk_vbox_new (FALSE, 5);
	gtk_container_add (GTK_CONTAINER(mntui->window), mntui->vbox);

	mntui->title = gtk_label_new ("New Maintenance");
	gtk_box_pack_start (GTK_BOX(mntui->vbox), mntui->title, FALSE, FALSE, 0);

	mntui->top_table = gtk_table_new (10, 4, FALSE);
	gtk_table_set_row_spacings(GTK_TABLE(mntui->top_table), 5);
	gtk_table_set_col_spacings(GTK_TABLE(mntui->top_table), 5);

	mntui->lbusregno = gtk_label_new ("Bus Reg. No : ");
	mntui->lbusmodel = gtk_label_new ("Model : ");
	mntui->lbusdriver = gtk_label_new ("Driver : ");
	mntui->lowner = gtk_label_new ("Owner Name : ");
	mntui->ldate = gtk_label_new ("Date : ");

	mntui->tbusregno = gtk_entry_new ();
	mntui->tbusmodel = gtk_entry_new ();
	mntui->tbusdriver = gtk_entry_new ();
	mntui->towner = gtk_entry_new ();
	mntui->tdate = gtk_entry_new ();
	mntui->date_hbox = gtk_hbox_new (FALSE, 5);
	mntui->date_btn = gtk_button_new_with_label ("T");
	gtk_widget_set_size_request (mntui->date_btn, 30, 30);

	gtk_box_pack_start (GTK_BOX(mntui->date_hbox), mntui->tdate, TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX(mntui->date_hbox), mntui->date_btn, FALSE, FALSE, 0);

	gtk_table_attach (GTK_TABLE(mntui->top_table), mntui->lbusregno, 0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(mntui->top_table), mntui->tbusregno, 1, 2, 0, 1);
	gtk_table_attach (GTK_TABLE(mntui->top_table), mntui->lbusmodel, 0, 1, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(mntui->top_table), mntui->tbusmodel, 1, 2, 1, 2);
	gtk_table_attach (GTK_TABLE(mntui->top_table), mntui->lbusdriver, 0, 1, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(mntui->top_table), mntui->tbusdriver, 1, 2, 2, 3);
	gtk_table_attach (GTK_TABLE(mntui->top_table), mntui->lowner, 2, 3, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(mntui->top_table), mntui->towner, 3, 4, 0, 1);
	gtk_table_attach (GTK_TABLE(mntui->top_table), mntui->ldate, 2, 3, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(mntui->top_table), mntui->date_hbox, 3, 4, 1, 2);

	mntui->lpack = gtk_label_new ("Package : ");
	mntui->combopack = gtk_combo_box_new_text ();
	mntui->addpack = gtk_button_new_with_label ("Add to List");
	mntui->lcustompack = gtk_label_new ("Custom Pack. : ");
	mntui->tcustompack = gtk_text_view_new();
	mntui->addcustompack = gtk_button_new_with_label ("Add to List");

	//gtk_widget_set_size_request (addpack, 100, 30);
	//gtk_widget_set_size_request (addcustompack, 100, 30);

	mntui->sw = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(mntui->sw),
            GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(mntui->sw),
            GTK_SHADOW_IN);  
	gtk_container_add(GTK_CONTAINER (mntui->sw), mntui->tcustompack);

	gtk_table_attach (GTK_TABLE(mntui->top_table), mntui->lpack, 0, 1, 3, 4, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(mntui->top_table), mntui->combopack, 1, 2, 3, 4);
	gtk_table_attach_defaults (GTK_TABLE(mntui->top_table), mntui->addpack, 1, 2, 4, 5);
	gtk_table_attach (GTK_TABLE(mntui->top_table), mntui->lcustompack, 0, 1, 5, 6, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(mntui->top_table), mntui->sw, 1, 2, 5, 7);
	gtk_table_attach_defaults (GTK_TABLE(mntui->top_table), mntui->addcustompack, 1, 2, 7, 10);

	//
	mntui->list = gtk_tree_view_new();
  	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(mntui->list), FALSE);

	GtkCellRenderer *renderer;
  	GtkTreeViewColumn *column;
  	GtkListStore *store;

  	renderer = gtk_cell_renderer_text_new();
  	column = gtk_tree_view_column_new_with_attributes("List Items",
    	renderer, "text", 0, NULL);
  	gtk_tree_view_append_column(GTK_TREE_VIEW(mntui->list), column);

  	store = gtk_list_store_new(1, G_TYPE_STRING);

  	gtk_tree_view_set_model(GTK_TREE_VIEW(mntui->list), 
  	    GTK_TREE_MODEL(store));

  	g_object_unref(store);
	
	mntui->listbase = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(mntui->listbase),
            GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(mntui->listbase),
            GTK_SHADOW_IN);  
	gtk_container_add(GTK_CONTAINER (mntui->listbase), mntui->list);
	gtk_table_attach_defaults (GTK_TABLE(mntui->top_table), mntui->listbase, 2, 4, 4, 10);
	//

	gtk_box_pack_start (GTK_BOX(mntui->vbox), mntui->top_table, FALSE, FALSE, 0);

	mntui->ok = gtk_button_new_with_label (" OK ");
	gtk_widget_set_size_request (mntui->ok, 100, 30);
	mntui->clear = gtk_button_new_with_label (" Clear ");
	gtk_widget_set_size_request (mntui->clear, 100, 30);
	mntui->cancel = gtk_button_new_with_label (" Cancel ");
	gtk_widget_set_size_request (mntui->cancel, 100, 30);

	mntui->btn_hbox = gtk_hbox_new (FALSE, 5);
	gtk_box_pack_start (GTK_BOX(mntui->btn_hbox), mntui->clear, FALSE, FALSE, 0);
	gtk_box_pack_end (GTK_BOX(mntui->btn_hbox), mntui->cancel, FALSE, FALSE, 0);
	gtk_box_pack_end (GTK_BOX(mntui->btn_hbox), mntui->ok, FALSE, FALSE, 0);

	gtk_box_pack_end (GTK_BOX(mntui->vbox), mntui->btn_hbox, FALSE, FALSE, 0);

	g_signal_connect_swapped (G_OBJECT(mntui->window), "destroy",
        G_CALLBACK(gtk_widget_destroy), G_OBJECT(mntui->window));

	gtk_window_set_modal (GTK_WINDOW(mntui->window), TRUE);

	gtk_widget_show_all (mntui->window);

	return mntui;
}
