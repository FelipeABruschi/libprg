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

    if(lista == NULL)
    {
        printf("Erro na alocação.\n");
        exit(1);
    }
    lista->valores = (int *) malloc (CAPACIDADE_INICIAL * sizeof (int));
    if(lista->valores == NULL)
    {
        printf("erro na alocação.\n");
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
    printf("\n");
}

void inserir(Lista *lista, int x)
{
    if(lista->tamanho == lista->capacidade)
    {
        lista->capacidade *= 2;
        lista->valores = (int *) realloc(lista->valores, lista->capacidade * sizeof(int));
    }
    if(lista->ordenada)
    {
        int indice_colocado = 0;
        for(int i = 0; i < lista->tamanho; i++)
        {
            if(lista->valores[i] == x)
            {
                printf("elemento ja esta na lista.\n");
                exit(1);
            }
            if(x < lista->valores[i])
            {
                indice_colocado = i;
                break;
            }
            else
                indice_colocado = lista->tamanho;
        }
        for(int i = lista->tamanho; i > indice_colocado; i--)
            lista->valores[i] = lista->valores[i - 1];
        lista->valores[indice_colocado] = x;
    }
    else
        lista->valores[lista->tamanho] = x;
    lista->tamanho++;
}

void remover(Lista *lista, int x)
{
    int indice_removido = busca_binaria(lista, x);

    if(indice_removido >= 0)
        for(int i = indice_removido; i < lista->tamanho - 1; i++)
            lista->valores[i] = lista->valores[i + 1];
    else
    {
        indice_removido = busca_linear(lista, x);
        if(indice_removido >= 0)
            lista->valores[indice_removido] = lista->valores[lista->tamanho - 1];
        else
        {
            printf("elemento nao esta na lista.\n");
            exit(1);
        }
    }
    lista->tamanho--;
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
        return -1; // retorna -1 se a lista é nao ordenada.
    printf("elemento nao esta na lista.\n");
    exit(1);
}

int busca_bin_rec(Lista *lista, int x, int inicio, int final)
{
    if(lista->ordenada)
    {
        if(inicio <= final)
        {
            int meio = inicio + (final - inicio) / 2;
            if(lista->valores[meio] == x)
                return meio;
            else if(lista->valores[meio] < x)
                return busca_bin_rec(lista, x, meio + 1, final);
            else
                return busca_bin_rec(lista, x, inicio, meio - 1);
        }
    }
    else
        return -1; // retorna -1 se a lista é nao ordenada.
    printf("elemento nao esta na lista.\n");
    exit(1);
}
