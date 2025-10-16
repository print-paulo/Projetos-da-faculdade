#include <stdio.h>

int main () {
    float num1, num2, resultado; // Declarando as variáveis
    int opcao;

    printf("Digite o primeiro número: "); // Solicita o primeiro número ao usuário
    scanf("%f", &num1);

    printf("Digite o segundo número: "); // Solicita o segundo número ao usuário
    scanf("%f", &num2);

    printf("1 - Adição\n"); // Exibe o menu de operações possíveis
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");

    printf("Escolha uma operação (1-4): "); // Pergunta ao usuário qual operação deseja realizar
    scanf("%d", &opcao);

    switch (opcao) { // Estrutura switch-case para selecionar a operação com base na escolha do usuário
        case 1:
            resultado = num1 + num2;
            printf("\nResultado: %.2f + %.2f = %.2f \n", num1, num2, resultado);
            break;
        case 2:
            resultado = num1 - num2;
            printf("\nResultado: %.2f - %.2f = %.2f \n", num1, num2, resultado);
            break;
        case 3:
            resultado = num1 * num2;
            printf("\nResultado: %.2f * %.2f = %.2f \n", num1, num2, resultado);
            break;
        case 4:
            if (num2 != 0) { // Verifica se o segundo número não é zero para evitar divisão por zero
                resultado = num1 / num2;
                printf("\nResultado: %.2f / %.2f = %.2f \n", num1, num2, resultado);
            } else {
                printf("Erro: Divisão por zero não é permitida.\n");
            }
            break;
        default: // Caso o usuário insira uma opção inválida 
            printf("Opção inválida.\n");
    }
}
