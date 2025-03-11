#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct aluno
{
    int mat;
    int notaf;
}Aluno;

void enche (Aluno *vet, int tam);
void insertionsort (Aluno *vet, int t);
void vettroca(Aluno *vet, int i, int j);
void selectionsort (Aluno *vet, int t);

int main()
{
    Aluno vet[TAM];
    enche(vet, TAM);

    for(int i=0; i<TAM; i++)
    {
        printf("%d\t%d\n", vet[i].mat, vet[i].notaf);
    }

    printf("\n\n");

    insertionsort(vet, TAM);
    for(int i=0; i<TAM; i++)
    {
        printf("%d\t%d\n", vet[i].mat, vet[i].notaf);
    }

    printf("\n\n");

    selectionsort(vet, TAM);
    for(int i=0; i<TAM; i++)
    {
        printf("%d\t%d\n", vet[i].mat, vet[i].notaf);
    }

    return 0;
}

void enche (Aluno *vet, int tam)
{
    int i=6;
    int j=50;

    for(int s=0; s<tam; s++)
    {
        vet[s].mat = i++;
        vet[s].notaf = j;
        j=j-10;
    }
}

void insertionsort (Aluno *vet, int t)
{
	for (int i=1; i<t; i++)
	{
         int j=i;
         while(j>0 && vet[j].mat<vet[j-1].mat)
         {
            vettroca(vet, j, j-1);
            j--;
         }
    }
}

void vettroca (Aluno *vet, int i, int j)
{
    Aluno temp = vet[i];
    vet[i] = vet[j];
    vet[j] = temp;
}

void selectionsort (Aluno *vet, int t)
{
    int menor;
        for(int i=0; i<t-1; i++)
        {
            menor = i;

                for(int j=(i+1); j<t; j++)
                {
                        if(vet[j].notaf<vet[menor].notaf)
                            menor=j;
                }
                vettroca(vet, i, menor);
        }
}


