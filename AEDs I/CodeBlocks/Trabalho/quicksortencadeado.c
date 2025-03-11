#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//BY CHATGPT

void troca(Notas *a, Notas *b) {
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

Notas* particiona(Notas *inicio, Notas *fim) {
    int pivo = fim->nota_aluno;
    Notas *i = inicio->prox;
    Notas *j = inicio;

    while (j != fim) {
        if (j->nota_aluno > pivo) {
            troca(i, j);
            i = i->prox;
        }
        j = j->prox;
    }
    troca(i, fim);
    return i;
}

void quicksort(Notas *inicio, Notas *fim) {
    if (inicio != fim && inicio != NULL && fim != NULL && inicio != fim->prox) {
        Notas *pivo = particiona(inicio, fim);
        quicksort(inicio, pivo->prox);
        quicksort(pivo->prox, fim);
    }
}

void ordenaNotasAvaliacao(Aluno *aluno, int cod_avaliacao) {
    if (aluno == NULL) return;

    Notas *inicio = NULL;
    Notas *fim = NULL;
    Notas *atual = aluno->notas;

    // Encontrar o início e o fim da lista de notas da avaliação específica
    while (atual != NULL) {
        if (atual->cod_avaliacao == cod_avaliacao) {
            if (inicio == NULL) {
                inicio = atual;
            }
            fim = atual;
        }
        atual = atual->prox;
    }

    // Ordenar usando quicksort
    if (inicio != NULL && fim != NULL) {
        quicksort(inicio, fim);
    }
}
