#--Makefile--#

CC = gcc -g
PROGRAM = bakamoona
CFLAGS = -I./db -I./ds -I./gui

SOURCES = 	./db/bus.c \
			./ds/bus_ds.c \
			./db/db.c \
			./gui/mainwin.c \
         	./gui/owner_reg.c \
			./db/owner.c \
			./ds/owner_ds.c

.PHONY: all
all:
	$(CC) -o $(PROGRAM) main.c $(SOURCES) $(CFLAGS) `mysql_config --cflags --libs` `pkg-config --libs --cflags gtk+-2.0`

.PHONY: clean
clean:
	rm -rf *.o $(PROGRAM)
