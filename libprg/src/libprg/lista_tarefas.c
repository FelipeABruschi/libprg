#include "libprg/libprg.h"
#include <stdio.h>
#include <string.h>

#define CAPACIDADE_INICIAL 10
int id = 1;

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
    nova_trf.status = 0;
    nova_trf.conclusao = 0;
    nova_trf.codigo = id;
    id++;

    lista->trf[lista->tamanho] = nova_trf;
    lista->tamanho++;
    return 0;
}

int excluir_trf(Lista_tarefas *lista, int id)
{
    for(int i = 0; i < lista->tamanho; i++)
        if(lista->trf[i].codigo == id)
        {
            lista->trf[i] = lista->trf[lista->tamanho - 1];
            lista->tamanho--;
            return 0;
        }
    return 1; //id nao existe
}

Lista_tarefas* busca_trf(Lista_tarefas *lista, char *string)
{
    Lista_tarefas *encontradas = criar_lista_trf();

    for(int i = 0; i < lista->tamanho; i++)
    {
        if(strcasestr(lista->trf[i].descricao, string) != NULL)
            add_trf(encontradas, lista->trf[i]);
        else if(strcasecmp(string, lista->trf[i].prioridade) == 0)
            add_trf(encontradas, lista->trf[i]);
        else if(strcmp(string, lista->trf[i].prazo) == 0 || strcmp(string, lista->trf[i].conclusao) == 0)
            add_trf(encontradas, lista->trf[i]);
    }
    return encontradas;
}

tarefa* edita_trf(Lista_tarefas *lista, int id)
{
    for(int i = 0; i < lista->tamanho; i++)
        if(lista->trf[i].codigo == id)
            return &lista->trf[i];
    return NULL;
}

void concluir_trf(Lista_tarefas *lista, int id, int estado)
{
    for(int i = 0; i < lista->tamanho; i++)
        if(lista->trf[i].codigo == id)
            lista->trf[i].status = estado;
}




