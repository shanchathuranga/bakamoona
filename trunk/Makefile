CC = gcc
PROGRAM = bakamoona
CFLAGS = -I./db

SOURCES = 	./db/db_man.c

.PHONY: all
all:
	$(CC) -o $(PROGRAM) main.c $(SOURCES) $(CFLAGS) `mysql_config --cflags --libs`

.PHONY: clean
clean:
	rm -rf *.o $(PROGRAM)
