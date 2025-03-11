#include <stdio.h>
int main()
{
    printf("Informe o lado do quadrado\n");
    int lado, i=0, j=0;
    scanf("%d", &lado);
    printf("\n");
    while (i<lado) 
    {
        j=0;
        while (j<lado-1)
        {
            printf("*");
            j++;
        }
    printf("*\n");
    i=i+1;
    }
    return 0;
}