#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

typedef struct Lista Lista;

Lista *criar_lista();
Lista *criar_lista_ord();
void imprimir(Lista *lista);
void inserir(Lista *lista, int x);
void remover(Lista *lista, int x);
int busca_linear(Lista *lista, int x);
int busca_binaria(Lista *lista, int x);

#endif
