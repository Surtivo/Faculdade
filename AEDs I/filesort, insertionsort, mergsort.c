#include <stdio.h>
#define TAM 5

void printfvet (int *, int);
void vettroca (int *, int, int);
void selectionsort (int *, int);
void inserctionsort (int *, int);
void MergeSort (int*, int*, int, int);
void merge (int *, int, int ,int);

int main()
{
    int vet2[TAM] = {0, 2, 5, 4, 1};
    printfvet(vet2, TAM);
    inserctionsort(vet2, TAM);
    printfvet(vet2, TAM);
    /*for (int o = 0; o < TAM; o++) printf("%d\t ", vet2[o]);
    printf("\n\n");
    int aux[TAM];
    MergeSort (vet2, aux, 0, TAM-1);
    printf("\n\n");
    for (int o = 0; o < TAM; o++) printf("%d\t ", vet2[o]);*/

	return 0;
}


//Feito pelo vídeo: https://www.youtube.com/watch?v=sWR3fWHs_Bg

void MergeSort (int* vet, int *aux, int beg, int end)
{

    int mid, i, j, k;

    if(beg<end)
    {
        mid = (beg+end)/2;
        MergeSort(vet, aux, beg, mid);
        MergeSort(vet, aux, mid+1, end);

        //Faz o merge ordenando os elementos.

        i = beg;
        j = mid+1;
        k = beg;

        while(i<=mid && j<=end)
        {
            if(vet[i]<vet[j])
            {
                aux[k]= vet[i];
                i++;
            }

            else
            {
                aux[k]=vet[j];
                j++;
            }
            k++;
        }

        while(i<=mid)
        {
            aux[k]= vet[i];
            i++;
            k++;
        }

        while(j<=end)
        {
            aux[k]=vet[j];
            j++;
            k++;
        }

        for(i=beg; i<=end; i++)
            vet[i]=aux[i];
    }
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

void selectionsort (int *vet, int t)
{
    int menor;
	for(int i=0; i<t-1; i++)
	{
	    menor = i;

		for(int j=(i+1); j<t; j++)
		{
			if(vet[j]<vet[menor])
			    menor=j;
		}
		vettroca(vet, i, menor);
	}
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

