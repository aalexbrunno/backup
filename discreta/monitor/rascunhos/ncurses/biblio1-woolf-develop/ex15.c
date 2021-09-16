/*****************************************************************************
 *   ex15.c                                    Version 20180714.101818       *
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
 * @file ex15.c
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
 *   $gcc ex15.c -o ex15.x -Wall
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
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv ex15.c
 */

/* ------------------------------------------------------------------------- */
/* includes at ex15.h */

#include "ex15.h" /* To be created for this template if needed */

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
    livro_t liv; /*info para ncurses*/
    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -V  version
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

    /* initialize ncurses */
    ex15_init(&win);

    /* laco principal */
    do
    {

        wrefresh(win.w[win.wi]);

        kpress=getch();

        if(kpress==KEY_F(1) || kpress=='1')
        {
            if(win.wi!=0)
            {
                win.wo=win.wi;
                win.wi=0;
                phelp(&win);
            }
            else
            {
                 switch(win.wo)
                 {
                     case 0:
                         win.wi=0;
                         ex15_init(&win);
                         break;
                     case 1:
                         win.wi=1;
                         padd(&win, &liv);
                         break;
                     case 2:
                         win.wi=2;
                         psearch(&win);
                         break;
                     case 3:
                         win.wi=3;
                         pchange(&win);
                         break;
                     case 4:
                         win.wi=4;
                         pdel(&win);
                         break;
                     case 5:
                         win.wi=5;
                         pabout(&win);
                         break;
                }
            }
        }
        if(kpress==KEY_F(2) || kpress=='2')
        {
            msgstatus(win, "Already up-to-date", STOK);
        }
        if(kpress==KEY_F(3) || kpress=='3')
        {
            if(liv.cod == 0)msgstatus(win, "You can't save twice times the same book.", STOK);
            else
            {
                if(msgstatus(win, "Are you sure you want to save?(y/n)", STYESNO) == 1) //chama funcao msgstatues();
                {
                    liv.file = fopen("livros.txt", "a"); // Abre arquivo para Anexar

                    for(int indice=0; indice <= liv.i; indice++)
                    {
                        liv.cod++; /*para contagem correta de linha*/
                                        fprintf(liv.file, "%i;%s;%s;%s;%s;%s;%s;%s\n", liv.cod, liv.autor[indice], liv.titulo[indice], liv.editora[indice], liv.local[indice], liv.ano[indice], liv.ed[indice], liv.isbn[indice]); // Insere o que foi escrito no arquivo
                    }

                                    liv.cod = 0;                   /*Impede que salve duas vezes o mesmo livro*/
                    msgstatus(win, "", STCL);
                    msgstatus(win, "Salvo com sucesso.", STOK);
                    fclose(liv.file);
                }
            }
        }
        if(kpress==KEY_F(4)||kpress=='4')
        {
            if(msgstatus(win, "Are you sure you want to get out?(y/n)", STYESNO) == 1)  /*chama a funcao msgstatus()*/
            {
                kpress = 'q';
            }
            /*else    fazer depois, perdao lupa*/
        }

        if(kpress==KEY_F(5)||kpress=='5')
        {
         if (win.wi == 0)
             pabout(&win);
         else
         {
             win.wo=win.wi;
             win.wi = (win.wi-1)%NWIN;
            switch(win.wi)
            {

                case 0:
                    phelp(&win);
                    break;
                case 1:
                    padd(&win, &liv);
                    break;
                case 2:
                    psearch(&win);
                    break;
                case 3:
                    pchange(&win);
                    break;
                case 4:
                    pdel(&win);
                    break;
                case 5:
                    pabout(&win);
                    break;
            }
         }
        }

        if(kpress==KEY_F(6)||kpress=='6')
        {
            win.wo=win.wi;
            win.wi = (win.wi+1)%NWIN;
            switch(win.wi)
            {

                case 0:
                    phelp(&win);
                    break;
                case 1:
                    padd(&win, &liv);
                    break;
                case 2:
                    psearch(&win);
                    break;
                case 3:
                    pchange(&win);
                    break;
                case 4:
                    pdel(&win);
                    break;
                case 5:
                    pabout(&win);
                    break;

            }

        }

        if(kpress=='s')
            msgstatus(win, "oi na linha de status", STOK);//teste linha de status


        napms(50);
    } while(kpress!='q');

    bomb(win, "", 0, NULL);
}


/* ------------------------------------------------------------------------- */
/* inicio de cada tela */
void modelo(wins_t *pw)  // modelo inicial de todas as janelas
{

//  if(pw->wi!=pw->wo)
//  {
//      pw->wo=pw->wi;
        wclear(pw->w[pw->wi]);
        box(pw->w[pw->wi], 0, 0);
//  }

    mvwprintw(pw->w[pw->wi], 1, (COLS/2)-16, "Nome do Programa"); // altera o nome do programa aqui, por enquanto e subtrai a quant de caracteres
    mvwhline(pw->w[pw->wi], 2, 1, '-', COLS-2);// linha de divisoria(LD)
    mvwprintw(pw->w[pw->wi], 3, 1, nomejanela[pw->wi]);// nome da tela que se encontra
    mvwhline(pw->w[pw->wi], 4, 1, '-', COLS-2);//LD

    mvwhline(pw->w[pw->wi], LINES-4, 1, '-', COLS-2); //LD
    mvwprintw(pw->w[pw->wi], STLINE, 1, "|Status line:");
}
/* ------------------------------------------------------------------------- */
/* Linha de atalhos */
void atalhos()  // atalhos
{
    attron(A_REVERSE);
    mvprintw(LINES-1, 0,"F1 Help "); // atalho 1
    mvprintw(LINES-1, 9, "F2 Load "); // atalho 2
    mvprintw(LINES-1, 18,"F3 Save "); // atalho 3
    mvprintw(LINES-1, 27, "F4 quit "); // atalho 4
    mvprintw(LINES-1, COLS-35, "F5 Prev "); // atalho 5
    mvprintw(LINES-1, COLS-26, "F6 Next "); // atalho 6
    mvprintw(LINES-1, COLS-17, "F7 Unkn "); // atalho 7
    mvprintw(LINES-1, COLS-8, "F8 Unkn "); // atalho 8
    attroff(A_REVERSE);
}
/* ------------------------------------------------------------------------- */
/* imprime tela 00: help */
void phelp(wins_t *pw)
{
    int lst=8; // linha que inicia os helps

    IFDEBUG("phelp()"); // funcao caso de erro ao iniciar
    pw->wi=0;
    modelo(pw); //funcao de template de cada pagina

    mvwprintw(pw->w[pw->wi], lst, 1,   "<f1> ou <1>  : Abre o help");
    mvwprintw(pw->w[pw->wi], lst++, 1, "<f2> ou <2>  : Carrega ultima alteracao");
    mvwprintw(pw->w[pw->wi], lst++, 1, "<f3> ou <3>  : Salva alteracoes");
    mvwprintw(pw->w[pw->wi], lst++, 1, "<f4> ou <4>  : Sai do programa");
    mvwprintw(pw->w[pw->wi], lst++, 1, "<f5> ou <5>  : Retrocede a pagina");
    mvwprintw(pw->w[pw->wi], lst++, 1, "<f6> ou <6>  : Avanca a pagina");

    wrefresh(pw->w[pw->wi]);
}

/* ------------------------------------------------------------------------- */
/* imprime tela 01 : adicionar livro  */
void padd(wins_t *pw, livro_t *pa)
{
    int lst = 5; /*Linha que inicia*/
    int met = (LINES/2); /*Linha na metade da tela*/
    char c; /*Para contagem de linhas*/
    int indice =1; /*Guarda return de msgstatus() e continua ou nao adicionando livros*/

    IFDEBUG("padd()");   // funcao caso de erro ao iniciar
    pw->wi=1;            // numero da janela atual
    modelo(pw);          // funcao de template de cada janela


    mvwprintw(pw->w[pw->wi], lst++, 1, "Campo Obrigatório:                    ");
    mvwprintw(pw->w[pw->wi], lst++, 1, "Título:_______________________________");
    mvwprintw(pw->w[pw->wi], lst++, 1, "Autor:________________________________");
    mvwprintw(pw->w[pw->wi], lst++, 1, "Ano:__________________________________");
    mvwprintw(pw->w[pw->wi], lst++, 1, "Editora:______________________________");
    mvwprintw(pw->w[pw->wi], lst++, 1, "Local:________________________________");
    mvwprintw(pw->w[pw->wi], lst++, 1, "Campo Opcional:                       ");
    mvwprintw(pw->w[pw->wi], lst++, 1, "Edição:_______________________________");
    mvwprintw(pw->w[pw->wi], lst++, 1, "ISBN:_________________________________");
    mvwhline(pw->w[pw->wi], met, 1, '_', COLS-2);  // linha que divide a tela ao meio

    pa->i = -1; /*Zera a quantidade de livros a ser salva*/
    while(indice == 1)
    {
        if(pa->i == -1)
        {
            indice = msgstatus(*pw, "Do you want to insert a book?(y/n)", STYESNO);
        }
        else
        {
            indice = msgstatus(*pw, "Do you want to insert another book?(y/n)", STYESNO);
        }

        if(indice == 1) /*Insere livro no arq livros.txt*/
        {

            msgstatus(*pw, " ", STCL); /*Limpa linha st*/
            msgstatus(*pw, "Inserting book.", STOK);

            if(pa->i == 4) /*Nao da pra inserir mais de 5 livros por vez*/
            {
                msgstatus(*pw, "You can't insert more then 5 books at time.)", STOK);
                break;
            }
            pa->i++; /*Muda livro*/

            wrefresh(pw->w[pw->wi]); /*Update the screen*/

            lst = 6; /*Volta para linha de Titulo*/
            met = (LINES/2) +1;/*Linha de metade da tela + 1, p/ colocar Titulo embaixo da linha de metade da tela*/

            echo();          // ativa a visibilidade do teclado

            mvwprintw(pw->w[pw->wi], lst, 1, "Título:_________writing...____________");
            wrefresh(pw->w[pw->wi]); /*Update the screen*/
            move(met++,1);                                // move o cursor as coordenadas desejadas
            getnstr(pa->titulo[pa->i],199);                  // lê para a string indicada, com um caracter a menos

            mvwprintw(pw->w[pw->wi], ++lst, 1, "Autor:_________writing..._______________");
            wrefresh(pw->w[pw->wi]); /*Update the screen*/
            move(met++,1);                                // move o cursor as coordenadas desejadas
            getnstr(pa->autor[pa->i],199);                   // lê para a string indicada, com um caracter a menos

            mvwprintw(pw->w[pw->wi], ++lst, 1, "Ano:_________writing..._________________");
            wrefresh(pw->w[pw->wi]); /*Update the screen*/
            move(met++,1);                                // move o cursor as coordenadas desejadas
            getnstr(pa->ano[pa->i],4);                       // lê para a string indicada, com um caracter a menos

            mvwprintw(pw->w[pw->wi], ++lst, 1, "Editora:_______writing..._____________");
            wrefresh(pw->w[pw->wi]); /*Update the screen*/
            move(met++,1);                                // move o cursor as coordenadas desejadas
            getnstr(pa->editora[pa->i],99);                  // lê para a string indicada, com um caracter a menos

            mvwprintw(pw->w[pw->wi], ++lst, 1, "Local:_________writing..._______________");
            wrefresh(pw->w[pw->wi]); /*Update the screen*/
            move(met++,1);                               // move o cursor as coordenadas desejadas
            getnstr(pa->local[pa->i],99);                    // lê para a string indicada, com um caracter a menos

            ++lst; /*Pula uma linha*/
            mvwprintw(pw->w[pw->wi], ++lst, 1, "Edição:_________writing...______________");
            wrefresh(pw->w[pw->wi]); /*Update the screen*/
            move(met++,1);                               // move o cursor as coordenadas desejadas
            getnstr(pa->ed[pa->i],3);                        // lê para a string indicada, com um caracter a menos

            mvwprintw(pw->w[pw->wi], ++lst, 1, "ISBN:_________writing...________________");
            wrefresh(pw->w[pw->wi]); /*Update the screen*/
            move(met++,1);                               // move o cursor as coordenadas desejadas
            getnstr(pa->isbn[pa->i],13);                     // lê para a string indicada, com um caracter a menos

            noecho(); // desativa a visibilidade do teclado

            /*CONTANDO LINHAS*/
            pa->file = fopen("livros.txt", "r"); // Abre arquivo para Ler e Contar Linhas

            pa->cod = 0; //contar desde a primeira linha
            while(fread(&c, sizeof(char), 1, pa->file))
            {
                if(c == '\n')
                    pa->cod++;
            }

            fclose(pa->file);
            /*Fim CONTANDO LINHAS*/

            /*INSERINDO LIVRO EM livros.txt*/
            pa->file = fopen("livros.txt", "a"); // Abre arquivo para Anexar

            if(pa->file == NULL) /*Arquivo vazio*/
            {
                msgstatus(*pw, "Arquivo nao pôde ser lido.   ", STOK);
                wrefresh(pw->w[pw->wi]); /*Update Screen*/
                getch();
            }

        //mvwscanw(pw->w[pw->wi], lst+1, 30, " %[^\n]s", titulo);  // outra opçao de receber dados, infelizmente n usei, mas fica de dica para usarem na proxima, alem de aprenderem a usar o comando move e o getnstr.

            wrefresh(pw->w[pw->wi]); //Update Screen/

            fclose(pa->file); /*Fecha arquivo*/
        }
    }

    msgstatus(*pw, "Nao esqueca de salvar pressionando F3.", STOK);

    wrefresh(pw->w[pw->wi]);
}

/* ------------------------------------------------------------------------- */
/* imprime tela 02 : consulta de livro  */
void psearch(wins_t *pw/*, livro_t *pa*/)  //caso use o ponteiro "*pa" não é necessário utilizar os strings abaixo
{
 //     int cod[4];
     char titulo[200];
     char autor[200];
     char ano[5];
     char editora[100];
     char local[100];
     char ed[5];
     char isbn[14];

   /*
    // p pra procurar livros existentes no arquivo .txt
     char ptitulo[200];
     char pautor[200];
     char pano[5];
     char peditora[100];
     char plocal[100];
     char ped[5];
     char pisbn[14];
    */

     char livros [999]; // ler todo o livro de uma linha ou código
 //    char n; // char criado para poder alterar o código

      int lst = 5; //linha de inicio dos mwprintw, inicia na linha 5
      int lst2 = 23; //linha que escreve na tela dividida

    IFDEBUG("psearch()"); // funcao caso de erro ao iniciar
    pw->wi=2;
    modelo(pw); //funcao de template de cada pagina

        echo();          // ativa a visibilidade do teclado

        mvwprintw(pw->w[pw->wi], lst++, 1, " Preencha total ou parcialmente um ou mais campos: ");
        mvwprintw(pw->w[pw->wi], lst++, 1, "                                                   ");
        mvwprintw(pw->w[pw->wi], lst++, 1, " Título:___________________________________________");
        mvwprintw(pw->w[pw->wi], lst++, 1, " Autor:____________________________________________");
        mvwprintw(pw->w[pw->wi], lst++, 1, " Ano:______________________________________________");
        mvwprintw(pw->w[pw->wi], lst++, 1, " Editora:__________________________________________");
        mvwprintw(pw->w[pw->wi], lst++, 1, " Local:____________________________________________");
        mvwprintw(pw->w[pw->wi], lst++, 1, " Edição:___________________________________________");
        mvwprintw(pw->w[pw->wi], lst++, 1, " ISBN:_____________________________________________");

        mvwhline(pw->w[pw->wi], (LINES/2), 1, '_', COLS-2);  // linha que divide a tela ao meio
        wrefresh(pw->w[pw->wi]);   //Update Screen

    if(msgstatus(*pw, "       Are you looking for a specific book?(y/n)", STYESNO) == 1) /*Insere livro no arq livros.txt*/
    {
        move(7,9);                                // move o cursor as coordenadas desejadas
        getnstr(titulo,199);                  // lê para a string indicada, com um caracter a menos
        move(8,8);                                // move o cursor as coordenadas desejadas
        getnstr(autor,199);                   // lê para a string indicada, com um caracter a menos
        move(9,6);                                // move o cursor as coordenadas desejadas
        getnstr(ano,4);                       // lê para a string indicada, com um caracter a menos
        move(10,10);                                // move o cursor as coordenadas desejadas
        getnstr(editora,99);                  // lê para a string indicada, com um caracter a menos
        move(11,8);                               // move o cursor as coordenadas desejadas
        getnstr(local,99);                    // lê para a string indicada, com um caracter a menos
        move(12,9);                               // move o cursor as coordenadas desejadas
        getnstr(ed,3);                        // lê para a string indicada, com um caracter a menos
        move(13,7);                               // move o cursor as coordenadas desejadas
        getnstr(isbn,13);                     // lê para a string indicada, com um caracter a menos
        wrefresh(pw->w[pw->wi]);                  //Update Screen
    }

        FILE *file; /*Arquivo*/

        file = fopen("livros.txt", "r"); // Abre o arquivo para leitura

        if(file == NULL)
        {
            printf("Erro ao identificar o arquivo");
        }

         //Lara comentou apenas para rodar o cod, mas nao estaca comentado
       // fgets(livros, 999, file);
        mvwprintw(pw->w[pw->wi], lst2, 1, "  ");
        mvwprintw(pw->w[pw->wi], lst2++, 1, "  ");
        mvwprintw(pw->w[pw->wi], lst2++, 1, " Resultados da busca: ");
        mvwprintw(pw->w[pw->wi], lst2++, 1, "  ");
        mvwprintw(pw->w[pw->wi], lst2++, 1, " %s", livros); // lê a primeira linha do arquivo .txt até encontrar '\n' ou o valor atribuído for atingido

        noecho(); //após confirmar o livro consultado, não há motivo de continuar vendo oq está sendo digitado


     /*
       // para depois comparar individualmente cada campo junto a uma função while para altera o codigo quando a linha terminar...

        fscanf(file,"%s", ptitulo);
        fscanf(file,"%s", pautor);
        fscanf(file,"%s", pano);
        fscanf(file,"%s", peditora);
        fscanf(file,"%s", plocal);
        fscanf(file,"%s", ped);
        fscanf(file,"%s", pisbn);
      */


    refresh();
}
/* ------------------------------------------------------------------------- */
/* imprime tela 03 : mudar livro  */
void pchange(wins_t *pw)
{
     
    
    IFDEBUG("pchange()"); // funcao caso de erro ao iniciar
     pw->wi=3;
    modelo(pw); //funcao de template de cada pagina
   
    int xMAX,yMAX;
    getmaxyx(stdscr,yMAX,xMAX);
    wclear(pw->w[pw->wi]);
    refresh();
    box(pw->w[pw->wi], 0, 0);

     mvwhline(pw->w[pw->wi],(yMAX-(yMAX-2)),xMAX-(xMAX-1),0,xMAX-2);
     mvwprintw(pw->w[pw->wi],yMAX-(yMAX-1),(xMAX/3)+2,"== Sistema de bibioteca Smith ==");
     mvwprintw(pw->w[pw->wi],yMAX-(yMAX-3),2,"Tela 03: editar os livros alex ",pw->wi +1);
     mvwhline(pw->w[pw->wi],(yMAX-(yMAX-4)),xMAX-(xMAX-1),0,xMAX-2);
     mvwhline(pw->w[pw->wi],(yMAX-(yMAX-17)),xMAX-(xMAX-1),0,xMAX-2);
   
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
     mvwprintw(pw->w[pw->wi],(yMAX-(yMAX -18)),(xMAX-(xMAX-2)), "o valor de ymax %d e xmax %d", yMAX, xMAX);    
    
    /*
    IFDEBUG("pchange()"); // funcao caso de erro ao iniciar
    pw->wi=3;
    modelo(pw); //funcao de template de cada pagina
    */
}
/* ------------------------------------------------------------------------- */
/* imprime tela 04 : apagar livro  */
void pdel(wins_t *pw)
{

    IFDEBUG("pdel()"); // funcao caso de erro ao iniciar
    pw->wi=4;
    modelo(pw); //funcao de template de cada pagina

}
/* ------------------------------------------------------------------------- */
/* imprime tela 05 : sobre biblioteca  */
void pabout(wins_t *pw)
{

    IFDEBUG("pabout()"); // funcao caso de erro ao iniciar
    pw->wi=5;
    modelo(pw); //funcao de template de cada pagina

}
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
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "ex15", "Brief description");
    printf("\nUsage: %s [-h|-v]\n", "ex15");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");

    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

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
// */

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
    printf("%s - Version %s\n", "ex15", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ------------------------------------------------------------------------- */
/* imprime na linha de status */
int msgstatus(wins_t win, char *msg, int tipo)
{
    IFDEBUG("msgstatus()");
    //char const *const lc = "|Status line:";
    int kpress;

    switch(tipo)
    {
        case STOK:
            mvwprintw(win.w[win.wi], STLINE, 15, "%s", msg);
            break;
        case STYESNO:
             mvwprintw(win.w[win.wi], STLINE, 15, "%s", msg);
             wrefresh(win.w[win.wi]); //  a mensagem na tela
             do
             {
                kpress = getch();
                napms(30);
             }
             while(kpress != 'y' && kpress != 'n');

             if(kpress == 'y')
                 return 1;
             else
             {
                 mvwhline(win.w[win.wi], STLINE, 15, ' ', COLS-2); //Limpa linha de st
                 return 0;
             }
             break;
        case STCL: /*Limpa linha st*/
            mvwhline(win.w[win.wi], STLINE, 15, ' ', COLS-2); //Limpa linha de st
            break;
        default:
             mvwprintw(win.w[win.wi], STLINE, 15, "status type undefined");
             break;
     }
     wrefresh(win.w[win.wi]);
     return 0;
 }

 /* ------------------------------------------------------------------------- */
 /* termina o programa graciosamente */
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
 void ex15_init(wins_t *pw)
 {
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

     /* criar janelas */
     for(i=0; i<NWIN; i++)
     {
         pw->w[i]=newwin(LINES-1,COLS,0,0);
         if(pw->w[i]==NULL)
         {
             for(--i; i>=0; --i)
                 delwin(pw->w[i]);
             endwin();
 
         }
     }       
 }        

/* esboço da função de movimentação */

     // Professor fez essa função no seu laço principal do programa gwork devido ele ser um programa simples com apenas uma tela para fazer alterações //
 // como o biblio vai ter 4 janelas como alterações precimanos fazer uma função que resouva esse problema nas 4 telas //
 /*    do
     {
         kpress=getch();
         if (Kpress == KEY_RIGHT)
         {
             if (dt.themenu)
                 dt=addmenu(dt);
             else
             dt=addcoin(dt);
         }
         if (Kpress == KEY_LEFT)
         {
             if (dt.themenu)
                 dt=submenu(dt);
             else
             dt=suncoin(dt);
             dt=submenu(dt)
         }
         if (Kpress == KEY_DOWN)
         {
            if (dt.themenu)
               dt=subcoin(dt);
            else
            dt=addmenu(dt);
         }
     }
 */
 /* ------------------------------------------------------------------------- */
 /* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline    */
 /* Template by Dr. Beco <rcb at beco dot cc>       Version 20180716.101436   */


/*                   */

