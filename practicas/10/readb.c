#include "./student.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	unsigned index;
	Student myStudent;
	
	printf("index: ");
	scanf("%d", &index);
	
	int fd = open(dbName, O_RDONLY, 0);
	int offset = index * sizeof(Student);
	lseek(fd, offset, SEEK_SET);
	read(fd, &myStudent, sizeof(Student));
	close(fd);
	
	printf("index %d, id %d, fistName %s, lastName %s, semester %c \n", 
		  index, myStudent.id, myStudent.firstName, myStudent.lastName, myStudent.semester);
	return 0;
}