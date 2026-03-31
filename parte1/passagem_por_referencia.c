#include <stdio.h>

/* Funcao que recebe um ponteiro para int e dobra o valor apontado */
void dobrar(int *num) {
    *num = (*num) * 2;  /* modifica diretamente o valor no endereco recebido */
}

int main(void) {
    int valor;

    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);

    printf("Valor original: %d\n", valor);

    /* Passa o endereco de 'valor' para a funcao */
    dobrar(&valor);

    printf("Valor apos dobrar: %d\n", valor);

    return 0;
}
