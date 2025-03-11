#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include"HeapSort.c"
#include"Lista 3 - Professor.c"
#include"quicksort.c"
#define TAM_MAX 200

void selectionsort (int *vet, int tam){
    int menor;
    for(int i=0; i<tam; i++)
    {
        menor = i;
        for(int j=(i+1); j<tam; j++)
        {
            if(vet[j]<vet[menor])
                menor=j;
        }
        vettroca(vet, i, menor);
    }
}

void insertionsort(int *vet, int tam){
    for (int i=1; i<tam; i++)
    {
        int j=i;
        while(j>0 && vet[j]<vet[j-1])
        {
            vettroca(vet, j, j-1);
            j--;
        }
    }
}

int binarysearch (int *vet, int key, int beg, int end){
    if(beg>end)
        return -1;
    int mid;
    mid = (beg+end)/2;
    if(vet[mid]==key)
        return mid;
    if(vet[mid]>key)
        return binarysearch(vet, key, beg, mid-1);
    if(vet[mid]<key)
        return binarysearch(vet, key, mid+1, end);
}

Heap* criarHeap2(Lista *l){
    Heap* h = (Heap*) malloc(sizeof(Heap));
    h->tam = 0;
    return h;
}

void heapSort2(int *vet, int n, Lista *l){
    Heap *h = criarHeap(l);
    for(int i = 0;i<n;i++){
        heap_insere(h,vet[i]);
    }
    for(int i = n-1;i>=0;i--){
        vet[i] = heap_extrai_max(h);
    }

}

void copia (Lista *l, int *vet, int vettam, int opcao){
    if(opcao == 1) //Lista encadeada para vetor;
    {
        No *aux = l->cabeca;
        int i = 0;

        while(aux != NULL && i<vettam)
        {
            vet[i++] = aux->chave;
            aux = aux->prox;
        }
        if(i==vettam && aux !=NULL)
          printf("Vetor menor que lista\n");
    }
    else if(opcao == 2) //Vetor para lista encadeada;
    {
        if(l->cabeca == NULL)
        {
            for(int jet=0; jet<vettam; jet++)
                insere(l, vet[jet], jet);
        }
        else //Consegui resolver o esvaziar lista;
        {
            printf("Lista tem elementos, preciso esvaziar ela!\n");
            No *aux = l->cabeca;
            No *aux2 = aux;

            while(aux != NULL) //Esvazia a lista;
            {
                printf("Removido: %d;\n", aux->chave);
                aux = aux->prox;
                free(aux2);
                aux2 = aux;
            }

            printf("Todos foram removidos!\n");
            l->cabeca = NULL;

            for(int j=0; j<vettam; j++)
                insere(l, vet[j], j);

        }
    }
    else
        printf("Entrada errada!\n");
}

int main(){

    srand(time(NULL));

    Lista *l = criaLista();
    int n = 100;
    for(int i = 0;i<n;i++){
            insere(l,rand()%99,0);
    }
    imprime2(l);

    printf("\n\n");

    Heap *h = criarHeap2(l);

    No *aux = l->cabeca;
    while(aux!=NULL)
    {
        heap_insere(h, aux->chave);
        aux = aux->prox;
    }
    heap_imprime(h);
    printf("\n\n");
    heapSort2(h->vet, h->tam, l);
    heap_imprime(h);
    printf("\n\n");

    int vet[l->contador];
    copia(l, vet, l->contador, 1);
    printvet(vet, l->contador);
    printf("\n\n");

    //QuickSort(vet, 0, l->contador);
    //printvet(vet, l->contador);

    //selectionsort(vet, l->contador);
    insertionsort(vet, l->contador);
    printvet(vet, l->contador);

    printf("%d\n", binarysearch(vet, 65, 0, l->contador));
    return 0;
}
