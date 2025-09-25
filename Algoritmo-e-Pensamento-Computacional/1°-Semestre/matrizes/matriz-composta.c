#include <stdio.h>
    
int main() {
    int A[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int T[2][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            T[j][i] = A[i][j];
        }
    }
    printf("Matriz transposta: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d \t", T[i][j]);
        }
    printf("\n");
    }
    return 0;
}
