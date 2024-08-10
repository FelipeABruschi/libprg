#include "libprg/libprg.h"
#include <stdio.h>
#include <string.h>

#define CAPACIDADE_INICIAL 10
int id_inicial = 1;

#include <ctype.h>
#include <stddef.h>

//no linux nao precisava dessa função, mas precisei terminar o projeto
//pelo windows e precisei colocar para reconhcer na função de busca_trf
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

void ordenar_trfs(Lista_tarefas *lista, int forma, int modo)
{
    for(int i = 0; i < lista->tamanho; i++)
        for(int j = 0; j < lista->tamanho - 1; j++)
            switch (forma)
            {
                case 1:
                case 2:
                    if(modo == 1)
                        if(lista->trf[j].prazo < lista->trf[j + 1].prazo)
                        {
                            tarefa aux = lista->trf[j];
                            lista->trf[j] = lista->trf[j + 1];
                            lista->trf[j + 1] = aux;
                        }
                    else
                        if(lista->trf[j].prazo > lista->trf[j + 1].prazo)
                        {
                            tarefa aux = lista->trf[j];
                            lista->trf[j] = lista->trf[j + 1];
                            lista->trf[j + 1] = aux;
                        }
                    break;
                case 3:
                    if(modo == 1)
                        if(lista->trf[j].conclusao < lista->trf[j + 1].conclusao)
                        {
                            tarefa aux = lista->trf[j];
                            lista->trf[j] = lista->trf[j + 1];
                            lista->trf[j + 1] = aux;
                        }
                    else
                        if(lista->trf[j].conclusao > lista->trf[j + 1].conclusao)
                        {
                            tarefa aux = lista->trf[j];
                            lista->trf[j] = lista->trf[j + 1];
                            lista->trf[j + 1] = aux;
                        }
                    break;
                default: break;
            }
}

int salvar_trfs(Lista_tarefas *lista)
{
    FILE *arq = fopen("tarefas.bin", "wb");
    if(arq)
    {
        fprintf(arq, "%d\n", lista->tamanho);
        fwrite(lista->trf, sizeof(tarefa), lista->tamanho, arq);
        fclose(arq);
        return 0;
    }
    return 1;
}

int ler_trfs(Lista_tarefas *lista)
{
    FILE *arq = fopen("tarefas.bin", "rb");
    if(arq)
    {
        fscanf(arq, "%d\n", &lista->tamanho);
        fread(lista->trf, sizeof(tarefa), lista->tamanho, arq);
        fclose(arq);
        return 0;
    }
    return 1;
}




