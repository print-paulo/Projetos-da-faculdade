#include <stdio.h>

void bubbleSort(int v[], int n) {
    int i, j, aux;
    // Percorre o vetor várias vezes
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            // Se o elemento atual for maior que o próximo, troca
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

int main() {
    int v[] = {5, 3, 4, 1, 2};
    int n = 5;
    bubbleSort(v, n);
    printf("Vetor ordenado (Bubble Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    return 0;
}