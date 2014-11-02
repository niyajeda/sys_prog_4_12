//#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_net.h"

int big_endian(){
   unsigned int a=1;
   return ((a << 1) == 2)? 0:1;
}

char *my_inet_ntoa(struct in_addr in){
 	/* interpret IPv4-Address as 32bit int */
 	unsigned int addr = *(unsigned int *)&in;
 	unsigned char *ipaddress;
 	static char buf[4*sizeof "123"];
 	ipaddress = (unsigned char*)malloc(4*sizeof(unsigned char));
 	int i;
 	for(i=0; i<4; i++)
 	{
 		ipaddress[i] = (addr >> (i*8)) & 0xFF;
 	}
 	snprintf(buf, sizeof(buf), "%d.%d.%d.%d", ipaddress[0], ipaddress[1], ipaddress[2], ipaddress[3]);
 	return buf;
}