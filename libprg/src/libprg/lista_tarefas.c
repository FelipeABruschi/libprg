#include "libprg/libprg.h"
#include <stdio.h>
#include <string.h>

#define CAPACIDADE_INICIAL 10
int id_inicial = 1;

#include <ctype.h>
#include <stddef.h>

char *strcasestr(const char *haystack, const char *needle) {
    size_t needle_len;
    if ((needle_len = strlen(needle)) == 0) {
        return (char *)haystack;
    }

    for (; *haystack; ++haystack) {
        if (tolower(*haystack) == tolower(*needle)) {
            const char *h = haystack;
            const char *n = needle;

            while (*n && tolower(*h) == tolower(*n)) {
                ++h;
                ++n;
            }

            if (*n == '\0') {
                return (char *)haystack;
            }
        }
    }
    return NULL;
}

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
    nova_trf.conclusao = 00000000;
    nova_trf.codigo = id_inicial;
    id_inicial++;

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

Lista_tarefas* busca_trf(Lista_tarefas *lista, char *desc, char *prio, int prazo, int conc)
{
    Lista_tarefas *encontradas = criar_lista_trf();

    for(int i = 0; i < lista->tamanho; i++)
    {
        if(desc != "")
            if(strcasestr(lista->trf[i].descricao, desc) != NULL)
                add_trf(encontradas, lista->trf[i]);
        if(prio != "")
            if(strcasecmp(lista->trf[i].prioridade, prio) == 0)
                add_trf(encontradas, lista->trf[i]);
        if(prazo != 0)
            if(lista->trf[i].prazo == prazo)
                add_trf(encontradas, lista->trf[i]);
        if(conc != 0)
            if(lista->trf[i].conclusao == conc)
                add_trf(encontradas, lista->trf[i]);
    }
    return encontradas;
}

int edita_trf(Lista_tarefas *lista, int id, char *desc, char *prio, int prazo)
{
    for(int i = 0; i < lista->tamanho; i++)
        if(lista->trf[i].codigo == id)
        {
            strcpy(lista->trf[i].descricao, desc);
            strcpy(lista->trf[i].prioridade, prio);
            lista->trf[i].prazo = prazo;
            return 0;
        }
    return 1;
}

int concluir_trf(Lista_tarefas *lista, int id, int data)
{
    for(int i = 0; i < lista->tamanho; i++)
        if(lista->trf[i].codigo == id)
        {
            lista->trf[i].conclusao = data;
            lista->trf[i].status = 1;
            return 0;
        }
    return 1; //nao encontrou id
}




