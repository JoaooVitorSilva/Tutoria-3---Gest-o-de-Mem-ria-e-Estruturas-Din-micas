#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Aloca 5 inteiros no heap */
    int *vetor = (int *)malloc(5 * sizeof(int));

    if (vetor == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memoria.\n");
        return 1;
    }

    /* Ponteiro auxiliar para nao perder o inicio do vetor */
    int *ptr = vetor;

    /* Preenche o vetor usando aritmetica de ponteiros */
    printf("Digite 5 valores inteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", ptr);   /* ptr aponta para a posicao atual */
        ptr++;              /* avanca para o proximo elemento */
    }

    /* Reinicia o ponteiro auxiliar para o inicio */
    ptr = vetor;

    /* Percorre e imprime usando apenas * e ptr++ */
    printf("\nValores armazenados:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", *ptr);  /* indiracao: le o valor apontado */
        ptr++;                 /* incremento: avanca o endereco */
    }

    /* Libera o vetor usando o ponteiro original */
    free(vetor);
    vetor = NULL;

    return 0;
}
