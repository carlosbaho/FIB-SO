#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "socketMng.c"

main (int argc, char *argv[])
{
	
	char buffer[256];
	int socketFD = createSocket ("Meh");
	if (socketFD < 0)
	    {
	      perror ("Error creating socket\n");
	      exit (1);
	    }

	int connectionFD = serverConnection (socketFD);
	if (connectionFD < 0)
	{
	      perror ("Error establishing connection \n");
	      exit (1);
	}

	strcpy (buffer, "Hello!\n");
	int ret = write (connectionFD, buffer, strlen (buffer));
	while(ret > 0) {
		write(1, buffer, ret);
		ret = read(0, buffer, sizeof(buffer));
	}		
	if (ret < 0)
	    {
	      perror ("Error writing on connection \n");
	      exit (1);
	    }

	closeConnection (connectionFD);
	deleteSocket (socketFD, "Meh");	
	closeConnection(socketFD);

}
