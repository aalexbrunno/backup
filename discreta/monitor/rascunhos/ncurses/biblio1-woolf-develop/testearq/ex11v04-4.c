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

#include "ex11v04-4.h" /* To be created for this template if needed */
#include <assert.h>
#include <form.h>
#include <ctype.h>
file_entry str;
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
void printForm(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw);
void printForm2(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw,char **string);
void printFormRegClient(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw);
void show(wins_t *pw ,char *string);
void deleteLine(char *fname);
char* trim(char * str);
char *get_line(int line,char *txt);
char* search4(wins_t *pw,char *txt, char *str);
char* edit_waiter(wins_t *pw, char *txt, char *hold);
char** split(char* string);

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

static void driver(int ch, wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw)
{
	int i;
    int xMAX, yMAX; 
    getmaxyx(stdscr,yMAX,xMAX);
	switch (ch) 
    {
        case KEY_F(2):
			// Or the current field buffer won't be sync with what is displayed
			form_driver(form, REQ_NEXT_FIELD);
			form_driver(form, REQ_PREV_FIELD);
			// move(LINES-3, 2);

			for (i = 0; fields[i]; i++) {
				printw("%s", trim_whitespaces(field_buffer(fields[i], 0)));

				if (field_opts(fields[i]) & O_ACTIVE)
					printw("\"\t");
				else
					printw(": \"");
			}

			refresh();
			pos_form_cursor(form);
			break;
		case KEY_F(3):
            // if(win_body !=0)
            //     break;
			form_driver(form, REQ_NEXT_FIELD);
			form_driver(form, REQ_PREV_FIELD);
            if(pw2->wi == 0)
            {
                mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-22),xMAX-(xMAX-1),"INFORMACOES SALVAS!!!");
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
                
                pw->titulo = trim_whitespaces(field_buffer(fields[1], 0));
                pw->autor = trim_whitespaces(field_buffer(fields[3], 0));
                pw->ano = trim_whitespaces(field_buffer(fields[5], 0));
                pw->editora = trim_whitespaces(field_buffer(fields[7], 0));
                pw->local = trim_whitespaces(field_buffer(fields[9], 0));
                pw->ed = trim_whitespaces(field_buffer(fields[11], 0));
                pw->isbn = trim_whitespaces(field_buffer(fields[13], 0));
                
                pw->cod = findFileLine();

                aux = itoa(pw->cod, aux,10);

                str.buffer = concatenate(concatenado,str, aux);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->titulo);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->autor);
                str.buffer = concatenate(concatenado,str, ";");

            //aux = itoa(l->ano, aux,10);
                str.buffer = concatenate(concatenado,str, pw->ano);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->editora);
                str.buffer = concatenate(concatenado,str, ";");
                str.buffer = concatenate(concatenado,str, pw->local);
                str.buffer = concatenate(concatenado,str, ";");
            //aux = itoa(l->ed, aux,10);
                str.buffer = concatenate(concatenado,str, pw->ed);
                str.buffer = concatenate(concatenado,str, ";");
            //aux = itoa(l->isbn, aux,10);
                str.buffer = concatenate(concatenado,str, pw->isbn);
                str.buffer = concatenate(concatenado,str, "\n");

            //mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-24)),(xMAX-(xMAX-34)+i),"LIVRO SALVO!!! %s",str.buffer);
                

                livros = fopen("livros.txt", "r+");
                fseek(livros, 0, SEEK_END);
                fputs(str.buffer,livros);

                fclose(livros);
                free(str.buffer);
                free(aux);

			    refresh();
			    pos_form_cursor(form);
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
            break;
        case 10:
            
            if(pw2->wi == 1)
            {
                form_driver(form, REQ_NEXT_FIELD);
    			form_driver(form, REQ_PREV_FIELD);
            
                // int yMAX,xMAX;
                char* ptr = (char*)calloc(50,sizeof(char));
                // getmaxyx(stdscr,yMAX,xMAX);
            // str.buffer = concatenate(concatenado, str, trim_whitespaces(field_buffer(fields[0], 0)));
            // char *vet=field_buffer(fields[0], 0);

            // strcat(vet,trim_whitespaces(field_buffer(fields[0], 0)));
            // search2(win_body, concatenad);
            // search2(win_body,trim_whitespaces("John"));
            // vet[0] = (char)trim_whitespaces(field_buffer(fields[0], 0));
            //printw("%s", trim_whitespaces(field_buffer(fields[0], 0)));
                ptr = search4(pw2,"livros.txt", trim(field_buffer(fields[0], 0)));
            //mvwprintw(pw2->w[pw2->wi],yMAX-(yMAX-22),xMAX-(xMAX-1),"%s", ptr);
                box(pw2->w[pw2->wi],0,0);
                refresh();
                wrefresh(pw2->w[pw2->wi]);
                free(ptr);
            }
            if(pw2->wi == 5)
            {
                form_driver(form, REQ_NEXT_FIELD);
    			form_driver(form, REQ_PREV_FIELD);
            
                // int yMAX,xMAX;
                char* ptr = (char*)calloc(50,sizeof(char));
                // getmaxyx(stdscr,yMAX,xMAX);
                ptr = search4(pw2,"clientes.txt", trim_whitespaces(field_buffer(fields[0], 0)));
                box(pw2->w[pw2->wi],0,0);
                refresh();
                wrefresh(pw2->w[pw2->wi]);
                free(ptr);
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

void printFormSearch(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw)
{
	int ch,xMAX=0,yMAX=0;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr,yMAX, xMAX);

	// box(win_body, 0, 0);
	
	// mvwprintw(win_body, 1, 2, "Press F1 to quit and F2 to print fields content");
	
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
	endwin();
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

char *hold;
//(char*)calloc(100,sizeof(char));
char** hold2;
//= (char**)calloc(100,sizeof(char*));

int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    int count =0;
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

            if(win.wi==7)
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
                  win.wi=7;
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
                //searchInData(&win);
                printFormSearch(&win,fm.fieldSearch,fm.formSearch,&book);
                wattroff(win.w[win.wi],A_REVERSE); 
                printTemplate(&win);
            }
            if(win.wi==2)
            {
                count++;
                
               /*if(count > 1)
                {
                    hold = (char*) realloc(hold,100);
                    hold2 = (char**) realloc(hold2,200);
                    for(int i = 0; i < 9; i++)
                    {   
                        free(hold2[i]);
                    }   
                    free(hold2);
                    free(hold);
                }*/
                if(count == 1)
                {
                    wattroff(win.w[win.wi],A_REVERSE);
                    //printTemplate(&win);
                    hold = edit_waiter(&win,"livros.txt",hold);
                    hold2 = split(hold); 
                    printForm2(&win,fm.fields,fm.form,&book, hold2);
                    wattroff(win.w[win.wi],A_REVERSE); 
                }
                else
                {
                    int xMAX,yMAX;
                    getmaxyx(stdscr,yMAX,xMAX);
                    wclear(win.w[win.wi]);
                    printTemplate(&win);
                    wattron(win.w[win.wi],A_REVERSE); 
                    mvwprintw(win.w[win.wi],(yMAX-(yMAX-20)),(xMAX/4),"Por favor, reinicie o programa para editar novamente");
                    
                }
                //free(hold2);
                
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
            //if(win.wi==
        }
        napms(50);
    }while(kpress!='q');
    
    /*for(int i = 0; i < 9; i++)
    {   
        free(hold2[i]);
    }
    free(hold2);
    free(hold);*/
    bomb(win, "", 0, NULL);

    return EXIT_SUCCESS;
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
    rectangle(pw,((yMAX/2)-1)+5,(xMAX/2)-3,((yMAX/2)+1)+5,(xMAX/2));
    refresh();
    wrefresh(pw->w[pw->wi]);
    fclose(file);
}

char* trim(char * str)
{
    // printf("antes: %ld\n", strlen(str));
    int flag=0, n=strlen(str)-1;
    char *end= (char*)calloc(100, sizeof(char));
	// trim leading space
	while(isspace(*str))
    {
		str++;
        n--;
    }

	if(*str == 0) // all spaces?
		return str;

    // n--;
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

    // printf("depois: %ld\n", strlen(end));
    // free(end);
    // for(int i=0; *(str+i) !='\0'; i++&&flag++)
}

char* search4(wins_t *pw, char *txt, char *str)
{
    FILE *arquivo;
    arquivo = fopen(txt,"r");
    
    int c =0, xMAX=0, yMAX=0; 
    int line = 1;
    int i =0;

    getmaxyx(stdscr,yMAX,xMAX);

    char stringSearched[200];
    char *stringChanged = (char*)calloc(50,sizeof(char));                                    
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
                
                //mvwprintw(win_body,yMAX-(yMAX-22-c),xMAX-(xMAX-1),"Opaaaaaaaaaa");
                mvwprintw(pw->w[pw->wi],yMAX-(yMAX-22-c),xMAX-(xMAX-1),"[%i] %s",line, stringChanged);
                c++;
        }
        line++;

    }
    return stringChanged;
    // free(stringChanged);
    // fclose(arquivo);
}


void printForm2(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw, char **string)
{
	int ch;
    // ,xMAX=0,yMAX=0;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	// getmaxyx(stdscr,yMAX, xMAX);

	// win_body = newwin(yMAX, xMAX, 0, 0);

	// assert(win_body != NULL);
	// box(win_body, 0, 0);
	
	// mvwprintw(win_body, 1, 2, "Press F1 to quit and F2 to print fields content");
	
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
	fields[14] = NULL;
    
    

    wattron(pw2->w[pw2->wi],COLOR_PAIR(1));
	set_field_buffer(fields[0], 0, "Titulo");
	set_field_buffer(fields[1], 0, string[2]);
	
	set_field_buffer(fields[2], 0, "Autor");
	set_field_buffer(fields[3], 0, string[1]);

	set_field_buffer(fields[4], 0, "Ano");
	set_field_buffer(fields[5], 0, string[5]);
	
	set_field_buffer(fields[6], 0, "Editora");
	set_field_buffer(fields[7], 0, string[3]);

	set_field_buffer(fields[8], 0, "Local");
	set_field_buffer(fields[9], 0, string[4]);

	set_field_buffer(fields[10], 0, "Edicao");
	set_field_buffer(fields[11], 0, string[6]);
	
	set_field_buffer(fields[12], 0, "ISBN");
	set_field_buffer(fields[13], 0, string[7]);

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

	set_field_back(fields[1], A_UNDERLINE);
	set_field_back(fields[3], A_UNDERLINE);
	set_field_back(fields[5], A_UNDERLINE);
	set_field_back(fields[7], A_UNDERLINE);
	set_field_back(fields[9], A_UNDERLINE);
	set_field_back(fields[11], A_UNDERLINE);
	set_field_back(fields[13], A_UNDERLINE);

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
	free_field(fields[5]);
	free_field(fields[6]);
	free_field(fields[7]);
	free_field(fields[8]);
	free_field(fields[9]);
	free_field(fields[10]);
	free_field(fields[11]);
	free_field(fields[12]);
	free_field(fields[13]);
    
    /*free(hold);
        
    for(int i = 0; i < 9; i++)
    {   
        free(hold2[i]);
    }   
    free(hold2);*/

	delwin(pw2->w[pw2->wi]);
}

char** split(char* string)
{
    
    char* index = (char*)malloc(strlen(string) * sizeof(char));
    char* autor = (char*)malloc(strlen(string) * sizeof(char));
    char* titulo = (char*)malloc(strlen(string) * sizeof(char));
    char* editora = (char*)malloc(strlen(string) * sizeof(char));
    char* local = (char*)malloc(strlen(string) * sizeof(char));
    char* ano = (char*)malloc(strlen(string) * sizeof(char));
    char* edicao = (char*)malloc(strlen(string) * sizeof(char));
    char* isbn = (char*)malloc(strlen(string) * sizeof(char));
    char* quantidade = (char*)malloc(strlen(string) * sizeof(char));
    char** resultado = (char**)malloc(strlen(string) * sizeof(char*));
    int count = 0;
    int separatorCount = 0;

    for(int k = 0; k < 9; k++)
    {
        resultado[k] = (char*)malloc(strlen(string) * sizeof(char)); 
    }

    for(int i = 0; i < (int)strlen(string); i++)
    {
        if(string[i] == ';') {
            separatorCount++;
            count = 0;
        }
        else {
            switch(separatorCount)
            {
                case 0:
                    index[count] = string[i];
                    count++;
                    break;
                case 1:
                    autor[count] = string[i];
                    count++;
                    break;
                case 2:
                    titulo[count] = string[i];
                    count++;
                    break;
                case 3:
                    editora[count] = string[i];
                    count++;
                    break;
                case 4:
                    local[count] = string[i];
                    count++;
                    break;
                case 5:
                    ano[count] = string[i];
                    count++;
                    break;
                case 6:
                    edicao[count] = string[i];
                    count++;
                    break;
                case 7:
                    isbn[count] = string[i];
                    count++;
                    break;
                case 8:
                    quantidade[count] = string[i];
                    count++;
                    break;
                default:
                    count = 0;
                    break;
            }
        }
    }

    index[strlen(index) + 1] = '\0';
    autor[strlen(autor) + 1] = '\0';
    titulo[strlen(titulo) + 1] = '\0';
    editora[strlen(editora) + 1] = '\0';
    local[strlen(local) + 1] = '\0';
    ano[strlen(ano) + 1] = '\0';
    edicao[strlen(edicao) + 1] = '\0';
    isbn[strlen(isbn) + 1] = '\0';
    quantidade[strlen(quantidade) + 1] = '\0';

    strcpy(resultado[0], index);
    strcpy(resultado[1], autor);
    strcpy(resultado[2], titulo);
    strcpy(resultado[3], editora);
    strcpy(resultado[4], local);
    strcpy(resultado[5], ano);
    strcpy(resultado[6], edicao);
    strcpy(resultado[7], isbn);
    strcpy(resultado[8], quantidade);

    return resultado;
}

char* edit_waiter(wins_t *pw, char *txt, char *hold)
{
    int yMAX,xMAX;
    int line =0;
    int key =0;
    getmaxyx(stdscr,yMAX,xMAX);

    move(((yMAX/2)-1)+6,((xMAX/2)-2));
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
        {
            break; 
        }
    }    
    line = line-48;
    hold = get_line(line,txt);
    //mvwprintw(pw->w[pw->wi],(yMAX/2),(xMAX/4),"%s",hold);
    refresh();
    wrefresh(pw->w[pw->wi]);
    return hold;
}

char *get_line(int line,char *txt)
{
    FILE *file;
    file = fopen(txt,"r");
    
    char *line_wanted = (char*)calloc(50,sizeof(char));
    
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

        //mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-19)),(xMAX/4),"%i",line);

        fptr1 = fopen(fname, "r");
        if(!fptr1) 
		{
                //printf(" File not found or unable to open the input file!!\n");
                return;
        }
        
        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
        if(!fptr2) 
		{
                //printf("Unable to open a temporary file to write!!\n");
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
            //printf("%c",ch); 
            ch=fgetc(fptr1); 
        }
        noecho();
}
void printFormRegClient(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw)
{
	int ch;
    // ,xMAX=0,yMAX=0;

	/*initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);*/
	// getmaxyx(stdscr,yMAX, xMAX);

	//win_body = newwin(yMAX, xMAX, 0, 0);

	assert(pw2->w[pw2->wi] != NULL);
	// box(win_body, 0, 0);
	
	// mvwprintw(win_body, 1, 2, "Press F1 to quit and F2 to print fields content");
	
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
	//endwin();
}

void printForm(wins_t *pw2, FIELD *fields[], FORM *form, livro_t *pw)
{
	int ch;
    // ,xMAX=0,yMAX=0;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	// getmaxyx(stdscr,yMAX, xMAX);

	// win_body = newwin(yMAX, xMAX, 0, 0);

	// assert(win_body != NULL);
	// box(win_body, 0, 0);
	
	// mvwprintw(win_body, 1, 2, "Press F1 to quit and F2 to print fields content");
	
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
	fields[14] = NULL;
    
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

	set_field_back(fields[1], A_UNDERLINE);
	set_field_back(fields[3], A_UNDERLINE);
	set_field_back(fields[5], A_UNDERLINE);
	set_field_back(fields[7], A_UNDERLINE);
	set_field_back(fields[9], A_UNDERLINE);
	set_field_back(fields[11], A_UNDERLINE);
	set_field_back(fields[13], A_UNDERLINE);

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
	free_field(fields[5]);
	free_field(fields[6]);
	free_field(fields[7]);
	free_field(fields[8]);
	free_field(fields[9]);
	free_field(fields[10]);
	free_field(fields[11]);
	free_field(fields[12]);
	free_field(fields[13]);
	
	delwin(pw2->w[pw2->wi]);
	//endwin();
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
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Edição de Livros",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            show(pw,"livros.txt");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-20)),(xMAX/4),"Pressione F8 e digite a linha do livro que deseja Editar");
            break;
        case 3:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Remoção de Livros",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            show(pw,"livros.txt");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-20)),(xMAX/4),"Pressione F8 e digite a linha do livro que deseja remover");
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
            //rectangle(pw,(yMAX/3)-5,xMAX/3+25,(yMAX/3)+1,(xMAX/3)+60);
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
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Edição de Clientes",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            show(pw,"clientes.txt");
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-20)),(xMAX/4),"Pressione F8 e digite a linha do livro que deseja Editar");
            break;
        case 7:
            wclear(pw->w[pw->wi]);
            refresh();
            box(pw->w[pw->wi], 0, 0);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
            mvwprintw(pw->w[pw->wi],(yMAX-(yMAX-1)),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
            mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 0%i: Remoção de Clientes",pw->wi +1);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
            mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
            show(pw,"clientes.txt");
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

/*void moveInData(wins_t *pw, livro_t *l)
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
}*/
/*funcao a ser mexida */
char *search(wins_t *pw, char **str)
{
    int xMAX,yMAX;
    getmaxyx(stdscr,yMAX,xMAX);

    FILE *arquivo;
    arquivo = fopen("livros.txt","r");
    
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
                if(stringChanged[i] == ';')
                    stringChanged[i] = ' ';
                else
                    i++;
            }

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

/*void search2(wins_t *pw, char *str)
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
}*/


/*char* search2(wins_t *pw, char *str)
{
    FILE *arquivo;
    arquivo = fopen("livros.txt","r");
    
    int c =0, xMAX, yMAX; 
    int line = 1;
    int i =0;

    getmaxyx(stdscr,yMAX,xMAX);

    char stringSearched[200];
    char *stringChanged = (char*)calloc(50,sizeof(char));                                    
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
                
                //mvwprintw(win_body,yMAX-(yMAX-22-c),xMAX-(xMAX-1),"Opaaaaaaaaaa");
                // mvwprintw(win_body,yMAX-(yMAX-22-c),xMAX-(xMAX-1),"[%i] %s",line, stringChanged);
                c++;
        }
        line++;

    }
    //free(stringChanged);
    return stringChanged;
    // free(stringChanged);
    // fclose(arquivo);
}*/

/*
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
}*/

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



