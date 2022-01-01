/***************************************************************************
 *   upecman.c                                Version 20160529.013231      *
 *                                                                         *
 *   Pacman Ncurses                                                        *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
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
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file upecman.c
 * @ingroup GroupUnique
 * @brief Pacman Ncurses
 * @details This program really do a nice job as a template, and template only!
 * @version 20160529.013231
 * @date 2016-05-29
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
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
 *      $make
 * ou
 *      $gcc upecman.c -o upecman.x -Wall -lncurses -g -Og
 *          -Wextra -ansi -pedantic-errors -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <ncurses.h> /* Screen handling and optimisation functions */
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <assert.h> /* Verify assumptions with assert */
#include <unistd.h> /* UNIX standard function */
#include "upecman.h" /* To be created for this template if needed */
#include <time.h>  /* Time and date functions */
#include <math.h>  /* Mathematics functions */

/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
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
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

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
 *    $./upecman -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */



int main(int argc, char *argv[])
{
    /*Início das variáveis preestabelecidas*/

    IFDEBUG("main()\n");
    int opt; /* return from getopt() */
    t_game g; /* o jogo */
    int kin; /* keyboard input - valor de entrada do teclado */
    int ch;
    char barreira[2] = "#-";
    char pacdot[3] = ".o%";
    char vazio[1] = " ";
    int powerup = 0; // conta o tempo do powerup
    int tempo = 0; // serve para o funcionamento dos fantasmas da prisão, a cada 5 unidades se passa 1 segundo

    /*Fim das variáveis preestabelecidas*/

    IFDEBUG("Starting optarg loop...\n");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright & version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hvc")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'v':
                verb++;
                break;
            case 'c':
                copyr();
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    /* ...and we are done */
    IFDEBUG("Starting the game now...\n");

    /*Começa o programa*/
    g = upecman_init(); //g = código do labirinto
    imprime_menu();

    while(1)
    {

        kin = getch(); //a variável kin recebe o valor dado pelo usuário

        if(kin == 's' || kin == KEY_LEFT) //se o usuário apertar s, o jogo fecha
            break;
        usleep(16667); // wait 16666 microseconds to avoid frying the processor (1/60 s)

        if(kin == 'i' || kin == KEY_RIGHT) //se o usuário apertar i, o jogo inicia
        {
            clear(); // inicia a tela  
            cbreak();
            noecho();
            curs_set(FALSE); // desabilita o input do mouse
            keypad(stdscr, TRUE); // habilita o input do teclado
            timeout(100); // tempo que o programa vai esperar o input


            while(1)
            {
                clear();

                printlab(g); // imprime o labirinto
                g = fantdirec(g); // decide a direção de cada fantasma de acordo com o modo de perseguição de cada um

                g.lab[g.pacman.pos.y][g.pacman.pos.x] = vazio[0]; // retira a bolinha do mapa

                refresh();

                ch = getch(); // input do usuário

                if(ch == 's') // se o usuário apertar s, o jogo fecha
                    break;

                if(ch == KEY_RIGHT && g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] != barreira[0]) // verifica a direção dada pelo input do usuário
                    g.pacman.dir = right;
                else
                    if(ch == KEY_LEFT && g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] != barreira[0])
                        g.pacman.dir = left;
                    else
                        if(ch == KEY_UP && g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != barreira[0])
                            g.pacman.dir = up;
                        else
                            if(ch == KEY_DOWN && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != barreira[0])
                                g.pacman.dir = down;

                g = pacmov(g);// movimentação do pacman

                if(tempo % 3 != 0)
                    g = fantimov(g);// movimentação dos fantasmas

                for(int i = blinky; i <= clyde; i++)// troca o modo perserguir pelo espalhar
                {
                    if(powerup == 0) // se o powerup não estiver ativado
                    {
                        if(tempo % 135 < 100 && g.ghost[i].mode != dead && g.ghost[i].mode != afraid) // os fantasmas ficam 20 segundos no modo chase e depois 7 segundos no modo scatter
                            g.ghost[i].mode = chase;
                        else
                            g.ghost[i].mode = scatter;
                    }
                }

                if(tempo == 150) // após 30 segundos do início do round nasce uma cereja 
                    g.lab[17][9] = pacdot[2];
                if(tempo == 200) // aos 40 segundos a cereja some 
                    g.lab[17][9] = vazio[0];

                for(int i = blinky; i <= clyde; i++) // verifica se o pacman está na mesma posição de um dos fantasmas
                {
                    if((g.ghost[i].pos.y == g.pacman.pos.y && g.ghost[i].pos.x == g.pacman.pos.x) || (g.ghost[i].pos.y + 1 == g.pacman.pos.y && g.ghost[i].pos.x == g.pacman.pos.x) || (g.ghost[i].pos.y - 1 == g.pacman.pos.y && g.ghost[i].pos.x == g.pacman.pos.x) || (g.ghost[i].pos.y == g.pacman.pos.y && g.ghost[i].pos.x == g.pacman.pos.x + 1) || (g.ghost[i].pos.y == g.pacman.pos.y && g.ghost[i].pos.x == g.pacman.pos.x - 1))
                    // se os fantasmas estiverem numa posição adjacente ao pacman
                    {
                        if(g.ghost[i].mode == afraid || g.ghost[i].mode == dead) // se os fantasmas estiverem no modo dead ou afraid seu modo é trocado para dead
                            g.ghost[i].mode = dead;

                        else // senão o pacman perde uma vida, as posições dos personagens são resetadas
                        {
                            g.pacman.life--;
                            g = resetpos(g);
                            usleep(1000000);
                        }
                        if(g.ghost[i].mode == afraid) // ao consumir um fantasma no modo afraid é adcionado +750 ao score
                            g.pacman.score += 75;
                    }
                }

                if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == pacdot[0])  // verifica se onde o pacman está tem uma pastilha
                {
                    g.pacman.pacdot++; // mais um para o contador de pacdot
                    g.pacman.score++; 
                }

                if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == pacdot[1])  // verifica se onde o pacman está tem uma pílula
                {
                    for(int i = blinky; i <= clyde; i++) // ao consumir uma pílula os fantasmas devem inverter sua direção
                    {
                        g.ghost[i].mode = afraid; // muda o modo dos fantasmas para afraid

                        if(g.ghost[i].dir == right)
                            g.ghost[i].dir = left;
                        else
                            if(g.ghost[i].dir == left)
                                g.ghost[i].dir = right;
                            else
                                if(g.ghost[i].dir == up)
                                    g.ghost[i].dir = down;
                                else
                                    if(g.ghost[i].dir == down)
                                        g.ghost[i].dir = up;
                    }
                    powerup = 1; // inicia o contador do powerup
                    g.pacman.score += 5; // adiciona +50 ao score
                }

                if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == pacdot[2])  // verifica se onde o pacman está tem uma cereja
                    g.pacman.score += 50; // adiciona +500 ao consumir a cereja

                if(powerup > 0) // se o contador do powerup for maior que um
                    powerup += 1; // adiciona +1 ao powerup

                if(powerup == 75) // se o powerup chegar a 75 (15 segundos)
                {
                    for(int i = blinky; i <= clyde; i++)
                    {
                        if(g.ghost[i].mode != dead) // se os fantasmas não estiverem no modo dead
                        {
                            g.ghost[i].mode = chase; // troca o modo dos fantasmas para chase

                            if(g.ghost[i].dir == right) // os fantasmas invertem a direção
                                g.ghost[i].dir = left;
                            else
                                if(g.ghost[i].dir == left)
                                    g.ghost[i].dir = right;
                                else
                                    if(g.ghost[i].dir == up)
                                        g.ghost[i].dir = down;
                                    else
                                        if(g.ghost[i].dir == down)
                                            g.ghost[i].dir = up;
                        }
                    }

                    powerup = 0;  // powerup volta a 0
                }

                if(g.pacman.pacdot % 184 == 0 && g.pacman.pacdot != 0) //reseta o jogo se o pacman comer todas as pastilhas
                {
                    g = resetlab(g);
                    g = resetpos(g);
                    g.pacman.pacdot = 0;
                    tempo = 0;
                }

                if(g.pacman.life == 0)  // se o pacman nao tiver mais vidas
                {
                    while(1)  // pausa o jogo e apace na tela game over
                    {
                        mvprintw(20, 30, "GAME OVER");
                        mvchgat(20, 30, -1, A_BOLD, 1, NULL);
                        mvprintw(21, 30, "Deseja recomeçar? (s/n)");
                        kin = getch();

                        if(kin == 's')  // reinicia o jogo se o usuario apertar S
                        {
                            g = resetlab(g);
                            g = resetpos(g);
                            g.pacman.pacdot = 0;
                            g.pacman.life = 3;
                            tempo = 0;
                            break;
                        }
                        if(kin == 'n')  // fecha o jogo se apertar N
                        {
                            endwin();
                            return EXIT_SUCCESS;
                        }
                    }
                }


                tempo++;
                usleep(100000);

            }

            endwin();
            return EXIT_SUCCESS;
        }
    }

    endwin();
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Prints help information and exit
* @details Prints help information (usually called by opt -h)
* @return Void
* @author Ruben Carlo Benante
* @version 20160529.013231
* @date 2016-05-29
*
*/
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "upecman", "Pacman Ncurses");
    printf("\nOpções:\n");
    printf("\t-h,  --help\n\t\tMostra este menu de ajuda.\n");
    printf("\t-c,  --copyright, --version\n\t\tMostra as informações de versão e copyright.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nSaída:\n\tPara sair, aperte a tecla S a qualquer momento.\n");
    printf("\nRegras do jogo:\n\tPara jogar Pacman, você deve movimentar o @ pelo labirinto usando as setas do seu teclado. Seu objetivo é coletar todas as pastilhas (.) sem ser pego pelos fantasmas    .");
    printf("\n\tOs fantasmas são representados pelas letras I, P, C e B. Cada um deles vai tentar alcançar o Pacman utilizando uma estratégia diferente. Caso consigam, o Pacman perderá 1 v    ida.");
    printf("\n\tO modo Powerup é ativado quando o Pacman ingere as pastilhas maiores (o); por 10 segundos, os fantasmas ficarão indefesos e poderão ser comidos.");
    printf("\n\tVocê terá 3 vidas durante o jogo.");
    printf("\n\tA cereja irá aparecer durante o jogo. Ela vale 500 pontos.");
    printf("\n\tPara iniciar o jogo, aperte a tecla i. Para sair do menu principal, use o botão s.");
    printf("\n\tCaso precise sair no meio da partida, aperte s.");
    printf("\n\tPontuação:");
    printf("\n\t. = 10 pontos\n\to = 50 pontos\n\tI = 750 pontos\n\tB = 750 pontos\n\tP = 750 pontos\n\tC = 750 pontos");
    printf("\n\nAutores:\n\tEste jogo foi desenvolvido por:");
    printf("\n\t Alanne Carvalho De Paula <acp1@poli.br>\n\t Ana Clara Alexandre De Freitas <acaf1@poli.br>");
    printf("\n\t Camila Póvoas Tavares <cpt1@poli.br>\n\t Giovani Maciel Filho <gmf1@poli.br>\n\t Lucas Vinnicius Santos De Melo <lvsm@poli.br>");
    printf("\n\t Mariana Chiappeta Castelo Branco <mariana.chiappeta@gmail.com>\n\t Matheus Barbosa Lebre Alves <mbla@poli.br>\n");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "upecman", VERSION);
    printf("\nCopyright (C) %d %s <%s>, %s <%s>, %s <%s>, %s <%s>, %s <%s>, %s <%s>, %s <%s>\n\n", 2021, "Alanne Carvalho De Paula", "acp1@poli.br", "Ana Clara Alexandre De Freitas", "acaf1@poli.br", "Camila Póvoas Tavares", "pt1@poli.br", "Giovani Maciel Filho", "gmf1@poli.br", "Lucas Vinnicius Santos De Melo", "lvsm@poli.br", "Mariana Chiappeta Castelo Branco", "mariana.chiappeta@gmail.com", "Matheus Barbosa Lebre Alves", "mbla@poli.br");
    printf("GNU GPL version 2 <http://gnu.org/licenses/gpl.html>.\n");
    printf("This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS.\n");
    printf("The author takes no responsability to any damage this software may inflige in your data.\n\n");
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
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
void imprime_menu(void)  //imprime o menu
{
    int ymax, xmax; //mostra qual o x e y máximos da tela

    initscr(); // iniciar a tela
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);   // tirar o cursor branco que aparece na tela
    cor();    // iniciar a função da cor
    getmaxyx(stdscr, ymax, xmax); //stdscr = janela grande inicial

    attron(COLOR_PAIR(3));
    mvprintw((ymax / 2) - 2, (xmax / 2) - 22, "INSIRA UMA MOEDA PARA JOGAR APERTANDO");
    mvprintw(19, (xmax / 2) - 12, "PARA SAIR APERTE");
    attroff(COLOR_PAIR(3));
    mvprintw((ymax / 2) - 2, (xmax / 2) + 16, "I");
    mvprintw(19, (xmax / 2) + 5, "S");
    mvchgat((ymax / 2) - 2, (xmax / 2) + 16, -1, A_BOLD, 6, NULL);
    mvchgat(19, (xmax / 2) + 5, -1, A_BOLD, 6, NULL);

    /*Ajuda*/
    mvprintw(27, (xmax / 2) - 3, "AJUDA ");
    mvchgat(27, (xmax / 2) - 3, -1, A_BOLD, 6, NULL);
    attron(COLOR_PAIR(3));
    mvprintw(31, (xmax / 2) - 44, "Ajude o Pacman (@) a comer todas as pastilhas do labirinto. Você tem 3 vidas para isso!");
    mvprintw(33, (xmax / 2) - 67, "Os fantasmas Inky, Pinky, Blinky e Clyde vão tentar atingir o Pacman. Cuidado: cada um deles tem sua estratégia única. Então, atenção!");
    mvprintw(35, (xmax / 2) - 31, "Se algum dos fantasmas atingir o pacman, você perderá uma vida.");
    mvprintw(37, (xmax / 2) - 72, "O labirinto possui 184 pastilhas (.), 4 pílulas (o) e uma cereja (%). As pastilhas valem 10 pontos, cada pílula 50 pontos e a cereja 500 pontos.");
    mvprintw(39, (xmax / 2) - 49, "As pastilhas darão ao Pacman o poder de comer os fantasmas. Cada fantasma devorado vale 750 pontos.");
    mvprintw(41, (xmax / 2) - 17, "O Pacman conta com você. Bom jogo!");
    attroff(COLOR_PAIR(3));

    /*Título*/
    mvprintw(6, (xmax / 2) - 33, "UU  UU  PPPPP   EEEEEE");
    mvprintw(7, (xmax / 2) - 33, "UU  UU  PP   P  EE    ");
    mvprintw(8, (xmax / 2) - 33, "UU  UU  PP   P  EE      CCCCCCC    M     M    AAAAAAA  NN    NN    ");
    mvprintw(9, (xmax / 2) - 33, "UU  UU  PPPPP   EE EE   CC       MM M  M  MM  AA   AA  NN N  NN    ");
    mvprintw(10, (xmax / 2) - 33, "UU  UU  PP      EE      CC       MM   M   MM  AAAAAAA  NN  N NN    ");
    mvprintw(11, (xmax / 2) - 33, "UU  UU  PP      EE      CCCCCCC  MM       MM  AA   AA  NN    NN  0 ");
    mvprintw(12, (xmax / 2) - 33, "UUUUUU  PP      EEEEEE");
    mvchgat(6, (xmax / 2) - 33, -1, A_BOLD, 6, NULL);  // adicionar a cor amarela para dar destaque ao título
    mvchgat(7, (xmax / 2) - 33, -1, A_BOLD, 6, NULL);
    mvchgat(8, (xmax / 2) - 33, -1, A_BOLD, 6, NULL);
    mvchgat(9, (xmax / 2) - 33, -1, A_BOLD, 6, NULL);
    mvchgat(10, (xmax / 2) - 33, -1, A_BOLD, 6, NULL);
    mvchgat(11, (xmax / 2) - 33, -1, A_BOLD, 6, NULL);
    mvchgat(12, (xmax / 2) - 33, -1, A_BOLD, 6, NULL);

    refresh();

    return;
}



t_game upecman_init(void)
{
    IFDEBUG("init()");
    /* initialization */

    t_game g;
    int f, y;

    for(y = 0; y < 23; y++) //LABL = número de linhas do labirinto
        strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */

    g.pacman.pos.y = 17; /* pacman start position (line) */
    g.pacman.pos.x = 9; /* pacman start position (column) */
    g.pacman.dir = left; /* pacman start direction */
    g.pacman.life = 3; /* 3 lifes */
    g.pacman.score = 0; /* 0 points */
    g.pacman.pacdot = 0;

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
    {
        switch(f)
        {
            case blinky:
                g.ghost[f].pos.y = 7; /* blinky start position (line) */
                g.ghost[f].pos.x = 9; /* blinky start position (column) */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case pinky:
                g.ghost[f].pos.y = 9; /* pinky start position (line) */
                g.ghost[f].pos.x = 9; /* pinky start position (column) */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
                break;
            case inky:
                g.ghost[f].pos.y = 10; /* inky start position (line) */
                g.ghost[f].pos.x = 9; /* inky start position (column) */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case clyde:
                g.ghost[f].pos.y = 11; /* clyde start position (line) */
                g.ghost[f].pos.x = 9; /* clyde start position (column) */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
        }
        g.ghost[f].dir = left; /* start direction and future direction: left */
        g.ghost[f].mode = chase;
    }
    return g;
}

void cor(void)
{
    initscr(); /* start ncurses mode screen */
    cbreak(); /* stop line buffering */
    keypad(stdscr, TRUE); /* grab extended keys */
    noecho(); /* stop echoing chars */
    timeout(0); /* do not wait */
    start_color(); /* initialize the color functionality */

    /* Initialize all the colors */
    init_pair(1, COLOR_RED, COLOR_BLACK); /* Blinky */
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK); /* Pinky */
    init_pair(3, COLOR_CYAN, COLOR_BLACK); /* Inky */
    init_pair(4, COLOR_GREEN, COLOR_BLACK); /* Clyde doesn't have orange :( */
    init_pair(5, COLOR_BLUE, COLOR_BLACK); /* Afraid mode: blue with A_BLINK */
    init_pair(6, COLOR_YELLOW, COLOR_BLACK); /* Pacman */

}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
void printlab(t_game g)
{
    char pacdot[3] = ".o%";
    int y, f;


    for(y = 0; y < 23; y++) // imprime o labirinto
        mvprintw(0 + y, 0, "%s", g.lab[y]);

    mvprintw(7, 30, "VIDAS: %d", g.pacman.life); // imprime a quantidade de vida
    mvprintw(9, 30, "SCORE: %d", g.pacman.score * 10); // imprime o score 
    mvprintw(10, 21, "                         ^  ");
    mvprintw(11, 30,          "CONTROLES:   <     > ");
    mvprintw(12, 30,          "                v  ");
    mvprintw(13, 30,          "SAIR: S");
    mvchgat(7, 30, -1, A_BOLD, 6, NULL);
    mvchgat(9, 30, -1, A_BOLD, 6, NULL);
    mvchgat(10, 30, -1, A_BOLD, 6, NULL);
    mvchgat(11, 30, -1, A_BOLD, 6, NULL);
    mvchgat(12, 30, -1, A_BOLD, 6, NULL);
    mvchgat(13, 30, -1, A_BOLD, 6, NULL);

    cor_labirinto(g); // colore o labirinto

    mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@"); // imprime o caractere do pacmam
    mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL); // colore o pacman

    mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, "B"); // imprime os caracteres dos fantasmas 
    mvprintw(g.ghost[1].pos.y, g.ghost[1].pos.x, "P");
    mvprintw(g.ghost[2].pos.y, g.ghost[2].pos.x, "I");
    mvprintw(g.ghost[3].pos.y, g.ghost[3].pos.x, "C");

    if(g.lab[17][9] == pacdot[2]) // colore a cereja caso ela esteja no mapa
        mvchgat(17, 9, 1, A_BOLD, 1, NULL);

    for(f = blinky; f <= clyde; f++) // colore os fantasmas com as suas respectivas cores ou azul caso estiverem no modo dead ou afraid
    {
        if(g.ghost[f].mode == chase || g.ghost[f].mode == scatter)
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f + 1, NULL);
        if(g.ghost[f].mode == afraid || g.ghost[f].mode == dead)
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 5, NULL);
    }

    mvprintw(8, 10, "-"); // conserta a representação do mapa

    mvprintw(9, 8, " ");
    mvprintw(9, 10, " ");
    mvprintw(9, 11, " ");
    mvprintw(10, 8, " ");
    mvprintw(10, 10, " ");
    mvprintw(10, 11, " ");
    mvprintw(11, 8, " ");
    mvprintw(11, 10, " ");
    mvprintw(11, 11, " ");
}


void cor_labirinto(t_game g)
{
    int y, i;

    for(y = 0; y < LABL; y++)
    {
        for(i = 0; i < LABC; i++)
        {
            if(g.lab[y][i] == '#')     // ter a parede do labirinto (#) em azul
                mvchgat(y, i, 1, A_BOLD, 5, NULL);

            if(g.lab[y][i] == 'o' || g.lab[y][i] == '.')     // as pastilhas em amarelo
                mvchgat(y, i, 1, A_BOLD, 6, NULL);
        }
    }
}


t_game fantdirec(t_game g)
{
    char barreira[2] = "#-";
    int troca = 0;
    int i, r;

    for(int i = blinky; i <= clyde; i++) // alvo modo dead
    {
        if(g.ghost[i].mode == dead) // no modo dead os fantasmas devem voltar para a prisão
        {
            g.ghost[i].starget.y = 7;
            g.ghost[i].starget.x = 9;

            if(g.ghost[i].pos.y == 7 && g.ghost[i].pos.x == 9) // ao chegar na prisão o modo é trocado para chase
                g.ghost[i].mode = chase;
        }
    }

    if(g.ghost[0].mode == chase) // alvo blinky
    {
        g.ghost[0].starget.y = g.pacman.pos.y; // o blinky persegue o pacmam
        g.ghost[0].starget.x = g.pacman.pos.x;
    }
    if(g.ghost[0].mode == scatter)
    {
        g.ghost[0].starget.y = 1; // canto favorito do blinky
        g.ghost[0].starget.x = 16;
    }

    if(g.ghost[1].mode == chase) //alvo pinky
    {
        if(g.pacman.dir == right) // o pinky tenta ficar 4 casas á frente do pacman
        {
            g.ghost[1].starget.y = g.pacman.pos.y;
            g.ghost[1].starget.x = g.pacman.pos.x + 4;
        }
        if(g.pacman.dir == left)
        {
            g.ghost[1].starget.y = g.pacman.pos.y;
            g.ghost[1].starget.x = g.pacman.pos.x - 4;
        }
        if(g.pacman.dir == up)
        {
            g.ghost[1].starget.y = g.pacman.pos.y - 4;
            g.ghost[1].starget.x = g.pacman.pos.x;
        }
        if(g.pacman.dir == down)
        {
            g.ghost[1].starget.y = g.pacman.pos.y + 4;
            g.ghost[1].starget.x = g.pacman.pos.x;
        }
    }

    if(g.ghost[1].mode == scatter)
    {
        g.ghost[1].starget.y = 1; // canto favorito do pinky
        g.ghost[1].starget.x = 3;
    }
    if(g.ghost[2].mode == chase) // alvo inky
    {
        if(pow(g.ghost[2].starget.y - g.pacman.pos.y, 2) <= 9 || pow(g.ghost[2].starget.x - g.pacman.pos.x, 2) <= 9)
            // se o inky estiver a menos de 3 casas so pacman ele deve se comportar igual ao bliky
        {
            g.ghost[2].starget.y = g.pacman.pos.y;
            g.ghost[2].starget.x = g.pacman.pos.x;
        }
        else
            if(pow(g.ghost[2].starget.y - g.pacman.pos.y, 2) <= 36 || pow(g.ghost[2].starget.x - g.pacman.pos.x, 2) <= 36)
                // se o inky estiver a menos de 3 casas deve se comportar igual ao pinky
            {
                if(g.pacman.dir == right)
                {
                    g.ghost[2].starget.y = g.pacman.pos.y;
                    g.ghost[2].starget.x = g.pacman.pos.x + 4;
                }
                if(g.pacman.dir == left)
                {
                    g.ghost[2].starget.y = g.pacman.pos.y;
                    g.ghost[2].starget.x = g.pacman.pos.x - 4;
                }
                if(g.pacman.dir == up)
                {
                    g.ghost[2].starget.y = g.pacman.pos.y - 4;
                    g.ghost[2].starget.x = g.pacman.pos.x;
                }
                if(g.pacman.dir == down)
                {
                    g.ghost[2].starget.y = g.pacman.pos.y + 4;
                    g.ghost[2].starget.x = g.pacman.pos.x;
                }
            }
        if(pow(g.ghost[2].starget.y - g.pacman.pos.y, 2) > 36 || pow(g.ghost[2].starget.x - g.pacman.pos.x, 2) > 36)
            g.ghost[2].mode = scatter;
    }
    if(g.ghost[2].mode == scatter)
        // se o inky estiver muito distante ele volta para o seu canto preferido
    {
        g.ghost[2].starget.y = 21;
        g.ghost[2].starget.x = 15;
    }

    if(pow(g.ghost[3].starget.y - g.pacman.pos.y, 2) < 36 || pow(g.ghost[3].starget.x - g.pacman.pos.x, 2) < 36 || g.ghost[3].mode == scatter)   // alvo clyde
    { 
        g.ghost[3].starget.y = 21; // se o clyde estiver muito próximo do pacman ele volta pro seu canto favorito
        g.ghost[3].starget.x = 4;
    }
    else // senão ele persegue o pacman
    {
        g.ghost[3].starget.y = g.pacman.pos.y;
        g.ghost[3].starget.y = g.pacman.pos.x;
    }


    for(i = blinky; i <= clyde; i++) // decide a direcão tomada por cada fantasma
    {
        if(g.ghost[i].mode == chase || g.ghost[i].mode == scatter || g.ghost[i].mode == dead) // se o modo do fantasma for chase, scatter ou dead
        {
            if(g.ghost[i].dir == right) // se a direção atual do fantasma for right
            {
                if(g.ghost[i].starget.y > g.ghost[i].pos.y && g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[0])
                {
                    // se o target do fantasma estiver abaixo dele e não tiver barreira abaixo 
                    g.ghost[i].dir = down; // modo muda para down
                    troca = 1; // troca +1
                }
                else
                    if(g.ghost[i].starget.y < g.ghost[i].pos.y && g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != barreira[0])
                    {
                        // se o target do fantasma estiver acima dele e não tiver barreira acima
                        g.ghost[i].dir = up; // modo muda para up
                        troca = 1; // troca +1
                    }
                    else
                        if(g.ghost[i].starget.x > g.ghost[i].pos.x && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != barreira[0])
                        {
                            // se o target do fantasma estiver à direita dele e não tiver barreira à direita
                            g.ghost[i].dir = right; // modo muda para right
                            troca = 1; // troca +1
                        }
            }
            else
                if(g.ghost[i].dir == left)  // se a direção atual do fantasma for left
                {
                    if(g.ghost[i].starget.y > g.ghost[i].pos.y && g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[0])
                    {
                        // se o target do fantasma estiver abaixo dele e não tiver barreira abaixo
                        g.ghost[i].dir = down; // modo muda para down
                        troca = 1; // troca +1
                    }
                    else
                        if(g.ghost[i].starget.y < g.ghost[i].pos.y && g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != barreira[0])
                        {
                            // se o target do fantasma estiver acima dele e não tiver barreira acima
                            g.ghost[i].dir = up; // modo muda para up
                            troca = 1; // troca +1
                        }
                        else
                            if(g.ghost[i].starget.x < g.ghost[i].pos.x && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != barreira[0])
                            {
                                // se o target do fantasma estiver à esquerda dele e não tiver barreira à esquerda
                                g.ghost[i].dir = left; // modo muda para left
                                troca = 1; // troca +1
                            }
                }
                else
                    if(g.ghost[i].dir == up)  // se a direção atual do fantasma for up
                    {
                        if(g.ghost[i].starget.x > g.ghost[i].pos.x && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != barreira[0])
                        {
                            // se o target do fantasma estiver à direita dele e não tiver barreira à direita
                            g.ghost[i].dir = right; // modo muda para right
                            troca = 1; // troca +1
                        }
                        else
                            if(g.ghost[i].starget.x < g.ghost[i].pos.x && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != barreira[0])
                            {
                                // se o target do fantasma estiver à esquerda dele e não tiver barreira à esquerda
                                g.ghost[i].dir = left; // modo muda para left
                                troca = 1; // troca +1
                            }
                            else
                                if(g.ghost[i].starget.x < g.ghost[i].pos.y && g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != barreira[0])
                                {
                                    // se o target do fantasma estiver acima dele e não tiver barreira acima
                                    g.ghost[i].dir = up; // modo muda para up
                                    troca = 1; // troca +1
                                }
                    }
                    else
                        if(g.ghost[i].dir == down)  // se a direção atual do fantasma for down
                        {
                            if(g.ghost[i].starget.x > g.ghost[i].pos.x && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != barreira[0])
                            {
                                // se o target do fantasma estiver à direita dele e não tiver barreira à direita
                                g.ghost[i].dir = right; // modo muda para right
                                troca = 1; // troca +1
                            }
                            else
                                if(g.ghost[i].starget.x < g.ghost[i].pos.x && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != barreira[0])
                                {
                                    // se o target do fantasma estiver à esquerda dele e não tiver barreira à esquerda
                                    g.ghost[i].dir = left; // modo muda para left
                                    troca = 1; // troca +1
                                }
                                else
                                    if(g.ghost[i].starget.y > g.ghost[i].pos.y && g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[0])
                                    {
                                        // se o target do fantasma estiver abaixo dele e não tiver barreira abaixo
                                        g.ghost[i].dir = down; // modo muda para down
                                        troca = 1; // troca +1
                                    }
                        }

            if(g.ghost[i].mode == afraid) // se o fantasma estiver no modo afraid (movimento aleatório)
            {
                while(1) // enquanto o fantasma não achar uma direção válida
                {
                    r = rand() % 3; // sorteia uma das 4 direções

                    if(r == 0) // up
                    {
                        if(g.lab[g.ghost[i].pos.y - 1 ][g.ghost[i].pos.x] != barreira[0] && g.ghost[i].dir != down) 
                        // se a direção atual do fantasma não for down e não tiver barreira acima
                        {
                            g.ghost[i].dir = up; // muda a direcão para up
                            break;
                        }
                    }
                    else
                        if(r == 1) // left
                        {
                            if(g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != barreira[0] && g.ghost[i].dir != right)
                            // se a direção atual do fantasma não for right e não tiver barreira à esquerda    
                            {
                                g.ghost[i].dir = left; // muda a direcão para left
                                break;
                            }
                        }
                        else
                            if(r == 2) // down
                            {
                                if(g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[0] && g.ghost[i].dir != up)
                                // se a direção atual do fantasma não for up e não tiver barreira abaixo
                                {
                                    g.ghost[i].dir = down; // muda a direcão para down
                                    break;
                                }
                            }
                            else
                                if(r == 3) // right
                                {
                                    if(g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != barreira[0] && g.ghost[i].dir != left)
                                    // se a direção atual do fantasma não for left e não tiver barreira à direita
                                    {
                                        g.ghost[i].dir = right; // muda a direcão para right
                                        break;
                                    }
                                }
                }
                troca++;
            }


        }
        if(troca == 0)  // se direção  do fantasma não tiver sido trocada até essa parte do código ele deverá pegar a primeira direção possivel (evita que o fantasma fique travado)
        {
            if(g.ghost[i].dir == right) // se a direção for right
            {
                if(g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[0] && g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[1])
                    g.ghost[i].dir = down; // se não tiver barreira abaixo a direção muda para down
                else
                    if(g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != barreira[0])
                        g.ghost[i].dir = up; // se não tiver barreira acima a direção muda para up
            }
            else
                if(g.ghost[i].dir == left)
                {
                    if(g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[0] && g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[1])
                        g.ghost[i].dir = down; // se não tiver barreira abaixo a direção muda para down
                    else
                        if(g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != barreira[0])
                            g.ghost[i].dir = up; // se não tiver barreira acima a direção muda para up
                }
                else
                    if(g.ghost[i].dir == up) // se a direção for up
                    {
                        if(g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != barreira[0])
                            g.ghost[i].dir = right; // se não tiver barreira à direita a direção muda para right
                        else
                            if(g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != barreira[0])
                                g.ghost[i].dir = left; // se não tiver barreira à esquerda a direção muda para left
                    }
                    else
                        if(g.ghost[i].dir == down)  // se a direção for down
                        {
                            if(g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != barreira[0])
                                g.ghost[i].dir = right; // se não tiver barreira à direita a direção muda para right
                            else
                                if(g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != barreira[0])
                                    g.ghost[i].dir = left; // se não tiver barreira à esquerda a direção muda para left
                        }
            troca = 0; // troca volta para 0
        }
    }
    return g;
}

t_game resetlab(t_game g) // limpa o labirinto
{
    g.pacman.score = 0; // score volta para 0

    usleep(1000000);
    for(int y = 0; y < 23; y++) // zera o labirinto
        strcpy(g.lab[y], labmodel[y]);
    usleep(100000);
    return g;
}

t_game resetpos(t_game g) // reseta a posição dos personagens
{
    printlab(g); // atualiza a tela do jogo
    refresh();

    g.pacman.pos.y = 17; // pacman
    g.pacman.pos.x = 9;

    g.ghost[0].pos.y = 7; // blinky
    g.ghost[0].pos.x = 9;

    g.ghost[1].pos.y = 9; // pinky
    g.ghost[1].pos.x = 9;

    g.ghost[2].pos.y = 10; // inky
    g.ghost[2].pos.x = 9;

    g.ghost[3].pos.y = 11; // clyde
    g.ghost[3].pos.x = 9;

    for(int i = blinky; i <= clyde; i++) // os fantasmas iniciam com a direção up
        g.ghost[i].dir = up;

    return g;
}

t_game fantimov(t_game g) // movimenta os fantasmas
{
    char barreira[2] = "#-";
    for(int i = blinky; i <= clyde; i++) // se o fantasmas sair dos limites do labirinto ele é teleportado pro outro lado (tuneis)
    {
        if(g.ghost[i].pos.x < 1)
            g.ghost[i].pos.x = 18;
        if(g.ghost[i].pos.x > 18)
            g.ghost[i].pos.x = 1;
    }

    if(g.pacman.pacdot == 7) // ao coletar 7 pacdots o pinky sai
    {
        g.ghost[1].pos.y = 7;
        g.ghost[1].pos.x = 9;
    }
    if(g.pacman.pacdot == 17) // ao coletar 17 pacdots o inky sai
    {
        g.ghost[2].pos.y = 7;
        g.ghost[2].pos.x = 9;
    }
    if(g.pacman.pacdot == 32) // ao coletar 32 pacdots o clyde sai
    {
        g.ghost[3].pos.y = 7;
        g.ghost[3].pos.x = 9;
    }

    if(g.ghost[0].dir == right && g.lab[g.ghost[0].pos.y][g.ghost[0].pos.x + 1] != barreira[0]) // movimenta os fantasmas de acordo com a sua direção(up, left, down e right)
        g.ghost[0].pos.x += 1;
    if(g.ghost[0].dir == left && g.lab[g.ghost[0].pos.y][g.ghost[0].pos.x - 1] != barreira[0])
        g.ghost[0].pos.x -= 1;
    if(g.ghost[0].dir == up && g.lab[g.ghost[0].pos.y - 1][g.ghost[0].pos.x] != barreira[0])
        g.ghost[0].pos.y -= 1;
    if(g.ghost[0].dir == down && g.lab[g.ghost[0].pos.y + 1][g.ghost[0].pos.x] != barreira[0] && g.lab[g.ghost[0].pos.y + 1][g.ghost[0].pos.x] != barreira[1])
        g.ghost[0].pos.y += 1;

    if(g.pacman.pacdot > 7) // o pinky so se movimenta se mais de 7 pacdots forem coletadas
    {
        if(g.ghost[1].dir == right && g.lab[g.ghost[1].pos.y][g.ghost[1].pos.x + 1] != barreira[0])
            g.ghost[1].pos.x += 1;
        if(g.ghost[1].dir == left && g.lab[g.ghost[1].pos.y][g.ghost[1].pos.x - 1] != barreira[0])
            g.ghost[1].pos.x -= 1;
        if(g.ghost[1].dir == up && g.lab[g.ghost[1].pos.y - 1][g.ghost[1].pos.x] != barreira[0])
            g.ghost[1].pos.y -= 1;
        if(g.ghost[1].dir == down && g.lab[g.ghost[1].pos.y + 1][g.ghost[1].pos.x] != barreira[0] && g.lab[g.ghost[1].pos.y + 1][g.ghost[1].pos.x] != barreira[1])
            g.ghost[1].pos.y += 1;
    }

    if(g.pacman.pacdot > 17) // o inky so se movimenta se mais de 17 pacdots forem coletadas
    {
        if(g.ghost[2].dir == right && g.lab[g.ghost[2].pos.y][g.ghost[2].pos.x + 1] != barreira[0])
            g.ghost[2].pos.x += 1;
        if(g.ghost[2].dir == left && g.lab[g.ghost[2].pos.y][g.ghost[2].pos.x - 1] != barreira[0])
            g.ghost[2].pos.x -= 1;
        if(g.ghost[2].dir == up && g.lab[g.ghost[2].pos.y - 1][g.ghost[2].pos.x] != barreira[0])
            g.ghost[2].pos.y -= 1;
        if(g.ghost[2].dir == down && g.lab[g.ghost[2].pos.y + 1][g.ghost[2].pos.x] != barreira[0] && g.lab[g.ghost[2].pos.y + 1][g.ghost[2].pos.x] != barreira[1])
            g.ghost[2].pos.y += 1;
    }

    if(g.pacman.pacdot > 32) // o clyde so se movimenta se mais de 32 pacdots forem coletadas
    {
        if(g.ghost[3].dir == right && g.lab[g.ghost[3].pos.y][g.ghost[3].pos.x + 1] != barreira[0])
            g.ghost[3].pos.x += 1;
        if(g.ghost[3].dir == left && g.lab[g.ghost[3].pos.y][g.ghost[3].pos.x - 1] != barreira[0])
            g.ghost[3].pos.x -= 1;
        if(g.ghost[3].dir == up && g.lab[g.ghost[3].pos.y - 1][g.ghost[3].pos.x] != barreira[0])
            g.ghost[3].pos.y -= 1;
        if(g.ghost[3].dir == down && g.lab[g.ghost[3].pos.y + 1][g.ghost[3].pos.x] != barreira[0] && g.lab[g.ghost[3].pos.y + 1][g.ghost[3].pos.x] != barreira[1])
            g.ghost[3].pos.y += 1;
    }

    return g;
}

t_game pacmov(t_game g)
{
    char barreira[2] = "#-";
    if(g.pacman.pos.x < 1) // teletransporta o pacman se ele passar pelos túneis laterais
        g.pacman.pos.x = 18;
    if(g.pacman.pos.x > 18)
        g.pacman.pos.x = 1;

    if(g.pacman.dir == right) // altera a posição do personagem e verifica as barreiras
    {
        if(barreira[0] != labmodel[g.pacman.pos.y][g.pacman.pos.x + 1])
            g.pacman.pos.x++;
    }
    else
        if(g.pacman.dir == left)
        {
            if(barreira[0] != labmodel[g.pacman.pos.y][g.pacman.pos.x - 1])
                g.pacman.pos.x--;
        }
        else
            if(g.pacman.dir == up)
            {
                if(barreira[0] != labmodel[g.pacman.pos.y - 1][g.pacman.pos.x])
                    g.pacman.pos.y--;
            }
            else
                if(g.pacman.dir == down)
                {
                    if(barreira[0] != labmodel[g.pacman.pos.y + 1][g.pacman.pos.x] && barreira[1] != labmodel[g.pacman.pos.y + 1][g.pacman.pos.x])
                        // também impede que o pacman passe pela porta dos fantasmas
                        g.pacman.pos.y++;
                }
    return g;
}
