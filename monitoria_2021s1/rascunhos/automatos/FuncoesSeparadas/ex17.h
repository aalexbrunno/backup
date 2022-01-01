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




void pegaEntrada(quint_t *q, FILE *arq);
void montar_afnd(FILE *exp_regular);


void insereNosEstadosFinais (ef_t **p, int f);
void insereNaFuncaoDelta(delta_t **d, int ei, char c, int ef);

int finalDoVetor (char s[SBUFF]);

/* ---------------------------------------------------------------------- */
