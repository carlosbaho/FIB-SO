#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



main (int argc, char *argv[])
{
	int fd = creat("salida.txt", O_RDWR); //genera un archivo del formato O_RDWR,  similar open (nombre, O_RDWR|O_CREAT, acceso)
	char buffer[6];
	strcpy(buffer, "ABCD"); //Copies the C string pointed by source into the array pointed by destination
    write (fd, buffer, strlen (buffer));
	close(fd);
}
