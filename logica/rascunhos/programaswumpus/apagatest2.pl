%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    Hunt The Wumpus - World Simulator                                          %
%    Copyright (C) 2012 - 2016  Ruben Carlo Benante <rcb at beco dot cc>        %
%                                                                               %
%    This program is free software; you can redistribute it and/or modify       %
%    it under the terms of the GNU General Public License as published by       %
%    the Free Software Foundation; version 2 of the License.                    %
%                                                                               %
%    This program is distributed in the hope that it will be useful,            %
%    but WITHOUT ANY WARRANTY; without even the implied warranty of             %
%    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              %
%    GNU General Public License for more details.                               %
%                                                                               %
%    You should have received a copy of the GNU General Public License along    %
%    with this program; if not, write to the Free Software Foundation, Inc.,    %
%    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Special thanks to:
%     - Gregory Yob
%     - Larry Holder 
%     - Walter Nauber
%
% A Prolog implementation of the Wumpus world invented by Gregory Yob (1972)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% To allow an agent to run with the Wumpus Simulator you need to define:
%   init_agent : 
%       It will be called only once, at the start. Put here definitions and
%       other start code you need (asserts, retracts, and so on)
%   run_agent :
%       It will be called each turn by the simulator.
%       Input: perceptions from the world.
%       Expected output: an action for the agent to perform.
%   world_setup([Size, Type, Move, Gold, Pit, Bat, [RandS, RandA]]):
%       This is a fact. It will be consulted only once at the beginning,
%       even before init_agent. It will configure the world as you say,
%       or use a default in case of conflicts or mistakes.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Lista de Percepcao: [Stench, Breeze, Glitter, Bump, Scream, Rustle]
% Traducao: [Fedor, Vento, Brilho, Trombada, Grito, Ruido]
% Acoes possiveis (abreviacoes):
% 1. goforward (go)                - andar
% 2. turnright (turn, turnr ou tr) - girar sentido horario
% 3. turnleft (turnl ou tl)        - girar sentido anti-horario
% 4. grab (gr)                     - pegar o ouro
% 5. shoot (sh)                    - atirar a flecha
% 6. sit (si)                      - sentar (nao faz nada, passa a vez)
% 7. climb (cl)                    - sair da caverna
% 8. gps                           - pega sua posicao e orientacao
%
% Costs (Custos):
% Actions: -1 (Andar/Girar/Pegar/Sair/Atirar/Sentar/GPS)
% Die: -1000 (morrer no buraco, wumpus ou de fadiga)
% Killing the Wumpus: +1000 (matar Wumpus)
% Climbing alive with golds: +500 for each gold (sair com ouro)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% To run the example, start PROLOG with (rode o exemplo iniciando o prolog com):
% swipl -s agenteXXX.pl
% then do the query (faca a consulta):
% ?- start.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% world_setup([Size, Type, Move, Gold, Pit, Bat, Adv])
%
% Size and Type: - fig62, 4
%                - grid, [2-9] (default 4)
%                - dodeca, 20
%       +--------+-----------+
%       |  Type  |    Size   |
%       +--------+-----------+
%       | fig62  | 4 (fixed) |
%       | grid   | 2 ... 9   |
%       | dodeca | 20 (fixed)|
%       +--------+-----------+
%
% Configuration:
%    1.   Size: 0,2..9,20, where: grid is [2-9] or 0 for random, dodeca is 20, fig62 is 4.
%    2.   Type: fig62, grid or dodeca
%    3.   Move: stander, walker, runner (wumpus movement)
%    4.   Gold: Integer is deterministic number, float from 0.0<G<1.0 is probabilistic
%    5.   Pits: Idem, 0 is no pits.
%    6.   Bats: Idem, 0 is no bats.
%    7.   Adv: a list with advanced configuration in the form [RandS, RandA]:
%       - RandS - yes or no, random agent start position
%       - RandA - yes or no, random agent start angle of orientation
%
% examples: 
% * default:
%      world_setup([4, grid, stander, 0.1, 0.2, 0.1, [no, no]]).
% * size 5, 1 gold, 3 pits, some bats prob. 0.1, agent randomly positioned
%      world_setup([5, grid, stander, 1, 3, 0.1, [yes]]). 
%
%   Types of Wumpus Movement
%       walker    : original: moves when it hears a shoot, or you enter its cave
%       runner    : go forward and turn left or right on bumps, maybe on pits
%       wanderer  : arbitrarily choses an action from [sit,turnleft,turnright,goforward]
%       spinner   : goforward, turnright, repeat.
%       hoarder   : go to one of the golds and sit
%       spelunker : go to a pit and sit
%       stander   : do not move (default)
%       trapper   : goes hunting agent as soon as it leaves [1,1]; goes home otherwise
%       bulldozer : hunt the agent as soon as it smells him
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% agente007.pl:
%
% Strategy: goes only forward, do not turn, do not grab gold, do not come back
% Performance: it does not go very well as you can imagine
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

:- use_module(wumpus, [start/0]). % agente usa modulo simulador

:- dynamic([
  adjbat/1,
  adjpit/1,
  estou/1,
  andei/1,
  wumpus_em/1,
  buraco_em/1,
  bat_em/1,
  seguras/1,
  agent_orientation/1,
  flag_init/1
]).

% Versao 1.0
% Mundo: 
%    Tamanho (size) 5x5, quadrado (grid)
%    Wumpus nao anda
%    5% de chance de ouro por casa, 4 buracos e 1 morcego
%    agente inicia na casa [1,1], orientado para direita (0 graus)
%    Maximo de acoes antes de morrer de fome: Size^2x4 = 5x5x4 = 100 (media de 4 acoes por casa)
world_setup([5, grid, stander, 0.05, 4, 1, [no, no]]).

% Versao 2.0
% Mundo: 
%    Tamanho (size) aleatorio, quadrado (grid)
%    Wumpus com andar original: quando escuta flechada ou quando se entra em sua casa
%    10% de chance de ouro por casa, 8% buracos e 6% morcego
%    agente inicia em casa aleatoria, orientado tambem aleatoriamente (use GPS)
%    Maximo de acoes antes de morrer de fome: Size^2x4 = media de 4 acoes por casa
%    ou seja, se mundo 5x5, maximo de acoes eh 5^2x4=100
%
%world_setup([0, grid, walker, 0.1, 0.08, 0.06, [yes, yes]]).

% Versao 3.0
% Mundo: 
%    Tamanho (size) 20 casas, formato dodecaedro
%    Wumpus anda quando escuta flecha ou quando o agente entra em sua casa
%    5% de chance de ouro por casa, 3 buracos e 1 morcego
%    agente inicia na casa [1,1], orientado para direita (0 graus)
%    Maximo de acoes antes de morrer de fome: 100 (media de 5 acoes por casa)
%
%world_setup([20, dodeca, walker, 0.05, 3, 1, [no, no]]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Inicie aqui seu programa.

init_agent.

run_agent(Percepcao, Acao) :-
  format("~n***Percepcoes***: ~w~n", [Percepcao]),
  init_data(Percepcao),
  tomaDecisao(Percepcao, Acao).

% anguloentre([X,Y],[X1,Y1],Ang) :-
%   agent_location()
%   Ang is arccos(((X*X1)+(Y*Y1))/(sqrt((X**2)+(Y**2)))*(sqrt((X1**2)+(Y1**2)))),
%   (Ang < 45, Ang is 0);
%   (Ang>45, Ang is 90);
%   (Ang < 135, Ang is 90);
%   (Ang > 135, Ang is 180);
%   (Ang < 225, Ang is 180);
%   (Ang > 225, Ang is 270),
%   !.

% apontar([WX, WY],turnleft) :-
%   wumpus_location([WX,WY]),
%   agent_location([X,Y]),
%   anguloentre([X,Y],[WX,WY],Ang) is 90,
%   !.
% apontar([WX, WY],turnright) :-
%   wumpus_location([WX,WY]),
%   agent_location([X,Y]),
%   anguloentre([X,Y],[WX,WY],Ang) is 270,
%   !.

init_data([_,_,_,_,_,_,[H|Ang]]) :-
  flag_init \== 1,
  setSeguras([H]),
  setEstou(H),
  setAndei([H]),
  setAgent_orientation(Ang),
  setFlag_init(1),!.

init_data([_,_,_,_,_,_,_]).

tomaDecisao(P,R) :-
  grab_gold(P,R),!;

  separe_action(P, R),
  atualiza_seguras(P),
  atualiza_wumpus(P).


adjacentes(X,Y,La) :-
  adjcima(X,Y,Lc),
  adjbaixo(X,Y,Lb),
  adjesqueda(X,Y,Lesq),
  adjdireita(X,Y,Ldir),
  append(Lc, Lb, L1),
  append(Lesq, L1, L2),
  append(Ldir, L2,La).
  
adjcima(X,Y,Lc) :-
  Y1 is Y+1,
  Y1=<5,
  Lc = [[X,Y1]],!.

adjcima(_,_,[]).

adjbaixo(X,Y,Lb) :-
  Y1 is Y-1,
  Y1>0,
  Lb = [[X,Y1]],!.

adjbaixo(_,_,[]).

adjesqueda(X,Y,Lesq) :-
  X1 is X-1,
  X1>0,
  Lesq = [[X1,Y]],!.

adjesqueda(_,_,[]).

adjdireita(X,Y,Ldir) :-
  X1 is X+1,
  X1=<5,
  Ldir = [[X1,Y]],!.

adjdireita(_,_,[]).

seMoveu(X,Y,Ang,New_pos) :-
  cima(X,Y,Ang,M1),
  baixo(X,Y,Ang,M2),
  left(X,Y,Ang,M3),
  right(X,Y,Ang,M4),
  union(M1,M2,L1),
  union(M3,L1,L2),
  union(M4,L2,New_pos).

cima(X,Y,Ang,M1) :-
  Y1 is Y+1,
  Y1=<5,
  Ang == 90,
  M1 = [X,Y1],!.

cima(_,_,_,[]).

baixo(X,Y,Ang,M2) :-
  Y1 is Y-1,
  Y1>0,
  Ang == 270,
  M2 = [X,Y1],!.

baixo(_,_,_,[]).

left(X,Y,Ang,M3) :-
  X1 is X-1,
  X1>0,
  Ang == 180,
  M3 = [X1,Y],!.

left(_,_,_,[]).

right(X,Y,Ang,M4) :-
  X1 is X+1,
  X1=<5,
  Ang == 0,
  M4 = [X1,Y],!.

right(_,_,_,[]).

setEstou([X,Y]) :-
  retractall(estou(_)),
  asserta(estou([X,Y])).

ondeEstou([X,Y]) :-
  estou([X,Y]).

set_agent_location(Ang) :-
  retractall(agent_location(_)),
  asserta(agent_location(Ang)).

setAgent_orientation(Pos) :-
  retractall(agent_orientation(_)),
  asserta(agent_orientation(Pos)).

setwumpus_em(List) :-
  retractall(wumpus_em(_)),
  asserta(wumpus_em(List)).

setbat_em(List) :-
  retractall(bat_em(_)),
  asserta(bat_em(List)).

setburaco_em(List) :-
  retractall(buraco_em(_)),
  asserta(buraco_em(List)).

setAndei(List) :-
  retractall(andei(_)),
  asserta(andei(List)).

setSeguras(List) :-
  retractall(seguras(_)),
  asserta(seguras(List)).

setFlag_init(N) :-
  retractall(flag_init(_)),
  asserta(flag_init(N)).



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
vaipara([Xfinal, Yfinal]):-
        agent_location([X,Y]),
        Xfinal=X,
        Yfinal=Y,
        !.




















%setLife_wumpus(WL) :-
%   retractall(

%kill_wumpus :-
%  retract(wumpus_health(alive)),
%  assert(wumpus_health(dead)).






atualiza_wumpus([yes,_,_,_,_,_,_]) :-
  ondeEstou([X,Y]),
  andei(An),
  union(An,[[X,Y]],Nan),
  setAndei(Nan),
  adjacentes(X,Y,Ladj),
  seguras(Ls),
  subtract(Ladj,Ls,Lp1),
  wumpus_em(W),
  subtract(W,Ls,Lp2),
  union(Lp1,Lp2,Nw),
  setwumpus_em(Nw),!.










%atualiza_scream([_,_,_,_,yes,_,_]) :-
     













atualiza_wumpus([_,_,_,_,_,_,_]).

atualiza_seguras([no,no,_,_,_,no,_]) :-
  ondeEstou([X,Y]),
  andei(An),
  union(An,[[X,Y]],Nan),
  setAndei(Nan),
  seguras(Ls),
  union(Ls,[[X,Y]],Ns),
  adjacentes(X,Y,Ladj),
  union(Ns,Ladj,Ns2),
  setSeguras(Ns2),!.

atualiza_seguras([_,_,_,_,_,_,_]).

grab_gold([_,_,yes,_,_,_,_],grab).

atualiza_bat([_,_,_,_,_,no,_]) :-
ondeEstou([X,Y]),
andei(An),
union(An,[[X,Y]],Nan),
setAndei(Nan),
adjacentes(X,Y,Ladj),
seguras(Ls),
subtract(Ladj,Ls,Lp1),
bat_em(B),
subtract(B,Ls,Lp2),
union(Lp1,Lp2,Nb),
setbat_em(Nb),!.

atualiza_bat([_,_,_,_,_,_,_]).

atualiza_brisa([_,yes,_,_,_,_,_]) :-
ondeEstou([X,Y]),
andei(An),
union(An,[[X,Y]],Nan),
setAndei(Nan),
adjacentes(X,Y,Ladj),
seguras(Ls),
subtract(Ladj,Ls,Lp1),
buraco_em(P),
subtract(P,Ls,Lp2),
union(Lp1,Lp2,Np),
setburaco_em(Np),!.

separe_action(_, goforward) :-
  ondeEstou([X,Y]),
  andei(An),
  agent_orientation([Ang|_]),
  seMoveu(X,Y,Ang,NewCoord),
  setEstou(NewCoord),
  union(An,[NewCoord],Nan),
  setAndei(Nan).

%   % findall(X, menber(X, P), ACT),
%   % [Wum, Bri, Gold, Bump, Scr, Bat, Undo] = P,
%   % menber(Results, P),
%   format("~n***Resposta***: ~w~n", H),
%   separe_action(T,Results),
%   Results = H.
%   % format("~n***Resposta***: ~w~n", Bri),
%   % format("~n***Resposta***: ~w~n", Gold),
%   % format("~n***Resposta***: ~w~n", Bump),
%   % format("~n***Resposta***: ~w~n", Scr),
%   % format("~n***Resposta***: ~w~n", Bat).

  
% move(_, goforward).
% move(_, turnleft).
% chose_action(_, goforward).

  
% seMoveu(AO) :-
%   orientacao0(AO);

%   orientacao90(AO);
  
%   orientacao180(AO);

%   orientacao270(AO).

% orientacao0(0) :-
%   ondeEstou([X,Y]),
%   X2 is X+1,
%   setEstou([X2,Y]).

% orientacao90(90) :-
%   ondeEstou([X,Y]),
%   Y2 is Y+1,
%   setEstou([X,Y2]).

% orientacao180(180) :-
%   ondeEstou([X,Y]),
%   X2 is X+1,
%   setEstou([X2,Y]).

% orientacao0(0) :-
%   ondeEstou([X,Y]),
%   X2 is X+1,
%   setEstou([X2,Y]).

/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */


