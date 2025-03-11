#include <stdio.h>
int strcounta (char *s);
int lastindexstr (char *s, char c);
int stricmp (char *s1, char *s2);
void viramas (char *s);

int main ()
{
    char st [10];
    char sb [10];
    char in;
    
    scanf("%s", st);
    scanf("%s", sb);
    scanf("%c", &in);
    printf("Escolha um caractere.\n");
    scanf("%c", &in);
    
    
    printf("\nO número de caracteres alfabeticos da primeira string é: %d\t", strcounta(st));
    printf("\nO último índice em que [%c] foi encontrado na primeira string é: %d", in, lastindexstr(st, in));
    printf("\nAs strings são iguais se o número entre colchetes for 1, caso contrário ele será 0 [%d]", stricmp(st, sb));
    
    
    return 0;
}

int strcounta (char *s)
{
    int count = 0;
    while (*s != '\0')
    {
        if(*s>=97 && *s<=122)
        {
            count++;
        }
        if(*s>=65 && *s<=90)
        {
            count++;
        }
        s++;
    }
    return count;
}

int lastindexstr (char *s, char c)
{
    int i=0;
    int ind;
    while (i<10)
    {
        if(s[i-1]==c)
        {
            ind=i;
        }
        i++;
    }
    if (ind!=0)
    {
        return ind;
    }
    else return -1;
}

void viramas (char *s)
{
   while (*s != '\0')
    {
        if (*s>='a' && *s<='z')
        {
            *s-=32;
        }
        ++s;
    }  
}

int stricmp (char *s1, char *s2)
{
    int po = 1;
    if (*s1>='a' && *s1<='z')
        {
            viramas(s1);
        }
    if (*s2>='a' && *s2<='z')
        {
            viramas(s2);
        }
    while (*s1 != '\0')
    {
        if (*s1==*s2)
        {
            ++s1;
            ++s2;
            continue;
        }
        else 
        {
            po = 0;
            break;
        }
    }
    while (*s2 != '\0')
    {
        if (*s1==*s2)
        {
            ++s1;
            ++s2;
            continue;
        }
        else 
        {
            po = 0;
            break;
        }
    }
    if (po==1)
    {
        return po;
    }
    else return po;
}