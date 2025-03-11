#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 197

typedef struct notas{
    int disciplina;                      //C�digo da disciplina. N�o vai ter utilidade pr�tica, mas pode ser usado para confer�ncia;
    int cod_avaliacao;
    int nota_aluno;
    struct notas *prox;
}Notas;

typedef struct aluno{
    int matricula;
    char* nome;
    char* curso;
    int data_curso;                     //Data de entrada no curso;
    int faltas;                         //Faltas s�o contabilizadas por dia na �nica turma existente;
    Notas *notas;
    struct aluno *prox;
}Aluno;

typedef struct avaliacao{
    char* nome_avaliacao;
    int valor_avaliacao;
    int cod_avaliacao;                  //Codigo correspondente a avalia��o;
    int disciplina;                     //C�digo da disciplina ao qual a avalia��o pertence. Para fins de confer�ncia;
    struct avaliacao *prox;
}Avaliacao;

typedef struct lista{
    Aluno *alunos;
}Lista;

typedef struct lista_avs{
    Avaliacao *avaliacoes;
}Lista_Avs;
