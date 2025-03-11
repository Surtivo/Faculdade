#include<stdio.h>
#include<math.h>

float perimetro(float raio);
float area(float raio);
float main(float raio)
{
    printf("Forneça o valor do raio ");
    scanf("%f", &raio);
    printf("\n A área é igual a %.2f", area(raio));
    printf("\n O perímetro é igual a %.2f", perimetro(raio));
    
    return 0;
}

float area(float raio)
{
    float area = 3.14*pow(raio,2);
    return area;
}

float perimetro(float raio)
{
    float perimetro = 2*3.14*raio;
    return perimetro;
}