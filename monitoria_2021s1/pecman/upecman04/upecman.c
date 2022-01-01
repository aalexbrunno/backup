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
 ***************************************************************************
 * Vinicius Marzo De Araujo, @viniciusmarzo752                             *
 * Maria Vitoria De Quairoz Cabral, @mvqc                                  *
 * Bernardo Lima Milhomens Salomoni, @BernaSalomoni                        *
 * Matheus Buarque Cousseiro, @MatheusBuarq                                *
 ***************************************************************************
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
    IFDEBUG("main()\n");
    int opt; /* return from getopt() */
    t_game g; /* the game */
    const char *sready = "Are you ready? (y/n)"; /* ready string */
    int kin; /* keyboard input */
    t_direction prox = left; /* proxima direcao do pacman */
    clock_t start_t; /* inicializa o temporizador */

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

    printlab(g);
    pacWelcome();

    curs_set(FALSE);
    mvprintw(10, 25, "%s", sready);
    refresh();

    while(1)
    {
        kin = getch();
        if(kin == 'y' || kin == KEY_LEFT)
            break;
        if(kin == 'n')
        {
            endwin();
            return EXIT_SUCCESS;
        }
        usleep(16667); /* wait 16666 microseconds to avoid frying the processor (1/60 s) */
    }

    start_t = clock();

    while(1)
    {
        usleep(250000);
        kin = getch();

        if(kin == KEY_LEFT) //alterna a direcao para a esquerda
            prox = left;
        if(kin == KEY_RIGHT) //alterna a direcao para a direita
            prox = right;
        if(kin == KEY_DOWN) //alterna a direcao para baixo
            prox = down;
        if(kin == KEY_UP) //alterna a direcao para cima
            prox = up;
        if(kin == 'q') //para quitar durante o jogo
        {
            endwin();
            return EXIT_SUCCESS;
        }

        g.pacman = movPac(g, prox);
        printlab(g);
        g = comecome(g);
        g = mortalPac(g);
        g = modofantasma(g);
        if((frightened == 0) || (frightened == 1 && clock() - afraid_t > 16000))
        {
            frightened = 0;
            g = alternador(g, start_t);
        }
        if(g.pacman.life == 0) //quando o jagador perde o jogo
        {
            endwin();
            while(1)
            {
                mvprintw(25, 0, "VOCE PERDEU!!! Para sair do jogo pressione E...");
                kin = getch();
                if(kin == 'e')
                {
                    endwin();
                    return EXIT_SUCCESS;
                }
            }
            refresh();
        }
        if(g.pacman.coin == 188) //quando o jagador ganha o jogo
        {
            endwin();
            while(1)
            {
                mvprintw(25, 0, "VOCE GANHOU!! Para sair do jogo pressione E...");
                kin = getch();
                if(kin == 'e')
                {
                    endwin();
                    return EXIT_SUCCESS;
                }
            }
            refresh();
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
    g.pacman.coin = 0; /* 0 coins */
    g.cherry.pos.y = 13;/* cherry start position (line) */
    g.cherry.pos.x = 10;/* cherry start position (column) */

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
void printlab(t_game g)
{
    //IFDEBUG("printlab()");

    int y, f;

    g.lab[17][9] = ' '; //limpa o @ da tela
    g.lab[7][9] = ' '; //limpa o B da tela
    g.lab[9][10] = ' '; //limpa o P da tela
    g.lab[10][10] = ' '; //limpa o I da tela
    g.lab[11][10] = ' '; //limpa o C da tela

    clear(); /* clear the screen */

    attron(COLOR_PAIR(5));//pinta o mapa de azul
    for(y = 0; y < LABL; y++)
        printw("%s\n", g.lab[y]);
    attroff(COLOR_PAIR(5));

    corlab(g);

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
    {
        if(f == blinky)
        {
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "B");//printa o fantasma BLINKY na tela
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 1, NULL);
        }
        if(f == pinky)
        {
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "P");//printa o fantasma PINKY na tela
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 2, NULL);
        }
        if(f == inky)
        {
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "I");//printa o fantasma INKY na tela
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 3, NULL);
        }
        if(f == clyde)
        {
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "C");//printa o fantasma CLYDE na tela
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 4, NULL);
        }
        if(g.ghost[f].mode == afraid)//ativa a cor do modo afraid dos fantasmas
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BLINK, 5, NULL);
    }
    mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");//printa o pacman na tela
    mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);

    mvprintw(g.cherry.pos.y, g.cherry.pos.x, "%");//printa a cereja na tela
    mvchgat(g.cherry.pos.y, g.cherry.pos.x, 1, A_BOLD, 1, NULL);

    mvprintw(20, 22, "Coins: %i", g.pacman.coin);//printa a contagem de moedas
    mvprintw(21, 22, "Life: %i", g.pacman.life);//printa a contagem das vidas dos pacman
    mvprintw(22, 22, "Score: %d", g.pacman.score);//printa a pontuacao do jogador

    refresh();
}
/* FUNCAO QUE ATIVA A MOVIMENTACAO DO PACMAN */
t_pacman movPac(t_game g, t_direction prox)
{
    int px = 0;
    int py = 0;
    curs_set(FALSE);

    /* MOVE PARA A ESQUERDA */
    if(prox == left)
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] != '#')
            g.pacman.dir = left;
    if(g.pacman.dir == left)
    {
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] != '#')
        {
            px--;
            py = 0;
        }
        else
        {
            px = 0;
            py = 0;
        }
    }
    /* MOVE PARA A DIREITA */
    if(prox == right)
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] != '#')
            g.pacman.dir = right;
    if(g.pacman.dir == right)
    {
        if(g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] != '#')
        {
            px++;
            py = 0;
        }
        else
        {
            px = 0;
            py = 0;
        }
    }
    /* MOVE PARA CIMA */
    if(prox == up)
    {
        if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != '#')
            g.pacman.dir = up;
    }
    if(g.pacman.dir == up)
    {
        if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != '#')
        {
            px = 0;
            py--;
        }
        else
        {
            px = 0;
            py = 0;
        }
    }
    /* MOVE PARA BAIXO */
    if(prox == down)
        if(g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '#')
            g.pacman.dir = down;
    if(g.pacman.dir == down)
    {
        if(g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '#' && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '-')
        {
            px = 0;
            py++;
        }
        else
        {
            px = 0;
            py = 0;
        }
    }
    /* TELEPORTE DO LABIRINTO */
    if(g.pacman.dir == left && g.pacman.pos.y == 10 && g.pacman.pos.x == 0)
    {
        g.pacman.pos.y = 10;
        g.pacman.pos.x = 19;
    }
    if(g.pacman.dir == right && g.pacman.pos.y == 10 && g.pacman.pos.x == 19)
    {
        g.pacman.pos.y = 10;
        g.pacman.pos.x = 0;
    }
    g.pacman.pos.y += py;
    g.pacman.pos.x += px;

    return g.pacman;
}
/* FUNCAO QUE ATIVA A COLETA DAS COINS DO LABIRINTO */
t_game comecome(t_game g)
{
    int pacy = g.pacman.pos.y;
    int pacx = g.pacman.pos.x;
    int chy = g.cherry.pos.y;
    int chx = g.cherry.pos.x;
    int b = 0;

    if(g.lab[pacy][pacx] == '.') //coin normal
    {
        g.lab[pacy][pacx] = ' '; //limpa a coin normal
        g.pacman.coin += 1;  //adiciona quantidade de coins no contador
        g.pacman.score += 10;  //adiciona pontuacao no contador
    }
    if(g.lab[pacy][pacx] == 'o') //coin especial
    {
        g.lab[pacy][pacx] = ' ';
        g.pacman.coin += 1;
        g.pacman.score += 50;

        /*ATIVA A COIN ESPECIAL DESPERTANDO O MODO AFRAID NOS FANTASMAS*/

        frightened = 1; // variavel que inicia o modo AFRAID
        afraid_t = clock(); // o modo afraid recebe a funcao marca o tempo
        for(b = blinky; b <= clyde; b++)
            g.ghost[b].mode = afraid;
    }
    if(g.pacman.coin == 94) // inicializa a cereja no jogo
        g.lab[chy][chx] = '%';
    if(g.lab[pacy][pacx] == '%') //aciona a pontuacao da cereja no score
    {
        g.lab[pacy][pacx] = ' ';
        g.pacman.score += 500;
    }
    return g;
}
/* FUNCAO PARA PINTAR AS COINS DO JOGO */
void corlab(t_game g)
{
    int y;
    int m;
    /* CICLOS PARA PINTAR AS COINS NORMAIS */
    for(y = 0; y < LABL; y++)
        for(m = 0; m < LABC; m++)
            if(g.lab[y][m] == '.')
                mvchgat(y, m, 1, A_BOLD, 6, NULL);//ativa a cor das coins normais
    /* CICLOS PARA PINTAR AS COINS ESPECIAIS */
    for(y = 0; y < LABL; y++)
        for(m = 0; m < LABC; m++)
            if(g.lab[y][m] == 'o')
                mvchgat(y, m, 1, A_BOLD, 7, NULL);//ativa a cor das coins especiais

    refresh();
}
/* FUNCAO PARA OS MODOS DOS FANTASMAS */
t_game modofantasma(t_game g)
{
    int i, dy, dx;

    usleep(100000);
    for(i = blinky; i <= clyde; i++)//ciclo que alterna os fantasmas
    {
        while(g.ghost[i].mode == chase)//ciclo que configura o modo CHASE
        {
            if(g.ghost[blinky].mode == chase)
            {
                g.ghost[blinky].starget.y = g.pacman.pos.y;
                g.ghost[blinky].starget.x = g.pacman.pos.x;
            }
            if(g.ghost[pinky].mode == chase)
            {
                if(g.ghost[pinky].pos.y > 7 && g.ghost[pinky].pos.y <= 11 && g.ghost[pinky].pos.x == 10)
                {
                    g.ghost[pinky].pos.y--;
                    continue;
                }
                if(g.pacman.dir == up)
                {
                    g.ghost[pinky].starget.x = g.pacman.pos.x - 2;

                    if(g.pacman.pos.y + 4 > 22)
                        g.ghost[pinky].starget.y = 22;
                    else
                        g.ghost[pinky].starget.y = g.pacman.pos.y + 4;
                }
                if(g.pacman.dir == down)
                {
                    g.ghost[pinky].starget.x = g.pacman.pos.x;

                    if(g.pacman.pos.y - 4 < 0)
                        g.ghost[pinky].starget.y = 0;
                    else
                        g.ghost[pinky].starget.y = g.pacman.pos.y + 4;
                }
                if(g.pacman.dir == left)
                {
                    g.ghost[pinky].starget.y = g.pacman.pos.y;

                    if(g.pacman.pos.x - 4 < 0)
                        g.ghost[pinky].starget.x = 0;
                    else
                        g.ghost[pinky].starget.x = g.pacman.pos.x - 4;
                }
                if(g.pacman.dir == right)
                {
                    g.ghost[pinky].starget.y = g.pacman.pos.y;

                    if(g.pacman.pos.x > 19)
                        g.ghost[pinky].starget.x = 19;
                    else
                        g.ghost[pinky].starget.x = g.pacman.pos.x + 4;
                }
            }
            if(g.ghost[inky].mode == chase)
            {
                if(g.ghost[inky].pos.y > 7 && g.ghost[inky].pos.y <= 11 && g.ghost[inky].pos.x == 10)
                {
                    g.ghost[inky].pos.y--;
                    continue;
                }
                dy = g.pacman.pos.y - g.ghost[blinky].pos.y;
                dx = g.pacman.pos.x - g.ghost[blinky].pos.x;
                if(g.pacman.dir == up)
                {
                    g.ghost[inky].starget.x = g.pacman.pos.x + dx;

                    if(g.pacman.pos.y + 2 + 2 * dy > 22)
                        g.ghost[inky].starget.y = 22;
                    else
                        g.ghost[inky].starget.y = g.pacman.pos.y + 2 + 2 * dy;
                }
                if(g.pacman.dir == down)
                {
                    g.ghost[inky].starget.x = g.pacman.pos.x + dx;

                    if(g.pacman.pos.y - 2 - 2 * dy < 0)
                        g.ghost[inky].starget.y = 0;
                    else
                        g.ghost[inky].starget.y = g.pacman.pos.y - 2 - 2 * dy;
                }
                if(g.pacman.dir == left)
                {
                    g.ghost[inky].starget.y = g.pacman.pos.y + dy;

                    if(g.pacman.pos.x - 2 - 2 * dx < 0)
                        g.ghost[inky].starget.x = 0;
                    else
                        g.ghost[inky].starget.x = g.pacman.pos.x - 2 - 2 * dx;
                }
                if(g.pacman.dir == right)
                {
                    g.ghost[inky].starget.y = g.pacman.pos.y + dy;

                    if(g.pacman.pos.x + 2 + 2 * dx > 20)
                        g.ghost[inky].starget.x = 20;
                    else
                        g.ghost[inky].starget.x = g.pacman.pos.x + 2 + 2 * dx;
                }
            }
            if(g.ghost[clyde].mode == chase)
            {
                if(g.ghost[clyde].pos.y > 7 && g.ghost[clyde].pos.y <= 11 && g.ghost[clyde].pos.x == 10)
                {
                    g.ghost[clyde].pos.y--;
                    continue;
                }
                dy = abs(g.pacman.pos.y - g.ghost[clyde].pos.y);
                dx = abs(g.pacman.pos.x - g.ghost[clyde].pos.x);

                if((dy + dx) >= 8)
                    g.ghost[clyde].starget = g.pacman.pos;
                else
                {
                    g.ghost[clyde].starget.y = 22;
                    g.ghost[clyde].starget.x = 0;
                }
            }
            break;
        }
        while(g.ghost[i].mode == scatter)//ciclo que configura o modo SCATTER
        {
            /* IFs QUE DETERMINAM A QUINA PREFERIDA DE CADA FANTASMA */
            if(g.ghost[blinky].mode == scatter)
            {
                g.ghost[blinky].starget.y = 0;
                g.ghost[blinky].starget.x = 19;
            }
            if(g.ghost[pinky].mode == scatter)
            {
                g.ghost[pinky].starget.y = 0;
                g.ghost[pinky].starget.x = 0;
            }
            if(g.ghost[inky].mode == scatter)
            {
                g.ghost[inky].starget.y = 22;
                g.ghost[inky].starget.x = 19;
            }
            if(g.ghost[clyde].mode == scatter)
            {
                g.ghost[clyde].starget.y = 22;
                g.ghost[clyde].starget.x = 0;
            }
            break;
        }
        while(g.ghost[i].mode == afraid)//ciclo que configura o modo AFRAID
        {
            /* IFs QUE FAZEM COM QUE OS FANTASMAS SE MOVAM ASSUSTADOS ALEATORIAMENTE */
            if(g.ghost[blinky].mode == afraid)
            {
                g.ghost[blinky].starget.y = rand() % 20;
                g.ghost[blinky].starget.x = rand() % 20;
            }
            if(g.ghost[pinky].mode == afraid)
            {
                g.ghost[pinky].starget.y = rand() % 20;
                g.ghost[pinky].starget.x = rand() % 20;
            }
            if(g.ghost[inky].mode == afraid)
            {
                g.ghost[inky].starget.y = rand() % 20;
                g.ghost[inky].starget.x = rand() % 20;
            }
            if(g.ghost[clyde].mode == afraid)
            {
                g.ghost[clyde].starget.y = rand() % 20;
                g.ghost[clyde].starget.x = rand() % 20;
            }
            break;
        }
        while(g.ghost[i].mode == dead)//ciclo que configura o modo DEAD
        {
            if(g.ghost[blinky].mode == dead)
            {
                g.ghost[blinky].pos.y = 10;
                g.ghost[blinky].pos.x = 10;
                g.ghost[blinky].mode = chase;
                continue;
            }
            if(g.ghost[pinky].mode == dead)
            {
                g.ghost[pinky].pos.y = 9;
                g.ghost[pinky].pos.x = 10;
                g.ghost[pinky].mode = chase;
                continue;
            }
            if(g.ghost[inky].mode == dead)
            {
                g.ghost[inky].pos.y = 10;
                g.ghost[inky].pos.x = 10;
                g.ghost[inky].mode = chase;
                continue;
            }
            if(g.ghost[clyde].mode == dead)
            {
                g.ghost[clyde].pos.y = 11;
                g.ghost[clyde].pos.x = 10;
                g.ghost[clyde].mode = chase;
                continue;
            }
            break;
        }
        g = gps(g, i);//chamando funcao para calculo de rota
    }
    refresh();
    return g;
}

t_game mortalPac(t_game g)
{
    for(int i = blinky; i <= clyde; i++)  //laço choque entre pacman e fantasma
    {
        if((g.ghost[i].mode != afraid) && (g.ghost[i].mode != dead)) //IFs para colisão de posição entre pacman e fantasmas.
        {
            if(g.pacman.pos.y == g.ghost[i].pos.y && g.pacman.pos.x == g.ghost[i].pos.x)
            {
                g.pacman.life--;
                g.pacman.pos.x = 9;
                g.pacman.pos.y = 17;
                g.pacman.dir = left;

                g.ghost[blinky].pos.y = 7;
                g.ghost[blinky].pos.x = 9;
                g.ghost[pinky].pos.y = 9;
                g.ghost[pinky].pos.x = 10;
                g.ghost[inky].pos.y = 10;
                g.ghost[inky].pos.x = 10;
                g.ghost[clyde].pos.y = 11;
                g.ghost[clyde].pos.x = 10;


            }
            if(g.pacman.dir == left && g.ghost[i].dir == right && g.pacman.pos.x == g.ghost[i].pos.x - 1 && g.pacman.pos.y == g.ghost[i].pos.y)
            {
                g.pacman.life--;
                g.pacman.pos.x = 9;
                g.pacman.pos.y = 17;
                g.pacman.dir = left;

                g.ghost[blinky].pos.y = 7;
                g.ghost[blinky].pos.x = 9;
                g.ghost[pinky].pos.y = 9;
                g.ghost[pinky].pos.x = 10;
                g.ghost[inky].pos.y = 10;
                g.ghost[inky].pos.x = 10;
                g.ghost[clyde].pos.y = 11;
                g.ghost[clyde].pos.x = 10;
            }
            if(g.pacman.dir == right && g.ghost[i].dir == left && g.pacman.pos.x == g.ghost[i].pos.x + 1 && g.pacman.pos.y == g.ghost[i].pos.y)
            {
                g.pacman.life--;
                g.pacman.pos.x = 9;
                g.pacman.pos.y = 17;
                g.pacman.dir = left;

                g.ghost[blinky].pos.y = 7;
                g.ghost[blinky].pos.x = 9;
                g.ghost[pinky].pos.y = 9;
                g.ghost[pinky].pos.x = 10;
                g.ghost[inky].pos.y = 10;
                g.ghost[inky].pos.x = 10;
                g.ghost[clyde].pos.y = 11;
                g.ghost[clyde].pos.x = 10;
            }
            if(g.pacman.dir == up && g.ghost[i].dir == down && g.pacman.pos.x == g.ghost[i].pos.x && g.pacman.pos.y == g.ghost[i].pos.y - 1)
            {
                g.pacman.life--;
                g.pacman.pos.x = 9;
                g.pacman.pos.y = 17;
                g.pacman.dir = left;

                g.ghost[blinky].pos.y = 7;
                g.ghost[blinky].pos.x = 9;
                g.ghost[pinky].pos.y = 9;
                g.ghost[pinky].pos.x = 10;
                g.ghost[inky].pos.y = 10;
                g.ghost[inky].pos.x = 10;
                g.ghost[clyde].pos.y = 11;
                g.ghost[clyde].pos.x = 10;
            }
            if(g.pacman.dir == down && g.ghost[i].dir == up && g.pacman.pos.x == g.ghost[i].pos.x && g.pacman.pos.y == g.ghost[i].pos.y + 1)
            {
                g.pacman.life--;
                g.pacman.pos.x = 9;
                g.pacman.pos.y = 17;
                g.pacman.dir = left;

                g.ghost[blinky].pos.y = 7;
                g.ghost[blinky].pos.x = 9;
                g.ghost[pinky].pos.y = 9;
                g.ghost[pinky].pos.x = 10;
                g.ghost[inky].pos.y = 10;
                g.ghost[inky].pos.x = 10;
                g.ghost[clyde].pos.y = 11;
                g.ghost[clyde].pos.x = 10;
            }
        }
        else
            if((g.ghost[i].mode == afraid) && (g.ghost[i].mode != dead))//IFs para pacman derrotar os fantamas e ganhar pontos nas condições dadas
            {
                if(g.pacman.pos.y == g.ghost[i].pos.y && g.pacman.pos.x == g.ghost[i].pos.x)
                {
                    g.pacman.score = g.pacman.score + 750;
                    g.ghost[i].mode = dead;
                }
                if(g.pacman.dir == left && g.ghost[i].dir == right && g.pacman.pos.x == g.ghost[i].pos.x - 1 && g.pacman.pos.y == g.ghost[i].pos.y)
                {
                    g.pacman.score = g.pacman.score + 750;
                    g.ghost[i].mode = dead;
                }
                if(g.pacman.dir == right && g.ghost[i].dir == left && g.pacman.pos.x == g.ghost[i].pos.x + 1 && g.pacman.pos.y == g.ghost[i].pos.y)
                {
                    g.pacman.score = g.pacman.score + 750;
                    g.ghost[i].mode = dead;
                }
                if(g.pacman.dir == up && g.ghost[i].dir == down && g.pacman.pos.x == g.ghost[i].pos.x && g.pacman.pos.y == g.ghost[i].pos.y - 1)
                {
                    g.pacman.score = g.pacman.score + 750;
                    g.ghost[i].mode = dead;
                }
                if(g.pacman.dir == down && g.ghost[i].dir == up && g.pacman.pos.x == g.ghost[i].pos.x && g.pacman.pos.y == g.ghost[i].pos.y + 1)
                {
                    g.pacman.score = g.pacman.score + 750;
                    g.ghost[i].mode = dead;
                }
            }
    }
    return g;
}
t_game gps(t_game g, int i)//calculo da rota para os fantasmas
{
    float d1 = 0, d2 = 0, d3 = 0, d4 = 0;//modulo das hipotenusas
    int A = 0, B = 0, C = 0, D = 0;//variaveis para as 4 direções e possibilidades de movimentacao
    char pos = ' ';

    if((g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != '#' && '-') && (g.ghost[i].dir != left))
    {
        A = 1;
        d1 = sqrt(pow(((g.ghost[i].pos.y) - g.ghost[i].starget.y), 2) + pow((g.ghost[i].pos.x + 1 - g.ghost[i].starget.x), 2)); //cálculo da hipotenusa.
    }
    if((g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != '#' && '-') && (g.ghost[i].dir != right))
    {
        B = 1;
        d2 = sqrt(pow((g.ghost[i].pos.y - g.ghost[i].starget.y), 2) + pow((g.ghost[i].pos.x - 1 - g.ghost[i].starget.x), 2));
    }
    if((g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != '#' && (g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != '-') && (g.ghost[i].dir != up)))
    {
        C = 1;
        d3 = sqrt(pow((g.ghost[i].pos.y + 1 - g.ghost[i].starget.y), 2) + pow((g.ghost[i].pos.x  - g.ghost[i].starget.x), 2));
    }
    if((g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != '#' && '-') && (g.ghost[i].dir != down))
    {
        D = 1;
        d4 = sqrt(pow((g.ghost[i].pos.y - 1 - g.ghost[i].starget.y), 2) + pow((g.ghost[i].pos.x  - g.ghost[i].starget.x), 2));
    }

    /* TELEPORTE DOS FANTASMAS */
    if(g.ghost[i].pos.x == 0 && g.ghost[i].pos.y == 10)
        g.ghost[i].pos.x = 18, g.ghost[i].pos.y = 10;
    if(g.ghost[i].pos.x == 19 && g.ghost[i].pos.y == 10)
        g.ghost[i].pos.x = 1, g.ghost[i].pos.y = 10;

    if(A == 1 && B == 1) //caso exista mais de uma possibilidade de caminho para fantasmas
        pos = 'E';
    if(A == 1 && C == 1)
        pos = 'F';
    if(A == 1 && D == 1)
        pos = 'G';
    if(B == 1 && C == 1)
        pos = 'H';
    if(B == 1 && D == 1)
        pos = 'I';
    if(C == 1 && D == 1)
        pos = 'J';
    if(A == 1 && B == 1 && C == 1)
        pos = 'K';
    if(A == 1 && B == 1 && D == 1)
        pos = 'L';
    if(C == 1 && B == 1 && D == 1)
        pos = 'M';
    if(A == 1 && C == 1 && D == 1)
        pos = 'N';

    if(A == 1 && B == 0 && C == 0 && D == 0)
    {
        g.ghost[i].pos.x++;
        g.ghost[i].dir = right;
    }
    if(A == 0 && B == 1 && C == 0 && D == 0)
    {
        g.ghost[i].pos.x--;
        g.ghost[i].dir = left;
    }
    if(A == 0 && B == 0 && C == 1 && D == 0)
    {
        g.ghost[i].pos.y++;
        g.ghost[i].dir = down;
    }
    if(A == 0 && B == 0 && C == 0 && D == 1)
    {
        g.ghost[i].pos.y--;
        g.ghost[i].dir = up;
    }
    switch(pos)
    {
        case('E'):
        {
            if(d1 < d2)
            {
                g.ghost[i].pos.x++;
                g.ghost[i].dir = right;
            }
            else
            {
                g.ghost[i].pos.x--;
                g.ghost[i].dir = left;
            }
            break;
        }
        case('F'):
        {
            if(d1 < d3)
            {
                g.ghost[i].pos.x++;
                g.ghost[i].dir = right;
            }
            else
            {
                g.ghost[i].pos.y++;
                g.ghost[i].dir = down;
            }
            break;
        }
        case('G'):
        {
            if(d1 < d4)
            {
                g.ghost[i].pos.x++;
                g.ghost[i].dir = right;
            }
            else
            {
                g.ghost[i].pos.y--;
                g.ghost[i].dir = up;
            }
            break;
        }
        case('H'):
        {
            if(d2 < d3)
            {
                g.ghost[i].pos.x--;
                g.ghost[i].dir = left;
            }
            else
            {
                g.ghost[i].pos.y++;
                g.ghost[i].dir = down;
            }
            break;
        }
        case('I'):
        {
            if(d2 < d3)
            {
                g.ghost[i].pos.x--;
                g.ghost[i].dir = left;
            }
            else
            {
                g.ghost[i].pos.y--;
                g.ghost[i].dir = up;

            }
            break;
        }
        case('J'):
        {
            if(d3 < d4)
            {
                g.ghost[i].pos.y++;
                g.ghost[i].dir = down;
            }
            else
            {
                g.ghost[i].pos.y--;
                g.ghost[i].dir = up;
            }
            break;
        }
        case('K'):
        {
            if(d1 < d2 && d1 <= d3)
            {
                g.ghost[i].pos.x++;
                g.ghost[i].dir = right;
            }
            if(d2 < d3 && d2 <= d1)
            {
                g.ghost[i].pos.x--;
                g.ghost[i].dir = left;
            }
            else
            {
                g.ghost[i].pos.y++;
                g.ghost[i].dir = down;
            }
            break;
        }
        case('L'):
        {
            if(d1 < d2 && d1 < d4)
            {
                g.ghost[i].pos.x++;
                g.ghost[i].dir = right;
            }
            if(d2 < d4 && d2 < d1)
            {
                g.ghost[i].pos.x--;
                g.ghost[i].dir = left;
            }
            else
            {
                g.ghost[i].pos.y--;
                g.ghost[i].dir = up;
            }
            break;
        }
        case('M'):
        {
            if(d3 < d2 && d3 < d4)
            {
                g.ghost[i].pos.y++;
                g.ghost[i].dir = down;
            }
            if(d2 < d3 && d2 < d4)
            {
                g.ghost[i].pos.x--;
                g.ghost[i].dir = left;
            }
            else
            {
                g.ghost[i].pos.y--;
                g.ghost[i].dir = up;
            }
            break;
        }
        case('N'):
        {
            if(d1 < d3 && d1 < d4)
            {
                g.ghost[i].pos.x++;
                g.ghost[i].dir = right;
            }
            if(d3 < d1 && d3 < d4)
            {
                g.ghost[i].pos.y++;
                g.ghost[i].dir = down;
            }
            else
            {
                g.ghost[i].pos.y--;
                g.ghost[i].dir = up;
            }
            break;
        }
        default:
            break;
    }
    return g;
}
t_game alternador(t_game g, clock_t start_t)//temporizar os modos dos fantasmas
{
    clock_t presente_t, total_t;
    for(int i = blinky; i <= clyde; i++)
    {
        presente_t = clock();
        total_t = (presente_t - start_t);

        if(total_t > 0 && total_t <= 21000)
            g.ghost[i].mode = scatter;
        if(total_t > 21000 && total_t <= 81000)
            g.ghost[i].mode = chase;
        if(total_t > 81000 && total_t <= 102000)
            g.ghost[i].mode = scatter;
        if(total_t > 102000 && total_t <= 162000)
            g.ghost[i].mode = chase;
        if(total_t > 162000 && total_t <= 177000)
            g.ghost[i].mode = scatter;
        if(total_t > 177000 && total_t <= 237000)
            g.ghost[i].mode = chase;
        if(total_t > 237000 && total_t <= 252000)
            g.ghost[i].mode = scatter;
        if(total_t > 252000)
            g.ghost[i].mode = chase;
    }
    return g;
}
void pacWelcome() /* Void para mostrar ao usuario a tela help antes do inicio do jogo */
{
    int lmax, cmax;
    getmaxyx(stdscr, lmax, cmax);//para saber os limites da tela do usuario

    mvprintw((lmax / 2) - 15, (cmax / 2) - 1, "THE PACMAN");

    attron(COLOR_PAIR(4));
    mvprintw((lmax / 2) - 13, (cmax / 2) - 5, "CONTROLES DO PACMAN:");
    mvprintw((lmax / 2) - 11, (cmax / 2) + 1, "KEY UP");
    mvprintw((lmax / 2) - 10, (cmax / 2) + 4, "^");
    mvprintw((lmax / 2) - 8, (cmax / 2) - 9, "KEY LEFT");
    mvprintw((lmax / 2) - 8, (cmax / 2), "<");
    mvprintw((lmax / 2) - 8, (cmax / 2) + 8, ">");
    mvprintw((lmax / 2) - 8, (cmax / 2) + 10, "KEY RIGHT");
    mvprintw((lmax / 2) - 6, (cmax / 2) + 4, "v");
    mvprintw((lmax / 2) - 5, (cmax / 2), "KEY DOWN");
    attroff(COLOR_PAIR(4));

    mvprintw(24, 0, "COMO JOGAR:");

    attron(COLOR_PAIR(3));
    mvprintw(26, 0, "- COLETE TODAS AS COINS.");
    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(1));
    mvprintw(27, 0, "- VOCE PERDE SE MORRER 3 VEZES.");
    attroff(COLOR_PAIR(1));

    mvprintw(28, 0, "- PARA SAIR DURANTE O JOGO PRESSIONE Q.");
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
