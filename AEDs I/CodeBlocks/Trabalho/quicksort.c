#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
#include "quicksort.h"

//Monta de forma decrescente;

Lista_notas* cria_lista_notas (){
    Lista_notas *nova = (Lista_notas*) malloc(sizeof(Lista_notas));
    nova->notas = NULL;
    return nova;
}

void printa_lista_ordenada (Lista_notas* l){
    int i = 1;
    Notas *atual = l->notas;
    printf("Notas Gerais:\n");
    while (atual != NULL) {
        printf("Nota %d: %d\n",i++, atual->nota_aluno);
        atual = atual->prox;
    }
}

void troca_notas (Notas *a, Notas *b){
    int tempNota = a->nota_aluno;
    int tempDisciplina = a->disciplina;
    int tempCodAvaliacao = a->cod_avaliacao;

    a->nota_aluno = b->nota_aluno;
    a->disciplina = b->disciplina;
    a->cod_avaliacao = b->cod_avaliacao;

    b->nota_aluno = tempNota;
    b->disciplina = tempDisciplina;
    b->cod_avaliacao = tempCodAvaliacao;
}

void insere_nota(Lista_notas* l, Notas *av_aluno){
    av_aluno->prox = l->notas;
    l->notas = av_aluno;
}

Notas* particiona(Notas *inicio, Notas *fim){
    int pivo = fim->nota_aluno;     //Usa como piv� a nota do �ltimo aluno;
    Notas *i = inicio;
    Notas *j = inicio;

    while (j != fim) {
        if (j->nota_aluno > pivo) {
            troca_notas(i, j);      //Chama a fun��o "troca_notas" para trocar as notas de posi��o;
            i = i->prox;
        }
        j = j->prox;
    }
    troca_notas(i, fim);
    return i;
}

void QuickSort(Notas *inicio, Notas *fim){
    if (inicio != fim && inicio != NULL && fim != NULL && inicio != fim->prox){     //Executa o QuickSort apenas se in�cio e fim forem diferentes entre si e diferente de nulo;
        Notas *pivo = particiona(inicio, fim);
        if(pivo->prox == NULL || pivo == fim)
            return;
        QuickSort(inicio, pivo);
        QuickSort(pivo->prox, fim);
    }
}

void ordenaNotasAvaliacao(Lista *l, int cod_avaliacao){
    if (l == NULL || l->alunos == NULL) return;         //Se n�o houver nenhum aluno cadastrado, n�o h� nada para ordenar. A fun��o termina;

    Notas *inicio = NULL;
    Notas *fim = NULL;
    Aluno *atual = l->alunos;
    Notas *av_aluno;

    Lista_notas *l_notas = cria_lista_notas();      //Cria uma lista auxiliar para ordenar as notas;

    //Encontrar o in�cio e o fim da lista de notas da avalia��o espec�fica
    while(atual != NULL){
        av_aluno = atual->notas;
        while(av_aluno != NULL){
            if(av_aluno->cod_avaliacao == cod_avaliacao && fim == NULL){            //Para conseguir marcar quem � o final;
                insere_nota(l_notas, av_aluno);
                fim = l_notas->notas;
                break;
            }else if(av_aluno->cod_avaliacao == cod_avaliacao && fim != NULL){      //Encadeia o resto das notas, sempre marcando a �ltima inserida como o in�cio;
                insere_nota(l_notas, av_aluno);
                inicio = l_notas->notas;
                break;
            }
            else av_aluno = av_aluno->prox;     //Se a avalia��o atual n�o for a procurada, passamos para a pr�xima;
        }
        if(av_aluno == NULL)                    //Se n�o acharmos a avalia��o;
            printf("O aluno %s de matricula %d nao fez essa avaliacao!", atual->nome, atual->matricula);

        atual = atual->prox;        //Passamos para o pr�ximo aluno;
    }

    //Ordenar usando quicksort;
    if (inicio != NULL && fim != NULL) {
        QuickSort(inicio, fim);
    }
    printa_lista_ordenada(l_notas);
    //free(l_notas);
}
