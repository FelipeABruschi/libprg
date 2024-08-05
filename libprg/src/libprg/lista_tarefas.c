#include "libprg/libprg.h"
#include <stdio.h>
#include <string.h>

#define CAPACIDADE_INICIAL 10

Lista_tarefas *criar_lista_trf()
{
    Lista_tarefas *lista = (Lista_tarefas *) malloc(sizeof(Lista_tarefas));
    if(lista == NULL)
        exit(1);
    lista->trf = (tarefa *) malloc(CAPACIDADE_INICIAL * sizeof(tarefa));
    if(lista->trf == NULL)
        exit(1);
    lista->tamanho = 0;
    lista->capacidade = CAPACIDADE_INICIAL;

    return lista;
}

int add_trf(Lista_tarefas *lista, tarefa nova_trf)
{
    if(lista->tamanho == lista->capacidade)
    {
        lista->capacidade *= 2;
        lista->trf = (tarefa *) realloc(lista->trf, lista->capacidade * sizeof(tarefa));
        if(lista->trf == NULL)
            return 1;
    }
    nova_trf.codigo = lista->tamanho + 1; // errado, verificar ainda como vou atribuir o id
    lista->trf[lista->tamanho] = nova_trf;
    lista->tamanho++;
    return 0;
}

int excluir_trf(Lista_tarefas *lista, int id)
{
    for(int i = 0; i < lista->tamanho; i++)
        if(lista->trf[i].codigo == id)
            lista->trf[i] = lista->trf[lista->tamanho - 1];
    return 1; //id nao existe
}






