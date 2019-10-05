#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>



main (int argc, char *argv[])
{
	
	char buffer[256];
	int fd = open("pipe1", O_NONBLOCK | O_RDONLY);
	if(fd < 0 && errno == ENXIO) {
		sprintf(buffer, "Esperando un lector\n");
		write(1, buffer, strlen(buffer));
		fd = open("pipe1", O_RDONLY);
	}
	else if(fd < 0) perror("Error en el open");
	int ret = read(0, buffer, sizeof(buffer));
	while(ret > 0) {
		write(fd, buffer, ret);
		ret = read(0, buffer, sizeof(buffer));
	}
	close(fd);

}
