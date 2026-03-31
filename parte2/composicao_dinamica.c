#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char rua[128];
    int  numero;
    char cidade[64];
} Endereco;

typedef struct {
    char      nome[64];
    int       idade;
    Endereco *endereco;  /* ponteiro para Endereco alocado separadamente */
} Pessoa;

int main(void) {
    /* Aloca Endereco no heap */
    Endereco *end = (Endereco *)malloc(sizeof(Endereco));
    if (end == NULL) {
        fprintf(stderr, "Erro: falha ao alocar Endereco.\n");
        return 1;
    }

    /* Aloca Pessoa no heap */
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
    if (p == NULL) {
        fprintf(stderr, "Erro: falha ao alocar Pessoa.\n");
        free(end);
        return 1;
    }

    /* Conecta Pessoa ao Endereco */
    p->endereco = end;

    /* Preenche dados da Pessoa */
    printf("Nome: ");
    scanf(" %63[^\n]", p->nome);
    printf("Idade: ");
    scanf("%d", &p->idade);

    /* Preenche dados do Endereco */
    printf("Rua: ");
    scanf(" %127[^\n]", p->endereco->rua);
    printf("Numero: ");
    scanf("%d", &p->endereco->numero);
    printf("Cidade: ");
    scanf(" %63[^\n]", p->endereco->cidade);

    /* Exibe informacoes */
    printf("\n--- Dados ---\n");
    printf("Nome: %s | Idade: %d\n", p->nome, p->idade);
    printf("Endereco: %s, %d - %s\n",
           p->endereco->rua, p->endereco->numero, p->endereco->cidade);

    /* Libera: primeiro Endereco, depois Pessoa */
    free(p->endereco);
    p->endereco = NULL;
    free(p);
    p = NULL;

    return 0;
}