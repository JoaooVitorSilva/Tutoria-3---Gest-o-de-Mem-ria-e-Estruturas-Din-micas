#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int capacidade = 2;

    /* Alocacao inicial: 2 inteiros */
    int *vetor = (int *)malloc(capacidade * sizeof(int));

    if (vetor == NULL) {
        fprintf(stderr, "Erro: falha na alocacao inicial.\n");
        return 1;
    }

    /* Preenche os 2 primeiros elementos */
    printf("Digite %d valores:\n", capacidade);
    for (int i = 0; i < capacidade; i++) {
        printf("vetor[%d] = ", i);
        scanf("%d", &vetor[i]);
    }

    /* Expande para 4 inteiros com realloc */
    capacidade = 4;
    int *temp = (int *)realloc(vetor, capacidade * sizeof(int));

    if (temp == NULL) {
        fprintf(stderr, "Erro: falha ao redimensionar com realloc.\n");
        free(vetor);   /* libera o bloco original antes de sair */
        return 1;
    }

    vetor = temp;  /* atualiza o ponteiro somente apos verificar NULL */

    /* Preenche os 2 novos elementos */
    printf("Vetor expandido! Digite mais %d valores:\n", capacidade - 2);
    for (int i = 2; i < capacidade; i++) {
        printf("vetor[%d] = ", i);
        scanf("%d", &vetor[i]);
    }

    /* Exibe o vetor completo */
    printf("\nVetor final:\n");
    for (int i = 0; i < capacidade; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    free(vetor);
    vetor = NULL;

    return 0;
}
