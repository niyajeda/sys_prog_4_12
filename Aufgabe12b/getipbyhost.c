#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "my_net.h"

unsigned int hostname_to_ip(char *hostname);

int main(int argc, char** argv){
	if(argc != 2){
		printf("Bitte auf richtige Parameterübergabe achten: ./getipbyhost hostname");
		return 0;
	}
	
	(big_endian() == 1)? printf("Big Endian\n") : printf("Little Endian\n");
	struct sockaddr_in addr;
	addr.sin_addr.s_addr=hostname_to_ip(argv[1]); /* local address */
  	printf("Hostname: %s - IP-Adresse (inet_ntoa): %s\nHostname: %s - IP-Adresse (my_inet_ntoa): %s \n" , argv[1] , inet_ntoa(addr.sin_addr), argv[1], my_inet_ntoa(addr.sin_addr));
}

unsigned int hostname_to_ip(char *hostname)
{  
 	struct addrinfo hints, *res;
 	struct in_addr addr;
 	int err;

 	memset(&hints, 0, sizeof(hints));
 	hints.ai_socktype = SOCK_STREAM;
 	hints.ai_family = AF_INET;

 	if ((err = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
 	printf("error %d\n", err);
 	return 1;
 	}
	addr.s_addr = ((struct sockaddr_in *)(res->ai_addr))->sin_addr.s_addr;
	freeaddrinfo(res);
	return addr.s_addr;
}