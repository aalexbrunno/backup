/***************************************************************************
 *   afd to er                                Version 20171128.121000      *
 *                                                                         *
 *   Library for efd2er, a program that convert AFD into Exp Reg           *
 *   Copyright (C) 2016-2017    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License                *
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
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION
#define VERSION "20171128.121000" /**< Version Number */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */
#define MAX_ALFA 25
#define LIMITE_DEBUG 10

/* ---------------------------------------------------------------------- */
/* globals */

static int verb=0; /**< verbose level, global within the file */

/* tipo lista encadeada simples dos estados finais */
typedef struct st_lef
{
    unsigned short int f;
    struct st_lef *prox;
} t_lef;

/* tipo lista encadeada simples da funcao de transicao */
typedef struct st_lft
{
    unsigned short int ei;
    char *le;
    unsigned short int ef;
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
/* tipo arquivo: recebe as linhas do arquivo txt */
typedef struct st_arquivo
{
    char *linhas;
    struct st_arquivo *prox;
}arquivo_fonte;

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void exN_init(void); /* global initialization function */
int funcexample(int i, int *o, int *z); /* just an example with complete doxygen fields */
t_quintupla entrada(void); /* recebe os dados da quintupla do AFD */
void le_arquivo(char *optarg); /* funcao que recebe dados do arquivo txt */
char *strdup (const char *s); /* funcao utilizada na hora de inserir linhas do arquivo na linked list */ 
void insere_linhas(arquivo_fonte **cabeca, char *x); /* funcao utilizada para inserir linhas na linked list */
void entende_automato(arquivo_fonte *basico); /* le txt e monda automato  */
int retorna_contador_e_alfabeto(char *x,char *tokens2[SBUFF]); /* auxilia na leitura do alfabeto */
void inserir_alfabeto(t_quintupla **cabeca, char x); /* insere alfabeto na linked list */
void insere_S(t_quintupla **cabeca, int x);
void insere_K(t_quintupla **cabeca, int x);
void insere_A(t_quintupla **cabeca, char *x);
int retorna_estados_finais(char *estados_finais[SBUFF],char *pra_separar);
void insere_finais(t_lef **cabeca, int x);
void insere_transicoes(t_lft **cabeca, int x,char *c,int y);
void imprimir_transicoes(t_lft *cabeca);
void roda_as_buscas(t_lft *transicoes,t_lft *auxiliar,t_lef *finais,t_quintupla dados);
int criar_novas_transicoes(t_lft **novas_transicoes,t_quintupla *dados,t_lef *finais);
void cria_transicao_inicial(t_lft **cabeca, int tamanho,int x);
void cria_transicao_final(t_lft **cabeca, int tamanho,int x);
int unicos_estados_sejam_os_dois_novos(t_lft *nova_transicao);
int buscar_tamanho(t_lft *cabeca);
int retorna_o_menor_estado(t_lft *novas_transicoes,t_quintupla novos_estados);
int buscar_quando_ele_eh_final_e_retorna_posicao(int menor_estado,t_lft *novas_transicoes);
int buscar_quando_ele_eh_inicial_e_retorna_posicao(int menor_estado,t_lft *novas_transicoes);
void junta_strings(char **essa_muda_nova,int pos_do_final,int pos_do_inicial,t_lft *novas_transicoes);
void faz_a_nova_transicao(t_lft **cabeca,t_lft *transicoes_antigas,char *caractere,int pos_do_inicial,int pos_do_final);
void elimina_onde_eh_inicial(t_lft **cabeca,int pos_do_final);
void elimina_onde_eh_final(t_lft **cabeca,int pos_do_final);
int o_estado_final_principal_eh_o_msm(t_lft *cabeca,int pos_do_final);
int procura_a_prox_ligacao(t_lft *cabeca,t_lft *transicoes_antigas,int pos_do_final);
void elimina_tudo_desse_estado(t_lft **cabeca,int menor_estado);
int checagem_final_se_tem_transicao_solta(t_lft **cabeca,int menor_estado,int pos_do_final);
int se_esse_ef_esta_como_ei(t_lft *cabeca,int x);
int todos_os_inicias_um_tipo_de_numero(t_lft *cabeca);
void junta_expressao(char **expressao,t_lft *cabeca);
void coloca_kline(t_lft **cabeca,int contador);
void identifica_quem_precisa_kline(t_lft **cabeca);
int todos_os_inicias_2_tipos_sendo_um_o_novo(t_lft *cabeca);
char *strrev(char *str);
void anda_para_colocar_o_OU(t_lft *auxiliar,char *expressao);
