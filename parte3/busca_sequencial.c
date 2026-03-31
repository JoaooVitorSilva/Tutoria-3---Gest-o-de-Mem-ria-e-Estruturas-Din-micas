#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUTOS 10

typedef struct {
    int   id;
    float preco;
} Produto;

/* Percorre o vetor e retorna o endereco do produto com o id buscado, ou NULL */
Produto *buscar_por_id(Produto *vetor, int tamanho, int id) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i].id == id) {
            return &vetor[i];  /* retorna endereco do elemento encontrado */
        }
    }
    return NULL;  /* nao encontrado */
}

int main(void) {
    /* Aloca vetor de 10 produtos */
    Produto *produtos = (Produto *)malloc(NUM_PRODUTOS * sizeof(Produto));

    if (produtos == NULL) {
        fprintf(stderr, "Erro: falha ao alocar vetor de produtos.\n");
        return 1;
    }

    /* Preenche os produtos com IDs de 1 a 10 */
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        produtos[i].id    = i + 1;
        produtos[i].preco = (float)(i + 1) * 10.50f;
    }

    /* Exibe o catalogo */
    printf("Catalogo:\n");
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        printf("  ID: %2d | Preco: R$ %6.2f\n", produtos[i].id, produtos[i].preco);
    }

    /* Solicita ID para busca */
    int id_buscado;
    printf("\nDigite o ID a buscar: ");
    scanf("%d", &id_buscado);

    Produto *resultado = buscar_por_id(produtos, NUM_PRODUTOS, id_buscado);

    if (resultado != NULL) {
        printf("Produto encontrado -> ID: %d | Preco: R$ %.2f\n",
               resultado->id, resultado->preco);
    } else {
        printf("Produto com ID %d nao encontrado.\n", id_buscado);
    }

    free(produtos);
    produtos = NULL;

    return 0;
}
