#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

void criar_lista(Lista *lista, int tamanho)
{
    lista->valores = (int *) calloc (tamanho, sizeof(int));

    if(lista->valores == NULL)
    {
        printf("Erro na alocação.\n");
        exit(1);
    }
    lista->tamanho = tamanho;
    lista->qtd_elementos = 0;
}

void imprimir(Lista *lista)
{
    for(int i = 0; i < lista->qtd_elementos; i++)
        printf("%d ", lista->valores[i]);
}

void inserir_nao_ord(Lista *lista, int x)
{
    for(int i = 0; i < lista->qtd_elementos; i++)
        if(x == lista->valores[i])
        {
            printf("valor ja pertence a lista.\n");
            exit(1);
        }
    lista->valores[lista->qtd_elementos] = x;
    lista->qtd_elementos += 1;
}

void inserir_ord(Lista *lista, int x)
{
    int aux1 = 0, aux2 = lista->qtd_elementos;

    for(int i = 0; i < lista->qtd_elementos; i++)
    {
        if(x == lista->valores[i])
        {
            printf("valor ja pertence a lista.\n");
            exit(1);
        }
        if(x < lista->valores[i])
        {
            aux1 = i;
            break;
        }
    }
    //aux1 = posicao que o X vai ser colocado
    //aux2 = final da lista
    for(int i = aux2; i > aux1; i--)
        lista->valores[i] = lista->valores[i - 1];
    lista->valores[aux1] = x;
    lista->qtd_elementos += 1;
}

int busca_linear(Lista *lista, int x)
{
    //retorna o indice da posicao que esta o elemento ou -1 se nao existe na lista
    for(int i = 0; i < lista->qtd_elementos; i++)
        if(x == lista->valores[i])
            return i;
    return -1;
}

void remover_nao_ord(Lista *lista, int x)
{
    for(int i = 0; i < lista->qtd_elementos; i++)
        if(x == lista->valores[i])
        {
            lista->valores[i] = lista->valores[lista->qtd_elementos - 1];
            lista->valores[lista->qtd_elementos - 1] = 0;
            lista->qtd_elementos -= 1;
            break;
        }
}
