#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    struct set* conjunto;
    int dado;
    struct item* prox;
}Item;

typedef struct set{
    Item* cabeca;
    Item* fim;
    int tam;
}Set;

Item* criaItem(int dado){
    Item* novo = (Item*) malloc(sizeof(Item));
    novo->conjunto = NULL;
    novo->prox = NULL;
    novo->dado = dado;
    return novo;
}

void makeSet(Item* item){
    Set* novoSet = (Set*) malloc(sizeof(Set));
    novoSet->cabeca = item;
    novoSet->fim = item;
    novoSet->tam = 1;
    item->conjunto = novoSet;
}

Item* find(Item* item){
    if(item->conjunto==NULL) return NULL;
    return item->conjunto->cabeca;
}

void unionSets(Item* x, Item* y){
    Set* sx = x->conjunto;
    Set* sy = y->conjunto;
    if(sx->tam < sy->tam){
        Set* auxS = sy;
        sy = sx;
        sx = auxS;
    }
    sx->fim->prox = sy->cabeca;
    sx->fim = sy->fim;
    Item* aux = sy->cabeca;
    while(aux!=NULL){
        aux->conjunto = sx;
        aux = aux->prox;
    }
    sx->tam = sx->tam + sy->tam;
    free(sy);

}

void unionSets2 (Item *x, Item *y){
    Set* sx = x->conjunto;
    Set* sy = y->conjunto;
    if(sx->tam < sy->tam){
        Set* auxS = sy;
        sy = sx;
        sx = auxS;
    }



    sx->tam = sx->tam + sy->tam;
    free(sy);
}

int main(){
    Item* i1 = criaItem(1);
    Item* i2 = criaItem(2);
    makeSet(i1);
    makeSet(i2);
    printf("%d, %d\n",find(i1)->dado,find(i2)->dado);
    unionSets2(i1,i2);
    printf("%d, %d\n",find(i1)->dado,find(i2)->dado);
    Item *i3 = criaItem(3);
    makeSet(i3);
    unionSets2(i3,i2);
    printf("%d, %d, %d\n",find(i1)->dado,find(i2)->dado,find(i3)->dado);

    return 0;
}
