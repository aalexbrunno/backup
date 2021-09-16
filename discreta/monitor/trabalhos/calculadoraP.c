/***************************************************************************
 *   polonesa.c                               Version 20190919.124742      *
 *                                                                         *
 *   Calculadora Polonesa                                                  *
 *   Copyright (C) 2019         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
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

/* Organizacao:
 *
 * pilha_t
 *              +--------------+
 *              | int val;     |
 *              +--------------+
 *              | pilha *prox; |
 *              +--------------+
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <string.h> /* strtok() */
#include <errno.h> /* handling errors */

/* ---------------------------------------------------------------------- */
/* definitions */
#define SBUFF 80
#define INC 42
#define DEC 19
#define TOT 0

/* ---------------------------------------------------------------------- */
/* structs and types */

typedef struct nodo_pilha
{
    int val; /* valor na pilha */
    struct nodo_pilha *prox;
} pilha_t;

/* ---------------------------------------------------------------------- */
/* prototypes */

/* funcoes de pilha */
int empty(pilha_t *pil); /* retorna verdadeiro se pilha vazia */
void push(pilha_t **pil, int val); /* insere elemento no topo */
int pop(pilha_t **pil); /* remove elemento do topo */
int top(pilha_t *pil); /* consulta elemento no topo, sem remove-lo */
int total(int modo); /* retorna o total de elementos na pilha */
void clean(pilha_t **pil); /* limpa a memoria utilizada */

/* funcoes auxiliares */
int valida(char *s); /* valida a equacao */

/* ---------------------------------------------------------------------- */
/* entra com valores e calcula expressao
 */
int main(void)
{
    char equa[SBUFF];
    char *tok, *freetok, *bn;
    int num, n1, n2, res;
    pilha_t *pil=NULL;
    int fim=0;

    printf("Calculadora Polonesa v0.2, by Dr. Beco\n");
    printf("Digite uma expressao em notacao pos-fixa:\n");

    fgets(equa, SBUFF, stdin);
    bn=strchr(equa, '\n');
    if(bn)
        *bn='\0';
    if(!valida(equa))
    {
        printf("Equacao deve conter apenas numeros, +-*/ e espacos, ou 'q' para terminar\n");
        perror("Error message");
        exit(1);
    }
    freetok=tok=strdup(equa); /* duplicar string para nao perder, pois strdup() destroi a string */
    for(tok = strtok(equa," "); !fim && tok != NULL; tok = strtok(NULL, " "))
    {
        switch(*tok)
        {
            case 'q':
                printf("encontrado 'q'\n");
                fim=1;
                break;
            case '+':
                printf("somar\n");
                n1=pop(&pil);
                n2=pop(&pil);
                res = n1 + n2;
                push(&pil, res);
                break;
            case '-':
                printf("subtrair\n");
                n1=pop(&pil);
                n2=pop(&pil);
                res = n1 - n2;
                push(&pil, res);
                break;
            case '*':
                printf("multiplicar\n");
                n1=pop(&pil);
                n2=pop(&pil);
                res = n1 * n2;
                push(&pil, res);
                break;
            case '/':
                printf("dividir\n");
                n1=pop(&pil);
                n2=pop(&pil);
                res = n1 / n2;
                push(&pil, res);
                break;
            default:
                num=atoi(tok);
                printf("Numero %d\n", num);
                push(&pil, num);
        }
    }

    printf("Total de elementos na pilha: %d\n", total(TOT));
    printf("Elemento do topo: ");
    num=top(pil);
    if(errno) 
    {
        printf("erro\n");
        perror("Error message");
    }
    else
        printf("%d\n", num);

    /* printf("\ndebug:\n\ttok: %p %s %c\n\tfreetok: %p %s %c\n\n", tok, tok, *tok, freetok, freetok, *freetok); */
    if(!empty(pil))
    {
        printf("Limpando memoria e ");
        clean(&pil);
        free(freetok); /* todo malloc deve ter um free. strdup() chama malloc internamente */
    }
    printf("Terminando o programa com sucesso...\n");
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* valida a equacao aceitando apenas numeros, 4 operacoes e espaco */
int valida(char *s)
{
    char sval[]="0123456789 +-*/q";

    errno = 0;
    while(*s!='\0')
    {
        if(strchr(sval, *s)==NULL)
        {
            errno=EINVAL; /* invalid argument */
            return 0;
        }
        s++;
    }
    return 1;
}

/* ---------------------------------------------------------------------- */
/* remove elemento do topo */
int pop(pilha_t **pil)
{
    errno=ENOSYS;
    return -1;
}

/* ---------------------------------------------------------------------- */
/* insere elemento no topo */
void push(pilha_t **pil, int n)
{
    ;
}

/* ---------------------------------------------------------------------- */
/* retorna verdadeiro se pilha vazia */
int empty(pilha_t *pil)
{
    return (pil==NULL);
}

/* ---------------------------------------------------------------------- */
/* limpa a memoria utilizada */
void clean(pilha_t **pil)
{
    pilha_t *pant=NULL;

    if(empty(*pil))
        return;
    
    /* laco para apagar todos nodos */
    while((*pil)!=NULL)
    {
        pant = *pil;
        (*pil) = (*pil)->prox;
        free(pant);
    }

    return;
}

/* ---------------------------------------------------------------------- */
/* retorna o total de elementos na pilha */
int total(int modo)
{
    /* BUG problema nesta funcao: ela nao depende de pilha *pil */
    static int totalpil=0;

    if(modo==INC)
        totalpil++;
    if(modo==DEC)
        totalpil--;
    return totalpil;
}

/* ---------------------------------------------------------------------- */
/* consulta elemento no topo, sem remove-lo */
int top(pilha_t *pil)
{
    errno = 0;
    if(empty(pil))
    {
        errno=EFAULT; /* bad address */
        return 0;
    }
    return pil->val; 
}


/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

