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
	printf("id: ");
	scanf("%d", &myStudent.id);
	printf("fistName: ");
	scanf("%s", myStudent.firstName);
	printf("lastName: ");
	scanf("%s", myStudent.lastName);
	printf("semester: ");
	scanf("\n%c", &myStudent.semester);
	
	//printf("index %d, id %d, fistName %s, lastName %s, semester %c ", 
	//	  index, myStudent.id, myStudent.firstName, myStudent.lastName, myStudent.semester);
	
	int fd = open(dbName, O_WRONLY, 0);
	int offset = index * sizeof(Student);
	lseek(fd, offset, SEEK_SET);
	write(fd, &myStudent, sizeof(Student));
	close(fd);
	return 0;
}