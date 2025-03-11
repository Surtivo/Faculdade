#include <stdio.h>

float calcValor(float preco, int quant);
int main(float preco, int quant)
{
    preco = 1;
    printf("Informe o valor da passagem e a quantidade desejada.\n");
    while (preco>0)
    {
    scanf("\n%f %d", &preco, &quant);
    printf("O valor total é R$:%.2f\n", calcValor(preco, quant));
    }
    return 0;
}

float calcValor(float preco, int quant)
{
    float vt = preco*quant;
    if (quant>=2 && quant<=4)
    {
       float desc = vt*0.05;
        vt= vt-desc;
        return vt;
    }
    if (quant>=5 && quant<8)
    {
        float desc = vt*0.1;
        vt = vt-desc;
        return vt;
    }
    if (quant>=8)
    {
        float desc = vt*0.2;
        vt = vt-desc;
        return vt;
    }
}
