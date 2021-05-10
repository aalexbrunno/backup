/***************************************************************************
 *   ew1.pl                                   Version 20210327.124302      *
 *                                                                         *
 *   exercicio ew1                                                         *
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
 * @brief help is det
 * @details Shows a help message on how to use ew1
 * @return TRUE always.
 */
 

:- dynamic([
    agent_orientation/1,
    agent_location/1,
    wumpus_location/1
    ]).

% #####  for test  #####

init_data :-
    retractall(agent_location(_)),
    retractall(agent_orientation(_)),
    retractall(wumpus_location(_)),
    asserta(wumpus_location([2,2])),
    asserta(agent_location([2,1])),
    asserta(agent_orientation(0)).

calc2p([X,Y],[X1,Y1],Ang) :-
    Etp1 is X*X1,
    Etp2 is Y*Y1,
    Etp3 is (X^2)+(Y^2),
    Etp4 is (X1^2)+(Y1^2),
    Etp5 is sqrt(Etp3),
    Etp6 is sqrt(Etp4),
    Ang is (Etp1+Etp2)/(Etp5*Etp6).

calcBypi(Num,X) :-
    X is (Num*180)/pi().

calc_ang([X,Y],[X1,Y1],Ang) :-
    calc2p([X,Y],[X1,Y1],Dir),
    Rad is acos(Dir),
    calcBypi(Rad,By_ang),
    Ang is floor(By_ang).

apontar([WX, WY],turnleft) :-
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 90,
    !.
apontar([WX, WY],turnright) :-
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 270,
    !.
apontar([WX, WY],turnleft) :-
    agent_orientation(O),
    O =:= 180,
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 270,
    !.
apontar([WX, WY],turnright) :-
    agent_orientation(O),
    O =:= 180,
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 90,
    !.
apontar([WX, WY],turnleft) :-
    agent_orientation(O),
    O =:= 90,
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 180,
    !.
apontar([WX, WY],turnright) :-
    agent_orientation(O),
    O =:= 90,
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 0,
    !.
apontar([WX, WY],turnleft) :-
    agent_orientation(O),
    O =:= 270,
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 0,
    !.
apontar([WX, WY],turnright) :-
    agent_orientation(O),
    O =:= 270,
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 180,
    !.
apontar([WX, WY],shoot) :-
    agent_location([X,Y]),
    wumpus_location([WX,WY]),
    anguloentre([X,Y],[WX,WY],Dir),
    agent_orientation(O),
    Dir =:=  O,
    !.

setAgent_location([X,Y]) :-
    retractall(estou(_)),
    asserta(estou([X,Y])).

setAgent_orientation([X,Y]) :-
    retractall(agent_orientation(_)),
    asserta(agent_orientation([X,Y])).

setWumpus_position([X,Y]) :-
    retractall(wumpus_location([X,Y])),
    asserta(wumpus_location([X,Y])).

anguloentre([X,Y],[X1,Y1],Dir):-
    calc2p([X,Y],[X1,Y1],Ang),
    select_ang_0(Ang,P1),
    select_ang_180(Ang,P2),
    select_ang_270(Ang,P3),
    select_ang_270(Ang,P4),
    Dir is P1+P2+P3+P4.

select_ang_0(Ang,X) :-
    Ang <45,
    X is 0,!;
    
    Ang >315,
    X is 0,!.

select_ang_0(_,0).

select_ang_90(Ang,X) :-
    Ang >45,
    Ang <135,
    X is 90,!.

select_ang_90(_,0).

select_ang_180(Ang,X) :-
    Ang >135,
    Ang <225,
    X is 180,!.

select_ang_180(_,0).

select_ang_270(Ang,X) :-
    Ang >225,
    Ang <315,
    X is 270,!.

select_ang_270(_,0).

/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */

