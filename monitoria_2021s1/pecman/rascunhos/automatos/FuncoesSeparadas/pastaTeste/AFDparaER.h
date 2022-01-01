#include <stdbool.h>

#ifndef _EX17_H
#define _EX17_H
#endif

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20181202.205013" /**< Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */
#define ZERO_EM_ASCII 48

/* ---------------------------------------------------------------------- */
/* globals */


/* ---------------------------------------------------------------------- */
/* tipo lista encadeada simples dos estados finais */
typedef struct st_lef
{
    unsigned short int f;
    struct st_lef *prox;
} t_lef;

/* tipo lista encadeada simples da funcao de transicao */
typedef struct st_lft
{
    unsigned short int ei;  /* estado inicial */
    char le;               /* le (string com rotulos) */
    unsigned short int ef;  /* estado final */
    struct st_lft *prox;
} t_lft;

/* tipo quintupla: representacao formal de um automato */
typedef struct st_quintupla
{
    unsigned short int K;   /* conjunto de estados */
    char A;                 /* alfabeto */
    unsigned short int S;   /* estado inicial */
    t_lef *F;               /* lista de estados finais */
    t_lft *D;               /* lista da funcao de transicao d(ei, le, ef) */
} t_quintupla;


typedef struct st_ll
{
    unsigned short int fi;
    struct st_ll *prox;
} t_ll;


typedef struct st_lprinc
{
    t_ll *simul;
    struct st_lprinc *prox;
    unsigned short int indice;
} t_lprinc;

/* ---------------------------------------------------------------------- */
/* prototypes */
/* EX11 */
int buscar_indice(t_lprinc  *a, t_ll *b);
void gera_nova_quintupla(t_quintupla q,char *vet_alf);
void imprimir_novos_finais(t_lprinc  *cabeca, t_lef *x);
t_ll *gera_estado(t_lft *deltas,t_ll *estado ,char letra,t_lprinc *simultaneos);
bool ja_faz_parte(t_lprinc *a,t_ll *b);
int tamanho(t_ll *x);
bool compara_listas(t_ll *a,t_ll *b);
t_ll *buscar_principal(t_lprinc  *cabeca, unsigned short int x);
void imprimir_estados(t_lef  *cabeca);
void limpar(t_lft **lista);//Remove todos os nM-CM-3s da Lista
t_ll *buscar(t_ll  *cabeca, unsigned short int x);
t_lprinc *acha_simultaneos(t_lft *cabeca,unsigned short int nes);
void imprimir_delta(t_lft  *cabeca);
void help(void); /**< Prints help information and exit */
void copyr(void); /**< Prints copyright information and exit */
void ex17_init(void);  /**< Initializes some operations before start */
void ex17_update(void); /**< Updates values during program cycle */
void ex11(char *optarg);
void inserir_delta(t_lft **cabeca, char *x);
void inserir_estados_finais(t_lef **cabeca,unsigned short int ini);
void quebra_vetores(char *a, char *vetor);
unsigned short int busca_trans(t_lft *cabeca,unsigned short int qinic,char alfb);
void inserir_na_listinha(t_ll **cabeca, unsigned short int fin);
void inserir_na_principal(t_lprinc **cabeca, unsigned short int fin, t_ll *lista);
/* une todo o conteudo da lista a cabeca sem repetir */
void uniao_simultaneos(t_ll **cabeca, t_ll *lista);
void inserir_outro_delta(t_lft **cabeca, unsigned short int i, char a, unsigned short int f);
void  imprimir_principal(t_lprinc *cabeca);
void  imprimir_listinha(t_ll  *cabeca);
void salva_saida11_no_txt(t_lft *cabeca, char *vet_alf, t_lef *x);

/* ---------------------------------------------------------------------- */
/* EX 12 */ 

typedef struct st_ef
{
    int f;
    struct st_ef *prox;
} ef_t;

typedef struct s_delta
{
    int ei;
    char s[SBUFF];
    int ef;
    struct s_delta *prox;
} delta_t;

typedef struct s_quintupla
{
    int k;
    char a;
    int s0;
    ef_t *f;
    delta_t *d;
} quint_t;

void pegaEntrada (quint_t *q, FILE *arq);
int finalDoVetor (char s[SBUFF]);
void insereNaFuncaoDelta (delta_t **d, int ei, char c, int ef);
void insereNosEstadosFinais (ef_t **p, int f);
void imprimeQuintupla (quint_t q);
void imprimeListaDeEstadosFinais (quint_t q);
void imprimeFuncaoDelta (delta_t *head);
void criaEstadoInicial (quint_t *q);
void criaEstadoFinal (quint_t *q);
void encurtaEstadoE (quint_t *q, int e);
delta_t *buscaDelta (delta_t *head, int ei, int ef, char vet[SBUFF]);
ef_t *busca (ef_t *head, int f);
void removerDelta(delta_t **head, delta_t *r);
void removerFinais(ef_t **head, ef_t *r);
void novoElementoDelta (delta_t **d, int ei, char vet[SBUFF], int ef);
void montaTransicao (char sei[SBUFF], char sef[SBUFF], char vet[SBUFF]);
void insereComVetorNaFuncaoDelta (delta_t **d, int ei, char s[SBUFF], int ef);
delta_t *buscaTransicaoCabecaKleene (delta_t *head, int e);
void montaKleene(char kleene[SBUFF], char vet[SBUFF]);
void montaOU(char trans1[SBUFF], char trans2[SBUFF], char vet[SBUFF]);
void montaTransicaoKleene(delta_t *d, char kleene[SBUFF], char vet[SBUFF]);
void encurtaEstadoKleene (quint_t *q, int e);
void encurtaEstadoOU (quint_t *q, int e);
void encurtaEstado (quint_t *q, int e);
int contaNodoDelta (delta_t *d);
void novo (quint_t *q, int e);
void finalE (quint_t *q, int e);
void converte (quint_t *q, char vet[SBUFF]);
/* ---------------------------------------------------------------------- */
/* EX 16 */

typedef struct st_lft1
{
    unsigned short int ei;  /* estado inicial */
    char *le;               /* le (string com rotulos) */
    unsigned short int ef;  /* estado final */
    struct st_lft1 *prox;
} t_lft1;

typedef struct st_lef1
{
    unsigned short int f;
    struct st_lef1 *prox;
}t_lef1;

/* tipo quintupla: representacao formal de um automato */
typedef struct st_quintupla1
{
    unsigned short int K;  /* conjunto de estados */   
    char A;                /* albeto*/ 
    unsigned short int S;  /*estado inicial*/
    t_lef1 *F;             /* lista de estados finais */
    t_lft1 *D;             /* lista da funcao de transicao d(ei, le, ef) */
} t_quintupla1;

/* tipo lista encadeada simples da funcao de transicao */

/* Tipo lista encadeada simples dos estados finais */

void separar_er(t_lft1 er_comp);
t_quintupla1 *criar_quint(void);
void montar_loop(t_quintupla1 *quint, unsigned short int inicio, unsigned short int fim);
void montar_afnd(FILE *exp_regular);
void montar_trans(char linha[SBUFF], t_quintupla1 *novo_afnd, unsigned short int *est);
void montar_estrela(t_quintupla1 *quint, char c, unsigned short int *est);
void inserir_nodo(t_lft1 **cabeca, unsigned short int i, char a, unsigned short int f);
void imprimir_delta1(t_lft1 *cabeca);

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */
