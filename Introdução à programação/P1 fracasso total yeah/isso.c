#include<stdio.h>
#define MAX 5
#define ALT 71
int encode (char *s);
void decode (char *s, int l);

int main()
{
    char s[5]= "hello";
    char p;
    char k[5];
    printf("%s\n\n", s);
    
    printf("%d\n", encode(s));
    decode (s, 71);
    
    return 0;
}
       
int encode (char *s)
{    
    for(int i=0; i<MAX; i++)
    {
        s[i]+=ALT;
        
        if(s[i]>'z')
        {
            s[i]-=(ALT+7);
        }
    }
    
    printf("%s/t - ", s);
    return ALT;
}

void decode (char *s, int l)
{    
    for (int j=0; j<MAX; j++)
    {
       s[j]-=l;
        if (s[j]<'A')
        {
            s[j]+=(l+7);
        } 
    }
    printf("%s\n", s);
    
}