#ifndef _MAINWIN_H_
#define _MAINWIN_H_

#include <gtk/gtk.h>

       GtkWidget * window;
       GtkWidget * header_label;
       GtkWidget * name_label;
       GtkWidget * name_txt;
       GtkWidget * address_label;
       GtkWidget * address_txt;
       GtkWidget * city_label;
       GtkWidget * city_txt;
       GtkWidget * nicNo_label;
       GtkWidget * nicNo_txt;
       GtkWidget * phoneNo_label;
       GtkWidget * phoneNo_txt;
       GtkWidget * joinDate_label;
       GtkWidget * joinDate_txt;
       GtkWidget * clear_button;
       GtkWidget * ok_button;
       GtkWidget * cancel_button;
       GtkWidget * layout;
    GtkWidget * vbox;
    GtkWidget * hbox;

//void worker_reg_ui();

void create_worker_reg_window ();
#endif
