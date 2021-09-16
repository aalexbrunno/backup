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

#include "ex11.h" /* To be created for this template if needed */
file_entry str;
int num;
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
    form_t fm;
    
    IFDEBUG("Starting optarg loop...");

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

        if(kpress==KEY_F(1))
        {
            wattroff(win.w[win.wi], A_REVERSE);
            win.wi = 11;
            printTemplate(&win);
            wattroff(win.w[win.wi],A_REVERSE);
        }
        else if(kpress=='s')
            msgstatus(win, "Status Line: ", STOK);
        else if(kpress==KEY_F(4) || kpress=='4')
            bomb(win,"",0,NULL);
        else if(kpress==KEY_F(2) || kpress=='2')
        {
            refresh();
            wrefresh(win.w[win.wi]);
            if(win.wi==1)
            {
                wattroff(win.w[win.wi],A_REVERSE); 
                printFormSearch(&win,fm.fieldSearch,fm.formSearch,&book);
                wattroff(win.w[win.wi],A_REVERSE); 
                printTemplate(&win);
            }
            refresh();
            wrefresh(win.w[win.wi]);
        }
        else if(kpress==KEY_F(3) || kpress=='3')
        {
            refresh();
            wrefresh(win.w[win.wi]);

            refresh();
            wrefresh(win.w[win.wi]);
        }
        else if(kpress==KEY_F(5) || kpress=='5')
        {
            refresh();
            wrefresh(win.w[win.wi]);
            if(win.wi==11)
                win.wi=0;

            if(win.wi==10)
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
            if(win.wi == 11)
                win.wi=10;
            if(win.wi == 0)
                  win.wi=10;
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
                printTemplate(&win);
                printForm(&win,fm.fields,fm.form,&book);
                wattroff(win.w[win.wi],A_REVERSE); 
            }
            if(win.wi==1)
            {
                wattroff(win.w[win.wi],A_REVERSE); 
                printFormSearch(&win,fm.fieldSearch,fm.formSearch,&book);
                wattroff(win.w[win.wi],A_REVERSE); 
                printTemplate(&win);
            }
            if(win.wi==2)
            {
                wattroff(win.w[win.wi], A_REVERSE); 
                printFormLine(&win,fm.fieldSearch,fm.formSearch,&book);
                printFormLine2(&win,fm.fieldSearch,fm.formSearch,&book,book.hold);
                box(win.w[win.wi],0,0);
                wattroff(win.w[win.wi],A_REVERSE);
                printTemplate(&win);
            }
            if(win.wi==6)
            {
                wattroff(win.w[win.wi], A_REVERSE); 
                printFormLine(&win,fm.fieldSearch,fm.formSearch,&book);
                printFormLine2(&win,fm.fieldSearch,fm.formSearch,&book,book.hold);
                wattroff(win.w[win.wi],A_REVERSE);
                printTemplate(&win);
            }
            if(win.wi==8)
            {
                wattroff(win.w[win.wi], A_REVERSE); 
                printFormLoan(&win,fm.fieldSearch,fm.formSearch,&book);
                wattroff(win.w[win.wi],A_REVERSE);
                printTemplate(&win);
            }
            if(win.wi==3)
            {
                wattroff(win.w[win.wi],A_REVERSE); 
                deleteLine("livros.txt");
                wattroff(win.w[win.wi],A_REVERSE); 
                printTemplate(&win);
            }
            if(win.wi==4)
            {
                wattroff(win.w[win.wi],A_REVERSE); 
                printFormRegClient(&win,fm.fieldsRegClient,fm.formRegClient,&book);
                wattroff(win.w[win.wi],A_REVERSE); 
                printTemplate(&win);
            }
            if(win.wi==5)
            {
                wattroff(win.w[win.wi],A_REVERSE); 
                printFormSearch(&win,fm.fieldSearch,fm.formSearch,&book);
                wattroff(win.w[win.wi],A_REVERSE); 
                printTemplate(&win);
            }
            if(win.wi==7)
            {

                wattroff(win.w[win.wi],A_REVERSE); 
                deleteLine("clientes.txt");
                wattroff(win.w[win.wi],A_REVERSE); 
                printTemplate(&win);
            }
        }
        napms(50);
    }while(kpress!='q');
    
    bomb(win, "", 0, NULL);

    return EXIT_SUCCESS;
}

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
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-6)),(xMAX-(xMAX-59)),"Pressione F8 para entrar em modo de Cadastro");

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
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-6)),(xMAX-(xMAX-42)),"Pressione F8 para entrar em modo de PESQUISA");
            rectangle(pw,(yMAX/3)-1,xMAX/3,(yMAX/3)+1,(xMAX/3)+35);
            break;
        case 2:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-1),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Editar Livros",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            show(pw,"livros.txt");
            rectangle(pw,((yMAX/2)-1)+5,(xMAX/2)-4,((yMAX/2)+1)+5,(xMAX/2)+1);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-20)),(xMAX/4),"Pressione F8 e digite a linha do livro que deseja Editar");
            break;
        case 3:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Remover Livros",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            show(pw,"livros.txt");
            rectangle(pw,((yMAX/2)-1)+5,(xMAX/2)-4,((yMAX/2)+1)+5,(xMAX/2)+1);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-20)),(xMAX/4),"Pressione F8 e digite a linha do livro que deseja Remover");
            break;
        case 4:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Cadastro de Clientes",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-6)),(xMAX-(xMAX-59)),"Pressione F8 para entrar em modo de Cadastro");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-8)),(xMAX-(xMAX-59)),"Use as setas para se mover entre as linhas");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-10)),(xMAX-(xMAX-59)),"Pressione F8 uma segunda vez para sair do modo de Cadastro");
            break;
        case 5:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Consulta de Clientes",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-6)),(xMAX-(xMAX-42)),"Pressione F8 para entrar em modo de PESQUISA");
            rectangle(pw,(yMAX/3)-1,xMAX/3,(yMAX/3)+1,(xMAX/3)+35);
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-21),xMAX-(xMAX-1),"   /Cod/Nome/telefone/email/aniversario ");
            break;
        case 6:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-1),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Editar Clientes",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            show(pw,"clientes.txt");
            rectangle(pw,((yMAX/2)-1)+5,(xMAX/2)-4,((yMAX/2)+1)+5,(xMAX/2)+1);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-20)),(xMAX/4),"Pressione F8 e digite a linha do livro que deseja Editar");
            break;
        case 7:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Remover Clientes",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            show(pw,"clientes.txt");
            rectangle(pw,((yMAX/2)-1)+5,(xMAX/2)-4,((yMAX/2)+1)+5,(xMAX/2)+1);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-20)),(xMAX/4),"Pressione F8 e digite a linha do livro que deseja remover");
            break;
        case 8:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Emprestar Livros",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-24)),(xMAX-(xMAX-1)),"LIVROS:");
            show(pw,"livros.txt");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-18)),(xMAX-(xMAX-1)),"CLIENTES:");
            show2(pw,"clientes.txt");
            break;
        case 9:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela %i: Copyright e Creditos",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-10)),xMAX-(xMAX-1),"Sistema de biblioteca Smith.\n O projeto foi desenvolvido pelo grupo Smith, alunos da disciplina de Matemática Discreta do curso de Engenharia de \n Controle e Automacao pela Universidade de Pernambuco.Tendo como orientador o professor Doutor Ruben Carlo Benante.\n\n Participantes do grupo:\n Gabriel De Mendonca Ramalho <gabriel.mendoncaramalho@upe.br\n Eduardo Felipe Da Silva Braga <eduardo.eng.braga@gmail.com>\n Thayná Luiza Gitirana da Cunha <thaygitirana@gmail.com>\n Alex Bruno Seabra <aalexbrunno@gmail.com>\n Andre Wanderley de Melo <andrewanderleymelo@gmail.com>\n Adriano Jose Morais Barros Silva <ajmbs@poli.com>");
            box(pw->w[pw->wi],0,0);
            break;
        case 10:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela %i: Licensa",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-10)),xMAX-(xMAX-1),"                                        GNU GENERAL PUBLIC LICENSE\n\n                                         Version 2, June 1991\n\n                                         Copyright (C) 1989, 1991 Free Software Foundation, Inc.,\n                                         51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA\n                                         Everyone is permitted to copy and distribute verbatim copies\n                                         of this license document, but changing it is not allowed.");
            box(pw->w[pw->wi],0,0);
            break;
        case 11:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 00: Tela de Ajuda",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-5)),xMAX-(xMAX-1),"                                                  Comandos:\n\n                                                   F1 - > Help\n                                                   F2 - > Load\n                                                   F3 - > Save\n                                                   F4 - > Quit\n                                                   F5 - > Next Page\n                                                   F6 - > Previous Page\n                                                   F7 - > Reload");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-15)),xMAX-(xMAX-1),"Tela 01: Tela de cadastro de livros, use F8 para entrar em modo de edicao e apos preencher, pressione F3 para salvar e F8 para sair\n do modo de edicao a fim de poder se mover entre as janelas.(O mesmo serve para cadastro de clientes) ");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),"Tela 02: Tela de consulta de livros, use F8 para entrar em modo de pesquisa, aperte ENTER para pesquisar e F8 para sair do modo de\n pesquisa a fim de poder se mover entre as janelas.(O mesmo serve para tela de consulta de clientes) ");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-19)),xMAX-(xMAX-1),"Tela 03: Tela de edicao de livros, use F8 para entrar em modo de edicao, digite a linha que deseja editar, aperte ENTER, F8 e apos\n isso sera possivel editar a linha escolhida. Quando finalizar pressione F3 para salvar e F8 para sair\n do modo de edicao a fim de poder se mover entre as janelas.(O mesmo serve para a tela de edicao de clientes) ");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-22)),xMAX-(xMAX-1),"Tela 04: Tela de remocao de livros, use F8 para entrar em modo de edicao, digite a linha do livro que deseja remover, aperte ENTER,\n(Nao eh necessario usar F8 apos. (O mesmo serve para a tela de remocao de clientes) ");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-24)),xMAX-(xMAX-1),"Tela 09: Tela de emprestimo de livros, use F8 para entrar em modo de edicao, digite o codigo do cliente e do livro, pressione F3,\ncaso o cliente esteja cadastrado e o livro esteja disponivel sera efetuado o emprestimo. Apos finalizar, pressione F8 para sair\n do modo de edicao.");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-27)),xMAX-(xMAX-1),"Tela 10: Tela de Copyright e Creditos, contem informacoes a sobre os participantes do grupo ");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-28)),xMAX-(xMAX-1),"Tela 11: Tela de Licensa, tela com a licensa GNU ");
            box(pw->w[pw->wi],0,0);
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

void printForm(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw)
{
	int ch;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	
	fields[0] = new_field(1, 10, 1, 0, 0, 0);
	fields[1] = new_field(1, 40, 1, 15, 0, 0);
	fields[2] = new_field(1, 10, 2, 0, 0, 0);
	fields[3] = new_field(1, 40, 2, 15, 0, 0);

	fields[4] = new_field(1, 10, 3, 0, 0, 0);
	fields[5] = new_field(1, 40, 3, 15, 0, 0);
	fields[6] = new_field(1, 10, 4, 0, 0, 0);
	fields[7] = new_field(1, 40, 4, 15, 0, 0);
	fields[8] = new_field(1, 10, 5, 0, 0, 0);
	fields[9] = new_field(1, 40, 5, 15, 0, 0);
	fields[10] = new_field(1, 10,6, 0, 0, 0);
	fields[11] = new_field(1, 40, 6, 15, 0, 0);
	fields[12] = new_field(1, 10, 7, 0, 0, 0);
	fields[13] = new_field(1, 40, 7, 15, 0, 0);
	fields[14] = new_field(1, 10, 8, 0, 0, 0);
	fields[15] = new_field(1, 40, 8, 15, 0, 0);
	fields[16] = NULL;
    
    wattron(pw2->w[pw2->wi],COLOR_PAIR(1));
	set_field_buffer(fields[0], 0, "Titulo");
	set_field_buffer(fields[1], 0, "titulo");
	
	set_field_buffer(fields[2], 0, "Autor");
	set_field_buffer(fields[3], 0, "autor");

	set_field_buffer(fields[4], 0, "Ano");
	set_field_buffer(fields[5], 0, "ano");
	
	set_field_buffer(fields[6], 0, "Editora");
	set_field_buffer(fields[7], 0, "editora");

	set_field_buffer(fields[8], 0, "Local");
	set_field_buffer(fields[9], 0, "local");

	set_field_buffer(fields[10], 0, "Edicao");
	set_field_buffer(fields[11], 0, "edicaoo");
	
	set_field_buffer(fields[12], 0, "ISBN");
	set_field_buffer(fields[13], 0, "isbn");

	set_field_buffer(fields[14], 0, "Quant.");
	set_field_buffer(fields[15], 0, "quantidade");
	
    set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[1], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
	set_field_opts(fields[2], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[3], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

	set_field_opts(fields[4], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[5], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
	set_field_opts(fields[6], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[7], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

	set_field_opts(fields[8], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[9], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
	set_field_opts(fields[10], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[11], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
	
	set_field_opts(fields[12], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[13], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
	
    set_field_opts(fields[14], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[15], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

	set_field_back(fields[1], A_UNDERLINE);
	set_field_back(fields[3], A_UNDERLINE);
	set_field_back(fields[5], A_UNDERLINE);
	set_field_back(fields[7], A_UNDERLINE);
	set_field_back(fields[9], A_UNDERLINE);
	set_field_back(fields[11], A_UNDERLINE);
	set_field_back(fields[13], A_UNDERLINE);
	set_field_back(fields[15], A_UNDERLINE);

	form = new_form(fields);
	assert(form != NULL);
	set_form_win(form, pw2->w[pw2->wi]);
	set_form_sub(form, derwin(pw2->w[pw2->wi], 9, 56, 5, 1)); //controla altura e largura da subjanela
	post_form(form);

	refresh();
	wrefresh(pw2->w[pw2->wi]);

	while ((ch = getch()) != KEY_F(8))
		driver(ch, pw2, fields, form, pw);

	unpost_form(form);
	free_form(form);
	free_field(fields[0]);
	free_field(fields[1]);
	free_field(fields[2]);
	free_field(fields[3]);
	free_field(fields[4]);
	free_field(fields[5]);
	free_field(fields[6]);
	free_field(fields[7]);
	free_field(fields[8]);
	free_field(fields[9]);
	free_field(fields[10]);
	free_field(fields[11]);
	free_field(fields[12]);
	free_field(fields[13]);
	free_field(fields[14]);
	free_field(fields[15]);
    
	
	delwin(pw2->w[pw2->wi]);
}

void printFormLoan(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw)
{
	int ch;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	fields[0] = new_field(1, 10, 1, 0, 0, 0);
	fields[1] = new_field(1, 40, 1, 15, 0, 0);
	fields[2] = new_field(1, 10, 2, 0, 0, 0);
	fields[3] = new_field(1, 40, 2, 15, 0, 0);

	fields[4] = NULL;
    wattron(pw2->w[pw2->wi],COLOR_PAIR(1));
	set_field_buffer(fields[0], 0, "Cod do Cliente");
	set_field_buffer(fields[1], 0, "cod");

	set_field_buffer(fields[2], 0, "Cod do Livro");
	set_field_buffer(fields[3], 0, "cod");

	set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[1], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
	set_field_opts(fields[2], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[3], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

	set_field_back(fields[1], A_UNDERLINE);
	set_field_back(fields[3], A_UNDERLINE);
	form = new_form(fields);
	assert(form != NULL);
	set_form_win(form, pw2->w[pw2->wi]);
	set_form_sub(form, derwin(pw2->w[pw2->wi], 8, 56, 5, 1)); //controla altura e largura da subjanela
	post_form(form);

	refresh();
	wrefresh(pw2->w[pw2->wi]);

	while ((ch = getch()) != KEY_F(8))
		driver(ch, pw2, fields, form, pw);

	unpost_form(form);
	free_form(form);
	free_field(fields[0]);
	free_field(fields[1]);
	free_field(fields[2]);
	free_field(fields[3]);
	free_field(fields[4]);
	delwin(pw2->w[pw2->wi]);
}

void printFormRegClient(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw)
{
	int ch;

	assert(pw2->w[pw2->wi] != NULL);
	
	fields[0] = new_field(1, 10, 1, 0, 0, 0);
	fields[1] = new_field(1, 40, 1, 15, 0, 0);
	fields[2] = new_field(1, 10, 2, 0, 0, 0);
	fields[3] = new_field(1, 40, 2, 15, 0, 0);

	fields[4] = new_field(1, 10, 3, 0, 0, 0);
	fields[5] = new_field(1, 40, 3, 15, 0, 0);
	fields[6] = new_field(1, 10, 4, 0, 0, 0);
	fields[7] = new_field(1, 40, 4, 15, 0, 0);
	fields[8] = NULL;

	set_field_buffer(fields[0], 0, "Nome");
	set_field_buffer(fields[1], 0, "nome");
	
	set_field_buffer(fields[2], 0, "Telefone");
	set_field_buffer(fields[3], 0, "telefone");

	set_field_buffer(fields[4], 0, "Email");
	set_field_buffer(fields[5], 0, "email");
	
	set_field_buffer(fields[6], 0, "Aniversario");
	set_field_buffer(fields[7], 0, "aniversario");

	set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[1], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
	set_field_opts(fields[2], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[3], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

	set_field_opts(fields[4], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[5], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
	set_field_opts(fields[6], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
	set_field_opts(fields[7], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

	set_field_back(fields[1], A_UNDERLINE);
	set_field_back(fields[3], A_UNDERLINE);
	set_field_back(fields[5], A_UNDERLINE);
	set_field_back(fields[7], A_UNDERLINE);

	form = new_form(fields);
	assert(form != NULL);
	set_form_win(form, pw2->w[pw2->wi]);
	set_form_sub(form, derwin(pw2->w[pw2->wi], 5, 56, 5, 1)); //controla altura e largura da subjanela
	post_form(form);

	refresh();
	wrefresh(pw2->w[pw2->wi]);

	while ((ch = getch()) != KEY_F(8))
		driver(ch, pw2, fields, form, pw);

	unpost_form(form);
	free_form(form);
	free_field(fields[0]);
	free_field(fields[1]);
	free_field(fields[2]);
	free_field(fields[3]);
	free_field(fields[4]);
	free_field(fields[5]);
	free_field(fields[6]);
	free_field(fields[7]);
	
	delwin(pw2->w[pw2->wi]);
}

void printFormSearch(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw)
{
	int ch,xMAX=0,yMAX=0;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr,yMAX, xMAX);

	fields[0] = new_field(1, 30, 0, 0, 0, 0);
	fields[1] = NULL;

	set_field_buffer(fields[0], 0, "Pesquisar...");

	set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

	set_field_back(fields[0], A_BOLD);

	form = new_form(fields);
	assert(form != NULL);
	set_form_win(form, pw2->w[pw2->wi]);
	set_form_sub(form, derwin(pw2->w[pw2->wi], 1, 30, yMAX/3, (xMAX-((xMAX/2)+20)))); //controla altura e largura da subjanela
	post_form(form);

	refresh();
	wrefresh(pw2->w[pw2->wi]);

	while ((ch = getch()) != KEY_F(8))
		driver(ch, pw2, fields, form,pw);

	unpost_form(form);
	free_form(form);
	free_field(fields[0]);

	delwin(pw2->w[pw2->wi]);
}

void printFormLine(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw)
{
	int ch,xMAX=0,yMAX=0;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr,yMAX, xMAX);

	fields[0] = new_field(1, 3, 0, 0, 0, 0);
	fields[1] = NULL;
    /*comentario para marcar*/
	set_field_buffer(fields[0], 0, "1");
    
	set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

	set_field_back(fields[0], A_BOLD);

	form = new_form(fields);
	assert(form != NULL);
	set_form_win(form, pw2->w[pw2->wi]);
	set_form_sub(form, derwin(pw2->w[pw2->wi], 1, 3, (yMAX/2)+5, (xMAX-((xMAX/2)+3)))); //controla altura e largura da subjanela
	post_form(form);

	refresh();
	wrefresh(pw2->w[pw2->wi]);
    
	while ((ch = getch()) != KEY_F(8))
		driver(ch, pw2, fields, form,pw);

	unpost_form(form);
	free_form(form);
	free_field(fields[0]);
	
	delwin(pw2->w[pw2->wi]);
}

void printFormLine2(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw, char *string)
{

	int ch,xMAX=0,yMAX=0;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr,yMAX, xMAX);
	fields[0] = new_field(1, 125, 0, 0, 0, 0);
	fields[1] = NULL;

	set_field_buffer(fields[0], 0, string);

	set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

	set_field_back(fields[0], A_UNDERLINE);

	form = new_form(fields);
	assert(form != NULL);
	set_form_win(form, pw2->w[pw2->wi]);
	set_form_sub(form, derwin(pw2->w[pw2->wi], 1, 125, (yMAX/4)+5, (xMAX-((xMAX-1))))); //controla altura e largura da subjanela
	post_form(form);

	refresh();
	wrefresh(pw2->w[pw2->wi]);
    
	while ((ch = getch()) != KEY_F(8))
		driver(ch, pw2, fields, form,pw);

	unpost_form(form);
	free_form(form);
	free_field(fields[0]);
	
	delwin(pw2->w[pw2->wi]);
	endwin();
}

static void driver(int ch, wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw)
{
	int i;
    list *b = NULL;
    list *a = NULL;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int xMAX, yMAX; 
    getmaxyx(stdscr,yMAX,xMAX);
	switch (ch) 
    {
		case KEY_F(3):
			form_driver(form, REQ_NEXT_FIELD);
			form_driver(form, REQ_PREV_FIELD);
            if(pw2->wi == 0)
            {
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-22),xMAX-(xMAX-1),"INFORMACOES SALVAS!!!");
    			move(LINES-3, 2);

                str.buffer="";
                FILE *livros;
                char *concatenado=NULL, *aux=NULL;
                aux = (char*)calloc(10,sizeof(char));
                
                pw->titulo = trim_whitespaces(field_buffer(fields[1], 0));
                pw->autor = trim_whitespaces(field_buffer(fields[3], 0));
                pw->ano = trim_whitespaces(field_buffer(fields[5], 0));
                pw->editora = trim_whitespaces(field_buffer(fields[7], 0));
                pw->local = trim_whitespaces(field_buffer(fields[9], 0));
                pw->ed = trim_whitespaces(field_buffer(fields[11], 0));
                pw->isbn = trim_whitespaces(field_buffer(fields[13], 0));
                pw->quant = trim_whitespaces(field_buffer(fields[15],0));

                pw->cod = findFileLine();

                aux = itoa(pw->cod, aux,10);

                str.buffer = concatenate(concatenado,str, aux);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->titulo);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->autor);
                str.buffer = concatenate(concatenado,str, ";");

                str.buffer = concatenate(concatenado,str, pw->ano);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->editora);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->local);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->ed);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->isbn);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str,pw->quant);
                str.buffer = concatenate(concatenado,str, "\n");

                wattroff(pw2->w[pw2->wi], A_REVERSE);
                mvwprintw(pw2->w[pw2->wi],(yMAX-(yMAX-22)),(xMAX-(xMAX-34)),"@BOOK{%s%s,",pw->autor,pw->ano);
                mvwprintw(pw2->w[pw2->wi],(yMAX-(yMAX-23)),(xMAX-(xMAX-34)),"  title     = \"%s\"" ,pw->titulo); 
                mvwprintw(pw2->w[pw2->wi],(yMAX-(yMAX-24)),(xMAX-(xMAX-34)),"  author    = \"%s\" ",pw->autor);
                mvwprintw(pw2->w[pw2->wi],(yMAX-(yMAX-25)),(xMAX-(xMAX-34)),"  publisher = \"%s\" ",pw->editora);
                mvwprintw(pw2->w[pw2->wi],(yMAX-(yMAX-26)),(xMAX-(xMAX-34)),"  address   = \"%s\"",pw->local);
                mvwprintw(pw2->w[pw2->wi],(yMAX-(yMAX-27)),(xMAX-(xMAX-34)),"  edition   = \"%s\"",pw->ed);
                mvwprintw(pw2->w[pw2->wi],(yMAX-(yMAX-28)),(xMAX-(xMAX-34)),"  year      = \"%s\"",pw->ano);
                mvwprintw(pw2->w[pw2->wi],(yMAX-(yMAX-29)),(xMAX-(xMAX-34)),"}");
                wattroff(pw2->w[pw2->wi], A_REVERSE); 

                livros = fopen("livros.txt", "r+");
                fseek(livros, 0, SEEK_END);
                fputs(str.buffer,livros);

                fclose(livros);
                free(str.buffer);
                free(aux);

			    refresh();
			    pos_form_cursor(form);
            }
            if(pw2->wi==2)
            {
                str.buffer="";
                char *concatenado = NULL;
                
                pw->hold = trim_whitespaces(field_buffer(fields[0],0));
                str.buffer = concatenate(concatenado,str, pw->hold);
                str.buffer = concatenate(concatenado,str, "\n");
                insertLine("livros.txt",str.buffer,num); 
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-9),xMAX-(xMAX-1),"ALTERACOES SALVAS:");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-10),xMAX-(xMAX-1),"%s",str.buffer);
                free(str.buffer);
            }
            if(pw2->wi==6)
            {
                str.buffer="";
                char *concatenado = NULL;
                
                pw->hold = trim_whitespaces(field_buffer(fields[0],0));
                str.buffer = concatenate(concatenado,str, pw->hold);
                str.buffer = concatenate(concatenado,str, "\n");
                insertLine("clientes.txt",str.buffer,num); 
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-9),xMAX-(xMAX-1),"ALTERACOES SALVAS:");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-10),xMAX-(xMAX-1),"%s",str.buffer);
                free(str.buffer);
            }
            if(pw2->wi == 4)
            {
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-22),xMAX-(xMAX-1),"INFORMACOES SALVAS");
    			move(LINES-3, 2);

	    		for (i = 0; fields[i]; i++) 
                {
    				printw("%s", trim_whitespaces(field_buffer(fields[i], 0)));
    
    				if (field_opts(fields[i]) & O_ACTIVE)
    					printw("\"\t");
    				else
    					printw(": \"");
    			}
                
                str.buffer="";
                FILE *livros;
                char *concatenado=NULL, *aux=NULL;
                aux = (char*)calloc(10,sizeof(char));
                
                pw->codClient = findFileLine();
                pw->nome = trim_whitespaces(field_buffer(fields[1], 0));
                pw->telefone = trim_whitespaces(field_buffer(fields[3], 0));
                pw->email = trim_whitespaces(field_buffer(fields[5], 0));
                pw->aniversario = trim_whitespaces(field_buffer(fields[7], 0));

                aux = itoa(pw->codClient, aux,10);

                str.buffer = concatenate(concatenado,str, aux);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->nome);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->telefone);
                str.buffer = concatenate(concatenado,str, ";");

                str.buffer = concatenate(concatenado,str, pw->email);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->aniversario);
                str.buffer = concatenate(concatenado,str, "\n");

                livros = fopen("clientes.txt", "r+");
                fseek(livros, 0, SEEK_END);
                fputs(str.buffer,livros);

                fclose(livros);
                free(str.buffer);
                free(aux);

			    refresh();
			    pos_form_cursor(form);
            }
            if(pw2->wi==8)
            { 
                form_driver(form, REQ_NEXT_FIELD);
    			form_driver(form, REQ_PREV_FIELD);
                int flag1 =0;
                int flag2 =0;


                flag1 = search_client_cod(atoi(trim_whitespaces(field_buffer(fields[3],0))),"livros.txt"); 
                flag2 = search_client_cod(atoi(trim_whitespaces(field_buffer(fields[3],0))),"livros.txt");
                
                if((search_client_cod(atoi(trim_whitespaces(field_buffer(fields[1],0))),"emprestou.txt")>0)&&flag1==1)
                {  
                    char keep2[100];
                    char* keep = get_line(atoi(trim_whitespaces(field_buffer(fields[1],0))),"emprestou.txt");
                    char vtr1[100],vtr2[100];
                    strcpy(vtr1,keep);
                    strcpy(vtr2,trim_whitespaces(field_buffer(fields[3],0)));
                    vtr1[strlen(vtr1)-1] = '\0';
                    strcat(vtr1,";");
                     
                    strcat(vtr1,vtr2);
                    strcat(vtr1,";");
                    sprintf(keep2,"%d",tm.tm_year+1900);
                    strcat(vtr1,keep2);
                    if((tm.tm_mon+1)<10)
                        strcat(vtr1,"0");
                    sprintf(keep2,"%d",tm.tm_mon+1);
                    strcat(vtr1,keep2);
                    sprintf(keep2,"%d",tm.tm_mday);
                    strcat(vtr1,keep2);
                    strcat(vtr1,"\n");  /*comecando a editar */
                    char *number = (char*)calloc(10,sizeof(char));
                    number = change_amount(atoi(trim_whitespaces(field_buffer(fields[3],0))),number,'-');
                    if(number == NULL)
                    {
                        mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-10),xMAX-(xMAX-1),"SEM LIVROS NO ESTOQUE!!!");
                        break;
                    }
                    insert_new_amount(atoi(trim_whitespaces(field_buffer(fields[3],0))),number);
                    add(&b,vtr1);
                    print(b,pw2);
                    insertLine("emprestou.txt",vtr1,atoi(trim_whitespaces(field_buffer(fields[1],0))));
                    /* --------------------- EMPRESTADO ------------------------------------*/

                    if(search_client_cod(atoi(trim_whitespaces(field_buffer(fields[3],0))),"emprestado.txt"))
                    {
                        char* keep4 = get_line(atoi(trim_whitespaces(field_buffer(fields[3],0))),"emprestado.txt"); 
                        char vtr3[100],vtr4[100];
                        strcpy(vtr3,keep4);
                        strcpy(vtr4,trim_whitespaces(field_buffer(fields[1],0))); 
                        vtr3[strlen(vtr3)-1] = '\0';
                        strcat(vtr3,";");
                        strcat(vtr3,vtr4);
                        strcat(vtr3,"\n");

                        insertLine("emprestado.txt",vtr3,atoi(trim_whitespaces(field_buffer(fields[3],0))));
                        mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-10),xMAX-(xMAX-1),"Livro emprestado! Arquivo: %s",vtr3);
                    }
                }
                else if((search_client_cod(atoi(trim_whitespaces(field_buffer(fields[1],0))),"clientes.txt")>0)&& flag2==1)
                {
                    char vtr1[100];
                    char keep2[100];
                    strcpy(vtr1,trim_whitespaces(field_buffer(fields[1],0)));
                    strcat(vtr1,";");
                    strcat(vtr1,trim_whitespaces(field_buffer(fields[3],0)));
                    strcat(vtr1,";");
                    sprintf(keep2,"%d",tm.tm_year+1900);
                    strcat(vtr1,keep2);
                    if((tm.tm_mon+1)<10)
                        strcat(vtr1,"0");
                    sprintf(keep2,"%d",tm.tm_mon+1);
                    strcat(vtr1,keep2);
                    sprintf(keep2,"%d",tm.tm_mday);
                    strcat(vtr1,keep2);
                    
                    char *number = (char*)calloc(10,sizeof(char));
                    number = change_amount(atoi(trim_whitespaces(field_buffer(fields[3],0))),number,'-');
                    if(number == NULL)
                    {
                        mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-10),xMAX-(xMAX-1),"SEM LIVROS NO ESTOQUE!!!");
                        break;
                    }
                    insert_new_amount(atoi(trim_whitespaces(field_buffer(fields[3],0))),number);

                    char vtr3[100],vtr4[100];
                    char *keep4 = NULL;
                    if(search_client_cod(atoi(trim_whitespaces(field_buffer(fields[3],0))),"emprestado.txt")>0)
                    { 
                        keep4 = get_line(atoi(trim_whitespaces(field_buffer(fields[3],0))),"emprestado.txt"); 
                        strcpy(vtr3,keep4);
                        strcpy(vtr4,trim_whitespaces(field_buffer(fields[1],0))); 
                        vtr3[strlen(vtr3)-1] = '\0';
                        strcat(vtr3,";");
                        strcat(vtr3,vtr4);
                        strcat(vtr3,"\n");
                        insertLine("emprestado.txt",vtr3,atoi(trim_whitespaces(field_buffer(fields[3],0))));
                        mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-10),xMAX-(xMAX-1),"Livro emprestado! Arquivo: %s",vtr3);

                    }
                    else
                    {
                        strcpy(vtr3,trim_whitespaces(field_buffer(fields[3],0)));
                        strcpy(vtr4,trim_whitespaces(field_buffer(fields[1],0))); 
                        strcat(vtr3,";");
                        strcat(vtr3,vtr4);
                        FILE *file2;
                        file2 = fopen("emprestado.txt","r+");
                        fseek(file2,0,SEEK_END);
                        fprintf(file2,"%s\n",vtr3);
                        fclose(file2);
                    }
                    add(&a,vtr3);
                    print(a,pw2);    
                    FILE *file; 
                    file = fopen("emprestou.txt","r+");
                    fseek(file, 0, SEEK_END);
                    fprintf(file,"%s\n",vtr1);
                    fclose(file);
                    mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-11),xMAX-(xMAX-1),"INFORMACOES SALVAS");
                }
            }
            break;
        case 10:
            
            if(pw2->wi == 1)
            {
                form_driver(form, REQ_NEXT_FIELD);
    			form_driver(form, REQ_PREV_FIELD);
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-22),xMAX-(xMAX-1),"                                                                                                                                      ");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-23),xMAX-(xMAX-1),"                                                                                                                                      ");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-24),xMAX-(xMAX-1),"                                                                                                                                      ");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-25),xMAX-(xMAX-1),"                                                                                                                                      ");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-26),xMAX-(xMAX-1),"                                                                                                                                      ");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-27),xMAX-(xMAX-1),"                                                                                                                                      ");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-28),xMAX-(xMAX-1),"                                                                                                                                      ");
                char* ptr = (char*)calloc(210,sizeof(char));
                search4(pw2,"livros.txt", trim_whitespaces(field_buffer(fields[0], 0)),ptr);
                box(pw2->w[pw2->wi],0,0);
                refresh();
                wrefresh(pw2->w[pw2->wi]);
                free(ptr);
            }
            if(pw2->wi==2)
            {
                form_driver(form, REQ_NEXT_FIELD);
    			form_driver(form, REQ_PREV_FIELD);
                num = atoi(field_buffer(fields[0],0));
                pw->hold = get_line(num,"livros.txt");
            }
            if(pw2->wi == 5)
            {
                form_driver(form, REQ_NEXT_FIELD);
    			form_driver(form, REQ_PREV_FIELD);
            
                int yMAX,xMAX;
                getmaxyx(stdscr,yMAX,xMAX);
                
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-22),xMAX-(xMAX-1),"                                                                                                                                      ");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-23),xMAX-(xMAX-1),"                                                                                                                                      ");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-24),xMAX-(xMAX-1),"                                                                                                                                      ");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-25),xMAX-(xMAX-1),"                                                                                                                                      ");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-26),xMAX-(xMAX-1),"                                                                                                                                      ");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-27),xMAX-(xMAX-1),"                                                                                                                                      ");
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-28),xMAX-(xMAX-1),"                                                                                                                                      ");
                char* ptr = (char*)calloc(210,sizeof(char));
                
                search4(pw2,"clientes.txt", trim_whitespaces(field_buffer(fields[0], 0)),ptr);
                
                box(pw2->w[pw2->wi],0,0);
                
                refresh();
                wrefresh(pw2->w[pw2->wi]);
                
                free(ptr);
            }
            if(pw2->wi==6)
            {
                form_driver(form, REQ_NEXT_FIELD);
    			form_driver(form, REQ_PREV_FIELD);
                num = atoi(field_buffer(fields[0],0));
                pw->hold = get_line(num,"clientes.txt");
            } 
            break;

		case KEY_DOWN:
			form_driver(form, REQ_NEXT_FIELD);
			form_driver(form, REQ_END_LINE);
			break;

		case KEY_UP:
			form_driver(form, REQ_PREV_FIELD);
			form_driver(form, REQ_END_LINE);
			break;

		case KEY_LEFT:
			form_driver(form, REQ_PREV_CHAR);
			break;

		case KEY_RIGHT:
			form_driver(form, REQ_NEXT_CHAR);
			break;

		// Delete the char before cursor
		case 8:
		case 127:
        case KEY_BACKSPACE:
			form_driver(form, REQ_DEL_PREV);
			break;

		// Delete the char under the cursor
		case KEY_DC:
			form_driver(form, REQ_DEL_CHAR);
			break;

		default:
			form_driver(form, ch);
			break;
	}

	wrefresh(pw2->w[pw2->wi]);
}

char *change_amount(int line,char *number,char ch)
{
    int cc =0;
    char c =' ';
    FILE *file;
    int count =0;
    int symbol_count = 0;
    char next_ch= ' ';
    int count2 =0;
    int value =0;
    file = fopen("livros.txt","r+");
    
    if(line == -1)
        line++;
    else
        line--;

    if(file == NULL)
    {
        exit(0);
    }
    if(file)
    {
        c=fgetc(file);
        while(c != EOF)
        {
            if(c == ';')
            {
                symbol_count++;
            }
            if(c == '\n')
            {
                count++;
                symbol_count = 0;
            }
            if(count == line)
            {
                if(symbol_count == 8)
                {   
                    next_ch = fgetc(file);
                    while(next_ch !='\n')
                    {
                        number[count2] = next_ch;
                        count2++;
                        next_ch= fgetc(file);
                    }
                    value = atoi(number);
                    if(ch == '+')
                        value++;
                    else if(ch== '-')
                    {
                        if(value == 0)
                            return NULL;

                        value--;
                    }
                    sprintf(number,"%d", value);
                    return number;

                    break;
                }
            }
            c=fgetc(file);
            cc++;
        }
    }
    return NULL;
}

int search_client_cod(int client_cod,char *txt)
{
    char c =' ';
    int count =0;
    FILE *file;
    file = fopen(txt,"r");

    c = fgetc(file);
    if(c == client_cod+48)
    {
        return 1;
    }
    while(c != EOF)
    {
        if(c == '\n')
        {   
            count++;
            c=fgetc(file);
            if(c == client_cod+48)
                return 1;
            else
                continue;
        }
        
        c = fgetc(file);
    }
    return 0;
}

void add(list **head,char* num)
{
    list *pl = *head;
    list *plant = NULL;
    while(pl!=NULL)
    {
        plant=pl;
        pl=pl->prox;
    }
    pl = malloc(sizeof(list));
    pl->data=num;
    pl->prox=NULL;
    if(plant!=NULL)
        plant->prox=pl;
    else
        *head = pl;
}

void search4(wins_t *pw, char *txt, char *str,char *ptr)
{
    FILE *arquivo;
    arquivo = fopen(txt,"r");
    
    int c =0, xMAX=0, yMAX=0; 
    int line = 1;

    getmaxyx(stdscr,yMAX,xMAX);

    char stringSearched[200];
    char stringChanged[200];                                    
    while(fgets(stringSearched,200,arquivo)!=NULL)
    {
        if(strstr(stringSearched,str)!=NULL)
        {
            strcpy(stringChanged,stringSearched);

                mvwprintw(pw->w[pw->wi],yMAX-(yMAX-22-c),xMAX-(xMAX-1),"[%i] %s",line, stringChanged);
                c++;
        }
        line++;

    }
    strcpy(ptr,stringChanged);
    fclose(arquivo);
    
}

char *get_line(int line,char *txt)
{
    FILE *file;
    file = fopen(txt,"r");
    
    char *line_wanted = (char*)calloc(256,sizeof(char));
    
    if(file == NULL)
        exit(0);
    if(line <= 0)
        line = 0;
    if(line > 0)
        line--;

    int count_line = 0;
    char c =' ';

    while(c != EOF)
    {
        if(c == '\n')
        {  
            count_line++;
        }
        if(count_line == line)
        {
            fgets(line_wanted,256,file);
            return line_wanted;
        }
        c=fgetc(file);
    }
    return NULL;
}

void print(list *head,wins_t *pw)
{
    int i =0;
    int xMAX,yMAX;
    getmaxyx(stdscr,yMAX,xMAX);
    list *pl = head;
    while(pl!=NULL)
    {
        mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-10))+i,(xMAX-(xMAX-1)),"%s",pl->data);
        printf("%s", pl->data);
        pl=pl->prox;
        i++;
    }
}

void insertLine(char *path, char *str, int line)
{
    FILE * fPtr;
    FILE * fTemp;
    
    char buffer[BUFFER_SIZE];
    int count;

    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    if (fPtr == NULL || fTemp == NULL)
    {
        //Unable to open file hence exit 
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }

    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;

         //If current line is line to replace 
        if (count == line)
            fputs(str, fTemp);
        else
            fputs(buffer, fTemp);
    }


    //Close all files to release resource 
    fclose(fPtr);
    fclose(fTemp);


    //Delete original source file 
    remove(path);

     //Rename temporary file as original file
    rename("replace.tmp", path);
}

void show2(wins_t *pw,char *string)
{
    int yMAX,xMAX;
    getmaxyx(stdscr,yMAX,xMAX);
    int col =0;
    int lin =0;
    int c =0;
    FILE *file;
    file = fopen(string,"r");

    if(file == NULL)
    {
        exit(0);
    }
    
    if(file)
    {
        c = fgetc(file);
        while(c!=EOF)
        {
            if(lin == 0)
                mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-19)),(xMAX-(xMAX-1))+col,"%c",c);
            else 
                mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-19))+lin,(xMAX-(xMAX))+col,"%c",c);
            c = fgetc(file);
            if(c == '\n')
            {  
                col = 0;
                lin++;
            }
            else
                col++;
        }
        
    }

    box(pw->w[pw->wi],0,0);
    refresh();
    wrefresh(pw->w[pw->wi]);
    fclose(file);
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

void rectangle(wins_t *pw, int y1, int x1, int y2, int x2)
{
    mvwhline(pw->w[pw->wi],y1, x1, 0, x2-x1);
    mvwhline(pw->w[pw->wi],y1+2, x1, 0, x2-x1);
    mvwhline(pw->w[pw->wi],y2, x1, 0, x2-x1);
    mvwvline(pw->w[pw->wi],y1, x1, 0, y2-y1);
    mvwvline(pw->w[pw->wi],y1, x2, 0, y2-y1);
    mvwaddch(pw->w[pw->wi],y1, x1, ACS_ULCORNER);
    mvwaddch(pw->w[pw->wi],y2, x1, ACS_LLCORNER);
    mvwaddch(pw->w[pw->wi],y1, x2, ACS_URCORNER);
    mvwaddch(pw->w[pw->wi],y2, x2, ACS_LRCORNER);
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

int findFileLine()
{
	FILE *livros;
    int count_lines = 0;
    char chr;

    livros = fopen("livros.txt", "r");

    chr = getc(livros);
    while (chr != EOF)
    {
        if (chr == '\n')
        {
            count_lines++;
        }
        chr = getc(livros);
    }
    fclose(livros);
    return count_lines+1;
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

void insert_new_amount(int line,char *new_amount)
{
    if(new_amount == NULL)
        return;

    FILE *file;
    file = fopen("livros.txt","r+");
     
    if(line == -1)
        line++;
    else
        line--;
    
    int count =0;

    int cc =0;
    int cc2 =0;
    int symbol_count =0;
    char c = ' ';

    if(file == NULL)
        exit(0);
    c = fgetc(file);
    while(c != EOF)
    {
        if(c == ';')
        {
            symbol_count++;
        }
        else if(c == '\n')
        {
            count++;
            symbol_count = 0;
        }
        else if(count==line)
        {
            if(symbol_count == 8)
            {
                cc2=cc;
                printf("Sofreu atribuicao: ");
                printf("%i ",cc2);
            }
        }
        if(symbol_count == 8 && count == line)
        {
            printf("Chegou aqui agora: ");
            fputs(new_amount,file);
        }
        c=fgetc(file);
        cc++;
    }
}

char* trim(char * str)
{
    int flag=0, n=strlen(str)-1;
    char *end= (char*)calloc(100, sizeof(char));
	while(isspace(*str))
    {
		str++;
        n--;
    }

	if(*str == 0) // all spaces?
		return str;

    for(int i=n;str[i];i--)
    {
        flag++;
        if(str[i] !=' ')
        {
            strncat(end, str,n-flag+2);
            break;
        }
    }
	return end;
}

void deleteLine(char *fname)
{
        int xMAX,yMAX;
        int key = 0;
        getmaxyx(stdscr,yMAX,xMAX);
        move(((yMAX/2)-1)+6,((xMAX/2)-2));
        int line =0; 
        int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;
        char str[256], temp[] = "temp.txt";
        echo();
        
        while(1)
        {
            if((line = getch())==ERR)
                continue;
            else
            {
                if((key=getch())==ERR)
                    continue;
                else
                    break;
            }
            if(key==10)
               break; 
        }    
        line = line-48;

        fptr1 = fopen(fname, "r");
        if(!fptr1) 
		{
                return;
        }
        
        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
        if(!fptr2) 
		{
                fclose(fptr1);
                return;
        }
        lno = line;
        
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, 256, fptr1);
            if (!feof(fptr1)) 
            {
                ctr++;                
                if (ctr != lno) 
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);  		 
        rename(temp, fname); 	
        fptr1=fopen(fname,"r"); 
        ch=fgetc(fptr1); 
        
        while(ch!=EOF) 
        { 
            ch=fgetc(fptr1); 
        }
        noecho();
}

static char*trim_whitespaces(char *str)
{
	char *end;

	// trim leading space
	while(isspace(*str))
		str++;

	if(*str == 0) // all spaces?
		return str;

	// trim trailing space
	end = str + strnlen(str, 128) - 1;

	while(end > str && isspace(*end))
		end--;

	// write new null terminator
	*(end+1) = '\0';

	return str;
}

void show(wins_t *pw,char *string)
{
    int yMAX,xMAX;
    getmaxyx(stdscr,yMAX,xMAX);
    int col =0;
    int lin =0;
    int c =0;
    FILE *file;
    file = fopen(string,"r");

    if(file == NULL)
    {
        exit(0);
    }

    if(file)
    {
        c = fgetc(file);
        while(c!=EOF)
        {
            if(lin == 0)
                mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-25)),(xMAX-(xMAX-1))+col,"%c",c);
            else
                mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-25))+lin,(xMAX-(xMAX))+col,"%c",c);
            c = fgetc(file);
            if(c == '\n')
            {
                col = 0;
                lin++;
            }
            else
                col++;
        }

    }

    box(pw->w[pw->wi],0,0);
    refresh();
    wrefresh(pw->w[pw->wi]);
    fclose(file);
}

/* ------------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline    */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20180716.101436   */


