#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int   id;
    float preco;
} Produto;

/* Zera todos os campos da struct apontada por p */
void reset_estoque(Produto *p) {
    p->id    = 0;
    p->preco = 0.0f;
}

int main(void) {
    /* Aloca produto no heap */
    Produto *prod = (Produto *)malloc(sizeof(Produto));

    if (prod == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memoria.\n");
        return 1;
    }

    /* Atribui valores iniciais */
    prod->id    = 55;
    prod->preco = 199.99f;

    printf("Antes do reset -> ID: %d | Preco: %.2f\n", prod->id, prod->preco);

    /* Chama a funcao de reset */
    reset_estoque(prod);

    printf("Apos o reset  -> ID: %d | Preco: %.2f\n", prod->id, prod->preco);

    free(prod);
    prod = NULL;

    return 0;
}
