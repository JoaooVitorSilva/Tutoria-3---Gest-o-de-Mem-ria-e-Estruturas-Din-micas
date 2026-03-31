#include <stdio.h>
#include <stdlib.h>

/* Libera a matriz linha por linha antes de liberar o array de ponteiros */
void liberar_matriz(int **matriz, int m) {
    if (matriz == NULL) return;

    for (int i = 0; i < m; i++) {
        free(matriz[i]);   /* libera cada linha individualmente */
        matriz[i] = NULL;
    }
    free(matriz);          /* libera o array de ponteiros */
}

int main(void) {
    int m = 3, n = 3;

    /* Aloca matriz 3x3 */
    int **matriz = (int **)malloc(m * sizeof(int *));
    if (matriz == NULL) {
        fprintf(stderr, "Erro: falha ao alocar ponteiros de linha.\n");
        return 1;
    }

    for (int i = 0; i < m; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
        if (matriz[i] == NULL) {
            fprintf(stderr, "Erro: falha ao alocar linha %d.\n", i);
            for (int k = 0; k < i; k++) free(matriz[k]);
            free(matriz);
            return 1;
        }
    }

    /* Preenche com valores de exemplo */
    int contador = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = contador++;

    /* Exibe */
    printf("Matriz antes da liberacao:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d", matriz[i][j]);
        printf("\n");
    }

    /* Libera com a funcao de liberacao profunda */
    liberar_matriz(matriz, m);
    matriz = NULL;

    printf("Memoria liberada com sucesso.\n");
    return 0;
}