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
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}

bool remover_no(Lista_encadeada *lista, int valor)
{
    no *aux1 = lista->inicio;
    no *aux2 = aux1->proximo;
    bool result;

    if(aux1->valor == valor)
    {
        lista->inicio = aux1->proximo;
        free(aux1);
        result = true;
    }
    else
    {
        while(aux2)
        {
            if(aux2->valor == valor)
            {
                aux1 = aux2->proximo;
                break;
            }
            else
            {
                aux1 = aux2;
                aux2 = aux2->proximo;
            }
        }
        free(aux2);
    }


}

no* buscar_no(Lista_encadeada *lista, int valor)
{
    no *aux = lista->inicio;

    while(aux)
    {
        if(aux->valor == valor)
            return aux;
        else
            aux = aux->proximo;
    }
    return NULL;
    //retorna o ponteiro para o nó ou NULL se o valor nao existe na lista
}

