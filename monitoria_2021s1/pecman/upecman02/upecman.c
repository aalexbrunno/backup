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
 *   To contact the Authors from Cebolinha, please write to:               *  
 *   Arthur Bezerra Oliveira <abo@poli.br>                                 *
 *   Carlos Felipe Pereira da Silva <cfps@poli.br>                         *
 *   Jose Ricardo da Silva Junior <jrsj1@poli.br>                          *
 *   Lucas Felipe Dias de Miranda <lfdm@poli.br>                           *
 *   Marco Antonio Pontual Amorim Amaral <mapaa@poli.br>                   *
 *   Ricardo Giuseppe de Medeiros Fiorentino <rgmf@poli.br>                *
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
#include <math.h>  /* Mathematics functions */
#include <time.h> /* Time and date functions */

/* --------------------------------------------------------------------  */

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

/* ----------------------------------------------------------------------------  */
/* Funcao principal, que tem a chamada das funcoes secundarias mais importantes */
int main(int argc, char **argv)
{
    IFDEBUG("main()\n");
    int opt; /*return from getopt()*/

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
            case 'c':
                copyr();
                break;
        }

    /*...and we are done*/
    IFDEBUG("Starting the game now...\n");

    iniciar_ncurses(); /* Chama funcao de inicio de jogo */
    telas();

    endwin();
    IFDEBUG("Ending the game now...\n");
    printf("\nVolte sempre! O nosso Pacman te espera!!!\n\n");
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* Esta funcao cria uma cereja em momentos especificos do jogo, com uma *
 * pontuacao bonus                                                      */
t_game cereja(t_game g)
{
    if(g.pacman.score == 1000 || g.pacman.score == 2100)
        g.lab[13][10] = '%';

    return g;
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
/* Help chamado com o getopt */
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
/* Copyright chamado com o getopt */
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
/* Possui o print inicial do pacman, dos fantasmas e do labirinto, assim como inicializa praticamente todas as cores */
t_game upecman_init(void)
{
    /* IFDEBUG("init()");*/
    /* initialization */

    t_game g;
    int f, y;

    for(y = 0; y < LABL; y++)
        strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */

    g.pacman.pos.y = 17; /* pacman start position (line) */
    g.pacman.pos.x = 9; /* pacman start position (column) */
    g.pacman.dir = left; /* pacman start direction *//* Currente direction */
    g.pacman.life = 3; /* 3 lifes */
    g.pacman.score = 0; /* 0 points */

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
    {
        switch(f)
        {
            case blinky: /* Canto de preferência: superior direito */
                /* Posição de início */
                g.ghost[f].pos.y = 7; /* blinky start position (line) */
                g.ghost[f].pos.x = 9; /* blinky start position (column) */
                /* Canto de preferência */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case pinky: /* Canto de preferência: superior esquerdo */
                /* Posição de início */
                g.ghost[f].pos.y = 9; /* pinky start position (line) */
                g.ghost[f].pos.x = 10; /* pinky start position (column) */
                /* Canto de preferência */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
                break;
            case inky: /* Canto de preferência: inferior direito */
                /* Posição de início */
                g.ghost[f].pos.y = 10; /* inky start position (line) */
                g.ghost[f].pos.x = 10; /* inky start position (column) */
                /* Canto de preferência */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case clyde: /* Canto de preferência inferior direito */
                /* Posição de início */
                g.ghost[f].pos.y = 11; /* clyde start position (line) */
                g.ghost[f].pos.x = 10; /* clyde start position (column) */
                /* Canto de preferência */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
        }
        g.ghost[f].dir = left; /* start direction and future direction: left */
        g.ghost[f].mode = chase;
    }

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
/* Funcao que printa todas as telas do jogo e faz a passagem entre elas */
void telas() 
{
    int ymax, xmax; /* Vairaveis que recebem os tamanhos de tela */
    getmaxyx(stdscr, ymax, xmax); /* Pega o tamanho da tela do usuario*/
    int destaque = 0; /* Highlight do menu principal */
    int destaque_out = 0; /* Highlight da saida */
    int play = 0; /* Variavel usada para definir as telas e facilitar a transicao entre elas */
    int ch; /* Variavel que reccebe input do usuario */
    int U, C; /* Contadores do laco de print das duas partes do titulo */
    int i; /* Contador de mudanca de posicao do destaque do menu principal */
    int a; /* Contador do laco de print do copyright */
    keypad(stdscr, true); /* Permite o uso de setas */

    while(1)
    {
        while(play == 0)
        {
            /* Titulo - UPE */
            char UPE[7][50] =
            {
               "####   ####    #########    #########",
               "##  #  ##  #   ##  #### #   ##       #",
               " ##  #  ##  #   ##  #  # #   ##  ######",
               "  ##  #  ##  #   ##  ####     ##       #",
               "   ##  #  ##  #   ##  #        ##  ######",
               "    ##  #####  #   ##  #        ##       #",
               "     ############   #####        ##########",
            };

            /* Titulo - CMAN */
            char CMAN[7][50] =
            {
                " ########  ##     ##    #    ##    #",
                "##         # #   # #   # #   # #   #",
                "##         #  # #  #  #   #  #  #  #",
                "##         #   #   #  #   #  #  #  #",
                "##         #       #  # # #  #   # #",
                "##         #       #  #   #  #   # #",
                " ########  #       #  #   #  #    ##",
            };

            for (U = 0; U < 7; U++)
            {
                attron(COLOR_PAIR(1));
                mvprintw(U + 7, xmax/2 - 45, " %s", UPE[U]);
                attroff(COLOR_PAIR(1));
            }
            for (C = 0; C < 7; C++)
            {
                attron(COLOR_PAIR(2));
                mvprintw(C + 8, xmax/2 + 1, " %s", CMAN[C]);
                attroff(COLOR_PAIR(2));
            }

/* ---------------------------------------------------------------------------------------- */

            char escolhas [4][15] = {"Jogar", "Controles", "Copyright", "Sair do jogo"};

            for(i = 0; i < 4; i++)
            {
                if(i == destaque) attron(COLOR_PAIR(1));
                if(i == 0)mvprintw(ymax / 2 + 1, xmax / 2 - 5, escolhas[i]);
                if(i == 1)mvprintw(ymax / 2 + 2, xmax / 2 - 7, escolhas[i]);
                if(i == 2)mvprintw(ymax / 2 + 3, xmax / 2 - 7, escolhas[i]);
                if(i == 3)mvprintw(ymax / 2 + 4, xmax / 2 - 8, escolhas[i]);
                attroff(COLOR_PAIR(1));
            }

            ch = getch();
            switch(ch)
            {
                case KEY_UP:
                    destaque--;
                    if(destaque == -1)
                        destaque = 0;
                    break;


                case KEY_DOWN:
                    destaque++;
                    if(destaque == 4)
                        destaque = 3;
                    break;

                default:
                    break;
            }

            if(ch == ENTER && destaque == 0)
            {
                play = 1;
                clear();
                break;
            }

            if(ch == ENTER && destaque == 1)
            {
                play = 2;
                clear();
                break;
            }

            if(ch == ENTER && destaque == 2)
            {
                play = 3;
                clear();
                break;
            }

            if(ch == ENTER && destaque == 3)
            {
                play = 4;
                clear();
                break;
            }

            usleep(DELAY);
        }

        while(play == 1) // Entra no mapa do jogo 
        {
            t_game g; /* variavel g do tipo t_game */
            g = upecman_init(); /* g recebe os prints iniciais */
            movimentacao(g); /* Chamada da funcao Movimentacao que recebe a variavel g como argumento */
            printlab(g);/* A funcao printlab tem o seus prints e cores atualizados */
            refresh();
    
        }

        while(play == 2) // Entra no menu de Controles
        {
            mvprintw(2, 5, "Aperte 'enter' para voltar");
            mvprintw(3, 5, "Controles:");
            char controle[19][100] =
            {
                "__________________________________________________________________",
                "|Movimentação:                                                 |",
                "|                                                                | ",
                "|  Use as setas (up, left, down, right) para movimentar o Pacman.|",
                "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                "|Vida:                                                           |",
                "|                                                                |",
                "|  O Pacman '@' tem 3 vidas no início da partida.               |",
                "|  Caso um fantasma te ataque, você perderá 1 vida.            |",
                "|  Caso todas as pastilhas sejam comidas ou você perca          |",
                "|  todas as vidas, o jogo será fechado e uma mensagem aparecerá. |",
                "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                "|Pontuação:                                                    |",
                "|                                                                |",
                "|  A pastilha comum '.' vale 10 pontos                           |",
                "|  A pastilha grande 'o' vale 50 pontos                          |",
                "|  A cereja '%' vale 500 pontos                                  |",
                "|  Os fantasmas 'P, B, I, C' valem 750 pontos, cada              |",
                "|________________________________________________________________|",
            };

            for(a = 0; a < 19; a++)
                mvprintw(a + 8, xmax/2 - 33, "%s", controle[a]);
            refresh();

            ch = getch();

            if(ch == ENTER)
            {
                play = 0;
                clear();
                break;
            }
            usleep(DELAY);
        }

        while(play == 3)  // Entra no menu de Copyright
        {
            mvprintw(2, 4, "Copyright:");
            mvprintw(1, 4, "Aperte 'enter' para voltar");
            char direitos[32][100] =
            {
                "____________________________________________________________________________",
                "|    UPECMAN                                                               |",
                "|    Jogo recreativo. Faça a maior pontuação que conseguir.             | ",
                "|                                                                          |",
                "|    Copyright (C) 2021 by CEBOLINHA, AUTHORS_2                            |",
                "|                                                                          |",
                "|    This program is free software; you can redistribute it and/or modify  |",
                "|    it under the terms of the GNU General Public License as published by  |",
                "|    the Free Software Foundation; either version 2 of the License, or     |",
                "|    (at your option) any later version.                                   |",
                "|                                                                          |",
                "|    This program is distributed in the hope that it will be useful,       |",
                "|    but WITHOUT ANY WARRANTY; without even the implied warranty of        |",
                "|    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         |",
                "|    GNU General Public License for more details.                          |",
                "|                                                                          |",
                "|    You should have received a copy of the GNU General Public License     |",
                "|    along with this program; if not, write to the                         |",
                "|    Free Software Foundation, Inc.,                                       |",
                "|    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             |",
                "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|",
                "|    To contact the authors, write to:                                     |",
                "|                                                                          |",
                "|    Arthur Bezerra Oliveira <abo@poli.br>                                 |",
                "|    Carlos Felipe Pereira Da Silva <cfps@poli.br>                         |",
                "|    Jose Ricardo Da Silva Junior <jrsj1@poli.br>                          |",
                "|    Lucas Felipe Dias De Miranda <lfdm@poli.br>                           |",
                "|    Marco Antonio Pontual Amorim Amaral <mapaa@poli.br>                   |",
                "|    Ricardo Giuseppe De Medeiros Fiorentino <rgmf@poli.br>                |",
                "|__________________________________________________________________________|",
                "                                                                            ",
            };

            for(int b = 0; b < 32; b++)
                mvprintw(b + 3, xmax/2 - 35, "%s", direitos[b]);
            refresh();

            ch = getch();
            if(ch == ENTER)
            {
                play = 0;
                clear();
                break;
            }
            usleep(DELAY);
        }

        while(play == 4) // Tela de sair 
        {
            char opcoes_out[2][10] = {"Sim", "Nao"};
            mvprintw(2, 2, "Certeza que deseja sair?");
            for(int s = 0; s < 2; s++)
            {
                if(destaque_out == s) attron(COLOR_PAIR(1));
                if(s == 0)mvprintw(3, 2, opcoes_out[s]); /* Sim, deseja sair */
                if(s == 1)mvprintw(4, 2, opcoes_out[s]); /* Nao, deseja ficar */
                attroff(COLOR_PAIR(1));
            }
            refresh();

            ch = getch();

            switch(ch)
            {
                case KEY_UP:
                    destaque_out--;
                    if(destaque_out == -1)
                        destaque_out = 0;
                    break;

                case KEY_DOWN:
                    destaque_out++;
                    if(destaque_out == 2)
                        destaque_out = 1;
                    break;

                default:
                    break;
            }

            if(ch == ENTER && destaque_out == 0)
            {
                clear();
                endwin();
                return;
            }
            if(ch == ENTER && destaque_out == 1)
            {
                play = 0;
                clear();
                break;
            }

            usleep(DELAY);
        }

    }
    return;
}

/* ---------------------------------------------------------------------- */
/* Funcao que faz a inicializacao da tela do ncurses e de algumas cores */
void iniciar_ncurses()
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
    timeout(DELAY);
    curs_set(FALSE);

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    
    return;
}

/* ----------------------------------------------------------------------- */
/* Funcao que contem toda a movimentacao do pacman, assim como as          *
 * atualizacoes de posicao e modos dos fantasmas, tudo sendo atuliazado no * 
 * print do mapa.                                                          */
t_game movimentacao(t_game g)
{
    int pac; /* Contador para printar o desenho do pacman */
    int currentdir; /* Recebe a direcao atual */
    int key; /* Variavel que recebe o input do usuario para mover o pacman */
    keypad(stdscr, TRUE);

    while(1)
    {
        if(g.pacman.life < 1)
        {
            endwin();
            printf("\nBlinky grita:Voce foi facil!\nInky diz:Treine mais.\nClyde debocha:Nem precisei correr muito.\nPink ironiza:Ainda procuro um oponente digno.\n\n");
            exit(1);
        }
        if(key == KEY_R) /*Reseta o jogo ao apertar*/
        {
            clear();
            refresh();
            break;
        }
        if(fim_jogo(g) == 1) /* Finaliza o jogo com vitória */
        {
            endwin();
            printf("\nBlinky, Inky, Clyde, Pink gritam: Equipe Ghost decolando de novo!\n");
            printf("Narrado: Seu poder eh mais de %i!\n\n", g.pacman.score);
            exit(1);
        }
        if(key == KEY_S)/* Sair do jogo ao apertar 's' */
        {
            endwin();
            printf("\nVai tao cedo? Volte logo\n\n");
            exit(1);
        }
        switch(key)
        {
            case KEY_UP:
                if(g.lab[g.pacman.pos.y-1][g.pacman.pos.x] == '#')
                    break;
                else currentdir = up;
                break;

            case KEY_DOWN:
                if(g.lab[g.pacman.pos.y+1][g.pacman.pos.x] == '#')
                    break; 
                else currentdir = down;
                break;

            case KEY_LEFT:
                if(g.lab[g.pacman.pos.y][g.pacman.pos.x-1] == '#')
                    break;
                else currentdir = left;
                break;

            case KEY_RIGHT:
                if(g.lab[g.pacman.pos.y][g.pacman.pos.x+1] == '#')
                    break;
                else currentdir = right;
                break;

            default:
                break;
        }

        switch(currentdir)
        {
            case up:
                if((currentdir == up) && (g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != '#'))
                {
                    if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] == 46)
                        g.pacman.score += 10;
                    if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] == 111) /* pastilha grande, permite comer fantasmas */
                    {
                        g.pacman.score += 50;
                        for(int i = blinky; i <= clyde; i++)
                        {
                            g.ghost[i].mode = afraid;
                            g.ghost[i].inittime = time(NULL);
                        }
                    }
                    if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] == '%')
                        g.pacman.score += 500;
                    g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
                    g.pacman.pos.y = g.pacman.pos.y - 1;
                }
                break;

            case left:
                if(currentdir == left && g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] != '#')
                {
                    if(g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] == 46)
                        g.pacman.score += 10;
                    if(g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] == 111)
                    {
                        g.pacman.score += 50;
                        for(int i = blinky; i <= clyde; i++)
                        {
                            g.ghost[i].mode = afraid;
                            g.ghost[i].inittime = time(NULL);
                        }
                    }
                    if(g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] == '%')
                        g.pacman.score += 500;
                    if(g.pacman.pos.x == 6 && g.pacman.pos.y == 9)
                    {
                        g.pacman.primeira_pallet--;
                        g.lab[g.pacman.posant.x][g.pacman.posant.y] = ' ';
                    }
                    g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
                    g.pacman.pos.x = g.pacman.pos.x - 1;
                    if((g.pacman.pos.y == 10) && (g.pacman.pos.x == 0))
                        g.pacman.pos.x = 19;
                }
                break;

            case right:
                if(currentdir == right && g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] != '#')
                {
                    if(g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] == 46)
                        g.pacman.score += 10;
                    if(g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] == 111)
                    {
                        g.pacman.score += 50;
                        for(int i = blinky; i <= clyde; i++)
                        {
                            g.ghost[i].mode = afraid;
                            g.ghost[i].inittime = time(NULL);
                        }
                    }
                    if(g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] == '%')
                        g.pacman.score += 500;
                    if(g.pacman.pos.x == 8 && g.pacman.pos.y == 9)
                    {
                        g.pacman.primeira_pallet--;
                        g.lab[g.pacman.posant.x][g.pacman.posant.y] = ' ';
                    }
                    g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
                    g.pacman.pos.x = g.pacman.pos.x + 1;
                    if((g.pacman.pos.y == 10) && (g.pacman.pos.x == 20))
                        g.pacman.pos.x = 0;
                }
                break;

            case down:
                if(currentdir == down && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '#' && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '-')
                {
                    if(g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] == 46)
                        g.pacman.score += 10;
                    if(g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] == 111)
                    {
                        g.pacman.score += 50;
                        for(int i = blinky; i <= clyde; i++)
                        {
                            g.ghost[i].mode = afraid;
                            g.ghost[i].inittime = time(NULL);
                        }
                    }
                    if(g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] == '%')
                        g.pacman.score += 500;
                    g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
                    g.pacman.pos.y = g.pacman.pos.y + 1;
                }
                break;

            default:
                break;
        }
        /* Chamadas de funcao e atualizacao dos fantasmas, junto com print da posicao atualizada do pacman e atualizacao do printlab */
        g = cereja(g);
        g.ghost[0].target.y = g.pacman.pos.y;
        g.ghost[0].target.x = g.pacman.pos.x;
        g = inkychase(g);
        g = fantbridge(g, 0);
        g = fantbridge(g, 2);
        g = pinkychase(g);
        g = clydechase(g);
        g = fantbridge(g, 1);
        g = fantbridge(g, 3);
        g = colisao(g);
        g = modos(g, 0);
        g = modos(g, 1);
        g = modos(g, 2);
        g = modos(g, 3);
        g.lab[g.pacman.pos.y][g.pacman.pos.x] = '@';
        printlab(g);
        /* Prints que ficam ao lado do mapa */
        mvprintw(19, 30, "Score: %i", g.pacman.score);
        mvprintw(20, 30, "Life: %i", g.pacman.life);
        mvprintw(21, 30, "Aperte 'r' para resetar");
        mvprintw(22, 30, "Aperte 's' para sair do jogo");
        for(pac = 0; pac < 12; pac++)/* Print do desenho do pacman ao lado do mapa */
        {
            attron(COLOR_PAIR(6));
            mvprintw(pac + 5, 30, "%s", artpac[pac]);   
            attroff(COLOR_PAIR(6));
        }
        refresh();
        usleep(300);
        timeout(280);
        key = getch();
    }
    return g;
}

/* ---------------------------------------------------------------------- */
/* Esta funcao determina o comportamento do Inky no modo de perseguicao */
t_game inkychase(t_game g)
{
    t_pos posref;

    posref = pacBox(g);
    g = alvoinky(posref, g);

    return g;
}

/* ---------------------------------------------------------------------- */
/* Esta funcao cria um quadrado 2x2 em torno do pacman, que vai servir de *
 * referencia para os fantasmas.                                          */
t_pos pacBox(t_game g)
{
    t_pos pacBox;

    pacBox.y = g.pacman.pos.y;
    pacBox.x = g.pacman.pos.x;

    switch(g.pacman.dir)
    {
        case up:
            pacBox.y -= 2;
            break;

        case down:
            pacBox.y += 2;
            break;

        case left:
            pacBox.x -= 2;
            break;

        case right:
            pacBox.x += 2;
            break;

        default:
            break;

    }

    return pacBox;
}

/* ---------------------------------------------------------------------- */
/* Essa funcao faz o Inky perseguir o pacman de uma certa distancia *
 * calculada com base na função pacBox e na posicao atual do blinky */
t_game alvoinky(t_pos pacBox, t_game g)
{
    g.ghost[inky].target.y = 2 * pacBox.y - g.ghost[blinky].pos.y;
    g.ghost[inky].target.x = 2 * pacBox.x - g.ghost[blinky].pos.x;

    return g;
}

/* ---------------------------------------------------------------------- */
/* Essa funcao desenvolve a movimentacao de caca do Pinky em relacao ao   *
 * Pacman, mantendo o fantasma sempre 4 tales a frente do pacman, barrando*
 * a sua movimentacao para o Blinky atacar por tras.                      */

t_game pinkychase(t_game g)
{
    /* Cada case serve para deixar o pinky quatro casas em torno do pacman a depender do direcinamento do pacman */
    switch(g.pacman.dir)
    {
        case up:
            g.ghost[pinky].target.y = g.pacman.pos.y - 4;
            g.ghost[pinky].target.x = g.pacman.pos.x;
            break;

        case left:
            g.ghost[pinky].target.y = g.pacman.pos.y;
            g.ghost[pinky].target.x = g.pacman.pos.x - 4;
            break;

        case down:
            g.ghost[pinky].target.y = g.pacman.pos.y + 4;
            g.ghost[pinky].target.x = g.pacman.pos.x;
            break;

        case right:
            g.ghost[pinky].target.y = g.pacman.pos.y;
            g.ghost[pinky].target.x = g.pacman.pos.x + 4;

        default:
            break;
    }

    return g;
}

/* ---------------------------------------------------------------------- */
/* Essa funcao permite com que o fantasma "Clyde" persiga o Pacman */
t_game clydechase(t_game g)
{
    /* Clyde comeca a se perceguir o pacman se estiver num raio de 8 blocos, mas volta para o seu corner se a distancia for maior que isso */
    if((g.ghost[clyde].pos.x >= g.pacman.pos.x + 8) && (g.ghost[clyde].pos.y == g.pacman.pos.y))
    {
        g.ghost[clyde].target.x = g.pacman.pos.x;
        g.ghost[clyde].target.y = g.pacman.pos.y;
    }
    if((g.ghost[clyde].pos.x == g.pacman.pos.x) && (g.ghost[clyde].pos.y >= g.pacman.pos.y + 8))
    {
        g.ghost[clyde].target.x = g.pacman.pos.x;
        g.ghost[clyde].target.y = g.pacman.pos.y;
    }
    if((g.ghost[clyde].pos.x >= g.pacman.pos.x - 8) && (g.ghost[clyde].pos.y == g.pacman.pos.y))
    {
        g.ghost[clyde].target.x = g.pacman.pos.x;
        g.ghost[clyde].target.y = g.pacman.pos.y;
    }
    if((g.ghost[clyde].pos.x == g.pacman.pos.x) && (g.ghost[clyde].pos.y >= g.pacman.pos.y - 8))
    {
        g.ghost[clyde].target.x = g.pacman.pos.x;
        g.ghost[clyde].target.y = g.pacman.pos.y;
    }
    else
    {
        g.ghost[clyde].target.x = 22;
        g.ghost[clyde].target.y = 0;
    }
    return g;

}

/* ---------------------------------------------------------------------- */
/* Funcao que de acordo com o fantasma que receber, devolve o movimento   * 
 * de cada um, de acordo com suas caracteristicas proprias.               */
t_game caracfantasma(t_game g, int fantasma)
{
    t_pos obj, lado[4];
    t_direction c1, c2, direc;
    float distancia[4], dist2;

    obj.y = g.ghost[fantasma].target.y;
    obj.x = g.ghost[fantasma].target.x;
    direc = up;

    /*UP*/
    lado[up].y = g.ghost[fantasma].pos.y - 1;
    lado[up].x = g.ghost[fantasma].pos.x;
    /*DOWN*/
    lado[down].y = g.ghost[fantasma].pos.y + 1;
    lado[down].x = g.ghost[fantasma].pos.x;
    /*LEFT*/
    lado[left].y = g.ghost[fantasma].pos.y;
    lado[left].x = g.ghost[fantasma].pos.x - 1;
    /*RIGHT*/
    lado[right].y = g.ghost[fantasma].pos.y;
    lado[right].x = g.ghost[fantasma].pos.x + 1;

    c1 = 0;
    while(c1 <= 3)
    {              /* Verifica se a posição ao lado do pacman é uma CERCA ou sua posição anterior */
        if((g.lab[lado[c1].y][lado[c1].x] == CERCA) || (lado[c1].x == g.ghost[fantasma].oldpos.x && lado[c1].y == g.ghost[c1].oldpos.y))
            distancia[c1] = 5001.0;
        
        else      /* Verifica se o pacman está dentro da caixa */
            if(lado[c1].x > 7 && lado[c1].x < 12 && lado[c1].y > 7 && lado[c1].y < 12)
                distancia[c1] = (lado[c1].y - 4) * 1000;
            else
                distancia[c1] = sqrt(((lado[c1].x - obj.x) * (lado[c1].x - obj.x)) + ((lado[c1].y - obj.y) * (lado[c1].y - obj.y)));
        c1 += 1;
    }
    dist2 = distancia[up];

    c2 = 0;
    while(c2 <= 3)
    {
        if(distancia[c2] < dist2)
        {
            dist2 = distancia[c2];
            direc = c2;
        }
        c2++;
    }
    g.ghost[fantasma].dir = direc;

    return g;
}

/* ---------------------------------------------------------------------- */
/*Funcao que apaga vestigios dos fantasmas*/
t_game direcionamento(t_game g, int nomeDoFantasma)
{
    g.ghost[nomeDoFantasma].oldpos = g.ghost[nomeDoFantasma].pos;

    usleep(16000);

    if(g.lab[g.ghost[nomeDoFantasma].oldpos.y][g.ghost[nomeDoFantasma].oldpos.x] == 'B' || g.lab[g.ghost[nomeDoFantasma].oldpos.y]
            [g.ghost[nomeDoFantasma].oldpos.x] == 'C' || g.lab[g.ghost[nomeDoFantasma].oldpos.y][g.ghost[nomeDoFantasma].oldpos.x] == 'P' ||
            g.lab[g.ghost[nomeDoFantasma].oldpos.y][g.ghost[nomeDoFantasma].oldpos.x] == 'I')
        g.ghost[nomeDoFantasma].item_anterior = ' ';

    if(g.pacman.primeira_pallet == 2)
    {
        g.ghost[blinky].item_anterior = '.';
        g.pacman.primeira_pallet--;
    }

    else
        if(g.pacman.primeira_pallet == 1)
            g.lab[7][9] = '.';

    switch(g.ghost[nomeDoFantasma].dir) /*switch que altera o fantasma, dependendo da sua direcao atual*/
    {

        case up:
            g.lab[g.ghost[nomeDoFantasma].oldpos.y][g.ghost[nomeDoFantasma].oldpos.x] = g.ghost[nomeDoFantasma].item_anterior;
            g.ghost[nomeDoFantasma].item_anterior = g.lab[g.ghost[nomeDoFantasma].pos.y - 1][g.ghost[nomeDoFantasma].pos.x];
            g.ghost[nomeDoFantasma].pos.y = g.ghost[nomeDoFantasma].pos.y - 1;
            break;

        case left:
            if(g.ghost[nomeDoFantasma].pos.x == 0)
            {
                g.ghost[nomeDoFantasma].pos.x = 19;
                g.lab[10][0] = ' ';
            }
            g.lab[g.ghost[nomeDoFantasma].oldpos.y][g.ghost[nomeDoFantasma].oldpos.x] = g.ghost[nomeDoFantasma].item_anterior;
            g.ghost[nomeDoFantasma].item_anterior = g.lab[g.ghost[nomeDoFantasma].pos.y][g.ghost[nomeDoFantasma].pos.x - 1];
            g.ghost[nomeDoFantasma].pos.x = g.ghost[nomeDoFantasma].pos.x - 1;
            break;

        case down:
            g.lab[g.ghost[nomeDoFantasma].oldpos.y][g.ghost[nomeDoFantasma].oldpos.x] = g.ghost[nomeDoFantasma].item_anterior;
            g.ghost[nomeDoFantasma].item_anterior = g.lab[g.ghost[nomeDoFantasma].pos.y + 1][g.ghost[nomeDoFantasma].pos.x];
            g.ghost[nomeDoFantasma].pos.y = g.ghost[nomeDoFantasma].pos.y + 1;
            break;

        case right:
            if(g.ghost[nomeDoFantasma].pos.x == 19)
            {
                g.ghost[nomeDoFantasma].pos.x = 0;
                g.lab[10][19] = ' ';
            }
            g.lab[g.ghost[nomeDoFantasma].oldpos.y][g.ghost[nomeDoFantasma].oldpos.x] = g.ghost[nomeDoFantasma].item_anterior;
            g.ghost[nomeDoFantasma].item_anterior = g.lab[g.ghost[nomeDoFantasma].pos.y][g.ghost[nomeDoFantasma].pos.x + 1];
            g.ghost[nomeDoFantasma].pos.x = g.ghost[nomeDoFantasma].pos.x + 1;
        default:
            break;
    }
    g.lab[9][10] = ' ';
    g.lab[10][10] = ' ';
    g.lab[11][10] = ' ';


    return g;
}

/* ---------------------------------------------------------------------- */
/*Funcao que faz com que caso haja colisao entre fantasmas e pacman, ele morra ou perca vidas*/
t_game colisao(t_game g)
{
    int w;

    /* Dentro do for e dos if's existem as posibilidade de colisao e o que acontece em cada caso */
    for(w = blinky; w <= clyde; w++)
    {
        if((g.ghost[w].mode != afraid) && (g.ghost[w].mode != dead))
        {
            if(((g.ghost[w].pos.x == g.pacman.pos.x) && (g.ghost[w].pos.y == g.pacman.pos.y)) || ((g.pacman.pos.x == g.ghost[w].oldpos.x) &&
                    (g.pacman.pos.y == g.ghost[w].oldpos.y)) || ((g.ghost[w].pos.x == g.pacman.posant.x) && (g.ghost[w].pos.y == g.pacman.posant.y)))
            {
                usleep(16000);
                g.pacman.life--;
                g.pacman.pos.x = 9;
                g.pacman.pos.y = 17;
                g.pacman.dir = left;

                g.lab[g.ghost[w].pos.y][g.ghost[w].pos.x] = ' ';
                g.ghost[w].item_anterior = ' ';

                //Posicao inicial Pinky
                g.ghost[pinky].pos.y = 9;
                g.ghost[pinky].pos.x = 10;
                //Posicao inicial Inky
                g.ghost[inky].pos.y = 10;
                g.ghost[inky].pos.x = 10;
                //Posicao inicial Blinky
                g.ghost[blinky].pos.y = 7;
                g.ghost[blinky].pos.x = 9;
                //Posicao inicial Clyde
                g.ghost[clyde].pos.y = 11;
                g.ghost[clyde].pos.x = 10;
            }
        }
        if(g.ghost[w].mode == afraid)
        {
            if(((g.ghost[w].pos.x == g.pacman.pos.x) && (g.ghost[w].pos.y == g.pacman.pos.y)) || ((g.pacman.pos.x == g.ghost[w].oldpos.x) &&
                    (g.pacman.pos.y == g.ghost[w].oldpos.y)) || ((g.ghost[w].pos.x == g.pacman.posant.x) && (g.ghost[w].pos.y == g.pacman.posant.y)))
            {
                switch(w)
                {
                    case pinky:
                    {
                        g.ghost[pinky].pos.x = 10;
                        g.ghost[pinky].pos.y = 9;
                        break;
                    }
                    case inky:
                    {
                        g.ghost[inky].pos.x = 10;
                        g.ghost[inky].pos.y = 10;
                        break;
                    }
                    case blinky:
                    {
                        g.ghost[blinky].pos.x = 9;
                        g.ghost[blinky].pos.y = 7;
                        break;
                    }
                    case clyde:
                    {
                        g.ghost[clyde].pos.x = 10;
                        g.ghost[clyde].pos.y = 11;
                        break;
                    }
                }
                g.pacman.score = g.pacman.score + 200;
                g.ghost[w].mode = chase;
                g.ghost[w].item_anterior = ' ';
            }
        }
    }

    return g;
}

/* ---------------------------------------------------------------------- */
/* Ligacao entre as funcoes 'caracfantasma' e 'direcionamento' */
t_game fantbridge(t_game g, int fantasma)
{
    g = caracfantasma(g, fantasma);
    g = direcionamento(g, fantasma);

    return g;
}

/* ---------------------------------------------------------------------- */
/*Funcao que calcula o tempo de cada modo dos fantasmas usando funcoes da biblioteca time.h*/
double calculatempo(t_game g, int fantasma)
{
    g.ghost[fantasma].endtime = time(NULL);
    g.ghost[fantasma].time = difftime(g.ghost[fantasma].endtime, g.ghost[fantasma].inittime);

    return g.ghost[fantasma].time;
}


/* ---------------------------------------------------------------------- */
/* Funcao que altera o modo dos fantasmas de acordo com a situacao atual do jogo */
t_game modos(t_game g, int fantasma)
{
    int mode = g.ghost[fantasma].mode;

    if((g.ghost[fantasma].pos.x > 7 && g.ghost[fantasma].pos.x < 12) && (g.ghost[fantasma].pos.y >= 8 && g.ghost[fantasma].pos.y < 12))
    {
        g.ghost[fantasma].target.x = 9;
        g.ghost[fantasma].target.y = 7;
    }
    else
    {
        switch(mode)
        {
            /* Se o tempo for menor que 20seg os fantasmas se mantem no modo chase, se for maior, eles entram no modo scatter e se espalham */
            case chase:
                if(calculatempo(g, fantasma) <= 20)
                    g.ghost[fantasma].mode = chase;
                else
                {
                    g.ghost[fantasma].mode = scatter;
                    g.ghost[fantasma].inittime = time(NULL);
                }
                break;
            /* Ao entrar no modo scatter, os fantasmas se mantem ate que o contador de tempo atinge 7seg, ai mudam para o modo chase */ 
            case scatter:
                if(calculatempo(g, fantasma) < 7)
                    g.ghost[fantasma].mode = scatter;
                else
                {
                    g.ghost[fantasma].mode = chase;
                    g.ghost[fantasma].inittime = time(NULL);
                }
                break;
            /* Quando o pacman come um pastilhao, o modo afraid eh ativado e os fantasmas ficam assim ate que o contador de tempo atinge 7seg */
            case afraid:
                if(calculatempo(g, fantasma) < 7)
                {
                    if((g.ghost[fantasma].pos.x == g.pacman.pos.x) && (g.ghost[fantasma].pos.y == g.pacman.pos.y))
                    {
                        g.ghost[fantasma].mode = dead;
                        g.ghost[fantasma].inittime = time(NULL);
                    }
                    else
                        g.ghost[fantasma].mode = afraid;
                }
                else
                {
                    g.ghost[fantasma].mode = chase;
                    g.ghost[fantasma].inittime = time(NULL);
                }
                break;
            /* O fantasma apos ser comido pelo pacman fica morto por 7seg */
            case dead:
                if(calculatempo(g, fantasma) < 7)
                {
                    g.ghost[fantasma].target.y = 10;
                    g.ghost[fantasma].target.y = 10;
                }
                else
                {
                    g.ghost[fantasma].mode = chase;
                    g.ghost[fantasma].inittime = time(NULL);
                }
                break;

            default:
                break;
        }
    }

    return g;
}

/* ---------------------------------------------------------------------- */
/* Esta funcao finaliza o jogo caso as condições sejam satisfeitas */
int fim_jogo(t_game g)
{
    int i, j;
    /* O for faz a leitura constante do mapa para encontrar pastilhas normais e encerra o jogo caso não haja nenhuma */
    for(i = 0; i < LABL; i++)
    {
        for(j = 0; j < LABC; j++)
        {
            if(g.lab[i][j] == '.')
                return 0;
            else
                continue;
        }
    }
    return 1;
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
/* Possui o print dos fantamas e do pacman */
void printlab(t_game g)
{
    /*IFDEBUG("printlab()");*/
    int y, a, f;

    clear();  /* clear the screen */

    /* Vai colorir as paredes do mapa de azul e a cereja de vermelho */
    for(y = 0; y < LABL; y++)
    {
        for(a = 0; a < LABC; a++)
        {
            mvprintw(y, a, "%c", g.lab[y][a]);
            /* Colore as paredes */
            if(g.lab[y][a] == '#')
                mvchgat(y, a, -1, A_BOLD, 5, NULL);
            /* Colore a cereja */
            if(g.lab[y][a] == '%')
                mvchgat(y, a, -1, A_BOLD, 1, NULL);
            /* Colore a pastilha normal */
            if(g.lab[y][a] == '.')
                mvchgat(y, a, -1, A_BOLD, 6, NULL);
            /*Colore o pastilhao */
            if(g.lab[y][a] == 'o')
                mvchgat(y, a, -1, A_BOLD, 6, NULL);
        }
    }

    /* Print dos fantamas com as cores correspondente que foram declaradas na upecman_init */
    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
        mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f + 1, NULL);

    /* Print dos fantasmas mostrando as letras e fazendo a troca de cor quando o pacman come a pastilha grande */
    for(f = blinky; f <= clyde; f++)
    {
        if(f == blinky)
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "B");

        if(f == pinky)
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "P");

        if(f == inky)
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "I");

        if(f == clyde)
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "C");

        if((g.ghost[f].mode != afraid) && (g.ghost[f].mode != dead))
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f + 1, NULL);
        else
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 5, NULL);
    }

    /* Print do pacman com a sua cor amarela declarada na upecaman_init */
    mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);

    refresh();
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

