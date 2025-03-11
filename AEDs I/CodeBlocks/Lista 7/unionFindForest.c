#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int dado;
    struct item* pai;
    int rank;
}Item;

Item* criaItem(int dado){
    Item* novo = (Item*) malloc(sizeof(Item));
    novo->dado = dado;
    novo->pai = NULL;
    return novo;
}

void makeSet(Item* item){
    item->pai = item;
    item->rank = 0;
}

Item* find(Item* i){
    if(i!=i->pai){
        i->pai = find(i->pai);
    }
    return i->pai;
}

void unionSets(Item* x, Item* y){
    Item* sx = find(x);
    Item* sy = find(y);
    //sy->pai = sx;
    if(sx->rank > sy->rank){
        sy->pai = sx;
    }else{
        sx->pai = sy;
        if(sx->rank == sy->rank){
            sy->rank++;
        }
    }
}

int main(){
    Item* i1 = criaItem(1);
    Item* i2 = criaItem(2);
    Item* i3 = criaItem(3);
    Item* i4 = criaItem(4);
    makeSet(i1);
    makeSet(i2);
    makeSet(i3);
    makeSet(i4);
    unionSets(i1,i3);
    unionSets(i3,i2);
    printf("%d,rank:%d\n ",find(i1)->dado,find(i1)->rank);
    printf("%d,rank:%d\n ",find(i2)->dado,find(i2)->rank);
    printf("%d,rank:%d\n ",find(i3)->dado,find(i3)->rank);
    printf("%d,rank:%d\n ",find(i4)->dado,find(i4)->rank);
    return 0;
}
