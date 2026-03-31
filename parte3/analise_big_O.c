#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("Tamanho N da matriz quadrada: ");
    scanf("%d", &n);

    if (n <= 0) {
        fprintf(stderr, "Erro: valor invalido.\n");
        return 1;
    }

    /* Aloca matriz N×N */
    int **mat = (int **)malloc(n * sizeof(int *));
    if (mat == NULL) { fprintf(stderr, "Erro de alocacao.\n"); return 1; }

    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
        if (mat[i] == NULL) {
            for (int k = 0; k < i; k++) free(mat[k]);
            free(mat);
            return 1;
        }
    }

    /* Preenche a matriz com valores sequenciais */
    int v = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = v++;

    /*
     * ANALISE DE COMPLEXIDADE - O(n^2)
     * ─────────────────────────────────────────────────────────────────────
     * O laco externo (i) executa exatamente N vezes.
     * Para cada iteracao do laco externo, o laco interno (j) executa N vezes.
     * Total de operacoes: N * N = N^2
     *
     * Independentemente dos valores armazenados, todo par (i, j) e visitado
     * uma unica vez. Com N dobrando, o numero de operacoes quadruplica.
     * Por isso a complexidade de tempo e O(n^2).
     * ─────────────────────────────────────────────────────────────────────
     */
    long long operacoes = 0;
    printf("\nPercorrendo a matriz %d x %d:\n", n, n);
    for (int i = 0; i < n; i++) {             /* laco externo: N iteracoes */
        for (int j = 0; j < n; j++) {         /* laco interno: N iteracoes */
            printf("%4d", mat[i][j]);
            operacoes++;                       /* conta cada acesso */
        }
        printf("\n");
    }

    printf("\nTotal de operacoes: %lld (esperado N^2 = %d)\n", operacoes, n * n);

    /* Liberacao profunda */
    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
    mat = NULL;

    return 0;
}
