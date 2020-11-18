#include "./student.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
	Student *myStudent;
	myStudent = calloc(1, sizeof(Student));
	int dFd = open(dbName, O_WRONLY | O_CREAT, 0600);

	for(int i = 0; i < 20; i++) {
		write(dFd, myStudent, sizeof(Student));
	}
	close(dFd);
	return 0;
}