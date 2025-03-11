#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario Funcionario;
typedef Funcionario *FuncPtr;

struct funcionario{
    int matricula;
    char nome[30];
    float salario;
    Funcionario *next;
};

void Inserir (FuncPtr *, int mat, char *, float wage);
void Exibir (FuncPtr *, int);
void Listar (FuncPtr);
void Apagar (FuncPtr *, int i);


int main()
{
    FuncPtr Func = NULL;
    
    Inserir (&Func, 10, "Luis", 100.50);
    Inserir (&Func, 20, "Manu", 100.00);
    Inserir (&Func, 30, "Sueli", 200.50);
    Exibir (&Func, 20);
    printf("Lista de Funcionarios:\n\n");
    Listar (Func);
    Apagar (&Func, 20);
    printf("Lista de Funcionarios:\n\n");
    Listar (Func);
    
    return 0;
}

void Inserir (FuncPtr *x, int mat, char *z, float wage)
{
    FuncPtr novo;
    FuncPtr last;
    
    novo = malloc(sizeof(Funcionario));
    
    if (novo == NULL)
    {
        printf("Não há espaço na memória.");
        return;
    }
    
    novo->matricula = mat;
    strcpy (novo->nome, z);
    novo->salario = wage;
    novo->next = NULL;
    
    if (*x == NULL)
    {
        *x = novo;
    }
    
    else
    {
        last = *x;
        
        while (last->next != NULL)
        {
            last = last->next;
        }
        
        last->next = novo;
    }
}

void Exibir (FuncPtr *x, int z)
{
    FuncPtr last;
    
    if (*x == NULL)
    {
        printf("A lista está vazia.");
        return;
    }

    last = *x;
    
    while (last != NULL && last->matricula != z)
    {
        last = last->next;
    }
        
    if (last == NULL || last->matricula != z)
    {
        printf("Matricula não encontrada\n");
        return;
    }
        
    else
    {
        if (last->matricula == z)
        {
            printf("Exbindo dados da matricula n° %d\n\n", last->matricula);
            printf("Matricula: %d\n", last->matricula);
            printf("Nome: %s\n", last->nome);
            printf("Salario: %.2f\n\n", last->salario);
        }
    }
}

void Listar (FuncPtr y)
{
    if (y == NULL)
    {
        printf("Fim da lista\n\n");
        return;
    }
    
    printf("Matricula: %d\n", y->matricula);
    printf("Nome: %s\n", y->nome);
    printf("Salario: %.2f\n\n", y->salario);
    Listar (y->next);
}

void Apagar (FuncPtr *x, int i)
{
    FuncPtr atual;
    FuncPtr antes;
    
    if(*x == NULL)
    {
        printf("A lista está vazia.");
        return;
    }
    
    atual = *x;
    antes = NULL;
    
    while (atual != NULL && atual->matricula != i)
    {
        antes = atual;
        atual = atual->next;
    }
    
    if(atual == NULL || atual->matricula != i)
    {
        printf("Matricula não encontrada\n");
        return;
    }
    
    else
    {
        if (antes == NULL)
        {
            *x = atual->next;
        }
        else
        {
            antes->next = atual->next;
        }
    }
    printf("Matricula n° %d excluida\n\n", atual->matricula);
    free(atual);
}