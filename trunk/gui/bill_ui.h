#ifndef _MAINWIN_H_
#define _MAINWIN_H_

#include <gtk/gtk.h>

       GtkWidget * window;
       GtkWidget * header_label;

       GtkWidget * maintenance_discription_label;
       GtkWidget * maintenance_discription_txt;
       GtkWidget * bus_reg_no_label;
       GtkWidget * bus_reg_no_txt;
       GtkWidget * job_bill_id_label;
       GtkWidget * job_bill_id_txt;
       GtkWidget * date_label;
       GtkWidget * date_txt;
       GtkWidget * total_label;
       GtkWidget * total_txt;
       GtkWidget * who_signed_label;
       GtkWidget * who_signed_txt;
       GtkWidget * clear_button;
       GtkWidget * ok_button;
       GtkWidget * cancel_button;
       GtkWidget * layout;
    GtkWidget * vbox;
    GtkWidget * hbox;



void create_bill_window ();
#endif
