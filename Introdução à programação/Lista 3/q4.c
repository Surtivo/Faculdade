#include <stdio.h>
#include <stdlib.h> /*Habilita a função "rand" e "srand"*/
#include<time.h> /*Habilita a função "time"*/
#define TAM 10

int busca_vetor (int x, int v[], int t);
void exibe_vetor (int v[], int t);

int main()
{
   int a [TAM];
   int i;
   int x;

    printf("Dê um valor entre 0 e 10.\n");
    scanf("%i", &x);
    
    if (x>=0 && x<=10)
    {
   srand(time(NULL)); 
   /*Habilita a função "rand" sempre produzir valores aleatórios, não valores aleatórios constantes*/
   
   for (i=0; i<TAM; i++)
   {
       a[i]=rand()%10;
   }
   
    exibe_vetor (a, TAM);
    busca_vetor (x, a, TAM);
    }
    
    else printf ("Erro!");
    return 0;
}

void exibe_vetor (int v[], int t)
{
    int i = 0;
    printf("Vetor Aleatório = [");
    while(i<t-1)
    {
        printf("%i,\t", v[i]);
        i++;
    }
    printf("%i]", v[i]);
}

int busca_vetor (int x, int v[], int t)
{
    int cont = 0;
    int i;
    
    for (i=0; i<t; i++)
    {
        if (x==v[i])
        {
            cont++;
        }
    }
    if (cont==0)
    {
        printf("\n\nValor não encontrado.");
    }
    else printf("\n\nO valor %i foi encontrado %i vez(es) no vetor aleatório.", x, cont);
    
    return 0;
}
