#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef Node *Lista;

struct node{
	int info;
	Node *next;
};

void inserir (Lista *lista, int i);
void listar (Lista lista);
void excluir(Lista *lista, int x);

int main()
{
	Lista lista = NULL;
	
	inserir(&lista, 10);
	inserir(&lista, 20);
	inserir(&lista, 30);
	listar(lista);
	printf("\n");
	excluir(&lista, 20);
	listar(lista);
	return 0;
}

void inserir(Lista *lista, int i)
{
	Node *novo;
	Node *last;
	
	novo=(Node*)malloc(sizeof(Node));
	
	if (novo == NULL)
	{
		printf("Não há espaço na memória.");
		return;
	}
	
	novo->info = i;
	novo->next = NULL;
	
	if (*lista == NULL)
	{
		*lista = novo;
	}
	else
	{
		last = *lista;
		while (last->next != NULL)
		{
			last=last->next;
		}
		last->next = novo;
    }
}

void listar (Lista lista)
{
	Lista prox;
	prox = lista;
	
	while (prox != NULL)
	{
		printf("\n%d", prox->info);
		prox = prox->next;
	}
}
void excluir(Lista *lista, int x)
{
	Node *curr;
	Node *prev;
	
	if(*lista==NULL)
		return;
	
	curr = *lista;
	prev = NULL;
	
	while (curr != NULL && curr->info != x)
	{
		prev = curr;
		curr = curr->next;
	}
	
	if (curr == NULL || curr->info != x)
		return;
		
	if (prev == NULL)
		*lista = curr->next;
	
	else
		prev->next = curr->next;
free(curr);
}