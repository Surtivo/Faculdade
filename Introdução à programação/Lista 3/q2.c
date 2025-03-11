#include <stdio.h>
int main ()
{
    int a [5];
    int b [5];
    int c [10] = {};
    int i;
    
    printf("Dê os valores do vetor A. Um valor por vez.\n");
    for (i=0; i<5; i++)
    {
        scanf("%i", &a[i]);
    }
    
    printf("Dê os valores do vetor B. Um valor por vez.\n");
    for (i=0; i<5; i++)
    {
        scanf("%i", &b[i]);
    }
    
    for (i = 0; i<10; i++) 
    {
        c[i*2] = a[i];
    }
    for (i = 0; i<10; i++) 
    {
        c[i*2+1] = b[i];
    }
    
    printf("\nA = [%i] [%i] [%i] [%i] [%i] \n\n", a[0], a[1], a[2], a[3], a[4]);
    printf("B = [%i] [%i] [%i] [%i] [%i] \n\n", b[0], b[1], b[2], b[3], b[4]);
    printf("C = [%i] [%i] [%i] [%i] [%i] [%i] [%i] [%i] [%i] [%i] \n\n", c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9]);
    
    return 0;
}