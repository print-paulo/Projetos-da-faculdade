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
    alfabetoShiftado[26 - shift] = '\0';
    strncat(alfabetoShiftado, alfabeto, shift);
}

void calcularAlfabetoPulado(char* alfabetoPulado, const char* alfabetoShiftado, int pulo) {
    int usado[26] = {0};
    int j = 0;

    for (int i = pulo - 1; i < 26; i += pulo) {
        alfabetoPulado[j++] = alfabetoShiftado[i];
        usado[i] = 1;
    }
    for (int i = 0; i <26; ++i) {
        if (!usado[i]) {
            alfabetoPulado[j++] = alfabetoShiftado[i];
        }
    }
    alfabetoPulado[26] = '\0';
}

int main () {
    char textoCriptografado[32] = "";
    int shift = 0;

    printf("Digite o texto a ser decriptografada: \n");
    scanf("%s", textoCriptografado);

    printf("Digite o valor do shift: \n");
    scanf("%d", &shift);


}
