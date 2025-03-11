#include <stdio.h>
int main ()
{
    int a [6][6] = {0};
    int i;
    int j;
    
    for (i=0; i<6; i++)
    {
        printf("\n");
        for(j=0; j<6; j++)
        {
            printf("\t[%i]", a[i][j]);
        }
    }
    return 0;
}