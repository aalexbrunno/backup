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
 * @brief
 * @details
 * @return
*/

% Fatos.

cor(vermelha).
cor(verde).
cor(azul).
cor(branca).
cor(amarela).

casa(1).
casa(2).
casa(3).
casa(4).
casa(5).

dono(ingles).
dono(espanhou).
dono(noruegues).
dono(japones).
dono(ucraniano).

animal(cachorro).
animal(serpente).
animal(raposa).
animal(cavalo).
animal(zebra).

cigarro(winston).
cigarro(kool).
cigarro(chesterfield).
cigarro(lucky_strike).
cigarro(kent).

bebida(agua).
bebida(cha).
bebida(leite).
bebida(suco).


% Casa é o principal se usar ela as coisas fazem mais sentido


goal :-
    tudodiferente(Ingles,Ingcor,Ingbeb,Ingcig,Ingani,Espanhou,Espcor,Espbeb,Espcig,Espani,Noruegues,Norcor,Norbeb,Norcig,Norani,Japones,Japcor, Japbeb,Japcig,Japani,Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani),
    tab(Ingles,Ingcor,Ingbeb,Ingcig,Ingani,Espanhou,Espcor,Espbeb,Espcig,Espani,Noruegues,Norcor,Norbeb,Norcig,Norani,Japones,Japcor, Japbeb,Japcig,Japani,Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani),
    writeln('\nResultado'),
    writef('%w %w %w %w %w\n',[Ingles,Ingcor,Ingbeb,Ingcig,Ingani]),
    writef('%w %w %w %w %w\n',[Espanhou,Espcor,Espbeb,Espcig,Espani]),
    writef('%w %w %w %w %w\n',[Noruegues,Norcor,Norbeb,Norcig,Norani]),
    writef('%w %w %w %w %w\n',[Japones,Japcor,Japbeb,Japcig,Japani]),
    writef('%w %w %w %w %w\n',[Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani]).

tab(Ingles,Ingcor,Ingbeb,Ingcig,Ingani,Espanhou,Espcor,Espbeb,Espcig,Espani,Noruegues,Norcor,Norbeb,Norcig,Norani,Japones,Japcor, Japbeb,Japcig,Japani,Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani) :-
    regra1(Ingles,Ingcor,Ingbeb,Ingcig,Ingani,Espanhou,Espcor,Espbeb,Espcig,Espani,Noruegues,Norcor,Norbeb,Norcig,Norani,Japones,Japcor, Japbeb,Japcig,Japani,Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani),
    regra2(Ingles,Ingcor,Ingbeb,Ingcig,Ingani,Espanhou,Espcor,Espbeb,Espcig,Espani,Noruegues,Norcor,Norbeb,Norcig,Norani,Japones,Japcor, Japbeb,Japcig,Japani,Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani),
    regra3(Ingles,Ingcor,Ingbeb,Ingcig,Ingani,Espanhou,Espcor,Espbeb,Espcig,Espani,Noruegues,Norcor,Norbeb,Norcig,Norani,Japones,Japcor, Japbeb,Japcig,Japani,Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani),
    regra4(Ingles,Ingcor,Ingbeb,Ingcig,Ingani,Espanhou,Espcor,Espbeb,Espcig,Espani,Noruegues,Norcor,Norbeb,Norcig,Norani,Japones,Japcor, Japbeb,Japcig,Japani,Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani),    
    regra5(Ingles,Ingcor,Ingbeb,Ingcig,Ingani,Espanhou,Espcor,Espbeb,Espcig,Espani,Noruegues,Norcor,Norbeb,Norcig,Norani,Japones,Japcor, Japbeb,Japcig,Japani,Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani),
    regra6(Ingles,Ingcor,Ingbeb,Ingcig,Ingani,Espanhou,Espcor,Espbeb,Espcig,Espani,Noruegues,Norcor,Norbeb,Norcig,Norani,Japones,Japcor, Japbeb,Japcig,Japani,Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani),
    regra13(Ingles,Ingcor,Ingbeb,Ingcig,Ingani,Espanhou,Espcor,Espbeb,Espcig,Espani,Noruegues,Norcor,Norbeb,Norcig,Norani,Japones,Japcor, Japbeb,Japcig,Japani,Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani),
    regra14(Ingles,Ingcor,Ingbeb,Ingcig,Ingani,Espanhou,Espcor,Espbeb,Espcig,Espani,Noruegues,Norcor,Norbeb,Norcig,Norani,Japones,Japcor, Japbeb,Japcig,Japani,Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani).


tudodiferente(Ingles,Ingcor,Ingbeb,Ingcig,Ingani,Espanhou,Espcor,Espbeb,Espcig,Espani,Noruegues,Norcor,Norbeb,Norcig,Norani,Japones,Japcor, Japbeb,Japcig,Japani,Ucraniano,Ucrcor,Ucrbeb,Ucrcig,Ucrani) :-
dono(Ingles),
dono(Espanhou),
not(Ingles = Espanhou),
dono(Noruegues),
dono(Japones),
not(Noruegues = Japones),
not(Noruegues = Ingles),
not(Noruegues = Espanhou),
not(Japones = Ingles),
not(Japones = Espanhou),
dono(Ucraniano),
not(Ucraniano = Ingles),
not(Ucraniano = Espanhou),
not(Ucraniano = Noruegues),
not(Ucraniano = Japones),

cor(Ingcor),
cor(Espcor),
not(Ingcor = Espcor),
cor(Norcor),
cor(Japcor),
not(Norcor = Japcor),
not(Norcor = Ingcor),
not(Norcor = Espcor),
not(Japcor = Ingcor),
not(Japcor = Espcor),
cor(Ucrcor),
not(Ucrcor = Ingcor),
not(Ucrcor = Espcor),
not(Ucrcor = Norcor),
not(Ucrcor = Japcor),

bebida(Ingbeb),
bebida(Espbeb),
not(Ingbeb = Espbeb),
bebida(Norbeb),
bebida(Japbeb),
not(Norbeb = Japbeb),
not(Norbeb = Ingbeb),
not(Norbeb = Espbeb),
not(Japbeb = Ingbeb),
not(Japbeb = Espbeb),
bebida(Ucrbeb),
not(Ucrbeb = Ingbeb),
not(Ucrbeb = Espbeb),
not(Ucrbeb = Norbeb),
not(Ucrbeb = Japbeb),

cigarro(Ingcig),
cigarro(Espcig),
not(Ingcig = Espcig),
cigarro(Norcig),
cigarro(Japcig),
not(Norcig = Japcig),
not(Norcig = Ingcig),
not(Norcig = Espcig),
not(Japcig = Ingcig),
not(Japcig = Espcig),
cigarro(Ucrcig),
not(Ucrcig = Ingcig),
not(Ucrcig = Espcig),
not(Ucrcig = Norcig),
not(Ucrcig = Japcig),

animal(Ingani),
animal(Espani),
not(Ingani = Espani),
animal(Norani),
animal(Japani),
not(Norani = Japani),
not(Norani = Ingani),
not(Norani = Espani),
not(Japani = Ingani),
not(Japani = Espani),
animal(Ucrani),
not(Ucrani = Ingani),
not(Ucrani = Espani),
not(Ucrani = Norani),
not(Ucrani = Japani).




% regra(_,_,_,_,5,_,_,_,_,5,_,_,_,_,5,_,_,_,_,5,_,_,_,_,5).

% O Inglês mora na casa vermelha
regra1(ingles,vermelha,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_).

% O Espanhol tem um cachorro
regra2(_,_,_,_,_,espanhou,_,_,_,cachorro,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_).

% Na casa verde se bebe água
regra3(_,verde,agua,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_).
regra3(_,_,_,_,_,_,verde,agua,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_).
regra3(_,_,_,_,_,_,_,_,_,_,_,verde,agua,_,_,_,_,_,_,_,_,_,_,_,_).
regra3(_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,verde,agua,_,_,_,_,_,_,_).
regra3(_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,verde,agua,_,_).

% O Ucraniano bebe chá
regra4(_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,ucraniano,_,cha,_,_).

% A casa verde fica imediatamente à direita da casa branca ????



% O fumante de Winston tem uma serpente
regra5(_,_,_,winston,serpente,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_).
regra5(_,_,_,_,_,_,_,_,winston,serpente,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_).
regra5(_,_,_,_,_,_,_,_,_,_,_,_,_,winston,serpente,_,_,_,_,_,_,_,_,_,_).
regra5(_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,winston,serpente,_,_,_,_,_).
regra5(_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,winston,serpente).

% Na casa amarela se fuma Kool
regra6(_,amarela,_,kool,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_).
regra6(_,_,_,_,_,_, amarela,_,kool,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_).
regra6(_,_,_,_,_,_,_,_,_,_,_,amarela,_,kool,_,_,_,_,_,_,_,_,_,_,_).
regra6(_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,amarela,_,kool,_,_,_,_,_,_).
regra6(_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,amarela,_,kool,_).

% Na casa do meio se bebe leite. ???



% O Norueguês mora na primeira casa da esquerda ???



% O fumante de Chesterfield mora vizinho do dono da raposa. ???



% Na casa vizinha da casa com um cavalo se fuma Kool ???



% O fumante de Lucky Strike bebe suco
% regra(_,_,_,_,5,_,_,_,_,5,_,_,_,_,5,_,_,_,_,5,_,_,_,_,5).
regra13(_,_,suco,lucky-strike,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_).
regra13(_,_,_,_,_,_,_,suco,lucky-strike,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_).
regra13(_,_,_,_,_,_,_,_,_,_,_,_,suco,lucky-strike,_,_,_,_,_,_,_,_,_,_,_).
regra13(_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,suco,lucky-strike,_,_,_,_,_,_).
regra13(_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,suco,lucky-strike,_).

% O Japonês fuma Kent.
regra14(_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,japones,_,kent,_,_,_,_,_,_,_).

% O Norueguês mora vizinho da casa azul ???


