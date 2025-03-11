#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int isAlpha (char *s);
int generateKey ();
int encodestr (char *s);
void decodestr (char *s, int k);

int main()
{
    int chave;
    char *s = "Eba";
    char *s2 = "Eba";
    
    printf("\n%d", decodestr(s, encodestr(s)));
    
    return 0;
}

int isAlpha (char *s)
{
    int k = 1;

    while (*s!='\0')    
    {
        if (*s>=65 && *s<=90)
        {
            ++s;
            continue;
        }
        else if  (*s>=97 && *s<=122)
        {
            ++s;
            continue;
        }
        else 
        {
            k=-1;
            break;
        }
    }
    if (k==1)
    {
        return k;
    }
    else return -1;
}

int generateKey()
{
    int key;
    key=(rand()%128)+1;
    return key;
}

int encodestr (char *s)
{
    int j=0;
    char po[3];
    int cha;
    cha=generateKey();
    int p =1;
    while(*s!='\0')
    {
        if(*s<65 || *s>122)
        {
            p=0;
            return 0;
            break;
        }
        if(*s>90 && *s<94)
        {
            p=0;
            return 0;
            break;
        }
        else 
        {
            while(j<3)
            {
            po[j]=*s+cha;
            j++;
            break;
            }
        }
        ++s;
    }
    
    if (p==1)
    {
        return cha;
    }
}

void decodestr (char *s, int k)
{
    while (*s!='\0')
    {
        s=s-k;
        ++s;
    }
}