#include <stdio.h>

int main() {
    int A[2][2] = {{1, 2}, {3, 4}}; // Matriz A 2x2
    int B[2][2] = {{5, 6}, {7, 8}}; // Matriz B 2x2
    int C[2][2]; // Matriz resultado

    printf("Soma de matrizes 2x2\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d \t", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}