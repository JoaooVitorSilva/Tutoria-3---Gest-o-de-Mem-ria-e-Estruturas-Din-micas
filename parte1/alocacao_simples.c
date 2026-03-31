#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Aloca espaco no heap para um unico float */
    float *valor = (float *)malloc(sizeof(float));

    /* Verifica se a alocacao foi bem-sucedida */
    if (valor == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memoria.\n");
        return 1;
    }

    printf("Digite um valor float: ");
    scanf("%f", valor);

    /* Exibe com duas casas decimais usando indiracao */
    printf("Valor armazenado: %.2f\n", *valor);

    /* Libera a memoria alocada */
    free(valor);
    valor = NULL;

    return 0;
}
