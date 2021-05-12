/***************************************************************************
 *   ex12.pl                                  Version 20210430.092724      *
 *                                                                         *
 *   exercicio 12                                                          *
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
/* Facts and Rules */
/**
 * @ingroup GroupUnique
 * @brief charada de logica.
 * @details atraves de regras em prolog o programa vai resolver a charada.
 * @return  uma lista com cinco casas que contém a solução do problema.
*/


donoZebra(Dono) :-
	goal(Hs),
	member(h(Dono,zebra,_,_,_), Hs),!.

bebeAgua(Bebida) :-
	goal(Hs),
	member(h(Bebida,_,_,agua,_), Hs),!.

% cada casa na lista Hs de casas é representada como:
% h(Nacionalidade, Animal de estimação, Cigarro, Bebida, Cor)
goal(Hs) :-
    length(Hs, 5),                                            
	member(h(ingles,_,_,_,vermelha), Hs),                         
	member(h(espanhou,cachorro,_,_,_), Hs),                         
	member(h(_,_,_,cafe,verde), Hs),                        
	member(h(ucraniano,_,_,cha,_), Hs),                       
	next(h(_,_,_,_,verde), h(_,_,_,_,branca), Hs),             
	member(h(_,serpente,winston,_,_), Hs),                       
	member(h(_,_,kool,_,amarela), Hs),                        
	Hs = [_,_,h(_,_,_,leite,_),_,_],                          
	Hs = [h(noruegues,_,_,_,_)|_],                           
	next(h(_,raposa,_,_,_), h(_,_,chesterfield,_,_), Hs),       
	next(h(_,_,kool,_,_), h(_,cavalo,_,_,_), Hs),              
	member(h(_,_,lucky,suco,_), Hs),                         
	member(h(japones,_,kent,_,_), Hs),                       
	next(h(noruegues,_,_,_,_), h(_,_,_,_,azul), Hs),          
	member(h(_,_,_,agua,_), Hs),		
	member(h(_,zebra,_,_,_), Hs),!.		

next(X, Y, Ls) :- append(_, [X,Y|_], Ls).
next(X, Y, Ls) :- append(_, [Y,X|_], Ls).


%direita(X, Y, Ls) :- append(_, [X,Y|_], Ls).





/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */

