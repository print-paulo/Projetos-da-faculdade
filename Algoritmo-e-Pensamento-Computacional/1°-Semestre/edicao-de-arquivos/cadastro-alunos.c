#include <stdio.h>
#include <stdlib.h>

// Estrutura para aluno
typedef struct {
    char nome[50];
    float nota1, nota2;
} Aluno;

// Função para calcular média
float calcularMedia(float n1, float n2) {
    return (n1 + n2) / 2.0; // Fórmula da média
}

// Função para salvar alunos em arquivo
void salvarAlunos(const char *arquivo, Aluno *alunos, int qtd) {
    FILE *fp = fopen(arquivo, "w"); // Abre em modo escrita
    if (!fp)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (int i = 0; i < qtd; i++)
    {
        float media = calcularMedia(alunos[i].nota1, alunos[i].nota2);
        // Grava nome, notas e média no arquivo
        fprintf(fp, "%s %.2f %.2f Média: %.2f\n",
                alunos[i].nome, alunos[i].nota1, alunos[i].nota2,
                media);
    }
    fclose(fp); // Fecha o arquivo
    printf("Alunos gravados em %s\n", arquivo);
}

// Função para ler alunos do arquivo
void lerAlunos(const char *arquivo) {
    FILE *fp = fopen(arquivo, "r"); // Abre em modo leitura
    if (!fp)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    char linha[100];
    printf("\nConteúdo do arquivo:\n");
    while (fgets(linha, sizeof(linha), fp) != NULL)
    { // Lê linha por linha
        printf("%s", linha);
    }
    fclose(fp);
}

int main() {
    int qtd;
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &qtd);
    Aluno alunos[qtd]; // Vetor de structs para armazenar os alunos
    for (int i = 0; i < qtd; i++)
    {
        printf("Nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
    }
    salvarAlunos("alunos.txt", alunos, qtd); // Grava em arquivo
    lerAlunos("alunos.txt");                 // Lê do arquivo
    return 0;
}