#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "my_net.h"

int main(int argc, char** argv){
	(big_endian() == 1)? printf("Big Endian\n") : printf("Little Endian\n");
	struct sockaddr_in addr;

	addr.sin_family=AF_INET;
	addr.sin_port=htons(5000); /* 0: randomly assigned by OS */
	addr.sin_addr.s_addr=htonl(INADDR_LOOPBACK); /* local address */
	char *x;
	x = my_inet_ntoa(addr.sin_addr);
	printf("%s", x);
	return 0;
}