#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct notas{
    int disciplina;                      //Código da disciplina. Não vai ter utilidade prática, mas pode ser usado para conferência;
    int cod_avaliacao;
    float nota_aluno;
    struct notas *prox;
}Notas;

typedef struct aluno{
    int matricula;
    char* nome;
    char* curso;
    int data_curso;                     //Data de entrada no curso;
    int faltas;                         //Faltas são contabilizadas por dia na única turma existente;
    Notas *notas;
    float somatorio_notas;
    struct aluno *prox;
}Aluno;

typedef struct avaliacao{
    char* nome_avaliacao;
    float valor_avaliacao;
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

typedef struct lista_notas{
    Notas* notas;
}Lista_notas;

#endif // HEADER_H_INCLUDED
