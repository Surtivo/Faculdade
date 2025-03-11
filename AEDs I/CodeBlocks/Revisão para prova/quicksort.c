#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8

//Feito com material da aula.
void printvet (int *, int);
void quicksort (int *, int, int);
int partition (int *, int, int);
void vettroca (int *, int, int);

//Feito com material do v�deo: https://www.youtube.com/watch?v=lL0tox33q90
int particiona(int*, int, int);
void QuickSort(int*, int, int);

void printvet (int *vet, int t)
{
    for (int i = 0; i<t; i++)
        printf("%d ", vet[i]);
    printf("\n\n");
}

void vettroca (int *vet, int k, int l)
{
    int temp = vet[k];
    vet[k]=vet[l];
    vet[l] = temp;
}

int partition (int *vet, int p, int r)
{
    int x = vet[r];
    int i = p-1;

    for (int j=p; j<=(r-1); j++)
    {
        if (vet[j]<=x)
        {
            i=i+1;
            vettroca (vet, i, j);
        }
    }
    vettroca(vet, i+1, r);
    return i+1;
}

void quicksort (int *vet, int p, int r)
{
    if (p<r)
    {
        int q = partition(vet, p, r);
        quicksort (vet, p, q-1);
        quicksort (vet, q+1, r);
    }
}

//COM BASE NO V�DEO

int particiona(int *vet, int beg, int end)
{
    int pivo = (vet[beg]+vet[end]+vet[(beg+end)/2])/3; //Desse modo estimamos o melhor pivo com essa soma ao inv�s de usar um n�mero do pr�prio vetor.

    while(beg<end)
    {
        while(beg<end && vet[beg]<=pivo)
            beg++;
        while(beg<end && vet[end]>pivo)
            end--;
        vettroca(vet, beg, end);
    }
    return beg; //Nesse ponto beg e end � para serem iguais ao meio do vetor.
}

void QuickSort(int *vet, int beg, int end)
{
    if(beg<end)
    {
        int mid = particiona(vet, beg, end);
        QuickSort(vet, beg, mid-1);
        QuickSort(vet, mid, end);
    }
}
