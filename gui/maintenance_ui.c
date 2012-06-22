#include "maintenance_ui.h"
#include "bus.h"
#include <glib.h>

static int selected_owner_id = 1;

static void ok_button_clicked (GtkWidget * widget, gpointer data)
{
}

static void clear_button_clicked (GtkWidget * widget, gpointer data)
{
}

static void populate_buses ()
{
	GtkTreeModel *store = gtk_combo_box_get_model( GTK_COMBO_BOX(select_bus) );
	gtk_list_store_clear( GTK_LIST_STORE( store ) );

	GSList * bus_list = get_bus_by_owner_id (selected_owner_id);
	GSList * bus_iter;

	for (bus_iter = bus_list; bus_iter; bus_iter = bus_iter->next)
	{
		BUS * bus = (BUS*)(bus_iter->data);
		gtk_combo_box_append_text (GTK_COMBO_BOX(select_bus), bus->bus_reg_no);
	}
	
	gtk_combo_box_set_active (GTK_COMBO_BOX(select_bus), 0);
}

static void select_owner_button_clicked (GtkWidget * widget, gpointer data)
{
	create_owner_search_window (tname, taddr, tcity, &selected_owner_id, &populate_buses);
}

static void cancel_button_clicked (GtkWidget * widget, gpointer data)
{
	gtk_widget_destroy (window);
}

void create_maintenance_window ()
{
 	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), "New Maintenance");
	gtk_window_set_default_size(GTK_WINDOW(window), 600, 500);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    GtkWidget * vbox = gtk_vbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    title = gtk_label_new ("New Maintenance");
    gtk_box_pack_start (GTK_BOX(vbox), title, FALSE, FALSE, 0);

    busframe = gtk_frame_new (" Bus Details ");
    gtk_box_pack_start (GTK_BOX(vbox), busframe, FALSE, FALSE, 0);

    bustable = gtk_table_new (4, 4, FALSE);
    gtk_table_set_row_spacings (GTK_TABLE(bustable), 5);
    gtk_table_set_col_spacings (GTK_TABLE(bustable), 5);
    gtk_container_set_border_width(GTK_CONTAINER(bustable), 5);
    gtk_container_add (GTK_CONTAINER(busframe), bustable);

    select_owner = gtk_button_new_with_label ("Select Owner");
    lname = gtk_label_new ("Name : ");
    laddr = gtk_label_new ("Address : ");
    lcity = gtk_label_new ("City : ");
    lcombo = gtk_label_new ("Bus Reg.No : ");
    ldriver = gtk_label_new ("Driver : ");
    lmodel = gtk_label_new ("Model : ");
    ldate = gtk_label_new ("Date : ");

	gtk_misc_set_alignment (GTK_MISC (lname), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (laddr), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (lcity), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (lcombo), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (ldriver), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (lmodel), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (ldate), 1, 0.5);

    gtk_table_attach_defaults (GTK_TABLE(bustable), select_owner, 0, 2, 0, 1);
    gtk_table_attach_defaults (GTK_TABLE(bustable), lname, 0, 1, 1, 2);
    gtk_table_attach_defaults (GTK_TABLE(bustable), laddr, 0, 1, 2, 3);
    gtk_table_attach_defaults (GTK_TABLE(bustable), lcity, 0, 1, 3, 4);
    gtk_table_attach_defaults (GTK_TABLE(bustable), lcombo, 2, 3, 0, 1);
    gtk_table_attach_defaults (GTK_TABLE(bustable), ldriver, 2, 3, 1, 2);
    gtk_table_attach_defaults (GTK_TABLE(bustable), lmodel, 2, 3, 2, 3);
    gtk_table_attach_defaults (GTK_TABLE(bustable), ldate, 2, 3, 3, 4);

    select_bus = gtk_combo_box_new_text ();
    tname = gtk_label_new ("");
    taddr = gtk_label_new ("");
    tcity = gtk_label_new ("");
	gtk_label_set_markup (GTK_LABEL(tname), "<i>--- Owner Name ---</i>");
	gtk_label_set_markup (GTK_LABEL(taddr), "<i>--- Owner Address ---</i>"); 
	gtk_label_set_markup (GTK_LABEL(tcity), "<i>--- Owner City ---</i>");
	gtk_misc_set_alignment (GTK_MISC (tname), 0, 0.5);
	gtk_misc_set_alignment (GTK_MISC (taddr), 0, 0.5);
	gtk_misc_set_alignment (GTK_MISC (tcity), 0, 0.5);
    tdriver = gtk_entry_new ();
    tmodel = gtk_entry_new ();
    tdate = gtk_entry_new ();

    gtk_table_attach_defaults (GTK_TABLE(bustable), select_bus, 3, 4, 0, 1);
    gtk_table_attach_defaults (GTK_TABLE(bustable), tname, 1, 2, 1, 2);
    gtk_table_attach_defaults (GTK_TABLE(bustable), taddr, 1, 2, 2, 3);
    gtk_table_attach_defaults (GTK_TABLE(bustable), tcity, 1, 2, 3, 4);
    gtk_table_attach_defaults (GTK_TABLE(bustable), tdriver, 3, 4, 1, 2);
    gtk_table_attach_defaults (GTK_TABLE(bustable), tmodel, 3, 4, 2, 3);
    gtk_table_attach_defaults (GTK_TABLE(bustable), tdate, 3, 4, 3, 4);

    pack_hbox = gtk_hbox_new (FALSE, 5);
    packframe = gtk_frame_new (" Packages ");
    itemframe = gtk_frame_new (" Spare Parts ");
    gtk_box_pack_start (GTK_BOX(pack_hbox), packframe, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX(pack_hbox), itemframe, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX(vbox), pack_hbox, TRUE, TRUE, 0);

    packvbox = gtk_vbox_new (FALSE, 5);
    gtk_container_set_border_width(GTK_CONTAINER(packvbox), 5);
    itemvbox = gtk_vbox_new (FALSE, 5);
    gtk_container_set_border_width(GTK_CONTAINER(itemvbox), 5);
    gtk_container_add(GTK_CONTAINER(packframe), packvbox);
    gtk_container_add(GTK_CONTAINER(itemframe), itemvbox);

    packselect = gtk_button_new_with_label ("Select");
    packcustom = gtk_button_new_with_label ("Custom");
    tmphbox = gtk_hbox_new (FALSE, 0);
    gtk_box_pack_start (GTK_BOX(tmphbox), packselect, TRUE, TRUE, 0);
    gtk_box_pack_end (GTK_BOX(tmphbox), packcustom, TRUE, TRUE, 0);
    packdelete = gtk_button_new_with_label ("Delete");
    gtk_box_pack_start (GTK_BOX(packvbox), tmphbox, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX(packvbox), packdelete, FALSE, FALSE, 0);

    itemselect = gtk_button_new_with_label ("Select");
    itemdelete = gtk_button_new_with_label ("Delete");
    gtk_box_pack_start (GTK_BOX(itemvbox), itemselect, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX(itemvbox), itemdelete, FALSE, FALSE, 0);

    btnbase = gtk_hbox_new (FALSE, 5);
    ok = gtk_button_new_with_label (" OK ");
    clear = gtk_button_new_with_label (" Clear ");
    cancel = gtk_button_new_with_label (" Cancel ");
	gtk_widget_set_size_request (clear, 100, 30);	
	gtk_widget_set_size_request (ok, 100, 30);
	gtk_widget_set_size_request (cancel, 100, 30);

    gtk_box_pack_start (GTK_BOX(btnbase), clear, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX(btnbase), cancel, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX(btnbase), ok, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX(vbox), btnbase, FALSE, FALSE, 0);

    g_signal_connect_swapped (G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_widget_destroy), G_OBJECT(window));

	g_signal_connect (G_OBJECT(ok), "clicked",
		G_CALLBACK(ok_button_clicked), G_OBJECT(window));

	g_signal_connect (G_OBJECT(clear), "clicked",
		G_CALLBACK(clear_button_clicked), G_OBJECT(window));

	g_signal_connect (G_OBJECT(cancel), "clicked",
		G_CALLBACK(cancel_button_clicked), G_OBJECT(window));

	g_signal_connect (G_OBJECT(select_owner), "clicked",
		G_CALLBACK(select_owner_button_clicked), G_OBJECT(window));

	gtk_window_set_modal (GTK_WINDOW(window), TRUE);
    
    gtk_widget_show_all (window);

}
