P=c2-cli
OBJECTS=c2-cli.o
CFLAGS=-g -Wall -O3
LDLIBS=-lreadline
CC=/usr/bin/c99

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDLIBS) -o $(P)