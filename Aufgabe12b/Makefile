CC=gcc
CFLAGS="-Wall"

DEPS = my_net.h
OBJ = getipbyhost.o my_net.o

%.o: %.c $(DEPS)
	$(CC) -c -o  $@ $< $(CFLAGS) 
getipbyhost: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) -g
debug:$(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) -g
clean:
	rm -vfr *~ getipbyhost *.o
	