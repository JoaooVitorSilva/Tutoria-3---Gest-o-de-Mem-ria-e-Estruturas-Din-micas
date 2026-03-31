#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int    id;
    float  preco;
} Produto;

int main(void) {
    /* Aloca a struct Produto no heap */
    Produto *p = (Produto *)malloc(sizeof(Produto));

    if (p == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memoria para Produto.\n");
        return 1;
    }

    /* Atribuicao exclusivamente pelo operador seta */
    p->id    = 101;
    p->preco = 49.90f;

    printf("Produto ID: %d\n",    p->id);
    printf("Preco: R$ %.2f\n",   p->preco);

    /* Libera a struct alocada */
    free(p);
    p = NULL;

    return 0;
}
