#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mostra (char v[]);
int main ()
{
    srand(time(NULL));
    int valor;
    int i=0;
    char a[10];
    int valores[10] = {0};
    
    printf("Dê 10 caracteres. Escreva-os juntos e sem espaço. ");
    scanf("%s", a);

    char b[10];
    
    while (i<10) 
    {
        valor = (rand()%10+1);
        
        if (valor!=valores[0]&&valor!=valores[1]&&valor!=valores[2]&&valor!=valores[3]&&valor!=valores[4]&&valor!=valores[5]&&valor!=valores[6]&&valor!=valores[7]&&valor!=valores[8])
        {
            valores[i]=valor;
            i++;
        }
    }
    
    for(int k=0; k<10; k++)
    {
        b[valores[k]-1]=a[k];
    }
    
    printf("\n");
    mostra (a);
    printf("\n\n");
    mostra (b);
    
    return 0;
}
void mostra (char v[])
{
        for(int k=0; k<10; k++)
    {
        printf("[%c]", v[k]);
    }
}