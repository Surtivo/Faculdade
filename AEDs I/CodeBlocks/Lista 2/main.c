#include <stdio.h>
#define TAM 5

void printfvet (int *, int);
void vettroca (int *, int, int);
void inserctionsort (int *, int);
void inserctionsort2 (int *, int);
int buscabinaria (int*, int, int);

int main()
{
    int vet2[TAM] = {0, 2, 5, 4, 1};
    printfvet(vet2, TAM);

    printf("\n\n");

    inserctionsort2(vet2, TAM);
    printfvet(vet2, TAM);

	return 0;
}

void printfvet (int *vet, int t)
{
	for(int i=0; i<t; i++)
		printf("%d\t", vet[i]);
}

void vettroca (int *vet, int i, int j)
{
	int temp = vet[i];
	vet[i] = vet[j];
	vet[j] = temp;
}
void inserctionsort (int *vet, int t)
{
	for (int i=1; i<t; i++)
	{
		int j=i;
		while(j>0 && vet[j]<vet[j-1])
		{
			vettroca(vet, j, j-1);
			j--;
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

        if(vet[ind-1]<elem && vet[ind+1]>elem)
            return ind;
        if(vet[ind]<elem)
            beg=ind+1;
        if(vet[ind]>elem)
            end=ind-1;
    }
    return -1;
}

void inserctionsort2 (int *vet, int t)
{
	for (int i=1; i<t; i++)
	{
		int j=i;
		vettroca(vet, i, buscabinaria(vet, t, vet[i]));
	}
}
