#include <stdio.h>

int main() {
    float temperatura, convertida;
    char escala;
    
    printf("Digite a temperatura:\n");
    scanf("%f", &temperatura);

    printf("Digite a escala:\n");
    scanf("%c", &escala);

    if (escala == 'C' || escala == 'c') {
        convertida = (temperatura * 9.0 / 5.0) + 32.0;
        printf("%.2f°C = %.2f°F\n", temperatura, convertida);
    }
    else if (escala == 'F' || escala == 'f') {
        convertida = (temperatura -32) * 5.0 / 9.0;
        printf("%.2f°F = %.2f°C\n", temperatura, convertida);
    }
    else {
        printf("Entrada inválida");
        return 1;
    }
    return 0;

}
