#include <stdio.h>
#define TAM 5
void exibe_vetor(int v[], int t);
int main()
{
    int a [TAM];
    int b [TAM];
    int c [TAM*2];
    int i;
    
    printf("Dê os valores do vetor A. Um valor por vez\n");
    for (i=0; i<TAM; i++)
    {
        scanf("%i", &a[i]);
    }
    
    printf("Dê os valores do vetor B. Um valor por vez\n");
    for (i=0; i<TAM; i++)
    {
        scanf("%i", &b[i]);
    }
    
    for(i=0; i<TAM; i++)
    {
        c[i*2] = a[i];
    }
    
    for(i=0; i<TAM; i++)
    {
        c[i*2+1] = b[i];
    }
    
    exibe_vetor(a, TAM);
    exibe_vetor(b, TAM);
    exibe_vetor(c, TAM*2);
    
    return 0;
}

void exibe_vetor(int v[], int t)
{
    printf("\n\nOs valores do vetor são:\n");
    for(int i=0; i<t; i++)
    {
        printf("[%i]\t", v[i]);
    }
    
}
