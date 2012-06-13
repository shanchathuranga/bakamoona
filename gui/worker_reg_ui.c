#include "worker_reg_ui.h"

      


//int main( int argc, char *argv[]){
  
   //gtk_init(&argc, &argv);
void create_worker_reg_window (){

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 270);
  gtk_window_set_title(GTK_WINDOW(window), "Worker Registration");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  vbox = gtk_vbox_new(FALSE, 1);  // hama kotuwakma 1ka =i ,true dapuwama
  gtk_box_set_spacing (GTK_BOX(vbox), 5);
  gtk_container_add(GTK_CONTAINER(window), vbox);

        header_label = gtk_label_new("Worker Registration");
        gtk_box_pack_start(GTK_BOX(vbox), header_label, FALSE, FALSE, 0);//
/////////
        layout = gtk_table_new(6, 2, FALSE);//
        gtk_table_set_row_spacings(GTK_TABLE(layout), 5);
 	gtk_table_set_col_spacings(GTK_TABLE(layout), 5);

	name_label = gtk_label_new("Name : ");
        name_txt = gtk_entry_new(); 

        address_label = gtk_label_new("Address : ");
        address_txt = gtk_entry_new(); 

        city_label = gtk_label_new("City : ");
        city_txt = gtk_entry_new(); 

        nicNo_label = gtk_label_new("Nic No : ");
        nicNo_txt = gtk_entry_new(); 

        phoneNo_label = gtk_label_new("Phone No : ");
        phoneNo_txt = gtk_entry_new(); 

        joinDate_label = gtk_label_new("Joined Date : ");
        joinDate_txt = gtk_entry_new(); 

gtk_misc_set_alignment (GTK_MISC (name_label), 1, 0.5);
gtk_misc_set_alignment (GTK_MISC (address_label), 1, 0.5);
gtk_misc_set_alignment (GTK_MISC (city_label), 1, 0.5);
gtk_misc_set_alignment (GTK_MISC (nicNo_label), 1, 0.5);
gtk_misc_set_alignment (GTK_MISC (phoneNo_label), 1, 0.5);
gtk_misc_set_alignment (GTK_MISC (joinDate_label), 1, 0.5);

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

gtk_table_attach (GTK_TABLE(layout), name_label,0, 1, 0, 1, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
gtk_table_attach_defaults (GTK_TABLE(layout), name_txt, 1, 2, 0, 1);

gtk_table_attach (GTK_TABLE(layout), address_label, 0, 1, 1, 2, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
gtk_table_attach_defaults (GTK_TABLE(layout), address_txt, 1, 2, 1, 2);

gtk_table_attach (GTK_TABLE(layout), city_label, 0, 1, 2, 3, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
gtk_table_attach_defaults (GTK_TABLE(layout), city_txt, 1, 2, 2, 3);

gtk_table_attach (GTK_TABLE(layout), nicNo_label, 0, 1, 3, 4, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
gtk_table_attach_defaults (GTK_TABLE(layout), nicNo_txt, 1, 2, 3, 4);

gtk_table_attach (GTK_TABLE(layout), phoneNo_label, 0, 1, 4, 5, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
gtk_table_attach_defaults (GTK_TABLE(layout), phoneNo_txt, 1, 2, 4, 5);

gtk_table_attach (GTK_TABLE(layout), joinDate_label, 0, 1, 5, 6, (GtkAttachOptions) (GTK_FILL), (GtkAttachOptions) (0), 0, 0);
gtk_table_attach_defaults (GTK_TABLE(layout), joinDate_txt, 1, 2, 5, 6);

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

