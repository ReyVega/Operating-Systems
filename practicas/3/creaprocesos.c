#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char **argv) {
    unsigned pid = fork();
    if(pid == 0) {
        printf("Soy el proceso del hijo\n");
        execv(argv[1],&argv[1]);
        return 10;
    } else {
        int status;
        printf("Soy el proceso del padre  y mi hijo es %u\n",pid);
        //hacer cosas mas
        sleep(4);
        //
        wait(&status);
        printf("terminando despues del hijo y estatus %d\n",status);
    }
    printf("Hola mundo\n");
    return 0;
}