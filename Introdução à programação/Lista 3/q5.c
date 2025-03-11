#include <stdio.h>
#define TAM 10
int acima_valor (float v[], int t, float m);
float calcula_media (float v[], int t);
float maior_valor (float v[], int t);
float calcula_percentual (int f, int t);

int main ()
{
    float a [TAM];
    int i;
    for(i=0; i<TAM; i++)
    {
        scanf("%f", &a[i]);
    }
    
    float y=calcula_media(a, TAM);
    printf("A média da turma é: %.2f.\n\n", y);
    int z = acima_valor(a, TAM, y);
    printf ("%i alunos ficaram com nota maior que a média.\n\n", z);
    printf("O percentual de alunos acima da média é: %.2f.\n\n", calcula_percentual(z, TAM));
    printf("A maior nota da turma foi %.2f\n\n", maior_valor(a, TAM));
    
    return 0;
}

float calcula_media (float v[], int t)
{
    float soma = 0;
    for(int i=0; i<t; i++)
    {
        soma = v[i] + soma;
    }
    float media = soma/t;
    return media;
}

int acima_valor (float v[], int t, float m)
{
    int i;
    int cont = 0;
    
    for (i=0; i<t; i++)
    {
        if ((v[i])>m)
        {
            cont++;
        }
    }
    
    return cont;
}

float calcula_percentual (int f, int t)
{
   float percent = (f*100)/t;
    
    return percent;
}

float maior_valor (float v[], int t)
{
    int j = 0;
    float maior = 0.0;
    
    while (j<t)
    {
        if (v[j]>maior)
        {
            maior = v[j];
        }
    j++;
    }
    
    return maior;
}
