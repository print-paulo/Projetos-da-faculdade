#include <stdio.h>

int main()
{
    FILE *arquivo = fopen("dados.txt", "r"); // Abre para leitura
    char linha[100];
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    
    printf("Conteúdo do arquivo:\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    fclose(arquivo);
    return 0;
}