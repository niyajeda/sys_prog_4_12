CC=gcc
CFLAGS="-Wall"

DEPS = my_net.h
OBJ = bodns.o my_net.o

%.o: %.c $(DEPS)
	$(CC) -c -o  $@ $< $(CFLAGS) 
bodns: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) -g
debug:$(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) -g
clean:
	rm -vfr *~ bodns *.o
	