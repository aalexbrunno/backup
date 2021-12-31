#ifndef _EX14_H
#define _EX14_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> //Standard I/O functions
#include <stdlib.h> // Miscellaneous functions (rand, malloc, srand)
#include <getopt.h> // get options from system argc/argv
#include <string.h> // Strings functions definitions
#include <allegro.h> // A game library for graphics, sounds, etc.

#ifndef VERSION
#define VERSION "20210512.104607" /**< Version Number */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
#include <assert.h> /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */

/* allegro */
#define CORBRANCO (makecol(255,255,255))
#define CORPRETO 1
#define CORCINZA (makecol(160,160,160))
#define CORAZUL (makecol(0, 0, 255))
#define CORVERDE (makecol(0, 255, 0))
#define CORAMARELO (makecol(255,255,100))
#define CORVERMELHO (makecol(255, 0, 0))

#define IMAGENAME "nome-generico.bmp" /* nome do arquivo de imagem */
#define IMAGENAME_EX1 "ER-AFND-01.bmp" /* nome do arquivo de imagem */
#define IMAGENAME_EX2 "ER-AFND-02.bmp" /* nome do arquivo de imagem */
#define IMAGENAME_EX3 "ER-AFND-03.bmp" /* nome do arquivo de imagem */

#define TAM_CIRC 12
#define INIT_POS_X 35
#define INIT_POS_Y_1 60
#define INIT_POS_Y_2 120
#define INIT_POS_Y_3 180
#define INIT_POS_Y_4 220


/* ---------------------------------------------------------------------- */
/* globals */

static int verb=0; /**< verbose level, global within the file */


typedef struct st_lef
{
    unsigned short int f; // num estado final
    struct st_lef *prox;  // prox nodo
} t_lef;

typedef struct t_delta
{
    unsigned short int ei;  // Estado inicial.
    char *le;               // Leitura.
    unsigned short int ef;  // Estado final.
    struct t_delta *prox;
} t_delta;

typedef struct st_quintupla
{
    unsigned short int K;   // numero de estados K=3 -> estados q0, q1 e q2
    char A;                 // ultima letra do alfabeto A=b -> {a,b}
    unsigned short int S;   // estado inicial
    //t_lef *F;               // lista de estados finais
    t_delta *D;             // lista da funcao de transicao d(ei, le, ef)
}t_quintupla;

t_lef *F = NULL;

t_quintupla alfabeto;
t_quintupla conj_est;

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void exN_init(void); /* global initialization function */
void exN_update(void); /**< Updates values during program cycle */
int funcexample(int i, int *o, int *z); /* just an example with complete doxygen fields */
void le_arquivo(FILE *exp_reg);
void divide_expressao(t_delta conteudo1);
t_quintupla *gerar_quintupla(void);
void conversao_er_afnd(char linha[SBUFF], t_quintupla *novo_afnd, unsigned short int *est);
void organiza_listas(t_delta **cabeca, unsigned short int i, char a, unsigned short int f);
void montar_estrela(t_quintupla *quint, char c, unsigned short int *est);
void montar_loop(t_quintupla *quint, unsigned short int inicio, unsigned short int fim);
void delta_er(t_delta *cabeca);
void estados_finais(t_lef **cabeca, int x);
void inserir_ef(t_lef **cabeca, int x);
void imprimir_ef();
int buscar_ef(t_lef *cabeca, int x); // ========== NOVA ADIÇÂO ==========

void entradaF(char *a);
void entradaN();

int ex1_allegro(void);
int ex2_allegro(void);
int ex3_allegro(void);

t_quintupla entrada(void); /* recebe os dados da quintupla do AFD */
#endif /* NOT def _EX14_H */
