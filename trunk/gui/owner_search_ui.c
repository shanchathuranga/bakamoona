#include "owner_search_ui.h"

void add_data (GtkWidget * list, char * name, char * age)
{
    GtkListStore *store;
    GtkTreeIter iter;

    store = GTK_LIST_STORE(gtk_tree_view_get_model
            (GTK_TREE_VIEW(list)));

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, COL_NAME, name, COL_REG_NO, age, -1);
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

    col = gtk_tree_view_column_new(); // Name

    gtk_tree_view_column_set_title(col, "Name");
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_column_pack_start(col, renderer, TRUE);
    gtk_tree_view_column_add_attribute(col, renderer, "text", COL_NAME);

    col = gtk_tree_view_column_new(); // Reg No

    gtk_tree_view_column_set_title(col, "Reg No");
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_column_pack_start(col, renderer, TRUE);
    gtk_tree_view_column_add_attribute(col, renderer, "text", COL_REG_NO);

    col = gtk_tree_view_column_new(); // phone 1

    gtk_tree_view_column_set_title(col, "Phone (1)");
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_column_pack_start(col, renderer, TRUE);
    gtk_tree_view_column_add_attribute(col, renderer, "text", COL_PHONE_1);

    col = gtk_tree_view_column_new(); // phone 2

    gtk_tree_view_column_set_title(col, "Phone (2)");
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_column_pack_start(col, renderer, TRUE);
    gtk_tree_view_column_add_attribute(col, renderer, "text", COL_PHONE_2);

    col = gtk_tree_view_column_new(); // address 1

    gtk_tree_view_column_set_title(col, "Address (1)");
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_column_pack_start(col, renderer, TRUE);
    gtk_tree_view_column_add_attribute(col, renderer, "text", COL_ADDRESS_1);

    col = gtk_tree_view_column_new(); // city 1

    gtk_tree_view_column_set_title(col, "City (1)");
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_column_pack_start(col, renderer, TRUE);
    gtk_tree_view_column_add_attribute(col, renderer, "text", COL_CITY_1);

    col = gtk_tree_view_column_new(); // address 2

    gtk_tree_view_column_set_title(col, "Address (2)");
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_column_pack_start(col, renderer, TRUE);
    gtk_tree_view_column_add_attribute(col, renderer, "text", COL_ADDRESS_2);

    col = gtk_tree_view_column_new(); // city 2

    gtk_tree_view_column_set_title(col, "City (2)");
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_column_pack_start(col, renderer, TRUE);
    gtk_tree_view_column_add_attribute(col, renderer, "text", COL_CITY_2);

    col = gtk_tree_view_column_new(); // email

    gtk_tree_view_column_set_title(col, "Email");
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);
    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_column_pack_start(col, renderer, TRUE);
    gtk_tree_view_column_add_attribute(col, renderer, "text", COL_EMAIL);

    store = gtk_list_store_new(COL_COUNT, 
        G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
        G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
        G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
    g_object_unref(store); 

    gtk_tree_selection_set_mode(gtk_tree_view_get_selection(
                GTK_TREE_VIEW(list)), GTK_SELECTION_SINGLE);

    return list;
}

owner_search_ui * create_owner_search_window ()
{
    ow_search_ui = malloc (sizeof(owner_search_ui));

    ow_search_ui->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width(GTK_CONTAINER(ow_search_ui->window), 10);

    ow_search_ui->vbox = gtk_vbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(ow_search_ui->window), ow_search_ui->vbox);

    ow_search_ui->title = gtk_label_new ("Owners");
    gtk_box_pack_start (GTK_BOX(ow_search_ui->vbox), ow_search_ui->title, FALSE, FALSE, 0);
    
    ow_search_ui->filter_by = gtk_label_new ("Filter By : ");
    ow_search_ui->filter_combo = gtk_combo_box_new_text ();

    gtk_combo_box_append_text (GTK_COMBO_BOX(ow_search_ui->filter_combo), "--- No Filter ---");
    gtk_combo_box_append_text (GTK_COMBO_BOX(ow_search_ui->filter_combo), "Name");
    gtk_combo_box_append_text (GTK_COMBO_BOX(ow_search_ui->filter_combo), "Reg No");
    gtk_combo_box_append_text (GTK_COMBO_BOX(ow_search_ui->filter_combo), "Phone (1)");
    gtk_combo_box_append_text (GTK_COMBO_BOX(ow_search_ui->filter_combo), "Phone (2)");
    gtk_combo_box_append_text (GTK_COMBO_BOX(ow_search_ui->filter_combo), "Address (1)");
    gtk_combo_box_append_text (GTK_COMBO_BOX(ow_search_ui->filter_combo), "City (1)");
    gtk_combo_box_append_text (GTK_COMBO_BOX(ow_search_ui->filter_combo), "Address (2)");
    gtk_combo_box_append_text (GTK_COMBO_BOX(ow_search_ui->filter_combo), "City (2)");
    gtk_combo_box_append_text (GTK_COMBO_BOX(ow_search_ui->filter_combo), "Email");

    gtk_combo_box_set_active (GTK_COMBO_BOX(ow_search_ui->filter_combo), 0);

    ow_search_ui->filter_lbl = gtk_label_new ("Filter Text : ");
    ow_search_ui->filter_txt = gtk_entry_new ();

    ow_search_ui->filter_box = gtk_hbox_new (FALSE, 5);
    gtk_box_pack_start (GTK_BOX(ow_search_ui->filter_box), ow_search_ui->filter_by, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX(ow_search_ui->filter_box), ow_search_ui->filter_combo, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX(ow_search_ui->filter_box), ow_search_ui->filter_lbl, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX(ow_search_ui->filter_box), ow_search_ui->filter_txt, TRUE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX(ow_search_ui->vbox), ow_search_ui->filter_box, FALSE, FALSE, 0);

    ow_search_ui->sw = gtk_scrolled_window_new (NULL, NULL);
    gtk_widget_set_size_request (ow_search_ui->sw, 600, 400);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(ow_search_ui->sw),
            GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(ow_search_ui->sw),
            GTK_SHADOW_IN);    

    GtkWidget * list = create_view ();

    add_data (list, "Ashan", "25");
    add_data (list, "kamal", "54");
    add_data (list, "saman", "34");
    add_data (list, "Nimal", "25");
    add_data (list, "Amal", "25");
    add_data (list, "Kumara", "25");
    add_data (list, "Nimal", "25");
    add_data (list, "Nimal", "25");
    add_data (list, "Nimal", "25");
    add_data (list, "Nimal", "25");

    gtk_container_add(GTK_CONTAINER (ow_search_ui->sw), list);
    gtk_box_pack_start(GTK_BOX(ow_search_ui->vbox), ow_search_ui->sw, FALSE, FALSE, 0);

    ow_search_ui->hbox = gtk_hbox_new (FALSE, 5);
    ow_search_ui->refresh = gtk_button_new_with_label ("Refresh");
    gtk_widget_set_size_request (ow_search_ui->refresh, 100, 30);
    ow_search_ui->select = gtk_button_new_with_label ("Select");
    gtk_widget_set_size_request (ow_search_ui->select, 100, 30);
    ow_search_ui->cancel = gtk_button_new_with_label ("Cancel");
    gtk_widget_set_size_request (ow_search_ui->cancel, 100, 30);

    gtk_box_pack_start (GTK_BOX(ow_search_ui->hbox), ow_search_ui->refresh, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX(ow_search_ui->hbox), ow_search_ui->cancel, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX(ow_search_ui->hbox), ow_search_ui->select, FALSE, FALSE, 0);

    gtk_box_pack_end (GTK_BOX(ow_search_ui->vbox), ow_search_ui->hbox, FALSE, FALSE, 0);

    gtk_widget_show_all(ow_search_ui->window);

    g_signal_connect_swapped (G_OBJECT(ow_search_ui->window), "destroy",
            G_CALLBACK(gtk_widget_destroy), ow_search_ui->window);

    return ow_search_ui;
}
