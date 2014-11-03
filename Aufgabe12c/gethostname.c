#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <libgen.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char **argv){
	int error;
	struct addrinfo *res, *resorig, hints;
	char host[NI_MAXHOST], numhost[NI_MAXHOST];

	if (argc != 2)
		errx(1, "usage: %s <ipaddress>", basename(argv[0]));

	memset(&hints, 0, sizeof (hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	/*
	 * Get our sockaddr structure(s) first via getaddrinfo(). We do not
	 * care about a port number so we set "servname" to NULL.
	 */
	if ((error = getaddrinfo(argv[1], NULL, &hints, &res)) != 0)
		errx(1, "%s", gai_strerror(error));

	for (resorig = res; res != NULL; res = res->ai_next) {
		/* Here getnameinfo() is used ala inet_ntop(). */
		if ((error = getnameinfo(res->ai_addr, res->ai_addrlen,
		    numhost, sizeof (numhost), NULL, 0, NI_NUMERICHOST)) != 0)
			errx(1, "%s", gai_strerror(error));
		/* Now try to resolve the address back to hostname. */
		if ((error = getnameinfo(res->ai_addr, res->ai_addrlen,
		    host, sizeof (host), NULL, 0, 0)) != 0)
			errx(1, "%s", gai_strerror(error));
		printf("IP-Adresse %s wird zu %s aufgelöst\n", numhost, host);
	}

	freeaddrinfo(resorig);
	return (0);
}