#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    char c;
    unsigned caracteres = -1;
    unsigned palabras = 0;
    unsigned lineas = 0;
    unsigned bandera = 0;
    unsigned bandera2 = 0;

    while(read(STDIN_FILENO,&c,1) != 0) {
        if(c == ' ')  {
            if(bandera == 0) {
                caracteres++;
                palabras++;
                bandera = 1;
            } else {
                caracteres++;
            }
        } else if(c == '\n'){
            caracteres++;
            lineas++;
            bandera = 0;
        } else {
            caracteres++;
            bandera = 0;
            if(bandera2 == 0) {
                palabras++;
                bandera2 = 1;
            }
        }
    }
    printf("Numero de caracteres: %u\n", caracteres);
    printf("Numero de palabras: %u\n", palabras);
    printf("Numero de lineas: %u\n", lineas);
    return 0;
}