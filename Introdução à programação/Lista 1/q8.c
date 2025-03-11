#include <stdio.h>
int main()
{
    printf("Digite um número \n");
    int k, n=2;
    scanf("%d", &k);
    if(k==2 || k==3 || k==5 || k==7)
    {
        printf("%d é primo!", k);
    }
    else
    {
        {
            if (k%n==0)
            {
                printf("%d não é primo!", k);
            }
            else
            {
                if (k%2==0 || k%3==0 || k%5==0 || k%7==0)
                {
                    printf("%d não é primo!", k);
                }
                else printf("%d é primo!", k);
            }
        }
    }
}