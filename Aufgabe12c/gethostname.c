#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <libgen.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char **argv){
	if (argc != 2)
		errx(1, "usage: %s <ipaddress>", argv[0]);

	struct addrinfo *res, *resorig, hints;
	char host[NI_MAXHOST];
	int err;

	memset(&hints, 0, sizeof (hints));
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_family = AF_INET;

	/*
	 * Hole sockaddr struct mit getaddrinfo(). Da Portname egal - servname = NULL
	*/
	if ((err = getaddrinfo(argv[1], NULL, &hints, &res)) != 0)
		errx(1, "%s", gai_strerror(err));

	for (resorig = res; res != NULL; res = res->ai_next) {
		/* getnameinfo() anstatt inet_ntop() zum umwandeln der Adresse */
		if ((err = getnameinfo(res->ai_addr, res->ai_addrlen,
		    numhost, sizeof (numhost), NULL, 0, NI_NUMERICHOST)) != 0)
			errx(1, "%s", gai_strerror(error));
		//Adresse auflösen
		if ((error = getnameinfo(res->ai_addr, res->ai_addrlen,
		    host, sizeof (host), NULL, 0, 0)) != 0)
			errx(1, "%s", gai_strerror(err));
		printf("IP-Adresse %s wird zu %s aufgelöst\n", argv[1], host);
	}

	freeaddrinfo(resorig);
	return (0);
}