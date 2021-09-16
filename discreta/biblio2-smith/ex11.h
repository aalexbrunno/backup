/*****************************************************************************
 *   ex11.h                                    Version 20180714.101818        *
 *                                                                           *
 *   Brief description                                                       *
 *   Copyright (C) 2016-2018    by Ruben Carlo Benante                       *
 *****************************************************************************
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License.          *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.               *
 *****************************************************************************
 *   To contact the author, please write to:                                 *
 *   Ruben Carlo Benante                                                     *
 *   Email: rcb@beco.cc                                                      *
 *   Webpage: www.beco.cc                                                    *
 *   Phone: +55 (81) 3184-7555                                               *
 *****************************************************************************/

/* ------------------------------------------------------------------------- */
/**
 * \file ex11.h
 * \ingroup GroupUnique
 * \brief Brief description
 * \details This program really do a nice job as a template, and template only!
 * \version 20160908.182854
 * \date 2016-09-08
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

#ifndef _EXN_H
#define _EXN_H

/* ------------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <ncurses.h> /* Screen handling and optimisation functions */
#include <string.h> /* Strings functions definitions */
#include <form.h>
#include<assert.h>
#include<ctype.h>
#include <time.h>  /* Time and date functions */

#include <assert.h>
#include <form.h>
#include <ctype.h>

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <stddef.h> */ /* Various types and MACROS */

/* ------------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20160908.182854" /**< Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */
#define SGRA 201 /* autor, titulo */ 
#define SMED 101 /* editora, local */
#define SPEQ 5 /* codigo, ano, edicao */
#define SISBN 14 /* isbn */

#define NWIN 12 /* help, add, search, change, del, about */

/* msgstatus */
#define STLINE (LINES-2) /* linha da msg de status */
#define STOK 0
#define STYESNO 1
#define BUFFER_SIZE 1000

/* ------------------------------------------------------------------------- */
/* structs and globals */

typedef struct slivro
{
    /* Código;Autor;Título;Editora;Local;Ano;Edição;ISBN */
    /* 4     ;200  ;200   ;100    ;100  ;4  ;4     ;13   */
    int cod;
    char *autor;
    char *titulo;
    char *editora;
    char *local;
    char *ano;
    char *ed;
    char *isbn;
    char *quant;
    int codClient;
    char *nome;
    char *telefone;
    char *email;
    char *aniversario;
    char *hold;
} livro_t;

typedef struct swins
{
    int menu[NWIN]; /* linha escolhida TODO avaliar necessidade */
    int lmax, cmax; /* lembra se a janela mudou de tamanho */
    int wi; /* indice da janela atual */
    int wo; /* indice da janela anterior */
    WINDOW *w[NWIN];
} wins_t;

typedef struct node{
    char* data;
    struct node *prox;
}list;

typedef struct{
    char *buffer;
}file_entry;

typedef struct formulario{
    FORM *form; 
	FIELD *fields[15];
	FORM *formSearch; 
    FIELD *fieldSearch[2];
    FORM *formRegClient; 
	FIELD *fieldsRegClient[9];
} form_t;

/* ------------------------------------------------------------------------- */
/* prototypes */

void help(void); /**< Prints help information and exit */
void copyr(void); /**< Prints copyright information and exit */
void ex11_init(wins_t *pw);  /**< Initializes some operations before start */
/* imprime na barra de status */
int msgstatus(wins_t win, char *msg, int tipo); 
/* imprime a janela de ajuda */
void phelp(wins_t *pw);
/* finaliza o programa */
void bomb(wins_t win, char *msg, int status, FILE *f);
/* printa cada template de cada janela especifica */
void printTemplate(wins_t *pw);
/* funcao presente no sistema windows que converte tipo inteiro para string*/
char* itoa(int num, char* str, int base);
/* movimenta-se nas opcoes */
void moveInData(wins_t *pw, livro_t *l);
/* imprime os dados na respectiva tela */
void printData(wins_t *pw);
/* funcao que concatena todos os dados do livro antes de ser inserido no banco de dados */
char *concatenate(char *dest, file_entry src, char *buffer);
/* inverte a string recursivamente */
char *strReverse(char *__str);
/* procura os livros atraves do nome inserido */
void search(wins_t *pw, char *str);
/* moveInData para editar */
void searchInData(wins_t *pw);
/* funcao que expoe o conteudo do arquivo */
void show2(wins_t *pw ,char *string);
/* funcao que manipula a quantidade de livros presente no estoque */
char *change_amount(int line,char *number,char ch);
/* funcao que salva a nova quantidade de livros dentro do banco de dados */
void insert_new_amount(int line,char *new_amount);
/* funcao que controla a remocao de livros do banco de dados */
void deleteLine(char *fname);
/* funcao que recebe uma string e retorna a mesma, mas limpa de espacos no comeco de no final */
char* trim(char * str);
/* funcao que imprime o conjunto de formularios para insercao de dados de cadastro de livros */
void printForm(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw);
/* funcao que controla o cursor dentro do campo de formulario */
static void driver(int ch, wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw);
/* funcao que imprime o conjunto de formularios para insercao de dados de emprestimo */
void printFormLoan(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw);
/* funcao que printa a area referente ao cadastro de clientes */
void printFormRegClient(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw);
/* funcao que imprime o conjunto de formularios para o input do numero da linha que deseja ser manipulado */
/* funcao que imprime o campo referente a area de pesquisa */
void printFormSearch(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw);
/* funcao que imprime o campo para escolha de linha para edicao */
void printFormLine(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw);
/* funcao que imprime o conjunto de formularios com os dados ja preenchidos de uma determinada linha */
void printFormLine2(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw, char *string);
/* funcao que manipula as listas dinamicas adicionando elementos */
void add(list **head,char* num);
/* funcao que recebe um numero de uma linha e retorna a mesma */
char* get_line(int line,char *txt);
/* funcao que recebe uma string vinda do field e retorna a mesma, mas limpa de espacos no comeco de no final */
static char*trim_whitespaces(char *str);
/* funcao que expoe o conteudo do arquivo */
void show(wins_t *pw ,char *string);
/* funcao que retorna a quantidade de linhas dentro do banco de dados */
int findFileLine();
/* funcao que imprime o conteudo da lista dinamica */
void print(list *head,wins_t *pw);
/* funcao que checa a existencia de um codigo dentro do banco de dados */
int search_client_cod(int client_cod,char *txt);
/* funcao que atualiza determinada linha do banco de dados com novas informacoes */
void insertLine(char *path, char *str, int line);
/* funcao que pesquisa uma determinada palavra no arquivo e retorna a linha a qual ela pertence */
void search4(wins_t *pw, char *txt, char *str,char *ptr);
/* funcao que cria uma borda ao redor do campo de submissao */
void rectangle(wins_t *pw, int y1, int x1, int y2, int x2);
#endif /* NOT def _EXN_H */

/* ------------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline    */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20180716.101436   */


