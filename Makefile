#--Makefile--#

CC = gcc -g
PROGRAM = bakamoona
CFLAGS = -I./db -I./ds -I./gui

SOURCES = 	./ds/bus_ds.c \
			./ds/owner_ds.c \
			./db/db.c \
			./db/bus.c \
			./db/owner.c \
			./gui/mainwin_ui.c \
         	./gui/owner_reg_ui.c \
			./gui/bus_reg_ui.c\
                    ./gui/worker_reg_ui.c

.PHONY: all
all:
	$(CC) -o $(PROGRAM) main.c $(SOURCES) $(CFLAGS) `mysql_config --cflags --libs` `pkg-config --libs --cflags gtk+-2.0`

.PHONY: clean
clean:
	rm -rf *.o $(PROGRAM)
