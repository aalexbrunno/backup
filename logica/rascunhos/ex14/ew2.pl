/***************************************************************************
 *   ew2.pl                                   Version 20210330.182441      *
 *                                                                         *
 *   exercicio ew2.pl                                                      *
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
/* Facts and Rules */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief help is det
 * @details Shows a help message on how to use ew2
 * @return TRUE always.
 */


calcBypi(Num,X) :-
    X is (Num*180)/pi().  %converte radianos para graus. os valores num são em decimal.
                          %para conseguir testar coloque um numero decimal em radianos com o caracter ponto invez da virgula.
find_quad([X,Y], [X1,Y1], 1) :- 
    X1 >= X, 
    Y1 >= Y.

find_quad([X,Y], [X1,Y1], 2) :- 
    X1 =< X, 
    Y1 >= Y.

find_quad([X,Y], [X1,Y1], 3) :- 
    X1 =< X, 
    Y1 =< Y,!.

find_quad([X,Y], [X1,Y1], 4) :- 
    X1 >= X, 
    Y1 =< Y,!.

calc2p([X1,Y1], [X2,Y2], [X3,Y3]) :- 
    X3 is X2-X1,
    Y3 is Y2-Y1.

calc_ang([X,Y], [X1,Y1], Ang) :-
    calc2p([X,Y], [X1,Y1], [Pa,Pb]),
    Pa =\= 0,
    Pb =\= 0,
    Tang is Pb/Pa,
    Arad is atan(Tang),
    calcBypi(Arad,Ang),!.

calc_ang([X,Y], [X1,Y1], 0) :- 
    calc2p([X,Y], [X1,Y1], [Pa,Pb]), 
    Pb =:= 0, 
    Pa>0,!.

calc_ang([X,Y], [X1,Y1], 90) :- 
    calc2p([X,Y], [X1,Y1], [Pa,Pb]), 
    Pa =:= 0, 
    Pb>0,!.

calc_ang([X,Y], [X1,Y1], 180) :- 
    calc2p([X,Y], [X1,Y1], [Pa,Pb]), 
    Pb =:= 0, 
    Pa<0,!.

calc_ang([X,Y], [X1,Y1], 270) :- 
    calc2p([X,Y], [X1,Y1], [Pa,Pb]), 
    Pa =:= 0, 
    Pb<0,!.

angulo_circulo([X,Y], [X1,Y1], Angc) :- 
    find_quad([X,Y], [X1,Y1], 1), 
    calc_ang([X,Y], [X1,Y1], Angc), 
    Angc =\= 0,
    Angc =\= 90,
    Angc =\= 180,
    Angc =\= 270,!.

angulo_circulo([X,Y], [X1,Y1], Angc) :- 
    find_quad([X,Y], [X1,Y1], 2), 
    calc_ang([X,Y], [X1,Y1], Ang),
    Ang =\= 0,
    Ang =\= 90,
    Ang =\= 180,
    Ang =\= 270,
    Angc is 180 + Ang,!.

angulo_circulo([X,Y], [X1,Y1], Angc) :- 
    find_quad([X,Y], [X1,Y1], 3), 
    calc_ang([X,Y], [X1,Y1], Ang), 
    Ang =\= 0,
    Ang =\= 90,
    Ang =\= 180,
    Ang =\= 270,
    Angc is 180 + Ang,!.

angulo_circulo([X,Y], [X1,Y1], Angc) :- 
    find_quad([X,Y], [X1,Y1], 4), 
    calc_ang([X,Y], [X1,Y1], Ang), 
    Ang =\= 0,
    Ang =\= 90,
    Ang =\= 180,
    Ang =\= 270,
    Angc is 270 - Ang,!.

angulo_circulo([X,Y], [X1,Y1], Angc) :- 
    calc_ang([X,Y], [X1,Y1], Angc),!.

anguloentre([X,Y], [X1,Y1], Dir) :- 
    calc_ang([X,Y], [X1,Y1], Ang), 
    find_quad([X,Y], [X1,Y1], Q),
    Q =\= 2,
    Q =\= 3,
    Ang >= 315,
    Dir is 0,!;

    calc_ang([X,Y], [X1,Y1], Ang), 
    find_quad([X,Y], [X1,Y1], Q),
    Q =\= 2,
    Q =\= 3,
    Ang =:= 0,
    Dir is 0,!;

    calc_ang([X,Y], [X1,Y1], Ang), 
    find_quad([X,Y], [X1,Y1], Q),
    Q =\= 2,
    Q =\= 3,
    Ang =< 45,
    Dir is 0,!.


anguloentre([X,Y], [X1,Y1], Dir) :-
    angulo_circulo([X,Y], [X1,Y1], Ang), 
    Ang =< 135,
    Ang > 45,
    Dir is 90,!. 

anguloentre([X,Y], [X1,Y1], Dir) :-
    angulo_circulo([X,Y], [X1,Y1], Ang), 
    Ang =< 225,
    Ang > 135,
    Dir is 180,!. 

anguloentre([X,Y], [X1,Y1], Dir) :-
    angulo_circulo([X,Y], [X1,Y1], Ang), 
    Ang < 315,
    Ang > 225,
    Dir is 270,!. 


















/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */

