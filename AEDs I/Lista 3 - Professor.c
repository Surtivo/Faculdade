#include <stdio.h>
#include<stdlib.h>

typedef struct aluno{
    int matricula;
    char nome[100];
    char curso[100];
}Aluno;

typedef struct no{
    int chave;
    struct no * prox;
    struct no * ant;
}No;

typedef struct lista{
    No* cabeca;
    No* fim;
    int contador;
}Lista;

void insere(Lista *l, int i,char nome[100],int matricula, char curso[100]){
    No* novo = (No*) malloc(sizeof(No));
    printf("Informe a matricula");
    scanf("%d", &novo->matricula);
}
Lista* criaLista(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->cabeca = NULL;
    l->fim = NULL;
    l->contador = 0;
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
    if(i>l->contador){
        printf("Indice invalido");
        return;
    }
    l->contador++;
    No* novo = (No*) malloc(sizeof(No));
    novo->chave = x;
    if(i == l->contador -1){
        l->fim = novo;
    }
    if(i == 0){
        novo->prox = l->cabeca;
        l->cabeca = novo;
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
        novo->prox = anterior->prox;
        anterior->prox = novo;
        novo->ant = anterior;
        if(novo->prox!=NULL)
            novo->prox->ant = novo;

    }
}

void imprime(Lista * l){
    No* aux = l->cabeca;
    while(aux!=NULL){
        printf("%d ",aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

void remove(Lista* l, int x){
   No* removido = busca(l,x);
   if(removido == NULL) return;
   if(removido->ant!=NULL){
    removido->ant->prox = removido->prox;
   }else{
    l->cabeca = removido->prox;
   }
   if(removido->prox!=NULL){
    removido->prox->ant = removido->ant;
   }else{
    l->fim = removido->ant;
   }
   l->contador--;
   free(removido);
}

void troca(Lista *l, int i, int j){     //O(n) percorre somente uma vez;
    if(i>= l->contador || j>= l->contador){
        printf("Indices invalidos!\n");
        return;
    }
    No* aux = l->cabeca;
    No* noI=NULL;
    No* noJ=NULL;
    int k = 0;
    while(aux!=NULL){
        if(k == i)
            noI = aux;
        if(k == j)
            noJ = aux;
        if(noI !=NULL && noJ!= NULL) break;
        aux= aux->prox;
        k++;
    }

    int auxTroca = noI->chave;
    noI->chave = noJ->chave;
    noJ->chave = auxTroca;

}

void trocaNos(Lista *l, int i, int j){
    if(i>= l->contador || j>= l->contador){
        printf("Indices invalidos!\n");
        return;
    }
    No* aux = l->cabeca;
    No* noI=NULL;
    No* noJ=NULL;
    int k = 0;
    while(aux!=NULL){
        if(k == i)
            noI = aux;
        if(k == j)
            noJ = aux;
        if(noI !=NULL && noJ!= NULL) break;
        aux= aux->prox;
        k++;
    }
    if(l->cabeca == noI) l->cabeca = noJ;
    else if(l->cabeca == noJ) l->cabeca = noI;
    if(l->fim == noI) l->fim = noJ;
    else if(l->fim == noJ) l->fim = noI;

    if(noI->ant!=NULL && noI->ant != noJ)
        noI->ant->prox = noJ;
    if(noI->prox!=NULL && noI->prox!=noJ)
        noI->prox->ant = noJ;
    if(noJ->ant!=NULL && noJ->ant != noI)
        noJ->ant->prox = noI;
    if(noJ->prox!=NULL && noJ->prox !=noI)
        noJ->prox->ant = noI;

    No * auxTroca = noJ->prox;
    noJ->prox = noI->prox;
    noI->prox = auxTroca;

    auxTroca = noJ->ant;
    noJ->ant = noI->ant;
    noI->ant = auxTroca;


    //Gambiarra para resolver o erro de quando os elementos são adjacentes. Aqui apenas consertamos sabendo qual tipo de erro irá ser propiciado.
    //Nesse caso, sabemos que os erros gerados serão loops em torno de sí mesmo e apenas fezemos os apontamento apontarem para o lugar certo.
    if(noI->ant == noI) noI->ant= noJ;
    if(noJ->prox== noJ) noJ->prox = noI;
    if(noI->prox == noI) noI->prox = noJ;
    if(noJ->ant == noJ) noJ->ant = noI;
}

No* acessa(Lista  *l, int i){           //Não percorre a lista toda quando o índice não existe na lista. Sendo O(1) quando o índice é inválido.
    if(i>= l->contador){
        printf("Indice invalido.\n");
        return NULL;
    }
    No* aux = l->cabeca;
    int k = 0;
    while(k<i){
        aux= aux->prox;
        k++;
    }
    return aux;

}

void removeIndice(Lista* l, int i){
   No* removido = acessa(l,i);
   if(removido == NULL) return;
   if(removido->ant!=NULL){
    removido->ant->prox = removido->prox;
   }else{
    l->cabeca = removido->prox;
   }
   if(removido->prox!=NULL){
    removido->prox->ant = removido->ant;
   }else{
    l->fim = removido->ant;
   }
   l->contador--;
   free(removido);
}


void imprimeInvertido(Lista * l){
    No* aux = l->fim;
    while(aux!=NULL){
        printf("%d ",aux->chave);
        aux = aux->ant;
    }
    printf("\n");
}

void removeTodos(Lista *l, int x){              //O(n), percorro a lista somente uma vez;
    No* aux = l->cabeca;
    No* auxEliminado=NULL;
    while(aux!=NULL){
        if(aux->chave == x){
            if(aux->ant!=NULL)
                aux->ant->prox = aux->prox;
            else
                l->cabeca = aux->prox;

            if(aux->prox!=NULL)
                aux->prox->ant = aux->ant;
            else
                l->fim = aux->ant;
            auxEliminado = aux;
        }

        aux = aux->prox;

        if(auxEliminado!=NULL){
            free(auxEliminado);
            l->contador --;
            auxEliminado = NULL;
        }
    }
}

void removeTodos2(Lista *l, int x){
    while(busca(l,x)!=NULL)
        remove(l,x);
}

void imprimeResto(No *no){
    if(no == NULL) return;
    printf("%d ",no->chave);
    imprimeResto(no->prox);
}

void imprime2(Lista *l){
    imprimeResto(l->cabeca);
}

int maiorElemento(No* no){
    if(no->prox ==NULL){
        return no->chave;
    }
    int aux = maiorElemento(no->prox);
    if(no->chave > aux){
        return no->chave;
    }else
        return aux;

}

void encadeadaParaContigua(Lista *l, int vet[]){
    No* aux = l->cabeca;
    int k =0;
    while(aux!=NULL){
        vet[k] = aux->chave;
        aux = aux->prox;
    }
}

void contiguaParaEncadeada(int vet[], int n, Lista *l){
    for(int i = n-1;i>=0;i--){
        insere(l,vet[i],0);
    }
}

int main(){
    Lista *l = criaLista();
    int n = 2;
    for(int i = 0;i<n;i++){
            insere(l,i,0);
    }
    imprime2(l);
    return 0;
}
