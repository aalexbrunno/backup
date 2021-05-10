/***************************************************************************
 *   ex10.pl                                  Version 20210417.154636      *
 *                                                                         *
 *   Torre de Hanoi                                                        *
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
 *   Webpage: http://beco.poli.br/aalexbrunno@gmail.com                                          username                                *
 *   Phone: (81) 98735-8802                                                *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief torre de hanói recursiva.
 * @details usando recursão o programa resolve o jogo da torre de hanói.
 * @return as instruções para resolver o jogo.
 */

/*
mover(1,E,D,_) :-  
    !,
    write('Mover disco superior de '), 
    write(E), 
    write(' para '), 
    write(D), 
    nl. 

mover(N,E,D,C) :- 
    !,
    N>1, 
    M is N-1, 
    mover(M,E,C,D), 
    mover(1,E,D,_), 
    mover(M,C,D,E). 
*/


move(1,X,Y,_) :-  
    write('Move top disk from '), 
    write(X), 
    write(' to '), 
    write(Y), 
    nl. 
move(N,X,Y,Z) :- 
    N>1, 
    M is N-1, 
    move(M,X,Z,Y),
    move(1,X,Y,_),
    move(M,Z,Y,X). 








/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */

