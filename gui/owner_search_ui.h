#ifndef _OWNER_SEARCH_UI_H_
#define _OWNER_SEARCH_UI_H_

#include <gtk/gtk.h>
#include "owner.h"

typedef struct _owner_search_ui
{
    GtkWidget * window;
    GtkWidget * vbox;
    GtkWidget * title;
    GtkWidget * sw;
    GtkWidget * hbox;
    GtkWidget * refresh;
    GtkWidget * select;
    GtkWidget * cancel;
    GtkWidget * filter_lbl;
    GtkWidget * filter_txt;
    GtkWidget * filter_by;
    GtkWidget * filter_combo;
    GtkWidget * filter_box;
} owner_search_ui;

enum
{
	COL_ID = 0,
    COL_NAME,
    COL_REG_NO,
    COL_PHONE_1,
    COL_PHONE_2,
    COL_ADDRESS_1, 
    COL_CITY_1,
    COL_ADDRESS_2,
    COL_CITY_2,
    COL_EMAIL,
    COL_COUNT
};

owner_search_ui * ow_search_ui;

owner_search_ui * create_owner_search_window (GtkWidget * n, GtkWidget * a, GtkWidget * c, int * id, void (*callback)(void));

#endif
