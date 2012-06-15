#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *vbox;
GtkWidget *sw;

enum
{
	NAME = 0,
	AGE,
	COUNT
};

void add_data (GtkWidget * list, char * name, char * age)
{
	GtkListStore *store;
  	GtkTreeIter iter;

  	store = GTK_LIST_STORE(gtk_tree_view_get_model
      	(GTK_TREE_VIEW(list)));

  	gtk_list_store_append(store, &iter);
  	gtk_list_store_set(store, &iter, NAME, name, AGE, age, -1);
}

GtkWidget * create_view ()
{
	GtkWidget *list;
	GtkTreeViewColumn * col;
	GtkCellRenderer * renderer;
	GtkListStore *store;
	
	list = gtk_tree_view_new();
  	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list), TRUE);
	gtk_tree_view_set_rules_hint (GTK_TREE_VIEW(list), TRUE);

	col = gtk_tree_view_column_new();

  	gtk_tree_view_column_set_title(col, "Name");
  	gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
  	renderer = gtk_cell_renderer_text_new();
  	gtk_tree_view_column_pack_start(col, renderer, TRUE);
  	gtk_tree_view_column_add_attribute(col, renderer, "text", NAME);

  	col = gtk_tree_view_column_new();

  	gtk_tree_view_column_set_title(col, "Age");
  	gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
  	renderer = gtk_cell_renderer_text_new();
  	gtk_tree_view_column_pack_start(col, renderer, TRUE);
  	gtk_tree_view_column_add_attribute(col, renderer, "text",AGE);

	store = gtk_list_store_new(COUNT, G_TYPE_STRING, G_TYPE_STRING);

	gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
	g_object_unref(store); 

	gtk_tree_selection_set_mode(gtk_tree_view_get_selection(
		GTK_TREE_VIEW(list)), GTK_SELECTION_SINGLE);

	return list;
}

int main( int argc, char *argv[])
{
  	gtk_init(&argc, &argv);

  	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	sw = gtk_scrolled_window_new(NULL, NULL);
  	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(sw),
      	GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  	gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(sw),
      	GTK_SHADOW_IN);

  	vbox = gtk_vbox_new(FALSE, 5);

	GtkWidget * list = create_view ();

	add_data (list, "shan", "25");
	add_data (list, "kamal", "54");
	add_data (list, "saman", "34");
	add_data (list, "Nimal", "25");
	add_data (list, "Amal", "25");
	add_data (list, "Kumara", "25");
	add_data (list, "Nimal", "25");
	add_data (list, "Nimal", "25");
	add_data (list, "Nimal", "25");
	add_data (list, "Nimal", "25");
	
  	gtk_container_add(GTK_CONTAINER (sw), list);
	gtk_box_pack_start(GTK_BOX(vbox), sw, TRUE, TRUE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);
  	gtk_widget_show_all(window);
	
	g_signal_connect_swapped (G_OBJECT(window), "destroy",
		G_CALLBACK(gtk_main_quit), NULL);

  	gtk_main();

  	return 0;
}
