#include <stdio.h>

int main()
{
int k, ult=1, penult=1, count, term;
scanf("%d", &k);
if(k>2)
{
    printf("\n1\n1\n");
   count=3;
   while(count<=k)
   {
        term=ult+penult;
        penult=ult;
        ult=term;
        printf("%d\n", term);
        count++;
   }
}

    return 0;
}
/*Estou considerando o sexto número da sequência de Fibonacci ser 8 e não 13 como diz o enunciado.*/
