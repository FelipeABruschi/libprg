#include "libprg/libprg.h"
#include <stdio.h>

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
        printf("erro ao criar novo nó.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}

