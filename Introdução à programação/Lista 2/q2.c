#include <stdio.h>

float fahrenheit(float C);
float kelvin(float C);
int main(int a, int b)
{
    printf("Forneça duas temperaturas em Celsius ");
    scanf("%d %d", &a, &b);
    if (a<b)
    {
        float c = (float)a * 1.0;
        while (c<=b)
        {
            printf("\n Celsius %.2f  ||  Fahrenheit %.2f  ||  Kelvin %.2f",c, fahrenheit(c), kelvin(c));
            c = c + 0.5;
        }
    }
    if (b<a)
    {
        float c = (float)b * 1.0;
        while (c<=a)
        {
            printf("\n Celsius %.2f  ||  Fahrenheit %.2f  ||  Kelvin %.2f",c, fahrenheit(c), kelvin(c));
            c = c + 0.5;
        }
    }
    

    return 0;
}

float fahrenheit(float c)
{
    float f = c*1.8+32;
    return f;
}

float kelvin(float c)
{
    float k = c+273;
    return k;
}