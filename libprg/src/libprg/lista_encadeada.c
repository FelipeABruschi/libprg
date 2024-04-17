#include "libprg/libprg.h"

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

Lista_encadeada* criar_lista_encadeada(bool ordenada)
{
    Lista_encadeada* lista = (Lista_encadeada *) malloc(sizeof(Lista_encadeada));

    if(lista == NULL)
        return lista;

    lista->inicio = NULL;
    lista->tamanho = 0;
    lista->ordenada = ordenada;

    return lista;
}

void inserir_no(Lista_encadeada* lista, int valor)
{
    no *novo = (no*) malloc(sizeof(no));
    if(novo == NULL)
    {

        exit(1);
    }
    novo->valor = valor;
    novo->proximo = NULL;
    lista->inicio = novo;
    lista->tamanho++;
}

