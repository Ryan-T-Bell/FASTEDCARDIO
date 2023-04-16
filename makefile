P=main
SRC_DIR=src
OBJECTS=$(SRC_DIR)/main.o $(SRC_DIR)/cli/cli.o  $(SRC_DIR)/forge/forge.o  $(SRC_DIR)/str/str.o
CFLAGS=-g -O3 -I src -D_POSIX_C_SOURCE=200809L
LDLIBS=-lreadline
CC=/usr/bin/c99

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDLIBS) -o $(P)
	rm -f $(OBJECTS)