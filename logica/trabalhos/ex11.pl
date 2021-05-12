/***************************************************************************
 *   ex11.pl                                  Version 20210424.133923      *
 *                                                                         *
 *   jogo da memoria                                                       *
 *   Copyright (C) 2021         by Alex Bruno Seabra                       *
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
 *   Alex Bruno Seabra                                                     *
 *   Email: aalexbrunno@gmail.com                                          *
 *   Webpage: http://beco.poli.br/aalexbrunno@gmail.com                    *
 *   Phone: (81) 98735-8802                                                *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief jogo da memoria .
 * @details o usuario vai receber uma matriz 2x2 com o objetivo de acertar a ordem certa das cartas.
 * @return a matriz 2x2 2 dados de entrada para o usuario poder interagir com o jogo colocando a ordem certa das cartas.
 */

start :-
    random_permutation([as,rei,rainha,valete],Lis),
    nth1(1,Lis,Elemento1),
    nth1(2,Lis,Elemento2),
    nth1(3,Lis,Elemento3),
    nth1(4,Lis,Elemento4),
    format('~w | ~w |~n', [Elemento1, Elemento2]),
    format('~w | ~w |~n', [Elemento3, Elemento4]),
    sleep(3),
    cls,
    write('digite com numeros de 1 a 4 em qual posicao estao essas cartas respectivamente: As, Rei, Rainha, Valete'),
    nl,
    read(Indice),
    nth1(Indice,Lis,Ele),
    write(Ele),
    nl,
    read(Indice2),
    nth1(Indice2,Lis,Ele2),
    write(Ele2),
    nl,
    read(Indice3),
    nth1(Indice3,Lis,Ele3),
    write(Ele3),
    nl,
    read(Indice4),
    nth1(Indice4,Lis,Ele4),
    write(Ele4),
    nl,
    (Ele  = as,
     Ele2 = rei,
     Ele3 = rainha,
     Ele4 = valete,
     write('voce ganhou parabens!!!'),
     !),repete;
     write('voce perdeu tente outra vez'),
     repete.


 
  repete :-
    nl,nl,
    write('Quer jogar de novo? (y/n)'),nl,
    read(Resp),
    execute(Resp).

 execute(R) :-
    R == 'y',
    start.

 execute(_).
 
 
 cls :- write('\e[H\e[2J').







/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */
