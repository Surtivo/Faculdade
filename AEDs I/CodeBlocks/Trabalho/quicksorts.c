#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "header.h"
#include "quicksorts.h"
#define TAM 197

void imprime_hashe_v2 (Aluno **tabela_hash, int caso) {        //Aqui recebemos a tabela e o número do caso. Desse modo, sabemos em qual ordem fazer a impressão;
    printf("\n\n----------Inicio da Tabela Hash----------\n\n");
    if(caso == 1){
        for (int i=0; i<5; i++) {
            if (tabela_hash[i] != NULL) {  //Verifica se a posição não é NULL;
                printf("Matricula: %d\t| Nome: %s\t| Somatorio das notas: %d\t| Total de faltas: %d\n", tabela_hash[i]->matricula, tabela_hash[i]->nome, tabela_hash[i]->somatorio_notas, tabela_hash[i]->faltas);
            }
        }
    }
    if(caso == 2){
        for (int i=0; i<5; i++) {
            if (tabela_hash[i] != NULL) {  //Verifica se a posição não é NULL;
                printf("Nome: %s\t| Matricula: %d\t| Somatorio das notas: %d\t| Total de faltas: %d\n", tabela_hash[i]->nome, tabela_hash[i]->matricula, tabela_hash[i]->somatorio_notas, tabela_hash[i]->faltas);
            }
        }
    }
    if(caso == 3){
        for (int i=0; i<5; i++) {
            if (tabela_hash[i] != NULL) {  //Verifica se a posição não é NULL;
                printf("Somatorio das notas: %d\t| Matricula: %d\t| Nome: %s\t| Total de faltas: %d\n", tabela_hash[i]->somatorio_notas, tabela_hash[i]->matricula, tabela_hash[i]->nome, tabela_hash[i]->faltas);
            }
        }
    }
    if(caso == 4){
        for (int i=0; i<5; i++) {
            if (tabela_hash[i] != NULL) {  //Verifica se a posição não é NULL;
                printf("Numero de faltas: %d\t| Matricula: %d\t| Nome: %s\t| Somatorio das notas: %d\n", tabela_hash[i]->faltas, tabela_hash[i]->matricula, tabela_hash[i]->nome, tabela_hash[i]->somatorio_notas);
            }
        }
    }
    printf("\n-----------------------------------------\n");
}

void troca_posicao(Aluno **tabela_hash, int k, int l) {
    if (k < 0 || l < 0 || k >= 5 || l >= 5) {
        printf("Índices fora dos limites!\n");
        return;
    }

    Aluno *temp = tabela_hash[k];
    tabela_hash[k] = tabela_hash[l];
    tabela_hash[l] = temp;
}

int particiona_mat(Aluno **tabela_hash, int beg, int end) {

    int pivo = ((tabela_hash[end]->matricula) + (tabela_hash[beg]->matricula) + (tabela_hash[(end+beg)/2]->matricula)) / 3;

    while (beg < end) {
        while (beg<end && (tabela_hash[beg] == NULL || tabela_hash[beg]->matricula <= pivo)) {
            beg++;
        }

        while (beg<end && (tabela_hash[end] == NULL || tabela_hash[end]->matricula > pivo)) {
            end--;
        }
        troca_posicao(tabela_hash, beg, end);
    }
    return beg;
}
void quicksort_mat(Aluno **tabela_hash, int beg, int end) {
    if (beg < end) {
        int mid = particiona_mat(tabela_hash, beg, end);
        quicksort_mat(tabela_hash, beg, mid-1);
        quicksort_mat(tabela_hash, mid, end);
    }
}

int particiona_nome (Aluno **tabela_hash, int beg, int end) {
    Aluno *pivo = tabela_hash[end]; // Escolhe o último elemento como pivô
    int i = beg - 1;

    for (int j = beg; j < end; j++) {
        if (strcmp(tabela_hash[j]->nome, pivo->nome) < 0) {
            i++;
            troca_posicao(tabela_hash, i, j);
        }
    }

    troca_posicao(tabela_hash, i + 1, end);
    return (i + 1);
}
void quicksort_nome (Aluno **tabela_hash, int beg, int end) {
    if (beg < end) {
        int mid = particiona_nome(tabela_hash, beg, end);
        quicksort_nome(tabela_hash, beg, mid - 1);
        quicksort_nome(tabela_hash, mid, end);
    }
}

int particiona_somatorio(Aluno **tabela_hash, int beg, int end) {

    int pivo = ((tabela_hash[end]->somatorio_notas) + (tabela_hash[beg]->somatorio_notas) + (tabela_hash[(end+beg)/2]->somatorio_notas)) / 3;

    while (beg < end) {
        while (beg<end && (tabela_hash[beg] == NULL || tabela_hash[beg]->somatorio_notas <= pivo)) {
            beg++;
        }

        while (beg<end && (tabela_hash[end] == NULL || tabela_hash[end]->somatorio_notas > pivo)) {
            end--;
        }
        troca_posicao(tabela_hash, beg, end);
    }
    return beg;
}
void quicksort_somatorio(Aluno **tabela_hash, int beg, int end) {
    if (beg < end) {
        int mid = particiona_somatorio(tabela_hash, beg, end);
        quicksort_somatorio(tabela_hash, beg, mid-1);
        quicksort_somatorio(tabela_hash, mid, end);
    }
}

int particiona_falta(Aluno **tabela_hash, int beg, int end) {

    int pivo = ((tabela_hash[end]->faltas) + (tabela_hash[beg]->faltas) + (tabela_hash[(end+beg)/2]->faltas)) / 3;

    while (beg < end) {
        while (beg<end && (tabela_hash[beg] == NULL || tabela_hash[beg]->faltas <= pivo)) {
            beg++;
        }

        while (beg<end && (tabela_hash[end] == NULL || tabela_hash[end]->faltas > pivo)) {
            end--;
        }
        troca_posicao(tabela_hash, beg, end);
    }
    return beg;
}
void quicksort_falta(Aluno **tabela_hash, int beg, int end) {
    if (beg < end) {
        int mid = particiona_falta(tabela_hash, beg, end);
        quicksort_falta(tabela_hash, beg, mid-1);
        quicksort_falta(tabela_hash, mid, end);
    }
}


void relatorio_alunos (Aluno **tabela_hash){
    printf("\n\nDigite um numero para organizar o relatorio por:\n\t1 - Matricula\n\t2 - Nome\n\t3 - Somatorio das notas\n\t4 - Numero de faltas\n");       //Menu;

    int aux;
    scanf("%d", &aux);
    getchar();

    Aluno *tabela_aux [5];      //Tabela auxiliar com tamanho do número de alunos;
    int j = 0;
    switch (aux){
        case 1:
            for(int i=0; i<TAM; i++){
                    if(tabela_hash[i] != NULL){             //Passamos os parâmetros da TabelaHash principal para a auxiliar. Mas apenas se a TabelaHash tiver algo;
                        tabela_aux[j++] = tabela_hash[i];
                        //printf("Matricula: %d\n", tabela_aux[j++]->matricula);
                    }
                }
            quicksort_mat(tabela_aux, 0, 4);                //Chamamos um quicksort para o tipo de organização desejada;
            imprime_hashe_v2(tabela_aux, 1);
            break;
        case 2:
            for(int i=0; i<TAM; i++){
                    if(tabela_hash[i] != NULL){
                        tabela_aux[j++] = tabela_hash[i];
                    }
                }
            quicksort_nome(tabela_aux, 0, 4);
            imprime_hashe_v2(tabela_aux, 2);
            break;
        case 3:
                for(int i=0; i<TAM; i++){
                    if(tabela_hash[i] != NULL){
                        tabela_aux[j++] = tabela_hash[i];
                        //printf("Somatorio: %d\n", tabela_aux[j++]->somatorio_notas);
                    }
                }
            quicksort_somatorio (tabela_aux, 0, 4);
            imprime_hashe_v2(tabela_aux, 3);
            break;
        case 4:
            for(int i=0; i<TAM; i++){
                    if(tabela_hash[i] != NULL){
                        tabela_aux[j++] = tabela_hash[i];
                        //printf("Numero de faltas: %d\n", tabela_aux[j++]->faltas);
                    }
                }
            quicksort_falta(tabela_aux, 0, 4);
            imprime_hashe_v2(tabela_aux, 4);
            break;
        default:
            printf("Selecao invalida! Tente novamente.\n");
    }
}
