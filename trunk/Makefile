#--Makefile--#

CC = gcc -g
PROGRAM = bakamoona
CFLAGS = -I./db -I./gui

SOURCES = 	./db/db.c \
			./db/bus.c \
			./db/owner.c \
			./gui/mainwin_ui.c \
      		./gui/owner_reg_ui.c \
			./gui/bus_reg_ui.c \
      		./gui/worker_reg_ui.c \
			./gui/owner_search_ui.c \
			./gui/sparepart_reg_ui.c \
			./gui/maintenance_ui.c\
                        ./gui/bill_ui.c\
                        ./gui/package_ui.c\

.PHONY: all
all:
	$(CC) -o $(PROGRAM) main.c $(SOURCES) $(CFLAGS) `mysql_config --cflags --libs` `pkg-config --libs --cflags gtk+-2.0` `pkg-config --cflags --libs glib-2.0`

.PHONY: clean
clean:
	rm -rf *.o $(PROGRAM)
