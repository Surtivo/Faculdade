#include<stdio.h>
#define MAX 5
#define ALT 71

int main()
{
    char s[5]= "hello";
    char p;
    char k[5];
    printf("%s\n", s);
       
    for(int i=0; i<MAX; i++)
    {
        s[i]+=ALT;
        
        if(s[i]>'z')
        {
            s[i]-=(ALT+7);
        }
    }
    
    printf("%s\n", s);
    
    for (int j=0; j<MAX; j++)
    {
       s[j]-=ALT;
        if (s[j]<'A')
        {
            s[j]+=(71+7);
        } 
    }
    printf("%s\n", s);
    
    return 0;
}