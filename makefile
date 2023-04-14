P=main
SRC_DIR=src
OBJECTS=$(SRC_DIR)/main.o
CFLAGS=-g -O3 -I src
LDLIBS=-lreadline
CC=/usr/bin/c99

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDLIBS) -o $(P)
	rm -f $(OBJECTS)