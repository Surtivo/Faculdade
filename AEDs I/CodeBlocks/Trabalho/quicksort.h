#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

typedef struct lista_notas{
    Notas* notas;
}Lista_notas;

Lista_notas* cria_lista_notas ();
void printa_lista_ordenada (Lista_notas* l);
void troca_notas (Notas *a, Notas *b);
void insere_nota(Lista_notas* l, Notas *av_aluno);
Notas* particiona(Notas *inicio, Notas *fim);
void QuickSort(Notas *inicio, Notas *fim);
void ordenaNotasAvaliacao(Lista *l, int cod_avaliacao);

#endif // QUICKSORT_H_INCLUDED
