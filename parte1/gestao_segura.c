#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Define 1 GB em bytes: 1024^3 = 1073741824 bytes */
    size_t tamanho = 1024UL * 1024UL * 1024UL;

    /* Tenta alocar 1 GB no heap */
    char *bloco = (char *)malloc(tamanho);

    if (bloco == NULL) {
        /* Alocacao falhou: exibe mensagem de erro */
        fprintf(stderr, "Erro: nao foi possivel alocar 1 GB de memoria.\n");
        return 1;
    }

    /* Alocacao bem-sucedida */
    printf("1 GB alocado com sucesso! Liberando imediatamente...\n");

    /* Libera a memoria */
    free(bloco);
    bloco = NULL;

    printf("Memoria liberada.\n");
    return 0;
}