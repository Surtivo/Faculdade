#include <stdio.h>
int main()
{
    int n, multi=1;
    scanf("%d", &n);
    if (n<0)
    {
        printf("Somente números positivos!");
    }
    else
    {
      while(n>1)
      {
          multi=multi*n;
          n=n-1;
          
      }
      printf("%d", multi);
      
    }
    
 return 0;   
}