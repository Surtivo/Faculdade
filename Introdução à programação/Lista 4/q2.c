#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void exibe_mat (int v[7][7]);
int main ()
{
    int mat [7][7] = {0};

    
    int dado2;
    int dado1;
    srand(time(NULL));
    
    for(int k=0; k<36000; k++)
    {
        dado1 = (rand()%6)+1;
        dado2 = (rand()%6)+1;
        
        mat[dado1][dado2]++;
    }
    
exibe_mat(mat);
    
    return 0;
}


void exibe_mat (int v[7][7])
{
    v[0][0];
    for (int i=1; i<7; i++)
    {
        v[0][i]=i;
    }

    for (int i=1; i<7; i++)
    {
        v[i][0]=i;
    }


    for (int i=0; i<7; i++)
    {
        printf("\n");
        for(int j=0; j<7; j++)
        {
            printf("%i\t", v[i][j]);
        }
    }
}