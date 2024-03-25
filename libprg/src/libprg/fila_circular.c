#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Fila
{
    int *valores;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
} Fila;

Fila *criar_fila(int capacidade)
{
    Fila *fila = (Fila *) malloc(sizeof(Fila));

    fila->valores = (int *) malloc(capacidade * sizeof(int));

    if(fila->valores == NULL)
    {
        printf("erro na alocação.\n");
        exit(1);
    }

    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;

    return fila;
}

void imprimir_fila(Fila *fila)
{
    for(int i = 0; i < fila->tamanho; i++)
        printf("%d ", fila->valores[i]);
    printf("\n");
}

void enfileirar(Fila *fila, int x)
{
    fila->valores[fila->fim] = x;
    fila->fim++;

    fila->tamanho++;
}

void desenfileirar(Fila *fila)
{
    if(fila->inicio == fila->fim)
    {
        printf("fila já está vazia");
        exit(1);
    }

    fila->inicio++;

    fila->tamanho--;
}

int inicio(Fila *fila)
{
    return fila->valores[fila->inicio];
    //retorna o valor que esta no inicio da fila
}

int fim(Fila *fila)
{
    return fila->valores[fila->fim];
    //retorna o valor que esta no fim da fila
}

int tamanho(Fila *fila)
{
    return fila->tamanho;
    //retorna o total de elementos da fila
}

bool cheia(Fila *fila)
{
    if(fila->tamanho == fila->capacidade)
        return true;
    else
        return false;
}

bool vazia(Fila *fila)
{
    if(fila->tamanho == 0)
        return true;
    else
        return false;
}



