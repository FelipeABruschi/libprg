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
    if(fila == NULL)
    {
        printf("erro na alocação.\n");
        exit(1);
    }
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
    fila->valores[fila->fim % fila->capacidade] = x;
    fila->fim++;

    fila->tamanho++;
}

int desenfileirar(Fila *fila)
{
    if(fila->inicio == fila->capacidade - 1)
        fila->inicio = 0;
    else if(fila->inicio == fila->fim)
    {
        printf("fila já está vazia");
        exit(1);
    }
    else
        fila->inicio++;
    
    fila->tamanho--;
}

int getinicio(Fila *fila)
{
    if(fila->tamanho == 0)
    {
        printf("fila está vazia");
        exit(1);
    }
    return fila->valores[fila->inicio];
    //retorna o valor que esta no inicio da fila
}

int getfim(Fila *fila)
{
    if(fila->tamanho == 0)
    {
        printf("fila está vazia");
        exit(1);
    }
    if(fila->fim == 0)
        return fila->valores[fila->capacidade - 1];

    return fila->valores[fila->fim - 1];
    //retorna o valor que esta no fim da fila
}

int gettamanho(Fila *fila)
{
    return fila->tamanho;
}

bool isCheia(Fila *fila)
{
    if(fila->tamanho == fila->capacidade)
        return true;
    else
        return false;
}

bool isVazia(Fila *fila)
{
    if(fila->tamanho == 0)
        return true;
    else
        return false;
}



