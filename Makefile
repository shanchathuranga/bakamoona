#--Makefile--#

CC = gcc -g
PROGRAM = bakamoona
CFLAGS = -I./db -I./ds

SOURCES = 	./db/bus.c \
			./ds/bus_ds.c

.PHONY: all
all:
	$(CC) -o $(PROGRAM) main.c $(SOURCES) $(CFLAGS) `mysql_config --cflags --libs`

.PHONY: clean
clean:
	rm -rf *.o $(PROGRAM)
