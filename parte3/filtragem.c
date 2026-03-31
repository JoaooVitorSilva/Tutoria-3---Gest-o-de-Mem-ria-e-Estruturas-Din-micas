#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME    64
#define NUM_ALUNOS  5

typedef struct {
    char  nome[MAX_NOME];
    float nota;
} Aluno;

int main(void) {
    /* Aloca o vetor principal de alunos */
    Aluno *alunos = (Aluno *)malloc(NUM_ALUNOS * sizeof(Aluno));

    if (alunos == NULL) {
        fprintf(stderr, "Erro: falha ao alocar vetor de alunos.\n");
        return 1;
    }

    /* Preenche os dados dos alunos */
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Aluno %d - Nome: ", i + 1);
        scanf(" %63[^\n]", alunos[i].nome);
        printf("Aluno %d - Nota: ", i + 1);
        scanf("%f", &alunos[i].nota);
    }

    /* Conta quantos alunos foram aprovados */
    int aprovados = 0;
    for (int i = 0; i < NUM_ALUNOS; i++) {
        if (alunos[i].nota > 7.0f) aprovados++;
    }

    if (aprovados == 0) {
        printf("\nNenhum aluno aprovado.\n");
        free(alunos);
        return 0;
    }

    /* Aloca vetor de ponteiros para os alunos aprovados */
    Aluno **aprovados_vec = (Aluno **)malloc(aprovados * sizeof(Aluno *));

    if (aprovados_vec == NULL) {
        fprintf(stderr, "Erro: falha ao alocar vetor de aprovados.\n");
        free(alunos);
        return 1;
    }

    /* Preenche o vetor de aprovados com os enderecos */
    int idx = 0;
    for (int i = 0; i < NUM_ALUNOS; i++) {
        if (alunos[i].nota > 7.0f) {
            aprovados_vec[idx++] = &alunos[i];
        }
    }

    /* Exibe os aprovados */
    printf("\nAlunos aprovados (%d):\n", aprovados);
    for (int i = 0; i < aprovados; i++) {
        printf("  %-30s | Nota: %.1f\n",
               aprovados_vec[i]->nome, aprovados_vec[i]->nota);
    }

    /* Libera apenas o vetor de ponteiros (nao os alunos em si) */
    free(aprovados_vec);
    aprovados_vec = NULL;

    /* Libera o vetor principal */
    free(alunos);
    alunos = NULL;

    return 0;
}
