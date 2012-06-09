#include "owner_reg.h"
#include "owner_ds.h"
#include <stdlib.h>
#include <string.h>

GtkWidget * window;
GtkWidget * title;
GtkWidget * vbox;
GtkWidget * hbox;
GtkWidget * hspace;
GtkWidget * table;
GtkWidget * clear;
GtkWidget * ok;
GtkWidget * cancel;
GtkWidget * lname, * tname;
GtkWidget * lregno, * tregno;
GtkWidget * lph1, * tph1;
GtkWidget * lph2, * tph2;
GtkWidget * laddress1, * taddress1;
GtkWidget * lcity1, * tcity1;
GtkWidget * laddress2, * taddress2;
GtkWidget * lcity2, * tcity2; 
GtkWidget * lemail, * temail;

void clear_fields ()
{
	gtk_entry_set_text(GTK_ENTRY(tname), "");
	gtk_entry_set_text(GTK_ENTRY(tregno), "");
	gtk_entry_set_text(GTK_ENTRY(tph1), "");
	gtk_entry_set_text(GTK_ENTRY(tph2), "");
	gtk_entry_set_text(GTK_ENTRY(taddress1), "");
	gtk_entry_set_text(GTK_ENTRY(tcity1), "");
	gtk_entry_set_text(GTK_ENTRY(taddress2), "");
	gtk_entry_set_text(GTK_ENTRY(tcity2), "");
}

void clear_button_clicked (GtkWidget * widget, gpointer data)
{
	clear_fields ();
}

void cancel_button_clicked (GtkWidget * widget, gpointer data)
{
	gtk_widget_destroy (window);
}

void ok_button_clicked (GtkWidget * widget, gpointer data)
{
	OWNER * owner = malloc (sizeof(OWNER));

	strcpy (owner->owner_name, gtk_entry_get_text(GTK_ENTRY(tname)));
	strcpy (owner->owner_reg_no, gtk_entry_get_text(GTK_ENTRY(tregno)));
	strcpy (owner->phone1, gtk_entry_get_text(GTK_ENTRY(tph1)));
	strcpy (owner->phone2, gtk_entry_get_text(GTK_ENTRY(tph2)));
	strcpy (owner->address1, gtk_entry_get_text(GTK_ENTRY(taddress1)));
	strcpy (owner->city1, gtk_entry_get_text(GTK_ENTRY(tcity1)));
	strcpy (owner->address2, gtk_entry_get_text(GTK_ENTRY(taddress2)));
	strcpy (owner->city2, gtk_entry_get_text(GTK_ENTRY(tcity2))); 
	strcpy (owner->email, gtk_entry_get_text(GTK_ENTRY(temail)));

	insert_owner (owner);

	clear_fields ();
}

GtkWidget * create_owner_reg_window ()
{
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), "Owner Registration");
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 370);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    vbox = gtk_vbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_box_set_spacing (GTK_BOX(vbox), 5);

    title = gtk_label_new ("Owner Registration");
    gtk_box_pack_start(GTK_BOX(vbox), title, FALSE, FALSE, 0);

    table = gtk_table_new (9, 2, FALSE);
	gtk_table_set_row_spacings(GTK_TABLE(table), 5);
 	gtk_table_set_col_spacings(GTK_TABLE(table), 5);

    lname = gtk_label_new ("Name : ");
    lregno = gtk_label_new ("NIC / Reg No : ");
    lph1 = gtk_label_new ("Phone (1) : ");
    lph2 = gtk_label_new ("Phone (2) : ");
    laddress1 = gtk_label_new ("Address (1) : ");
    lcity1 = gtk_label_new ("City (1) : ");
    laddress2 = gtk_label_new ("Address (2) : ");
    lcity2 = gtk_label_new ("City (2) : ");
	lemail = gtk_label_new ("Email : ");

    gtk_misc_set_alignment (GTK_MISC (lname), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (lregno), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (lph1), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (lph2), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (laddress1), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (laddress2), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (lcity1), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (lcity2), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (lemail), 1, 0.5);
    
    tname = gtk_entry_new();
    tregno = gtk_entry_new();
    tph1 = gtk_entry_new();
    tph2 = gtk_entry_new();
    taddress1 = gtk_entry_new();
    tcity1 = gtk_entry_new();
    taddress2 = gtk_entry_new();
    tcity2 = gtk_entry_new();
	temail = gtk_entry_new();

    gtk_table_attach (GTK_TABLE(table), lname, 0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(table), tname, 1, 2, 0, 1);
    gtk_table_attach (GTK_TABLE(table), lregno, 0, 1, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(table), tregno, 1, 2, 1, 2);
    gtk_table_attach (GTK_TABLE(table), lph1, 0, 1, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach (GTK_TABLE(table), tph1, 1, 2, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_SHRINK), 0, 0);
    gtk_widget_set_size_request (tph1, 150, 28);
    gtk_table_attach (GTK_TABLE(table), lph2, 0, 1, 3, 4, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(table), tph2, 1, 2, 3, 4);
    gtk_table_attach (GTK_TABLE(table), laddress1, 0, 1, 4, 5, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(table), taddress1, 1, 2, 4, 5);
    gtk_table_attach (GTK_TABLE(table), lcity1, 0, 1, 5, 6, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(table), tcity1, 1, 2, 5, 6);
    gtk_table_attach (GTK_TABLE(table), laddress2, 0, 1, 6, 7, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(table), taddress2, 1, 2, 6, 7);
    gtk_table_attach (GTK_TABLE(table), lcity2, 0, 1, 7, 8, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(table), tcity2, 1, 2, 7, 8);
	gtk_table_attach (GTK_TABLE(table), lemail, 0, 1, 8, 9, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(table), temail, 1, 2, 8, 9);
    
    gtk_box_pack_start(GTK_BOX(vbox), table, FALSE, FALSE, 0);
        
    hbox = gtk_hbox_new (FALSE, 5);
    clear = gtk_button_new_with_label ("Clear");
	gtk_widget_set_size_request (clear, 100, 30);
	ok = gtk_button_new_with_label ("OK");
	gtk_widget_set_size_request (ok, 100, 30);
    cancel = gtk_button_new_with_label ("Cancel");
	gtk_widget_set_size_request (cancel, 100, 30);

	gtk_box_pack_start(GTK_BOX(hbox), clear, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(hbox), cancel, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(hbox), ok, FALSE, FALSE, 0);

    gtk_box_pack_end(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

    g_signal_connect_swapped (G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_widget_destroy), G_OBJECT(window));

	g_signal_connect (G_OBJECT(ok), "clicked",
		G_CALLBACK(ok_button_clicked), G_OBJECT(window));

	g_signal_connect (G_OBJECT(clear), "clicked",
		G_CALLBACK(clear_button_clicked), G_OBJECT(window));

	g_signal_connect (G_OBJECT(cancel), "clicked",
		G_CALLBACK(cancel_button_clicked), G_OBJECT(window));
    
    gtk_widget_show_all (window);
    
    return window;
}
