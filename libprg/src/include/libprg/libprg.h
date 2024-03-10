#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

typedef struct {
    int *valores;
    int tamanho;
    int qtd_elementos;
} Lista;

void criar_lista(Lista *lista, int tamanho);
void imprimir(Lista *lista);
void inserir_nao_ord(Lista *lista, int x);
int busca_linear(Lista *lista, int x);
void remover_nao_ord(Lista *lista, int x);

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

#endif
