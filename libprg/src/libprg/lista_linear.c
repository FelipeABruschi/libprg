#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CAPACIDADE_INICIAL 10

typedef struct Lista{
    int *valores;
    int tamanho;
    int capacidade;
    bool ordenada;
} Lista;

Lista *criar_lista()
{
    Lista *lista = (Lista *) malloc(sizeof(Lista));

    lista->valores = (int *) malloc (CAPACIDADE_INICIAL * sizeof (int));

    if(lista->valores == NULL)
    {
        printf("Erro na alocação.\n");
        exit(1);
    }
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->tamanho = 0;
    lista->ordenada = false;

    return lista;
}

Lista *criar_lista_ord()
{
    Lista *lista = criar_lista();
    lista->ordenada = true;
    return lista;
}

void imprimir(Lista *lista)
{
    for(int i = 0; i < lista->tamanho; i++)
        printf("%d ", lista->valores[i]);
}

void inserir(Lista *lista, int x)
{
    
}

void remover(Lista *lista, int x)
{
    int indice_removido = busca_binaria(lista, x);

    if(indice_removido >= 0)
        for(int i = indice_removido; i < lista->tamanho - 1; i++)
        {
            lista->valores[i] = lista->valores[i + 1];
            lista->tamanho -= 1;
        }
    else
        for(int i = 0; i < lista->tamanho; i++)
            if(x == lista->valores[i])
            {
                lista->valores[i] = lista->valores[lista->tamanho - 1];
                lista->tamanho -= 1;
                break;
            }
}

int busca_linear(Lista *lista, int x)
{
    //retorna o indice da posicao que esta o elemento ou -1 se nao existe na lista
    for(int i = 0; i < lista->tamanho; i++)
        if(x == lista->valores[i])
            return i;
    return -1;
}

int busca_binaria(Lista *lista, int x)
{
    // essa funçao vai retornar o indice do elemento encontrado
    int meio, final = lista->tamanho - 1, inicio = 0;

    if(lista->ordenada)
        while(inicio <= final)
        {
            meio = inicio + (final - inicio) / 2;
            if(lista->valores[meio] == x)
                return meio;
            else if(lista->valores[meio] < x)
                inicio = meio + 1;
            else
                final = meio - 1;
        }
    else
        return -1;
    // retorna -1 se a lista é nao ordenada.
}
