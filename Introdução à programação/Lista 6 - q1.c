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
void menu ();


int main()
{
    int choice, matricula;
    float salario;
    char *nome;
    FuncPtr Func = NULL;
    
    while (choice != 0)
    {
        menu();
        scanf("%d", &choice);
    
        if (choice==0)
        {
            printf("Programa Terminado.");
            break;
        }
        
        if (choice == 1)
        {
            for(int p=0; p<2; p++)
            {
                printf("\nMatricula ");
                scanf("%d", &matricula);
                printf("Nome ");
                scanf("%s", nome);
                printf("Salario ");
                scanf("%f", &salario);
                break;
            }
            Inserir(&Func, matricula, nome, salario);
            
        }
        
        if (choice == 2)
        {
            printf("\nMatricula que deseja apagar ");
            scanf("%d", &matricula);
            Apagar (&Func, matricula);
        }
        
        if (choice == 3)
        {
            printf("\nMatricula que deseja mostrar ");
            scanf("%d", &matricula);
            Exibir (&Func, matricula);
        }
        
        if (choice == 4)
        {
            printf("\nLista de funcionarios:\n\n");
            Listar (Func);
        }
        
    }
    return 0;
}

void Inserir (FuncPtr *x, int mat, char *z, float wage)
{
    FuncPtr novo;
    FuncPtr last;
    
    novo = malloc(sizeof(Funcionario));
    
    if (novo == NULL)
    {
        printf("Não há espaço na memória.\n");
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
        printf("A lista está vazia.\n");
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
            printf("Exibindo dados da matricula n° %d\n\n", last->matricula);
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

void menu ()
{
    printf("\n 1. Inserir Registro\n 2. Apagar Registro\n 3. Exibir Registro\n 4. Exibir Listagem\n 0. Sair\n\n");
}