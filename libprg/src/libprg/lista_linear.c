#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

void criar_lista(int *lista, int tamanho)
{
    lista = (int *) calloc (tamanho, sizeof(int));

    if(lista == NULL)
    {
        printf("Erro na alocação.\n");
        exit(EXIT_FAILURE);
    }
}
