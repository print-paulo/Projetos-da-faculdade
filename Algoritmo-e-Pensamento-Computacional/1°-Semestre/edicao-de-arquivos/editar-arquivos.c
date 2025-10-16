#include <stdio.h>
#include <stdlib.h>

// Função para gravar nomes em arquivo
void gravarNomes(const char *arquivo) {
    FILE *fp = fopen(arquivo, "w"); // Abre o arquivo em modo escrita("w")
    if (fp == NULL)
    { // Testa se o arquivo abriu corretamente
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    int n;
    char nome[50];
    printf("Quantos nomes deseja gravar?\n");
    scanf("%d", &n); // Lê quantidade de nomes a gravar
    for (int i = 0; i < n; i++)
    {
        printf("Digite o nome %d: ", i + 1);
        scanf("%s", nome);         // Lê um nome digitado
        fprintf(fp, "%s\n", nome); // Grava o nome no arquivo
    }
    fclose(fp); // Fecha o arquivo
    printf("Nomes gravados com sucesso!\n");
}

// Função para ler nomes do arquivo
void lerNomes(const char *arquivo) {
    FILE *fp = fopen(arquivo, "r"); // Abre o arquivo em modo leitura ("r")
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }
    char nome[50];
    printf("\nNomes gravados no arquivo:\n");
    while (fgets(nome, sizeof(nome), fp) != NULL)
    { // Lê linha a linha do arquivo
        printf("%s", nome);
    }
    fclose(fp); // Fecha o arquivo
}
int main() {
    const char *arquivo = "nomes.txt"; // Nome do arquivo
    gravarNomes(arquivo);              // Chama função para gravar nomes
    lerNomes(arquivo);                 // Chama função para ler nomes
    return 0;
}