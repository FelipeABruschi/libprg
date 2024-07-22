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

