#include "bill_ui.h"

      


void create_bill_window (){

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 270);
  gtk_window_set_title(GTK_WINDOW(window), "Bill");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  vbox = gtk_vbox_new(FALSE, 1);  // hama kotuwakma 1ka =i ,true dapuwama
  gtk_box_set_spacing (GTK_BOX(vbox), 5);
  gtk_container_add(GTK_CONTAINER(window), vbox);

        header_label = gtk_label_new("Bill");
        gtk_box_pack_start(GTK_BOX(vbox), header_label, FALSE, FALSE, 0);//
/////////
        layout = gtk_table_new(6, 2, FALSE);//
        gtk_table_set_row_spacings(GTK_TABLE(layout), 5);
 	gtk_table_set_col_spacings(GTK_TABLE(layout), 5);

	job_bill_id_label = gtk_label_new("Bill ID : ");
        job_bill_id_txt = gtk_entry_new(); 

        date_label = gtk_label_new("Date : ");
        date_txt = gtk_entry_new(); 

        bus_reg_no_label = gtk_label_new("Bus RegNo : ");
        bus_reg_no_txt = gtk_entry_new();

        maintenance_discription_label = gtk_label_new("Maintenance Discription : ");
        maintenance_discription_txt = gtk_entry_new();


        total_label = gtk_label_new("Total : ");
        total_txt = gtk_entry_new(); 

        who_signed_label = gtk_label_new("Signed By : ");
        who_signed_txt = gtk_entry_new(); 


gtk_misc_set_alignment (GTK_MISC (job_bill_id_label), 1, 0.5);
gtk_misc_set_alignment (GTK_MISC (date_label), 1, 0.5);
gtk_misc_set_alignment (GTK_MISC (bus_reg_no_label), 1, 0.5);
gtk_misc_set_alignment (GTK_MISC (maintenance_discription_label), 1, 0.5);
gtk_misc_set_alignment (GTK_MISC (total_label), 1, 0.5);
gtk_misc_set_alignment (GTK_MISC (who_signed_label), 1, 0.5);


gtk_table_attach (GTK_TABLE(layout), job_bill_id_label,0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
gtk_table_attach_defaults (GTK_TABLE(layout), job_bill_id_txt, 1, 2, 0, 1);

gtk_table_attach (GTK_TABLE(layout), date_label, 0, 1, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
gtk_table_attach_defaults (GTK_TABLE(layout), date_txt, 1, 2, 1, 2);

gtk_table_attach (GTK_TABLE(layout), bus_reg_no_label, 0, 1, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
gtk_table_attach_defaults (GTK_TABLE(layout), bus_reg_no_txt, 1, 2, 2, 3);

gtk_table_attach (GTK_TABLE(layout), maintenance_discription_label, 0, 1, 3, 4, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
gtk_table_attach_defaults (GTK_TABLE(layout), maintenance_discription_txt, 1, 2, 3, 4);

gtk_table_attach (GTK_TABLE(layout), total_label, 0, 1, 4, 5, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
gtk_table_attach_defaults (GTK_TABLE(layout), total_txt, 1, 2, 4, 5);

gtk_table_attach (GTK_TABLE(layout), who_signed_label, 0, 1, 5, 6, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
gtk_table_attach_defaults (GTK_TABLE(layout), who_signed_txt, 1, 2, 5, 6);



//gtk_box_pack_start(GTK_BOX(vbox), layout, TRUE, TRUE, 0);

gtk_box_pack_start(GTK_BOX(vbox), layout, FALSE, FALSE, 0);
/////////

////////////////////

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


////////////////////
        g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);

  //gtk_main();

  //return 0;
}

