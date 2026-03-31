#ifndef PONTO_H
#define PONTO_H

/* Declaracao opaca: o cliente nao enxerga os campos internos */
typedef struct Ponto Ponto;

/*
 * ponto_criar - aloca e inicializa um novo Ponto no heap.
 * Retorna ponteiro para o Ponto criado, ou NULL em caso de falha.
 */
Ponto *ponto_criar(double x, double y);

/*
 * ponto_distancia - calcula a distancia euclidiana entre dois pontos.
 * Retorna o valor double da distancia.
 */
double ponto_distancia(const Ponto *a, const Ponto *b);

/*
 * ponto_destruir - libera a memoria alocada para o Ponto.
 * Define o ponteiro como NULL apos a liberacao (via ponteiro duplo).
 */
void ponto_destruir(Ponto **p);

#endif /* PONTO_H */