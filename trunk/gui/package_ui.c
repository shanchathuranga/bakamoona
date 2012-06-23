#include "package_ui.h"

static void ok_button_clicked (GtkWidget * widget, gpointer data)
{
}

static void clear_button_clicked (GtkWidget * widget, gpointer data)
{
}

static void cancel_button_clicked (GtkWidget * widget, gpointer data)
{
}

static void init_list(GtkWidget *list)
{
  	GtkCellRenderer *renderer;
  	GtkTreeViewColumn *column;
  	GtkListStore *store;

  	renderer = gtk_cell_renderer_text_new();
  	column = gtk_tree_view_column_new_with_attributes("List Items",
    	renderer, "text", 0, NULL);
  	gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

  	store = gtk_list_store_new(1, G_TYPE_STRING);

  	gtk_tree_view_set_model(GTK_TREE_VIEW(list), 
      	GTK_TREE_MODEL(store));

  	g_object_unref(store);
}

static void add_to_list(GtkWidget *list, const gchar *str)
{
  	GtkListStore *store;
  	GtkTreeIter iter;

  	store = GTK_LIST_STORE(gtk_tree_view_get_model
      	(GTK_TREE_VIEW(list)));

  	gtk_list_store_append(store, &iter);
  	gtk_list_store_set(store, &iter, 0, str, -1);
}

void create_enter_package_window ()
{
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
	gtk_window_set_title(GTK_WINDOW(window), "Package Registration");
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	vbox = gtk_vbox_new(FALSE, 5);
	//gtk_box_set_spacing (GTK_BOX(vbox), 5);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	header_label = gtk_label_new("Package Registration");
	gtk_box_pack_start(GTK_BOX(vbox), header_label, FALSE, FALSE, 0);

	layout = gtk_table_new(3, 2, FALSE);
	gtk_table_set_row_spacings(GTK_TABLE(layout), 5);
	gtk_table_set_col_spacings(GTK_TABLE(layout), 5);

	package_code_label = gtk_label_new("Package Code : ");
	package_code_txt = gtk_entry_new(); 

	package_discription_label = gtk_label_new("Discription : ");
	package_discription_txt = gtk_entry_new();

	package_price_label = gtk_label_new("Unit Cost : ");
	package_price_txt = gtk_entry_new(); 

	gtk_misc_set_alignment (GTK_MISC (package_code_label), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (package_discription_label), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (package_price_label), 1, 0.5);

	gtk_table_attach (GTK_TABLE(layout), package_code_label,0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(layout), package_code_txt, 1, 2, 0, 1);

	gtk_table_attach (GTK_TABLE(layout), package_discription_label, 0, 1, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(layout), package_discription_txt, 1, 2, 1, 2);

	gtk_table_attach (GTK_TABLE(layout), package_price_label, 0, 1, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
	gtk_table_attach_defaults (GTK_TABLE(layout), package_price_txt, 1, 2, 2, 3);

	gtk_box_pack_start(GTK_BOX(vbox), layout, FALSE, FALSE, 0);

	itemframe = gtk_frame_new (" Package Items ");
    gtk_box_pack_start (GTK_BOX(vbox), itemframe, TRUE, TRUE, 0);

	pkghbox = gtk_hbox_new (FALSE, 5);
	gtk_container_add (GTK_CONTAINER(itemframe), pkghbox);
	gtk_container_set_border_width(GTK_CONTAINER(pkghbox), 8);

	pkglist = gtk_tree_view_new();
  	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(pkglist), FALSE);
	init_list(pkglist);

	sw = gtk_scrolled_window_new (NULL, NULL);
    //gtk_widget_set_size_request (sw, 600, 400);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(sw),
            GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(sw),
            GTK_SHADOW_IN);

	gtk_container_add(GTK_CONTAINER (sw), pkglist);
    gtk_box_pack_start(GTK_BOX(pkghbox), sw, TRUE, TRUE, 0);

	btnvbox = gtk_vbox_new (FALSE, 5);
	gtk_box_pack_start(GTK_BOX(pkghbox), btnvbox, FALSE, FALSE, 0);

	add_sp = gtk_button_new_with_label ("Add SparePart"); 
	add_custom = gtk_button_new_with_label ("Add Custom");
	delete_item = gtk_button_new_with_label ("Delete");

	gtk_box_pack_start(GTK_BOX(btnvbox), add_sp, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(btnvbox), add_custom, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(btnvbox), delete_item, FALSE, FALSE, 0);

	hbox = gtk_hbox_new (FALSE, 5);
	clear_button = gtk_button_new_with_label ("Clear");
	gtk_widget_set_size_request (clear_button, 100, 30);
	ok_button = gtk_button_new_with_label ("Ok");
	gtk_widget_set_size_request (ok_button, 100, 30);
	cancel_button = gtk_button_new_with_label ("Cancel");
	gtk_widget_set_size_request (cancel_button, 100, 30);

	gtk_box_pack_start(GTK_BOX(hbox), clear_button, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(hbox), cancel_button, FALSE, FALSE, 0);
	gtk_box_pack_end(GTK_BOX(hbox), ok_button, FALSE, FALSE, 0);

	gtk_box_pack_end(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

	g_signal_connect_swapped(G_OBJECT(window), "destroy",
			G_CALLBACK(gtk_widget_destroy), G_OBJECT(window));

	g_signal_connect (G_OBJECT(ok_button), "clicked",
		G_CALLBACK(ok_button_clicked), G_OBJECT(window));

	g_signal_connect (G_OBJECT(clear_button), "clicked",
		G_CALLBACK(clear_button_clicked), G_OBJECT(window));

	g_signal_connect (G_OBJECT(cancel_button), "clicked",
		G_CALLBACK(cancel_button_clicked), G_OBJECT(window));

	gtk_widget_show_all(window);

}

