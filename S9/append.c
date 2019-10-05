#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	char buf2;
	int fd = open("file", O_RDWR);
	int total = lseek(fd,0,SEEK_END); // tamaño
	int i = 0;
	lseek(fd,0,SEEK_SET);
	while(read(fd, &buf2, 1) && i<total) { // buf2!='\n'
		lseek(fd,0,SEEK_END);
		write(fd, &buf2, 1);
		++i;
		lseek(fd,i,SEEK_SET);
	}
}
