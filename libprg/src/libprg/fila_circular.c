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
