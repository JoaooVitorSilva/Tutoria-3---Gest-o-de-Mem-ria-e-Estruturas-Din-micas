#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 64
#define NUM_ALUNOS 3

typedef struct {
    char  nome[MAX_NOME];
    float nota;
} Aluno;

int main(void) {
    /* Aloca array de 3 Alunos no heap */
    Aluno *alunos = (Aluno *)malloc(NUM_ALUNOS * sizeof(Aluno));

    if (alunos == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memoria para alunos.\n");
        return 1;
    }

    /* Leitura dos dados de cada aluno */
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %63[^\n]", alunos[i].nome);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }

    /* Exibe os dados */
    printf("\n=== Lista de Alunos ===\n");
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Aluno: %-30s | Nota: %.1f\n", alunos[i].nome, alunos[i].nota);
    }

    /* Libera a memoria */
    free(alunos);
    alunos = NULL;

    return 0;
}