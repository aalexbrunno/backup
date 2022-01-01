/***************************************************************************
 *   auto1.h                               Version 20210512.104607         *
 *   AFND to AFD                                                           *
 *                                                                         *
 *   Converte AFND para AFD                                                *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
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
 * \file auto1.h
 * \ingroup GroupUnique
 * \brief Converte AFND para AFD
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

#ifndef _AUTO1_H
#define _AUTO1_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h>  /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <allegro.h> /* A game library for graphics, sounds, etc. */

/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <time.h> */ /* Time and date functions */
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
#define IMAGENAME "teste.bmp" /* nome do arquivo de imagem */

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

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /**< Prints help information and exit */
void copyr(void); /**< Prints copyright information and exit */
void recebe_afnd(FILE *file, t_quintupla **cabeca); /**< Recebe o AFnD de um dado arquivo */
void print_quintupla(t_quintupla *q); /**< imprime na tela os valores da quintupla de forma organizada na tela principal */
t_lef *calcular_estado_f(t_quintupla *q, unsigned short int num ,char *test); /**< Dado uma quintupla um estado inicial e o teste retorna seus destinos */
t_lef *calcular_novos_finais(t_quintupla *q, t_list_lef *list); /**< calcula quais sao os novos finais dentro dos novos estados criados */
t_lef *calcular_estado(t_quintupla *q, t_lef *ei ,char *test); /**< dado uma lista de estados calcula sua lista de destino */
t_lef *calcula_epsilon(t_quintupla *q, unsigned short int num); /**< calcula estado destino se tiver transicao em epsilon */
t_delta *novo_delta(t_quintupla *q, t_list_lef *list); /**< calcula uma nova lista delta com uma nova lista de estados */
t_list_lef *calcular_list_lef(t_quintupla *q, t_lef *list); /**< calcula uma *lista* de lista de estados */
t_quintupla *montar_afd(t_quintupla *q, t_delta *delta, t_list_lef *list, t_lef *ef); /**< recebe as listas quintupla AFnD, novo delta e novo final e monta a nova quintupla AFD*/
t_quintupla *calcular_afd(t_quintupla *q); /**< recebe as listas quintupla AFnD, novo delta e novo final e monta a nova quintupla AFD*/
int ord_novo(t_list_lef *list, t_lef *lef); /**< confere em qual ordem esta o estado na lista dos novos estados */
int delta_existe(t_quintupla *q, unsigned short int num ,char *test); /**< confere na lista delta se a transicao existe */
int buscar(t_lef *est , t_lef *est2); /**< confere se duas listas t_lef tem os mesmo valores */
int buscar_list(t_lef *est, t_list_lef *est2); /*< confere se existe uma lista t_lef numa lista t_list_lef */
void juntar_lef_list(t_list_lef *est, t_list_lef **est2); /*< junta duas listas t_list_lef */
void remover_list_final(t_lef *est , t_list_lef **cabeca); /*< remove um t_lef de uma t_list_lef */
void inserir_list_final(t_lef *est , t_list_lef **cabeca); /*< inserir um t_lef de uma t_list_lef */
void inserir_final(int num, t_lef **cabeca); /**< Insere um numero em uma t_lef */
void inserir_delta(int EI, char *LE, int EF, t_delta **cabeca); /**< insere um novo nodo a uma t_delta */
void inserir_final_st(char *palavra, t_quintupla **cabeca); /**< Recebe uma string (linha do file) e passa para lista t_lef da quintupla */
void inserir_delta_st(char *palavra, t_quintupla **cabeca);  /**< Recebe uma string (linha do file) e passa para lista t_delta  da quintupla*/
void imagemAFD(void);
void imagemAFND(void);

#endif /* NOT def _AUTO1_H */
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */


