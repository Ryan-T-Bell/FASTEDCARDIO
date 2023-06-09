P=fastedcardio
SRC_DIR=src
OBJECTS=$(SRC_DIR)/fastedcardio.o $(SRC_DIR)/cli/cli.o $(SRC_DIR)/forge/forge.o
CFLAGS=-g -O3 -I src -D_POSIX_C_SOURCE=201712L
LDLIBS=-lreadline
CC=/usr/bin/c99

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDLIBS) -o $(P)
	rm -f $(OBJECTS)