#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct {
    int matricula;
    char nome[30];
    float salario;
} Funcionario;

void ImprimeFunc (Funcionario fun);

int main()
{
    Funcionario fun[MAX];
    for(int p=0; p<MAX; p++)
    {
        strcpy (fun[p].nome, "\0");
        fun[p].matricula = 0;
        fun[p].salario = 0;
    }
    
    for(int p=0; p<1000;p++)
    {
    printf("\n 1. Inserir Registro\n 2. Alterar Registro\n 3. Apagar Registro\n 4. Exibir Registro\n 5. Exibir Listagem\n 6. Pesquisar matricula\n 0. Sair\n");
    

    int numero;
    scanf("%d", &numero);
    
    if(numero==0)
    {
        int quant = MAX;
        
        for(int z=0; z<MAX; z++)
        {
            if(fun[z].matricula==0)
            {
                quant--;
            }
        }
        
        printf("\nPrograma Terminado.");
        printf("\nO número de registros totalizados é %d.", quant);
        break;
    }
    
    if(numero==1){
    
    int inte = -1;
    
    for(int i=0; i<MAX; i++)
    {
        if (fun[i].matricula==0)
        {
            inte=i;
            break;
        }
        else 
        {
            continue;
        }
    }
    
    
    for(int i=0; i<MAX; i++)
    {
            printf("\n");
            printf("Matrícula ");
            scanf("%d", &fun[inte].matricula);
            if(fun[inte].matricula==0)
            {
                strcpy (fun[inte].nome, "\0");
                fun[inte].salario = 0;
                break;
            }
            printf("Nome ");
            scanf("%s", fun[inte].nome);
            printf("Salário ");
            scanf("%f", &fun[inte].salario);
            break;
    }
    if (inte==-1)
    {
        printf("\nNão há registros vazios!\n Registro não adicionado!\n");
    }
    
    }
    
    if(numero==2)
    {
        for (int w=0; w<1; w++){
        int posi;
        printf("\nDigite a posição da lista que deseja alterar. \n");
        scanf("%d", &posi);
        
        if(posi>-1 && posi<MAX){
        
        printf("\n");
        printf("Matrícula ");
        scanf("%d", &fun[posi].matricula);
        if(fun[posi].matricula==0)
        {
            strcpy (fun[posi].nome, "\0");
            fun[posi].salario = 0;
            break;
        }
        printf("Nome ");
        scanf("%s", fun[posi].nome);
        printf("Salário ");
        scanf("%f", &fun[posi].salario);}
        
        else printf("\nAlgo deu errado!\n");
    }}
    
    if (numero==3)
    {
        int pos;
        printf("\nDigite a posição da lista que deseja apagar. \n");
        scanf("%d", &pos);
        
        if(pos>-1 && pos<MAX){
        strcpy (fun[pos].nome, "\0");
        fun[pos].matricula = 0;
        fun[pos].salario = 0;}
        
        else printf("\nAlgo deu errado!\n");
    }
    
    if (numero==4)
    {
        int regis;
        printf("\nDigite a posição da lista que deseja exibir \n");
        scanf("%d", &regis);
        
        if(regis>-1 && regis<MAX){
        ImprimeFunc(fun[regis]);}
        else printf("\nAlgo deu errado!\n");
    }
    
    if(numero==5)
    {
        for(int q=0; q<MAX; q++)
        {
            ImprimeFunc(fun[q]);
        }
    }
    
    if(numero==6)
    {
        int matri;
        int ind = -1;
        printf("\nDigite uma matrícula para ser procurada.\n");
        scanf("%d", &matri);
        
        for(int n=0; n<MAX; n++)
        {
            if (fun[n].matricula==matri)
            {
                ind = n;
                printf("A matrícula foi encontrada no indice %d.\n", ind);
                break;
            }
        }
        if (ind == -1)
        {
            printf("Matrícula não encontrada!\n");
        }
    }
    
    }
    
    //*Aqui*//
    
    return 0;
}

void ImprimeFunc (Funcionario fun)
{
  printf("\n\nMatricula: %d \t Nome: %s \t Salario: %.2f\n", fun.matricula, fun.nome, fun.salario);
}