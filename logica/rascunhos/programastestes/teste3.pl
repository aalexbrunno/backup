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

/*Dicas: escreva as listas para entender melhor os predicatos serem criados, pratique muito, procure entender a logica do problema e então
 * soluciona-lo, tente entender exatamente o que se pede.

 */

%soma([],0).
%soma([H|T],N) :- soma(T,N1),N is N1+H.
% colocar pra rodar: soma([1,2,3],N).

%soma([ ],0).
%soma([Elem| Cauda],S) :- 
%soma(Cauda,S1), 
%S is S1 + Elem.

soma([ ],0).
soma([Elem| Cauda],S) :-
soma(Cauda,S1),
S is S1 + Elem.



tamanho([],0).
tamanho([_|Y], N) :-
    tamanho(Y,T),
    N is T + 1.


%list_sum([],[],[]).
%list_sum([H1|T1],[H2|T2],[X|L3]):-list_sum(T1,T2,L3), X is H1+H2. % esse X is H1 + H2 pode ser porque ele se refere a cabeça da soma  2 a 2
% colocar pra rodar: list_sum([1,2,3,4],[1,2,3,4],R),write(R).


%list_sum([],[],[]).
%list_sum([X],[],[X]).
%list_sum([],[X],[X]).
%list_sum([C1|T1],[C2|T2],[X|T3]):-
%    list_sum(T1,T2,T3),
%    X is C1+C2.



list_sum([],[],[]).
list_sum([X],[],[X]).
list_sum([],[X],[X]).
list_sum([A1|T1],[A2|T2],[X|T3]):-
    list_sum(T1,T2,T3),
    X is A1+A2.





soma_lista([],[],[]).
soma_lista([H1|T1],[H2|T2],[X|L3]):-
         write("X: "),
         write(X),nl,
         write("L3-1: "),
         write(L3),nl,nl,

         soma_lista(T1,T2,L3),
         
         write("T1: "),
         write(T1),nl,
         write("T2: "),
         write(T2),nl,
         write("T3: "),
         write(L3),nl,nl,

         X = H1+H2,

         write("X-2: "),
         write(X),nl,nl.








frutas([laranja, banana, maca, pera, uva]).

filmes([terror, acao, comedia,ficcao_cientifica,suspence, romance]).

enserir(X,Y,[X|Y]).


ord_frequency_count(Words, Counts) :-
    maplist(downcase_atom, Words, LwrWords),
    msort(LwrWords, Sorted),
    clumped(Sorted, Counts).




