#include "libprg/libprg.h"
#include <stdio.h>

void criar_lista_encadeada(Lista_encadeada *lista, bool ordenada)
{
    lista->inicio = NULL;
    lista->tamanho = 0;
    lista->ordenada = ordenada;
}

void inserir_no(Lista_encadeada* lista, int valor)
{
    no *novo = (no*) malloc(sizeof(no));
    if(novo == NULL)
    {
        printf("erro ao criar novo nó.\n");
        exit(1);
    }

    novo->valor = valor;
    novo->proximo = NULL;
    if(lista->tamanho == 0)
        lista->inicio = novo;
    else
    {
        no *aux = lista->inicio;
        while(aux != NULL)
            aux = aux->proximo;
        aux = novo;
    }
    lista->tamanho++;
}

bool remover_no(Lista_encadeada *lista, int valor)
{
    no *aux = buscar_no(lista, valor);

    if(aux == NULL)
        return false;
    else
        aux = aux->proximo->proximo;
}

no* buscar_no(Lista_encadeada *lista, int valor)
{
    no *aux = lista->inicio;

    if(aux->valor == valor)
        return aux;
    for(int i = 1; i < lista->tamanho; i++)
    {
        if(aux->proximo->valor == valor)
            return aux;
        else
            aux = aux->proximo;
    }
    return NULL;
    //retorna o ponteiro para o nó ou NULL se o valor nao existe na lista
}

