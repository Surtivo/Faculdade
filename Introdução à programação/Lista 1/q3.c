#include <stdio.h>
int main()
{
    printf("Informe o lado do quadrado\n");
    int lado, i, j, aux;
    scanf("%d", &lado);
    printf("\n");
    aux=lado-2;
    
    for (i=0;i<lado;i++)
    printf("*");
    for (j=0;j<aux;j++)
    {
        printf("\n*");
            for(i=0; i<aux;i++)
            printf(" ");
            for(i=0; i<1;i++)
            printf("*");
    }
    printf("\n");
    for (i=0;i<lado;i++)
    printf("*");
    
    return 0;
}