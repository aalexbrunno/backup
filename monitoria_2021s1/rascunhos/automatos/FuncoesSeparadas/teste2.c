/*
 * Instrucoes para compilar:
 *   $gcc ex17.c -o ex17.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1 -DVERSION="0.1.160612.142044"
 *   ou preferencialmente inclua um makefile e use:
 *   $make
 *
 * Modelo de indentacao:
 * Estilo: --style=allman ou -A1
 *
 * Opcoes: -A1 -s4 -k3 -xj -SCNeUpv
 *
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv ex17.c
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include "teste2.h" /* To be created for this template if needed */

/* To include assert.h for diagnostics, do it after #define DEBUG bellow */
/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
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
/* #include <stdint.h> */ /* Integer types and sizes */
/* #include <inttypes.h> */ /* Macros for integer types */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20181202.204804" /**< Version Number (string) */
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

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /*< verbose level, global within the file */

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void ex17_init(void); /* global initialization function */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, iggc!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./ex17 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.upe.br">www.upe.br</a>>
 * @author Iago Gade Gusmao Carrazzoni
 * @version 20181202.204804
 * @date 2018-12-02
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    FILE *arq = NULL;
    char sfile[SBUFF]; 
    char data[SBUFF];
    quint_t *q = NULL;
    printf("Use uma das flags para realizar uma operacao. A flag -h eh a de ajuda.\n");
    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -V  version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "vhVf:m:n:")) != EOF)
    {
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'V':
                copyr();
                break;
            case 'v':
                verb++;
                break;
            case 'n':
                strcpy(sfile, optarg);
                arq = fopen(sfile, "r");
                pegaEntrada(q,arq); 
                break;
            case 'm':
                arq = fopen(optarg,"r");
                montar_afnd(arq);
                break;


            case 'f':
                strcpy(sfile, optarg);
                arq = fopen(sfile, "r"); /* Ponteiro leitor do arquivo em txt */
                if(arq == NULL)
                {
                    printf("Erro ao abrir o arquivo\n");
                    exit(1);
                }
                while(!feof(arq)) /* percorre todo o arquivo */
                {
                    fgets(data, SBUFF, arq); /* pegar a linha atual */
                    printf("%s\n", data);
                }
                fclose(arq);
                printf("Arquivo aberto com sucesso\n");
                ex11(optarg);
                break;

            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }
    }
    if(verb)
        printf("Verbose level set at: %d\n", verb);

    /* ex17_init(); */ /* initialization function */

    return EXIT_SUCCESS;
}












void converte(quint_t *q, char vet[SBUFF])
{
    char vetor[SBUFF];
    char sai[SBUFF];
    int i = 0;
    int j = 0;
    strcpy(vetor, q->d->s);
    do
    {
        if(vetor[i] != 'E')
        {
            sai[j] = vetor[i];
            j++;
        }
        i++;
     }while(vetor[i] != '\0');
     sai[j]='\0';
     strcat(vet, sai);
     return;
}

void pegaEntrada (quint_t *q, FILE *arq)
{
    /* as variaveis que comecam com p irao apenas guardar momentaneamente os dados */
    int pk;
    char pa;
    int ps0;
    char s[SBUFF];
    int pf[SBUFF];
    int i = 0;
    int c = 0;
    int pei;
    char pc;
    int pef;
    
    q->f = NULL;
    q->d = NULL; 
    fscanf(arq, "%d\n%c\n%d\n", &pk, &pa, &ps0);
    q->k = pk;
    q->a = pa;
    q->s0 = ps0;

    fgets(s, sizeof(s), arq);
    while(s[i] != '\0')
    {
        if(s[i] != ' ' && s[i] != '\n')
        {
            pf[c] = s[i] - ZERO_EM_ASCII;
            c++;
    
        }
        i++;
    }
    
    i = 0;
    /* while(pf[i] != '\0') */
    for(i = 0; i < c; i++)
    {
        insereNosEstadosFinais(&q->f, pf[i]);
    }
    while(!feof(arq))
    {
        fscanf(arq, "%d %c %d\n", &pei, &pc, &pef);
        insereNaFuncaoDelta(&q->d, pei, pc, pef);
    }
    return;
}
   
void encurtaEstadoKleene (quint_t *q, int e)
{
    delta_t *cont = q->d;
    delta_t *head = NULL;
    delta_t *aux = NULL;
    delta_t *busc = NULL;
    char kleene[SBUFF];
    char vet[SBUFF];

    while(cont != NULL)
    {
        if(cont->ei == e && cont->ef == e)
            insereComVetorNaFuncaoDelta(&head, cont->ei, cont->s, cont->ef);
        cont = cont->prox;
    }
    if(head == NULL)
        return;
    aux = head;
    cont = q->d;

    while(aux != NULL)
    {
        while(cont != NULL)
        {
            if(cont->ei == e && cont->ef != e)
            {
                montaKleene(aux->s, kleene);
                printf("\nkleene: %s\n", kleene);
                montaTransicao(kleene, cont->s, vet);
                printf("\nTransicao: %s\n", vet);
                busc = buscaDelta(q->d, aux->ei, aux->ef, aux->s);
                if(busc != NULL)
                    removerDelta(&q->d, busc);
                busc = buscaDelta(q->d, cont->ei, cont->ef, cont->s);
                if(busc != NULL)
                    removerDelta(&q->d, busc);
                insereComVetorNaFuncaoDelta(&q->d, e, vet, cont->ef);
            }
            cont = cont->prox;
        }
        cont = q->d;
        aux = aux->prox;
    }

    return;
}

void encurtaEstadoE (quint_t *q, int e)
{
    delta_t *qfinal = NULL;
    delta_t *qinicial = NULL;
    delta_t *cont = q->d;
    delta_t *qicont = NULL;
    delta_t *qfcont = NULL;
    delta_t *busc = NULL;
    char vet[SBUFF];
    int i;
    /* char kleene[SBUFF]; */

    /* cria duas funcoes delta: */
    /*uma com as transicoes que tem o estado a se apagar como estado final */
    /*e uma com as transicoes que tem o estado a se apagar como estado inicial */
    while(cont != NULL)
    {
        if(cont->ef == e)
            insereComVetorNaFuncaoDelta(&qinicial, cont->ei, cont->s, cont->ef);
        if(cont->ei == e)
            insereComVetorNaFuncaoDelta(&qfinal, cont->ei, cont->s, cont->ef);
        cont = cont->prox;
    }
    if(qinicial->prox != NULL)
    {
        printf("\noutro inicial: ei = %d\n", qinicial->prox->ei);
        encurtaEstadoE(q, qinicial->prox->ei);
        return;
    }

    qicont = qinicial;
    qfcont = qfinal;

    printf("\nDEBUG\n\n");
    printf("qicont\n");
    imprimeFuncaoDelta(qicont);
    printf("\nqfcont\n");
    imprimeFuncaoDelta(qfcont);

    while(qicont != NULL)
    {
        while(qfcont != NULL)
        {
            for(i = 0; i < SBUFF; i++)
                vet[i] = 0;
            /*if(qfcont->ei == qfcont->ef)
              {
              montaKleene(qfcont->s, kleene);
              busc = buscaTransicaoCabecaKleene(qfinal, qfcont->ei);
              montaTransicaoKleene(qfcont, kleene, vet);
              printf("\nTransicao criada: %s\n", vet);
              novoElementoDelta(&q->d, qicont->ei, vet, qfcont->ef);
              printf("Vou remover o ei = %d e o ef = %d, cujas transicoes sao si = %s e sf = %s\n", qicont->ei, qfcont->ef, qicont->s, qfcont->s);
              } */
            /*else
              { */
            montaTransicao(qicont->s, qfcont->s, vet);
            printf("\ntranseicao criada: %s\n", vet);
            novoElementoDelta(&q->d, qicont->ei, vet, qfcont->ef);
            printf("Vou remover o ei = %d e o ef = %d, cujas transicoes sao si = %s e sf = %s\n", qicont->ei, qfcont->ef, qicont->s, qfcont->s);
            /*} */
            qfcont = qfcont->prox;
        }
        qfcont = qfinal;
        while(qfcont != NULL)
        {
            busc = buscaDelta(q->d, qfcont->ei, qfcont->ef, qfcont->s);
            if(busc != NULL)
                removerDelta(&q->d, busc);
            qfcont = qfcont->prox;
        }

        qicont = qicont->prox;
    }
    qicont = qinicial;
    while(qicont != NULL)
    {
        busc = buscaDelta(q->d, qicont->ei, qicont->ef, qicont->s);
        if(busc != NULL)
            removerDelta(&q->d, busc);
        qicont = qicont->prox;
    }


    return;
}

void novoElementoDelta (delta_t **d, int ei, char vet[SBUFF], int ef)
{
    delta_t *cont = *d;
    delta_t *ant = NULL;

    while(cont != NULL)
    {
        ant = cont;
        cont = cont->prox;
    }

    cont = malloc(sizeof(delta_t));
    cont->prox = NULL;
    cont->ei = ei;
    strcpy(cont->s, vet);
    cont->ef = ef;

    if(ant != NULL)
        ant->prox = cont;
    else
        *d = cont;

    return;
}

void insereNaFuncaoDelta (delta_t **d, int ei, char c, int ef)
{
    delta_t *cont = *d;;
    delta_t *ant = NULL;
    int i;

    while(cont != NULL)
    {
        ant = cont;
        cont = cont->prox;
    }
    cont = malloc(sizeof(delta_t));
    cont->prox = NULL;

    cont->ei = ei;
    i = finalDoVetor(cont->s);
    cont->s[i] = c;
    cont->ef = ef;

    if(ant != NULL)
        ant->prox = cont;
    else
        *d = cont;

    return;
}

void insereComVetorNaFuncaoDelta (delta_t **d, int ei, char s[SBUFF], int ef)
{
    delta_t *cont = *d;;
    delta_t *ant = NULL;

    while(cont != NULL)
    {
        ant = cont;
        cont = cont->prox;
    }
    cont = malloc(sizeof(delta_t));
    cont->prox = NULL;

    cont->ei = ei;
    strcpy(cont->s, s);
    cont->ef = ef;

    if(ant != NULL)
        ant->prox = cont;
    else
        *d = cont;

    return;
}

void insereNosEstadosFinais (ef_t **p, int f)
{
    ef_t *cont = *p;;
    ef_t *ant = NULL;

    while(cont != NULL)
    {
        ant = cont;
        cont = cont->prox;
    }
    cont = malloc(sizeof(ef_t));
    cont->prox = NULL;

    cont->f = f;

    if(ant != NULL)
        ant->prox = cont;
    else
        *p = cont;

    return;
}

void montaKleene(char kleene[SBUFF], char vet[SBUFF])
{
    char vetor[SBUFF];
    int i = 1;
    int j = 0;

    vetor[0] = '(';
    while(kleene[j] != '\0')
    {
        vetor[i+j] = kleene[j];
        j++;
    }
    vetor[i+j] = ')';
    vetor[i+j+1] = '*';

    strcpy(vet, vetor);

    return;
}

void montaTransicao (char sei[SBUFF], char sef[SBUFF], char vet[SBUFF])
{
    char vetor[SBUFF]="\0";

    strcat(vetor, sei);
    strcat(vetor, sef);

    strcpy(vet, vetor);

    printf("vet = %s",vet);
    return;
}

delta_t *buscaDelta (delta_t *head, int ei, int ef, char vet[SBUFF])
{
    delta_t *cont = head;

    while(cont != NULL)
    {
        if(cont->ei == ei && cont->ef == ef && !strcmp(cont->s, vet))
            return cont;
        cont = cont->prox;
    }

    return NULL;
}


int finalDoVetor (char s[SBUFF])
{
    int i = 0;

    while(s[i] != '\0')
        i++;

    return i;
}

void imprimeQuintupla (quint_t q)
{
    printf("QUINTUPLA\n\n");
    printf("numero de estados = %d\n", q.k);
    printf("ultima letra do alfabeto = %c\n", q.a);
    printf("estado inicial = %d\n", q.s0);
    imprimeListaDeEstadosFinais(q);
    imprimeFuncaoDelta(q.d);

    return;
}

void imprimeListaDeEstadosFinais (quint_t q)
{
    ef_t *cont = q.f;

    while(cont != NULL)
    {
        printf("%d\n", cont->f);
        cont = cont->prox;
    }
    return;
}

void imprimeFuncaoDelta (delta_t *head)
{
    delta_t *cont = head;

    while(cont != NULL)
    {
        printf("(%d, %s, %d)\n", cont->ei, cont->s, cont->ef);
        cont = cont->prox;
    }
    return;
}

void removerDelta(delta_t **head, delta_t *r) 
{
    delta_t *cont = *head;
    delta_t *plant = NULL;

    if(r == NULL)
        return;
    while(cont != NULL && cont != r)
    {
        plant = cont;
        cont = cont->prox;
    }
    if(cont == NULL) 
        return;
    if(plant != NULL) 
        plant->prox = cont->prox;
    else 
        *head = cont->prox;

    free(cont);

    return;
} 
