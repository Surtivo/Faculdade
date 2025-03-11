#ifndef QUICKSORTS_H_INCLUDED
#define QUICKSORTS_H_INCLUDED

void imprime_hashe (Aluno **tabela_hash, int caso);
void troca_posicao (Aluno **tabela_hash, int k, int l);

int particiona_mat(Aluno **tabela_hash, int beg, int end);
void quicksort_mat(Aluno **tabela_hash, int beg, int end);

int particiona_nome (Aluno **tabela_hash, int beg, int end);
void quicksort_nome (Aluno **tabela_hash, int beg, int end);

int particiona_somatorio (Aluno **tabela_hash, int beg, int end);
void quicksort_somatorio(Aluno **tabela_hash, int beg, int end);

int particiona_falta(Aluno **tabela_hash, int beg, int end);
void quicksort_falta(Aluno **tabela_hash, int beg, int end);

void relatorio_alunos (Aluno **tabela_hash);

#endif // QUICKSORTS_H_INCLUDED
