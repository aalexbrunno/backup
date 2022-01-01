/***************************************************************************
 *   auto1.c                                 Version 20210512.104607         *
 *                                                                         *
 *   Converte AFND para AFD                                                *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.               *
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
 * @file auto1.c
 * @ingroup GroupUnique
 * @brief Converte AFND para AFD
 * @details This program really do a nice job as a template, and template only!
 * @version 20160618.013215
 * @date 2016-06-18
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
 *   $gcc auto1.c -o auto1.x -Wall
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
 *      $astyle -A1 -s4 -k3 -xj -SCNeUpv exN.c
 */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in exN.h */

#include "auto1.h" /* To be created for this template if needed */

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
 *    $./auto1 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20210512.104607
 * @date 2016-06-18
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */


    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright and version
     *        -v  verbose
     *        -f  given file name
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "vhcf:")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'c':
                copyr();
                break;
            case 'v':
                verb++;
                break;
            case 'f':
               // strcpy(sfile, optarg);
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    auto1_init(); /* global initialization function: ainda a saber para que usar se precisar */
    //read();

    int n, t, A, state1, state2, i, j, k, result[10][10] = {0};
    int count=0;// count the no of newstates
    int Node[50][26][50]={0};
    //int NewState[20];
    //int States[20];
    int nscount=0;
    char alphabets[10], alpha;

    printf("\n Enter the no of nodes :");
    scanf("%d",&n);

    // assigning each state as a newstate
    for(i=1;i<=n;i++)
         States[count++] = i;

    printf("\n A: "); //No of Alphabets
    scanf("%d",&A);

    printf("\n Enter the alphabets : a b c d ..... z \n >> ");

    for(i=1;i<=A;i++)
         scanf(" %c",&alphabets[i]);

    printf("\n T: "); //No of transitions
    scanf("%d", &t);
    printf("\nSTATE ALPHABET STATE\n");
       for(i=1;i<=t;i++)
       {
               scanf("%d %c %d",&state1,&alpha,&state2);
               Node[state1][map(alpha)][state2] = 1;
       }

       // finding the transitions
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=A;j++)
           {
               int num=0, flag=0;
               for(k=1;k<=n;k++)
               {
                   if( Node[i][j][k] == 1)
                   {
                       num = num * 10 + k;// ref eqn 1.a
                       flag = 1;
                   }
               }
               if( flag==1)
               {
                   result[i][j]=num; // ref eqn 1.a
                   CheckAndAdd(num,&count);
               }
           }
       }
       // displaying the result
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=A;j++)
           {
               //printf("\n STATE %d for ALPHABET %c >>> {",i,rmap(j));
               printf("\n %d %c",i,rmap(j)); //Original states
               int temp = reverse( result[i][j] );
               while( temp > 0 )
               {// ref eqn 1.b
                   printf(" %d", temp%10);
                   temp = temp / 10;
               }
           }
       }

       // finding the transition for any new states created
       while(nscount>0)
       {
           int st = NewState[--nscount];
               st = reverse(st);
               for(j=1;j<=A;j++)
               {
                   int new = -1, num =st;
                   printf("\n %d %c", NewState[nscount],rmap(j)); // New state
                   while(num > 0)
                   {
                       int r = num % 10;
                               new = Union( new , result[r][j] );
                               num = num/10;
                   }
               printf(" %d", new); // New state destination
               }
       }

    return EXIT_SUCCESS;
}
//Funcoes

int map(char a)
{
        int i;
        i=a-96;
        return i;
}

int rmap(int a)
{
        char i;
        i = a+96;
        return i;
}

int reverse(int num)
{
        if( num < 0)
            return num;

        int rev =0,r;

       while( num > 0)
        {
                r = num % 10;
                rev = rev * 10 + r;
                num = num / 10;
        }
        return rev;
}

int Union(int n1, int n2)
 {
         if(n1 == -1)
             return n2;

         int arr[10],i=0,k=0,num=0;

         n1 = reverse(n1);
         while( n1 > 0 )
         {
                 arr[i++] = n1 % 10;
                 n1 = n1 / 10;
         }

         n2 = reverse(n2);
         while( n2 > 0)
         {
                 int r = n2 % 10;
                 int flag = 0;

                 for(k=0;k<i;k++)
         {
                         if( r == arr[k] )
                                 flag = 1;
                 }
                 if( flag == 0 )
                         arr[i++] = r;

                 n2 = n2 / 10;
         }

         for(k=0;k<i;k++)
                 num = num * 10 + arr[k];
         return num;
 }

void CheckAndAdd(int num,int *cnt)
{
        int i, flag=0;
        //int States[20];
        //int NewState[20];
        int nscount=0;

        for(i=0;i<*cnt;i++)
        {
                if(States[i] == num)
                        flag = 1;
        }
        if( flag == 0)
        {
                States[(*cnt)++] = num;
                NewState[nscount++] = num;
        }
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160618.013215
 * @date 2016-06-18
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "exN", "Converte AFD, AFND e ER");
    printf("\nUsage: %s [-h|-v]\n", "auto1");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    /* add more options here */
    printf("\n\nNote (-n): input data is a NFA (Nondeterministic Finite Automata) 5-tuple to be converted to a DFA (Deterministic Finite Automata) 5-tuple.\n");
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
 * @version 20160618.013215
 * @date 2016-06-18
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "auto1", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void auto1_init(void)
{
    IFDEBUG("auto1_init()");
    /* initialization */
    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function does bla bla bla
 * @details It works by doing first a bla, followed by two bla's, giving
 * bla bla bla
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @return The returned value @a r means rhit
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x==funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @warning   Be carefull with blu
 * @deprecated This function will be deactivated in version +33
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @todo Need to change its output format to conform POSIX
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 * @copyright Only if not the same as the whole file
 *
 */
int funcexample(int i, int *o, int *z)
{
    IFDEBUG("funcexample()");
    i += *z;
    *o = (*z)++;
    return i - 4;
}

/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */


