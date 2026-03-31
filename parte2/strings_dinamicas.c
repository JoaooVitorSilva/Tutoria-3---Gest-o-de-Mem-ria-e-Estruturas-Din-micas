#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
} Usuario;

int main(void) {
    char buffer[256];

    /* Aloca a struct no heap */
    Usuario *u = (Usuario *)malloc(sizeof(Usuario));

    if (u == NULL) {
        fprintf(stderr, "Erro: falha ao alocar Usuario.\n");
        return 1;
    }

    /* Le o nome em um buffer temporario */
    printf("Digite o nome do usuario: ");
    scanf(" %255[^\n]", buffer);

    /* Aloca exatamente strlen(buffer) + 1 bytes para o nome */
    u->nome = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

    if (u->nome == NULL) {
        fprintf(stderr, "Erro: falha ao alocar string do nome.\n");
        free(u);
        return 1;
    }

    /* Copia o nome para a area alocada */
    strcpy(u->nome, buffer);

    printf("Usuario cadastrado: %s\n", u->nome);
    printf("Bytes alocados para o nome: %zu\n", strlen(u->nome) + 1);

    /* Libera primeiro o campo interno, depois a struct */
    free(u->nome);
    u->nome = NULL;
    free(u);
    u = NULL;

    return 0;
}