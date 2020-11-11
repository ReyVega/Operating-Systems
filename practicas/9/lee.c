#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = open("./lee.c",O_RDONLY,0); // abrir archivos open
	if(fd < 0) {
		printf("Error al abrir el archivo \n");
		return 1;
	}
	char c;
	write(fd, &c, 1);
	while(read(fd,&c,1)) {
		printf("%c",c);
	}
	return 0;
}