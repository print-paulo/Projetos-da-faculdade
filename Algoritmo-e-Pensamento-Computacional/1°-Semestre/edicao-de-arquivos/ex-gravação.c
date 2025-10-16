#include <stdio.h>

int main()
{
    FILE *arquivo = fopen("dados.txt", "a"); // Modo de anexar
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fprintf(arquivo, "Profissão: Engenheira\n");
    fclose(arquivo);
    printf("Novo dado adicionado ao arquivo!\n");
    return 0;
}