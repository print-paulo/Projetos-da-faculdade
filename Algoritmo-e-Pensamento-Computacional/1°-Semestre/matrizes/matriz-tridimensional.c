#include <stdio.h>

int main () {
    int A[2][2][2] = { //Declara uma matriz com 2 blocos, 2 linhas e 2 colunas (tridimensional)
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}
    };
    
    printf("Valores do setor tridimensional (2x2x2): \n");
    
    //Inicia os laços de repetição para percorrer cada elemento

    //O laço de 'i' controla os blocos (0 a 1)
    for (int i = 0; i < 2; i++) {
        //O laço de 'j' controla as linhas (0 a 1)
        for (int j = 0; j < 2; j++) {
            //O laço de 'k' controla as colunas (0 a 1) e imprime as posições
            for (int k = 0; k < 2; k++) {
                printf("A[%d][%d][%d] = %d\n", i, j, k, A[i][j][k]);
            }
        }
    }
    return 0;
}