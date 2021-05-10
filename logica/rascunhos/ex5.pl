
/***************************************************************************
 *   ex5.pl                                   Version 20210310.165943      *
 *                                                                         *
 *   TURMA DO PROLOG                                                       *
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
 * @brief gender definition. 
 * @details reply who is man.
 * @return names of men.
 */



man(john).
man(fred).
man(harry).



/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique.
 * @brief gender definition.
 * @details reply who is woman.
 * @return names of women.
 */


woman(mary).
woman(julie).
woman(susan).
woman(anne).

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief hair color.
 * @details answer who has blond hair.
 * @return names of those who have blond hair.
 */

blonde(john).
blonde(julie).
blonde(susan).

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique.
 * @brief hair color.
 * @details answer who has dark hair.
 * @return names of those who have dark hair.
 */

dark(fred).
dark(harry).
dark(mary).
dark(anne).

 /* ---------------------------------------------------------------------- */
 /**
  * @ingroup GroupUnique.
  * @brief social class.
  * @details answer who is rich.
  * @return names of people who are rich.
  */


rich(X) :-
    owner(X, gold).


/* ---------------------------------------------------------------------- */
 /**
  * @ingroup GroupUnique
  * @brief spouse preference.
  * @details responds to people's preference in relation to the type of spouse.
  * @return names of possible suitors.
  */

 like(john,X) :-
     woman(X),
     rich(X),
     blonde(X).
 
 
 like(harry,X) :-
     woman(X),
     rich(X).


 like(fred,X) :-
      woman(X),
      dark(X). 

 like(mary,X) :-
     man(X),
     dark(X).

 like(julie,X) :-
     man(X),
     dark(X),
     rich(X).


 like(anne,X) :-
     man(X).

 like(susan,X) :-
     man(X).

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique.
 * @brief couples who like each other.
 * @details responds if the man likes the woman and the woman likes the man.
 * @return names of people who like each other.
 */


 couple(X,Y) :- 
     man(X),
     woman(Y),
     like(X,Y),
     like(Y,X). 
 
 /* ---------------------------------------------------------------------- */
  /**
   * @ingroup GroupUnique
   * @brief the things that people own.
   * @details answers what people have.
   * @return the person’s name and what they have.
   */

  
  owner(anne, house).
  owner(john, car).
  owner(fred, gold).
  owner(julie, gold).



/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */
