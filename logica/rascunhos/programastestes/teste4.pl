/* *********************************************************************** *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *  Copyright (C) 2021 by Alex Bruno Seabra                                 *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *  To contact the author, please write to:                                 *
 *  Name: Alex Bruno Seabra <aalexbrunno@gmail.com>                         *
 *  Webpage: http://beco.poli.br/~username                                  *
 *  Phone: (81) 98735-8802                                                  *
 * ************************************************************************ *
 * 
 */


% uniao(L1, L2, LUNIAO).

%uniao([],L,L). %duas listas só com um unico elemento
%uniao([X|L1],L2,[X|L3]) :- uniao(L1,L2,L3).

%uniao([],L,L).
%uniao([X|L1], L2, [X|L3]) :- uniao(L1,L2,L3).




%membro(X,[X|Z]).
%membro(X,[W|Z]) :- membro(X,Z).

%inter([], _, []).
%inter([H|T],L,[H|U]) :- membro(H,L),!,inter(T,L,U).
%inter([_|T],L,U) :- inter(T,L,U).




%interseccao([], _, []).
%interseccao([Head | L1tail], L2, L3): -
%        memberchk (chefe, L2),
%        !,
%        L3 = [Cabeça | L3 cauda],
%        interseção (L1tail, L2, L3tail).
%interseccao([_ | L1tail], L2, L3): -
%        intersecção (L1tail, L2, L3).






intersection([], _, []).
intersection([Head|L1tail], L2, L3) :-
        memberchk(Head, L2),
        !,
        L3 = [Head|L3tail],
        intersection(L1tail, L2, L3tail).
intersection([_|L1tail], L2, L3) :-
        intersection(L1tail, L2, L3).


    
    
%intersection([], _, []).
%intersection([Head|L1tail], L2, L3) :-
%        memberchk(Head, L2),
%        !,
%        L3 = [Head|L3tail],
%        intersection(L1tail, L2, L3tail).
%intersection([_|L1tail], L2, L3) :-
%        intersection(L1tail, L2, L3).



 %pertence(X, [X, _]).
 %pertence(X, [_|Y]) :- pertence(X, Y).

 %interseccao([], _, []).
 %interseccao([A|X], L2,[A|Z]) :- pertence(A,L2),  interseccao(X, L2,Z).
 %interseccao([_|X], L2, Z) :- interseccao(X, L2, Z).





