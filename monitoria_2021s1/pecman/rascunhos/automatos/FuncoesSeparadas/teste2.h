/***************************************************************************
 *   ex17.h                                   Version 20181202.205013      *
 *                                                                         *
 *                                                                         *
 *   Copyright (C) 2018         by Iago Gade Gusmao Carrazzoni             *
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
 *   Iago Gade Gusmao Carrazzoni                                           *
 *   Email: iagocarrazzoni@gmail.com                                       *
 *   Webpage: www.upe.br                                                   *
 *   Phone: +55 (81) 99479-0584                                            *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * \file ex17.h
 * \ingroup GroupUnique
 * \brief 
 * \details This program really do a nice job as a template, and template only!
 * \version 20181202.205013
 * \date 2018-12-02
 * \author Iago Gade Gusmao Carrazzoni <<iagocarrazzoni@gmail.com>>
 * \par Webpage
 * <<a href="www.upe.br">www.upe.br</a>>
 * \copyright (c) 2018 GNU GPL v2
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
void pegaEntrada(quint_t *q, FILE *arq);
void converte (quint_t *q, char vet[SBUFF]);
void encurtaEstadoKleene (quint_t *q, int e);
void insereComVetorNaFuncaoDelta (delta_t **d, int ei, char s[SBUFF], int ef);
void montaKleene(char kleene[SBUFF], char vet[SBUFF]);
void montaTransicao (char sei[SBUFF], char sef[SBUFF], char vet[SBUFF]);
delta_t *buscaDelta (delta_t *head, int ei, int ef, char vet[SBUFF]);
void removerDelta(delta_t **head, delta_t *r);
void imprimeFuncaoDelta (delta_t *head);
void imprimeListaDeEstadosFinais (quint_t q);
 void insereNosEstadosFinais (ef_t **p, int f);   
 void insereNaFuncaoDelta (delta_t **d, int ei, char c, int ef);
 void novoElementoDelta (delta_t **d, int ei, char vet[SBUFF], int ef);
int finalDoVetor (char s[SBUFF]);
