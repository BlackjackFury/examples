#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>

char *socket_path = "test.sock";

int main(int argc, char *argv[])
{
 	char message[] = "Hello world!";
	char buf[sizeof(message)];
	int sock,rc;
	struct sockaddr_in addr;
	
	sock = socket(AF_INET, SOCK_STREAM,0);

	if (sock < 0) {
	
	perror("socket");
	return 1;
	}
    

	addr.sin_family = AF_INET;
	addr.sin_port = htons(3425);
	addr.sin_addr.s_addr = inet_addr("192.168.99.2");
	
	if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("connect");
		return 1;
	}

	if(rc = send (sock, message, sizeof(message),0))
	{
		if (rc > 0) {
			printf("write\n");
		}
		else {

			perror("write error");
			return 1;
		}
	}
close (sock);
return 0;
}

