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

/* #include <math.h> */ /* Mathematics functions */
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
    const char *sready = "INSIRA UMA MOEDA PARA JOGAR COM 'i'"; /* string que pergunta ao usuário se deve iniciar o jogo */
    int kin; /* keyboard input - valor de entrada do teclado */
    int ch;
    char barreira[2] = "#-";
    char pacdot[2] = ".o";
    char vazio[1] = " ";
    int contpacdot = 0;
    int powerup = 0;
    
    g.lab[22][23] = " ";
    
    int ymax, xmax; //mostra qual o x e y máximos da tela 
    getmaxyx(stdscr, ymax, xmax); //stdscr = janela grande inicial
    
    
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
    int tempo = 0; // util para o funcionamento dos fantasmas da prisao, a cada 5 unidades se passa 1 segundo

    g = upecman_init(); //g = código do labirinto

    curs_set(FALSE);   // tira o cursor branco de aparcer na tela

    //int ymax, xmax; //mostra qual o x e y máximos da tela
    getmaxyx(stdscr, ymax, xmax); //stdscr = janela grande inicial

    mvprintw(17, (xmax/2)-18, "%s", sready); //printa na tela a string que pergunta ao usuário se o jogo deve ser iniciado
    mvprintw(19, (xmax/2)-12, "PRESSIONE 's' PARA SAIR");
    mvprintw(27, (xmax/2)-3, "AJUDA ");
    mvprintw(31, (xmax/2)-44, "Ajude o Pacman (@) a comer todas as pastilhas do labirinto. Você tem 3 vidas para isso!");
    mvprintw(33, (xmax/2)-67, "Os fantasmas Inky, Pinky, Blinky e Clyde vão tentar atingir o Pacman. Cuidado: cada um deles tem sua estratégia única. Então, atenção!");
    mvprintw(35, (xmax/2)-31, "Se algum dos fantasmas atingir o pacman, você perderá uma vida");
    mvprintw(37, (xmax/2)-50, "O labirinto possui 184 pastilhas (.) e 4 pílulas (o). As pastilhas valem 10 pontos, e cada pílula 50 pontos");
    mvprintw(39, (xmax/2)-49, "As pastilhas darão ao Pacman o poder de comer os fantasmas. Cada fantasma devorado vale 750 pontos");
    mvprintw(41, (xmax/2)-17, "O Pacman conta com você. Bom jogo!");

    refresh(); //atualiza a tela inicial

    mvprintw(6, (xmax/2)-33, "UU  UU  PPPPP   EEEEEE");
    mvprintw(7, (xmax/2)-33, "UU  UU  PP   P  EE    ");
    mvprintw(8, (xmax/2)-33, "UU  UU  PP   P  EE      CCCCCCC    M     M    AAAAAAA  NN    NN    ");
    mvprintw(9, (xmax/2)-33, "UU  UU  PPPPP   EE EE   CC   CC  MM M  M  MM  AA   AA  NN N  NN    ");
    mvprintw(10, (xmax/2)-33, "UU  UU  PP      EE      CC       MM   M   MM  AAAAAAA  NN  N NN    ");
    mvprintw(11, (xmax/2)-33, "UU  UU  PP      EE      CCCCCCC  MM       MM  AA   AA  NN    NN  0 ");
    mvprintw(12, (xmax/2)-33, "UUUUUU  PP      EEEEEE");
    
    mvprintw(17, (xmax/2)-18, "%s", sready); //printa na tela a string que pergunta ao usuário se o jogo deve ser iniciado

   while(1)
    {

        kin = getch(); //a variável kin recebe o valor dado pelo usuário

        if(kin == 's' || kin == KEY_LEFT) //se o uauário apertar s, o jogo fecha
            break;
        usleep(16667); // wait 16666 microseconds to avoid frying the processor (1/60 s)

        if(kin == 'i' || kin == KEY_RIGHT) //se o usuário apertar i, o jogo comeca
         {
            clear(); //limpa a tela
            cbreak();
            noecho();
            curs_set(FALSE);
            keypad(stdscr, TRUE);
            timeout(100); // tempo que o programa vai esperar o input


            while(1)
            {
                clear();

                printlab (g);
                g = fantdirec(g); 

                if(powerup > 0)
                    mvprintw(6, 36, "POWERUP!!! %d", powerup); // imprime o powerup
                mvprintw(8, 36, "SCORE %d", g.pacman.score * 10); // imprime o score
                mvprintw(10, 36, "VIDAS: ");
                mvprintw(11, 36, "                ^  ");
                mvprintw(12, 36, "CONTROLES:   <     > ");
                mvprintw(13, 36, "                v  ");
                mvprintw(15, 36, "SAIR: crtl C ");

                g.lab[g.pacman.pos.y][g.pacman.pos.x] = vazio[0]; // retira a bolinha do mapa

                refresh();

                ch = getch(); // input do movimento
                if (contpacdot == 7)
                {
                    g.ghost[1].pos.y = 7;
                    g.ghost[1].pos.x = 9;
                }
                if (contpacdot == 17)
                {
                    g.ghost[2].pos.y = 7;
                    g.ghost[2].pos.x = 9;
                }
                if (contpacdot == 32)
                {
                    g.ghost[3].pos.y = 7;
                    g.ghost[3].pos.x = 9;
                }
                
                if (tempo % 8 != 0)
                {
                    if (g.ghost[0].dir == right && g.lab[g.ghost[0].pos.y][g.ghost[0].pos.x + 1] != barreira[0])
                        g.ghost[0].pos.x += 1;
                    if (g.ghost[0].dir == left && g.lab[g.ghost[0].pos.y][g.ghost[0].pos.x - 1] != barreira[0])
                        g.ghost[0].pos.x -= 1;
                    if (g.ghost[0].dir == up && g.lab[g.ghost[0].pos.y - 1][g.ghost[0].pos.x] != barreira[0])
                        g.ghost[0].pos.y -= 1;
                    if (g.ghost[0].dir == down && g.lab[g.ghost[0].pos.y + 1][g.ghost[0].pos.x] != barreira[0] && g.lab[g.ghost[0].pos.y + 1][g.ghost[0].pos.x] != barreira[1])
                        g.ghost[0].pos.y += 1;
                    
                    if (contpacdot > 7)
                    {
                        if (g.ghost[1].dir == right && g.lab[g.ghost[1].pos.y][g.ghost[1].pos.x + 1] != barreira[0])
                            g.ghost[1].pos.x += 1;
                        if (g.ghost[1].dir == left && g.lab[g.ghost[1].pos.y][g.ghost[1].pos.x - 1] != barreira[0])
                            g.ghost[1].pos.x -= 1;
                        if (g.ghost[1].dir == up && g.lab[g.ghost[1].pos.y - 1][g.ghost[1].pos.x] != barreira[0])                                            
                            g.ghost[1].pos.y -= 1;
                        if (g.ghost[1].dir == down && g.lab[g.ghost[1].pos.y + 1][g.ghost[1].pos.x] != barreira[0] && g.lab[g.ghost[1].pos.y + 1][g.ghost[1].pos.x] != barreira[1])
                            g.ghost[1].pos.y += 1;
                    }
                    if (contpacdot > 17)
                    {
                        if (g.ghost[2].dir == right && g.lab[g.ghost[2].pos.y][g.ghost[2].pos.x + 1] != barreira[0])
                            g.ghost[2].pos.x += 1;
                        if (g.ghost[2].dir == left && g.lab[g.ghost[2].pos.y][g.ghost[2].pos.x - 1] != barreira[0])
                            g.ghost[2].pos.x -= 1;
                        if (g.ghost[2].dir == up && g.lab[g.ghost[2].pos.y - 1][g.ghost[2].pos.x] != barreira[0])                      
                            g.ghost[2].pos.y -= 1;
                        if (g.ghost[2].dir == down && g.lab[g.ghost[2].pos.y + 1][g.ghost[2].pos.x] != barreira[0] && g.lab[g.ghost[2].pos.y + 1][g.ghost[2].pos.x] != barreira[1])
                            g.ghost[2].pos.y += 1;
                    }
                    if (contpacdot > 32 )
                    {
                        if (g.ghost[3].dir == right && g.lab[g.ghost[3].pos.y][g.ghost[3].pos.x + 1] != barreira[0])
                            g.ghost[3].pos.x += 1;
                        if (g.ghost[3].dir == left && g.lab[g.ghost[3].pos.y][g.ghost[3].pos.x - 1] != barreira[0])
                            g.ghost[3].pos.x -= 1;
                        if (g.ghost[3].dir == up && g.lab[g.ghost[3].pos.y - 1][g.ghost[3].pos.x] != barreira[0])
                            g.ghost[3].pos.y -= 1;
                        if (g.ghost[3].dir == down && g.lab[g.ghost[3].pos.y + 1][g.ghost[3].pos.x] != barreira[0] && g.lab[g.ghost[3].pos.y + 1][g.ghost[3].pos.x] != barreira[1])
                            g.ghost[3].pos.y += 1;
                    }
                }

                if(ch == KEY_RIGHT) // verifica a direção dada pelo input do usuário
                {
                    g.pacman.dir = right;
                }
                else if(ch == KEY_LEFT)
                {
                    g.pacman.dir = left;
                }
                else if(ch == KEY_UP)
                {
                    g.pacman.dir = up;
                }
                    else if(ch == KEY_DOWN)
                {
                g.pacman.dir = down;
                }







                if(g.pacman.dir == right) // altera a posição do personagem e verifica as barreiras
                {
                if(barreira[0] != labmodel[g.pacman.pos.y][g.pacman.pos.x + 1])
                {
                   g.pacman.pos.x++;
                }
                }
                else if(g.pacman.dir == left)
                {
                    if(barreira[0] != labmodel[g.pacman.pos.y][g.pacman.pos.x - 1])
                    {
                        g.pacman.pos.x--;
                }
                }
                else if(g.pacman.dir == up)
                {
                if(barreira[0] != labmodel[g.pacman.pos.y - 1][g.pacman.pos.x])
                {
                    g.pacman.pos.y--;
                }
                }
                else if(g.pacman.dir == down)
                {
                     if (barreira[0] != labmodel[g.pacman.pos.y + 1][g.pacman.pos.x] && barreira[1] != labmodel[g.pacman.pos.y + 1][g.pacman.pos.x]) // tambem impede que o pacman pass pela porta dos fantasmas
                     {
                         g.pacman.pos.y++;
                     }
                }


                if(g.pacman.pos.x < 1) // teleporta o pacman se ele passar pelos tuneis laterais
                {
                    g.pacman.pos.x = 19;
                }
                if(g.pacman.pos.x > 19)
                {
                    g.pacman.pos.x = 1;
                }

                if (g.lab[g.pacman.pos.y][g.pacman.pos.x] == pacdot[0]) // verifica se onde o pacman está tem uma bolinha
                {
                   contpacdot++; // mais um para o contador
                   g.pacman.score++;
                }

                if (g.lab[g.pacman.pos.y][g.pacman.pos.x] == pacdot[1]) // verifica se onde o pacman está tem uma bolinha grande
                {
                    powerup = 1;
                    g.pacman.score += 5;
                }

                if (powerup > 0)
                {
                    powerup += 1;
                }
                if (powerup > 50)
                { 
                    powerup = 0;
                }

                if (contpacdot % 184 == 0 && contpacdot != 0)//reseta o jogo se o pacman comer todas as bolinhas
                {
                    usleep(1000000);
                    contpacdot = 0;
                    for(int y = 0; y < 23; y++) // zera o labirinto
                    {
                        strcpy(g.lab[y], labmodel[y]);
                    }
                    g.pacman.pos.y = 17; 
                    g.pacman.pos.x = 9;
                    usleep(100000);
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
void imprime_menu (void) //imprime o menu
{
    int ymax, xmax; //mostra qual o x e y máximos da tela
    getmaxyx(stdscr, ymax, xmax); //stdscr = janela grande inicial

    mvprintw(19, (xmax/2)-12, "PRESSIONE 's' PARA SAIR");

    /*Ajuda*/
    mvprintw(27, (xmax/2)-3, "AJUDA ");
    mvprintw(31, (xmax/2)-44, "Ajude o Pacman (@) a comer todas as pastilhas do labirinto. Você tem 3 vidas para isso!");
    mvprintw(33, (xmax/2)-67, "Os fantasmas Inky, Pinky, Blinky e Clyde vão tentar atingir o Pacman. Cuidado: cada um deles tem sua estratégia única. Então, atenção!");
    mvprintw(35, (xmax/2)-31, "Se algum dos fantasmas atingir o pacman, você perderá uma vida");
    mvprintw(37, (xmax/2)-50, "O labirinto possui 184 pastilhas (.) e 4 pílulas (o). As pastilhas valem 10 pontos, e cada pílula 50 pontos");
    mvprintw(39, (xmax/2)-49, "As pastilhas darão ao Pacman o poder de comer os fantasmas. Cada fantasma devorado vale 750 pontos");
    mvprintw(41, (xmax/2)-17, "O Pacman conta com você. Bom jogo!");
    
    refresh(); //atualiza a tela inicial
    
    
    /*Título*/
    mvprintw(6, (xmax/2)-33, "UU  UU  PPPPP   EEEEEE");
    mvprintw(7, (xmax/2)-33, "UU  UU  PP   P  EE    ");
    mvprintw(8, (xmax/2)-33, "UU  UU  PP   P  EE      CCCCCCC    M     M    AAAAAAA  NN    NN    ");
    mvprintw(9, (xmax/2)-33, "UU  UU  PPPPP   EE EE   CC   CC  MM M  M  MM  AA   AA  NN N  NN    ");
    mvprintw(10, (xmax/2)-33, "UU  UU  PP      EE      CC       MM   M   MM  AAAAAAA  NN  N NN    ");
    mvprintw(11, (xmax/2)-33, "UU  UU  PP      EE      CCCCCCC  MM       MM  AA   AA  NN    NN  0 ");
    mvprintw(12, (xmax/2)-33, "UUUUUU  PP      EEEEEE");
    return;
}



t_game upecman_init(void)
{
    IFDEBUG("init()");
    /* initialization */

    t_game g;
    int f, y;
    char vazio[1] = " ";

    for(y = 0; y < 23; y++) //LABL = número de linhas do labirinto
        strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */

    g.pacman.pos.y = 17; /* pacman start position (line) */
    g.pacman.pos.x = 9; /* pacman start position (column) */
    g.pacman.dir = left; /* pacman start direction */
    g.pacman.life = 3; /* 3 lifes */
    g.pacman.score = 0; /* 0 points */

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
    IFDEBUG("printlab()");

    int y, f;
    int score = 0;
    int powerup = 0;


    for(y = 0; y < 23; y++)
    {
        mvprintw(0+y,0,"%s", g.lab[y]);
    }
    mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");
    mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);

    mvprintw(g.ghost[0].pos.y, g.ghost[0].pos.x, "B");
    mvprintw(g.ghost[1].pos.y, g.ghost[1].pos.x, "P");
    mvprintw(g.ghost[2].pos.y, g.ghost[2].pos.x, "I");
    mvprintw(g.ghost[3].pos.y, g.ghost[3].pos.x, "C");
    
    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
        mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f + 1, NULL);



    //refresh();
}

t_game fantdirec (t_game g)
{
    char barreira[2] = "#-";
    int troca = 0;
    int i;

    g.ghost[0].starget.y = g.pacman.pos.y;// alvo blinky
    g.ghost[0].starget.x = g.pacman.pos.x;

    if (g.pacman.dir == right)//alvo pinky
    {
        g.ghost[1].starget.y = g.pacman.pos.y;
        g.ghost[1].starget.x = g.pacman.pos.x + 4;
    }
    if (g.pacman.dir == left)
    {
        g.ghost[1].starget.y = g.pacman.pos.y;
        g.ghost[1].starget.x = g.pacman.pos.x - 4;
    }
    if (g.pacman.dir == up)
    {
        g.ghost[1].starget.y = g.pacman.pos.y - 4;
        g.ghost[1].starget.x = g.pacman.pos.x;
    }
    if (g.pacman.dir == down)
    {
        g.ghost[1].starget.y = g.pacman.pos.y + 4;
        g.ghost[1].starget.x = g.pacman.pos.x;
    }

    
    for(i = blinky; i<=clyde; i++)
    {
        if (g.ghost[i].mode == chase)
        {
            if (g.ghost[i].dir == right)
            {
                if (g.ghost[i].starget.y > g.ghost[i].pos.y && g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[0])
                {
                    g.ghost[i].dir = down;
                    troca = 1;
                }
                else if (g.ghost[i].starget.y < g.ghost[i].pos.y && g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != barreira[0])
                {
                    g.ghost[i].dir = up;
                    troca = 1;
                }
                else if (g.ghost[i].starget.x > g.ghost[i].pos.x && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != barreira[0])
                {
                    g.ghost[i].dir = right;
                    troca = 1;
                }
            }
            else if (g.ghost[i].dir == left)
            {
                if (g.ghost[i].starget.y > g.ghost[i].pos.y && g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[0])
                {
                    g.ghost[i].dir = down;
                    troca = 1;
                }
                else if (g.ghost[i].starget.y < g.ghost[i].pos.y && g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != barreira[0])
                {
                    g.ghost[i].dir = up;
                    troca = 1;
                }
                else if (g.ghost[i].starget.x < g.ghost[i].pos.x && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != barreira[0])
                {
                    g.ghost[i].dir = left;
                    troca = 1;
                }
            }
            else if (g.ghost[i].dir == up)
            {
                if (g.ghost[i].starget.x > g.ghost[i].pos.x && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != barreira[0])
                {
                    g.ghost[i].dir = right;
                    troca = 1;
                }
                else if (g.ghost[i].starget.x < g.ghost[i].pos.x && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != barreira[0])
                {
                    g.ghost[i].dir = left;
                    troca = 1;
                }
                else if (g.ghost[i].starget.x < g.ghost[i].pos.y && g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != barreira[0])
                {
                    g.ghost[i].dir = up;
                    troca = 1;
                }
            }
            else if (g.ghost[i].dir == down)
            {
                if (g.ghost[i].starget.x > g.ghost[i].pos.x && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != barreira[0])
                {
                    g.ghost[i].dir = right;
                    troca = 1;
                }
                else if (g.ghost[i].starget.x < g.ghost[i].pos.x && g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != barreira[0])
                {
                    g.ghost[i].dir = left;
                    troca = 1;
                }
                else if (g.ghost[i].starget.y > g.ghost[i].pos.y && g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[0])
                {
                    g.ghost[i].dir = down;
                    troca = 1;
                }
            }
        }
        if (troca == 0) // evita que o fantasma fique travado
        {
            if (g.ghost[i].dir == right)
            {
                if (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != barreira[0])
                    g.ghost[i].dir = right;
                else if (g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[0])
                    g.ghost[i].dir = down;
                else if (g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != barreira[0])
                    g.ghost[i].dir = up;
            }
            else if (g.ghost[i].dir == left)
            {
                if (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != barreira[0])
                    g.ghost[i].dir = left;
                else if (g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[0])
                    g.ghost[i].dir = down;
                else if (g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != barreira[0])
                    g.ghost[i].dir = up;
            }
            else if (g.ghost[i].dir == up)
            {
                if (g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != barreira[0])
                    g.ghost[i].dir = up;
                else if (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != barreira[0])
                    g.ghost[i].dir = right;
                else if (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != barreira[0])
                    g.ghost[i].dir = left;
            }
            else if (g.ghost[i].dir == down)
            {
                if (g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != barreira[0])
                    g.ghost[i].dir = down;
                else if (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != barreira[0])
                    g.ghost[i].dir = right;
                else if (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != barreira[0])
                    g.ghost[i].dir = left;
            }
            troca = 0;
        }
    }
    return g;
}

