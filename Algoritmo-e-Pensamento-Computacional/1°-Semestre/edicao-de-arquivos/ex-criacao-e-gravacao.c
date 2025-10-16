#include <stdio.h>

int main()
{
    FILE *arquivo = fopen("dados.txt", "w"); // Cria arq.(modo escrita)
    if (arquivo == NULL)
    {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    fprintf(arquivo, "Nome: Maria\nIdade: 25\nCidade: Recife\n");
    fclose(arquivo);
    printf("Arquivo criado e dados gravados com sucesso!\n");
    return 0;
}