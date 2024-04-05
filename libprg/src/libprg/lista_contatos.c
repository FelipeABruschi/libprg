#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE_INICIAL 10

typedef struct ctt
{
    char nome[50];
    int numero;
    char email[50];
}ctt;

typedef struct Lista_contatos
{
    ctt *contatos;
    int tamanho;
    int capacidade;
}Lista_contatos;

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
        printf("%s ", lista->contatos[i].nome);
        printf("%d ", lista->contatos[i].numero);
        printf("%s ", lista->contatos[i].email);
        printf("\n");
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

int excluir_ctt(Lista_contatos *lista, char *s)
{
    for(int i = 0; i < lista->tamanho; i++)
    {
        if(strcasecmp(lista->contatos[i].nome, s) == 0)
        {
            lista->contatos[i] = lista->contatos[lista->tamanho - 1];
            lista->tamanho--;
            return i;
        }
    }
}

int busca_ctt(Lista_contatos *lista, char *s)
{

}



