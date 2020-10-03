#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    char c;
    unsigned caracteres = 0;
    unsigned palabras = 0;
    unsigned lineas = 0;
    unsigned bandera = 1;

    while(read(STDIN_FILENO,&c,1) != 0) {
		if(c == '\n' && bandera == 0) {
            caracteres++;
            palabras++;
            lineas++;
            bandera = 0;
        } else if(c == '\n' && bandera == 1) {
            caracteres++;
            lineas++;
        } else if(c != ' ') {
            caracteres++;
            bandera = 0;
        } else {
            if(bandera == 0) {
                caracteres++;
                palabras++;
                bandera = 1;
            } else {
                caracteres++;
            }
        }
    }
    printf("Numero de lineas: %u\n", lineas);
    printf("Numero de palabras: %u\n", palabras);
    printf("Numero de caracteres: %u\n", caracteres);
    return 0;
}