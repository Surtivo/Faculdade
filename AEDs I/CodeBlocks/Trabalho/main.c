#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#define TAM 197

//Criação e Manipulação de Listas;
Lista* crialista ();
Lista_Avs* crialista_avs ();
void printalista (Lista *l);
void printalista_avs (Lista_Avs *l);

//Funções de Hash;
unsigned int funcao_hash(int chave, int tamanho_tabela);
void insere_hash (Aluno *aluno, Aluno **tabela_hash);
void imprime_hash (Aluno **tabela_hash);
void imprime_hashe_v2 (Aluno **tabela_hash, int caso);

//Funções de Avaliação;
void distribui_avaliacao (Avaliacao *av, Lista *l);
int checa_nota_av (Avaliacao *av, float nota);
int checa_av_igual (Lista_Avs *l_avs, Avaliacao *av);
void cadastra_avaliacao (Lista *l, Lista_Avs *l_avs);
void checa_avs (Avaliacao *teste, Aluno *aluno);
void relatorio_avaliacao (Avaliacao *av, Lista *l);
void lista_avaliacoes (Lista_Avs *l_avs, Lista *l);

// Funções de Ordenação;
Notas* particiona(Notas *inicio, Notas *fim);
void QuickSort(Notas *inicio, Notas *fim);
int particiona_mat(Aluno **tabela_hash, int beg, int end);
void quicksort_mat(Aluno **tabela_hash, int beg, int end);
int particiona_nome (Aluno **tabela_hash, int beg, int end);
void quicksort_nome (Aluno **tabela_hash, int beg, int end);
int particiona_somatorio (Aluno **tabela_hash, int beg, int end);
void quicksort_somatorio(Aluno **tabela_hash, int beg, int end);
int particiona_falta(Aluno **tabela_hash, int beg, int end);
void quicksort_falta(Aluno **tabela_hash, int beg, int end);
void troca_notas (Notas *a, Notas *b);
void troca_posicao (Aluno **tabela_hash, int k, int l);
void printa_lista_ordenada (Lista_notas* l);
void ordenaNotasAvaliacao(Lista *l, int cod_avaliacao);

//Outras Funções;
void cadastra_aluno(Lista *l, Lista_Avs *l_avs, Aluno **tabela_hash);
void relatorio_alunos (Aluno **tabela_hash, Lista *l);
void chamada (Lista *l);
Lista_notas* cria_lista_notas ();
void insere_nota(Lista_notas* l, Notas *av_aluno);


int global_numero_alunos = 0;


int main(){
    Aluno* TabelaHash [TAM] = {NULL};                             //A tabela possuirá endereços do tipo Aluno. Será uma tabela que aponta para onde o aluno está na memória;
    Lista *l = crialista();
    Lista_Avs *l_avs = crialista_avs();
    int menu = 1;

    while(menu != 0){
        printf("Digite um numero para:\n\t1 - Cadastrar um aluno;\n\t2 - Cadastrar uma avaliacao;\n\t3 - Realizar chamada;\n\t4 - Solicitar relatorio dos alunos;\n\t5 - Soliciar relatorio de uma avaliacao;\n\t0 - Sair;\n");       //Menu;
        scanf("%d", &menu);
        getchar();

        switch (menu){
        case 0:
            return 0;
        case 1:
            cadastra_aluno(l, l_avs, TabelaHash);
            break;
        case 2:
            cadastra_avaliacao(l, l_avs);
            break;
        case 3:
            chamada(l);
            break;
        case 4:
            relatorio_alunos(TabelaHash, l);
            break;
        case 5:
            lista_avaliacoes(l_avs, l);
            break;
        default:
            printf("Selecao invalida! Tente novamente.\n\n");
        }
    }
}

unsigned int funcao_hash(int chave, int tamanho_tabela) {           //Método da Multiplicação do livro "Algoritmos - Teoria e Prática";
    const double A = 0.6180339887;                                  //Constante que é o inverso da proporção áurea;
    double valor = chave * A;
    valor = valor - (int)valor;                                     //Parte fracionária;
    return (unsigned int)(tamanho_tabela * valor);
}
void insere_hash (Aluno *aluno, Aluno **tabela_hash){               //Função para inserir aluno na TabelaHash;
    int indice = funcao_hash(aluno->matricula, TAM);                //Chama "funcao_hash" para determinar o índice de qual posição o aluno ficará na tabela;
    if(tabela_hash[indice] == NULL)                                 //Se a posição estiver vazia, insere o aluno nessa posição;
        tabela_hash[indice] = aluno;
    else{
        printf("Colisao na Tabela Hash detectada! Matricula do aluno '%s' alterada para %d\n", aluno->nome, ++aluno->matricula);
        insere_hash(aluno, tabela_hash);                            //Incrementa a matricula do aluno para evitar colisão na tabela e chama a função novamente;
    }
}
void imprime_hash (Aluno **tabela_hash){
    printf("\n----------Inicio da Tabela Hash----------\n\n");
    for (int i = 0; i < TAM; i++){
        if (tabela_hash[i] != NULL){  // Verifica se a posição não é NULL
            printf("Indice %d: Matricula do aluno: %d\n", i, tabela_hash[i]->matricula);
        }
    }
    printf("\n-----------------------------------------\n");
}


Lista* crialista (){
    Lista *nova = (Lista*) malloc(sizeof(Lista));
    nova->alunos = NULL;
    return nova;
}
Lista_Avs* crialista_avs (){
    Lista_Avs *nova = (Lista_Avs*) malloc(sizeof(Lista_Avs));
    nova->avaliacoes = NULL;
    return nova;
}
void printalista (Lista *l){
    Aluno *novo = l->alunos;
    printf("\n\n----------Inicio da listagem----------\n\n");
    while (novo != NULL){
        printf("Matricula: %d\n", novo->matricula);
        printf("Nome: %s\n", novo->nome);
        printf("Curso: %s\n", novo->curso);
        printf("Total de faltas: %d\n\n", novo->faltas);
        novo = novo->prox;
    }
    printf("--------------------------------------\n\n");
}
void printalista_avs (Lista_Avs *l){
    Avaliacao *novo = l->avaliacoes;
    printf("\n\n----------Inicio da listagem de avaliacoes----------\n\n");
    while (novo != NULL){
        printf("Codigo da avaliacao: %d\n", novo->cod_avaliacao);
        printf("Nome da avaliacao: %s\n", novo->nome_avaliacao);
        printf("Curso da avaliacao: %d\n", novo->disciplina);
        printf("Valor da avaliacao: %.2f\n", novo->valor_avaliacao);
        novo = novo->prox;
        printf("\n");
    }
    printf("----------------------------------------------------\n\n");
}


void chamada (Lista *l){
    Aluno *nova = l->alunos;
    if(nova == NULL){
        printf("Nao ha alunos para realizar a chamada!\n\n");
        return;
    }

    char aux;
    while (nova != NULL){
        printf("Aluno %s - Digite 'P' para Presente || 'A' para Ausente: ", nova->nome);
        scanf(" %c", &aux);         //O espaço antes de %c é para ignorar espaços em branco, caso ainda estejam no buffer na memória;
        switch (aux) {
            case 'P':
            case 'p':
                break;
            case 'a':
            case 'A':
                nova->faltas++;         //Incrementa o número de faltas;
                if (nova->faltas >= 10)
                    printf("----O(a) Aluno(a) %s foi reprovado(a) por faltas!----\n\n", nova->nome);
                break;
            default:
                printf("\nCaracter invalido! Tente novamente.\n");
        }
        nova = nova->prox;      //Passa para o próximo aluno;
    }
}


int checa_av_igual (Lista_Avs *l_avs, Avaliacao *av){
    Avaliacao *aux = l_avs->avaliacoes;
    while(aux != NULL){
        if(av->cod_avaliacao == aux->cod_avaliacao){
            printf("\nEsse codigo de avaliacao ja esta em uso! Insercao terminda.\nPor favor, re-insira a avaliacao novamente com um codigo que nao esteja em uso.\n\n");
            return -1;
        }
        aux = aux->prox;
    }
    return 1;
}
void cadastra_avaliacao (Lista *l, Lista_Avs *l_avs){
    Avaliacao *av = (Avaliacao *)malloc(sizeof(Avaliacao));         //Aloca memória para a nova avaliação;
    av->nome_avaliacao = (char *)malloc(20);                        //Aloca memória para a string;

    printf("Nome da avaliacao: ");
    fgets(av->nome_avaliacao, 20, stdin);
    av->nome_avaliacao[strcspn(av->nome_avaliacao, "\n")] = '\0';   //Elimina o "troca linha" recebido pela função "fgets" ao apertar ENTER e o substitui por um caracter de fim de string;
                                                                    //Isso é feito para evitar problemas na impressão e evitar um "troca linha" nela;
    printf("Valor da avaliacao: ");
    scanf("%f", &av->valor_avaliacao);
    getchar();                                                      //Consome o "troca linha" que a função "scanf" não lê, mas que fica armazenado no buffer da memória;

    printf("Identificador da avaliacao: ");
    scanf("%d", &av->cod_avaliacao);
    getchar();

    printf("Codigo da disciplina ao qual a avaliacao pertence: ");
    scanf("%d", &av->disciplina);
    getchar();

    if(checa_av_igual(l_avs, av) == -1){                            //Confere se o codigo da avaliação não está em uso. Se estiver, a função "checa-avs" retorna -1 e o processo termina.
        free(av);                                                   //Libera o espaço da memória;
        return;
    }

    //Encadeia as avaliações;
    av->prox = l_avs->avaliacoes;
    l_avs->avaliacoes = av;
    distribui_avaliacao(l_avs->avaliacoes, l);                      //Chama a função "distribui_avalicao" para dar a nota de todos o alunos nela;
    printf("\n");                                                   //É passado como parâmetro a cabeça da lista de avaliações que agora é a nova avaliação, av;
}
void distribui_avaliacao(Avaliacao *av, Lista *l){
    if (l->alunos == NULL){                                        //Se não houver alunos cadastrados, a função termina;
        return;
    }

    printf("\n----Distribuicao de notas----\n");
    Aluno *atual = l->alunos;
    while (atual != NULL){
        if (atual->faltas < 10){                                     //Se o aluno ter mais de dez faltas o sistema ira ignorar ele;
            Notas *nova_nota = (Notas *)malloc(sizeof(Notas));       //Aloca memória para a nota do aluno nessa avaliação;
            nova_nota->cod_avaliacao = av->cod_avaliacao;
            nova_nota->disciplina = av->disciplina;

            printf("Nota do aluno %s: ", atual->nome);
            scanf("%f", &nova_nota->nota_aluno);
            getchar();

            float checagem = checa_nota_av(av, nova_nota->nota_aluno);

            while(checagem == -1){                          //Caso a nota fornecida para o aluno seja acima do valor da avaliacao, esse loop não permitirá a funçao seguir;
                printf("\nNota invalida! Nota maior que o valor da avaliacao.\nTente novamente com um valor apropriado como nota para essa avaliacao.\n\n");
                printf("Nota do aluno %s: ", atual->nome);
                scanf("%f", &nova_nota->nota_aluno);
                getchar();
                checagem = checa_nota_av(av, nova_nota->nota_aluno);
            }

            nova_nota->prox = atual->notas;
            atual->notas = nova_nota;
            atual->somatorio_notas += nova_nota->nota_aluno;
        }
        atual = atual->prox;
    }
    printf("-----------------------------\n\n");
}

int checa_nota_av (Avaliacao *av, float nota){
    if(nota > av->valor_avaliacao){
        return -1;
    }
    return 1;
}

void cadastra_aluno(Lista *l, Lista_Avs *l_avs, Aluno **tabela_hash){
    Aluno *novo_aluno = (Aluno *)malloc(sizeof(Aluno));
    novo_aluno->nome = (char *)malloc(50);      //Aloca memória para o nome
    novo_aluno->curso = (char *)malloc(20);     //Aloca memória para o curso

    printf("\nMatricula do aluno: ");
    scanf("%d", &novo_aluno->matricula);
    getchar();

    printf("Nome do aluno: ");
    fgets(novo_aluno->nome, 50, stdin);
    novo_aluno->nome[strcspn(novo_aluno->nome, "\n")] = '\0';

    printf("Curso do aluno: ");
    fgets(novo_aluno->curso, 20, stdin);
    novo_aluno->curso[strcspn(novo_aluno->curso, "\n")] = '\0';

    printf("Data de entrada no curso do aluno: ");
    scanf("%d", &novo_aluno->data_curso);
    getchar();

    printf("Total de faltas do aluno: ");
    scanf("%d", &novo_aluno->faltas);
    getchar();

    novo_aluno->somatorio_notas = 0;
    novo_aluno->notas = NULL;

    novo_aluno->prox = l->alunos;
    l->alunos = novo_aluno;

    insere_hash(novo_aluno, tabela_hash);       //Insere aluno na TabelaHash;
    checa_avs(l_avs->avaliacoes, novo_aluno);   //Chama a função "checa_avs" para checar se já existem avaliações e, se tiver, dar a nota do aluno nelas;
    global_numero_alunos++;
    printf("\n");
}
void checa_avs(Avaliacao *teste, Aluno *aluno){
    if (teste == NULL) return;              //Se não houver avaliações a função termina;

    float aux;
    printf("\nAvaliacao encontrada!\nDigite a nota desse aluno na avaliacao: %d - %s, valor: %.2f - ", teste->cod_avaliacao, teste->nome_avaliacao, teste->valor_avaliacao);
    scanf("%f", &aux);
    getchar();

    float checagem = checa_nota_av(teste, aux);

    while(checagem == -1){                          //Caso a nota fornecida para o aluno seja acima do valor da avaliacao, esse loop não permitirá a funçao seguir;
        printf("\nNota invalida! Nota maior que o valor da avaliacao.\nTente novamente com um valor apropriado como nota para essa avaliacao.\n");
        printf("\nDigite a nota desse aluno na avaliacao: %d - %s, valor: %.2f - ", teste->cod_avaliacao, teste->nome_avaliacao, teste->valor_avaliacao);
        scanf("%f", &aux);
        getchar();
        checagem = checa_nota_av(teste, aux);
    }

    Notas *nova_nota = (Notas *)malloc(sizeof(Notas));    //Aloca memória para a nova nota;
    nova_nota->cod_avaliacao = teste->cod_avaliacao;
    nova_nota->disciplina = teste->disciplina;
    nova_nota->nota_aluno = aux;
    aluno->somatorio_notas += aux;
    //Encadeia as notas do aluno;
    nova_nota->prox = aluno->notas;
    aluno->notas = nova_nota;

    checa_avs(teste->prox, aluno);                        //Chama a função novamente, mas agora com a próxima avaliação;
}

void lista_avaliacoes (Lista_Avs *l_avs, Lista *l){
    Avaliacao *av = l_avs->avaliacoes;
    int cod_av;

    if(l_avs == NULL || l_avs->avaliacoes == NULL){
        printf("Nao ha avaliacoes!\n\n");
        return;
    }

    printf("Escolha uma das avaliacoes informando seu codigo:\n");
    while(av != NULL){
        printf("\tCodigo: %d - Nome: %s\n", av->cod_avaliacao, av->nome_avaliacao);
        av = av->prox;
    }
    scanf("%d", &cod_av);
    getchar();

    av = l_avs->avaliacoes;

    while(av != NULL){
        if(av->cod_avaliacao == cod_av){
            relatorio_avaliacao(av, l);
            return;
        }
        av = av->prox;
    }
    printf("Avaliacao com codigo %d nao foi encontrada!\n\n", cod_av);
}
void relatorio_avaliacao (Avaliacao *av, Lista *l){             //Deu erro apenas uma vez;
    if (l == NULL || l->alunos == NULL || av == NULL) {
        printf("\nErro: Lista de alunos vazia ou avaliacao inexistente.\n\n");
        return;
    }

    printf("\n----Relatorio da avaliacao: %d - %s ----\n", av->cod_avaliacao, av->nome_avaliacao);
    float max = 0;
    float min = 100;        //Valor alto pois toda nota será menor que 100 ou, na pior das hipóteses, todas as notas serão 100;
    float soma_notas = 0;
    int num_provas = 0;

    Aluno *atual = l->alunos;
    Notas *av_aluno;

    while(atual != NULL){               //Enquanto houver um aluno, passaremos por cada avaliação dele até indentificar a avaliação que se quer;
        av_aluno = atual->notas;        //av_aluno é uma avaliação da lista de avaliações de um aluno;
        while(av_aluno != NULL){
            if(av_aluno->cod_avaliacao == av->cod_avaliacao){
                soma_notas = soma_notas + av_aluno->nota_aluno;
                num_provas++;
                if(av_aluno->nota_aluno < min)
                    min = av_aluno->nota_aluno;     //Altera nota mínima;
                if(av_aluno->nota_aluno > max)
                    max = av_aluno->nota_aluno;     //Altera nota máxima;
                break;                              //Se já identificamos a avaliação que se pede, já podemos sair do loop para encontrar a avaliação;
            }else av_aluno = av_aluno->prox;        //Se ainda não a encontramos, passamos para a próxima avalição do aluno;
        }
        if(av_aluno == NULL)
            printf("O aluno %s de matricula %d nao fez essa avaliacao!\n", atual->nome, atual->matricula);
        atual = atual->prox;        //Ao fim da busca pela avaliação desejada, passamos para o próximo aluno;
    }

    printf("Nota Maxima: %.2f\nNota Minima: %.2f\nMedia das notas: %.2f\n\n", max, min, (soma_notas/num_provas));
    ordenaNotasAvaliacao(l, av->cod_avaliacao);         //Chama a função "ordenaNotasAvaliacao" para ordenar as notas de forma decrescente;
    printf("--------------------------------------\n\n");
}
void ordenaNotasAvaliacao(Lista *l, int cod_avaliacao){
    if (l == NULL || l->alunos == NULL) return;         //Se não houver nenhum aluno cadastrado, não há nada para ordenar. A função termina;

    Lista_notas *l_notas = cria_lista_notas();
    Aluno *atual = l->alunos;

    //Encontrar todas as notas para a avaliação específica;
    while (atual != NULL){
        Notas *av_aluno = atual->notas;
        while (av_aluno != NULL){
            if (av_aluno->cod_avaliacao == cod_avaliacao){
                Notas *nova_nota = (Notas *)malloc(sizeof(Notas));
                *nova_nota = *av_aluno;                 //Copiar dados da nota;
                nova_nota->prox = l_notas->notas;
                l_notas->notas = nova_nota;
            }
            av_aluno = av_aluno->prox;                  //Se a avaliação atual não for a procurada, passamos para a próxima;
        }
        atual = atual->prox;                            //Passamos para o próximo aluno;
    }

    //Ordenar usando QuickSort;
    Notas *inicio = l_notas->notas;                 //Marca quem é o inicio;
    Notas *fim = inicio;
    while (fim != NULL && fim->prox != NULL){       //Para conseguir marcar quem é o final;
        fim = fim->prox;
    }

    if (inicio != NULL && fim != NULL){
        QuickSort(inicio, fim);                     //Chama o QuickSort para começar a ordenação;
    }

    printa_lista_ordenada(l_notas);

    //Libere a memória da lista de notas após a impressão;
    Notas *temp;
    while (l_notas->notas != NULL) {
        temp = l_notas->notas;
        l_notas->notas = l_notas->notas->prox;
        free(temp);
    }
    free(l_notas);
}

void printa_lista_ordenada (Lista_notas* l){
    int i = 1;
    Notas *atual = l->notas;
    printf("Notas Gerais:\n");
    while (atual != NULL) {
        printf("Nota %d: %.2f\n",i++, atual->nota_aluno);
        atual = atual->prox;
    }
}
void insere_nota(Lista_notas* l, Notas *av_aluno){
    av_aluno->prox = l->notas;
    l->notas = av_aluno;
}
Lista_notas* cria_lista_notas (){
    Lista_notas *nova = (Lista_notas*) malloc(sizeof(Lista_notas));
    nova->notas = NULL;
    return nova;
}

Notas* particiona(Notas *inicio, Notas *fim){
    int pivo = (int) fim->nota_aluno;
    Notas *i = inicio;
    Notas *j = inicio;

    while (j != fim){
        if (j->nota_aluno > pivo){
            troca_notas(i, j);
            i = i->prox;
        }
        j = j->prox;
    }
    troca_notas(i, fim);
    return i;
}
void QuickSort(Notas *inicio, Notas *fim){
    if (inicio != NULL && fim != NULL && inicio != fim && inicio != fim->prox){
        Notas *pivo = particiona(inicio, fim);
        if (pivo != NULL){
            if (inicio != pivo){
                QuickSort(inicio, pivo->prox);
            }
            if (pivo->prox != NULL){
                QuickSort(pivo->prox, fim);
            }
        }
    }
}
void troca_notas (Notas *a, Notas *b){
    float tempNota = a->nota_aluno;
    int tempDisciplina = a->disciplina;
    int tempCodAvaliacao = a->cod_avaliacao;

    a->nota_aluno = b->nota_aluno;
    a->disciplina = b->disciplina;
    a->cod_avaliacao = b->cod_avaliacao;

    b->nota_aluno = tempNota;
    b->disciplina = tempDisciplina;
    b->cod_avaliacao = tempCodAvaliacao;
}

void selectionsort (Aluno **tabela_hash, int t){
    int menor;
	for(int i=0; i<t-1; i++)
	{
	    menor = i;

		for(int j=(i+1); j<=t; j++)
		{
			if(tabela_hash[j]->matricula<tabela_hash[menor]->matricula)
			    menor=j;
		}
		troca_posicao(tabela_hash, i, menor);
	}
}

void troca_posicao(Aluno **tabela_hash, int k, int l) {
    if (k < 0 || l < 0 || k >= global_numero_alunos || l >= global_numero_alunos) {
        printf("Indices fora dos limites!\n");
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

int particiona_somatorio(Aluno **tabela_hash, int beg, int end) {       //Deu erro apenas 1 vez;

    float pivo = ((tabela_hash[end]->somatorio_notas) + (tabela_hash[beg]->somatorio_notas) + (tabela_hash[(end+beg)/2]->somatorio_notas)) / 3;

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

void relatorio_alunos (Aluno **tabela_hash, Lista *l){

    if(l->alunos == NULL){
        printf("Nao ha alunos para se obter um relatorio!\n\n");
        return;
    }

    printf("\n\nDigite um numero para organizar o relatorio por:\n\t1 - Matricula\n\t2 - Nome\n\t3 - Somatorio das notas\n\t4 - Numero de faltas\n");       //Menu;

    int aux;
    scanf("%d", &aux);
    getchar();

    Aluno *tabela_aux [global_numero_alunos];      //Tabela auxiliar com tamanho do número de alunos;
    int j = 0;
    switch (aux){
        case 1:
            for(int i=0; i<TAM; i++){
                    if(tabela_hash[i] != NULL){             //Passamos os parâmetros da TabelaHash principal para a auxiliar. Mas apenas se a TabelaHash tiver algo;
                        tabela_aux[j++] = tabela_hash[i];
                        //printf("Matricula: %d\n", tabela_aux[j++]->matricula);
                    }
                }
            quicksort_mat(tabela_aux, 0, global_numero_alunos-1);                //Chamamos um quicksort para o tipo de organização desejada;
            imprime_hashe_v2(tabela_aux, 1);
            break;
        case 2:
            for(int i=0; i<TAM; i++){
                    if(tabela_hash[i] != NULL){
                        tabela_aux[j++] = tabela_hash[i];
                    }
                }
            quicksort_nome(tabela_aux, 0, global_numero_alunos-1);
            imprime_hashe_v2(tabela_aux, 2);
            break;
        case 3:
                for(int i=0; i<TAM; i++){
                    if(tabela_hash[i] != NULL){
                        tabela_aux[j++] = tabela_hash[i];
                        //printf("Somatorio: %d\n", tabela_aux[j++]->somatorio_notas);
                    }
                }
            quicksort_somatorio (tabela_aux, 0, global_numero_alunos-1);
            imprime_hashe_v2(tabela_aux, 3);
            break;
        case 4:
            for(int i=0; i<TAM; i++){
                    if(tabela_hash[i] != NULL){
                        tabela_aux[j++] = tabela_hash[i];
                        //printf("Numero de faltas: %d\n", tabela_aux[j++]->faltas);
                    }
                }
            quicksort_falta(tabela_aux, 0, global_numero_alunos-1);
            imprime_hashe_v2(tabela_aux, 4);
            break;
        default:
            printf("Selecao invalida! Tente novamente.\n");
    }
}
void imprime_hashe_v2 (Aluno **tabela_hash, int caso) {        //Aqui recebemos a tabela e o número do caso. Desse modo, sabemos em qual ordem fazer a impressão;
    printf("\n\n----------Inicio da Tabela Hash----------\n\n");
    if(caso == 1){
        for (int i=0; i<global_numero_alunos; i++) {
            if (tabela_hash[i] != NULL) {  //Verifica se a posição não é NULL;
                printf("Matricula: %d\t| Somatorio das notas: %.2f\t| Total de faltas: %d\t| Nome: %s\n", tabela_hash[i]->matricula, tabela_hash[i]->somatorio_notas, tabela_hash[i]->faltas, tabela_hash[i]->nome);
            }
        }
    }
    if(caso == 2){
        for (int i=0; i<global_numero_alunos; i++) {
            if (tabela_hash[i] != NULL) {  //Verifica se a posição não é NULL;
                printf("Nome: %s\t| Matricula: %d\t| Somatorio das notas: %.2f\t| Total de faltas: %d\n", tabela_hash[i]->nome, tabela_hash[i]->matricula, tabela_hash[i]->somatorio_notas, tabela_hash[i]->faltas);
            }
        }
    }
    if(caso == 3){
        for (int i=0; i<global_numero_alunos; i++) {
            if (tabela_hash[i] != NULL) {  //Verifica se a posição não é NULL;
                printf("Somatorio das notas: %.2f\t| Matricula: %d\t| Total de faltas: %d\t| Nome: %s\n", tabela_hash[i]->somatorio_notas, tabela_hash[i]->matricula, tabela_hash[i]->faltas, tabela_hash[i]->nome);
            }
        }
    }
    if(caso == 4){
        for (int i=0; i<global_numero_alunos; i++) {
            if (tabela_hash[i] != NULL) {  //Verifica se a posição não é NULL;
                printf("Numero de faltas: %d\t| Matricula: %d\t| Somatorio das notas: %.2f\t| Nome: %s\n", tabela_hash[i]->faltas, tabela_hash[i]->matricula, tabela_hash[i]->somatorio_notas, tabela_hash[i]->nome);
            }
        }
    }
    printf("\n-----------------------------------------\n");
}
