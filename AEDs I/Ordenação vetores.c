#include <stdio.h>
#define TAM 10

void printvet (int *, int);
void ordena (int *, int);
void vettroca (int *, int, int);
int buscabinaria (int *, int, int);
int minhabinaria (int *, int, int);

int main ()
{
    int vetor [TAM] = {1, 0, 9, 2, 8, 6, 5, 7, 3, 4};

    printvet(vetor, TAM);
    printf("\n\n");
    ordena(vetor, TAM);
    printvet(vetor, TAM);
    printf("\n\n\t\t %d Encontrado no indíce = %d", 9 ,buscabinaria(vetor, TAM, 9));
    printf("\n\n\t\t %d Encontrado no indíce = %d", 9, minhabinaria(vetor, TAM, 9));

    return 0;
}

void printvet (int *vet, int tam)
{
    for (int i=0; i<(tam); i++)
        printf("%d\t", vet[i]);
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

int buscabinaria (int *vet, int tam, int elem)
{
    int beg = 0;
    int end = (tam-1);
    int ind;

    while (end >= beg)
    {
        ind = (beg+end)/2;

        if(vet[ind]==elem)
            return ind;
        if(vet[ind]<elem)
            beg=ind+1;
        if(vet[ind]>elem)
            end=ind-1;
    }
    return -1;
}

int minhabinaria (int *vet, int tam, int elem)
{
    int beg = 0;
    int end = tam-1;
    int sum = 0;
    int ind;

    if(end%2==0)
        ind = end/2;
    if(end%2!=0)
        ind = (end/2)+1;

    while (sum<end)
    {
        if(vet[ind]==elem)
            return ind;

        if(vet[ind]>elem)
        {
            end=ind-1;

            if(end%2==0)
                ind = end/2;
            if(end%2!=0)
               ind = (end/2)+1;
        }

        if(vet[ind]<elem)
        {
            beg=ind+1;
            if((beg+end)%2==0)
                ind = (beg+end)/2;
            if((beg+end)%2!=0)
               ind = ((beg+end)/2)+1;
        }

        sum++;
        if(sum==tam-1)
            return -1;
    }
}
