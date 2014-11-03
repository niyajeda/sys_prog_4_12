//#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_net.h"

int is_little_endian(){
    unsigned int x = 1;
  	char *c = (char*) &x;
  	return (int)*c;
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
	if(is_little_endian() == 1)
		snprintf(buf, sizeof(buf), "%d.%d.%d.%d", ipaddress[0], ipaddress[1], ipaddress[2], ipaddress[3]);
 	else
	 	snprintf(buf, sizeof(buf), "%d.%d.%d.%d", ipaddress[3], ipaddress[2], ipaddress[1], ipaddress[0]);
 	return buf;
}