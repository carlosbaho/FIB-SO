#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	char buf2;
	int fd = open("file", O_RDWR);
	int total = lseek(fd,0,SEEK_END)-1; // -1 para tema salto linea
	lseek(fd,total,SEEK_SET);
	int i = 0;
	while(read(fd, &buf2, 1) && i<=total) {
		lseek(fd,total+i,SEEK_SET);
		write(fd, &buf2, 1);
		++i;
		lseek(fd,total-i,SEEK_SET);
	}
}

