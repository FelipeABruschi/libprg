#include "libprg/libprg.h"
#include <stdio.h>
#include <string.h>

#define CAPACIDADE_INICIAL 10

Lista_contatos *criar_lista_ctt()
{
    Lista_contatos *lista = (Lista_contatos *) malloc(sizeof(Lista_contatos));
    if(lista == NULL)
    {
        printf("erro na alocacao.\n");
        exit(1);
    }
    lista->contatos = (ctt *) malloc(CAPACIDADE_INICIAL * sizeof(ctt));
    if(lista->contatos == NULL)
    {
        printf("erro na alocacao.\n");
        exit(1);
    }
    lista->tamanho = 0;
    lista->capacidade = CAPACIDADE_INICIAL;

    return lista;
}

void imprimir_ctt(Lista_contatos *lista)
{
    for(int i = 0; i < lista->tamanho; i++)
    {
        printf("%s\t", lista->contatos[i].nome);
        printf("%s\t", lista->contatos[i].numero);
        printf("%s\n", lista->contatos[i].email);
    }
}

void add_ctt(Lista_contatos *lista, ctt novo_ctt)
{
    if(lista->tamanho == lista->capacidade)
    {
        lista->capacidade *= 2;
        lista->contatos = (ctt *) realloc(lista->contatos, lista->capacidade * sizeof(ctt));
        if(lista->contatos == NULL)
        {
            printf("ERRO NA REALOCACAO AO AUMENTAR CAPACIDADE DA LISTA.\n");
            exit(1);
        }
    }
    lista->contatos[lista->tamanho] = novo_ctt;
    lista->tamanho++;
}

int excluir_ctt(Lista_contatos *lista, char *nome)
{
    for(int i = 0; i < lista->tamanho; i++)
        if(strcasecmp(lista->contatos[i].nome, nome) == 0)
        {
            lista->contatos[i] = lista->contatos[lista->tamanho - 1];
            lista->tamanho--;
            return 0;
        }
    //contato nao existe
    return 1;
}

Lista_contatos* busca_ctt(Lista_contatos *lista, char *nome)
{
    Lista_contatos* encontrados = criar_lista_ctt();

    for(int i = 0; i < lista->tamanho; i++)
        if(strcasestr(lista->contatos[i].nome, nome) != NULL)
            add_ctt(encontrados, lista->contatos[i]);
    return encontrados;
}

ctt* edita_ctt(Lista_contatos *lista, char *nome)
{
    for(int i = 0; i < lista->tamanho; i++)
        if(strcasecmp(lista->contatos[i].nome, nome) == 0)
            return &lista->contatos[i];
    return NULL;
}



