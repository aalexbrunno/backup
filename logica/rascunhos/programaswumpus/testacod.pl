:- use_module(wumpus, [start/0]). % agente usa modulo simulador

:- dynamic([
  adjbat/1,
  adjpit/1,
  estou/1,
  andei/1,
  wumpus_em/1,
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
  setSeguras(H),
  setEstou(H),
  setAndei(H),
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
  Y1<5,
  Lc = [[X,Y1]],!.

adjcima(_,_,[]).

adjbaixo(X,Y,Lb) :-
  Y1 is Y-1,
  Y1>0,
  Lb = [[X,Y1]],!.

adjbaixo(_,_,[]).

adjesqueda(X,Y,Lesq) :-
  X1 is X+1,
  X1<5,
  Lesq = [[X1,Y]],!.

adjesqueda(_,_,[]).

adjdireita(X,Y,Ldir) :-
  X1 is X-1,
  X1>0,
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
  Y1<5,
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
  X1<5,
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

setwumpus_em(List) :- %incompleta
  retractall(wumpus_em(_)),
  asserta(wumpus_em(List)).



setAndei([X,Y]) :-
  retractall(andei(_)),
  asserta(andei([X,Y])).

setSeguras([X,Y]) :-
  retractall(seguras(_)),
  asserta(seguras([X,Y])).

setFlag_init(N) :-
  retractall(flag_init(_)),
  asserta(flag_init(N)).
  
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

  
/*

atualizawumpus([yes,_,_,_,_,_]) :-
    estou([X,Y]),
    andei(An),
    retractall(andei(_)),
    union(An,[[X,Y]],Nan),
    asserta(andei(Nan)),
    adjacentes(X,Y,La),
    seguras(Ls),
    subtract(La,Ls,Lp1),
    buracoem(Lw),
    subtract(Lw,Ls,Lp2),
    union(Lp1,Lp2,Nw),
    retractall(buracoem(_)),
    asserta(buracoem(Nw)),
    andarei(Arei),
    append(Arei,Ls,Tarei1),
    list_to_set(Tarei1,Tarei),
    subtract(Tarei,Nan,Narei),
    retractall(andarei(_)),
    asserta(andarei(Narei)).

*/






uniao(Lw1,Lw2,NovaListaWumpus):-
    Lw2=[],
    union(Lw1,Lw2,NovaListaWumpus),
    !.


%atualiza_wumpus([_,_,_,_,_,_,_]).

atualiza_seguras([no,no,_,_,_,no,_]) :-
  ondeEstou([X,Y]),
  andei(An),
  union(An,[[X,Y]],Nan),
  setAndei(Nan),
  seguras(Ls),
  union(Ls,[[X,Y]],Ns),
  setSeguras(Ns),!.

atualiza_seguras([_,_,_,_,_,_,_]).

grab_gold([_,_,yes,_,_,_,_],grab).



separe_action(_, goforward) :-
  ondeEstou([X,Y]),
  agent_orientation([Ang|_]),
  seMoveu(X,Y,Ang,NewCoord),
  setEstou(NewCoord).

