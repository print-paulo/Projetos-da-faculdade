#include <stdio.h>

int main()
{
    if (remove("dados.txt") == 0)
        printf("Arquivo excluído com sucesso!\n");
    else
        printf("Erro ao excluir o arquivo!\n");
    return 0;
}