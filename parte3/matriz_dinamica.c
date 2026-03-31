#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n;

    printf("Linhas (M): ");
    scanf("%d", &m);
    printf("Colunas (N): ");
    scanf("%d", &n);

    if (m <= 0 || n <= 0) {
        fprintf(stderr, "Erro: dimensoes invalidas.\n");
        return 1;
    }

    /* Aloca array de M ponteiros (um por linha) */
    int **matriz = (int **)malloc(m * sizeof(int *));

    if (matriz == NULL) {
        fprintf(stderr, "Erro: falha ao alocar ponteiros de linha.\n");
        return 1;
    }

    /* Para cada linha, aloca N inteiros */
    for (int i = 0; i < m; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
        if (matriz[i] == NULL) {
            fprintf(stderr, "Erro: falha ao alocar linha %d.\n", i);
            /* Libera as linhas ja alocadas antes de sair */
            for (int k = 0; k < i; k++) free(matriz[k]);
            free(matriz);
            return 1;
        }
    }

    /* Preenche a matriz */
    printf("Preencha os elementos:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("matriz[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    /* Exibe a matriz */
    printf("\nMatriz %d x %d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    /* Libera cada linha e depois o array de ponteiros */
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
        matriz[i] = NULL;
    }
    free(matriz);
    matriz = NULL;

    return 0;
}
