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
 *                                                                         *
 *   Ameen Nasser Mohammed Abdul Kader, @Ameen7797                         *
 *   Bruno Alcantara Dias Rodrigues, @brunoalcantara26                     *
 *   Matheus Henrique De Arruda, @matheusarrudaaa                          *
 *   Vitoria Manuela Da Silva, @vitoriamanuela                             * 
 *                                                                         *
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
#include <time.h> /* Time and date functions */
#include <math.h> /* Mathematics functions */
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

    // tela do menu

    initscr(); //inicia a janela
    noecho(); // remove os imputs
    cbreak(); //fechar a janela usando a tecla crtl + c
    curs_set(FALSE);

    int i;
    int destaque;
    int escolha;
    int scrx, scry;
    int TempoInicio, TempoAtual;
    TempoAfraid = 0;
    char opcoes[3][30] = {"# JOGAR  #", "INSTRUCOES", "#  SAIR  #"};
    getmaxyx(stdscr, scry, scrx);


    if(!has_colors())
    {
        printw("o terminal nao consegue reproduzir cores");
        return -1;
    }

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    WINDOW *janela = newwin(scry - 5, scrx - 10, 2, 5);
    box(janela, 0, 0);
    refresh();
    wrefresh(janela);
    keypad(janela, true);

    // mostra a caixa de opcoes para ser escolhida pelo jogador
    while(1)
    {
        int k;

        for(k = 0; k < 15; k++) // Printa a logo do pac
        {
            wattron(janela, COLOR_PAIR(1));
            mvwprintw(janela, k + 1, scrx / 2 - 57, "%s", logo[k]);
            wattroff(janela, COLOR_PAIR(1));
        }

        for(i = 0; i < 3; i++)
        {
            mvwprintw(janela, 18, (scrx / 2) - 16, "ESCOLHA UMA OPCAO ABAIXO:");
            if(i == destaque) wattron(janela, A_REVERSE);
            mvwprintw(janela, i + 20, (scrx / 2) - 9, "%s", opcoes[i]);
            wattroff(janela, A_REVERSE);
        }
        escolha = wgetch(janela);
        switch(escolha) // nao permite que o indicador da opcao do jogador saia da tela
        {
            case KEY_UP:
                destaque--;
                if(destaque == -1)
                    destaque = 0;
                break;
            case KEY_DOWN:
                destaque++;
                if(destaque == 3)
                    destaque = 2;
                break;
            default:
                break;
        }
        if(escolha == '\n' && destaque == 0) // a opcao 1 para iniciar o jogo
            break;

        if(escolha == '\n' && destaque == 1) // a opcao 2 vai para tela do help
            pacHelp(scry, scrx);
        if(escolha == '\n' && destaque == 2) // opcao de sair do jogo
        {
            clear();
            endwin();
            return EXIT_SUCCESS;
        }
    }

//----------------------------------//

    IFDEBUG("main()\n");
    int opt; /* return from getopt() */
    t_game g; /* the game */
    const char *sready = "Are you ready? (y/n)"; /* ready string */
    int kin; /* keyboard input */

//----------------------------------//

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


    g = upecman_init();

    printlab(scrx, scry, g);
    g.lab[17][9] = ' ';

    mvprintw(10, 33, "%s", sready);
    refresh();
    getmaxyx(stdscr, scry, scrx);


    while(1) // opcao q o jogador vai escolher pra comecar a jogar
    {
        kin = getch();
        if(kin == 'y') // se apertar 'y' o jogo inicia
            break;


        if(kin == 'n') // se apertar 'n' o jogo sai
        {
            endwin();
            return EXIT_SUCCESS;
        }


        usleep(16667); /* wait 16666 microseconds to avoid frying the processor (1/60 s) */
    }

    TempoInicio = time(NULL);
    g.pacman.next = left;

    /* write your code here */
    while(kin != 'e')
    {
        usleep(250000);
        /* Keyboard input for pacman directions */

        kin = getch(); // vai receber o comando do jogador
        if(kin == KEY_LEFT)
            g.pacman.next = left;
        if(kin == KEY_RIGHT)
            g.pacman.next = right;
        if(kin == KEY_DOWN)
            g.pacman.next = down;
        if(kin == KEY_UP)
            g.pacman.next = up;


        g.pacman = mvpacman(g); // funcao da movimentação do pacman
        printlab(scrx, scry, g); // funcao para printar o labirinto
        g = pastilhas(g);//funcao das pastilhas

        if((TempoAfraid == 0) || (TempoAfraid == 1 && clock() - afraid_t > 20000)) // temporizador para trocar o modo afraid e scatter
        {
            TempoAfraid = 0;
            TempoAtual = time(NULL);
            g = temporizador(g, TempoInicio, TempoAtual); // funcao do temporizador
       }

        g = cereja(g, TempoInicio, TempoAtual); // funcao das cerejas
        g = modosfantasmas(g); // funcao dos modos dos fantasmas
        g = colisaofantasma(g); // funcao da interacao dos fantasmas com o pacman

        if(g.pacman.life == 0) // quando ele perde todas as vidas
        {
            while(1)
            {
                mvprintw(scry / 2 - 13, scrx / 2 - 10, "Vida: 0");
                attron(COLOR_PAIR(1));
                mvprintw(16, 91, " ______________________________");
                mvprintw(17, 91, "|         GAMER OVER!!!        |");
                attroff(COLOR_PAIR(1));
                mvprintw(18, 91, "|                              |");
                mvprintw(19, 90, " | Pressione 'y' para Reiniciar |");
                mvprintw(20, 90, " | Pressione 'n' para Sair.     |");
                mvprintw(21, 91, "|______________________________|");

                int  kin = 0;
                kin = getch();
                if(kin == 'y')
                {
                    g = upecman_init();
                    printlab(scry, scrx, g);
                    break;
                }
                if(kin == 'n')
                {
                    endwin();
                    return EXIT_SUCCESS;
                }
            }
        }
        if(g.pacman.pellet == 189) // quando o jogador pega todos os pontos
        {
            while(1)
            {
                attron(COLOR_PAIR(4));
                mvprintw(16, 91, " ______________________________");
                mvprintw(17, 91, "|   PARABENS, VOCE GANHOU!!!   |");
                attroff(COLOR_PAIR(4));
                mvprintw(18, 91, "|                              |");
                mvprintw(19, 90, " | Pressione 'y' para Reiniciar |");
                mvprintw(20, 90, " | Pressione 'n' para Sair.     |");
                mvprintw(21, 91, "|______________________________|");

                kin = getch();
                if(kin == 'y')
                {
                    g = upecman_init();
                    printlab(scrx, scry, g);
                    break;
                }
                if(kin == 'n')
                {
                    endwin();
                    return EXIT_SUCCESS;
                }
            }
        }
    }
    clear();
    endwin();
    return EXIT_SUCCESS;
}

void pacHelp(int scry, int scrx)  //Funcao que mostra a tela help
{
    WINDOW *help = newwin(scry - 3, scrx - 7, 2, 5);
    box(help, 0, 0);
    refresh();

    mvprintw((scry / 2) - 13, (scrx / 2) - 10, "CONTROLES DO PACMAN");

    mvprintw((scry / 2) - 11, (scrx / 2) - 3, "KEY_UP");
    mvprintw((scry / 2) - 9, (scrx / 2), "^");

    mvprintw((scry / 2) - 7, (scrx / 2) - 16, "KEY_LEFT");
    mvprintw((scry / 2) - 7, (scrx / 2) - 6, "<");

    mvprintw((scry / 2) - 7, (scrx / 2) + 6, ">");
    mvprintw((scry / 2) - 7, (scrx / 2) + 9, "KEY_RIGHT");

    mvprintw((scry / 2) - 4, (scrx / 2), "v");
    mvprintw((scry / 2) - 3, (scrx / 2) - 3, "KEY_DOWN");

    mvprintw((scry / 2), (scrx / 2) - 4, "PAUSE : P");
    mvprintw((scry / 2 - 5) + 6, (scrx / 2) - 4, "SAIR : e");

    mvprintw((scry / 2 - 5) + 8, (scrx / 2) - 60, "VIDA___________________________________________");
    mvprintw((scry / 2 - 5) + 9, (scrx / 2) - 60, "* O PACMAN '@' TEM 3 VIDAS NO INICIO DA PARTIDA.");
    mvprintw((scry / 2 - 5) + 10, (scrx / 2) - 60, "* CASO O FANTASMA ATAQUE, O PACMAN PERDE 1 VIDA.");
    mvprintw((scry / 2 - 5) + 11, (scrx / 2) - 60, "* CASO TODAS AS PASTILHAS COMIDAS, O JOGO REINICIA E O PACMAN GANHA 1 VIDA EXTRA.");
    mvprintw((scry / 2 - 5) + 12, (scrx / 2) - 60, "PONTUACAO_________________");
    mvprintw((scry / 2 - 5) + 13, (scrx / 2) - 60, "* PASTILHA COMUM '.' -> 10");
    mvprintw((scry / 2 - 5) + 14, (scrx / 2) - 60, "* PASTILHA GRANDE 'o' -> 50");
    mvprintw((scry / 2 - 5) + 15, (scrx / 2) - 60, "* CEREJA '%' -> 100");
    mvprintw((scry / 2 - 5) + 16, (scrx / 2) - 60, "* FANTASMAS 'P, B, I, C'(CADA) -> 750");

    mvprintw((scry / 2) + 14, (scrx / 2) - 60, "<<Back");

    mvprintw((scry / 2) + 13, (scrx / 2) - 45, "OBJETIVO: O JOGADOR DEVE COMER TODAS AS PASTILHAS DOS LABIRINTOS SEM SER PEGOS POR FANTASMAS.");

    wrefresh(help);
    getch();
    clear();
    endwin();
    refresh();
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
    printf("\nUsage: ./%s [-h|-v|-c]\n", "upecman");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}
//
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
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
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
t_game upecman_init(void)
{
    IFDEBUG("init()");
    /* initialization */

    t_game g;
    int f, y;

    for(y = 0; y < LABL; y++)
        strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */

    g.pacman.pos.y = 17; /* pacman start position (line) */
    g.pacman.pos.x = 9; /* pacman start position (column) */
    g.pacman.dir = left; /* pacman start direction */
    g.pacman.life = 3; /* 3 lifes */
    g.pacman.score = 0; /* 0 points */
    g.pacman.pellet = 0; /* pellets do mapa */

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
                g.ghost[f].pos.x = 10; /* pinky start position (column) */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
                break;
            case inky:
                g.ghost[f].pos.y = 10; /* inky start position (line) */
                g.ghost[f].pos.x = 10; /* inky start position (column) */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case clyde:
                g.ghost[f].pos.y = 11; /* clyde start position (line) */
                g.ghost[f].pos.x = 10; /* clyde start position (column) */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
        }
        g.ghost[f].dir = left; /* start direction and future direction: left */
        g.ghost[f].mode = chase;
    }

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

    return g;
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


void printlab(int scrx, int scry, t_game g) // printa o mapa do jogo
{

    int y;

    for(y = 0; y < LABL; y++) // mostrar o mapa
        printw("%s\n", g.lab[y]);


    clear(); /* clear the screen */

    coresdolab(scrx, scry, g);

    mvprintw(g.pacman.pos.y + scry / 2 - 11, g.pacman.pos.x + scrx / 2 - 10, "@"); // mostrar o pacman na tela
    attron(COLOR_PAIR(6));

    for(int i = blinky; i <= clyde; i++) // cores e posicao do blinky, pinky, inky and clyde (fantasmas do jogo)
    {

        if(i == blinky) //red
        {
            if(g.ghost[i].mode != afraid)
            {
                mvprintw(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, "B");
                mvchgat(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, 1, A_BOLD, 1, NULL);
            }
            else
            {
                mvprintw(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, "B");
                mvchgat(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, 1, A_BOLD, 5, NULL);
            }
        }

        if(i == pinky) //magenta
        {
            if(g.ghost[i].mode != afraid)
            {
                mvprintw(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, "P");
                mvchgat(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, 1, A_BOLD, 2, NULL);
            }
            else
            {
                mvprintw(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, "P");
                mvchgat(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, 1, A_BOLD, 5, NULL);
            }
        }

        if(i == inky) //cyan
        {
            if(g.ghost[i].mode != afraid)
            {
                mvprintw(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, "I");
                mvchgat(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, 1, A_BOLD, 3, NULL);
            }
            else
            {
                mvprintw(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, "I");
                mvchgat(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, 1, A_BOLD, 5, NULL);
            }
        }

        if(i == clyde) //green
        {
            if(g.ghost[i].mode != afraid)
            {
                mvprintw(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, "C");
                mvchgat(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, 1, A_BOLD, 4, NULL);
            }
            else
            {
                mvprintw(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, "C");
                mvchgat(g.ghost[i].pos.y + scry / 2 - 11, g.ghost[i].pos.x + scrx / 2 - 10, 1, A_BOLD, 5, NULL);
            }
        }
    }

    mvchgat(g.pacman.pos.y + scry / 2 - 11, g.pacman.pos.x + scrx / 2 - 10, 1, A_BOLD, 6, NULL); // cor do pacman (amarelo)

    refresh();
}


void coresdolab(int scrx, int scry, t_game g) // mostra as cores do labirinto
{
    int y, k, v;


    // pintar o '#' de azul
    attron(COLOR_PAIR(5));
    for(y = 0; y < LABL; y++)
        mvprintw(scry / 2 + y - 11, scrx / 2 - 10, "%s\n", g.lab[y]);
    attroff(COLOR_PAIR(5));


    // pintar o '.' de amarelo e 'O ' de branco
    for(y = 0; y < LABL; y++)
        for(k = 0; k < LABC; k++)
            if(g.lab[y][k] == '.')
                mvchgat(scry / 2 + y - 11, scrx / 2 - 10 + k, 1, A_BOLD, 6, NULL);
    for(y = 0; y < LABL; y++)
        for(k = 0; k < LABC; k++)
            if(g.lab[y][k] == 'o')
                mvchgat(scry / 2 + y - 11, scrx / 2 - 10 + k, 1, A_BOLD, 0, NULL);

    // pintar o '%' (cereja) de vermelho
    for(y = 0; y < LABL; y++)
        for(k = 0; k < LABC; k++)
            if(g.lab[y][k] == '%')
                mvchgat(scry / 2 + y - 11, scrx / 2 - 10 + k, 1, A_BOLD, 1, NULL);

    mvprintw(scry / 2 - 13, scrx / 2 - 10, "Vida: %d", g.pacman.life);
    mvprintw(scry / 2 - 13, scrx / 2 + 1, "Score: %d", g.pacman.score);

    //printa os fantasmas na mesma tela do labirinto
    for(v = 0; v < 10; v++)
    {
        attron(COLOR_PAIR(1));
        mvprintw(v + 15, scrx / 2 - 33, "%s", buh[v]);
        attroff(COLOR_PAIR(1));
    }

    mvprintw(scry / 2 + 3, scrx / 2 - 28, "##");
    mvprintw(scry / 2 + 4, scrx / 2 - 28, "##");
    mvprintw(scry / 2 + 3, scrx / 2 - 21, "##");
    mvprintw(scry / 2 + 4, scrx / 2 - 21, "##");

    for(v = 0; v < 10; v++)
    {
        attron(COLOR_PAIR(2));
        mvprintw(v + 15, scrx / 2 - 55, "%s", buh[v]);
        attroff(COLOR_PAIR(2));
    }

    mvprintw(scry / 2 + 3, scrx / 2 - 43, "##");
    mvprintw(scry / 2 + 4, scrx / 2 - 43, "##");
    mvprintw(scry / 2 + 3, scrx / 2 - 50, "##");
    mvprintw(scry / 2 + 4, scrx / 2 - 50, "##");
}


t_pacman mvpacman(t_game g) // movimentacao do pacman
{
    int xnext = 0, ynext = 0;

    if(g.pacman.next == down) // posicao para baixo
        if(g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] == '.' || g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] == ' ' || g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] == 'o' || g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] == '%')
            g.pacman.dir = down;

    if(g.pacman.dir == down)
    {
        if(g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] == '.' || g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] == ' ' || g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] == 'o' || g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] == '%')
        {
            xnext = 0;
            ynext = +1;
        }
        else
        {
            xnext = 0;
            ynext = 0;
        }
    }

    if(g.pacman.next == right) // posicao para direita
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] == '.' || g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] == ' ' || g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] == 'o' || g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] == '%')
            g.pacman.dir = right;

    if(g.pacman.dir == right)
    {
        if(g.pacman.pos.x == 19 && g.pacman.pos.y == 10) // portal do lado direito
        {
            g.pacman.pos.x = 0;
            g.pacman.pos.y = 10;
        }
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] == '.' || g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] == ' ' || g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] == 'o' || g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] == '%')
        {
            xnext = +1;
            ynext = 0;
        }
        else
        {
            xnext = 0;
            ynext = 0;
        }
    }

    if(g.pacman.next == up) // posicao para cima
        if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] == '.' || g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] == ' ' || g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] == 'o' || g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] == '%')
            g.pacman.dir = up;

    if(g.pacman.dir == up)
    {
        if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] == '.' || g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] == ' ' || g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] == 'o' || g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] == '%')
        {
            xnext = 0;
            ynext = -1;
        }
        else
        {
            xnext = 0;
            ynext = 0;
        }
    }


    if(g.pacman.next == left) // posicao para esquerda
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] == '.' || g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] == ' ' || g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] == 'o' || g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] == '%')
            g.pacman.dir = left;

    if(g.pacman.dir == left)
    {
        if(g.pacman.pos.x == 0 && g.pacman.pos.y == 10) // portal do lado esquerdo
        {
            g.pacman.pos.x = 19;
            g.pacman.pos.y = 10;
        }
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] == '.' || g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] == ' ' || g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] == 'o' || g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] == '%')
        {
            xnext = -1;
            ynext = 0;
        }
        else
        {
            xnext = 0;
            ynext = 0;
        }
    }

    g.pacman.pos.y += ynext;
    g.pacman.pos.x += xnext;

    return g.pacman;

}


t_game pastilhas(t_game g) // as pastilhas que o pacman come
{
    int j = 0;

    while(g.lab[g.pacman.pos.y][g.pacman.pos.x] == '.')
    {
        g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
        g.pacman.score += 10;
        g.pacman.pellet++;
    }
    while(g.lab[g.pacman.pos.y][g.pacman.pos.x] == 'o')
    {
        TempoAfraid = 1;
        afraid_t = clock();
        g.pacman.pellet++;
        g.pacman.score += 50;
        g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
        for(j = blinky; j <= clyde; j++)
            g.ghost[j].mode = afraid;
    }
    return g;
}


t_game modosfantasmas(t_game g) // os 4 modos que os fantasmas podem ficar
{
    int i;
    float dx, dy;


    for(i = blinky; i <= clyde; i++)
    {
        switch(i)
        {
            case(blinky):
            {
                if(g.ghost[i].mode == chase)
                {
                    g.ghost[i].starget.y = g.pacman.pos.y;
                    g.ghost[i].starget.x = g.pacman.pos.x;
                }
                if(g.ghost[i].mode == scatter)
                {
                    g.ghost[i].starget.y = 0;
                    g.ghost[i].starget.x = 19;
                }
                if(g.ghost[i].mode == dead)
                {
                    g.ghost[i].pos.y = 10;
                    g.ghost[i].pos.x = 10;
                    g.ghost[i].mode = chase;
                    continue;
                }
                if(g.ghost[i].mode == afraid)
                {
                    g.ghost[i].starget.y = rand() % 20;
                    g.ghost[i].starget.x = rand() % 20;
                }
                break;
            }


            case(pinky):
            {
                /* sair da casa dos fantasmas */
                if(g.ghost[i].pos.y > 7 && g.ghost[i].pos.y <= 11 && g.ghost[i].pos.x == 10)
                {
                    g.ghost[i].pos.y--;
                    continue;
                }

                if(g.ghost[i].pos.y == 7 && g.ghost[i].pos.x == 10 && g.ghost[i].pos.x <= 12)
                {
                    g.ghost[i].pos.x++;
                    continue;
                }


                if(g.ghost[i].mode == scatter)
                {
                    g.ghost[i].starget.y = 0;
                    g.ghost[i].starget.x = 0;
                }

                if(g.ghost[i].mode == chase)
                {
                    if(g.pacman.dir == up)
                    {
                        g.ghost[i].starget.x = g.pacman.pos.x - 4;

                        if(g.pacman.pos.y + 4 > 22)
                            g.ghost[i].starget.y = 22;
                        else
                            g.ghost[i].starget.y = g.pacman.pos.y + 4;
                    }
                    if(g.pacman.dir == down)
                    {
                        g.ghost[i].starget.x = g.pacman.pos.x;

                        if(g.pacman.pos.y - 4 < 0)
                            g.ghost[i].starget.y = 0;
                        else
                            g.ghost[i].starget.y = g.pacman.pos.y - 4;
                    }
                    if(g.pacman.dir == left)
                    {
                        g.ghost[i].starget.y = g.pacman.pos.y;

                        if(g.pacman.pos.x - 4 < 0)
                            g.ghost[i].starget.x = 0;
                        else
                            g.ghost[i].starget.x = g.pacman.pos.x - 4;
                    }
                    if(g.pacman.dir == right)
                    {
                        g.ghost[i].starget.y = g.pacman.pos.y;

                        if(g.pacman.pos.x + 4 > 19)
                            g.ghost[i].starget.x = 19;
                        else
                            g.ghost[i].starget.x = g.pacman.pos.x + 4;
                    }

                }

                if(g.ghost[i].mode == dead)
                {
                    g.ghost[i].pos.y = 9;
                    g.ghost[i].pos.x = 10;
                    g.ghost[i].mode = chase;
                    continue;
                }

                if(g.ghost[i].mode == afraid)
                {
                    g.ghost[i].starget.y = rand() % 20;
                    g.ghost[i].starget.x = rand() % 20;
                }
                break;
            }



            case(clyde):
            {
                /* sair da casa dos fantasmas */
                if(g.ghost[i].pos.y > 7 && g.ghost[i].pos.y <= 11 && g.ghost[i].pos.x == 10)
                {
                    g.ghost[i].pos.y--;
                    continue;
                }


                if(g.ghost[i].mode == chase)
                {
                    dy = g.pacman.pos.y - g.ghost[i].pos.y;
                    dx = g.pacman.pos.x - g.ghost[i].pos.x;

                    if((dy + dx) >= 8)
                        g.ghost[i].starget = g.pacman.pos;

                    else
                    {
                        g.ghost[i].starget.y = 22;
                        g.ghost[i].starget.x = 0;
                    }
                }
                if(g.ghost[i].mode == scatter)
                {
                    g.ghost[i].starget.y = 22;
                    g.ghost[i].starget.x = 0;
                }
                if(g.ghost[i].mode == dead)
                {
                    g.ghost[i].pos.y = 11;
                    g.ghost[i].pos.x = 10;
                    g.ghost[i].mode = chase;
                    continue;
                }

                if(g.ghost[i].mode == afraid)
                {
                    g.ghost[i].starget.y = rand() % 20;
                    g.ghost[i].starget.x = rand() % 20;
                }
                break;
            }



            case(inky):
            {
                /* sair da casa dos fantasmas */
                if(g.ghost[i].pos.y > 7 && g.ghost[i].pos.y <= 11 && g.ghost[i].pos.x == 10)
                {
                    g.ghost[i].pos.y--;
                    continue;
                }

                if(g.ghost[i].pos.y == 7 && g.ghost[i].pos.x == 10 && g.ghost[i].pos.x <= 13)
                {
                    g.ghost[i].pos.x++;
                    continue;
                }

                if(g.ghost[i].mode == scatter)
                {
                    g.ghost[i].starget.y = 22;
                    g.ghost[i].starget.x = 19;
                }

                if(g.ghost[i].mode == chase)
                {
                    dy = g.pacman.pos.y - g.ghost[blinky].pos.y;
                    dx = g.pacman.pos.x - g.ghost[blinky].pos.x;

                    if(g.pacman.dir == up)
                    {
                        g.ghost[i].starget.x = g.pacman.pos.x + dx;

                        if(g.pacman.pos.y + 2 + 2 * dy > 22)
                            g.ghost[i].starget.y = 22;
                        else
                            g.ghost[i].starget.y = g.pacman.pos.y + 2 + 2 * dy;
                    }
                    if(g.pacman.dir == down)
                    {
                        g.ghost[i].starget.x = g.pacman.pos.x + dx;

                        if(g.pacman.pos.y - 2 - 2 * dy < 0)
                            g.ghost[i].starget.y = 0;
                        else
                            g.ghost[i].starget.y = g.pacman.pos.y - 2 - 2 * dy;
                    }

                    if(g.pacman.dir == left)
                    {
                        g.ghost[i].starget.y = g.pacman.pos.y + dy;

                        if(g.pacman.pos.x - 2 - 2 * dx < 0)
                            g.ghost[i].starget.x = 0;
                        else
                            g.ghost[i].starget.x = g.pacman.pos.x - 2 - 2 * dx;
                    }
                    if(g.pacman.dir == right)
                    {
                        g.ghost[i].starget.y = g.pacman.pos.y + dy;

                        if(g.pacman.pos.x + 2 + 2 * dx > 20)
                            g.ghost[i].starget.x = 20;
                        else
                            g.ghost[i].starget.x = g.pacman.pos.x + 2 + 2 * dx;
                    }
                }

                if(g.ghost[i].mode == dead)
                {
                    g.ghost[i].pos.y = 10;
                    g.ghost[i].pos.x = 10;
                    g.ghost[i].mode = chase;
                    continue;
                }

                if(g.ghost[i].mode == afraid)
                {
                    g.ghost[i].starget.y = 22;
                    g.ghost[i].starget.x = 19;
                }

                break;
            }
        }
        g = IAfantasmas(g, i);
    }
    return g;
}


int hipotenusa(int py, int sty, int px, int stx) // funcao para calcular a hipotenusa quando necessaria
{
    return sqrt(pow(py - sty, 2) + pow(px - stx, 2));
}


t_game IAfantasmas(t_game g, int i) // Inteligencia Artificial dos fantasmas
{

    int py, px, sty, stx;
    py = g.ghost[i].pos.y;
    px = g.ghost[i].pos.x;
    sty = g.ghost[i].starget.y;
    stx = g.ghost[i].starget.x;

    float h[4] = {0}; //variavel das hipotenusas
    float c[4] = {0}; //variavel dos caminhos
    int posicao;



    /* armazena os dados das possiveis direcoes que o fantasma pode ir */
    if((g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != '#') && (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != '-') && (g.ghost[i].dir != left))
    {
        c[0] = 1;
        h[0] = hipotenusa(py, sty, px + 1, stx);
    }


    if((g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != '#') && (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != '-') && (g.ghost[i].dir != right))
    {
        c[1] = 1;
        h[1] = hipotenusa(py, sty, px - 1, stx);
    }


    if((g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != '#') && (g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != '-') && (g.ghost[i].dir != up))
    {
        c[2] = 1;
        h[2] = hipotenusa(py + 1, sty, px, stx);
    }


    if((g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != '#') && (g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != '-') && (g.ghost[i].dir != down))
    {
        c[3] = 1;
        h[3] = hipotenusa(py - 1, sty, px, stx);
    }



    /* calcula a melhor rota para poder andar, levando em consideracao a hipotenusa do fantasma em relacao a onde ele se encontra e seu lugar de preferencia */
    if(c[0] == 1 && c[1] == 0 && c[2] == 0 && c[3] == 0)
        posicao = direita;

    if(c[0] == 0 && c[1] == 1 && c[2] == 0 && c[3] == 0)
        posicao = esquerda;

    if(c[0] == 0 && c[1] == 0 && c[2] == 1 && c[3] == 0)
        posicao = baixo;

    if(c[0] == 0 && c[1] == 0 && c[2] == 0 && c[3] == 1)
        posicao = cima;

    if(c[0] == 1 && c[1] == 1 && c[2] == 0 && c[3] == 0)
    {
        if(h[0] < h[1])
            posicao = direita;

        else
            posicao = esquerda;
    }

    if(c[0] == 1 && c[1] == 0 && c[2] == 1 && c[3] == 0)
    {
        if(h[0] < h[2])
            posicao = direita;

        else
            posicao = baixo;
    }

    if(c[0] == 1 && c[1] == 0 && c[2] == 0 && c[3] == 1)
    {
        if(h[0] < h[3])
            posicao = direita;

        else
            posicao = cima;
    }

    if(c[0] == 0 && c[1] == 1 && c[2] == 1 && c[3] == 0)
    {
        if(h[1] < h[2])
            posicao = esquerda;

        else
            posicao = baixo;
    }

    if(c[0] == 0 && c[1] == 1 && c[2] == 0 && c[3] == 1)
    {
        if(h[1] < h[2])
            posicao = esquerda;

        else
            posicao = cima;
    }

    if(c[0] == 0 && c[1] == 0 && c[2] == 1 && c[3] == 1)
    {
        if(h[2] < h[3])
            posicao = baixo;

        else
            posicao = cima;
    }

    if(c[0] == 1 && c[1] == 1 && c[2] == 1 && c[3] == 0)
    {
        if(h[0] < h[1] && h[0] <= h[2])
            posicao = direita;

        if(h[1] < h[2] && h[0] <= h[2])
            posicao = esquerda;

        else
            posicao = baixo;
    }

    if(c[0] == 1 && c[1] == 1 && c[2] == 0 && c[3] == 1)
    {
        if(h[0] < h[1] && h[0] < h[3])
            posicao = direita;

        if(h[1] < h[3] && h[1] < h[0])
            posicao = esquerda;

        else
            posicao = cima;

    }

    if(c[0] == 0 && c[1] == 1 && c[2] == 1 && c[3] == 1)
    {
        if(h[2] < h[1] && h[2] < h[3])
            posicao = baixo;

        if(h[1] < h[2] && h[1] < h[3])
            posicao = esquerda;

        else
            posicao = cima;
    }

    if(c[0] == 1 && c[1] == 0 && c[2] == 1 && c[3] == 1)
    {
        if(h[0] < h[2] && h[0] < h[3])
            posicao = direita;

        if(h[2] < h[0] && h[2] < h[3])
            posicao = baixo;

        else
            posicao = cima;
    }

    if(c[0] == 1 && c[1] == 1 && c[2] == 1 && c[3] == 1)
    {
        if(h[0] < h[2] && h[0] < h[3] && h[0] < h[1])
            posicao = direita;

        if(h[1] < h[2] && h[1] < h[3] && h[1] < h[0])
            posicao = esquerda;

        if(h[2] < h[0] && h[2] < h[3] && h[2] < h[1])
            posicao = baixo;

        else
            posicao = cima;
    }


    switch(posicao)
    {
        case(direita):
        {
            g.ghost[i].pos.x++;
            g.ghost[i].dir = right;
            break;
        }

        case(esquerda):
        {
            g.ghost[i].pos.x--;
            g.ghost[i].dir = left;
            break;
        }

        case(baixo):
        {
            g.ghost[i].pos.y++;
            g.ghost[i].dir = down;
            break;
        }

        case(cima):
        {
            g.ghost[i].pos.y--;
            g.ghost[i].dir = up;
            break;
        }

        default:
            break;
    }

    /* portal de teleporte dos fantasmas */
    if(g.ghost[i].pos.x == 0 && g.ghost[i].pos.y == 10)
        g.ghost[i].pos.x = 18, g.ghost[i].pos.y = 10;
    if(g.ghost[i].pos.x == 19 && g.ghost[i].pos.y == 10)
        g.ghost[i].pos.x = 1, g.ghost[i].pos.y = 10;

    return g;

}


t_game temporizador(t_game g, int TempoInicio, int TempoAtual) // temporizador que calcula o tempo para os fantasmas mudarem o seu modo
{
    for(int i = blinky; i <= clyde; i++)
    {

        if(TempoAtual - TempoInicio <= 7)
            g.ghost[i].mode = scatter;
        else
        if(TempoAtual - TempoInicio <= 25)
            g.ghost[i].mode = chase;
        else
        if(TempoAtual - TempoInicio <= 30)
            g.ghost[i].mode = scatter;
        else
        if(TempoAtual - TempoInicio <= 57)
            g.ghost[i].mode = chase;
        else
        if(TempoAtual - TempoInicio <= 62)
            g.ghost[i].mode = scatter;
        else
        if(TempoAtual - TempoInicio <= 82)
            g.ghost[i].mode = chase;
        else
        if(TempoAtual - TempoInicio <= 87)
            g.ghost[i].mode = scatter;
        else
            g.ghost[i].mode = chase;
    }
    return g;
}


t_game cereja(t_game g, int TempoInicio, int TempoAtual) // funcao para aparecer as cerejas no mapa
{
    int tempo;
    tempo = TempoAtual - TempoInicio;

    /* as cerejas vao aparecer durante certo tempo no mapa, depois elas somem */
    if(tempo >= 10 && tempo <= 20 && g.pacman.cereja1 == 0)
    {
        g.lab[17][9] = '%';

        if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == '%' && (tempo >= 10 && tempo <= 20))
        {
            g.lab[17][9] = ' ';
            g.pacman.score += 400;
            g.pacman.cereja1 += 1;
        }
    }

    if(tempo >= 20 && tempo <= 40)
        g.lab[17][9] = ' ';

    if(tempo >= 40 && tempo <= 50 && g.pacman.cereja2 == 0)
    {
        g.lab[17][9] = '%';

        if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == '%' && (tempo >= 40 && tempo <= 50))
        {
            g.lab[17][9] = ' ';
            g.pacman.score += 400;
            g.pacman.cereja2 += 1;
        }
    }

    if(tempo >= 50 && tempo <= 70)
        g.lab[17][9] = ' ';

    if(tempo >= 70 && tempo <= 80 && g.pacman.cereja3 == 0)
    {
        g.lab[17][9] = '%';

        if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == '%' && (tempo >= 70 && tempo <= 80))
        {
            g.lab[17][9] = ' ';
            g.pacman.score += 400;
            g.pacman.cereja3 += 1;
        }
    }

    if(tempo >= 80)
        g.lab[17][9] = ' ';


    return g;
}


t_game colisaofantasma(t_game g) // interacao dos fantasmas com o pacman
{
    int a;


    for(a = blinky; a <= clyde; a++)
    {
        /* se a posicao do pacman for exatamente igual a do fantasma, ha uma colisao */
        if((g.pacman.pos.y == g.ghost[a].pos.y && g.pacman.pos.x == g.ghost[a].pos.x) || (g.pacman.dir == left && g.ghost[a].dir == right && g.pacman.pos.x == g.ghost[a].pos.x - 1 && g.pacman.pos.y == g.ghost[a].pos.y) || (g.pacman.dir == right && g.ghost[a].dir == left && g.pacman.pos.x == g.ghost[a].pos.x + 1 && g.pacman.pos.y == g.ghost[a].pos.y) || (g.pacman.dir == up && g.ghost[a].dir == down && g.pacman.pos.x == g.ghost[a].pos.x && g.pacman.pos.y == g.ghost[a].pos.y - 1) || (g.pacman.dir == down && g.ghost[a].dir == up && g.pacman.pos.x == g.ghost[a].pos.x && g.pacman.pos.y == g.ghost[a].pos.y + 1))
        {
            switch(a)
            {
                case blinky:

                    if((g.ghost[a].mode == scatter) || (g.ghost[a].mode == chase))

                    {
                        usleep(500000);
                        g.pacman.life--;
                        g.lab[17][9] = ' ';
                        g.pacman.pos.y = 17;
                        g.pacman.pos.x = 9;
                        g.pacman.next = left;
                        g.ghost[blinky].pos.y = 7;
                        g.ghost[blinky].pos.x = 9;
                        g.ghost[pinky].pos.y = 9;
                        g.ghost[pinky].pos.x = 10;
                        g.ghost[inky].pos.y = 10;
                        g.ghost[inky].pos.x = 10;
                        g.ghost[clyde].pos.y = 11;
                        g.ghost[clyde].pos.x = 10;
                        break;

                    }
                    else
                        if(g.ghost[a].mode == afraid)
                        {
                            g.pacman.score += 750;
                            g.ghost[a].pos.y = 7;
                            g.ghost[a].pos.x = 9;
                            g.ghost[a].mode = scatter;
                            break;
                        }
                        else
                            continue;

                case pinky:
                    if((g.ghost[a].mode == scatter) || (g.ghost[a].mode == chase))
                    {
                        usleep(500000);
                        g.pacman.life--;
                        g.lab[17][9] = ' ';
                        g.pacman.pos.y = 17;
                        g.pacman.pos.x = 9;
                        g.pacman.next = left;
                        g.ghost[blinky].pos.y = 7;
                        g.ghost[blinky].pos.x = 9;
                        g.ghost[pinky].pos.y = 9;
                        g.ghost[pinky].pos.x = 10;
                        g.ghost[inky].pos.y = 10;
                        g.ghost[inky].pos.x = 10;
                        g.ghost[clyde].pos.y = 11;
                        g.ghost[clyde].pos.x = 10;
                        break;
                    }
                    else
                        if(g.ghost[a].mode == afraid)
                        {
                            g.pacman.score += 750;
                            g.ghost[a].pos.y = 9;
                            g.ghost[a].pos.x = 10;
                            g.ghost[a].mode = scatter;
                            break;
                        }
                        else
                            continue;

                case inky:
                    if((g.ghost[a].mode == scatter) || (g.ghost[a].mode == chase))
                    {
                        usleep(500000);
                        g.pacman.life--;
                        g.lab[17][9] = ' ';
                        g.pacman.pos.y = 17;
                        g.pacman.pos.x = 9;
                        g.pacman.next = left;
                        g.ghost[blinky].pos.y = 7;
                        g.ghost[blinky].pos.x = 9;
                        g.ghost[pinky].pos.y = 9;
                        g.ghost[pinky].pos.x = 10;
                        g.ghost[inky].pos.y = 10;
                        g.ghost[inky].pos.x = 10;
                        g.ghost[clyde].pos.y = 11;
                        g.ghost[clyde].pos.x = 10;
                        break;
                    }
                    else
                        if(g.ghost[a].mode == afraid)
                        {
                            g.pacman.score += 750;
                            g.ghost[a].pos.y = 10;
                            g.ghost[a].pos.x = 10;
                            g.ghost[a].mode = scatter;
                            break;
                        }
                        else
                            continue;

                case clyde:
                    if((g.ghost[a].mode == scatter) || (g.ghost[a].mode == chase))
                    {
                        usleep(500000);
                        g.pacman.life--;
                        g.lab[17][9] = ' ';
                        g.pacman.pos.y = 17;
                        g.pacman.pos.x = 9;
                        g.pacman.next = left;
                        g.ghost[blinky].pos.y = 7;
                        g.ghost[blinky].pos.x = 9;
                        g.ghost[pinky].pos.y = 9;
                        g.ghost[pinky].pos.x = 10;
                        g.ghost[inky].pos.y = 10;
                        g.ghost[inky].pos.x = 10;
                        g.ghost[clyde].pos.y = 11;
                        g.ghost[clyde].pos.x = 10;
                        break;
                    }
                    else
                        if(g.ghost[a].mode == afraid)
                        {
                            g.pacman.score += 750;
                            g.ghost[a].pos.y = 11;
                            g.ghost[a].pos.x = 10;
                            g.ghost[a].mode = scatter;
                            break;
                        }
                        else
                            continue;
            }
        }
    }
    return g;
}
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
