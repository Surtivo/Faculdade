#include <stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    struct no * prox;
    struct no * ant;
}No;

typedef struct lista{
    No* cabeca;
    No* fim;
    int count;
}Lista;

void trocaNos(Lista *l, int i, int j);

Lista* criaLista(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->cabeca = NULL;
    l->fim = NULL;
    return l;
}

No* busca(Lista* l, int x){
    No* aux;
    aux = l->cabeca;
    while(aux!=NULL && aux->chave != x){
        aux = aux->prox;
    }
    return aux;
}

void insere(Lista* l, int x, int i){
    No* novo = (No*) malloc(sizeof(No));
    novo->chave = x;
    if(i == 0){
        novo->prox = l->cabeca;
        l->cabeca = novo;
        l->fim = novo;
        novo->ant = NULL;
        if(novo->prox!=NULL)
            novo->prox->ant = novo;
    }
    else{
        int j = 1;
        No* anterior = l->cabeca;
        while(anterior!=NULL && j<i){
            anterior = anterior->prox;
            j++;
        }

        if(anterior == NULL){
            printf("Indice nao existe");
        }else{
            novo->prox = anterior->prox;
            anterior->prox = novo;
            novo->ant = anterior;
            if(novo->prox == NULL)
                l->fim = novo;
            if(novo->prox!=NULL)
                novo->prox->ant = novo;
        }
    }
}

void imprime(Lista * l){

    int count = 0;

    No* aux = l->cabeca;
    while(aux!=NULL){
        printf("%d ",aux->chave);
        count++;
        aux = aux->prox;
    }
    printf("\n");
}

void remover(Lista* l, int x){
   No* removido = busca(l,x);
   if(removido->ant!=NULL){
    removido->ant->prox = removido->prox;
   }else{
    l->cabeca = removido->prox;
   }
   if(removido->prox!=NULL){
    removido->prox->ant = removido->ant;
   }
   else
   {
     l->fim = removido->ant;
     removido->ant->prox = NULL;
   }
   free(removido);
   l->count++;
}

void troca(Lista *l, int i, int j)  //O(n^2) percorro duas vezes;
{

    int aux1 = 0;
    int aux2 = 0;

    No* anterior1 = l->cabeca;
    while(anterior1!=NULL && aux1<i)
    {
        anterior1 = anterior1->prox;
        aux1++;
    }

    No* anterior2 = l->cabeca;
    while(anterior2!=NULL && aux2<j)
    {
        anterior2 = anterior2->prox;
        aux2++;
    }

    int aux = anterior1->chave;
    anterior1->chave = anterior2->chave;
    anterior2->chave = aux;

}

int acessa (Lista *l, int i)  //Percorro a lista toda, sempre.
{
    int aux = 0;

    No* anterior = l->cabeca;
    while(anterior!=NULL && aux<i)
    {
        anterior = anterior->prox;
        aux++;
    }
    if(anterior!=NULL)
        return anterior->chave;
    else
        return -1;
}

void removeind(Lista *l, int i)
{

    int j = 0;

    No *anterior = l->cabeca;
    No *aux = NULL;

    if(i==0)
    {
        l->cabeca = anterior->prox;
        anterior->prox->ant = anterior->ant; //anterior->ant == NULL;
    }

    while(anterior!=NULL && j<i)
    {
        aux = anterior;
        anterior = anterior->prox;
        j++;
    }

    if(anterior==NULL)
        printf("Erro!\n");
    else
    {
        if(anterior->ant==NULL)             //Isso não vai executar apenas se for o primeiro?
        {
            l->cabeca = anterior->prox;
            anterior->prox->ant = NULL;
        }
        else if(anterior->prox==NULL)
        {
            anterior->ant->prox = NULL;
            l->fim = anterior->ant;
        }
        else
        {
            aux->prox = anterior->prox;
            anterior->prox->ant = aux;
        }
    }

    free(anterior);
}

void imprimeR(Lista * l){
    No* aux = l->fim;
    while(aux!=NULL){
        printf("%d ",aux->chave);
        aux = aux->ant;
    }
    printf("\n");
}

void eliminatodos (Lista *l, int x)   //O(n^m), onde m é o número de elementos com a chave=x. Percorro vária e várias vezes a lista
{
    No *aux = busca(l, x);

    while(aux != NULL)
    {
        if(aux->ant == NULL)
        {
            l->cabeca = aux->prox;
            aux->prox->ant = aux->ant;
            l->count++;
            aux = busca(l, x);
        }

        else if (aux->prox == NULL)
        {
            aux->ant->prox = NULL;
            l->count++;
            aux = busca(l, x);
        }

        else
        {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            l->count++;
            aux = busca(l, x);
        }
    }
    free(aux);
}

void imprimeresto (No* no)
{
    No *aux = no;
    if(aux != NULL)
    {
        printf("%d ", aux->chave);
        imprimeresto(aux->prox);
        return;
    }
    printf("\n");
}

void copia (Lista *l, int *vet, int vettam, int opcao)
{
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
    Lista *l = criaLista();
    l->count = 0;

    insere(l,2,0);
    insere(l,3,0);
    insere(l,4,0);
    insere(l,7,1);
    imprime(l);
    remover(l,3);
    imprime(l);
    troca(l, 0, 1);
    insere(l, 10, 3);
    insere(l, 9, 4);
    imprime(l);
    printf("%d\n", acessa(l, 0));
    removeind(l, 4);
    imprime(l);
    removeind(l, 0);
    imprime(l);
    printf("%d\n", l->fim->chave);
    imprimeR(l);
    insere(l, 1, 2);
    insere(l, 4, 3);
    imprime(l);
    eliminatodos(l, 4);
    imprime(l);
    insere(l, 7, 3);
    imprime(l);
    eliminatodos(l, 7);
    imprime(l);
    insere(l, 10, 3);
    imprime(l);
    eliminatodos(l, 10);
    imprime(l);
    insere(l, 1, 0);
    imprime(l);
    eliminatodos(l, 1);
    imprime(l);
    insere(l, 1, 0);
    insere(l, 3, 2);
    insere(l, 4, 0);
    insere(l, 5, 0);
    insere(l, 6, 5);

    imprimeresto(l->cabeca);

    printf("\n");

    int vet[6];
    copia(l, vet, 6, 1);
    for(int i=0; i<6; i++)
        printf("%d\t", vet[i]);

    printf("\n\nVetor criado: ");

    int vet2[5] = {0, 1, 2, 3, 4};
    for(int j=0; j<5; j++)
        printf("\t%d", vet2[j]);

    printf("\n\nVetor criado2: ");

    int vet3[5] = {8, 4, 5, 0, 1};
    for(int p=0; p<5; p++)
        printf("\t%d", vet3[p]);

    printf("\n\n");

    Lista *k = criaLista();
    copia(k, vet2, 5, 2);
    imprime(k);

    printf("\n");

    copia(l, vet3, 5, 2);
    imprime(l);

    printf("\n\n");

    trocaNos(l, 1, 3);
    imprime(l);

    trocaNos(l, 1, 2);
    imprime(l);

    trocaNos(l, 2, 1);
    imprime(l);

    trocaNos(l, 0, 3);
    imprime(l);

    return 0;
}

// Questão 3. Funciona parcialmente. Não para todos os tipos de trocas.
// Complexidade O(n^2), percorremos a lita duas vezes.
void trocaNos(Lista *l, int i, int j)
{

    int aux1 = 0;
    int aux2 = 0;

    No *auxn1;
    No *auxn2;

    No* anterior1 = l->cabeca;
    while(anterior1!=NULL && aux1<i)
    {
        anterior1 = anterior1->prox;
        aux1++;
    }

    No* anterior2 = l->cabeca;
    while(anterior2!=NULL && aux2<j)
    {
        anterior2 = anterior2->prox;
        aux2++;
    }

    if(i==0 || j==0)
    {
        if(i==0)
        {
            auxn1 = (anterior2->prox);
            auxn2 = (anterior2->ant);

            l->cabeca = anterior2;
            anterior2->prox = anterior1->prox;
            auxn2->prox = anterior1;
            anterior1->prox = auxn1;
        }
    }

    else if(j==i+1 || i==j+1)
    {
        if(j==i+1)
        {
            auxn1 = (anterior2->prox);

            anterior1->ant->prox = anterior2;
            anterior2->prox = anterior1;
            anterior2->ant = anterior1->ant;

            anterior1->prox = auxn1;
            auxn1->ant = anterior1;
        }
        else
        {
            auxn1 = (anterior1->prox);

            anterior2->ant->prox = anterior1;
            anterior1->prox = anterior2;
            anterior1->ant = anterior2->ant;

            anterior2->prox = auxn1;
            auxn1->ant = anterior2;
        }
    }
    else if(anterior1->prox==NULL || anterior2->prox == NULL)
    {

    }
    else
    {
    auxn1 = (anterior2->prox);
    auxn2 = (anterior2->ant);

    anterior2->ant = anterior1->ant;
    anterior1->ant->prox = anterior2;
    anterior2->prox = anterior1->prox;

    auxn2->prox = anterior1;
    anterior1->ant = auxn2;

    anterior1->prox = auxn1;
    auxn1->ant = anterior1;
    }
}

