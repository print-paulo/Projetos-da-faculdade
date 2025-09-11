    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    //Criando a estrutura aluno
    struct Aluno {
            int matricula;
            char nome[50];
            float media;
        };

    //Também é possivel fazer um array com estruturas
    struct Aluno turma[2] = {
        {11111, "Joaquim Joelhos", 6.5},
        {22222, "Clariane Cotovelos", 10}
    };

    int main() {
        //Criando uma variável do tipo struct Aluno
        struct Aluno aluno1;

        //Atribuindo valores as variáveis dentro da estrutura
        aluno1.matricula = 12345;
        strcpy(aluno1.nome, "Maria Silva");
        aluno1.media = 8.7;

        //Exibir os dados da variável "aluno1" no console
        printf("=== Dados do Aluno ===\n");
        printf("Matrícula: %d\n", aluno1.matricula);
        printf("Nome: %s\n", aluno1.nome);
        printf("Média: %.2f\n\n\n", aluno1.media);
        
        printf("=== Dados dos Alunos ===\n");
        for (int i = 0; i < 2; i++) {
            printf("Aluno #%d\n", i + 1);
            printf("ID: %d\n", turma[i].matricula);
            printf("Nome: %s\n", turma[i].nome);
            printf("Média: %.2f\n\n", turma[i].media);
        };
        return 0;
    }
