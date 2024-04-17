#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>
#include <stdlib.h>


typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

typedef struct Lista Lista;

Lista *criar_lista(bool ordenada);
void imprimir(Lista *lista);
void inserir(Lista *lista, int x);
void remover(Lista *lista, int x);
int busca_linear(Lista *lista, int x);
int busca_binaria(Lista *lista, int x);
int busca_bin_rec(Lista *lista, int x, int inicio, int final);

typedef struct ctt
{
    char nome[50];
    char numero[15];
    char email[50];
}ctt;

typedef struct Lista_contatos
{
    ctt *contatos;
    int tamanho;
    int capacidade;
}Lista_contatos;

Lista_contatos *criar_lista_ctt();
void imprimir_ctt(Lista_contatos *lista);
void add_contato(Lista_contatos *lista, ctt novo_ctt);
int excluir_ctt(Lista_contatos *lista, char *s);
Lista_contatos* busca_ctt(Lista_contatos *lista, char *s);
ctt* edita_ctt(Lista_contatos *lista, char *s);

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

typedef struct no no;
typedef struct Lista_encadeada Lista_encadeada;

Lista_encadeada* criar_lista_encadeada(bool ordenada);
void inserir_no(Lista_encadeada* lista, int valor);
void remover_no();
int buscar_no();
void destruir();

#endif
