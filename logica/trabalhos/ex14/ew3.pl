/***************************************************************************
 *   ew3.pl                                   Version 20210403.111741      *
 *                                                                         *
 *   exercicio ew3.pl                                                      *
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
/**
 * @ingroup GroupUnique
 * @brief cria uma rota entre entre dois pontos.
 * @details cria uma lista de rotas entre dois pontos onde o ponto A terá que passar até chegar a B.
 * @return a lista dessas coordenadas.
 */


cria_rota([X2,Y2], [X2,Y2], []).

cria_rota([X1,Y1],[X2,Y2],[R|Tail]):-
    DX is X2 - X1,
    DX > 0,
    X3 is X1 + 1,
    X3 =< X2,
    append([[X3,Y1]],R),
    cria_rota([X3,Y1],[X2,Y2],Tail),
    !.

cria_rota([X1,Y1],[X2,Y2],[R|Tail]):-
    DX is X2 - X1,
    DX < 0,
    X3 is X1 - 1,
    X3 >= X2,
    append([[X3,Y1]],R),
    cria_rota([X3,Y1],[X2,Y2],Tail),
    !.

cria_rota([X1,Y1],[X2,Y2],[R|Tail]):-
    DY is Y2 - Y1,
    DY > 0,
    Y3 is Y1 + 1,
    Y3 =< Y2,
    append([[X1,Y3]],R),
    cria_rota([X1,Y3],[X2,Y2],Tail),
    !.

cria_rota([X1,Y1],[X2,Y2],[R|Tail]):-
    DY is Y2 - Y1,
    DY < 0,
    Y3 is Y1 - 1,
    Y3 >= Y2,
    append([[X1,Y3]],R),
    cria_rota([X1,Y3],[X2,Y2],Tail),
    !.














/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */

