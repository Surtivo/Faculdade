#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"
#define MAX 19

typedef struct no{
    int x;
    struct no *prox;
}No;

typedef struct lista{
    No *beg;
    No *end;
    int nume;
}Lista;

void printvet (int *vet, int tam){
    for(int i=0; i<tam; i++)
        printf("%d ", vet[i]);
    printf("\n\n");
}

int funcaoHash (int x, int tam){
    return x%tam;
}

Lista *IniciaLista (){
    Lista *nova = (Lista*) malloc(sizeof(Lista));
    nova->beg = NULL;
    nova->end = NULL;
    nova->nume = 0;
    return nova;
}

void InsereLista (Lista *l, int val){
    No *novo = (No*) malloc(sizeof(No));
    novo->x = val;
    novo->prox = NULL;
    if(l->beg == NULL){
        l->beg = novo;
        //l->end = novo->prox;
        l->nume++;
    }else{
        novo->prox = l->beg;
        l->beg = novo;
        l->nume++;
    }
}

void Printalista (Lista *l){
    No *novo = (No*) malloc(sizeof(No));
    novo = l->beg;
    printf("Lista: ");
    while(novo != NULL){
        printf("%d ", novo->x);
        novo = novo->prox;
    }
    printf("\n\n");
}

int main()
{
    srand(time(NULL));

    /*printf("%d\n\n", test(10));

    Lista *Hash[MAX];
    for(int i=0; i<MAX; i++)
        Hash[i] = IniciaLista();

    int vetor[10];
    for(int j=0; j<10; j++)
        vetor[j] = (rand()%5000)+5001;
    printvet(vetor, 10);

   //printf("%d\n\n", funcaoHash((rand()%5000), MAX));

    //Lista *l = IniciaLista();
    //InsereLista(l, 10);
    //InsereLista(l, 20);
    //Printalista(l);

    int aux;

    for(int k=0; k<10; k++){
        aux = funcaoHash(vetor[k], MAX);
        InsereLista(Hash[aux], vetor[k]);
    }
    for(int o=0; o<MAX; o++)
        Printalista(Hash[o]);*/

    char *strings[] = {"Aula 1","Aula 2","Aula 3","Aula 4"};
    for (int i = 0; i < 4; i++) {
        printf("%s\n", strings[i]);
    }

}
