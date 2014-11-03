CC=gcc
CFLAGS="-Wall"

DEPS = 
OBJ = gethostname.o

%.o: %.c $(DEPS)
	$(CC) -c -o  $@ $< $(CFLAGS) 
gethostname: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) -g
debug:$(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) -g
clean:
	rm -vfr *~ gethostname *.o
	