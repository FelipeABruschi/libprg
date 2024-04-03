#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

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
int busca_bin_rec(Lista *lista, int x, int inicio, int final);

typedef struct Fila Fila;

Fila *criar_fila(int capacidade);
void imprimir_fila(Fila *fila);
void enfileirar(Fila *fila, int x);
int desenfileirar(Fila *fila);
int getinicio(Fila *fila);
int getfim(Fila *fila);
int gettamanho_fila(Fila *fila);
bool isCheia(Fila *fila);
bool isFilaVazia(Fila *fila);

typedef struct Pilha Pilha;

Pilha *criar_pilha();
void empilhar(Pilha *pilha, char c);
char desempilhar(Pilha *pilha);
int gettamanho_pilha(Pilha *pilha);
bool isPilhaVazia(Pilha *pilha);

#endif
