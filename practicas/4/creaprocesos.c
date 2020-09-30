#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void signalHandler(int signum) {
    int status;
    wait(&status);
    printf("Mi hijo termino con status %d", status);
}

int main(int argc, char **argv) {
    signal(17, signalHandler);
    unsigned pid = fork();
    if(pid == 0) {
        sleep(5);
        printf("Soy el proceso del hijo\n");
        //execv(argv[1],&argv[1]);
        return 10;
    } else {
        printf("Soy el proceso del padre  y mi hijo es %u\n",pid);
        while(1){
             sleep(2);
             printf("trabajando \n");
        }
    }
    printf("Hola mundo\n");
    return 0;
}