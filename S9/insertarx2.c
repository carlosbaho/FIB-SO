#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	/* Hecho con un apuntador, hubiera sido mejor con 2(RD y WR) */
	char pathname[32] = "sortida.txt";
	char buf = 'X';
	char buf2;
	int posicion = 4; // donde queremos
	int fd = open(pathname, O_RDWR);
	int total = lseek(fd, -1, SEEK_END);
	int i = 0;
	int stop = 0;
	while(stop==0 && read(fd, &buf2, 1)) {
			int current = lseek(fd, 0, SEEK_CUR);
			if(current==(posicion)) {
				lseek(fd, -1, SEEK_CUR);
				write(fd, &buf, 1);
				stop=1;
			}
			lseek(fd, -i, SEEK_END);
			write(fd, &buf2, 1);
			++i;
			lseek(fd, total-i+1, SEEK_SET);	
	}
}
