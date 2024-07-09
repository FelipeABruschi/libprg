#include "libprg/libprg.h"

void bubble_sort_cres(int *vet, int tam)
{
    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam - 1; j++)
            if(vet[j] < vet[j + 1])
            {
                int aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
}

void bubble_sort_dec(int *vet, int tam)
{
    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam - 1; j++)
            if(vet[j] > vet[j + 1])
            {
                int aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
}

void insertion_sort(int *vet, int tam)
{
    for(int i = 1; i < tam - 1; i++)
    {
        int chave = vet[i];
        int j = i - 1;
        while(j >= 0 && vet[j] > chave)
        {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = chave;
    }
}

void selection_sort(int *vet, int tam)
{
    for(int i = 0; i < tam - 1; i++)
    {
        int menor = i;
        for(int j = ++i; j < tam; j++)
            if(vet[menor] > vet[j])
                menor = j;
        if(menor != i)
        {
            int auxiliar = vet[i];
            vet[i] = vet[menor];
            vet[menor] = auxiliar;
        }
    }
}