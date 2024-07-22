#include "libprg/libprg.h"

void merge(int *vet, int esquerda, int meio, int direita)
{
    int aux[direita - esquerda + 1];
    int i = esquerda, j = meio + 1, k = 0;
    while(i <= meio && j <= direita)
    {
        if(vet[i] <= vet[j])
        {
            aux[k] = vet[i];
            i++;
        }
        else
        {
            aux[k] = vet[j];
            j++;
        }
        k++;
    }
    while(i <= meio)
    {
        aux[k] = vet[i];
        i++, k++;
    }
    while(j <= direita)
    {
        aux[k] = vet[j];
        j++, k++;
    }
    for(int l = esquerda; l <= direita; l++)
        vet[l] = aux[l - esquerda];
}

void merge_sort(int *vet, int esquerda, int direita)
{
    if(esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        merge_sort(vet, esquerda, meio);
        merge_sort(vet, meio + 1, direita);

        merge(vet, esquerda, meio, direita);
    }
}

int particao_hoare(int *vet, int inicio, int fim)
{
    int pivo = (vet[inicio] + vet[fim] + vet[(inicio + fim) / 2]) / 3;
    while(inicio < fim)
    {
        while(inicio < fim && pivo >= vet[inicio])
            inicio++;
        while(inicio < fim && pivo < vet[fim])
            fim--;
        int aux = vet[inicio];
        vet[inicio] = vet[fim];
        vet[fim] = aux;
    }
    return inicio;
}

void quick_sort(int *vet, int inicio, int fim)
{
    if(inicio < fim)
    {
        int posicao = particao_hoare(vet, inicio, fim);
        quick_sort(vet, inicio, posicao - 1);
        quick_sort(vet, posicao, fim);
    }
}

