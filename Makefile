CC=gcc
CFLAGS=-I.
DEPS = netstat.h
OBJ = netstat.o
LIBS = -lncurses

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

netstat: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(OBJ) iostat
