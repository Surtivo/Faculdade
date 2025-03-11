#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int isalpha (char *s);
int generateKey ();
int encodestr (char *s);
void decodestr (char *s, int k);

int main()
{

    char *s = "Ema";
    
    printf("%d", isalpha (s));
    
    return 0;
}

int isalpha (char *s)
{
    int k = 1;

    while (*s!='\0')    
    {
        if (*s>=65 && *s>=90)
        {
            ++s;
            continue;
        }
        if  (*s>=97 && *s>=122)
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
    int cha;
    cha=generateKey();
    int p =1;
    while(*s!='\0')
    {
        if(*s<65 || *s>122 || *s>90 && *s<97)
        {
            p=0;
            return 0;
            break;
        }
        else s=s+cha;
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