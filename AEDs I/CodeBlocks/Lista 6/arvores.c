#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dado;
    struct no* pai;
    struct no* esq;
    struct no* dir;
}No;

typedef struct arv{
    No* raiz;
}Arv;

typedef struct fila{
    No *vet[100];
    int inicio;
    int fim;
    int numElementos;
}Fila;

Fila* criaFila(){
    Fila* nova = (Fila *) malloc(sizeof(Fila));
    nova->inicio = 0;
    nova->fim = 0;
    nova->numElementos = 0;
    return nova;
}

void enfilera(Fila* f, No* x){
    if(f->numElementos == 100){
        printf("queue overflow!");
        return;
    }
    f->numElementos++;
    f->vet[f->fim++] = x;
    f->fim = f->fim%100;
}

No* desenfilera(Fila* f){
    if(f->numElementos == 0){
        printf("queue underflow!");
        return NULL;
    }
    f->numElementos--;
    No* x = f->vet[f->inicio++];
    f->inicio = f->inicio%100;
    return x;
}

Arv* criaArvore(){
    Arv* nova = (Arv*) malloc(sizeof(Arv));
    nova->raiz = NULL;
    return nova;
}

No* criaNo(int dado){
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->pai = NULL;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void percursoEmOrdem(No* no){
    if(no == NULL) return;
    percursoEmOrdem(no->esq);
    printf("%d ",no->dado);
    percursoEmOrdem(no->dir);
}

void percursoPosOrdem(No* no){
    if(no == NULL) return;
    percursoPosOrdem(no->esq);
    percursoPosOrdem(no->dir);
    printf("%d ",no->dado);
}

void percursoPreOrdem(No* no){
    if(no == NULL) return;
    printf("%d ",no->dado);
    percursoPreOrdem(no->esq);
    percursoPreOrdem(no->dir);
}

void percursoLargura(No* no){
    Fila *f = criaFila();
    if(no == NULL) return;
    No* aux = no;
    enfilera(f,aux);
    while(f->numElementos>0){
        aux = desenfilera(f);
        printf("%d ",aux->dado);
        if(aux->esq!=NULL)
            enfilera(f,aux->esq);
        if(aux->dir!=NULL)
            enfilera(f,aux->dir);
    }
}

void insereABB(Arv* arv, int val){
    No* z = criaNo(val);

    No* y = NULL;
    No* x = arv->raiz;

    while(x!=NULL){
        y = x;
        if(x->dado > z->dado){
            x = x->esq;
        }else{
            x = x->dir;
        }
    }
    z->pai = y;
    if(y == NULL){
        arv->raiz = z;
    }else if(y->dado > z->dado){
        y->esq = z;
    }else{
        y->dir = z;
    }
}

No* buscaABB(No* no, int val){
    if(no == NULL || no->dado == val)
        return no;
    if(val > no->dado) buscaABB(no->dir, val);
    else buscaABB(no->esq, val);
}

int alturaABB(No* no){
    if(no == NULL) return -1;
    int alturaEsquerda = alturaABB(no->esq);
    int alturaDireita = alturaABB(no->dir);
    if(alturaEsquerda > alturaDireita)
        return alturaEsquerda + 1;
    else
        return alturaDireita + 1;
}

No* minimoABB(No* aux){
    if(aux == NULL) return NULL;
    while(aux->esq !=NULL)
        aux = aux->esq;
    return aux;
}

No* maximoABB(No* aux){
    if(aux == NULL) return NULL;
    while(aux->dir !=NULL)
        aux = aux->dir;
    return aux;
}

No* sucessorABB(No* aux){
    return minimoABB(aux->dir);
}

No* antecessorABB(No* aux){
    return maximoABB(aux->esq);
}

void transplantar(Arv* arv, No* u, No* v){
    if(u->pai==NULL){
        arv->raiz = v;
    }else if(u == u->pai->esq){
        u->pai->esq = v;
    }else{
        u->pai->dir = v;
    }
    if(v!=NULL){
        v->pai = u->pai;
    }
}

void deleta(Arv* arv, No* z){
    if(z->esq == NULL){
        transplantar(arv,z,z->dir);
    }else if(z->dir == NULL){
        transplantar(arv,z,z->esq);
    }else{
        No* y = sucessorABB(z);
        if(y->pai != z){
            transplantar(arv,y,y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        transplantar(arv,z,y);
        y->esq = z->esq;
        y->esq->pai = y;
    }
    free(z);
}

void deletaABB(Arv* arv, int x){
    No* no = buscaABB(arv->raiz,x);
    if(no!=NULL)
        deleta(arv,no);
}

void imprimeNivel(No* no, int nivel){
    if(nivel == 0){
        printf("%d ", no->dado);
        return;
    }
    if(no->esq !=NULL) imprimeNivel(no->esq, nivel-1);
    if(no->dir !=NULL) imprimeNivel(no->dir, nivel-1);
}

void imprimeArvoreLinhas(Arv* arv){
    for(int i = 0;i<= alturaABB(arv->raiz);i++){
        imprimeNivel(arv->raiz,i);
        printf("\n");
    }
}

void imprimeOrganizadoAux(No* no, int nivel){
    if(no == NULL) return;
    printf("|");
    for(int i = 0;i<nivel;i++) printf("-");
    if(no->pai!=NULL){
        //if(no->pai->dir == no) printf("D");
        //else printf("E");
    }
    printf("%d\n",no->dado);
    imprimeOrganizadoAux(no->esq,nivel+1);
    imprimeOrganizadoAux(no->dir,nivel+1);
}

void imprimeOrganizado(Arv* arvore){
    imprimeOrganizadoAux(arvore->raiz, 0);
}

/********************************************/

int filhos (No *filho, int contagem){

    contagem++;

    if(filho == NULL){
        return contagem;
    }

    filhos(filho->esq, contagem);
    filhos(filho->dir, contagem);

}

void contagem_filhos (Arv *arvore){
    No *aux = arvore->raiz;
    int contagem = 0;

    int a = filhos(aux->esq, contagem);
    int b = filhos(aux->dir, contagem);

    printf("\n\nA arvore possui %d filhos", (a+b));
}

void reflexao2 (No *no){
    if(no == NULL)  return;
    No *aux = no->esq;
    no->esq = no->dir;
    no->dir = aux;

    reflexao2(no->esq);
    reflexao2(no->dir);
}

int buscaABB2(No* no, int val){
    if(no == NULL)
        return -1;
    if(no->dado == val)
        return 1;
    if(val > no->dado) buscaABB2(no->dir, val);
    else buscaABB2(no->esq, val);
}

void busca(No *no, Arv* arv2){
    if(no == NULL)
        return;

    if(buscaABB2(arv2->raiz, no->dado) == 1){
        busca(no->dir, arv2);
        busca(no->esq, arv2);
    }else{
        printf("\n\nAs arvores possuem valores diferentes!");
        return;
    }
}

void checa__vals (Arv *arv1, Arv *arv2){
    busca(arv1->raiz, arv2);
}

void checa_similaridade (No* no1, No *no2){          //SLA, MAN... NÃO SEI COMO IMPEDIR OS PRINTS;
    if(no1 == NULL && no2 == NULL)    return;

    if(no1 == NULL && no2 != NULL){
        printf("Deu pau!\n");
        return;
    }
    if(no2 == NULL && no1 != NULL){
        printf("Deu pau!\n");
        return;
    }

    if(no1 != NULL && no2 != NULL){
    checa_similaridade(no1->esq, no2->esq);
    checa_similaridade(no1->dir, no2->dir);
    }

}

int ehABB (No *no){         //SLA SE TÁ CERTO;
    if(no == NULL) return 0;

    if(no->esq < no){
        ehABB(no->esq);
        return 1;
    }
    else if(no->dir > no){
        ehABB(no->dir);
        return 1;
    }
    else return -1;
}

insereABB_recaux(No *no, int val){
    No *noz = criaNo(val);

    if(val > no->dado){
        if(no->dir == NULL){
            no->dir = noz;
            return;
        }
        insereABB_recaux(no->dir, val);
    }
    if(val < no->dado){
        if(no->esq == NULL){
            no->esq = noz;
            return;
        }
        insereABB_recaux(no->esq, val);
    }
}

void insereABB_rec (Arv *arvore, int val){
    No *noz = criaNo(val);
    if(arvore->raiz == NULL){
        arvore->raiz = noz;
        return;
    }
    insereABB_recaux(arvore->raiz, val);


}

int main(){
    Arv* arvore = criaArvore();

    insereABB(arvore,15);
    insereABB(arvore, 6);
    insereABB(arvore, 18);
    insereABB(arvore, 3);
    insereABB(arvore, 7);
    insereABB(arvore, 17);
    insereABB(arvore, 20);
    imprimeOrganizado(arvore);
    printf("\n\n");

    contagem_filhos(arvore);
    reflexao2(arvore->raiz);
    printf("\n\n");
    imprimeOrganizado(arvore);
    printf("\n\n");

    Arv* arv1 = criaArvore();
    Arv* arv2 = criaArvore();
    insereABB(arv1, 2);
    insereABB(arv1, 4);
    insereABB(arv1, 1);
    insereABB(arv1, 3);
    imprimeOrganizado(arv1);
    printf("\n\n");

    insereABB_rec(arv2, 3);
    insereABB_rec(arv2, 2);
    insereABB_rec(arv2, 5);
    insereABB_rec(arv2, 4);
    imprimeOrganizado(arv2);

    checa__vals(arv1, arv2);
    printf("\n\n");
    checa_similaridade(arv1->raiz, arv2->raiz);
    printf("%d\n\n", ehABB(arv1->raiz));


    return 0;
}
