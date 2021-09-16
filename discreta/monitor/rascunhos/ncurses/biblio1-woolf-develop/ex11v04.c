/*****************************************************************************
 *   ex11.c                                    Version 20180714.101818        *
 *                                                                           *
 *   Brief description                                                       *
 *   Copyright (C) 2016-2018    by Ruben Carlo Benante                       *
 *****************************************************************************
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License.          *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.               *
 *****************************************************************************
 *   To contact the author, please write to:                                 *
 *   Ruben Carlo Benante                                                     *
 *   Email: rcb@beco.cc                                                      *
 *   Webpage: www.beco.cc                                                    *
 *   Phone: +55 (81) 3184-7555                                               *
 *****************************************************************************/

/* ------------------------------------------------------------------------- */
/**
 * @file ex11.c
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
 *   $gcc ex11.c -o ex11.x -Wall
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
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv ex11.c
 */

/* ------------------------------------------------------------------------- */
/* includes at ex11.h */

#include "ex11v04.h" /* To be created for this template if needed */
file_entry str;
void search2(wins_t *pw, char *str);
/* ------------------------------------------------------------------------- */
/**
  * @ingroup GroupUnique
 * @brief This 
 * @details Ladies and 
 * 
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */


int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    int kpress; /* tecla pressionada no laco principal */
    wins_t win; /* info para ncurses */
    livro_t book;

    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -V  version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hV")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'V':
                copyr();
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    ex11_init(&win);/* initialization function */
    printTemplate(&win); /* printa o template */
    do
    {
        refresh();
        wrefresh(win.w[win.wi]);
        kpress=getch();

        if(kpress==KEY_F(1) || kpress=='1')
        {
            wattroff(win.w[win.wi], A_REVERSE);
            phelp(&win);
        }
        else if(kpress=='s')
            msgstatus(win, "Status Line: ", STOK);
        else if(kpress==KEY_F(4) || kpress=='4')
            bomb(win,"",0,NULL);
        else if(kpress==KEY_F(2) || kpress=='2')
        {
            refresh();
            wrefresh(win.w[win.wi]);
            mvwprintw(win.w[win.wi],15,55,"Command in progress :)");

            refresh();
            wrefresh(win.w[win.wi]);
        }
        else if(kpress==KEY_F(3) || kpress=='3')
        {
            refresh();
            wrefresh(win.w[win.wi]);
            mvwprintw(win.w[win.wi],15,55,"Command in progress :)");

            refresh();
            wrefresh(win.w[win.wi]);
        }
        else if(kpress==KEY_F(5) || kpress=='5')
        {
            refresh();
            wrefresh(win.w[win.wi]);

            if(win.wi==5)
                win.wi=0;
            else
                win.wi++;
            wattroff(win.w[win.wi],A_REVERSE);
            printTemplate(&win);

            refresh();
            wrefresh(win.w[win.wi]);
        }
        else if(kpress==KEY_F(6) || kpress=='6')
        {
            refresh();
            wrefresh(win.w[win.wi]);

            if(win.wi == 0)
                  win.wi=5;
            else
                win.wi--;

            wattroff(win.w[win.wi],A_REVERSE);
            printTemplate(&win);

            refresh();
            wrefresh(win.w[win.wi]);
        }
        else if(kpress==KEY_F(7) || kpress=='7')
        {
            wclear(win.w[win.wi]);
            ex11_init(&win);
            printTemplate(&win);
        }
        else if(kpress==KEY_F(8) || kpress=='8')
        {
             if(win.wi==0)
            {
                wattroff(win.w[win.wi],A_REVERSE); 
                moveInData(&win, &book);
                wattroff(win.w[win.wi],A_REVERSE); 
                printTemplate(&win);
            }
            if(win.wi==1)
            {
                wattroff(win.w[win.wi],A_REVERSE); 
                searchInData(&win);
                wattroff(win.w[win.wi],A_REVERSE); 
                printTemplate(&win);
            }
        }
        napms(50);
    }while(kpress!='q');

    bomb(win, "", 0, NULL);

    return EXIT_SUCCESS;
}

/* Write your functions here... */

/* ------------------------------------------------------------------------- */
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

/* ------------------------------------------------------------------------- */
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
    printf("%s - Version %s\n", "exN", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}
void phelp(wins_t *pw)
{
    int xMAX,yMAX;
    getmaxyx(stdscr,yMAX,xMAX);

    IFDEBUG("phelp()");
    if(pw->wi!=pw->wo)
    {
        pw->wo=pw->wi;
        wclear(pw->w[pw->wi]);
        box(pw->w[pw->wi], 0, 0);
    }
    
    refresh();
    wrefresh(pw->w[pw->wi]);
    printTemplate(pw);
    wattroff(pw->w[pw->wi],A_REVERSE);
    mvwvline(pw->w[pw->wi],yMAX-yMAX/1.2,xMAX-xMAX/4.2,0,(yMAX/5)+1);
    wattron(pw->w[pw->wi],A_BOLD);
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-5)) ,xMAX-xMAX/4.3, "F1(HELP)->Commands/instructions");
            //mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
    mvwprintw(pw->w[pw->wi], (yMAX-(yMAX-6)), xMAX-xMAX/4.3, "F2(LOAD) -> Load a txt file");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-7)) , xMAX-xMAX/4.3, "F3(SAVE) -> Save all");
    mvwprintw(pw->w[pw->wi], (yMAX-(yMAX-8)), xMAX-xMAX/4.3, "F4(QUIT) -> Close program");
    mvwprintw(pw->w[pw->wi], (yMAX-(yMAX-9)), xMAX-xMAX/4.3, "F5(NEXT) -> Next page");
    mvwprintw(pw->w[pw->wi], (yMAX-(yMAX-10)), xMAX-xMAX/4.3, "F6(PREV) -> Previous page");
    mvwprintw(pw->w[pw->wi], (yMAX-(yMAX-11)), xMAX-xMAX/4.3, "F7(RELD) -> adjust the screen");
    wattroff(pw->w[pw->wi],A_BOLD);
    
    refresh();
    wrefresh(pw->w[pw->wi]);

}

/* ------------------------------------------------------------------------- */
// imprime na linha de status

int msgstatus(wins_t win, char *msg, int tipo)
{
    int yMAX,X;
    getmaxyx(stdscr, yMAX,X);
    X=2;
    IFDEBUG("msgstatus()");
    switch(tipo)
    {
        case STOK:
            mvwprintw(win.w[win.wi], yMAX-4, X, "%s", msg);
            break;
        case STYESNO:
            mvwprintw(win.w[win.wi], yMAX-4, X, "%s", msg);
            break;
        default:
            mvwprintw(win.w[win.wi], yMAX-4, X, "status type undefined");
            break;
    }
    wrefresh(win.w[win.wi]);
    return 1;
}


void bomb(wins_t win, char *msg, int status, FILE *f)
{
    IFDEBUG("bomb()");
    int i;

    if(f)
        fclose(f);

    for(i=0; i<NWIN; i++)
        delwin(win.w[i]);

    endwin();
    fprintf(stderr, msg);

    exit(status);
}

void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "exN", "Brief description");
    printf("\nUsage: %s [-h|-v]\n", "exN");
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

/* ------------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written in
 * multiple lines
 *
 * @return Void
 *
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 * @copyright Use this tag only if not the same as the whole file
 *
 */
void ex11_init(wins_t *pw)
{
    int xMAX,yMAX;
    IFDEBUG("ex15_init()");
    int i; /* indice */
    for(i=0; i<NWIN; i++)
        pw->menu[i]=0;

    pw->wi=0; /* inicia na tela de help */
    pw->wo=1; /* tela anterior aa mudanca */

    initscr(); /* inicializa ncurses */
    napms(10); /* aguarda initscr() */
    refresh(); /* inicializar tela */
    halfdelay(2); /* cbreak sem espera ocupada */
    noecho(); /* desliga eco de teclado */
    keypad(stdscr, TRUE); /* liga teclas de funcao */
    
    getmaxyx(stdscr,yMAX, xMAX);
    /* criar janelas */
    start_color();
    init_pair(1,COLOR_GREEN, COLOR_BLACK);
    for(i=0; i<NWIN; i++)
    {
        pw->w[i]=newwin(yMAX,xMAX,0,0);
        wbkgd(pw->w[i],COLOR_PAIR(1));
        if(pw->w[i]==NULL)
        {
            for(--i; i>=0; --i)
                delwin(pw->w[i]);
            endwin();
            fprintf(stderr, "Error: can't create windows\n");
            exit(EXIT_FAILURE);
        }
    }

    pw->lmax=LINES; /* qtdd de linhas na tela */
    pw->cmax=COLS; /* qtdd de colunas na tela */
    return;
}

void printTemplate(wins_t *pw)
{
    int xMAX,yMAX;
    getmaxyx(stdscr,yMAX,xMAX);
    switch(pw->wi)
    {
        case 0:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-1),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Cadastro de livros",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            printData(pw);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-6)),(xMAX-(xMAX-59)),"Pressione F8 para entrar em modo de Edição");

            break;
        case 1:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-1),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Consulta de Livros",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-6)),(xMAX-(xMAX-59)),"Pressione F8 para entrar em modo de PESQUISA");
            printData(pw);
            break;
        case 2:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-1),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Page in Work",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            break;
        case 3:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Page in Work",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            break;
        case 4:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Page in Work",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            break;
        case 5:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Page in Work",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            break;
        default:
            break;
    }
    
    mvwhline(pw->w[pw->wi],(yMAX-3),xMAX-(xMAX-1),0,xMAX-2);
    wattron(pw->w[pw->wi],A_REVERSE); 
    mvwprintw(pw->w[pw->wi],yMAX-2,xMAX-(xMAX-2),"F1 HELP");
    mvwprintw(pw->w[pw->wi],yMAX-2,xMAX-(xMAX-12),"F2 LOAD");
    mvwprintw(pw->w[pw->wi],yMAX-2,xMAX-(xMAX-22),"F3 SAVE");
    mvwprintw(pw->w[pw->wi],yMAX-2,xMAX-(xMAX-32),"F4 QUIT");
    mvwprintw(pw->w[pw->wi],yMAX-2,xMAX-(xMAX-52),"F5 NEXT");
    mvwprintw(pw->w[pw->wi],yMAX-2,xMAX-(xMAX-62),"F6 PREV");
    mvwprintw(pw->w[pw->wi],yMAX-2,xMAX-(xMAX-72),"F7 RELD");
    wrefresh(pw->w[pw->wi]);
    refresh();
}

void moveInData(wins_t *pw, livro_t *l)
{
    int counter = 6;
    int options = 0;
    int string = 0;
    char caractere = ' ';
    int i = 0;
    l->titulo = (char*)calloc(10,sizeof(char));
    
    l->autor = (char*)calloc(10,sizeof(char));
    l->editora = (char*)calloc(10,sizeof(char));
    l->local = (char*)calloc(10,sizeof(char));

    int yMAX,xMAX;
    getmaxyx(stdscr,yMAX,xMAX);   
    
   

    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-8)),(xMAX-(xMAX-59)),"Pressione F8 novamente para do modo de edição ");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-10)),(xMAX-(xMAX-59)),"Use as setas para se mover entre as opções");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-12)),(xMAX-(xMAX-59)),"Use Enter para selecionar a opção e Enter novamente para desselecionar");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-14)),(xMAX-(xMAX-59)),"Use BackSpace para voltar ao início do texto");
   
    refresh();
    wrefresh(pw->w[pw->wi]);
    
    do
    {    
        refresh();
        wrefresh(pw->w[pw->wi]);
        
        options=getch();
        
        wattron(pw->w[pw->wi], A_BLINK); 
        mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-counter)),(xMAX-(xMAX-54)),"<==");
        wattroff(pw->w[pw->wi], A_BLINK);
        
        refresh();
        wrefresh(pw->w[pw->wi]);
        
        switch(options)
        {
            case 10:
                switch(counter)
                {
                    case 6:
                        echo();
                        move(yMAX-(yMAX-counter),xMAX-(xMAX-7));
                        char *teste2 = (char*)calloc(10,sizeof(char));
                        while(1)
                        {
                            if((string=getch()) == ERR)
                                continue;
                            else
                            {
                                if(string!=10)
                                {
                                    l->cod = string-48;
                                }
                                else if(string == 8)
                                    move(yMAX-(yMAX-counter),xMAX-(xMAX-10));
                                else
                                    break;
                            }
                        }    
                        teste2 = itoa(l->cod,teste2,10);

                        noecho();
                        string =0;
                        free(teste2);
                        break;

                    case 7:
                        move(yMAX-(yMAX-counter),xMAX-(xMAX-10));
                        echo();
                        i=0;              
                
                        while(1)
                        {
                            if((caractere=getch()) == ERR)
                                continue;
                            else
                            {
                                if(caractere!=10)
                                {
                                    l->titulo[i] = caractere;
                                    i =i+1;
                                }
                                else if(caractere == 8)
                                    move(yMAX-(yMAX-counter),xMAX-(xMAX-10));
                                else
                                    break;
                            }    
                        }
                        i=0;
                        caractere = ' ';
                        noecho();
                        break;
                        
                    case 8:
                        move(yMAX-(yMAX-counter),xMAX-(xMAX-9));
                        echo();
                        while(1)
                        {
                            if((caractere=getch()) == ERR)
                                continue;
                            else
                            {
                                if(caractere!=10)
                                {
                                    l->autor[i] = caractere;
                                    i =i+1;
                                }
                                else if(caractere == 8)
                                    move(yMAX-(yMAX-counter),xMAX-(xMAX-10));
                                else
                                    break;
                            }
                        }    
                        i=0;
                        caractere = ' ';
                        noecho();
                        break;

                    case 9:
                        move(yMAX-(yMAX-counter),xMAX-(xMAX-7));
                        echo();
                        char* teste = (char*)calloc(10,sizeof(char));
                        int num[4] ={48,48,48,48};
                        while(1)
                        {
                            if((string=getch()) == ERR)
                                continue;
                            else
                            {
                                if(string!=10 && string != 8)
                                {
                                    num[i] = string;
                                    i =i+1;
                                }
                                else if(string == 8)
                                {
                                    int X;
                                    
                                    num[i]=48;
                                    i--;
                                    if(i > 0)
                                    {
                                        move(yMAX-(yMAX-counter),(xMAX-(xMAX-7))+i);
                                        X = (xMAX-(xMAX-7)+i);
                                        mvwprintw(pw->w[pw->wi],yMAX-(yMAX-counter),X,"_");
                                    }
                                    if(i <= 0)
                                    { 
                                        for(int cl=0; cl<4; cl++)
                                            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-counter),xMAX-(xMAX-8),"_");
                                        i=0; 
                                        move(yMAX-(yMAX-counter),xMAX-(xMAX-7));
                                        mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-counter)),(xMAX-(xMAX-7)),"_");
                                    }
                                    refresh();
                                    wrefresh(pw->w[pw->wi]);
                                }
                                else
                                    break;
                            }
                        }    
                        noecho();
                        l->ano = (((num[0]-48)*1000)+((num[1]-48)*100)+((num[2]-48)*10)+(num[3]-48));
                        teste = itoa(l->ano,teste,10);
                        i=0;
                        string =0;
                        free(teste);
                        break;

                    case 10:
                        move(yMAX-(yMAX-counter),xMAX-(xMAX-11));
                        echo();

                        while(1)
                        {
                            if((caractere=getch()) == ERR)
                                continue;
                            else
                            {
                                if(caractere!=10)
                                {
                                    l->editora[i] = caractere;
                                    i =i+1;
                                }
                                else if(caractere == 8)
                                    move(yMAX-(yMAX-counter),xMAX-(xMAX-10));
                                else
                                    break;
                            }
                        }    
                        noecho();
                        i=0;
                        string =0;
                        break;

                    case 11:
                        move(yMAX-(yMAX-counter),xMAX-(xMAX-9));
                        echo();
                        while(1)
                        {
                            if((caractere=getch()) == ERR)
                                continue;
                            else
                            {
                                if(caractere!=10)
                                {
                                    l->local[i] = caractere;
                                    i =i+1;
                                }
                                else if(caractere == 8)
                                    move(yMAX-(yMAX-counter),xMAX-(xMAX-10));
                                else
                                    break;
                            }
                        }    
                        i=0;
                        string =0;
                        caractere= ' ';
                        noecho();
                        break;

                    case 14:
                        move(yMAX-(yMAX-counter),xMAX-(xMAX-10));
                        echo();
                        char *teste3 = (char*)calloc(10,sizeof(char));
                        while(1)
                        {
                            if((string=getch()) == ERR)
                                continue;
                            else
                            {
                                if(string!=10)
                                {
                                    l->ed = string-48;
                                }
                                else if(string == 8)
                                    move(yMAX-(yMAX-counter),xMAX-(xMAX-10));
                                else
                                    break;
                            }
                        }    
                        noecho();
                        teste3 = itoa(l->ed,teste3,10);
                        free(teste3);
                        i=0;
                        string =0;
                        break;

                    case 15:
                        move(yMAX-(yMAX-counter),xMAX-(xMAX-8));
                        echo();
                        char *teste4 = (char*)calloc(10,sizeof(char));

                        int num2[4]={48,48,48,48};
                        while(1)
                        {
                            if((string=getch()) == ERR)
                                continue;
                            else
                            {
                                if(string!=10)
                                {
                                    num2[i] = string;
                                    i =i+1;
                                }
                                else if(string == 8)
                                    move(yMAX-(yMAX-counter),xMAX-(xMAX-10));
                                else
                                    break;
                            }
                        }    
                        l->isbn = (((num2[0]-48)*1000)+((num2[1]-48)*100)+((num2[2]-48)*10)+(num2[3]-48));
                        teste4 = itoa(l->isbn,teste4,10);
                        noecho();
                        free(teste4);
                        i=0;
                        string =0;
                        break;
                }
                break;
            case KEY_F(3):

                str.buffer="";
                FILE *livros;
                char *concatenado=NULL, *aux=NULL;
                aux = (char*)calloc(10,sizeof(char)); 

                aux = itoa(l->cod, aux,10);

                str.buffer = concatenate(concatenado,str, aux);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, l->titulo);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, l->autor);
                str.buffer = concatenate(concatenado,str, ";");

                aux = itoa(l->ano, aux,10);
                str.buffer = concatenate(concatenado,str, aux);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, l->editora);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, l->local);
                str.buffer = concatenate(concatenado,str, ";");
                aux = itoa(l->ed, aux,10);
                str.buffer = concatenate(concatenado,str, aux);
                str.buffer = concatenate(concatenado,str, ";");
                aux = itoa(l->isbn, aux,10);
                str.buffer = concatenate(concatenado,str, aux);
                str.buffer = concatenate(concatenado,str, "\n");

                mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-24)),(xMAX-(xMAX-34)+i),"LIVRO SALVO!!! %s",str.buffer);
                

                livros = fopen("livros.txt", "r+");
                fseek(livros, 0, SEEK_END);
                fputs(str.buffer,livros);

                fclose(livros);
                free(str.buffer);
                free(aux);
                
                break;
            case KEY_DOWN:
                mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-counter)),(xMAX-(xMAX-54)),"   ");
                wattroff(pw->w[pw->wi], A_BLINK);
                counter++;
                switch(counter)
                {
                    case 12:    
                        counter=14;
                        break;
                    case 16:
                        counter=6;
                        break;
                }
                break;
            case KEY_UP:
                mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-counter)),(xMAX-(xMAX-54)),"   ");
                wattroff(pw->w[pw->wi], A_BLINK);
                counter--;
                switch(counter)
                {
                    case 5:
                        counter=15;
                        break;
                    case 13:
                        counter=11;
                        break;
                }
                break;
            default:
                break;
        }
    }
    while(options !=KEY_F(8));
    refresh();
}
/*funcao a ser mexida */
char *search(wins_t *pw, char **str)
{
    //str = (char*)calloc(10,sizeof(char));
    int xMAX,yMAX;
    getmaxyx(stdscr,yMAX,xMAX);

    FILE *arquivo;
    arquivo = fopen("livros.txt","r");
    
   /* if(*str == NULL)
    {
        mvwprintw(pw->w[pw->wi],yMAX-(yMAX-10),xMAX-(xMAX-5),"Favor, inserir um texto válido");
        return *str;
        //return;
    }

    
    if(arquivo == NULL)
    {
        //printf("Não foi possível ler o arquivo!\n");
        mvwprintw(pw->w[pw->wi],yMAX-(yMAX-10),xMAX-(xMAX-5),"Favor, inserir um texto válido");
        return *str;
        //return;
    }*/

    int line = 1;
    int i =0;

    char stringSearched[100];
    char *stringChanged = (char*)calloc(20,sizeof(char));
    
    while(fgets(stringSearched,100,arquivo)!=NULL)
    {
        if(strstr(stringSearched,*str)!=NULL)
        {
            strcpy(stringChanged,stringSearched);
            
            while(stringChanged[i] != '\n')
            {
                //printf("%c",stringChanged[i]);
                if(stringChanged[i] == ';')
                    stringChanged[i] = ' ';
                else
                    i++;
            }
            //printf("\n");
            //printf("[%i] %s\n",line, stringChanged); 

            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-10),xMAX-(xMAX-5),"%s",stringChanged);
        }
        line++;   
    }
    
    refresh();
    wrefresh(pw->w[pw->wi]);

    free(stringChanged);
    //free(str);

    if(arquivo)
        fclose(arquivo);
    return *str;
}

void search2(wins_t *pw, char *str)
{
    FILE *arquivo;
    arquivo = fopen("livros.txt","r");
    
    int c =0, xMAX, yMAX; 
    int line = 1;
    int i =0;

    getmaxyx(stdscr,yMAX,xMAX);

    char stringSearched[200];
    char *stringChanged = (char*)calloc(10,sizeof(char));                                    
    while(fgets(stringSearched,200,arquivo)!=NULL)
    {
        if(strstr(stringSearched,str)!=NULL)
        {
            strcpy(stringChanged,stringSearched);

                while(stringChanged[i] != '\n')
                {
                    if(stringChanged[i] == ';')
                        stringChanged[i] = ' ';
                    else
                        i++;
                }
                mvwprintw(pw->w[pw->wi],yMAX-(yMAX-22-c),xMAX-(xMAX-1),"[%i] %s",line, stringChanged);
                c++;
        }
        line++;

    }
    free(stringChanged);
}

void searchInData(wins_t *pw)
{
    int counter = 7;
    int options = 0;
    char caractere = ' ';
    int i = 0;
    
    int yMAX,xMAX;
    getmaxyx(stdscr,yMAX,xMAX);   
    
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-8)),(xMAX-(xMAX-59)),"Pressione F8 novamente para sair do modo de Pesquisa ");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-12)),(xMAX-(xMAX-59)),"Use Enter para selecionar a opção e Enter novamente para desselecionar");
   
    refresh();
    wrefresh(pw->w[pw->wi]);
    
    do
    {    
        refresh();
        wrefresh(pw->w[pw->wi]);
        
        options=getch();
        
        wattron(pw->w[pw->wi], A_BLINK); 
        mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-counter)),(xMAX-(xMAX-54)),"<==");
        wattroff(pw->w[pw->wi], A_BLINK);
        
        refresh();
        wrefresh(pw->w[pw->wi]);
        
        switch(options)
        {
            case 10:
                switch(counter)
                {
                    case 7:
                        move(yMAX-(yMAX-counter),xMAX-(xMAX-10));
                        echo();
                        i=0;              
                        
                        char *tituloP = (char*)calloc(30,sizeof(char));

                        while(1)
                        {
                            if((caractere=getch()) == ERR)
                                continue;
                            else
                            {
                                if(caractere!=10)
                                {
                                    tituloP[i] = caractere;
                                    i =i+1;
                                }
                                else if(caractere == 8)
                                    move(yMAX-(yMAX-counter),xMAX-(xMAX-10));
                                else
                                {
                                    /*Trocar por uma unica funcao*/
                                    // FILE *arquivo;
                                    // arquivo = fopen("livros.txt","r");
                                    
                                    // int c =0; 
                                    // int line = 1;
                                    // int i =0;

                                    // char stringSearched[200];
                                    // char *stringChanged = (char*)calloc(10,sizeof(char));                                    
                                    // while(fgets(stringSearched,200,arquivo)!=NULL)
                                    // {
                                    //     if(strstr(stringSearched,tituloP)!=NULL)
                                    //     {
                                    //         strcpy(stringChanged,stringSearched);
                                
                                    //             while(stringChanged[i] != '\n')
                                    //             {
                                    //                 if(stringChanged[i] == ';')
                                    //                     stringChanged[i] = ' ';
                                    //                 else
                                    //                     i++;
                                    //             }
                                    //             mvwprintw(pw->w[pw->wi],yMAX-(yMAX-22-c),xMAX-(xMAX-1),"[%i] %s",line, stringChanged);
                                    //             c++;
                                    //     }
                                    //     line++;
        
                                    // }
                                    search2(pw, tituloP);

                                    break;
                                }
                            }    
                        }
                        i=0;
                        caractere = ' ';
                        noecho();
                        free(tituloP);
                        break;
                }
                break;
        }
    }
    while(options !=KEY_F(8));
    refresh();
}

char* itoa(int num, char* str, int base)
{
	int i = 0;
	bool isNegative = false;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	if (num < 0 && base == 10)
	{
		isNegative = true;
		num = -num;
	}

	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		num = num/base;
	}

	if (isNegative)
		str[i++] = '-';

	str[i] = '\0';

    str = strReverse(str);

	return str;
}

char *strReverse(char *__str)
{
	static int i=0, n=0;
    static char *string;
    i=0;
    if(__str == NULL)
        return NULL;
	else if (*__str == '\0') {
        string = (char*)calloc(n, sizeof(char));
		return string;
	}

    n++;

	strReverse(__str+1);

    string[i++] = *__str;

    n=0;

    return string;
}

void printData(wins_t *pw)
{

    int xMAX, yMAX;
    getmaxyx(stdscr,yMAX, xMAX);

    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX -5)),(xMAX-(xMAX-2)), "Campos Obrigatórios:");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX -6)),(xMAX-(xMAX-2)), "Cod: ____________________________________________");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX -7)),(xMAX-(xMAX-2)), "Titulo: _________________________________________");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX -8)),(xMAX-(xMAX-2)), "Autor: __________________________________________");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX -9)),(xMAX-(xMAX-2)), "Ano: ____________________________________________");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX -10)),(xMAX-(xMAX-2)), "Editora: ________________________________________");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX -11)),(xMAX-(xMAX-2)), "Local: __________________________________________");


    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX -13)),(xMAX-(xMAX-2)), "Campos Opcionais:");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX -14)),(xMAX-(xMAX-2)), "Edição: _________________________________________");
    mvwprintw(pw->w[pw->wi],(yMAX-(yMAX -15)),(xMAX-(xMAX-2)), "ISBN: ___________________________________________");

}

char *concatenate(char *dest, file_entry src, char *buffer)
{
    int newSize = strlen(src.buffer)  + strlen(buffer) + 1; 
    dest = (char *)calloc(newSize, sizeof(char));
    strcpy(dest,src.buffer);
    strcat(dest,buffer);
    return dest;
}
/* ------------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline    */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20180716.101436   */



