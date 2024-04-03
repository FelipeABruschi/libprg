#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#define CAPACIDADE_INICIAL 10

typedef struct Pilha
{
    char *caracteres;
    int topo;
    int tamanho;
    int capacidade;
}Pilha;

Pilha *criar_pilha()
{
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    if(pilha == NULL)
    {
        printf("erro na alocacao.\n");
        exit(1);
    }

    pilha->caracteres = (char *) malloc(CAPACIDADE_INICIAL * sizeof(char));
    if(pilha->caracteres == NULL)
    {
        printf("erro na alocacao.\n");
        exit(1);
    }

    pilha->topo = -1;
    pilha->tamanho = 0;
    pilha->capacidade = CAPACIDADE_INICIAL;

    return pilha;
}

void empilhar(Pilha *pilha, char c)
{
    if(pilha->tamanho == pilha->capacidade)
    {
        pilha->capacidade *= 2;
        pilha->caracteres = (char *) realloc(pilha->caracteres, pilha->capacidade * sizeof(char));
        if(pilha->caracteres == NULL)
        {
            printf("erro na realocacao ao aumentar a capacidade da pilha.\n");
            exit(1);
        }
    }
    pilha->topo++;
    pilha->caracteres[pilha->topo] = c;
    pilha->tamanho++;
}

char desempilhar(Pilha *pilha)
{
    if(pilha->tamanho == 0)
    {
        printf("pilha esta vazia.\n");
        exit(1);
    }
    char c = pilha->caracteres[pilha->topo];
    pilha->topo--;
    pilha->tamanho--;
    return c;
}

int gettamanho_pilha(Pilha *pilha)
{
    return pilha->tamanho;
}

bool isPilhaVazia(Pilha *pilha)
{
    if(pilha->tamanho == 0)
        return true;
    else
        return false;
}

