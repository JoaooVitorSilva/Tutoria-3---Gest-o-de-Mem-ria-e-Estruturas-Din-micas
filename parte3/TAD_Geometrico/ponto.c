#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

/* Definicao interna da struct — invisivel fora deste arquivo */
struct Ponto {
    double x;
    double y;
};

/* Aloca e inicializa um Ponto no heap */
Ponto *ponto_criar(double x, double y) {
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    if (p == NULL) {
        fprintf(stderr, "Erro: falha ao alocar Ponto.\n");
        return NULL;
    }

    p->x = x;
    p->y = y;

    return p;
}

/* Calcula a distancia euclidiana: sqrt((x2-x1)^2 + (y2-y1)^2) */
double ponto_distancia(const Ponto *a, const Ponto *b) {
    if (a == NULL || b == NULL) return -1.0;

    double dx = b->x - a->x;
    double dy = b->y - a->y;

    return sqrt(dx * dx + dy * dy);
}

/* Libera a memoria e anula o ponteiro do chamador via ponteiro duplo */
void ponto_destruir(Ponto **p) {
    if (p == NULL || *p == NULL) return;

    free(*p);
    *p = NULL;  /* anula o ponteiro original no chamador */
}
