#include<stdio.h>
float pesoideal(float a, char s);
float main (float t, float p, char g)
{
    printf("Informe altura, peso e sexo, respectivamente.\n");
    t=1.0;
    while (t>0)   
    {
        scanf("%f %f %c", &t, &p, &g);
        printf("\nO peso ideal é %.2f.", pesoideal(t, g));
        if (p>pesoideal(t,g))
        {
            printf("\nEstá acima do peso ideal.");
        }
        else printf("\nNão está acima do peso ideal.");
    }
    
    return 0;
}

float pesoideal(float a, char s)
{
    if (s == 'M' || s == 'm')
    {
        float pesoideal = 72.7 * a - 58;
        return pesoideal;
    }
    if (s == 'F' || s == 'f')
    {
        float pesoideal = 62.1 * a - 44.72;
        return pesoideal;
    }
    else return 0;
}