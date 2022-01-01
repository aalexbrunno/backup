/***************************************************************************
 *   automax.h                             Version 20210512.104607         *
 *   AFND, AFD and ER                                                      *
 *                                                                         *
 *   Converte de tudo: AFD, AFND e ER                                      *
 *   Copyright (C) 2016-2021         by Ruben Carlo Benante                *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: www.beco.cc                                                  *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * \file automax.h
 * \ingroup GroupUnique
 * \brief Converte AFD, AFND e ER
 * \details This program really do a nice job as a template, and template only!
 * \version 20160618.013412
 * \date 2016-06-18
 * \author Ruben Carlo Benante <<rcb@beco.cc>>
 * \par Webpage
 * <<a href="www.beco.cc">www.beco.cc</a>>
 * \copyright (c) 2016 GNU GPL v2
 * \note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * \todo Now that you have the template, hands on! Programme!
 * \warning Be carefull not to lose your mind in small things.
 * \bug This file right now does nothing usefull
 *
 */

#ifndef _AUTOMAX_H
#define _AUTOMAX_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <allegro.h> /* A game library for graphics, sounds, etc. */

/* #include <malloc.h> */ /* Dynamic memory allocation */
#include <time.h> /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
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

#define IMAGENAMEAFD01 "AFD-01.bmp" /* nome do arquivo de imagem */
#define IMAGENAMEAFND01 "AFND-01.bmp" /* nome do arquivo de imagem */
#define IMAGENAMEAFD02 "AFD-02.bmp" /* nome do arquivo de imagem */
#define IMAGENAMEAFND02 "AFND-02.bmp" /* nome do arquivo de imagem */
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
#define INIT_POS_Y_4 220


/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

/* tipo lista encadeada simples dos estados finais */
typedef struct st_lef
{
    unsigned short int f; /* num estado final */
    struct st_lef *prox;  /* prox nodo */
} t_lef;

/* tipo lista encadeada simples de listas de estados finais */
typedef struct st_list_lef
{
    unsigned short int ord;     /* orden do novo estado */ 
    t_lef *F;                   /* lista estados */
    struct st_list_lef *prox;   /* prox nodo */
} t_list_lef;

/* tipo lista encadeada simples da funcao de transicao delta */
typedef struct st_delta
{
    unsigned short int ei;  /* estado inicial */
    char *le;               /* string com rotulos dos arcos */
    unsigned short int ef;  /* estado destino final */
    struct st_delta *prox;  /* prox nodo */
} t_delta;

/* tipo quintupla: representacao formal de um automato */
typedef struct st_quintupla
{
    unsigned short int K;   /* numero de estados K=3 -> estados q0, q1 e q2 */
    char A;                 /* ultima letra do alfabeto A=b -> {a,b} */
    unsigned short int S;   /* estado inicial */
    t_lef *F;               /* lista de estados finais */
    t_delta *D;             /* lista da funcao de transicao d(ei, le, ef) */
} t_quintupla;

t_lef *F = NULL;

t_quintupla alfabeto;
t_quintupla conj_est;

/* ---------------------------------------------------------------------- */
/* prototypes */

/* AFND -> AFD */

void help(void); /**< Prints help information and exit */
void copyr(void); /**< Prints copyright information and exit */
void entrada_dados(FILE *f); /**< aplica manualmente informacoes sobre a entrada afnd dada manualmente */
void recebe_afnd(FILE *file, t_quintupla **cabeca); /**< Recebe o AFnD de um dado arquivo */
void m_recebe_afnd(t_quintupla **cabeca); /**< Recebe o AFnD de forma manual */
void print_quintupla(t_quintupla *q); /**< imprime na tela os valores da quintupla de forma organizada na tela principal */
t_lef *calcular_estado_f(t_quintupla *q, unsigned short int num ,char *test); /**< Dado uma quintupla um estado inicial e o teste retorna seus destinos */
t_lef *calcular_novos_finais(t_quintupla *q, t_list_lef *base); /**< calcula quais sao os novos finais dentro dos novos estados criados */
t_lef *calcular_estado(t_quintupla *q, t_lef *ei ,char *test); /**< dado uma lista de estados calcula sua lista de destino */
t_lef *calcula_epsilon(t_quintupla *q, unsigned short int num); /**< calcula estado destino se tiver transicao em epsilon */
t_lef *calcula_est_inic(t_quintupla *q, unsigned short int num); /**< Calcula uma lista de todos os estados encontrados com a transicao E */
t_delta *novo_delta(t_quintupla *q, t_list_lef *list); /**< calcula uma nova lista delta com uma nova lista de estados */
t_list_lef *calcular_list_lef(t_quintupla *q, t_lef *list); /**< calcula uma *lista* de lista de estados */
t_quintupla *montar_afd(t_quintupla *q, t_delta *delta, t_list_lef *list, t_lef *ef); /**< recebe as listas quintupla AFnD, novo delta e novo final e monta a nova quintupla AFD*/
t_quintupla *calcular_afd(t_quintupla *q); /**< recebe as listas quintupla AFnD, novo delta e novo final e monta a nova quintupla AFD*/
int ord_novo(t_list_lef *list, t_lef *lef); /**< confere em qual ordem esta o estado na lista dos novos estados */
int delta_existe(t_quintupla *q, unsigned short int num ,char *test); /**< confere na lista delta se a transicao existe */
int buscar(t_lef *est , t_lef *est2); /**< confere se duas listas t_lef tem os mesmo valores */
int buscar_f(t_lef *est, unsigned short int num); /**< confere se um numero existe em um t_lef */
int buscar_list(t_lef *est, t_list_lef *est2); /*< confere se existe uma lista t_lef numa lista t_list_lef */
void juntar_lef_list(t_list_lef *est, t_list_lef **est2); /*< junta duas listas t_list_lef */
void remover_list_final(t_lef *est , t_list_lef **cabeca); /*< remove um t_lef de uma t_list_lef */
void inserir_list_final(t_lef *est , t_list_lef **cabeca); /*< inserir um t_lef de uma t_list_lef */
void inserir_final(int num, t_lef **cabeca); /**< Insere um numero em uma t_lef */
void inserir_delta(int EI, char *LE, int EF, t_delta **cabeca); /**< insere um novo nodo a uma t_delta */
void inserir_final_st(char *palavra, t_quintupla **cabeca); /**< Recebe uma string (linha do file) e passa para lista t_lef da quintupla */
void inserir_delta_st(char *palavra, t_quintupla **cabeca);  /**< Recebe uma string (linha do file) e passa para lista t_delta  da quintupla*/
void imagemAFD_01(void); /* imprime representacao do AFD entrada 01 apos haver a conversao, quando entrado com arquivo */
void imagemAFND_01(void); /* imprime representacao do AFND entrada 01, quando entrado com arquivo */

/*------------------------------------------------------------------------*/
/* AFD->ER */
//void inserir_final_st(char *palavra, t_quintupla **cabeca); /*  */ // ja tem no afnd->afd
//void inserir_delta_st(char *palavra, t_quintupla **cabeca);        // ja tem no afnd->afd
//void inserir_delta(int EI, char *LE, int EF, t_delta **cabeca);    // ja tem no afnd->afd
void recebe_afd(FILE *file, t_quintupla **cabeca); /* recebe AFD de um arquivo */
void afd2er(t_quintupla *cabeca); /* transforma afd2er */
void remover_lef(int i, t_lef **cabeca); /* remover 1 valor de t_lef */
void remover_delta(int EI, char LE[], int EF, t_delta **cabeca); /* remover 1 lista t_delta */
void inserir_lef(int f, t_lef **cabeca); /* insere 1 valor a t_lef */
void concatena(t_delta *cabeca, int i, t_quintupla *principal, int elimina); /* concatena a */
void eliminaEstados(t_delta *cabeca, int i, t_quintupla *principal); /* elimina o estado final enviado */
void transER(t_delta *cabeca, t_quintupla *quint); /* transformacao final para ER dos arcos que iniciam e finalizam no mesmo estado */

/*------------------------------------------------------------------------*/
/* ER -> AFND */

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
int buscar_ef(t_lef *cabeca, int x);

/*------------------------------------------------------------------------*/
//Allegro

int ex1_allegro(void);

int ex2_allegro(void);

int ex3_allegro(void);

void imagemAFD_02(void); /* imprime representacao do AFD da entrada 02 apos haver a conversao, quando entrado com arquivo */

void imagemAFND_02(void); /* imprime representacao do AFND da entrada 02, quando entrado com arquivo */

#endif /* NOT def _AUTOMAX_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */

