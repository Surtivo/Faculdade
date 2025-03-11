#include <stdio.h>

int main ()
{
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    if (a>0 && b>0 && c>0)
    {
      if (a+b>c && b+c>a && a+c>b)
      {
          if (a==b && b==c) printf("É um triângulo equilátero, todos os lados são iguais.");
          if (a==b && a!=c || b==c && b!=a || a==c && a!=b) printf("É um triângulo isósceles, tem apenas 2 lados iguais.");
          if (a!=b && b!=c && a!=c) printf("É um triângulo escaleno, nenhum lado é igual.");
      }
      else printf("Não é um triângulo!");
    }
    else printf("As medidas precisam ser positivas!");
    return 0;
}