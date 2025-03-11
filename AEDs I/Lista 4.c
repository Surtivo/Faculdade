#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct pilha{
	int vet[MAX];
	int topo;
}Pilha;

typedef struct fila{
	int vet[MAX];
	int beg;
	int end;
	int nume;
}Fila;

Pilha* criaPilha(){
	Pilha *nova = (Pilha*) malloc(sizeof(Pilha));
	nova->topo = -1;
	return nova;
}

void empilhar(Pilha *pilha, int x){
	pilha->vet[++pilha->topo] = x;
}

int desempilhar(Pilha *pilha){
	if(pilha->topo != -1)
		return pilha->vet[pilha->topo--];
	else
		return -1;
}

void imprimePilha(Pilha* p){
    for(int i = p->topo; i >= 0; i--){
        printf("%d ",p->vet[i]);
    }
    printf("\n\n");
}

Fila * criaFila(){
	Fila *nova = (Fila*) malloc(sizeof(Fila));
	nova->beg = -1;
	nova->end = -1;
	nova->nume = 0;
	return nova;
}

void enfileirar(Fila *fila, int x){
	if(fila->beg == -1){
		fila->vet[++fila->beg] = x;
		fila->end = fila->beg;
		fila->nume++;
	}
	else{
		fila->vet[++fila->end] = x;
		fila->nume++;
	}
}

int desenfileirar (Fila *fila){
	if(fila->beg != -1){
		fila->nume--;
		return fila->vet[fila->beg++];

	}
}

void imprimeFila (Fila *f){
	for(int i=0; i<=f->end; i++)
		printf("%d ", f->vet[i]);
	printf("\n\n");
}

void inverterpilha (Pilha *p, Fila* aux){
    aux->beg++;
    while(p->topo >= 0)
        aux->vet[++aux->end] = p->vet[p->topo--];

    while(aux->beg <= aux->end)
        p->vet[++p->topo] = aux->vet[aux->beg++];
}

void invertefila (Fila *f, Pilha *aux){
    int x = f->nume;
    while(f->beg <= f->end){
        empilhar(aux, f->vet[f->beg++]);
        f->nume--;
    }
    f->beg = -1;
    while(f->nume++ <= x)
        enfileirar(f, aux->vet[aux->topo--]);
}

int countpilha (Pilha *p){
    int vet[MAX];
    int i = 0;
    int count;
    int aux = desempilhar(p);
    while(aux != -1){
        vet[i++] = aux;
        aux = desempilhar(p);
    }
    count = i;
    while(i>0)
        empilhar(p, vet[--i]);
    return count;
}

int comparapilha (Pilha *p1, Pilha *p2){
    int vet1[100];
    int vet2[100];
    int aux = 0;
    int x = desempilhar(p1);
    int y = desempilhar(p2);
    while(x!=-1 && x==y){
        vet1[aux] = x;
        vet2[aux++] = y;
        x = desempilhar(p1);
        y = desempilhar(p2);
    }
    if(x!=y)
        return -1;
    else{
        while(aux > 0){
            empilhar(p1, vet1[--aux]);
            empilhar(p2, vet2[aux]);
        }
        return 1;
    }
}

int palindromo (Pilha* p){
    Pilha *p2 = criaPilha();
    char *pal = (char *)malloc(sizeof(5));
    fgets(pal, 5, stdin);
    int i = 0;
    while(i<4)
        empilhar(p, pal[i++]);
    while(i>0)
        empilhar(p2, pal[--i]);
    imprimePilha(p2);
    return comparapilha(p, p2);
}
int main (){

	Pilha *p = criaPilha();
	//empilhar(p, 1);
	//empilhar(p, 2);
	//imprimePilha(p);
	printf("%d\n", palindromo(p));
	imprimePilha(p);

	return 0;
}
