#ifndef _EX10_H
#define _EX10_H

/* includes */
#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */

#include <string.h> /* Strings functions definitions */

/* definitions */
#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20160618.013412" /**< Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
#include <assert.h> /* Verify assumptions with assert. Turn off with #define NDEBUG */

/* limits */
#define SBUFF 512 /*< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */
int counter = 0;
int qlabel = 0;
int qmax = 0;
int simpos = 0;
int state = 0;

/* estrutura padrao para autômatos */
struct automato
{
    unsigned short int K; /* conjunto de estados */
    char A; /* conjunto alfabeto */
    unsigned short int S; /* estado inicial */
    struct final *F; /* conjunto de estados finais */
    struct delta *D; /*conjunto de funções */
};

/* estrutura para armazenar valores de equivalencia para o novo estado */
struct estados
{
    unsigned short int label;
    unsigned short int size;
    struct final *L; /* nos aproveitamos da estutura 'final' mas isto nao é uma lista de estados finais. */
    struct estados *prox;
};

/* estrutura para o conjunto 'estados finais' dos autômatos */
struct final
{
    unsigned short int value; /* inteiro representando o número do(s) estado(s) final(is) */
    struct final *prox; /* ponteiro para guiar a lista */
};

/* estrutura para o conjunto 'delta' dos autômatos */
struct delta
{
    unsigned short int Ei; /* inteiro representando o estado inicial desta funçao */
    char Le[SBUFF]; /* char representando uma letra do alfabeto, argumento da funçao */
    unsigned short int Ef; /* inteiro representando o estado final desta funçao */
    struct delta *prox; /* ponteiro para guiar a lista */
};

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /**< Prints help information and exit */
void ex10_init(void);  /**< Initializes some operations before start */
void ex10_update(void); /**< Updates values during program cycle */

void afdtoer(void); /* funçao iniciada pela flag -d para converter um AFD em ER */
void afndtoafd(void); /* funçao iniciada pela flag -n para converter um AFND em AFD */
void checkstring(char entrada[SBUFF]); /* Funçao para conferir se o usuário digitou algum caractere inválido */
void conversaoafder(struct automato *afd); /* converte afd numa expressao regular */
void conversaoerafnd(char entrada[SBUFF]); /* converte expressao regular num afnd */
void defineState(struct delta *afndD); /* Salva numa variável global o valor numérico do maior estado do autômato */
void entradainvalida(void); /* Esta funçao avisa ao usuário que a entrada de dados foi inválida e fecha o programa. */
void ertoafnd(void); /* funçao iniciada pela flag -e para converter uma ER em AFND */
void fileer(char sfile[SBUFF]); /* Funçao que lê um arquivo de entrada que contém uma er */
void printAuto(struct automato *autom); /* Funçao para imprimir um autômato. */

char alfabeto(struct delta *aux); /* Funçao para definir o alfabeto do autômato */

void simplificar(char expressao[SBUFF]); /* Aplica funções "simplificarparenteses" e "simplificarvazios"*/
const char *simplificarparenteses(char expressao[SBUFF]); /* Retira parênteses nao obrigatórios de uma expressao regular */
void simplificarvazios(char expressao[SBUFF]); /* Retira caracteres vazios nao obrigatórios de uma expressao regular */

unsigned short int checksize(struct final *lista); /* Funçao que retorna o tamanho da lista de estados finais */

int fileafd(char sfile[SBUFF]); /* Funçao que lê um arquivo de entrada que contém um afd */
int fileafnd(char sfile[SBUFF]); /* Funçao que lê um arquivo de entrada que contém um afnd */
int checknovoestado(struct estados *temp, struct estados *novosestados);

struct automato *checksizeE(struct automato *afd); /* Funçao que atualiza a quantidade de estados no autômato */
struct automato *conversao(struct automato *afnd);
struct automato *criarQuintupla(char entrada[SBUFF]);
struct automato *criarUnidade(char letra[SBUFF]); /* Funçao para criar uma transiçao entre dois estados ao ler uma letra. */
struct automato *freeAuto(struct automato *quintupla);
struct automato *novosestadosauxiliares(struct automato *afd); /* Cria dois novos estados, um de partida e um de chegada, para auxliar na esclusao dos demais */
struct automato *novosFinais(struct automato *afnd);
struct automato *processoDeEquivalencia(struct automato *afnd);
struct automato *readsuser(void); /* Funçao para ler o entrada do terminal. */
struct automato *removerImpossiveis(struct automato *afnd); /* Funçao que remove do autômato estados impossíveis de se chegar */
struct automato *removerVazios(struct automato *afnd);




 #define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}



struct delta *addStringToD(unsigned short int val1, char le[SBUFF], unsigned short int val2, struct delta *afndD); /* Funçao para construir a lista de conjunto delta de funções dentro da quíntupla, mas com Le sendo do tipo string. */
struct delta *addToD(unsigned short int val1, char le, unsigned short int val2, struct delta *afndD); /* Funçao para construir a lista de conjunto delta de funções. */
struct delta *copiarDelta(struct delta *destino, struct delta *origem);
struct delta *freeD(struct delta *vec);
struct delta *kleene(char er[SBUFF], unsigned short int target, struct delta *afdD); /* Continua a identificar casos de estrela de Kleene e apaga estas transições enquanto copia sua ER às outras transições que passam por este estado excluído */
struct delta *redirecionarDelta(unsigned short int oldEi, unsigned short int oldEf, struct delta *afndD);
struct delta *removeDelta(int pos, struct delta *afndD); /* Funçao para remover a transiçao de número "pos" da lista delta de transições */
struct delta *removeRepeticoes(struct delta *afndD); /* Funçao que elimine transições repetidas da estrutura */
struct delta *substituirDelta(unsigned short int oldEi, char oldLe, unsigned short int novoestado, struct delta *afndD); /* Funçao que substitua todos estados de valor x para um estado de valor y */
struct delta *substituirEf(unsigned short intx, char y[SBUFF], unsigned short int z, struct delta *afdD); /* Quando encontrar uma transiçao "ei le ef" que coincide com o "x" obtido pelo argumento, a funçao copia a transiçao e substitui "le ef" pelos argumentos "y, z" */
struct delta *organizar(struct delta *afndD); /* Funçao que organiza as transições "D" em ordem crescente de estados */

struct estados *freeEstados(struct estados *lista);
struct estados *findlabel(struct estados *lista, unsigned short int x);

struct final *addToF(unsigned short int val1, struct final *afndF); /* Funçao para construir a lista de estados finais. */
struct final *freeF(struct final *vec);
struct final *readsF(char string[SBUFF], struct final *lista); /* Funçao que lê uma linha de valores para lugares finais e transforma em diversos valores */
struct final *removeFinal(unsigned short int oldE, struct final *afndF);

#endif /* NOT def _EX10_H */

