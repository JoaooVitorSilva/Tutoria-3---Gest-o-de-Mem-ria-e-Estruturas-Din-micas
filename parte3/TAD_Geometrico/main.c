#include <stdio.h>
#include "ponto.h"

int main(void) {
    double x1, y1, x2, y2;

    printf("Ponto A - x: "); scanf("%lf", &x1);
    printf("Ponto A - y: "); scanf("%lf", &y1);
    printf("Ponto B - x: "); scanf("%lf", &x2);
    printf("Ponto B - y: "); scanf("%lf", &y2);

    /* Cria os dois pontos usando o TAD */
    Ponto *a = ponto_criar(x1, y1);
    Ponto *b = ponto_criar(x2, y2);

    if (a == NULL || b == NULL) {
        ponto_destruir(&a);
        ponto_destruir(&b);
        return 1;
    }

    /* Calcula e exibe a distancia */
    double dist = ponto_distancia(a, b);
    printf("Distancia entre A e B: %.4f\n", dist);

    /* Destroi os pontos (ponteiros sao anulados internamente) */
    ponto_destruir(&a);
    ponto_destruir(&b);

    return 0;
}
