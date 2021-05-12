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
  flag_init/1,
  gotTheGold/1,
  mvolta/1,
  possivelSeguroWumpus/1,
  proximaCasa/1,
  wumpusMorto/1,
  flecha/1
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
    init_data(Percepcao),
    tomaDecisao(Percepcao, Acao).

init_data([_,_,_,_,_,_,[H|Ang]]) :-
    flag_init \== 1,
    setSeguras([H]),
    setEstou(H),
    setAndei([H]),
    setburaco_em([]),
    setwumpus_em([]),
    setbat_em([]),
    setMvolta(0),
    nth0(0, Ang, O),
    setAgent_orientation(O),
    setWumpusMorto(0),
    setFlecha(1),
    setFlag_init(1),!.

init_data([_,_,_,_,_,_,_]).

resetGame:-
    setFlag_init(0),
    setGotTheGold(0).

tomaDecisao(P,R) :-
    atualiza_seguras(P),
    atualiza_wumpus(P),
    atualiza_brisa(P),
    atualiza_bat(P),
    matouWumpus(P,R),!;
    depoisDeMatarWumpus(P,R),!;
    grab_gold(P,R),!;
    pegou_ouro(P,R),!;
    sentir_nada(P,R),!;
    sentir_buraco(P,R),!;
    sentir_parede(P,R),!;
    sentir_bat(P,R),!;
    sentir_wumpus(P,R),!;
    voltar_sem_vencer(P,R),!.

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
    union(M4,L2,New_pos),
    length(New_pos,N),
    N > 0,!;
    New_pos =[X,Y].

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

setAgent_orientation(Ang) :-
    retractall(agent_orientation(_)),
    asserta(agent_orientation(Ang)).

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

setGotTheGold(N) :-
    retractall(gotTheGold(_)),
    asserta(gotTheGold(N)).

setMvolta(N) :-
    retractall(mvolta(_)),
    asserta(mvolta(N)).

setWumpusMorto(N) :-
    retractall(wumpusMorto(_)),
    asserta(wumpusMorto(N)).

setPossivelSeguroWumpus(L) :-
    retractall(possivelSeguroWumpus(_)),
    asserta(possivelSeguroWumpus(L)).

setProximaCasa(L) :-
    retractall(proximaCasa(_)),
    asserta(proximaCasa(L)).

setFlecha(N) :-
    retractall(flecha(_)),
    asserta(flecha(N)).

andarei(New_Andarei):- 
    seguras(Ls),
    andei(An),
    subtract(Ls, An, Andarei),
    estou(E),
    subtract(Andarei, [E], New_Andarei).

atualiza_andarei(Andarei):-
    retractall(Andarei),
    seguras(Ls),
    andei(An),
    subtract(Ls,An,Andarei).

atualiza_wumpus([yes,_,_,_,_,_,_]) :-
    ondeEstou([X,Y]),
    andei(An),
    union(An,[[X,Y]],Nan),
    setAndei(Nan),
    adjacentes(X,Y,Ladj),
    seguras(Ls),
    subtract(Ladj,Ls,Lp1),
    wumpus_em(W),
    definePosWumpus(Lp1, W, Np),
    setwumpus_em(Np),!.

atualiza_wumpus([_,_,_,_,_,_,_]).

definePosWumpus(Lp, P, R) :-
    P == [],
    R = Lp,
    setPossivelSeguroWumpus(Lp),!.

definePosWumpus(Lp, P, R) :-
    length(P, N),
    N >= 2,
    intersection(Lp,P,R),
    possivelSeguroWumpus(X),
    subtract(X, Lp, Ns),
    seguras(Ls),
    union(Ns,Ls,Nls),
    setSeguras(Nls),!.

definePosWumpus(_, P, R) :-
    length(P, N),
    N == 1,
    R = P.

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

voltar_sem_vencer([_,_,_,_,_,_,_],A):-
    andarei(Andarei),
    Andarei == [],
    vaipara([1,1],A).

grab_gold([_,_,yes,_,_,_,_],grab) :-
    setGotTheGold(1).

sentir_buraco([_,yes,_,_,_,_,_],A):-
    andarei(Andarei),
    nth1(1,Andarei,Casa),
    vaipara(Casa,A).

meiaVolta([_,yes,_,_,_,_,_],A):-
    mvolta(V),
    V < 2,
    V1 is V+1,
    setMvolta(V1),
    A = turnleft,
    agent_orientation(O),
    O2 is O+90,
    setAgent_orientation(O2).

meiaVolta([_,yes,_,_,_,_,_],A):- 
    mvolta(V),
    V == 2,
    setMvolta(0), 
    A = goforward,
    estou([X,Y]),
    agent_orientation(Ang),
    seMoveu(X,Y,Ang,New_coord),
    setEstou(New_coord).

atualiza_bat([_,_,_,_,_,yes,_]) :-
    ondeEstou([X,Y]),
    andei(An),
    union(An,[[X,Y]],Nan),
    setAndei(Nan),
    adjacentes(X,Y,Ladj),
    seguras(Ls),
    subtract(Ladj,Ls,Lp1),
    bat_em(B),
    subtract(B,Ls,Lp2),
    union(Lp1,Lp2,Np),
    setbat_em(Np),!.

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

atualiza_brisa([_,_,_,_,_,_,_]).

matouWumpus([yes,_,_,_,yes,_,_],A) :-
    setWumpusMorto(1),
    wumpusMorto(W),
    W \== 0,
    wumpus_em(E),
    seguras(Ls),
    union(Ls,E,NLs),
    setSeguras(NLs),
    setwumpus_em([[]]),
    vaipara([1,1],A).

matarWumpus(A):-
    flecha(1),
    wumpus_em(E),
    nth1(1,E,Wcasa),
    apontar(Wcasa,A).

sentir_parede([_,_,_,yes,_,_,_],A):-
    getNearHouse(NearH),
    setProximaCasa(NearH),
    proximaCasa(N),
    vaipara(N,A).

sentir_bat([_,_,_,_,_,yes,_],A):-
    andarei(Andarei),
    nth1(1,Andarei,Casa),
    vaipara(Casa,A).


sentir_wumpus([yes,_,_,_,_,_,_],A):-
    (wumpus_em(E),
    length(E,N),
    N == 1,
    matarWumpus(A),!);
    (andarei(Andarei),
    nth1(1,Andarei,Casa),
    vaipara(Casa,A),!).

sentir_nada([no,no,_,no,no,no,_],A):- 
    getNearHouse(NearH),
    setProximaCasa(NearH),
    proximaCasa(N),
    vaipara(N,A).

pegou_ouro([no,no,_,no,no,no,_], A):-
    gotTheGold(D),
    D == 1,
    vaipara([1,1],A),!.

depoisDeMatarWumpus([_,no,_,no,_,no,_],A):-
    wumpusMorto(W),
    W == 1,
    vaipara([1,1],A),!.

vaipara([Xfinal,Yfinal], climb) :-
    estou([X,Y]),
    gotTheGold(G),
    G == 1,
    Xfinal == 1,
    Yfinal == 1,
    Xfinal == X,
    Yfinal == Y,
    resetGame.

vaipara([Xfinal,Yfinal], climb) :-
    estou([X,Y]),
    wumpusMorto(1),
    [Xfinal,Yfinal] == [1,1],
    [Xfinal,Yfinal] == [X,Y],
    resetGame.

vaipara([Xfinal,Yfinal], climb) :-
    estou([X,Y]),
    andarei(Andarei),
    Andarei == [],
    Xfinal == 1,
    Yfinal == 1,
    Xfinal == X,
    Yfinal == Y,
    resetGame.

vaipara([Xfinal,Yfinal],A) :-
    Xfinal == 1,
    Yfinal == 1,
    estou([X,Y]),
    gotTheGold(G),
    G == 0,
    cria_rota([X,Y],[Xfinal,Yfinal],R),
    nth1(1,R,Way),
    apontarpara(Way,Acao),
    A = Acao.

vaipara([Xfinal,Yfinal],A) :-
    ondeEstou([X,Y]),
    cria_rota([X,Y],[Xfinal,Yfinal],R),
    nth1(1,R,Way),
    apontarpara(Way, Acao),
    A = Acao.

apontar([WX, WY],turnleft) :-
    estou([X,Y]),
    agent_orientation(O),
    O =:= 0,
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 90,
    Ang is O+90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontar([WX, WY],turnright) :-
    estou([X,Y]),
    agent_orientation(O),
    O =:= 90,
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 270,
    Ang is O-90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontar([WX, WY],turnright) :-
    estou([X,Y]),
    agent_orientation(O),
    O =:= 0,
    anguloentre([X,Y],[WX, WY],Dir),
    Dir =:= 270,
    Ang is O-90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontar([WX, WY],turnleft) :-
    agent_orientation(O),
    O =:= 180,
    estou([X,Y]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 270,
    Ang is O+90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontar([WX, WY],turnright) :-
    agent_orientation(O),
    O =:= 180,
    estou([X,Y]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 90,
    Ang is O-90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontar([WX, WY],turnleft) :-
    agent_orientation(O),
    O =:= 90,
    estou([X,Y]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 180,
    Ang is O+90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontar([WX, WY],turnright) :-
    agent_orientation(O),
    O =:= 90,
    estou([X,Y]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 0,
    Ang is O-90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontar([WX, WY],turnright) :-
    agent_orientation(O),
    O =:= 180,
    estou([X,Y]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 0,
    Ang is O-90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontar([WX, WY],turnleft) :-
    agent_orientation(O),
    O =:= 270,
    estou([X,Y]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 0,
    Ang is O+90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontar([WX, WY],turnleft) :-
    agent_orientation(O),
    O =:= 270,
    estou([X,Y]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 90,
    Ang is O+90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontar([WX, WY],turnright) :-
    agent_orientation(O),
    O =:= 270,
    estou([X,Y]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 180,
    Ang is O-90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontar([WX, WY],turnleft) :-
    agent_orientation(O),
    O =:= 0,
    estou([X,Y]),
    anguloentre([X,Y],[WX,WY],Dir),
    Dir =:= 90,
    Ang is O+90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontar([WX, WY],shoot) :-
    estou([X,Y]),
    anguloentre([X,Y],[WX,WY],Dir),
    agent_orientation(O),
    Dir =:=  O,
    setFlecha(0).

aproximar(Angulo1,Angulo2):-
    (Angulo1 =:= 360,
     Angulo2 is 0);
    (Angulo1 =:= -90,
     Angulo2 is 270);
     Angulo2 = Angulo1.

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

apontarpara([Xqualquer,Yqualquer],turnleft) :-
    estou([X,Y]),
    agent_orientation(O),
    O =:= 0,
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 90,
    Ang is O+90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),
    !.

apontarpara([Xqualquer,Yqualquer],turnright) :-
    estou([X,Y]),
    agent_orientation(O),
    O =:= 90,
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 270,
    Ang is O-90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontarpara([Xqualquer,Yqualquer],turnright) :-
    estou([X,Y]),
    agent_orientation(O),
    O =:= 0,
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 270,
    Ang is O-90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontarpara([Xqualquer,Yqualquer],turnleft) :-
    agent_orientation(O),
    O =:= 180,
    estou([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 270,
    Ang is O+90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),
    !.

apontarpara([Xqualquer,Yqualquer],turnright) :-
    agent_orientation(O),
    O =:= 180,
    estou([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 90,
    Ang is O-90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontarpara([Xqualquer, Yqualquer],turnleft) :-
    agent_orientation(O),
    O =:= 90,
    estou([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 180,
    Ang is O+90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),
    !.

apontarpara([Xqualquer,Yqualquer],turnright) :-
    agent_orientation(O),
    O =:= 90,
    estou([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 0,
    Ang is O-90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontarpara([Xqualquer,Yqualquer],turnright) :-
    agent_orientation(O),
    O =:= 180,
    estou([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 0,
    Ang is O-90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontarpara([Xqualquer,Yqualquer],turnleft) :-
    agent_orientation(O),
    O =:= 270,
    estou([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 0,
    Ang is O+90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontarpara([Xqualquer,Yqualquer],turnleft) :-
    agent_orientation(O),
    O =:= 270,
    estou([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 90,
    Ang is O+90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontarpara([Xqualquer,Yqualquer],turnright) :-
    agent_orientation(O),
    O =:= 270,
    estou([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 180,
    Ang is O-90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontarpara([Xqualquer,Yqualquer],turnleft) :-
    agent_orientation(O),
    O =:= 0,
    estou([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    Dir =:= 180,
    Ang is O+90,
    aproximar(Ang,Angulo2),
    setAgent_orientation(Angulo2),!.

apontarpara([Xqualquer,Yqualquer],goforward) :-
    ondeEstou([X,Y]),
    anguloentre([X,Y],[Xqualquer,Yqualquer],Dir),
    agent_orientation(O),
    Dir =:=  O,
    seMoveu(X,Y,O,NewCoord),
    setEstou(NewCoord),!.

getNearHouse(NearH) :-
    ondeEstou([X,Y]),
    adjacentes(X,Y,Ladj),
    andarei(Landarei),
    intersection(Landarei,Ladj,Lintersec),
    nth1(1,Lintersec,NearH).

revertOrientation(O,O2) :-
    (O == 0,
    O2 = 180),!;
    (O == 180,
    O2 = 0),!;
    (O == 90,
    O2 = 270),!;
    (O == 270,
    O2 = 90).

calcBypi(Num,X) :-
    X is (Num*180)/pi().

find_quad([X,Y], [X1,Y1], 1) :- 
    X1 >= X, 
    Y1 >= Y.

find_quad([X,Y], [X1,Y1], 2) :- 
    X1 =< X, 
    Y1 >= Y.

find_quad([X,Y], [X1,Y1], 3) :- 
    X1 =< X, 
    Y1 =< Y,
    !.

find_quad([X,Y], [X1,Y1], 4) :- 
    X1 >= X, 
    Y1 =< Y,
    !.

calc2p([X1,Y1], [X2,Y2], [X3,Y3]) :- 
    X3 is X2-X1,
    Y3 is Y2-Y1.

calc_ang([X,Y], [X1,Y1], Ang) :-
    calc2p([X,Y], [X1,Y1], [Pa,Pb]),
    Pa =\= 0,
    Pb =\= 0,
    Tang is Pb/Pa,
    Arad is atan(Tang),
    calcBypi(Arad,Ang),!.

calc_ang([X,Y], [X1,Y1], 0) :- 
    calc2p([X,Y], [X1,Y1], [Pa,Pb]), 
    Pb =:= 0, 
    Pa>0,!.

calc_ang([X,Y], [X1,Y1], 90) :- 
    calc2p([X,Y], [X1,Y1], [Pa,Pb]), 
    Pa =:= 0, 
    Pb>0,!.

calc_ang([X,Y], [X1,Y1], 180) :- 
    calc2p([X,Y], [X1,Y1], [Pa,Pb]), 
    Pb =:= 0, 
    Pa<0,!.

calc_ang([X,Y], [X1,Y1], 270) :- 
    calc2p([X,Y], [X1,Y1], [Pa,Pb]), 
    Pa =:= 0, 
    Pb<0,!.

angulo_circulo([X,Y], [X1,Y1], Angc) :-
    find_quad([X,Y], [X1,Y1], 1),
    calc_ang([X,Y], [X1,Y1], Angc),
    Angc =\= 0,
    Angc =\= 90,
    Angc =\= 180,
    Angc =\= 270,!.

angulo_circulo([X,Y], [X1,Y1], Angc) :-
    find_quad([X,Y], [X1,Y1], 2),
    calc_ang([X,Y], [X1,Y1], Ang),
    Ang =\= 0,
    Ang =\= 90,
    Ang =\= 180,
    Ang =\= 270,
    Angc is 180 + Ang,!.

angulo_circulo([X,Y], [X1,Y1], Angc) :-
    find_quad([X,Y], [X1,Y1], 3),
    calc_ang([X,Y], [X1,Y1], Ang),
    Ang =\= 0,
    Ang =\= 90,
    Ang =\= 180,
    Ang =\= 270,
    Angc is 180 + Ang,!.

angulo_circulo([X,Y], [X1,Y1], Angc) :-
    find_quad([X,Y], [X1,Y1], 4),
    calc_ang([X,Y], [X1,Y1], Ang),
    Ang =\= 0,
    Ang =\= 90,
    Ang =\= 180,
    Ang =\= 270,
    Angc is 270 - Ang,!.

angulo_circulo([X,Y], [X1,Y1], Angc) :-
    calc_ang([X,Y], [X1,Y1], Angc),!.

anguloentre([X,Y], [X1,Y1], Dir) :- 
    calc_ang([X,Y], [X1,Y1], Ang), 
    find_quad([X,Y], [X1,Y1], Q),
    Q =\= 2,
    Q =\= 3,
    Ang >= 315,
    Dir is 0,!;
    calc_ang([X,Y], [X1,Y1], Ang), 
    find_quad([X,Y], [X1,Y1], Q),
    Q =\= 2,
    Q =\= 3,
    Ang =:= 0,
    Dir is 0,!;
    calc_ang([X,Y], [X1,Y1], Ang), 
    find_quad([X,Y], [X1,Y1], Q),
    Q =\= 2,
    Q =\= 3,
    Ang =< 45,
    Dir is 0,!.

anguloentre([X,Y], [X1,Y1], Dir) :-
    angulo_circulo([X,Y], [X1,Y1], Ang), 
    Ang =< 135,
    Ang > 45,
    Dir is 90,!. 

anguloentre([X,Y], [X1,Y1], Dir) :-
    angulo_circulo([X,Y], [X1,Y1], Ang), 
    Ang =< 225,
    Ang > 135,
    Dir is 180,!. 

anguloentre([X,Y], [X1,Y1], Dir) :-
    angulo_circulo([X,Y], [X1,Y1], Ang), 
    Ang < 315,
    Ang > 225,
    Dir is 270,!.

/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */

