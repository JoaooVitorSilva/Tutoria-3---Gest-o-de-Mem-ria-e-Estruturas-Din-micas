#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int   id;
    float preco;
} Produto;

/* Aloca um novo Produto e copia os dados de origem */
Produto *clonar(Produto *origem) {
    if (origem == NULL) return NULL;

    /* Aloca espaco para o clone no heap */
    Produto *clone = (Produto *)malloc(sizeof(Produto));

    if (clone == NULL) {
        fprintf(stderr, "Erro: falha ao alocar clone.\n");
        return NULL;
    }

    /* Copia os campos manualmente */
    clone->id    = origem->id;
    clone->preco = origem->preco;

    return clone;
}

int main(void) {
    /* Produto original no heap */
    Produto *original = (Produto *)malloc(sizeof(Produto));
    if (original == NULL) {
        fprintf(stderr, "Erro: falha ao alocar produto original.\n");
        return 1;
    }

    original->id    = 7;
    original->preco = 89.90f;

    printf("Original -> ID: %d | Preco: R$ %.2f\n", original->id, original->preco);

    /* Clona o produto */
    Produto *copia = clonar(original);
    if (copia == NULL) {
        free(original);
        return 1;
    }

    printf("Clone    -> ID: %d | Preco: R$ %.2f\n", copia->id, copia->preco);
    printf("Enderecos diferentes? %s\n", (original != copia) ? "Sim" : "Nao");

    free(original);
    original = NULL;
    free(copia);
    copia = NULL;

    return 0;
}
