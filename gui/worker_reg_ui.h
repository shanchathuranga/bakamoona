#ifndef _WORKER_REG_UI_H_
#define _WORKER_REG_UI_H_

#include <gtk/gtk.h>

typedef struct _worker_ui
{
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
} worker_ui; 

worker_ui * wrkui;

worker_ui * create_worker_reg_window ();

#endif
