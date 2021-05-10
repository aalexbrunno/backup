%#!/usr/bin/swipl -q -G64m -L64m -t main -f none -s
%  Uncomment the live above to run as executable prolog script
%  -q : Operate silently
%  -G : Set global stack
%  -L : Set local stack
%  -t main : Set goal to main
%  -f none : Do not use an initialization file
%  -s : Turn this file into an executable
%       prolog script (use chmod +x ex5.pl)
%

/***************************************************************************
 *   ex5.pl                                   Version 20210310.165943      *
 *                                                                         *
 *   Turma do Prolog                                                       *
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
 * @ingroup GroupUnique.
 * @brief definicação de genero. 
 * @details responde quem é homem e quem é mulher.
 * @return nomes de homem e de mulheres.
 */


man(john).
man(fred).
man(harry).
woman(mary).
woman(julie).
woman(susan).
woman(anne).

%morena(mary).
%morena(anne).

%gosta(john,julie).
%gosta(harry,julie).

%gosta(fred,X) :- 
%    woman(X),
%    morena(X).

%rico(fred, ouro).
%rico(julie, ouro).


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief
 * @details
 * @return
 */

loiro(john).
loiro(julie).
loiro(susan).

moreno(fred).
moreno(harry).
moreno(mary).
moreno(anne).

 /* ---------------------------------------------------------------------- */
 /**
  * @ingroup GroupUnique
  * @brief
  * @details
  * @return
  */

% ou poderia ter escrito rico nos dois casos e depois dizer na regra que o caso envolvido é woman


%rico(fred).
%rico(julie).

rico(X) :- 
    proprietario(X,ouro).

%ouro(fred).
%ouro(julie).

%rico(X) :-
%    ouro(X).


/* ---------------------------------------------------------------------- */
 /**
  * @ingroup GroupUnique
  * @brief
  * @details
  * @return
  */

 gosta(john,X) :-
     woman(X),
     rico(X),
     loiro(X).
 
 
 gosta(harry,X) :-
     woman(X),
     rico(X).


 gosta(fred,X) :-
    woman(X),
    moreno(X). 

 gosta(mary,X) :-
     man(X),
     moreno(X).

 gosta(julie,X) :-
     man(X),
     moreno(X),
     rico(X).
 
 gosta(anne,X) :-
     man(X).

 gosta(susan,X) :-
      man(X).

 gosta_simultaneamente(X,Y) :- 
      man(X),
      woman(Y),
      gosta(X,Y),
      gosta(Y,X).
     
 % tipo se ele já achou a resposta tu pode dar um !corte  para ele não olha
 % os outros ramos da arvore de recursão

 
 
 
 /* ---------------------------------------------------------------------- */
  /**
   * @ingroup GroupUnique
   * @brief
   * @details
   * @return
   */

  
  proprietario(anne, house).
  proprietario(john, car).
  proprietario(fred, ouro).
  proprietario(julie, ouro).
  proprietario(fred, barco).
   proprietario(fred, mansao).


 



/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */
