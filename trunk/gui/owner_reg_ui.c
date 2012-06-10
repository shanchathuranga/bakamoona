#include "owner_reg_ui.h"
#include "owner.h"
#include <stdlib.h>
#include <string.h>

static void clear_fields ()
{
	gtk_entry_set_text(GTK_ENTRY(ownui->tname), "");
	gtk_entry_set_text(GTK_ENTRY(ownui->tregno), "");
	gtk_entry_set_text(GTK_ENTRY(ownui->tph1), "");
	gtk_entry_set_text(GTK_ENTRY(ownui->tph2), "");
	gtk_entry_set_text(GTK_ENTRY(ownui->taddress1), "");
	gtk_entry_set_text(GTK_ENTRY(ownui->tcity1), "");
	gtk_entry_set_text(GTK_ENTRY(ownui->taddress2), "");
	gtk_entry_set_text(GTK_ENTRY(ownui->tcity2), "");
}

static void clear_button_clicked (GtkWidget * widget, gpointer data)
{
	clear_fields ();
}

static void cancel_button_clicked (GtkWidget * widget, gpointer data)
{
	gtk_widget_destroy (ownui->window);
}

static void ok_button_clicked (GtkWidget * widget, gpointer data)
{
	OWNER * owner = malloc (sizeof(OWNER));

	strcpy (owner->owner_name, gtk_entry_get_text(GTK_ENTRY(ownui->tname)));
	strcpy (owner->owner_reg_no, gtk_entry_get_text(GTK_ENTRY(ownui->tregno)));
	strcpy (owner->phone1, gtk_entry_get_text(GTK_ENTRY(ownui->tph1)));
	strcpy (owner->phone2, gtk_entry_get_text(GTK_ENTRY(ownui->tph2)));
	strcpy (owner->address1, gtk_entry_get_text(GTK_ENTRY(ownui->taddress1)));
	strcpy (owner->city1, gtk_entry_get_text(GTK_ENTRY(ownui->tcity1)));
	strcpy (owner->address2, gtk_entry_get_text(GTK_ENTRY(ownui->taddress2)));
	strcpy (owner->city2, gtk_entry_get_text(GTK_ENTRY(ownui->tcity2))); 
	strcpy (owner->email, gtk_entry_get_text(GTK_ENTRY(ownui->temail)));

	insert_owner (owner);

	clear_fields ();
}

owner_ui * create_owner_reg_window ()
{
	ownui = malloc (sizeof(owner_ui));
	
    ownui->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(ownui->window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(ownui->window), "Owner Registration");
	gtk_window_set_default_size(GTK_WINDOW(ownui->window), 500, 370);
    gtk_container_set_border_width(GTK_CONTAINER(ownui->window), 10);

    ownui->vbox = gtk_vbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(ownui->window), ownui->vbox);
	gtk_box_set_spacing (GTK_BOX(ownui->vbox), 5);

    ownui->title = gtk_label_new ("Owner Registration");
    gtk_box_pack_start(GTK_BOX(ownui->vbox), ownui->title, FALSE, FALSE, 0);

    ownui->table = gtk_table_new (9, 2, FALSE);
	gtk_table_set_row_spacings(GTK_TABLE(ownui->table), 5);
 	gtk_table_set_col_spacings(GTK_TABLE(ownui->table), 5);

    ownui->lname = gtk_label_new ("Name : ");
    ownui->lregno = gtk_label_new ("NIC / Reg No : ");
    ownui->lph1 = gtk_label_new ("Phone (1) : ");
    ownui->lph2 = gtk_label_new ("Phone (2) : ");
    ownui->laddress1 = gtk_label_new ("Address (1) : ");
    ownui->lcity1 = gtk_label_new ("City (1) : ");
    ownui->laddress2 = gtk_label_new ("Address (2) : ");
    ownui->lcity2 = gtk_label_new ("City (2) : ");
	ownui->lemail = gtk_label_new ("Email : ");

    gtk_misc_set_alignment (GTK_MISC (ownui->lname), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (ownui->lregno), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (ownui->lph1), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (ownui->lph2), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (ownui->laddress1), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (ownui->laddress2), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (ownui->lcity1), 1, 0.5);
    gtk_misc_set_alignment (GTK_MISC (ownui->lcity2), 1, 0.5);
	gtk_misc_set_alignment (GTK_MISC (ownui->lemail), 1, 0.5);
    
    ownui->tname = gtk_entry_new();
    ownui->tregno = gtk_entry_new();
    ownui->tph1 = gtk_entry_new();
    ownui->tph2 = gtk_entry_new();
    ownui->taddress1 = gtk_entry_new();
    ownui->tcity1 = gtk_entry_new();
    ownui->taddress2 = gtk_entry_new();
    ownui->tcity2 = gtk_entry_new();
	ownui->temail = gtk_entry_new();

    gtk_table_attach (GTK_TABLE(ownui->table), ownui->lname, 0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(ownui->table), ownui->tname, 1, 2, 0, 1);
    gtk_table_attach (GTK_TABLE(ownui->table), ownui->lregno, 0, 1, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(ownui->table), ownui->tregno, 1, 2, 1, 2);
    gtk_table_attach (GTK_TABLE(ownui->table), ownui->lph1, 0, 1, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach (GTK_TABLE(ownui->table), ownui->tph1, 1, 2, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (GTK_SHRINK), 0, 0);
    gtk_widget_set_size_request (ownui->tph1, 150, 28);
    gtk_table_attach (GTK_TABLE(ownui->table), ownui->lph2, 0, 1, 3, 4, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(ownui->table), ownui->tph2, 1, 2, 3, 4);
    gtk_table_attach (GTK_TABLE(ownui->table), ownui->laddress1, 0, 1, 4, 5, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(ownui->table), ownui->taddress1, 1, 2, 4, 5);
    gtk_table_attach (GTK_TABLE(ownui->table), ownui->lcity1, 0, 1, 5, 6, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(ownui->table), ownui->tcity1, 1, 2, 5, 6);
    gtk_table_attach (GTK_TABLE(ownui->table), ownui->laddress2, 0, 1, 6, 7, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(ownui->table), ownui->taddress2, 1, 2, 6, 7);
    gtk_table_attach (GTK_TABLE(ownui->table), ownui->lcity2, 0, 1, 7, 8, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(ownui->table), ownui->tcity2, 1, 2, 7, 8);
	gtk_table_attach (GTK_TABLE(ownui->table), ownui->lemail, 0, 1, 8, 9, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
    gtk_table_attach_defaults (GTK_TABLE(ownui->table), ownui->temail, 1, 2, 8, 9);
    
    gtk_box_pack_start(GTK_BOX(ownui->vbox), ownui->table, FALSE, FALSE, 0);
        
    ownui->hbox = gtk_hbox_new (FALSE, 5);
    ownui->clear = gtk_button_new_with_label ("Clear");
	gtk_widget_set_size_request (ownui->clear, 100, 30);
	ownui->ok = gtk_button_new_with_label ("OK");
	gtk_widget_set_size_request (ownui->ok, 100, 30);
    ownui->cancel = gtk_button_new_with_label ("Cancel");
	gtk_widget_set_size_request (ownui->cancel, 100, 30);

	gtk_box_pack_start(GTK_BOX(ownui->hbox), ownui->clear, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(ownui->hbox), ownui->cancel, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(ownui->hbox), ownui->ok, FALSE, FALSE, 0);

    gtk_box_pack_end(GTK_BOX(ownui->vbox), ownui->hbox, FALSE, FALSE, 0);

    g_signal_connect_swapped (G_OBJECT(ownui->window), "destroy",
        G_CALLBACK(gtk_widget_destroy), G_OBJECT(ownui->window));

	g_signal_connect (G_OBJECT(ownui->ok), "clicked",
		G_CALLBACK(ok_button_clicked), G_OBJECT(ownui->window));

	g_signal_connect (G_OBJECT(ownui->clear), "clicked",
		G_CALLBACK(clear_button_clicked), G_OBJECT(ownui->window));

	g_signal_connect (G_OBJECT(ownui->cancel), "clicked",
		G_CALLBACK(cancel_button_clicked), G_OBJECT(ownui->window));
    
    gtk_widget_show_all (ownui->window);
    
    return ownui;
}
