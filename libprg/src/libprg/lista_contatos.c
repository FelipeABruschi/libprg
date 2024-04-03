#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ctt
{
    char nome[50];
    int numero[20];
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
    Lista_contatos lista =
}