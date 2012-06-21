#ifndef _MAINWIN_H_
#define _MAINWIN_H_

#include <gtk/gtk.h>

       GtkWidget * window;
       GtkWidget * header_label;

       GtkWidget * package_code_label;
       GtkWidget * package_code_txt;
       GtkWidget * enetr_package_items_label;
       GtkWidget * enetr_package_items_txt;
       GtkWidget * package_price_label;
       GtkWidget * package_price_txt;
       GtkWidget * package_discription_label;
       GtkWidget * package_discription_txt;
       //GtkWidget * date_label;
       //GtkWidget * date_txt;
       
       GtkWidget * clear_button;
       GtkWidget * ok_button;
       GtkWidget * cancel_button;
       GtkWidget * layout;
    GtkWidget * vbox;
    GtkWidget * hbox;



void create_enter_package_window ();
#endif
