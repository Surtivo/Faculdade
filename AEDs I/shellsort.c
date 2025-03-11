#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8

void printvet (int *, int);
void vettroca (int *, int, int);
void shellsort (int *, int);

int main ()
{
    int vet[TAM] = {2, 8, 7, 1, 3, 5, 6, 4};
    printvet(vet, TAM);
    printf("\n");
    shellsort(vet, TAM);
    printvet(vet, TAM);

    return 0;
}

void printvet (int *vet, int t)
{
    for (int i = 0; i<t; i++)
        printf("%d\t", vet[i]);
}

void vettroca (int *vet, int k, int l)
{
    int temp = vet[k];
    vet[k]=vet[l];
    vet[l] = temp;
}

void shellsort (int *vet, int size)
{
    int i, j, value;

    int h=1;
    while (h < size)
        h = 3*h+1;

    while (h>0)
    {
        for (i = h; i<size; i++)
        {
            value = vet[i];
            j=i;
            while (j>(h-1) && value<=vet[j-h])
            {
                vet[j]= vet[j-h];
                j=j-h;
            }
            vet[j]=value;
        }
        h = h/3;
    }
}