#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int buscasequencial (int*, int, int);
int buscabinaria (int*, int, int);
int buscabinariaRecursiva (int*, int, int, int);
void printvet (int*, int);
void vettroca (int*, int, int);
void ordena (int*, int);
int fib (int, int*);
int fibon (int);
void invertevet (int*, int, int);
int somapartes (int, int);

//Lista 1, não fiz a 7, nem a 9 e muito menos o desafio!

int main()
{
    int vet[TAM] = {0, 2, 4, 5, 1};
    printvet(vet, TAM);
    printf("\t");
    buscasequencial(vet, TAM, 1);

    printf("\n");
    ordena(vet, TAM);
    printvet(vet, TAM);
    printf("\tElemento encontrado no indice %d\n\n", buscabinaria(vet, TAM, 5));
    printvet(vet, TAM);
    printf("\tElemento encontrado no indice %d\n\n\n", buscabinariaRecursiva(vet, 5, 0, TAM-1));

    int count = 0;

    printf("%d\n", fib(5, &count));
    printf("\t\t\t\t   Contador: %d\n\n", count);

    printf("%d\n\n", fibon(5));

    invertevet(vet, 0, TAM-1);
    printvet(vet, TAM);
    printf("\n\n");

    int soma = 0;
    int somado = 1250;
    printf("\t\t\t\tNumero: %d  Soma:%d\n\n", somado, somapartes(somado, soma));

    return 0;
}

int buscasequencial (int* vet, int tam, int elem)
{
    for(int i=0; i<tam; i++){
        if(vet[i]==elem)
        {
            printf("Numero encontrado no indice %d\n", i);
            return 0;
        }
    }
}

void printvet(int* vet, int tam)
{
    for(int i=0; i<tam; i++)
        printf("%d\t", vet[i]);
}

void vettroca(int* vet, int i, int j)
{
    int aux;
    aux=vet[i];
    vet[i]=vet[j];
    vet[j]=aux;
}

void ordena (int* vet, int tam)
{
    for (int i=0; i<tam; i++)
    {
        for (int j=(i+1); j<tam; j++)
        {
            if(vet[j]<vet[i])
                vettroca(vet, i, j);
        }
    }
}

int buscabinaria(int* vet, int tam, int elem)
{
    int beg = 0;
    int end = tam-1;
    int meio;

    while(end >= beg)
    {
        meio  = (beg+end)/2;

        if(vet[meio]==elem)
            return meio;
        if(vet[meio]<elem)
            beg=meio+1;
        if(vet[meio]>elem)
            end=meio-1;
    }
    return -1;
}



int buscabinariaRecursiva(int *vet, int elem, int beg, int end)
{
    int meio = (beg+end)/2;

    if (beg > end)
        return -1;
    if(vet[meio]==elem)
        return meio;
    if(vet[meio]<elem)
        return buscabinariaRecursiva(vet, elem, meio+1, end);
    if(vet[meio]>elem)
        return buscabinariaRecursiva(vet, elem, beg, meio-1);
}

int fib (int n, int *count)
{
    *count=*count+1;
    if(n==1 || n==2)
        return 1;
    else return (fib(n-1, count)+fib(n-2, count));
}

int fibon (int n)
{
    int *vet = (int*)malloc(n*sizeof(int));

    if(n<=2)
        return 1;

    vet[0] = 1;
    vet [1] = 1;

    for (int i=2; i<n; i++)
        vet[i] = vet[i-1] + vet[i-2];

    return vet[n-1];
}

void invertevet (int *vet, int beg, int end)
{
    if(end<=beg)
        return;

    vettroca(vet, beg, end);
    invertevet(vet, beg+1, end-1);
}

int somapartes (int n, int soma)
{
    if(n==0)
        return soma;

    soma+= n%10;
    return somapartes(n/10, soma);
}
