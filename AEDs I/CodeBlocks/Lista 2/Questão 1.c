#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void printvet (int *, int);
int buscasequencial(int*, int, int, int*);
int buscabinaria(int*, int, int, int*);
void ordena (int *, int);
void vettroca (int *, int, int);

int main()
{
    int vet[TAM] = {0, 2, 4, 2, 5, 7, 2, 2, 9, 2};
    printvet(vet, TAM);
    int vetpos[TAM] = {0};
    printvet(buscasequencial(vet, TAM, 2, vetpos), TAM);

    ordena(vet, TAM);
    printvet(vet, TAM);
    int vetpos2[TAM] = {0};
    printvet(buscabinaria(vet, TAM, 2, vetpos2), TAM);

    return 0;
}

void printvet(int *vet, int tam)
{
    for(int i=0; i<tam; i++)
        {
            printf("%d\t", vet[i]);
            if(vet[i]==-1)
                break;
        }
    printf("\n\n");
}

int buscasequencial (int *vet, int tam, int elem, int *vetpos)
{
    int aux = 0;

    for(int i=0; i<tam; i++)
    {
        if(vet[i]==elem)
        {
            vetpos[aux]=i;
            aux++;
        }
    }
    vetpos[aux]=-1;
    return vetpos;
}

void vettroca (int *vet, int i, int j)
{
    int temp = vet[i];
    vet[i] = vet[j];
    vet[j] = temp;
}

void ordena (int *vet, int tam)
{
    for (int i=0; i<tam; i++)
    {
        for (int j=(i+1); j<tam; j++)
        {
            int menor = vet[i];
            if(vet[j]<vet[i])
                vettroca(vet, i, j);
        }
    }
}


int buscabinaria (int *vet, int tam, int elem, int *vetpos)
{
    int beg = 0;
    int end = tam-1;
    int ind;
    int aux = 0;

    while (end >= beg)
    {
        ind = (beg+end)/2;

        if(vet[ind]==elem)
        {
            vetpos[aux++]=ind;
            int i = ind+1;
            int j = ind-1;

            while(i<tam && vet[i]==elem)
                vetpos[aux++]=i++;

            while(j>=0 && vet[j]==elem)
                vetpos[aux++]=j--;

            break;

        }
        if(vet[ind]<elem)
            beg=ind+1;
        if(vet[ind]>elem)
            end=ind-1;
    }
    vetpos[aux]=-1;
    return vetpos;
}
