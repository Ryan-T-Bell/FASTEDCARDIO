P=main
OBJECTS=main.o
CFLAGS=-g -O3
LDLIBS=-lreadline
CC=/usr/bin/c99

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDLIBS) -o $(P)
	rm -f $(OBJECTS)