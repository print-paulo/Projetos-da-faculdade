#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char const alfabeto[] = "abcdefghijklmnopqrstuvwxyz";

void aplicarShift(char *alfabetoShiftado, int shift) {
    shift = shift % 26;
    if (shift < 0) {
        shift += 26;
    }

    strncpy(alfabetoShiftado, alfabeto + shift, 26 - shift);
    alfabetoShiftado[26 - shift] = '\0';
    strncat(alfabetoShiftado, alfabeto, shift);
}

void calcularAlfabetoPulado(char *alfabetoPulado, const char* alfabetoShiftado, int pulo) {
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

void decriptografarTexto(char *textoDecriptografado, const char* textoCriptografado, const char* alfabetoPulado) {
    char caractere;
    int j = 0;

    for (int i = 0; textoCriptografado[i] != '\0'; ++i) {
        caractere = textoCriptografado[i];
        
        if (islower(caractere)) {
            char* ponteiroCaractere = strchr(alfabetoPulado, caractere);
            if (ponteiroCaractere != NULL) {
                size_t posicaoChave = ponteiroCaractere - alfabetoPulado;
                textoDecriptografado[j++] = alfabeto[posicaoChave];
            }
            else {
                textoDecriptografado[j++] = caractere;
            }
        }
        else if (isupper(caractere)) {
            char minuscula = tolower(caractere);
            char* ponteiroCaractere = strchr(alfabetoPulado, minuscula);
            if (ponteiroCaractere != NULL) {
                size_t posicaoChave = ponteiroCaractere - alfabetoPulado;
                char decifrado = alfabeto[posicaoChave];
                textoDecriptografado[j++] = toupper(decifrado);
            }
            else {
                textoDecriptografado[j++] = caractere;
            }
        }
        else {
            textoDecriptografado[j++] = caractere;
        }
    }
    textoDecriptografado[j] = '\0';
}

int main () {
    char textoCriptografado[32];
    int shift = 0;
    char alfabetoShiftado[27];

    printf("Digite o texto a ser decriptografada: \n");
    scanf("%s", textoCriptografado);

    printf("Digite o valor do shift: \n");
    scanf("%d", &shift);

    aplicarShift(alfabetoShiftado, shift);

    printf("------------------------------\n Tentativas de decifração:\n------------------------------\n\n");
    printf("ALfabeto com shift: %s\n\n", alfabetoShiftado);
    for (int pulo = 1; pulo <= 26 / 2; ++pulo) {
        char alfabetoPulado[27];
        char textoDecriptografado[50];

        calcularAlfabetoPulado(alfabetoPulado, alfabetoShiftado, pulo);
        decriptografarTexto(textoDecriptografado,textoCriptografado, alfabetoPulado);

        printf("PA %d: %s\n Alfabeto com PA: %s\n", pulo, textoDecriptografado, alfabetoPulado);
    }
}
