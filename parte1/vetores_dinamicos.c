#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    if (n <= 0) {
        fprintf(stderr, "Erro: tamanho invalido.\n");
        return 1;
    }

    /* Aloca n inteiros no heap de forma portavel */
    int *vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memoria.\n");
        return 1;
    }

    /* Preenche o vetor com valores do usuario */
    for (int i = 0; i < n; i++) {
        printf("vetor[%d] = ", i);
        scanf("%d", &vetor[i]);
    }

    /* Calcula a media aritmetica */
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += vetor[i];
    }
    double media = soma / n;

    printf("Media aritmetica: %.2f\n", media);

    /* Libera a memoria alocada */
    free(vetor);
    vetor = NULL;

    return 0;
}
