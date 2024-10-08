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

typedef struct Lista_linear Lista_linear;

// Lista_linear *criar_lista(bool ordenada);
// void imprimir(Lista_linear *lista);
// void inserir(Lista_linear *lista, int x);
// void remover(Lista_linear *lista, int x);
// int busca_linear(Lista_linear *lista, int x);
// int busca_binaria(Lista_linear *lista, int x);
// int busca_bin_rec(Lista_linear *lista, int x, int inicio, int final);

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
void salvar_arq(Lista_contatos *lista);
void ler_arq(Lista_contatos *lista);

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

typedef struct no
{
    int valor;
    struct no* proximo;
}no;

typedef struct Lista_encadeada
{
    no* inicio;
    int tamanho;
    bool ordenada;
}Lista_encadeada;

void criar_lista_encadeada(Lista_encadeada *lista, bool ordenada);
void inserir_no(Lista_encadeada *lista, int valor);
bool remover_no(Lista_encadeada *lista, int valor);
no* buscar_no(Lista_encadeada *lista, int valor);
void destruir();

// algoritmos de ondenação

void bubble_sort_cres(int *vet, int tam);
void bubble_sort_dec(int *vet, int tam);
void selection_sort(int *vet, int tam);
void insertion_sort(int *vet, int tam);

// algoritmos de ordenação divisao e conquista

void merge_sort(int *vet, int esquerda, int direita);
void quick_sort(int *vet, int inicio, int fim);

typedef struct tarefa
{
    char descricao[50];
    char prioridade[10];
    int prazo;
    int conclusao;
    int status;
    int codigo;
}tarefa;

typedef struct Lista_tarefas
{
    tarefa *trf;
    int tamanho;
    int capacidade;
}Lista_tarefas;

Lista_tarefas *criar_lista_trf();
int add_trf(Lista_tarefas *lista, tarefa nova_trf);
int excluir_trf(Lista_tarefas *lista, int id);
Lista_tarefas* busca_trf(Lista_tarefas *lista, char *desc, char *prio, int prazo, int conc);
int edita_trf(Lista_tarefas *lista, int id, char *desc, char *prio, int prazo);
int concluir_trf(Lista_tarefas *lista, int id, int data);
void ordenar_trfs(Lista_tarefas *lista, int forma, int modo);
char *strcasestr(const char *haystack, const char *needle);
int salvar_trfs(Lista_tarefas *lista);
int ler_trfs(Lista_tarefas *lista);

// typedef struct no_arv
// {
//     int valor;
//     struct no_arv *esquerda;
//     struct no_arv *direita;
// }no_arv;
//
// no_arv *criar_no(int valor);
// void destruir_no(no_arv *no);
// no_arv *inserir_valor(no_arv *raiz, int valor);
// bool busca(no_arv *raiz, int valor);

typedef struct no_avl
{
    int valor;
    int altura; // altura da subárvore
    struct no_avl *esquerda;
    struct no_avl *direita;
} no_avl;

no_avl *criar_no(int valor);
int altura(no_avl *v);
int fator_balanceamento(no_avl *v);
no_avl *rotacao_esquerda(no_avl *v);
no_avl *rotacao_direita(no_avl *v);
no_avl *rotacao_dupla_esquerda(no_avl *v);
no_avl *rotacao_dupla_direita(no_avl *v);
no_avl *balancear(no_avl *v);
no_avl *inserir(no_avl *v, int valor);
no_avl *remover(no_avl *raiz, int valor);
int conta_rotacao();

#endif
