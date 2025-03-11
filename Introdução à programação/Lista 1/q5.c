#include <stdio.h>
int main()
{
    printf("Forneça um número ");
    int k, n=1, s=0;
    scanf("%d", &k);
    while(n<=k)
    {
        s=s+((2*n)-1);
        n++;
    }
    printf("\n O somatório é igual a %d", s);
    
    return 0;
}