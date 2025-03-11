#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 197

typedef struct notas{
    int disciplina;                      //Código da disciplina. Não vai ter utilidade prática, mas pode ser usado para conferência;
    int cod_avaliacao;
    int nota_aluno;
    struct notas *prox;
}Notas;

typedef struct aluno{
    int matricula;
    char* nome;
    char* curso;
    int data_curso;                     //Data de entrada no curso;
    int faltas;                         //Faltas são contabilizadas por dia na única turma existente;
    Notas *notas;
    struct aluno *prox;
}Aluno;

typedef struct avaliacao{
    char* nome_avaliacao;
    int valor_avaliacao;
    int cod_avaliacao;                  //Codigo correspondente a avaliação;
    int disciplina;                     //Código da disciplina ao qual a avaliação pertence. Para fins de conferência;
    struct avaliacao *prox;
}Avaliacao;

typedef struct lista{
    Aluno *alunos;
}Lista;

typedef struct lista_avs{
    Avaliacao *avaliacoes;
}Lista_Avs;
