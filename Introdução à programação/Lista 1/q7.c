#include <stdio.h>
/*Não estou contando o 0*/
int main()
{
int a,b, c;
scanf("%d %d %d", &a, &b, &c);
printf("\n");
if (a>b)
{
    while (a>=b)
    {
        if(b%c==0) printf("%d\n", b);
    b++;
    }
}
else
{
    while (a<=b)
    {
        if(a%c==0) printf("%d\n", a);
    a++;
    }
}
    return 0;
}
