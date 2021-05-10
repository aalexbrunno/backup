/***************************************************************************
 *   ew4.pl                                   Version 20210419.220409      *
 *                                                                         *
 *   predicato vai para                                                    *
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


/**
 * @ingroup GroupUnique
 * @brief help is det
 * @details Shows a help message on how to use ew4
 * @return TRUE always.
 */




/*

apontarpara([X,Y],[Xqualquer,Yqualquer],turnleft) :-
    agent_location([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 90,
    !.
apontarpara([X,Y],[Xqualquer,Yqualquer],turnright) :-
    agent_location([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 270,
    !.
apontarpara([X,Y],[Xqualquer,Yqualquer],turnleft) :-
    agent_orientation(O),
    O =:= 180,
    agent_location([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 270,
    !.
apontarpara([X,Y],[Xqualquer,Yqualquer],turnright) :-
    agent_orientation(O),
    O =:= 180,
    agent_location([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 90,
    !.
apontarpara([X,Y],[Xqualquer, Yqualquer],turnleft) :-
    agent_orientation(O),
    O =:= 90,
    agent_location([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 180,
    !.
apontarpara([X,Y],[Xqualquer,Yqualquer],turnright) :-
    agent_orientation(O),
    O =:= 90,
    agent_location([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 0,
    !.
apontarpara([X,Y],[Xqualquer,Yqualquer],turnleft) :-
    agent_orientation(O),
    O =:= 270,
    agent_location([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 0,
    !.
apontarpara([X,Y],[Xqualquer,Yqualquer],turnright) :-
    agent_orientation(O),
    O =:= 270,
    agent_location([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 180,
    !.
apontarpara([X,Y],[Xqualquer,Yqualquer],gofoward) :-
    agent_location([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    agent_orientation(O),
    Dir =:=  O,
    !.
vaipara([Xfinal,Yfinal], climb) :-
        agent_location([1,1]),
        Xfinal=1,
        Yfinal=1,
        !.
vaipara([Xfinal,Yfinal],A) :-
        agent_location([X,Y]),
        not(Xfinal=X),
        not(Yfinal=Y),
        criar_rota([X,Y],[Xfinal,Yfinal],[R|_]), 
        apontarpara([X,Y],R,Acao),
        A is Acao.

*/







vaipara([Xfinal,Yfinal], climb) :-
  estou([X,Y]),
  gotTheGold(G),
  G == 1,
  Xfinal == 1,
  Yfinal == 1,
  Xfinal == X,
  Yfinal == Y.

vaipara([Xfinal,Yfinal],A) :-
  Xfinal == 1,
  Yfinal == 1,
  estou([X,Y]),
  not(Xfinal == X),
  not(Yfinal == Y),
  gotTheGold(G),
  G==1,
  cria_rota([X,Y],[Xfinal,Yfinal],[R|_]),
  apontarpara([X,Y],[R|_],Acao),
  A is Acao.


vaipara([Xfinal,Yfinal],A) :-
  estou([X,Y]),
  not(Xfinal == 1),
  not(Yfinal == 1),
  cria_rota([X,Y],[Xfinal,Yfinal],[R|_]),
  apontarpara([X,Y],[R|_], Acao),
  A is Acao.





apontarpara([X,Y],[Xqualquer,Yqualquer],turnleft) :-
  estou([X,Y]),
  anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
  Dir =:= 90,!.

apontarpara([X,Y],[Xqualquer,Yqualquer],turnright) :-
  estou([X,Y]),
  anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
  Dir =:= 270,!.

apontarpara([X,Y],[Xqualquer,Yqualquer],turnleft) :-
  agent_orientation(O),
  O =:= 180,
  estou([X,Y]),
  anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
  Dir =:= 270,!.

apontarpara([X,Y],[Xqualquer,Yqualquer],turnright) :-
  agent_orientation(O),
  O =:= 180,
  estou([X,Y]),
  anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
  Dir =:= 90,!.

apontarpara([X,Y],[Xqualquer, Yqualquer],turnleft) :-
  agent_orientation(O),
  O =:= 90,
  estou([X,Y]),
  anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
  Dir =:= 180,!.

apontarpara([X,Y],[Xqualquer,Yqualquer],turnright) :-
  agent_orientation(O),
  O =:= 90,
  estou([X,Y]),
  anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
  Dir =:= 0,!.
apontarpara([X,Y],[Xqualquer,Yqualquer],turnleft) :-
  agent_orientation(O),
  O =:= 270,
  estou([X,Y]),
  anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
  Dir =:= 0,!.

apontarpara([X,Y],[Xqualquer,Yqualquer],turnright) :-
  agent_orientation(O),
  O =:= 270,
  estou([X,Y]),
  anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
  Dir =:= 180,!.

apontarpara([X,Y],[Xqualquer,Yqualquer],gofoward) :-
  estou([X,Y]),
  anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
  agent_orientation(O),
  Dir =:=  O,!.










/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */

