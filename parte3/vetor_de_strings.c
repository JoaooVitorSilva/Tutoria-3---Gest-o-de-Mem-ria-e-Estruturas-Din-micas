#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n;

    printf("Quantas cidades deseja cadastrar? ");
    scanf("%d", &n);

    if (n <= 0) {
        fprintf(stderr, "Erro: quantidade invalida.\n");
        return 1;
    }

    /* Aloca vetor de n ponteiros para char */
    char **cidades = (char **)malloc(n * sizeof(char *));

    if (cidades == NULL) {
        fprintf(stderr, "Erro: falha ao alocar vetor de ponteiros.\n");
        return 1;
    }

    char buffer[256];

    /* Para cada cidade, aloca apenas os bytes necessarios */
    for (int i = 0; i < n; i++) {
        printf("Cidade %d: ", i + 1);
        scanf(" %255[^\n]", buffer);

        /* Aloca strlen + 1 bytes para o nome exato */
        cidades[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

        if (cidades[i] == NULL) {
            fprintf(stderr, "Erro: falha ao alocar nome da cidade %d.\n", i);
            for (int k = 0; k < i; k++) free(cidades[k]);
            free(cidades);
            return 1;
        }

        strcpy(cidades[i], buffer);
    }

    /* Exibe as cidades cadastradas */
    printf("\nCidades cadastradas:\n");
    for (int i = 0; i < n; i++) {
        printf("  %d. %s\n", i + 1, cidades[i]);
    }

    /* Libera cada string e depois o vetor de ponteiros */
    for (int i = 0; i < n; i++) {
        free(cidades[i]);
        cidades[i] = NULL;
    }
    free(cidades);
    cidades = NULL;

    return 0;
}
