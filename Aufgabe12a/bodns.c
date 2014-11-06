#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "my_net.h"

int main(int argc, char** argv){
	(is_little_endian() == 1)? printf("Little Endian\n") : printf("Big Endian\n");
	
	struct sockaddr_in addr;

	addr.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
	char *x;
	x = my_inet_ntoa(addr.sin_addr);
	printf("%s", x);
	return 0;
}