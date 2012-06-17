#ifndef _MAINTENANCE_UI_H_
#define _MAINTENANCE_UI_H_

typedef struct _mnt_ui
{
	GtkWidget * window;
	GtkWidget * vbox;
	GtkWidget * title;
	GtkWidget * top_table;
	GtkWidget * lbusregno, * tbusregno;
	GtkWidget * lbusmodel, * tbusmodel;
	GtkWidget * lbusdriver, * tbusdriver;
	GtkWidget * lowner, * towner;
	GtkWidget * ldate, * date_hbox, * tdate, * date_btn;

	GtkWidget * lpack;
	GtkWidget * combopack;
	GtkWidget * addpack;
	GtkWidget * lcustompack;
	GtkWidget * tcustompack, * sw;
	GtkWidget * addcustompack;

	GtkWidget * btn_hbox;
	GtkWidget * ok, * clear, * cancel;
	GtkWidget * list, * listbase;
} mnt_ui;

mnt_ui * mntui;

mnt_ui * create_maintenance_window ();

#endif
