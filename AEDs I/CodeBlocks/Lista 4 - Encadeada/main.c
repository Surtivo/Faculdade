#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int val;
    struct no* prox;
}No;

typedef struct pilha{
	No *topo;
}Pilha;

Pilha* criaPilha(){
	Pilha *p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

void imprimePilha (Pilha *p){
    No *novo = (No*) malloc(sizeof(No));
    novo = p->topo;
    while(novo != NULL)
    {
        printf("%d   ", novo->val);
        novo = novo->prox;
    }
    printf("\n\n");
}

void empilhar(Pilha *p, int x){
	No *novo = (No*) malloc(sizeof(No));
	novo->val = x;
	novo->prox = NULL;
	if(p->topo == NULL)
        p->topo = novo;
    else{
        novo->prox = p->topo;
        p->topo = novo;
    }
}

void desempilhar(Pilha *p){
    printf("Out: %d", p->topo->val);
    p->topo = p->topo->prox;
    printf("\n\n");
}

typedef struct fila{
	No *beg;
	No *end;
	int nume;
}Fila;

Fila * criaFila(){
	Fila *nova = (Fila*) malloc(sizeof(Fila));
	nova->beg = NULL;
	nova->end = NULL;
	nova->nume = 0;
	return nova;
}

void imprimeFila(Fila *f){
    No *novo = (No*) malloc(sizeof(No));
    novo = f->beg;
    while (novo != NULL){
        printf("%d   ", novo->val);
        novo = novo->prox;
    }
    printf("\n\n");
}

void enfileirar(Fila *f, int x){
    No *novo = (No*) malloc(sizeof(No));
    novo->val = x;
    novo->prox = NULL;
    if(f->beg == NULL){
        f->beg = novo;
        f->end = novo;
        f->nume++;
    }
    else{
        f->end->prox = novo;
        f->end = novo;
        f->nume++;
    }
}

void desenfileirar(Fila *f){
    printf("Out : %d", f->beg->val);
    f->beg = f->beg->prox;
    printf("\n\n");
}

int main(){
    Fila *f = criaFila();
    enfileirar(f, 1);
    enfileirar(f, 2);
    enfileirar(f, 3);
    enfileirar(f, 4);
    enfileirar(f, 5);
    imprimeFila(f);
    desenfileirar(f);
    desenfileirar(f);
    desenfileirar(f);
    desenfileirar(f);
    imprimeFila(f);

    return 0;
}
