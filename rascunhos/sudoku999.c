/***************************************************************************
 *   sudoku999.c                           Version 20201018.020303         *
 *                                                                         *
 *   Sudoku Solver                                                         *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
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

/* ---------------------------------------------------------------------- */
/**
 * @file sudoku999.c
 * @ingroup GroupUnique
 * @brief Brief description
 * @details This program really do a nice job as a template, and template only!
 * @version 20160908.182830
 * @date 2016-09-08
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
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
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc sudoku999.c -o sudoku999.x -Wall
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
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv sudoku999.c
 */

/* ---------------------------------------------------------------------- */
/* includes */

 /* Standard I/O functions */
#include <stdlib.h> /* #include <stdio.h>Miscellaneous functions (rand, malloc, srand)*/
#include "sudoku999.h" /* To be created for this template if needed */
#include <stdio.h>

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */

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
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./sudoku999 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */

int main(void)
{
    int z; /* flag indicativa de deducao com sucesso */
    int sudoku[9][9][9]={{{0}}}; /* todas as 729 possibilidades */

    IFDEBUG("Starting optarg loop...");

    sudoku999_init(sudoku); /* initialization function: set all candidates to true */
    printsudoku(sudoku);
    do
    {  
        z=0;
        z+=d1(sudoku); /* naked single */
        z+=d2(sudoku); /* hidden single */
        z+=d3(sudoku); /* naked pair */
        z+=d4(sudoku); /* hidden pair */
        z+=d5(sudoku); /* pointing candidate */
        z+=d6(sudoku); /* claiming candidate */
        z+=d7(sudoku); /* x-wing */
        z+=d8(sudoku); /* xy-wing */
        z+=d9(sudoku); /* fined x-wing */
    }while(z);

    printsudoku(sudoku);

    return check(sudoku);
}

/* Write your functions here... */

/* ---------------------------------------------------------------------- */
/* funcoes de apoio */

/* ---------------------------------------------------------------------- */
/* imprime o tabuleiro de sudoku */
void printsudoku(int w[9][9][9])
{
    int i,j,k,ct=0,k1, flag=0;

    //fprintf(stdout,"\n   +---+---+---+\n");
    fprintf(stdout,"    abc def ghi \n");
    for(i=0;i<9;i++)
    {
        if(i==0 || i==3 || i==6 || i==9)
        {
            fprintf(stdout,"   +---+---+---+\n");
        }
        fprintf(stdout,"%i. ",i+1);
        for(j=0;j<9;j++)
        {
            for(k=0;k<9;k++)
            {
                //printf("%i",w[i][j][k]);
                ct++;
                if(w[i][j][k] != 0)
                {
                    for(k1=0;k1<9;k1++)
                    {
                        if(k == k1)
                            continue;

                        if(w[i][j][k1] == 1)
                        {
                            ct=0;
                            flag=1;
                            break;
                        }
                    }
                    break;
                }
            }
            if(j==0 || j==3 || j==6 || j==9)
                fprintf(stdout,"|");

            fprintf(stderr,"%i",ct);
            if(flag==1)
            {
                fprintf(stdout,".");
                flag=0;
            }
            else
            {
                fprintf(stdout,"%i",ct);
                flag=0;
            }
            
            ct=0;
            flag=0;
        }
        fprintf(stdout,"|");
        fprintf(stderr,"\n");
        fprintf(stdout,"\n");
    }
    fprintf(stdout,"   +---+---+---+\n\n");
}
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "sudoku999", "Brief description");
    printf("\nUsage: %s [-h|-v]\n", "sudoku999");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "sudoku999", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written in
 * multiple lines
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x == funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @return Void
 *
 * @warning Be carefull with blu
 * @todo Need to implement it. Its empty now. This doxygen tags are overwhelming.
 * Mandatory tags are: ingroup, brief, details, param, return, author and date.
 * The others are optional.
 *
 * @deprecated This function will be deactivated in version +11
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 *
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 * @copyright Use this tag only if not the same as the whole file
 *
 */
void sudoku999_init(int w[9][9][9])
{
    IFDEBUG("sudoku999_init()");
    /* initialization */
    int i,j,k,d;

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            scanf(" %lc",w[i][j]);
        }
    }

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        { 
            for(d=0;d<9;d++)
             {
                if((w[i][j][d]-48) != 0)
                 {
                    if(w[i][j][d]==10)
                     {
                        w[i][j][d]=0;
                        break;
                    }
                    int pos=w[i][j][d]-48;
                    w[i][j][(pos-1)]=1;
                    for(k=0;k<9;k++)
                     {
                        if(k == (pos-1))
                         {
                            continue;
                        }
                        w[i][j][k] = 0;
                    }
                    break;
                }
                if((w[i][j][d]-48) == 0)
                {
                    for(k=0;k<9;k++)
                    {
                        w[i][j][k] = 1;
                    }
                    break;
                }
            }
            for(k=0;k<9;k++)
            {
                //printf("%i", w[i][j][k]);
            }
            //printf("|");
        }
        //printf("\n");
    }
    return;
}


/* ---------------------------------------------------------------------- */
/* acha coordenada superior esquerda do bloco que contem uma celula l,c dada */
/* retorna o numero do bloco e seta as coordenadas em *ql, *qc
 * +---+---+---+
 * | 0 | 1 | 2 | 0,0 0,3 0,6
 * +---+---+---+
 * | 3 | 4 | 5 | 3,0 3,3 3,6
 * +---+---+---+
 * | 6 | 7 | 8 | 6,0 6,3 6,6
 * +---+---+---+
 */
int cbloco(int l, int c, int *ql, int *qc)
{
    int b; /* numero do bloco */

    /*Muda a posicao para as coordenadas da 
     * celula do canto superior esquerdo de um bloco*/
    *ql = (l/3)*3;
    *qc = (c/3)*3;
    /*Recebe as coordenadas e localiza a posicao do bloco*/
    switch (*ql)
    {    
        case 0:
            switch(*qc)
            {
                case 0:
                    b = 0;
                    break;
                case 3:
                    b = 1;
                    break;
                case 6:
                    b = 2;
                    break;

            }
            break;

        case 3:
            switch(*qc)
            {
                case 0:
                    b = 3;
                    break;
                case 3:
                    b = 4;
                    break;
                case 6:
                    b = 5;
                    break;
            }
            break;

        case 6:
            switch(*qc)
            {
                case 0:
                    b = 6;
                    break;
                case 3:
                    b = 7;
                    break;
                case 6:
                    b = 8;
                    break;
            }
            break;

    }

    return b;
}

/* ---------------------------------------------------------------------- */
/* acha coordenada superior esquerda do bloco n dado */
/* retorna void
 * +---+---+---+
 * | 0 | 1 | 2 | 0,0 0,3 0,6
 * +---+---+---+
 * | 3 | 4 | 5 | 3,0 3,3 3,6
 * +---+---+---+
 * | 6 | 7 | 8 | 6,0 6,3 6,6
 * +---+---+---+
 */
void bloco(int n, int *ql, int *qc)
{
    
    int l,c;

    if(n < 3)
    {
        l = 0;

        if(n == 0)
            c = 0;

        if(n == 1)
            c = 3;

        if(n == 2)
            c = 6;
    }
    if(n < 6 && n >= 3)
    {
        l = 3;

        if(n == 3)
            c = 0;

        if(n == 4)
            c = 3;

        if(n == 5)
            c = 6;
    }
    if(n < 9 && n >= 6)
    {
        l = 6;

        if(n == 6)
            c = 0;

        if(n == 7)
            c = 3;

        if(n == 8)
            c = 6;
    }

    *ql = l;
    *qc = c;
    
    return;
}

/* ---------------------------------------------------------------------- */
/* retorna verdadeiro se a celula tem candidato unico */
int unico(int y[9])
{
    int ct=0,i,n=0;
    for(i=0;i<9;i++)
    {
        if(y[i]!=0)
        {
            n=i;
            ct++;
        }
    }
    if(ct!=1)
    {
        n=0;
    }
    return (n+1);
}

/* ---------------------------------------------------------------------- */


/* ---------------------------------------------------------------------- */
/* check if sudoku is solved, incomplete or invalid */
int check(int w[9][9][9])
{
    int l, c, flag = 0, contador = 0, exit = 1;
	
	for(l=0; l<9; l++)
	{
		for(c=0; c<9; c++)
		{
			contador++;
			if(totalcandy(w[l][c])== 0)
			{
				flag = 0;
				exit = 0;
				break;
			}					
			if(totalcandy(w[l][c])== 1)
            {
				if(unico(w[l][c]))
                {
					flag = -1;
                }
            }
				if(!unico(w[l][c]))
				{
					flag = contador;
					exit = 0;
					break;
				}	
			if(totalcandy(w[l][c]) > 1)
			{
				flag = contador;
				exit = 0;
				break;	
            }			
		}
		if(exit == 0)
			break;
	}
	return flag;
}

int totalcandy(int y[9])
{
    int ct=0;
    for(int i=0;i<9;i++)
    {
        if(y[i]!=0)
        {
            ct++;
        }
    }
    return ct;
}
int dyes(int l, int c, int n, int w[9][9][9])
{
    int i,j,
    l0=(l/3)*3, //recebe a coordenada l0 do bloco
    c0=(c/3)*3; //recebe a coordenada c0 do bloco
    for(i=0;i<9;i++) //navega pelas colunas da matriz
    {
        if(i==c)
        {
            continue;
        }
        if(w[l][i][n]==1)
        {
            w[l][c][n]=0;
            break;
        }
    }
    for(i=0;i<9;i++) //navega pelas linhas da matriz
    {
        if(i==l)
        {
            continue;
        }
        if(w[i][c][n]==1)
        {
            w[l][c][n]=0;
            break;
        }
    }
    /* este conjunto de fors servem para a navegacao dentro do bloco da matriz*/
    for(i=0;i<3;i++) //variavel para linha
    {
        if(i==l)
        {
            continue;
        }
        for(j=0;j<3;j++) //variavel para coluna
        {
            if(j==c)
            {
                continue;
            }
            if(w[l0+i][c0+j][n]==1)
            {
                w[l][c][n]=0;
            }
        }
    }
    return 1;
}

    
void clearcandy(int w[9][9][9], int l, int c, int y[9])
{    
    int j;
    for(int i = 0; i<9; i++)
    {
        //printf("y[%d] = %d\n", i,y[i]);
    }
        for(j=0;j<9;j++)
        {
            if(w[l][c][j]==y[j])
            {
                y[j]=0;
            }
        }
}
void copycandy(int w[9][9][9], int l, int c, int y[9])
{
	int i;

	for(i=0; i<9;i++)
	{
        y[i] = w[l][c][i];
	}
}
/* ---------------------------------------------------------------------- */
/* funcoes de deducao de d1 a d8 */


/* ---------------------------------------------------------------------- */
/* naked single : peladao */
/* d1 : naked sigle
 * limpa linha: confronta cada valor ja deduzido com sua linha (horizontal) limpando falsas possibilidades
 *
 * Explicacao:
 *      percorre todas as 9x9 celulas da grade (cada celula contem 9 possibilidades)
 *      Para cada celula que achar que tiver o valor ja determinado (unica possibilidade), 
 *      percorre a horizontal que ela pertence e remove nas outras celulas dessa horizontal 
 *      a possibilidade deste valor que nao pode ser repetido
 */

/* 1- naked single : peladao : 
--> quando as possibilidades de uma celula se reduzem a um unico numero, ele e o valor correto.

   se um numero foi deduzido, remove-se o mesmo como candidato nas outras celulas da mesma linha, coluna ou bloco

algoritmo: fixa celula e gira digito, comparando-o com os grupos (linha, coluna, bloco), ate reduzir suas possibilidades a apenas uma.

 */
int d1(int w[9][9][9])
{
    int z=0;
    z+=d1l(w); /* naked single : line */
    z+=d1c(w); /* naked single : column */
    z+=d1b(w); /* naked single : block */
    //printsudoku(w);
    //printf("d1() - OK!\n");
    return z;
}

/* ---------------------------------------------------------------------- */
/* hidden single : peladao escondido */
/* d2: procura um numero que aparece apenas uma vez na linha */
/* Explicacao:
 *      Procura, para cada celula, uma que nao tem valor definido e chame-a de celula com n candidatos.
 *      Percorre a horizontal da celula com n candidatos e remove candidatos que se repetem
 *      Ao final, se restar apenas um candidato na celula fixada inicialmente, este eh o valor
 *      correto da celula.
 * 
 *      Exemplo, o valor 7 para a celula a7. Inicialmente os candidatos sao 1, 3, 6 e 7
 *      Percorrendo a horizontal e removendo os repetidos sobra apenas o 7 como possibilidade
 
       a   b   c   d   e   f   g   h   i
     +===========+===========+===========+
     |1 3:1 3:   |1  :  3:   |   :   : 2 |
  7  |  6:  6:   |   :  6:4 6| 5 :   :   |
     |7  :   :  9|   :   :   |   : 8 :   |
     +-----------+-----------+-----------+
 */

/* 2- hidden single : peladao escondido :
--> mesmo que tenham mais candidatos, se em uma celula tem um valor que nao aparece nas outras da mesma linha, coluna ou bloco, ele eh o solteirao escondido.

 * uma celula com multiplos candidatos eh chamada de solteirao se um dos candidatos so
 * aparece em um local na linha, coluna ou bloco. Ele e a solucao e os outros candidatos podem ser eliminados
 
algoritmo: 
 
 */
int d2(int w[9][9][9])
{
    int z=0;
    z+=d2l(w); /* hidden single : line */
    z+=d2c(w); /* hidden single : column */
    z+=d2b(w); /* hidden single : block */
    return z;
}

/* ---------------------------------------------------------------------- */
/* naked pair : dupla pelada */
/* naked pair:
 *
 * para cada conjunto de 2 celulas
 * quando tiverem os mesmo 2 candidatos e apenas eles
 * retira das outras celulas do grupo esses candidatos
 *
 * naked tuple: (todos grupos: linha, coluna e bloco)
 * N>1 celulas exatamente iguais com N candidatos cada
 *
 * >> retira das outras celulas do grupo esses numeros
 *
 * Upgrade: N>1 celulas com APENAS N candidatos em comum
 *
 */

/* 3- naked pair : dupla pelada : 

 * duas celulas com o mesmo par de candidatos e apenas ele, chama-se dupla pelada.
 * os valores do par sao removidos do grupo (bloco, linha ou coluna) em que se encontram
 * sobrando somente a duvida do par
 */

/* Opcional: 3.b- naked triple : tripla pelada : ocorre quando 3 celulas em uma mesma linha, coluna ou bloco contem os
 * apenas os mesmos tres candidatos; ou um subconjunto deles. Todas as aparencias dos 3 candidatos podem ser
 * eliminadas do resto do bloco, linha ou coluna
 */


/* Opcional: 3.c- naked quad : quatro pelados : quatro celulas com os mesmos quatro candidatos ou subconjuntos, em uma mesma
 * linha, coluna ou bloco, implicam que os mesmos candidatos em outras celulas no bloco ou seguindo a linha ou
 * coluna respectiva podem ser eliminados.
 */
int d3(int w[9][9][9])
{
    int z=0;
    //printf("entrou d3\n");
    z+=d3l(w); /* naked pair : line */
    z+=d3c(w); /* naked pair : column */
    z+=d3b(w); /* naked pair : block */
    z+=d3_triplel(w); /* naked triple : line */
    z+=d3_triplel(w); /* naked triple : column*/
    z+=d3_triplel(w); /* naked triple : block */
    return z;
}

/* ---------------------------------------------------------------------- */
/* hidden pair : dupla escondida */
/*
 * Se X candidatos em um grupo estao apenas em X celulas compartilhadas, pode-se limpar
 * os outros candidatos dessas X celulas, sobrando apenas os candidatos repetidos.
 * Afeta: apenas as celulas da tupla.
 *
 * O par escondido quando limpo se transforma em par pelado
 *
 */

/* 4- hidden pair : dupla escondida
 *
 * quando dois candidatos aparecem em apenas duas celulas, em um grupo (linha, coluna ou bloco)
 * mesmo que estas celulas estejam com mais candidatos
 * os demais podem ser eliminados dessas duas celulas, restando assim uma dupla pelada.
 */
int d4(int w[9][9][9])
{
    int z=0;
    z+=d4l(w); /* hidden pair : line */
    z+=d4c(w); /* hidden pair : column */
    z+=d4b(w); /* hidden pair : block */
    return z;
}

/* ---------------------------------------------------------------------- */
/* pointing candidate : candidato dedo-duro */
/* pointing pair : dedo-duro
 * quando um candidato esta dentro de um bloco em apenas duas ou tres celulas
 * alinhadas em linha ou coluna, chama-se dedo-duro. O numero do candidato pode ser removido
 * da linha ou coluna que se estende para fora do bloco. Parecido com o 5, mas aqui remove de linha ou coluna,
 * enquanto la remove de bloco.
 * 
 * Pointing: um certo candidato de um bloco so aparece numa reta: limpa o restante da reta
 * Claiming: um certo candidato de uma reta so aparece em um bloco: limpa o restante do bloco
 * 
 */

/* 5- pointing pair : dedo-duro : quando um candidato esta dentro de um bloco em apenas duas ou tres celulas
 * alinhadas em linha ou coluna, chama-se dedo-duro. O numero do candidato pode ser removido
 * da linha ou coluna que se estende para fora do bloco. Parecido com o 5, mas aqui remove de linha ou coluna,
 * enquanto la remove de bloco.
 */
int d5(int w[9][9][9])
{
    int z=0;
    z+=d5l(w); /* pointing candidate : line */
    z+=d5c(w); /* pointing candidate : column */
    return z;
}

/* ---------------------------------------------------------------------- */
/* claiming candidate : candidato exigente */
/* claiming pair : exigente : quando um certo candidato precisa estar numa certa linha ou coluna, a linha ou coluna o requisita. Se as possibilidades para essa linha ou coluna estao apenas em um bloco, mantem-se os candidatos na linha ou coluna que intersecciona o bloco, mas remove-se o mesmo do restante do bloco.
 * A linha ou coluna o requisita,
 * logo todas outras celulas deste bloco fora da linha ou coluna, podem ter este numero canditado removido. Parecido com 4, mas aqui remove do bloco, la da linha ou coluna.
 * 
 * Pointing: um certo candidato de um bloco so aparece numa reta: limpa o restante da reta
 * Claiming: um certo candidato de uma reta so aparece em um bloco: limpa o restante do bloco
 * 
 */

/* 6- claiming pair : exigente : quando um certo candidato precisa estar numa certa linha ou coluna, a linha ou coluna o requisita. Se as possibilidades para essa linha ou coluna estao apenas em um bloco, mantem-se os candidatos na linha ou coluna que intersecciona o bloco, mas remove-se o mesmo do restante do bloco.
 * A linha ou coluna o requisita,
 * logo todas outras celulas deste bloco fora da linha ou coluna, podem ter este numero canditado removido. Parecido com 4, mas aqui remove do bloco, la da linha ou coluna.
 */
int d6(int w[9][9][9])
{
    int z=0;

    z+=d6l(w); /* claiming candidate : line */
    z+=d6c(w); /* claiming candidate : column */

    return z;
}

/* ---------------------------------------------------------------------- */
/* x-wing : cruzamento em x */

/* 7- x-wing : cruzamento : quando um candidato aparece em quatro celulas que formam os cantos de um retangulo ou quadrado,
 * e aparece somente em duas celulas para cada uma das linhas, o candidato pode ser removido das colunas.
 * Idem para o inverso entre colunas e linhas.
 */
int d7(int w[9][9][9])
{
    int z=0;
    z+=d7l(w); /* x-wing : line */
    z+=d7c(w); /* x-wing : column */
    return z;
}
/* ---------------------------------------------------------------------- */
/* fined x-wing : cruzamento em x com rebarba */

int d9(int w[9][9][9])
{
    int z=0;

    z+=d9l(w);
    z+=d9c(w);

    return z;
}


/* ---------------------------------------------------------------------- */
/* deducoes divididas por grupo: linha, coluna e bloco */


/* ---------------------------------------------------------------------- */
/* naked single : line */
/* naked single: confronta cada valor ja deduzido com sua linha (horizontal) */
int d1l(int w[9][9][9])
{
    int l, c, /* indices para rodar o mapa inteiro */
        j, /* as colunas a percorrer na linha l a limpar */
        n, /* o numero unico na linha l */
        z=0; /* retorna verdadeiro se alterou w */
        //z1; /* flag para imprimir */
    char *hd="d1l: naked single (line)";

    for(l=0; l<9; l++)
    {
        for(c=0; c<9; c++)
        {
            if(totalcandy(w[l][c])==1)
            {
                n = unico(w[l][c]);
                //printf("w[%d][%d][%d]\n",l,c,n-1);
                for(j=0; j<9; j++) /* todas colunas da linha l */
                {
                    if(j==c)
                    {
                        continue;
                    }
                    if(w[l][j][n-1]==0)
                    {
                        continue;
                    }
                    z=1;
                    fprintf(stdout,"%s dado a celula %d %c contem apenas o candidato %d, remove o mesmo como candidato de %d %c\n",hd,l+1,letra(c),n-1,l+1,letra(j));

                    w[l][j][n-1]=0;

                    //printf("%s\n",hd);

                }
                //printsudoku(w);
            }
        }
    }
    return z>0;
}
/* ---------------------------------------------------------------------- */
/* naked single : column */
/* naked single: confronta cada valor ja deduzido com sua coluna (vertical) */
int d1c(int w[9][9][9])
{
    int z=0, /* flag que indica se ocorreu deducao */
    n, /* o numero unico na coluna c */
    l,c, /* indices para rodar o mapa inteiro */
    j; /* as linhas a percorrer na coluna c a limpar */
    char *hd="d1c: naked single (column)";
    for(c=0; c<9; c++)
     {
        for(l=0; l<9; l++)
        {    
            if(totalcandy(w[l][c])==1)
            {
                n = unico(w[l][c]);
                //z=1;
                //printf("w[%d][%d][%d]\n",l,c,n-1);
                for(j=0; j<9; j++) /* todas as linhas da coluna c */
                {
                    if(j==l)
                    {
                        continue;
                    }
                    if(w[j][c][n-1]==0)
                    {
                        continue;
                    }
                    z=1;
                    fprintf(stdout,"%s dado a celula %d %c contem apenas o candidato %d, remove o mesmo como candidato de %d %c\n",hd,l+1,letra(c),n-1,j+1,letra(c));
                    w[j][c][n-1]=0;
                }
                //printsudoku(w);
             }
         }
    }
    return z>0;
}
/* ---------------------------------------------------------------------- */
/* naked single : block */
/* naked single: confronta cada valor ja deduzido com seu quadrado (bloco) */
int d1b(int w[9][9][9])
{
    int z,l,c,n,i,j; /* flag que indica se ocorreu deducao */
    int l0=0; int c0=0; /* ponteiros das coordenadas superior esquerda do bloco */
    int x,y;
    char *hd="d1b: naked single (block)";
    for(l=0;l<9;l++)
    {
        for(c=0;c<9;c++)
        {
            if(totalcandy(w[l][c])==1)
            {
                //z=1;
                n=unico(w[l][c]);
                cbloco(l,c,&l0,&c0);
                x=l0;
                y=c0;
                //printf("w[%d][%d][%d]\n",l,c,n-1);
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        if(i+x==l && j+y==c)
                        {
                            continue;
                        }
                        if(w[(x+i)][(y+j)][n-1]==0)
                        {
                            continue;
                        }
                        fprintf(stdout,"%s dado a celula %d %c contem apenas o candidato %d, remove o mesmo como candidato de %d %c\n",hd,l+1,letra(c),n-1,x+i+1,letra(y+j));
                        z=1;
                        w[(x+i)][(y+j)][n-1]=0;
                        //printf("w[%d][%d][%d]\n",(i),(j),n-1);

                    }
                    //printf("l0: %d c0: %d\n",l0,c0);
                }
                //printsudoku(w);
            }
        }
    }
    return z>0;
}
/* ---------------------------------------------------------------------- */
/* hidden single : linha */
/* hidden single: procura numa horizontal um numero com apenas uma celula possivel de estar */
int d2l(int w[9][9][9])
{
    int l, c, j, z=0;
    int candy[9];
    char *hd="d2l: hidden single (line)";
    
    for(l=0; l<9; l++)
    {
        for(c=0; c<9; c++)
        {   
            if(totalcandy(w[l][c])>1)
            {
                copycandy(w, l, c, candy);
                         
                for(j=0; j<9; j++)
                {
                    if(j==c)
                    {    
                        continue;
                    }    
                    clearcandy(w,l,j,candy);
                }
                if(totalcandy(candy)!= 1)
                {
                    continue;
                }    
                if(totalcandy(candy) == 1)
                {
                    for(j=0; j<9; j++) /* todas colunas da linha l */
                    {
                        fprintf(stdout,"%s dado que o candidato %d pode ocorrer na celula %d %c o mesmo deixa de ser candidato e passa a ser o valor da celula\n",hd,j+1,l+1,letra(c));
                            w[l][c][j]= candy[j];
                            z = 1;
                    } 
                    break;
                }
            }
        }      
    }
   
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* hidden single : column */
/* hidden single: procura numa vertical um numero com apenas uma celula possivel de estar */
int d2c(int w[9][9][9])
{
    //printf("Entrou na funcao");
    int l, c, j;
    int candy[9];
    int z = 0; /* flag que indica se ocorreu deducao */
    char *hd="d2c: hidden single (column)";
    for(c=0; c<9; c++)
    {
        for(l = 0; l<9; l++)
        {
            if(totalcandy(w[l][c])>1)
            {
                copycandy(w, l, c, candy);
                for(j=0; j<9; j++)
                {
                    if(j==l)
                    {    
                        continue;
                    }   
                    clearcandy(w,j,c,candy);
                }
                if(totalcandy(candy) != 1)
                {
                    continue;
                }    
                if(totalcandy(candy) == 1)
                {
                    for(j=0; j<9; j++)
                    {
                        fprintf(stdout,"%s dado que o candidato %d pode ocorrer na celula %d %c o mesmo deixa de ser candidato e passa a ser o valor da celula\n",hd,j+1,l+1,letra(c));
                         w[l][c][j] = candy[j];
                         z = 1;
                    }
                    break;
                }
            }
        }
    }

    return z>0;
}

/* ---------------------------------------------------------------------- */
/* hidden single : block */
/* hidden single: procura num bloco um numero com apenas uma celula possivel de estar */
int d2b(int w[9][9][9])
{
    int l, c, j,  n, i,
    l0=0,
    c0=0;
    int x,y;
    int candy[9];
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d2b: hidden single (block)";

    for(l=0; l<9; l++)
    {
        for(c=0; c<9; c++)
        {
            if(totalcandy(w[l][c])>1)
            {
                copycandy(w, l, c, candy);
                cbloco(l,c,&l0,&c0);
                x=l0;
                y=c0;

                for(j=0; j<3; j++)
                {
                    for(i=0; i<3; i++)
                    {
                        if((j+y)==c && (i+x) == l)
                        {    
                            continue;
                        }    
                        clearcandy(w,i+x,j+y,candy);
                    }
                }
                if(totalcandy(candy)!= 1)
                {    
                    continue;
                }    
                if(totalcandy(candy) == 1)
                {
                    for(n=0; n<9; n++)
                    {
                        fprintf(stdout,"%s dado que o candidato %d pode ocorrer na celula %d %c o mesmo deixa de ser candidato e passa a ser o valor da celula\n",hd,j+1,l+1,letra(c));
                        w[l][c][n] = candy[n];
                        z = 1;
                    }
                    break;
                }
            }
        }
    }

    return z>0;
}

/* ---------------------------------------------------------------------- */
/* naked pair : line */
/* naked tuple (pair/triple/quad): remove candidatos fora do par, no grupo */
int d3l(int w[9][9][9])
{
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d3l: naked pair (line)";
    int l, c1, c2, d, i, j, f, x, y, b1, b2;
    int lb1=0, lb2=0, cb1=0, cb2=0;
    int candy[9];
    //printf("entrou d3l\n");
    for(l=0; l<9; l++)
    {
        for(c1=0; c1<9; c1++)
        {
            if(totalcandy(w[l][c1])==1)
            {
                z=0;
                continue;
            }
            for(c2=0; c2<9; c2++)
            {
                if(totalcandy(w[l][c2])==1)
                {
                    z=0;
                    continue;
                }
                if(c1==c2) //significa que é a mesma célula
                {
                    continue; // c2++
                }
                if(totalcandy(w[l][c1]) != 2 || totalcandy(w[l][c2]) != 2) //o total de candidatos das duas células tem que ser igual a 2
                {
                    continue;
                }
                f=0; //flag da dedução 1
                for(d=0; d<9; d++)
                {
                    if(w[l][c1][d] != w[l][c2][d]) //testa para saber se os candidatos são iguais
                    {
                                    
                        f=1; //ocorreu dedução 1
                        break; //sai do for d++
                    }
                    //se os candidatos forem iguais tem que guardar em algum lugar
                    copycandy(w, l, c1, candy);
                }
                if(f==1)
                {
                    continue; //troca célula c2, pois os candidatos não eram iguais (c2++)
                }
                //vai ter achado um par => limpar esses candidatos na linha
                for(i=0;i<9;i++)
                {
                    if(i==c1 || i==c2)
                    {
                        continue;
                    }
                    for(d=0;d<9;d++)
                    {
                        if(w[l][i][d]==candy[d])
                        {
                        fprintf(stdout,"%s as celulas %d %c e %d %c com os mesmos candidatos %d, limpando ele da celula %d %c\n",hd,l+1,letra(c1),l+1,letra(c2),d+1,l+1,letra(i));
                            z=1;
                            w[l][i][d]=0; //para tirar o numero como candidato
                        }
                    }
                }
                b1=cbloco(l, c1, &lb1, &cb1);
                b2=cbloco(l, c2, &lb2, &cb2);
                if(b1==b2)
                {
                    x=lb1;
                    y=cb1;
                    //limpar bloco
                    for(i=x; i<x+3; i++)
                    {
                        for(j=y; j<y+3; j++)
                        {
                            if((i==l && j==c1) || (i==l && j==c2))
                            {
                                continue;
                            }
                            //candidatos da celula
                            for(d=0;d<9;d++)
                            {
                                if(w[i][j][d]==0)
                                {
                                    continue;
                                }
                                if(w[i][j][d]==candy[d]) //se estiver num digito do par ai o candidato e retirado
                                {
                                    fprintf(stdout,"%s as celulas %d %c e %d %c com os mesmos candidatos %d, limpando ele da celula %d %c\n",hd,l+1,letra(c1),l+1,letra(c2),d+1,i+1,letra(j));
                                    z=1; //ocorreu deducao
                                    w[i][j][d]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //printf("saiu d3l\n");
    return z>0;
}
/* ---------------------------------------------------------------------- */
/* naked pair : column */
int d3c(int w[9][9][9])
{
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d3c: naked pair (column)";
    int l1, l2, c, d, i, f;
    //int lb1=0, lb2=0, cb1=0, cb2=0;
    int candy[9];
    //printf("entrou d3c\n");
    for(c=0; c<9; c++)
    {
        for(l1=0; l1<9; l1++)
        {
            if(totalcandy(w[l1][c])==1)
            {
                z=0;
                continue;
            }
            for(l2=0; l2<9; l2++)
            {
                if(totalcandy(w[l1][c])==1)
                {
                    z=0;
                    continue;
                }
                if(l1==l2) //significa que é a mesma célula
                {
                    continue; // c2++
                }
                if(totalcandy(w[l1][c]) != 2 || totalcandy(w[l2][c]) != 2) //o total de candidatos das duas células tem que ser igual a 2
                {
                    continue;
                }
                f=0; //flag da dedução 1
                for(d=0; d<9; d++)
                {
                    if(w[l1][c][d] != w[l2][c][d]) //testa para saber se os candidatos são iguais
                    {
                        f=1; //ocorreu dedução 1
                        break; //sai do for d++
                    }
                    //se os candidatos forem iguais tem que guardar em algum lugar
                    copycandy(w, l1, c, candy);
                }
                if(f==1) //f != 0
                {
                    continue; //troca célula c2, pois os candidatos não eram iguais (c2++)
                }
                //vai ter achado um par => limpar esses candidatos na coluna
                z=1; //ocorreu dedução 2
                for(i=0;i<9;i++)
                {
                    if(i==l1 || i==l2)
                    {
                        continue;
                    }
                    for(d=0;d<9;d++)
                    {
                        if(w[i][c][d]==0)
                        {
                            continue;
                        }
                        if(w[i][c][d]==candy[d])
                        {
                            fprintf(stdout,"%s as celulas %d %c e %d %c com os mesmos candidatos %d, limpando ele da celula %d %c\n",hd,l1+1,letra(c),l2+1,letra(c),d+1,i+1,letra(c));
                            z=1;
                            w[i][c][d]=0; //para tirar o número como candidato
                        }
                    }
                }
            }
        }
    }
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* naked pair : block */
int d3b(int w[9][9][9])
{
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d3b: naked pair (block)";
    int b, l, c, i, l1, c1, x, y, aux_l1, aux_l2, aux_c1, aux_c2;
    int EXIT=0,deu_certo=0;
    int candy[9], candy2[9];
    int ql=0, qc=0;

    //printsudoku(w);
    for(b=0;b<9;b++)
    {
        bloco(b, &ql, &qc);
        x=ql;
        y=qc;
        //printf("bloco = %d\n",b);
        //printf("ql = %d qc = %d\n",x,y);
        for(l=0;l<3;l++)
        {
            for(c=0;c<3;c++)
            {
                //printf("w1[%d][%d]\n",x+l,y+c);
                if(totalcandy(w[x+l][c+y])==2)
                {
                    //printf("totalcandy1[%d][%d] = %d\n",x+l,y+c,totalcandy(w[x+l][y+c]));
                    copycandy(w, x+l, y+c, candy);
                    //printf("depois da copycandy\n");
                    for(l1=0;l1<3;l1++)
                    {
                        for(c1=0;c1<3;c1++)
                        {
                            if(x+l1==x+l && y+c1==y+c)
                            {
                                continue;
                            }
                            //printf("w2[%d][%d]\n",x+l1,y+c1);
                            if(totalcandy(w[x+l1][c1+y])==2)
                            {
                                //printf("totalcandy2[%d][%d] = %d\n",x+l1,y+c1,totalcandy(w[x+l1][y+c1]));
                                copycandy(w, x+l1, y+c1, candy2);
                                if(verifica_candy(candy, candy2))
                                {
                           
                                    aux_l1=x+l;
                                    aux_c1=y+c;
                                    aux_l2=x+l1;
                                    aux_c2=y+c1;
                                    deu_certo=1;
                                    EXIT=1;
                                    break;
                                }
                            }
                        }
                        if(EXIT)
                        {
                        break; 
                        }
                    }
                    if(EXIT)
                    {
                    break; 
                    }
                }
            }
            if(EXIT)
            {
                break; 
            }
        }
        if(!deu_certo)
        {
            continue;
        }
        //printf("pair1[%d][%d]\n",aux_l1,aux_c1);
        //printf("pair2[%d][%d]\n",aux_l2,aux_c2);
        for(l=0;l<3;l++)
        {
            for(c=0;c<3;c++)
            {
                if((((x+l)==aux_l1) && ((y+c)==aux_c1)) || (((x+l)==aux_l2) && ((y+c)==aux_c2)))
                {
                    continue;
                }
                for(i=0;i<9;i++)
                {
                    if(w[aux_l1][aux_c1][i]==1)
                    {
                        EXIT=0;
                        deu_certo=0;
                        if(w[x+l][y+c][i]==0)
                        {
                            continue;
                        }
                        z=1;
                                    
                        fprintf(stdout,"%s as celulas %d %c e %d %c com os mesmos candidatos %d, limpando ele da celula %d %c\n",hd,l+1,letra(c),l1+1,letra(c1),i+1,x+l,letra(y+c));
                        //printf("apagou em w[%d][%d][%d]\n",x+l,y+c,i);
                        w[x+l][y+c][i]=0;
                    }
                }
            }
        }
    }
    return z;
}

/* ---------------------------------------------------------------------- */
/*verifica candy: verifica se os candidatos são iguais*/
int verifica_candy(int candy1[9], int candy2[9])
{
    int i=0, ct=0,z=0;
    for(i=0;i<9;i++)
    {
        if(candy1[i]==candy2[i])
        {
            ct++;
        }
    }
    if(ct==9)
    {
        z=1;
    }
    return z;
}

int d3_triplel(int w[9][9][9])
{
    int l,c,c1,c2,i,ct1=0,coluna,z=0;
    char *hd = "naked triple (line):";

    for(l=0;l<9;l++)
    {
        for(c=0;c<9;c++)
        {
            if(totalcandy(w[l][c])==3)
            {
                for(c1=0;c1<9;c1++)
                {
                    if(c1==c)
                    {
                        continue;
                    }
                    if(totalcandy(w[l][c1])>=2 && totalcandy(w[l][c1])<4)
                    {
                        for(i=0;i<9;i++)
                        {
                            if(w[l][c1][i]==w[l][c][i] && w[l][c1][i]==1)
                            {
                                ct1++;
                            }
                        }
                        if(totalcandy(w[l][c1])==3)
                        {
                            if(ct1!=3)
                            {
                                ct1=0;
                                continue;
                            }
                        }
                        if(totalcandy(w[l][c1])==2)
                        {
                            if(ct1!=2)
                            {
                                ct1=0;
                                continue;
                            }
                        }
                        ct1=0;
                        for(c2=0;c2<9;c2++)
                        {
                            if(c2==c || c2==c1)
                            {
                                continue;
                            }
                            if(totalcandy(w[l][c2])>=2 && totalcandy(w[l][c2])<4)
                            {
                                for(i=0;i<9;i++)
                                {
                                    if(w[l][c2][i]==w[l][c][i] && w[l][c2][i]==1)
                                    {
                                        ct1++;
                                    }
                                }
                                if(totalcandy(w[l][c2])==2)
                                {
                                    if(ct1!=2)
                                    {
                                        ct1=0;
                                        continue;
                                    }
                                }
                                if(totalcandy(w[l][c2])==3)
                                {
                                    if(ct1!=3)
                                    {
                                        ct1=0;
                                        continue;
                                    }
                                }
                                ct1=0;
                                for(coluna=0;coluna<9;coluna++)
                                {
                                    if(coluna==c || coluna==c1 || coluna==c2)
                                    {
                                        continue;
                                    }
                                    for(i=0;i<9;i++)
                                    {
                                        if(w[l][coluna][i]==0)
                                        {
                                            continue;
                                        }
                                        if(w[l][c][i]==1)
                                        {
                                            fprintf(stdout,"%s as celulas %d,%c, %d,%c e %d,%c com os mesmos candidatos %d, limpando ele da celula %d,%c\n",hd,l+1,letra(c),l+1,letra(c1),l+1,letra(c2),i+1,l+1,letra(coluna));
                                            z=1;
                                            w[l][coluna][i]=0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return z;
}

int d3_triplec(int w[9][9][9])
{
    int l,c,l1,l2,i,ct=0,linha,z=0;
    char *hd = "naked triple (column):";

    for(c=0;c<9;c++)
    {
        for(l=0;l<9;l++)
        {
            if(totalcandy(w[l][c])==3)
            {
                for(l1=0;l1<9;l1++)
                {
                    if(l1==l)
                    {
                        continue;
                    }
                    if(totalcandy(w[l1][c])>=2 && totalcandy(w[l1][c])<4)
                    {
                        for(i=0;i<9;i++)
                        {
                            if(w[l1][c][i]==w[l][c][i] && w[l1][c][i]==1)
                            {
                                ct++;
                            }
                        }
                        if(totalcandy(w[l1][c])==3)
                        {
                            if(ct!=3)
                            {
                                ct=0;
                                continue;
                            }
                        }
                        if(totalcandy(w[l1][c])==2)
                        {
                            if(ct!=2)
                            {
                                ct=0;
                                continue;
                            }
                        }
                        ct=0;
                        for(l2=0;l2<9;l2++)
                        {
                            if(l2==l || l2==l1)
                            {
                                continue;
                            }
                            if(totalcandy(w[l2][c])>=2 && totalcandy(w[l2][c])<4)
                            {
                                for(i=0;i<9;i++)
                                {
                                    if(w[l2][c][i]==w[l][c][i] && w[l2][c][i]==1)
                                    {
                                        ct++;
                                    }
                                }
                                if(totalcandy(w[l2][c])==2)
                                {
                                    if(ct!=2)
                                    {
                                        ct=0;
                                        continue;
                                    }
                                }
                                if(totalcandy(w[l2][c])==3)
                                {
                                    if(ct!=3)
                                    {
                                        ct=0;
                                        continue;
                                    }
                                }
                                ct=0;
                                for(linha=0;linha<9;linha++)
                                {
                                    if(linha==l || linha==l1 || linha==l2)
                                    {
                                        continue;
                                    }
                                    for(i=0;i<9;i++)
                                    {
                                        if(w[linha][c][i]==0)
                                        {
                                            continue;
                                        }
                                        if(w[l][c][i]==1)
                                        {
                                            fprintf(stdout,"%s as celulas %d,%c, %d,%c e %d,%c com os mesmos candidatos %d, limpando ele da celula %d,%c\n",hd,l+1,letra(c),l1+1,letra(c),l2+1,letra(c),i+1,linha+1,letra(c));
                                            z=1;
                                            w[linha][c][i]=0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return z;
}

int d3_tripleb(int w[9][9][9])
{
    int b,l,l1,l2,c,c1,c2,i,ct1=0,linha,coluna,z=0;
    int ql=0,qc=0;
    char *hd = "naked triple (block):";

    for(b=0;b<9;b++)
    {
        bloco(b,&ql,&qc);
        for(l=0;l<3;l++)
        {
            for(c=0;c<3;c++)
            {
                if(totalcandy(w[ql+l][qc+c])==3)
                {
                    for(l1=0;l1<3;l1++)
                    {
                        for(c1=0;c1<3;c1++)
                        {
                            if((qc+c1)==(qc+c) && (ql+l1)==(ql+l))
                            {
                                continue;
                            }
                            if(totalcandy(w[ql+l1][qc+c1])>=2 && totalcandy(w[ql+l1][qc+c1])<4)
                            {
                                for(i=0;i<9;i++)
                                {
                                    if(w[ql+l1][qc+c1][i]==w[ql+l][qc+c][i] && w[ql+l1][qc+c1][i]==1)
                                    {
                                        ct1++;
                                    }
                                }
                                if(totalcandy(w[ql+l1][qc+c1])==3)
                                {
                                    if(ct1!=3)
                                    {
                                        ct1=0;
                                        continue;
                                    }
                                }
                                if(totalcandy(w[ql+l1][qc+c1])==2)
                                {
                                    if(ct1!=2)
                                    {
                                        ct1=0;
                                        continue;
                                    }
                                }
                                ct1=0;
                                for(l2=0;l2<3;l2++)
                                {
                                    for(c2=0;c2<3;c2++)
                                    {
                                        if(((qc+c2)==(qc+c) && (ql+l2)==(ql+l)) || ((qc+c2)==(qc+c1) && (ql+l2)==(ql+l1)))
                                        {
                                            continue;
                                        }
                                        if(totalcandy(w[ql+l2][qc+c2])>=2 && totalcandy(w[ql+l2][qc+c2])<4)
                                        {
                                            for(i=0;i<9;i++)
                                            {
                                                if(w[ql+l2][qc+c2][i]==w[ql+l][qc+c][i] && w[ql+l2][qc+c2][i]==1)
                                                {
                                                    ct1++;
                                                }
                                            }
                                            if(totalcandy(w[ql+l2][qc+c2])==2)
                                            {
                                                if(ct1!=2)
                                                {
                                                    ct1=0;
                                                    continue;
                                                }
                                            }
                                            if(totalcandy(w[ql+l2][qc+c2])==3)
                                            {
                                                if(ct1!=3)
                                                {
                                                    ct1=0;
                                                    continue;
                                                }
                                            }
                                            ct1=0;
                                            for(linha=0;linha<3;linha++)
                                            {
                                                for(coluna=0;coluna<3;coluna++)
                                                {
                                                    if(((qc+coluna)==(qc+c) && (ql+linha)==(ql+l)) || ((qc+coluna)==(qc+c1) && (ql+linha)==(ql+l1)) || ((qc+coluna)==(qc+c2) && (ql+linha)==(ql+l2)))
                                                    {
                                                        continue;
                                                    }
                                                    for(i=0;i<9;i++)
                                                    {
                                                        if(w[ql+linha][qc+coluna][i]==0)
                                                        {
                                                            continue;
                                                        }
                                                        if(w[ql+l][qc+c][i]==1)
                                                        {
                                                            fprintf(stdout,"%s as celulas %d,%c, %d,%c e %d,%c com os mesmos candidatos %d, limpando ele da celula %d,%c\n",hd,ql+l+1,letra(qc+c),ql+l1+1,letra(qc+c1),ql+l2+1,letra(qc+c2),i+1,ql+linha+1,letra(qc+coluna));
                                                            z=1;
                                                            w[ql+linha][qc+coluna][i]=0;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return z;
}

/* ---------------------------------------------------------------------- */
/* hidden pair : line */
/* hidden pair: remove candidatos na celula do par, limpando-o, tornando-o naked pair */
int d4l(int w[9][9][9])
{
    int l,c,c1,i,c2, z=0;
    //printsudoku(w);
    //printf("entrou na d4\n");
    for(l=0;l<9;l++)
    {
        for(c=0;c<9;c++)
        {
            if(totalcandy(w[l][c])>1)
            {
                for(c1=0;c1<9;c1++)
                {
                    if(c1==c)
                    {
                        continue;
                    }
                    if(totalcandy(w[l][c1])>1)
                    {
                        if(verifica_pairl(w, l, c, c1))
                        {
                            for(i=0;i<9;i++)
                            {
                                for(c2=0;c2<9;c2++)
                                {
                                    if(c2==c || c2==c1)
                                    {
                                        continue;
                                    }
                                    if(w[l][c2][i]==w[l][c][i] || w[l][c2][i]==w[l][c1][i])
                                    {
                                        if(w[l][c][i]==0 && w[l][c1][i]==0)
                                        {
                                            continue;
                                        }
                                        z=1;
                                        fprintf(stdout,"hidden pairs/dupla escondida (linha): o par escondido de celulas %d %c e %d %c restringem %d, que nao pode em %d %c\n",l+1,letra(c),l+1,letra(c1),i+1,l+1,letra(c));
                                        //printf("apagado w[%d][%d][%d]\n",l,c,i);
                                        //printf("apagado w[%d][%d][%d]\n",l,c1,i);
                                        w[l][c][i]=0;
                                        w[l][c1][i]=0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //printsudoku(w);
    //printf("saida da d4\n");
    return z;
}
int verifica_pairl(int w[9][9][9], int l, int c, int c1)
{
    int coluna, i, z=0;
    int candy[9]={0}, candy2[9]={0};

    copycandy(w,l,c,candy);
    copycandy(w,l,c1,candy2);
    for(i=0;i<9;i++)
    {
        for(coluna=0;coluna<9;coluna++)
        {
            if(coluna==c || coluna==c1)
            {
                continue;
            }
            if((w[l][coluna][i]==candy[i] || w[l][coluna][i]==candy2[i]) && w[l][coluna][i]==1)
            {
                candy[i]=0;
                candy2[i]=0;
            }
        }
    }
    if(totalcandy(candy)==2 && totalcandy(candy2)==2)
    {
        z=1;
    }
    return z;
}
/* ---------------------------------------------------------------------- */
/* hidden pair : column */
int d4c(int w[9][9][9])
{
    int l,c,l1,i,l2, z=0;
    for(c=0;c<9;c++)
    {
        for(l=0;l<9;l++)
        {
            if(totalcandy(w[l][c])>1)
            {
                for(l1=0;l1<9;l1++)
                {
                    if(l1==l)
                    {
                        continue;
                    }
                    if(totalcandy(w[l1][c])>1)
                    {
                        if(verifica_pairc(w, c, l, l1))
                        {
                            for(i=0;i<9;i++)
                            {
                                for(l2=0;l2<9;l2++)
                                {
                                    if(l2==l || l2==l1)
                                    {
                                        continue;
                                    }
                                    if(w[l2][c][i]==w[l][c][i] || w[l2][c][i]==w[l1][c][i])
                                    {
                                        if(w[l][c][i]==0 && w[l1][c][i]==0)
                                        {
                                            continue;
                                        }
                                             fprintf(stdout,"hidden pairs/dupla escondida (linha): o par escondido de celulas %d %c e %d %c restringem %d, que nao pode em %d %c\n",l+1,letra(c),l1+1,letra(c),i+1,l+1,letra(c));
                                        z=1;
                                        w[l][c][i]=0;
                                        w[l1][c][i]=0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return z;
}
int verifica_pairc(int w[9][9][9], int c, int l, int l1)
{
    int linha, i, z=0;
    int candy[9]={0}, candy2[9]={0};

    copycandy(w,l,c,candy);
    copycandy(w,l1,c,candy2);
    for(i=0;i<9;i++)
    {
        for(linha=0;linha<9;linha++)
        {
            if(linha==l || linha==l1)
            {
                continue;
            }
            if((w[linha][c][i]==candy[i] || w[linha][c][i]==candy2[i]) && w[linha][c][i]==1)
            {
                candy[i]=0;
                candy2[i]=0;
            }
        }
    }
    if(totalcandy(candy)==2 && totalcandy(candy2)==2)
    {
        z=1;
    }
    return z;
}
/* ---------------------------------------------------------------------- */
/* hidden pair : block */
int d4b(int w[9][9][9])
{
    int l,l1,l2,c,c1,i,c2,z=0,b;
    int ql=0,qc=0;
    char *hd = "hidden pairs/dupla escondida (bloco): o par escondido de celulas ";

    for(b=0;b<9;b++)
    {
        bloco(b,&ql,&qc);
        for(l=0;l<3;l++)
        {
            for(c=0;c<3;c++)
            {
                if(totalcandy(w[ql+l][qc+c])>1)
                {
                    for(l1=0;l1<3;l1++)
                    {
                        for(c1=0;c1<3;c1++)
                        {
                            if((qc+c1)==(qc+c) && (ql+l1)==(ql+l))
                            {
                                continue;
                            }
                            if(totalcandy(w[ql+l1][qc+c1])>1)
                            {
                                if(verifica_pairb(w, ql+l, qc+c, ql+l1, qc+c1, b))
                                {
                                    for(i=0;i<9;i++)
                                    {
                                        for(l2=0;l2<3;l2++)
                                        {
                                            for(c2=0;c2<3;c2++)
                                            {
                                                if(((qc+c2)==(qc+c) && (ql+l2)==(ql+l)) || ((qc+c2)==(qc+c1) && (ql+l2)==(ql+l1)))
                                                {
                                                    continue;
                                                }
                                                if(w[ql+l2][qc+c2][i]==w[ql+l][qc+c][i] || w[ql+l2][qc+c2][i]==w[ql+l1][qc+c1][i])
                                                {
                                                    if(w[ql+l][qc+c][i]==0 && w[ql+l1][qc+c1][i]==0)
                                                    {
                                                        continue;
                                                    }
                                                    fprintf(stdout,"%s o par escondido de celulas %d%c e %d%c restringem %d, que nao pode em %d%c\n",hd,ql+l+1,letra(qc+c),ql+l1+1,letra(qc+c1),i+1,ql+l+1,letra(qc+c));
                                                    z=1;
                                                    w[ql+l][qc+c][i]=0;
                                                    w[ql+l1][qc+c1][i]=0;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return z;
}
int verifica_pairb(int w[9][9][9], int l, int c, int l1, int c1, int b)
{
    int linha, coluna, i, z=0, ql=0, qc=0;
    int candy[9]={0}, candy2[9]={0};

    copycandy(w,l,c,candy);
    copycandy(w,l1,c1,candy2);

    bloco(b, &ql, &qc);
    for(i=0;i<9;i++)
    {
        for(linha=0;linha<3;linha++)
        {
            for(coluna=0;coluna<3;coluna++)
            {
                if(((qc+coluna)==c && (ql+linha)==l) || ((qc+coluna)==c1 && (ql+linha)==l1))
                {
                    continue;
                }
                if((w[ql+linha][(qc+coluna)][i]==candy[i] || w[ql+linha][(qc+coluna)][i]==candy2[i]) && w[ql+linha][(qc+coluna)][i]==1)
                {
                    candy[i]=0;
                    candy2[i]=0;
                }
            }
        }
    }
    if(totalcandy(candy)==2 && totalcandy(candy2)==2)
    {
        z=1;
    }
    return z;
}
/* ---------------------------------------------------------------------- */
/* pointing candidates : dedo-duro : linha */
int d5l(int w[9][9][9])
{   
    int l, c, z=0, b, ql, qc;
    int x,y;
    //int candy[9], candy2[9];
    // int z; /* flag que indica se ocorreu deducao */
    char *hd="d5l: pointing pair (line)";
    //printsudoku(w);
    //printf("entrou na d5()\n");
    for(b=0; b<9; b++) //cada valor de "b" corresponde a um bloco na matriz do sudoku
    {
        //printf("Bloco: %d\n",b);
        bloco(b, &ql, &qc); //retorna as coordenadas superior esqueda do bloco passado
        x=ql;
        y=qc;
        //printf("ql = %d qc = %d\n",x,y);
        for(l=0; l<3; l++) //laÃ§o que roda as linhas dentro do bloco
        {
            for(c=0; c<3; c++) //laÃ§o que roda as colunas dentro do bloco
            {
                if(totalcandy(w[l+x][c+y])>1) //verifica se a celula tem mais de 1 candidato
                {
                    int point_i; //ponteiro que recebe numero do point candidate
                    if(found_pointl(w, l+x, c+y, y, &point_i))
                    {
                        //printf("totalcandy(w[%d][%d])= %d\n",l+x,c+y,totalcandy(w[l+x][c+y]));
                        //z=1;
                        int a = point_i;
                        //printf("A = %d\n",a);
                        int mesmobloco = ((c+y)/3)*3; //variavel que guarda a celula superior esqueda do bloco do point candidate
                        for(int k=0;k<9;k++)
                        {
                            if(((k/3)*3)==mesmobloco) //verifica se a coluna "K" estÃ¡ dentro do bloco do point candidate
                            {
                                continue;
                            }
                            if(w[l+x][k][a]==w[l+x][c+y][a]) //verifica se a celula na coluna "k" contem o mesmo candidato da celula dentro do bloco
                            {
                               // printf("apagou em w[%d][%d][%d]\n",l+x,k,a);
                               // printsudoku(w);
                               // printf("Indentificado: w[%d][%d][%d]\n",l+x,c+y,a);
                               // printf("totalcandy = %d\n",totalcandy(w[l+x][c+y]));
                               // printf("Limpado: w[%d][%d][%d]\n",l,k,a);
                                if(w[l+x][k][a]==0)
                                {
                                    continue;
                                }
                                //printf("apagou em w[%d][%d][%d]\n",l+x,k,a);
                                z=1;
                                fprintf(stdout,"%s o candidato %d do setor %d restringe o restante da linha, e por isso nao pode em %i %c\n",hd,a+1,b+1,l+x,letra(k));
                                w[l+x][k][a]=0;
                            }
                        }
                        //printsudoku(w);
                    }
                }
            }
        }
    }    
    
    return z>0;
}
/* encontra os candidatos point na mesma linha do bloco, retorna verdadeiro caso exista um */
int found_pointl(int w[9][9][9], int l, int c0, int qc, int *c2)
{
    int i,j,k,ct=0,z=0,U;
    int linha0,coluna0,coord_L,coord_C;
    cbloco(l,c0,&coord_L,&coord_C);
    linha0=coord_L;
    coluna0=coord_C;
    for(i=0;i<9;i++) //candidatos
    {
        for(j=0;j<3;j++) //coluna
        {
            if((qc+j)==c0)
            {
                continue;
            }
            //  && totalcandy(w[l][qc+j])>1
            if(w[l][c0][i]==w[l][qc+j][i] && w[l][c0][i]==1 && totalcandy(w[l][qc+j])>1) //se o  igual ao analidaso
            {
                U=qc+j; //variavel auxiliar que guarda o valor da coluna "qc+j"
                ct++; //contador recebe 1 unidade
            }
        }
        if(ct==0) //se contador for 0 nao tem tenhum candidato igual na linha e tenta outro
        {
            continue;
        }
        for(k=0;k<3;k++) //vai percorrer todo o bloco pra ter certeza que o candidato so aparece 2 vezes
        {
            for(j=0;j<3;j++)
            {
                if((linha0+k==l && coluna0+j==c0) || (linha0+k==l && coluna0+j==U)) //pula a verificacao caso seja as coordenadas ja analisadas
                {
                    continue;
                }
                if(w[l][c0][i]==w[linha0+k][coluna0+j][i]) //se achar um terceiro candidato igual, zera o contador e tenta outro
                {
                    ct=0;
                    continue;
                }
            }
        }
        if(ct==1) //se no final o contador marcar 1 eh porque so tem 2 candidatos e eles sao point
        {
            //printf("point encontrado entre w[%d][%d][%d] e w[%d][%d][%d]\n",l,c0,i,l,U,i);
            z=1; //flag para retornar verdadeiro caso seja
            *c2=i; //retorna o numero do candidato
            //printf("C2 = %d\n",i);
            break;
        }
    }

    return z;
}

/* ---------------------------------------------------------------------- */
/* pointing candidates : dedo-duro : coluna */
int d5c(int w[9][9][9])
{
    int l, c, z=0, b, ql, qc;
    int x,y;
    //int candy[9], candy2[9];
    // int z; /* flag que indica se ocorreu deducao */
    char *hd="d5l: pointing pair (column)";
    //printsudoku(w);
    //printf("entrou na d5()\n");
    for(b=0; b<9; b++) //cada valor de "b" corresponde a um bloco na matriz do sudoku
    {
        //printf("Bloco: %d\n",b);
        bloco(b, &ql, &qc); //retorna as coordenadas superior esqueda do bloco passado
        x=ql;
        y=qc;
        //printf("ql = %d qc = %d\n",x,y);
        for(c=0; c<3; c++) //laÃ§o que roda as linhas dentro do bloco
        {
            for(l=0; l<3; l++) //laÃ§o que roda as colunas dentro do bloco
            {
                if(totalcandy(w[l+x][c+y])>1) //verifica se a celula tem mais de 1 candidato
                {
                    int point_i; //ponteiro que recebe numero do point candidate
                    if(found_pointc(w, l+x, c+y, x, &point_i))
                    {
                        //printf("totalcandy(w[%d][%d])= %d\n",l+x,c+y,totalcandy(w[l+x][c+y]));
                        //z=1;
                        int a = point_i;
                        //printf("A = %d\n",a);
                        int mesmobloco = ((x+l)/3)*3; //variavel que guarda a celula superior esqueda do bloco do point candidate
                        for(int k=0;k<9;k++)
                        {
                            if(((k/3)*3)==mesmobloco) //verifica se a coluna "K" estÃ¡ dentro do bloco do point candidate
                            {
                                continue;
                            }
                            if(w[k][c+y][a]==w[l+x][c+y][a]) //verifica se a celula na coluna "k" contem o mesmo candidato da celula dentro do bloco
                            {
                               // printf("apagou em w[%d][%d][%d]\n",l+x,k,a);
                               // printsudoku(w);
                               // printf("Indentificado: w[%d][%d][%d]\n",l+x,c+y,a);
                               // printf("totalcandy = %d\n",totalcandy(w[l+x][c+y]));
                               // printf("Limpado: w[%d][%d][%d]\n",l,k,a);
                                if(w[k][c+y][a]==0)
                                {
                                    continue;
                                }
                                fprintf(stdout,"%s o candidato %d do setor %d restringe o restante da coluna, e por isso nao pode em %i %c\n",hd,a+1,b+1,k+1,letra(c+y));
                                //printf("apagou em w[%d][%d][%d]\n",l+x,k,a);
                                z=1;
                                w[k][c+y][a]=0;
                            }
                        }
                    //  printsudoku(w);
                    }
                }
            }
        }
    }

    return z>0;
}
/* encontra os candidatos point na mesma linha do bloco, retorna verdadeiro caso exista um */
int found_pointc(int w[9][9][9], int l, int c0, int ql, int *c2)
{
    int i,j,k,ct=0,z=0,U;
    int linha0,coluna0,coord_L,coord_C;
    cbloco(l,c0,&coord_L,&coord_C);
    linha0=coord_L;
    coluna0=coord_C;
    for(i=0;i<9;i++) //candidatos
    {
        for(j=0;j<3;j++) //linha
        {
            if((ql+j)==l)
            {
                continue;
            }
            //  && totalcandy(w[l][ql+j])>1
            if(w[l][c0][i]==w[ql+j][c0][i] && w[l][c0][i]==1 && totalcandy(w[ql+j][c0])>1) //se o  igual ao analidaso
            {
                U=ql+j; //variavel auxiliar que guarda o valor da coluna "ql+j"
                ct++; //contador recebe 1 unidade
            }
        }
        if(ct==0) //se contador for 0 nao tem tenhum candidato igual na coluna e tenta outro
        {
            continue;
        }
        for(j=0;j<3;j++) //vai percorrer todo o bloco pra ter certeza que o candidato so aparece 2 vezes
        {
            for(k=0;k<3;k++)
            {
                if((linha0+k==l && coluna0+j==c0) || (coluna0+j==c0 && linha0+k==U)) //pula a verificacao caso seja as coordenadas ja analisadas
                {
                    continue;
                }
                if(w[l][c0][i]==w[linha0+k][coluna0+j][i]) //se achar um terceiro candidato igual, zera o contador e tenta outro
                {
                    ct=0;
                    continue;
                }
            }
        }
        if(ct==1) //se no final o contador marcar 1 eh porque so tem 2 candidatos e eles sao point
        {
            //printf("point encontrado entre w[%d][%d][%d] e w[%d][%d][%d]\n",l,c0,i,l,U,i);
            z=1; //flag para retornar verdadeiro caso seja
            *c2=i; //retorna o numero do candidato
            //printf("C2 = %d\n",i);
            break;
        }
    }

    return z;
}
/* ---------------------------------------------------------------------- */
/* claiming candidate : exigente : line */
int d6l(int w[9][9][9])
{
    int z=0; /* flag que indica se ocorreu deducao */
    int l, c1,c2, d, f, b, x1,y1,x2,y2,lb,cb,
        ls1=0,
        cs1=0;
    char *hd="d6l: claiming candidate (line)";

    //printsudoku(w);
    for( l = 0; l < 9; l++)
    {
        for( c1 = 0; c1 < 9; c1++)
        {
            if(totalcandy(w[l][c1]) == 1)
                continue;
            for(d = 0; d < 9; d++)
            {
                if(w[l][c1][d]==0)
                    continue;

                f = 0;

                //printf("foi \n");
                //printf("w[%i][%i][%i] = %i\n\n",l,c1,d,w[l][c1][d]);
                //copycandy(w, l, c, candy);
                b = cbloco(l, c1, &ls1, &cs1);
                x1 = ls1;
                y1 = cs1; //y1 foi apagado por nao ser usado no decorrer da funcao//intf("foi \n");
                //printf("w[%i][%i][%i] = %i\n\n",l,c1,d,w[l][c1][d]);

                for(c2 = 0; c2 < 9; c2++)
                {
                    //printf("w[%i][%i][%i] = %i\n",l,c2,d,w[l][c2][d]);

                    if(cbloco(l,c2,&x2,&y2) == b)
                        continue;
                    //printf("w[%i][%i][%i] = %i\n",l,c1,d,w[l][c1][d]);
                    //printf("w[%i][%i][%i] = %i\n\n",l,c2,d,w[l][c2][d]);
                    //printf("%i e %i com %i e %i\n",x1,y1,x2,y2);
                    //peguei 2 culunas de blocos diferentes
                    if(w[l][c2][d] == 1)
                    {
                        f=1;
                        break;
                    }

                    //printf("w[%i][%i][%i] = %i\n",l,c1,d,w[l][c1][d]);
                    //printf("w[%i][%i][%i] = %i\n\n",l,c2,d,w[l][c2][d]);
                }
                if(f == 0)
                {
                    for(lb = x1;lb < x1+3;lb++)
                    {
                        for(cb = y1;cb < y1+3;cb++)
                        {
                            if(l == lb)
                            {
                                continue;
                            }
                            if(w[lb][cb][d] == 1)
                            {
                                fprintf(stdout," %s o candidato %d da celula %i %c restringe o restante do bloco %i, por isso nao pode em %i %c\n",hd,d+1,l+1,letra(c1),b,lb+1,letra(cb));
                                z=1;
                            }
                            //printsudoku(w);
                            //printf("w[%i][%i][%i] = %i\n\n\n",l,c1,d,w[l][c1][d]);
                            w[lb][cb][d] = 0;
                        }
                    }
                }
            }
        }
    }
    return z;
}
/* ---------------------------------------------------------------------- */
/* claiming candidate : exigente : column */
int d6c(int w[9][9][9])
{
    int z=0;
    int c,l1,l2,d,f,b,x1,y1,x2,y2,lb,cb,
        ls1=0,
        cs1=0;
    char *hd = "d6l: claiming candidate (coluna)";

    //printsudoku(w);

    for(c = 0;c < 9;c++)
    {
        for(l1 = 0;l1 < 9;l1++)
        {
            if(totalcandy(w[l1][c]) == 1)
            {
                continue;
            }
            for(d = 0;d < 9;d++)
            {
                if(w[l1][c][d] == 0)
                {
                    continue;
                }

                f=0;

                b = cbloco(l1,c,&ls1,&cs1);
                x1 = ls1;
                y1 = cs1;

                for(l2 = 0;l2 < 9; l2++)
                {
                    if(cbloco(l2,c,&x2,&y2) == b)
                    {
                        continue;
                    }

                    if(w[l2][c][d] == 1)
                    {
                        f=1;
                        break;
                    }
                }

                if(f == 0)
                {
                    for(cb = y1;cb < y1+3; cb++)
                    {
                        for(lb = x1;lb < x1+3; lb ++)
                        {
                            if(c == cb)
                            {
                                continue;
                            }
                            if(w[lb][cb][d] == 1)
                            {
                                fprintf(stdout," %s o candidato %d da celula %i %c restringe o restante do bloco %i, por isso nao pode em %i %c\n",hd,d+1,l1+1,letra(c),b,lb+1,letra(cb));
                                z=1;
                            }
                            //printsudoku(w);
                            //printf("w[%i][%i][%i] = %i\n\n\n",l1,c,d,w[l1][c][d])
                            w[lb][cb][d] = 0;
                        }
                    }
                }
            }
        }
    }

    return z;
}

/* ---------------------------------------------------------------------- */
/* x-wing */
int d7l(int w[9][9][9])
{
    int z = 0; /* flag que indica se ocorreu deducao */
    char *hd="d7l: x-wing (line)";
    int l1,l2, /* variaveis para as linhas l1 e l2 */
        l, /* variavel para a limpeza das colunas */
        c1,c2, /* variaveis para percorrer as colunas da l1 */
        c3, /* variavel para percorrer as celulas adjacentes depois da coluna c2 na linha l1 */
        c4, /* variavel para percorrer todas as celulas da linha 2 */
        d, /* variavel para percorrer todos os candidatos */
        f,a, /* flag para ver a continuaçao da linha l1 e para a linha l2 */
        sum=0; /* variavel para somar todos os números que estão sendo limpados */


    //printsudoku(w);
    for(l1=0;l1<9;l1++)
        for(c1=0;c1<8;c1++)
            for(c2=c1+1;c2<9;c2++)
                for(d=0;d<9;d++)
                  { 
                    /* vendo se as celulas (l1,c1) e (l1,c2) tem o mesmo candidato */
                    if(w[l1][c1][d] != w[l1][c2][d] || w[l1][c1][d] == 0)
                        continue;
                   // printf("celulas (%i,%i) e (%i,%i) tem os mesmos candidatos %i\n\n",l1,c1,l1,c2,d);

                    f=0;
                    /* laço para percorrer o que tem depois da celula (l1,c2) */
                    for(c3=0;c3<9;c3++)
                    {    
                        if(c3 == c1 || c3 == c2)
                            continue;

                        if(w[l1][c2][d] == w[l1][c3][d])
                        {
                            f=1;
                            continue;
                        }
                    }
                    /* se a celula (l1,c2) tiver o mesmo candidato da celula (l1,c3) entao as celulas nao servem para o x-wing, entao a f vai valer 1 */

                    if(f == 0)
                    { 
                    //printf("celulas (%i,%i) e (%i,%i) tem os candidatos %i\n\n",l1,c1,l1,c2,d);
                        /* vendo nas linhas abaixo da linha l1 nas mesmas colunas */
                        for(l2=0;l2<9;l2++)
                        {
                            if(l2 == l1)
                                continue;

                            if(w[l1][c1][d] != w[l2][c1][d] || w[l1][c2][d] != w[l2][c2][d])
                                continue;
                            //printf("celulas (%i,%i),(%i,%i),(%i,%i),(%i,%i) tem os candidatos %i\n\n",l1,c1,l1,c2,l2,c1,l2,c2,d);
                            /* achou 4 celulas com mesmos candidatos : (l1,c1),(l1,c2),(l2,c1),(l2,c2) */

                       /*     printf("l1|l1|l2|l2\n");
                            printf("c1|c2|c1|c2\n");
                            for(int a=0;a<9;a++)
                            {
                                printf("|%i|%i|%i|%i|\n",w[l1][c1][a],w[l1][c2][a],w[l2][c1][a],w[l2][c2][a]);
                            }
                            printf("\n\n\n");*/
                            a=0;
                            for(c4=0;c4<9;c4++)
                            { 
                                /* laço para percorer a linha 2 para ver se os unicos candidatos sao os candidatos das celulas (l2,c1) e (l2,c2) */
                                if(c4 == c1 || c4 == c2)
                                    continue;

                                /* se tiver na linha 2 alguma celula com o mesmo candidato das celulas (l2,c1) e (l2,c2) nao serve para o x-wing e pula para a proxima linha */
                                if(w[l2][c1][d] == w[l2][c4][d])
                                  {
                                    a=1;
                                    continue;
                                 }
                             }
                       
                            //printf("celulas (%i,%i),(%i,%i),(%i,%i),(%i,%i) tem os candidatos %i\n\n",l1,c1,l1,c2,l2,c1,l2,c2,d);
                                /* quadrado x-wing formado apartir daqui, limpar as colunas c1 e c2 dos candidatos d */
                            //printf("celulas (%i,%i) e (%i,%i) tem os candidatos %i\n\n",l1,c1,l1,c2,d);
                            if(a == 0)
                            {
                                //printf("celulas (%i,%i) = %i,(%i,%i) = %i,(%i,%i) = %i,(%i,%i) = %i tem os candidatos %i\n\n",l1,c1,w[l1][c1][d],l1,c2,w[l1][c2][d],l2,c1,w[l1][c2][d],l2,c2,w[l2][c2][d],d);
                                //printf("celulas (%i,%i),(%i,%i),(%i,%i),(%i,%i) tem os candidatos %i\n\n",l1,c1,l1,c2,l2,c1,l2,c2,d);
                                for(l=0;l<9;l++)
                                   {
                                    if(l == l1 || l == l2)
                                        continue;
                                    if(w[l][c1][d] == 1)
                                    {
                                        fprintf(stdout,"%s o candidato %d das celulas %i %c,%i %c,%i %c e %i %c restringe a coluna %c, por isso nao pode em %i %c \n",hd,d+1,l1+1,letra(c1),l1+1,letra(c2),l2+1,letra(c1),l2+1,letra(c2),letra(c1),l+1,letra(c1));
                                    }
                                    if(w[l][c2][d] == 1)
                                    {
                                        fprintf(stdout,"%s o candidato %d das celulas %i %c,%i %c,%i %c e %i %c restringe a coluna %c, por isso nao pode em %i %c \n",hd,d+1,l1+1,letra(c1),l1+1,letra(c2),l2+1,letra(c1),l2+1,letra(c2),letra(c2),l+1,letra(c2));
                                    }
                                    sum += w[l][c1][d]+w[l][c2][d];
                                    //printf("(%i,%i,%i)=%i\n(%i,%i,%i) = %i\nsoma das colunas = %i\n",l,c1,d,w[l][c1][d],l,c2,d,w[l][c2][d],sum);
                                    w[l][c1][d] = 0;
                                    w[l][c2][d] = 0;
                                }
                                //printsudoku(w);
                                /* para o programa nao ficar preso eternamente a um caso ja visto antes, somo as duas colunas e vejo se a soma for 0, se for 0 ou ela ja foi limpa ou realmente nao tem nenhum numero para limpar, nos dois casos o que acontece e ele ir pro proximo candidato */
                                if(sum == 0)
                                    break;

                                /* a única forma de chegar aqui é se passar por todas as condições e se passar todas as condições a dedução foi feita e o programa retorna 1 pois ocorreu uma dedução */
                                z = 1;
                             }else
                                continue;
                         }
                        
                    }else
                        continue;
                 }
                
    return z;
}
/* se rodar todas as celulas e todas as possibilidades e não tiver nenhum candidato x-wing então a dedução não foi feita e o programa retorna 0 */

/* ---------------------------------------------------------------------- */
/* x-wing */
int d7c(int w[9][9][9])
{
    int z=0; /* flag que indica se ocorreu deducao */
    char *hd="d7c: x-wing (column)";
    int c1,c2, /* variaveis para a coluna c1 e c2 */
        c, /* variavel para a limpeza das linhas */
        l1,l2, /* variaveis para percorrer as linhas de c1 */
        l3, /* variavel para percorrer as celulas adjacentes depois da linha l2 na coluna c1 */
        l4, /* variavel para percorrer todas as celulas da coluna c2 */
        d, /* variavel para percorrer todos os candidatos */
        f,a, /* flag para ver a continuaçao da coluna c1 e para a coluna c2 */
        sum = 0;

    //printsudoku(w);
    for(c1=0;c1<9;c1++)
        for(l1=0;l1<8;l1++)
            for(l2=l1+1;l2<9;l2++)
                for(d=0;d<9;d++)
                {
                    //printf("dentro do laço");
                    /* vendo se as celulas (l1,c1) e (l2,c1) tem o mesmo candidato */
                    //printf("(%i,%i)  = %i,(%i,%i) = %i",l1,c1,l2,c1,d);
                    if(w[l1][c1][d] != w[l2][c1][d] || w[l1][c1][d] == 0)
                        continue;
                    //printf("(%i,%i)=%i,(%i,%i)=%i tem os candidatos %i\n",l1,c1,w[l1][c1][d],l2,c1,w[l2][c1][d],d);

                    f=0;
                    /* laço para percorrero que tem depois da celula (l2,c1) */
                    for(l3=0;l3<9;l3++)
                    { 
                    if(l3 == l1 || l3 == l2)
                        continue;

                    if(w[l2][c1][d] == w[l3][c1][d])
                    {
                        f=1;
                        continue;
                    }
                    }
                /* se a celula (l2,c1) tiver o mesmo candidato da celula (l3,c1) entao as celulas nao servem para o x-wing, entao f vai valer 1 */

                if(f == 0)
                {
                    /* vendo nas colunas adiante da c1 nas mesmas linhas l1 e l2 */
                    for(c2=0;c2<9;c2++)
                    {
                        if(c2 == c1)
                            continue;

                        if(w[l1][c1][d] != w[l1][c2][d] || w[l2][c1][d] != w[l2][c2][d])
                            continue;

                    /* achou 4 celulas com mesmos candidatos : (l1,c1),(l1,c2),(l2,c1),(l2,c2) */
                    a=0;
                    for(l4=0;l4<9;l4++)
                    {
                        /* laço para percorrer todas as linhas da coluna c2 */

                        if(l4 == l1 || l4 == l2)
                            continue;

                        /* se na coluna c2 tiver algum outro candidato se não os das celulas (l1,c2) e (l2,c2) */
                        if(w[l1][c2][d] == w[l4][c2][d])
                        {
                            a=1;
                            continue;
                        }
                    }
                    //printf("celulas (%i,%i) = %i,(%i,%i) = %i,(%i,%i) = %i,(%i,%i) = %i tem os candidatos %i\n\n",l1,c1,w[l1][c1][d],l1,c2,w[l1][c2][d],l2,c1,w[l1][c2][d]     ,l2,c2,w[l2][c2][d],d);
                        /* quadrado x-wing formado apartir daqui, limpar linhas l1 e l2 dos candidatos d */
                    
                        if(a == 0)
                        { 
                            //printf("celulas (%i,%i) = %i,(%i,%i) = %i,(%i,%i) = %i,(%i,%i) = %i tem os candidatos %i\n\n",l1,c1,w[l1][c1][d],l2,c1,w[l2][c1][d],l1,c2,w[l1][c2][d],l2,c2,w[l2][c2][d],d);
                            for(c=0;c<9;c++)
                            { 
                                if(c == c1 || c == c2)
                                    continue;

                                if(w[l1][c][d] == 1)
                                {
                                    fprintf(stdout,"%s o candidato %d das celulas %i %c,%i %c,%i %c e %i %c restringe a linha %d, por isso nao pode em %i %c \n",hd,d+1,l1+1,letra(c1),l2+1,letra(c1),l1+1,letra(c2),l2+1,letra(c2),l1+1,l1+1,letra(c));
                                }
                                if(w[l2][c][d] == 1)
                                {
                                    fprintf(stdout,"%s o candidato %d das celulas %i %c,%i %c,%i %c e %i %c restringe a linha %d, por isso nao pode em %i %c \n",hd,d+1,l1+1,letra(c1),l2+1,letra(c1),l1+1,letra(c2),l2+1,letra(c2),l2+1,l2+1,letra(c));
                                }
                                sum += w[l1][c][d] + w[l2][c][d];
                                w[l1][c][d] = 0;
                                w[l2][c][d] = 0;
                            }
                            //printsudoku(w);
                            if(sum == 0)
                                break;

                            z = 1;

                        }else
                            continue;
                    }
                }else
                    continue;
                }
return z;

}

int d8(int w[9][9][9])
{
    int l,c,l1,c1,l2,c2,l3,c3,i,x=0,y=0,ct1=0,ct2=0,ct3=0,z=0,k=0;
    char *hd = "d8: xy-wing (linha coluna bloco)";

    for(l=0;l<9;l++)
    {
        for(c=0;c<9;c++)
        {
            if(totalcandy(w[l][c])==2)
            {
                for(l1=0;l1<9;l1++)
                {
                    for(c1=0;c1<9;c1++)
                    {
                        if(totalcandy(w[l1][c1])==2 && enxergar(l,c,l1,c1)>0 && (c!=c1 || l!=l1))
                        {
                            for(l2=0;l2<9;l2++)
                            {
                                for(c2=0;c2<9;c2++)
                                {
                                    if(totalcandy(w[l2][c2])==2 && enxergar(l,c,l2,c2)>0 && (c!=c2 || l!=l2) && (c1!=c2 || l1!=l2) && enxergar(l1,c1,l2,c2)==0)
                                    {
                                        for(i=0;i<9;i++)
                                        {
                                            if(w[l][c][i]==w[l1][c1][i] && w[l][c][i]==1)
                                            {
                                                ct1++;
                                                x=i;
                                            }
                                            if(w[l][c][i]==w[l2][c2][i] && w[l][c][i]==1)
                                            {
                                                ct2++;
                                                y=i;
                                            }
                                            if(w[l1][c1][i]==w[l2][c2][i] && w[l1][c1][i]==1)
                                            {
                                                ct3++;
                                                k=i;
                                            }
                                        }
                                        if(ct1==1 && ct2==1 && ct3==1 && (x!=y) && (k!=x) && (k!=y))
                                        {
                                            for(l3=0;l3<9;l3++)
                                            {
                                                for(c3=0;c3<9;c3++)
                                                {
                                                    if((c!=c3 || l!=l3) && (c1!=c3 || l1!=l3) && (c2!=c3 || l2!=l3) && enxergar(l1,c1,l3,c3)>0 && enxergar(l2,c2,l3,c3)>0 && totalcandy(w[l3][c3])>=2)
                                                    {
                                                        fprintf(stdout,"%s o candidato %d comum as asas (%d,%c) e (%d,%c) vai ser limpando da celula (%d,%c)\n",hd,k+1,l1+1,letra(c1),l2+1,letra(c2),l3+1,letra(c3));
                                                        w[l3][c3][k]=0;
                                                        z=1;
                                                    }
                                                }
                                            }
                                        }
                                        ct1=0;
                                        ct2=0;
                                        ct3=0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return z;
}

/* ---------------------------------------------------------------------- */

/* encontra o par da celula passada na linha, caso não tenha, retorna false */
int found_pairl(int w[9][9][9], int l, int c0, int *c2)
{
int c, i, z=0, ct=0;

for(c=0;c<9;c++)
{
    if(c==c0)
    {
        continue;
    }
    for(i=0;i<9;i++)
    {
        if(w[l][c0][i]==w[l][c][i])
        {
            ct++;
        }
    }
    if(ct==2)
    {
        z=1;
        *c2 = (int)c;
        break;
    }
    ct=0;
}
return z;
}

/* encontra o par da celula passada na coluna, caso não tenha, retorna false */ 
int found_pairc(int w[9][9][9], int c, int l0, int *l2)
{
int l, i, z=0, ct=0;

for(l=0;l<9;l++)
{
    if(l==l0)
    {
        continue;
    }
    for(i=0;i<9;i++)
    {
        if(w[l0][c][i]==w[l][c][i])
        {
            ct++;
        }
    }
    if(ct==2)
    {
        z=1;
        *l2= (int)l;
        break;
    }
}

return z;
}

/* encontra o par da celula passada no bloco, caso não tenha, retorna false */
int found_pairb(int w[9][9][9], int l0, int c0, int *l2, int *c2)
{
int l ,c , i, z=0, ct=0;
for(l=0;l<3;l++)
{
    for(c=0;c<3;c++)
    {
        if(l==l0 && c==c0)
        {
            continue;
        }
        for(i=0; i<9; i++)
        {
            if(w[l0][c0][i]==w[l0+l][c0+c][i])
            {
                ct++;
            }
        }
        if(ct==2)
        {
            z=1;
            *l2= (int)l;
            *c2= (int)c;
            break;
        }
    }
}

return z;
}

int enxergar(int l, int c, int l1, int c1)
{
    int b, b1,
    l0=0,c0=0,z=0;

    if(l == l1)
        z=1;
    if(c == c1)
        z=2;
    b=cbloco(l,c,&l0,&c0);
    b1=cbloco(l1,c1,&l0,&c0);
    if(b == b1)
        z=3;

    return z;
}
char letra(int c)
{
    return (c== 0?c='a':c==1?c='b':c==2?c='c':c==3?c='d':c==4?c='e':c==5?c='f':c==6?c='g':c==7?c='h':c==8?c='i':c+1);
}
int d9l (int w[9][9][9])
{
    int z=0;
    char *hd = "d9l : Fined X-Wing linha";
    int l1,l2, // variaveis para percorrer as 2 linhas fixas da x-wing
        l, // variaveis para a limpeza
        c1,c2, // variaveis para percorrer as 2 colunas fixas da x-wing
        c3, // variavel para verificar a linha 1
        c4, // variavel para verificar a linha 2
        d, // variavel para verificar todos os candidatos
        ct=0,ct2=0,
        f,a,
        cr , // variavel da coluna que é a rebarba
        rebrl1 = 0,rebrl2 = 0; //variavel da linha da rebarba

     for(l1=0;l1<9;l1++)
         for(c1=0;c1<8;c1++)
             for(c2=c1+1;c2<9;c2++)
                for(d=0;d<9;d++)
                 {
                     if(w[l1][c1][d] != w[l1][c2][d] || w[l1][c1][d] == 0)
                         continue;

                    
                     ct=0;
                     f=0;
                     for(c3=0;c3<9;c3++)
                     {
                         if(c1 == c3 || c2 == c3)
                             continue;

                         if(w[l1][c3][d] == w[l1][c1][d] && ct == 0)
                         {
                             cr=c3;
                             rebrl1 = 1;
                             ct=1;
                             continue;
                         }
                         if(w[l1][c3][d] == w[l1][c1][d])
                             f=1;

                     }
                     if(f==0)
                     {
                         for(l2=0;l2<9;l2++)
                         {
                             if(l2 == l1)
                                 continue;

                             if(w[l1][c1][d] != w[l2][c1][d] || w[l1][c2][d] != w[l2][c2][d])
                                 continue;

                             a=0;
                             for(c4=0;c4<9;c4++)
                             {
                                 if(c4 == c1 || c4 == c2)
                                     continue;

                                 if(rebrl1 == 0)
                                 {
                                     if(w[l2][c4][d] == w[l2][c1][d] && ct2 == 0)
                                     {
                                         cr=c4;
                                         rebrl2=1;
                                         ct2=1;
                                         continue;
                                     }
                                     if(w[l2][c4][d] == w[l2][c1][d])
                                         a=1;
                                 }
                                 if(rebrl1 == 1)
                                 {
                                     if(w[l2][c4][d] == w[l2][c1][d])
                                     {
                                         a=1;
                                     }
                                 }
                             }
                             if(a==0)
                             {
                                 for(l=0;l<9;l++)
                                 {
                                     if(l1==l || l2==l)
                                         continue;

                                     if(rebrl1 == 1)
                                     {
                                         if(enxergar(l,c1,l1,cr)  && w[l][c1][d] == 1)
                                         {
                                             w[l][c1][d] = 0;
                                             z=1;
                                             fprintf(stdout,"%s as celulas %i %c,%i %c,%i %c e %i %c formam um x-wing imperfeito, pois a celula %i %c não deixa, e essa celula rebarba enxerga o candidato %d na celula da coluna da x-wing, e assim retirando o candidato %d da celula %i %c\n",hd,l1+1,letra(c1),l1+1,letra(c2),l2+1,letra(c1),l2+1,letra(c2),l1+1,letra(cr),d+1,d+1,l+1,letra(c1));
                                         }
                                         if(enxergar(l,c2,l1,cr)  && w[l][c2][d] == 1)
                                         {
                                             w[l][c2][d] = 0;
                                             z=1;
                                             fprintf(stdout,"%s as celulas %i %c,%i %c,%i %c e %i %c formam um x-wing imperfeito, pois a celula %i%c não deixa, e essa celula rebarba enxerga o candidato %d na celula da coluna da x-wing, e assim retirando o candidato %d da celula %i %c\n",hd,l1+1,letra(c1),l1+1,letra(c2),l2+1,letra(c1),l2+1,letra(c2),l1+1,letra(cr),d+1,d+1,l+1,letra(c2));
                                         }
                                     }
                                     if(rebrl2 == 1)
                                     {
                                         if(enxergar(l,c1,l2,cr)  && w[l][c1][d] == 1)
                                         {
                                             w[l][c1][d] = 0;
                                             z=1;
                                             fprintf(stdout,"%s as celulas %i %c,%i %c,%i %c e %i %c formam um x-wing imperfeito, pois a celula %i%c não deixa, e essa celula rebarba enxerga o candidato %d na celula da coluna da x-wing, e assim retirando o candidato %d da celula %i %c\n",hd,l1+1,letra(c1),l1+1,letra(c2),l2+1,letra(c1),l2+1,letra(c2),l2+1,letra(cr),d+1,d+1,l+1,letra(c1));
                                         }
                                         if(enxergar(l,c2,l2,cr)  && w[l][c2][d] == 1)
                                         {
                                             w[l][c2][d] = 0;
                                             z=1;
                                             fprintf(stdout,"%s as celulas %i %c,%i %c,%i %c e %i %c formam um x-wing imperfeito, pois a celula %i%c não deixa, e essa celula rebarba enxerga o candidato %d na celula da coluna da x-wing, e assim retirando o candidato %d da celula %i %c\n",hd,l1+1,letra(c1),l1+1,letra(c2),l2+1,letra(c1),l2+1,letra(c2),l2+1,letra(cr),d+1,d+1,letra(l),letra(c2));
                                         }
                                     }
                                 }
                             }
                         }
                     }
                 }
                
    return z;
}

int d9c (int w[9][9][9])
{
    int z=0;
    char *hd = "d9l : Fined X-Wing coluna";
    int c1,c2,
        c,
        l1,l2,
        l3,
        l4,
        d,
        ct=0,ct2=0,
        f,a,
        lr,
        rebrc1 = 0,rebrc2 = 0;

    for(c1=0;c1<9;c1++)
        for(l1=0;l1<8;l1++)
            for(l2=l1+1;l2<9;l2++)
                for(d=0;d<9;d++)
                {
                    if(w[l1][c1][d] != w[l2][c1][d] || w[l1][c1][d] == 0)
                        continue;

                    ct=0;
                    f=0;
                    for(l3=0;l3<9;l3++)
                    {
                        if(l1 == l3 || l2 == l3)
                            continue;

                        if(w[l3][c1][d] == w[l2][c1][d] && ct==0)
                        {
                            lr=l3;
                            rebrc1 = 1;
                            ct=1;
                            continue;
                        }
                        if(w[l3][c1][d] == w[l2][c1][d])
                            f=1;
                    }
                    if(f==0)
                    {
                        for(c2=0;c2<9;c2++)
                        {
                            if(c2 == c1)
                                continue;

                            if(w[l1][c1][d] != w[l1][c2][d] || w[l2][c1][d] != w[l2][c2][d])
                                continue;

                            a=0;
                            for(l4=0;l4<9;l4++)
                            {
                                if(l4 == l1 || l4 == l2)
                                    continue;

                                if(rebrc1 == 0)
                                {
                                    if(w[l4][c2][d] == w[l1][c2][d] && ct2==0)
                                    {
                                        lr=l4;
                                        rebrc2=1;
                                        ct2=1;
                                        continue;
                                    }
                                    if(w[l4][c2][d] == w[l1][c2][d])
                                        a=1;
                                }
                                if(rebrc1 == 1)
                                {
                                    if(w[l4][c2][d] == w[l1][c2][d])
                                        a=1;
                                }
                            }
                            if(a==0)
                            {
                                for(c=0;c<9;c++)
                                {
                                    if(c1==c || c2==c)
                                        continue;

                                    if(rebrc1 == 1)
                                    {
                                        if(enxergar(l1,c,lr,c1) && w[l1][c][d] == 1)
                                        {
                                            w[l1][c][d] = 0;
                                            z=1;
                                            fprintf(stdout,"%s as celulas %i %c,%i %c,%i %c e %i %c formam um x-wing imperfeito, pois a celula %i %c não deixa, e essa celula rebarba enxerga o candidato %d na celula da coluna da x-wing, e assim retirando o candidato %d da celula %i %c\n",hd,l1+1,letra(c1),l1+1,letra(c2),l2+1,letra(c1),l2+1,letra(c2),lr+1,letra(c1),d+1,d+1,l1+1,letra(c));
                                        }
                                        if(enxergar(l2,c,lr,c1) && w[l2][c][d] == 1)
                                        {
                                            w[l2][c][d] = 0;
                                            z=1;
                                            fprintf(stdout,"%s as celulas %i %c,%i %c,%i %c e %i %c formam um x-wing imperfeito, pois a celula %i %c não deixa, e essa celula rebarba enxerga o candidato %d na celula da coluna da x-wing, e assim retirando o candidato %d da celula %i %c\n",hd,l1+1,letra(c1),l1+1,letra(c2),l2+1,letra(c1),l2+1,letra(c2),lr+1,letra(c1),d+1,d+1,l2+1,letra(c));
                                        }
                                    }
                                    if(rebrc2 == 1)
                                    {
                                        if(enxergar(l1,c,lr,c2) && w[l1][c][d] == 1)
                                        {
                                            w[l1][c][d] = 0;
                                            z=1;
                                            fprintf(stdout,"%s as celulas %i %c,%i %c,%i %c e %i %c formam um x-wing imperfeito, pois a celula %i %c não deixa, e essa celula rebarba enxerga o candidato %d na celula da coluna da x-wing, e assim retirando o candidato %d da celula %i %c\n",hd,l1+1,letra(c1),l1+1,letra(c2),l2+1,letra(c1),l2+1,letra(c2),lr+1,letra(c2),d+1,d+1,l1+1,letra(c));
                                        }
                                        if(enxergar(l2,c,lr,c2) && w[l2][c][d] == 1)
                                        {
                                            w[l2][c][d] = 0;
                                            z=1;
                                            fprintf(stdout,"%s as celulas %i %c,%i %c,%i %c e %i %c formam um x-wing imperfeito, pois a celula %i %c não deixa, e essa celula rebarba enxerga o candidato %d na celula da coluna da x-wing, e assim retirando o candidato %d da celula %i %c\n",hd,l1+1,letra(c1),l1+1,letra(c2),l2+1,letra(c1),l2+1,letra(c2),lr+1,letra(c2),d+1,d+1,l2+1,letra(c));
                                        }
                                    }
                                }
                            }

                        }
                    }
                }

    return z;
}


/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
