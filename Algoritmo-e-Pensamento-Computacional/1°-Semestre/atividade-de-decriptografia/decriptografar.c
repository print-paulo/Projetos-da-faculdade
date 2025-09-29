#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char const alfabeto[] = "abcdefghijklmnopqrstuvwxyz";

void aplicarShift(char *alfabetoShiftado, int shift) {
    int tamanho = strlen(alfabeto);
    
    shift = shift % tamanho;
    if (shift < 0) {
        shift += tamanho;
    }



}

int main () {
    char textoCriptografado[32] = "";

    printf("Digite o texto a ser decriptografada: \n");
    scanf("%s", textoCriptografado);
}
