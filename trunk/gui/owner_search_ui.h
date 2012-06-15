#include <gtk/gtk.h>

GtkWidget * window;
GtkWidget * vbox;
GtkWidget * title;
GtkWidget * sw;
GtkWidget * hbox;
GtkWidget * refresh;
GtkWidget * select;
GtkWidget * cancel;

enum
{
    COL_NAME = 0,
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