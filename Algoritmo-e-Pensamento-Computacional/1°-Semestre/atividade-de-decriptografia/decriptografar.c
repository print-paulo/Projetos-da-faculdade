#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char const alfabeto[] = "abcdefghijklmnopqrstuvwxyz";

void aplicarShift(char *alfabetoShiftado, int shift) {
    int tamanhoAlfabeto = strlen(alfabeto);
    
    shift = shift % tamanhoAlfabeto;
    if (shift < 0) {
        shift += tamanhoAlfabeto;
    }

    strncpy(alfabetoShiftado, alfabeto + shift, 26 - shift);
    strncat(alfabetoShiftado, alfabeto, shift);

}

int main () {
    char textoCriptografado[32] = "";

    printf("Digite o texto a ser decriptografada: \n");
    scanf("%s", textoCriptografado);
}
