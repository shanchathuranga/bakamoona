#ifndef _SPAREPART_REG_UI_H_
#define _SPAREPART_REG_UI_H_

#include <gtk/gtk.h>

typedef struct _sparepart_ui
{
	GtkWidget * window;
	GtkWidget * header_label;
	GtkWidget * code_label;
	GtkWidget * code_txt;
	GtkWidget * sp_name_label;
	GtkWidget * sp_name_txt;
	GtkWidget * unitcost_label;
	GtkWidget * unitcost_txt;
	GtkWidget * mincost_label;
	GtkWidget * mincost_txt;
	GtkWidget * maxcost_label;
	GtkWidget * maxcost_txt;
	GtkWidget * desc_label;
	GtkWidget * desc_txt;
	GtkWidget * clear_button;
	GtkWidget * ok_button;
	GtkWidget * cancel_button;
	GtkWidget * layout;
	GtkWidget * vbox;
	GtkWidget * hbox;
} sparepart_ui;

sparepart_ui * spui;

sparepart_ui * create_sparepart_reg_window ();

#endif

