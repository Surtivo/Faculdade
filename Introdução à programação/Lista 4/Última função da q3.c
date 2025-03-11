#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int convert (char *);

int main ()
{
    char *s = "123";
    char *se = "123a";
    char *l = "+123";
    char *le = "-123";
    char *lei = "+123a";
    char *leis = "-123a";
    
    printf("result: %d\nCaso seja 0, a string contém caracter.\n\n", convert(s));
    printf("result: %d\nCaso seja 0, a string contém caracter.\n\n", convert(se));
    printf("result: %d\nCaso seja 0, a string contém caracter.\n\n", convert(l));
    printf("result: %d\nCaso seja 0, a string contém caracter.\n\n", convert(le));
    printf("result: %d\nCaso seja 0, a string contém caracter.\n\n", convert(lei));
    printf("result: %d\nCaso seja 0, a string contém caracter.\n\n", convert(leis));
    
    
    return 0;
}

int convert (char *s)
{
   
    int inte = 0;
    int tam = 0;
    int result = 0;
    int sinal = 3;
    
    while (*s != '\0')
    {
        tam++;
        s++;
    }
    printf("tam é: %d\n\n", tam);
    
    
    for (int i = 0; i<tam; i++)
        s--;
        
    if (s[0] == '-')
        {
            sinal = 1;
            s++;
        }
    
    else if (s[0] == '+')
        {
            sinal = 0;
            s++;
        }
    
    else if(s[0]>= '0' && s[0]<= '9')
        sinal=2;
        
    else
        return 0;
    
    while (*s != '\0')
    {
        if (*s < '0' || *s > '9')
            return 0;
        s++;
    }
    
    if(sinal == 0 || sinal == 1)
    {
        for (int i = 1; i<tam; i++)
            s--;
    }
    else if (sinal == 2)
    {
        for (int i = 0; i<tam; i++)
            s--;
    }
    else
    {
        printf("?\n");
        return 0;
        
    }
    
    printf("%c\n", *s);            //Aquiiiiiiiiiiiiiii
    printf("sinal %d\n\n", sinal); //Aquiiiiiiiiiiiiiii
    
    
    int val [tam];

    if(sinal == 2){        
    while (inte<tam)
    {
        while (*s != '\0')
        {
            val[inte] = (*s-48);
            inte++;
            s++;
        }
    }
        inte = 0;
    int pe = 0;
    int te = tam;
    
    printf("O vetor val é:\n");
    for (int j=0; j<tam; j++)
        printf("[%d]\t", val[j]);
    
    while (pe<tam-1)
    {
        while (te>1)
        {
            result += val[pe]*(pow(10, te-1));
            pe++;
            te--;
        }
    }
    
    if (te == 1)
        {
            result += val[pe];
        }

    printf("\n\n");
    return result;
    }
    
    if(sinal == 0 || sinal == 1){        
    while (inte<tam-1)
    {
        while (*s != '\0')
        {
            val[inte] = (*s-48);
            inte++;
            s++;
        }
    }
    
    inte = 0;
    int pe = 0;
    int te = tam-1;
    
    printf("O vetor val é:\n");
    for (int j=0; j<tam-1; j++)
        printf("[%d]\t", val[j]);
    
    while (pe<tam-1-1)
    {
        while (te>1)
        {
            result += val[pe]*(pow(10, te-1));
            pe++;
            te--;
        }
    }
    
    if (te == 1)
        {
            result += val[pe];
        }

    printf("\n\n");
    if (sinal == 1)
        return result-result-result;
    else
        return result;
    }
}