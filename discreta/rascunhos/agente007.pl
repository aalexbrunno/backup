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


% Fatos Dinamicos
:- dynamic([
    estou/1,                 %Localizacao atual do agente
    orienta/1,               %Orientacao atual do agente
    flecha/1,                %Quantidade atual de flechas do agente
    ouro/1,                  %Status atual da posse do ouro
    andei/1,                 %Casas visitadas
    andarei/1,               %Casas que ainda serao visitadas
    seguras/1,               %Casas seguras
    segurasburaco/1,         %Casas seguras de buraco
    seguraswumpus/1,         %Casas seguras de Wumpus
    segurasmorcego/1,        %Casas seguras de morcego
    objetivo/1,              %Objetivo atual do agente
    wumpusem/1,              %Casas provaveis de Wumpus
    wumpusvivo/1,            %Status do Wumpus
    buracosem/1,             %Casas provaveis de buraco
    proximaacao/1,           %Proxima acao a ser realizada
    morcegosem/1,            %Casas provaveis de morcego
    movimentosfeitos/1,      %Status de movimento
    copia_seguras/1,         %Copia da lista de casas seguras
    andei_reverso/1          %Lista andei
    ]).

% Limpa informacoes anteriores e atualiza
init_agent:-
    retractall(estou(_)),
    asserta(estou([1,1])),
    retractall(orienta(_)),
    asserta(orienta(0)),
    retractall(flecha(_)),
    asserta(flecha(1)),
    retractall(ouro(_)),
    asserta(ouro(no)),
    retractall(andei(_)),
    asserta(andei([])),
    retractall(andarei(_)),
    asserta(andarei([])),
    retractall(seguras(_)),
    asserta(seguras([])),
    retractall(segurasburaco(_)),
    asserta(segurasburaco([])),
    retractall(seguraswumpus(_)),
    asserta(seguraswumpus([])),
    retractall(segurasmorcego(_)),
    asserta(segurasmorcego([])),
    retractall(objetivo(_)),
    asserta(objetivo(0)),
    retractall(wumpusem(_)),
    asserta(wumpusem([])),
    retractall(wumpusvivo(_)),
    asserta(wumpusvivo(yes)),
    retractall(buracosem(_)),
    asserta(buracosem([])),
    retractall(proximaacao(_)),
    asserta(proximaacao(sit)),
    retractall(morcegosem(_)),
    asserta(morcegosem([])),
    retractall(movimentosfeitos(_)),
    asserta(movimentosfeitos(0)),
    retractall(copia_seguras(_)),
    asserta(copia_seguras([])),
    retractall(andei_reverso(_)),
    asserta(andei_reverso([])).

run_agent(Lista,Acao):-
   [Fedor,Brisa,Brilho,Choque,Grito,Ruido|_]=Lista,
    Percepcao=[Fedor,Brisa,Brilho,Choque,Grito,Ruido],
    rodar(Percepcao,Acao).

% Predicado que calcula acoes necessarias
rodar(Percepcao,Acao):-
    atualiza_fedor(Percepcao),
    atualiza_brisa(Percepcao),
    atualiza_ruido(Percepcao),
    atualiza_grito(Percepcao),
    atualiza_casas_seguras(Percepcao),
    atualiza_caminhos(Percepcao),
    estou(Estou),
    atualiza_estou_seguro(Estou),
    atualiza_objetivo(Percepcao),
    objetivo_de(Percepcao),
    proximaacao(Acao),
    movimentosfeitos(Mf),
    Mf1 is Mf+1,
    retractall(movimentosfeitos(_)),
    asserta(movimentosfeitos(Mf1)),
   (Acao=goforward,atualiza_andei_reverso,orienta(Or),atualiza_estou(Or);
    Acao=turnleft,orienta(Or),atualiza_orientacao(Or,turnleft);
    Acao=turnright,orienta(Or),atualiza_orientacao(Or,turnright);
    Acao=grab;
    Acao=sit;
    Acao=shoot,retractall(flecha(_)),asserta(flecha(0));
    Acao=climb).

% Atualiza lista de casas seguras retirando casas nao seguras
atualiza_seguras(ListaNaoSeguras):-
    seguras(Ls),
    retractall(seguras(_)),
    subtract(Ls,ListaNaoSeguras,NovaListaSeguras),
    asserta(seguras(NovaListaSeguras)).

% Adiciona novas casas seguras a casas que o agente ja sabia que eram seguras
adiciona_seguras(ListaNovosSeguros):-
    seguras(Ls),
    retractall(seguras(_)),
    union(Ls,ListaNovosSeguros, NovaListaSeguras),
    asserta(seguras(NovaListaSeguras)).

% Atualiza casas seguras
atualiza_casas_seguras(Percepcao):-
    atualiza_seguros(Percepcao),
    !.

atualiza_casas_seguras(_).

% Atualiza a casa atual do agente
atualiza_estou(0):-
    estou([X,Y]),
    retractall(estou(_)),
    X<5,
    X1 is X + 1,
    asserta(estou([X1,Y])).

atualiza_estou(0):-
    estou([X,_]),
    X=5.

atualiza_estou(90):-
    estou([X,Y]),
    retractall(estou(_)),
    Y<5,
    Y1 is Y + 1,
    asserta(estou([X,Y1])).

atualiza_estou(90):-
    estou([_,Y]),
    Y=5.

atualiza_estou(180):-
    estou([X,Y]),
    retractall(estou(_)),
    X>1,
    X1 is X - 1,
    asserta(estou([X1,Y])).

atualiza_estou(180):-
    estou([X,_]),
    X=1.

atualiza_estou(270):-
    estou([X,Y]),
    retractall(estou(_)),
    Y>1,
    Y1 is Y - 1,
    asserta(estou([X,Y1])).

atualiza_estou(270):-
    estou([_,Y]),
    Y=1.

% Atualiza orientacao de acordo acao e a orientacao anterior
atualiza_orientacao(0, turnright):-
    retractall(orienta(_)),
    asserta(orienta(270)).

atualiza_orientacao(90, turnright):-
    retractall(orienta(_)),
    asserta(orienta(0)).

atualiza_orientacao(180, turnright):-
    retractall(orienta(_)),
    asserta(orienta(90)).

atualiza_orientacao(270, turnright):-
    retractall(orienta(_)),
    asserta(orienta(180)).

atualiza_orientacao(0, turnleft):-
    retractall(orienta(_)),
    asserta(orienta(90)).

atualiza_orientacao(90, turnleft):-
    retractall(orienta(_)),
    asserta(orienta(180)).

atualiza_orientacao(180, turnleft):-
    retractall(orienta(_)),
    asserta(orienta(270)).

atualiza_orientacao(270, turnleft):-
    retractall(orienta(_)),
    asserta(orienta(0)).

% Atualiza localizacao do agente como sendo segura
atualiza_estou_seguro(Estou):-
    seguras(Ls),
    union([Estou],Ls,Lseguras),
    retractall(seguras(_)),
    asserta(seguras(Lseguras)).

% Chama os predicados para atualizar o andarei de acordo com a percepcao do choque
atualiza_caminhos([_,_,_,no,_,_]):-
    estou([X,Y]),
    atualiza_andei([X,Y]),
    seguras(Ls),
    atualiza_andarei(Ls).

atualiza_caminhos([_,_,_,yes,_,_]):-
    orienta(O),
    estou([X,Y]),
    atualiza_andarei_parede([X,Y],O).

% Atualiza casas ja visitadas
atualiza_andei([X,Y]):-
    andei(An),
    retractall(andei(_)),
    union(An, [[X,Y]], NovaAn),
    asserta(andei(NovaAn)).

% Atualiza andei pela união da localizacao do agente e a lista andei reversa anterior
atualiza_andei_reverso:-
    estou([X,Y]),
    andei_reverso(AnRepetido),
    retractall(andei_reverso(_)),
    union([[X,Y]],AnRepetido,AnRepetido2),
    asserta(andei_reverso(AnRepetido2)).

% Atualiza seguras que o agente pode visitar
atualiza_andarei(ListaSeguras):-
    andarei(Arei),
    andei(Andei),
    append(Arei,ListaSeguras, TemporariaAndarei1),
    list_to_set(TemporariaAndarei1,ConjuntoTemporariaAndarei),
    subtract(ConjuntoTemporariaAndarei, Andei, NovaAndarei),
    retractall(andarei(_)),
    asserta(andarei(NovaAndarei)).

% Atualiza casas que ocorreu choque com a parede
atualiza_andarei_parede([X,Y],0):-
    andarei(Arei),
    X2 is X+1,
    ListaNaoAndareiMais = [[X2,Y]],
    subtract(Arei, ListaNaoAndareiMais, ListaRemovida),
    retractall(andarei(_)),
    asserta(andarei(ListaRemovida)).

atualiza_andarei_parede([X,Y],90):-
    andarei(Arei),
    Y2 is Y+1,
    ListaNaoAndareiMais = [[X,Y2]],
    subtract(Arei, ListaNaoAndareiMais, ListaRemovida),
    retractall(andarei(_)),
    asserta(andarei(ListaRemovida)).

atualiza_andarei_parede([X,Y],180):-
    andarei(Arei),
    X2 is X-1,
    ListaNaoAndareiMais = [[X2,Y]],
    subtract(Arei, ListaNaoAndareiMais, ListaRemovida),
    retractall(andarei(_)),
    asserta(andarei(ListaRemovida)).

atualiza_andarei_parede([X,Y],270):-
    andarei(Arei),
    Y2 is Y-1,
    ListaNaoAndareiMais = [[X,Y2]],
    subtract(Arei, ListaNaoAndareiMais, ListaRemovida),
    retractall(andarei(_)),
    asserta(andarei(ListaRemovida)).

% Casas adjacentes ao agente
adjacentes(X,Y,La):-
    adjcima(X,Y,Ac),
    adjbaixo(X,Y,Ab),
    adjesqu(X,Y,Ae),
    adjdir(X,Y,Ad),
    append(Ac,Ab,L1),
    append(Ae,L1,L2),
    append(Ad,L2, La).

adjcima(X,Y,Ac):-
    Y<5,
    Y1 is Y + 1,
    Ac = [[X,Y1]],
    !.

adjcima(_,_,[]).

adjbaixo(X,Y,Ab):-
    Y>1,
    Y1 is Y - 1,
    Ab = [[X,Y1]],
    !.

adjbaixo(_,_,[]).

adjesqu(X,Y,Ae):-
    X>1,
    X1 is X - 1,
    Ae = [[X1, Y]],
    !.

adjesqu(_,_,[]).

adjdir(X,Y,Ad):-
    X<5,
    X1 is X + 1,
    Ad = [[X1,Y]],
    !.

adjdir(_,_,[]).

% Atualiza casas possiveis de morcegos
atualiza_morcegosem([X,Y]):-
    adjacentes(X,Y,La),
    seguras(Ls),
    subtract(La,Ls,Lm1),
    morcegosem(Lm),
    subtract(Lm,Ls,Lm2),
    (uniao_morcego(Lm1,Lm2,NovaListaMorcegos);
    intersecao_morcego(Lm1,Lm2,NovaListaMorcegos)),
    retractall(morcegosem(_)),
    asserta(morcegosem(NovaListaMorcegos)),
    atualiza_seguras(NovaListaMorcegos).

% Atualiza casas seguras de morcegos
atualiza_naomorcegosem([X,Y]):-
    adjacentes(X,Y,La),
    segurasmorcego(Lsm),
    union(La,Lsm,Lsm1),
    retractall(segurasmorcego(_)),
    asserta(segurasmorcego(Lsm1)).

% Atualiza casas possiveis de Wumpus
atualiza_wumpusem([X,Y]):-
    adjacentes(X,Y,La),
    seguras(Ls),
    subtract(La,Ls,Lw1),
    wumpusem(Lw),
    subtract(Lw,Ls,Lw2),
    (uniao_wumpus(Lw1,Lw2,NovaListaWumpus);
    intersecao_wumpus(Lw1,Lw2,NovaListaWumpus)),
    retractall(wumpusem(_)),
    asserta(wumpusem(NovaListaWumpus)),
    atualiza_seguras(NovaListaWumpus).

% Calcula onde o morcego esta
uniao_morcego(Lm1,Lm2,NovaListaMorcegos):-
    Lm2=[],
    union(Lm1,Lm2,NovaListaMorcegos),
    !.

intersecao_morcego(Lm1,Lm2,NovaListaMorcegos):-
    intersection(Lm1,Lm2,NovaListaMorcegos),
    subtract(Lm1,NovaListaMorcegos,Listaproduto1),
    subtract(Lm2,NovaListaMorcegos,Listaproduto2),
    union(Listaproduto1,Listaproduto2,Listaresultado),
    seguras(Ss),
    segurasmorcego(Sm),
    union(Sm,Listaresultado,Sm1),
    retractall(segurasmorcego(_)),
    asserta(segurasmorcego(Sm1)),
    segurasburaco(Sb),
    seguraswumpus(Sw),
    intersection(Sm1,Sb,Smb),
    intersection(Smb,Sw,Smbw),
    union(Smbw,Ss,Ss2),
    retractall(seguras(_)),
    asserta(seguras(Ss2)).

% Atualiza casas seguras de Wumpus
atualiza_naowumpusem([X,Y]):-
    adjacentes(X,Y,La),
    seguraswumpus(Lsw),
    union(La,Lsw,Lsw1),
    retractall(seguraswumpus(_)),
    asserta(seguraswumpus(Lsw1)).

% Uniao das listas do Wumpus
uniao_wumpus(Lw1,Lw2,NovaListaWumpus):-
    Lw2=[],
    union(Lw1,Lw2,NovaListaWumpus),
    !.

% Atualiza fedor indicando que o Wumpus nao esta vivo
atualiza_fedor([yes,_,_,_,_,_]):-
    wumpusvivo(no),
    !.

% Atualiza fedor indicando que o Wumpus esta vivo
atualiza_fedor([yes,_,_,_,_,_]):-
    wumpusvivo(yes),
    estou([X,Y]),
    atualiza_wumpusem([X,Y]),
    !.

atualiza_fedor([no,_,_,_,_,_]):-
    estou([X,Y]),
    atualiza_naowumpusem([X,Y]).

% Atualiza ruido de acordo com a percepcao recebida
atualiza_ruido([_,_,_,_,_,yes]):-
    estou([X,Y]),
    atualiza_morcegosem([X,Y]).

atualiza_ruido([_,_,_,_,_,no]):-
    estou([X,Y]),
    atualiza_naomorcegosem([X,Y]).

% Atualiza brisa de acordo com a percepcao recebida
atualiza_brisa([_,yes,_,_,_,_]):-
    estou([X,Y]),
    atualiza_buracosem([X,Y]).

atualiza_brisa([_,no,_,_,_,_]):-
    estou([X,Y]),
    atualiza_naoburacosem([X,Y]).

% Atualiza se o Wumpus ta vivo
atualiza_grito([_,_,_,_,yes,_]):-
    retractall(wumpusvivo(_)),
    asserta(wumpusvivo(no)),
    wumpusem(ListaWumpus),
    retractall(wumpusem(_)),
    asserta(wumpusem([])),
    segurasburaco(Sb),
    intersection(ListaWumpus,Sb,Sbw),
    segurasmorcego(Sm),
    intersection(Sbw,Sm,Sbwm),
    seguras(Ls),
    retractall(seguras(_)),
    union(Ls,Sbwm,Ls1),
    asserta(seguras(Ls1)).

atualiza_grito([_,_,_,_,no,_]).

% Atualiza casas possiveis de buraco
atualiza_buracosem([X,Y]):-
    adjacentes(X,Y,La),
    seguras(Ls),
    subtract(La,Ls,Lp1),
    buracosem(Lw),
    subtract(Lw,Ls,Lp2),
    union(Lp1,Lp2, NovaListaBuracos),
    retractall(buracosem(_)),
    asserta(buracosem(NovaListaBuracos)),
    atualiza_seguras(NovaListaBuracos).

% Atualiza casas seguras de buraco
atualiza_naoburacosem([X,Y]):-
    adjacentes(X,Y,La),
    segurasburaco(Lsb),
    union(La,Lsb,Lsb1),
    retractall(segurasburaco(_)),
    asserta(segurasburaco(Lsb1)).

% Atualiza brilho de acordo com a percepcao de ouro
atualiza_brilho([_,_,yes,_,_,_]):-
    atualiza_ouro.

% Chama adiciona_seguras de acordo com a percepcao de ruido, fedor e brisa
atualiza_seguros([no,no,_,_,_,no]):-
    estou([X,Y]),
    adjacentes(X,Y,La),
    adiciona_seguras(La).

% Atualiza o status do ouro e a proxima acao
atualiza_ouro:-
    retractall(proximaacao(_)),
    asserta(proximaacao(grab)),
    retractall(ouro(_)),
    asserta(ouro(yes)).

% Atualiza objetivo do agente de acordo com certas condicoes
atualiza_objetivo(_):-
    objetivo(2),
    !.

atualiza_objetivo(Percepcao):-
    not(Percepcao=[_,_,yes,_,_,_]),
    andarei(Andarei),
    length(Andarei,0),
    ouro(no),
    retractall(objetivo(_)),
    asserta(objetivo(2)),
    !.

atualiza_objetivo(_):-
    ouro(yes),
    wumpusvivo(yes),
    wumpusem(ListaWumpus),
    andarei(Andarei),
    (length(ListaWumpus,1);
    not(length(Andarei,0))),
    retractall(objetivo(_)),
    asserta(objetivo(1)),
    !.

atualiza_objetivo(_):-
    ouro(yes),
    wumpusem(ListaWumpus),
    not(length(ListaWumpus,1)),
    andarei(Andarei),
    length(Andarei,0),
    retractall(objetivo(_)),
    asserta(objetivo(2)),
    !.

atualiza_objetivo(_):-
    wumpusvivo(no),
    ouro(yes),
    retractall(objetivo(_)),
    asserta(objetivo(2)),
    !.

atualiza_objetivo(_).

% Calcula acao de acordo com o objetivo
objetivo_de(_):-
    movimentosfeitos(Mf),
    Mf=0.

objetivo_de([_,_,yes,_,_,_]):-
    ouro(yes),
    retractall(proximaacao(_)),
    asserta(proximaacao(grab)).

objetivo_de([yes,_,_,_,_,_]):-
    flecha(1),
    wumpusem(ListaWumpus),
    length(ListaWumpus,1),
    ListaWumpus=[CW],
    orienta(Or),
    estou(Estou),
    anguloentre(Estou,CW,Dir),
    Dir=Or,
    retractall(proximaacao(_)),
    asserta(proximaacao(shoot)).

objetivo_de([yes,_,_,_,_,_]):-
    flecha(1),
    wumpusem(ListaWumpus),
    length(ListaWumpus,1),
    ListaWumpus=[CW],
    orienta(Or),
    estou(Estou),
    anguloentre(Estou,CW,Dir),
    not(Dir=Or),
    apontar(CW,Acao),
    retractall(proximaacao(_)),
    asserta(proximaacao(Acao)).

objetivo_de([_,_,no,_,_,_]):-
    objetivo(Ob),
    Ob=0,
    andarei(An),
    last(An,X),
    vaipara(X,Acao),
    retractall(proximaacao(_)),
    asserta(proximaacao(Acao)).

objetivo_de([_,_,yes,_,_,_]):-
    objetivo(Ob),
    Ob=0,
    atualiza_brilho([_,_,yes,_,_,_]),
    objetivo_de([_, _, yes, _, _, _]).

objetivo_de(_):-
    objetivo(Ob),
    Ob=1,
    estou([X,Y]),
    wumpusem(ListaCoord),
    length(ListaCoord,1),
    ListaCoord=[[X1,Y1]],
    adjacentes(X1,Y1,La),
    not(member([X,Y],La)),
    member(Coord,La),
    vaipara(Coord,Acao),
    retractall(proximaacao(_)),
    asserta(proximaacao(Acao)).

objetivo_de(_):-
    objetivo(Ob),
    Ob=1,
    wumpusem(ListaCoord),
    not(length(ListaCoord,1)),
    andarei(Andarei),
    last(Andarei,Coord),
    vaipara(Coord,Acao),
    retractall(proximaacao(_)),
    asserta(proximaacao(Acao)).

objetivo_de(_):-
    objetivo(Ob),
    Ob=2,
    estou([X,Y]),
    not([X,Y]=[1,1]),
    vaipara([1,1],Acao),
    retractall(proximaacao(_)),
    asserta(proximaacao(Acao)).

objetivo_de(_):-
    objetivo(Ob),
    Ob=2,
    estou([1,1]),
    Acao=climb,
    retractall(proximaacao(_)),
    asserta(proximaacao(Acao)).

% Calcula onde o Wumpus esta
intersecao_wumpus(Lw1,Lw2,NovaListaWumpus):-
    intersection(Lw1,Lw2,NovaListaWumpus),
    subtract(Lw1,NovaListaWumpus,Listaproduto1),
    subtract(Lw2,NovaListaWumpus,Listaproduto2),
    union(Listaproduto1,Listaproduto2,Listaresultado),
    seguras(Ss),
    seguraswumpus(Sw),
    union(Sw,Listaresultado,Sw1),
    retractall(seguraswumpus(_)),
    asserta(seguraswumpus(Sw1)),
    segurasburaco(Sb),
    segurasmorcego(Sm),
    intersection(Sw1,Sb,Swb),
    intersection(Swb,Sm,Swbm),
    union(Swbm,Ss,Ss2),
    retractall(seguras(_)),
    asserta(seguras(Ss2)).

% Mira no Wumpus de acordo com o angulo entre a localizacao do agente e a do wumpus
apontar(Coord,turnright):-
    estou([X2,Y2]),
    orienta(Or),
    Direcao is ((Or+270) mod 360),
    anguloentre([X2,Y2],Coord,Direcao),
    !.

apontar(Coord,turnleft):-
    estou([X2,Y2]),
    orienta(Or),
    Direcao is ((Or+90) mod 360),
    anguloentre([X2,Y2],Coord,Direcao),
    !.

apontar(Coord,turnright):-
    estou([X2,Y2]),
    orienta(Or),
    Direcao is ((Or+180) mod 360),
    anguloentre([X2,Y2],Coord,Direcao),
    !.

% Calcula a acao
vaipara([X2,Y2],Acao):-
    estou([X1,Y1]),
    seguras(CopiaSeguras),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(CopiaSeguras)),
    cria_rota([X1,Y1],[X2,Y2],R),
    not(member([X2,Y2],R)),
    ([X2,Y2]=[1,1],
    andei_reverso(AndeiRepetido),
    [AndeiUltimo|_]=AndeiRepetido,
    not([X1,Y1]=AndeiUltimo),
    vaipara(AndeiUltimo,Acao),!;
    [X2,Y2]=[1,1],
    andei_reverso(AndeiRepetido),
    [_|Andar]=AndeiRepetido,
    retractall(andei_reverso(_)),
    asserta(andei_reverso(Andar)),
    [AndarUltimo|_]=Andar,
    vaipara(AndarUltimo,Acao),!;
    vaipara([1,1],Acao),
    retractall(objetivo(_)),
    asserta(objetivo(2))),
    !.

vaipara([X2,Y2],goforward):-
    estou([X1,Y1]),
    orienta(O),
    seguras(CopiaSeguras),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(CopiaSeguras)),
    cria_rota([X1,Y1],[X2,Y2],R),
    [[X1,Y1],[Xa,Ya]|_]=R,
    Direcao is O,
    anguloentre([X1,Y1],[Xa,Ya],Direcao),
    !.

vaipara([X2,Y2],turnleft):-
    estou([X1,Y1]),
    orienta(O),
    seguras(CopiaSeguras),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(CopiaSeguras)),
    cria_rota([X1,Y1],[X2,Y2],R),
    [[X1,Y1],[Xa,Ya]|_]=R,
    Direcao is ((O+90)mod 360),
    anguloentre([X1,Y1],[Xa,Ya],Direcao),
    !.

vaipara([X2,Y2],turnright):-
    estou([X1,Y1]),
    orienta(O),
    seguras(CopiaSeguras),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(CopiaSeguras)),
    cria_rota([X1,Y1],[X2,Y2],R),
    [[X1,Y1],[Xa,Ya]|_]=R,
    Direcao is ((O+180)mod 360),
    anguloentre([X1,Y1],[Xa,Ya],Direcao),
    !.

vaipara([X2,Y2],turnright):-
    estou([X1,Y1]),
    orienta(O),
    seguras(CopiaSeguras),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(CopiaSeguras)),
    cria_rota([X1,Y1],[X2,Y2],R),
    [[X1,Y1],[Xa,Ya]|_]=R,
    Direcao is ((O+270)mod 360),
    anguloentre([X1,Y1],[Xa,Ya],Direcao).

% Cria lista rota entre duas coordenadas
cria_rota([X2,Y2],[X2,Y2],[[X2,Y2]]):-!.

cria_rota([X1,Y1],_,[]):-
    copia_seguras(Cs),
    not(member([X1,Y1],Cs)),
    !.

cria_rota([X1,Y1],_,[]):-
    X1<1;X1>5;Y1<1;Y1>5,
    !.

cria_rota([X1,Y1],[X2,Y2],[]):-
    Y1<5,
    anguloentre([X1,Y1],[X2,Y2],90),
    Y3 is Y1+1,
    copia_seguras(Cs),
    subtract(Cs,[[X1,Y1]],Cs1),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(Cs1)),
    not(member([X1,Y3],Cs1)),
    X3 is X1 + 1,
    X4 is X1 - 1,
    not(member([X3,Y1],Cs1)),
    not(member([X4,Y1],Cs1)),
    !.

cria_rota([X1,Y1],[X2,Y2],[]):-
    X1<5,
    anguloentre([X1,Y1],[X2,Y2],0),
    X3 is X1+1,
    copia_seguras(Cs),
    subtract(Cs,[[X1,Y1]],Cs1),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(Cs1)),
    not(member([X3,Y1],Cs1)),
    Y3 is Y1 + 1,
    Y4 is Y1 - 1,
    not(member([X1,Y3],Cs1)),
    not(member([X1,Y4],Cs1)),
    !.

cria_rota([X1,Y1],[X2,Y2],[]):-
    X1>1,
    anguloentre([X1,Y1],[X2,Y2],180),
    X3 is X1-1,
    copia_seguras(Cs),
    subtract(Cs,[[X1,Y1]],Cs1),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(Cs1)),
    not(member([X3,Y1],Cs1)),
    Y3 is Y1 + 1,
    Y4 is Y1 - 1,
    not(member([X1,Y3],Cs1)),
    not(member([X1,Y4],Cs1)),
    !.

cria_rota([X1,Y1],[X2,Y2],[]):-
    Y1>1,
    anguloentre([X1,Y1],[X2,Y2],270),
    Y3 is Y1-1,
    copia_seguras(Cs),
    subtract(Cs,[[X1,Y1]],Cs1),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(Cs1)),
    not(member([X1,Y3],Cs1)),
    X3 is X1 + 1,
    X4 is X1 - 1,
    not(member([X3,Y1],Cs1)),
    not(member([X4,Y1],Cs1)),
    !.

cria_rota([X1,Y1],[X2,Y2],R):-
    X1>1,
    anguloentre([X1,Y1],[X2,Y2],180),
    X3 is X1 - 1,
    copia_seguras(Cs),
    subtract(Cs,[[X1,Y1]],Cs1),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(Cs1)),
    member([X3,Y1],Cs1),
    !,
    cria_rota([X3,Y1],[X2,Y2],R1),
    append([[X1,Y1]],R1,R).

cria_rota([X1,Y1],[X2,Y2],R):-
    X1<5,
    anguloentre([X1,Y1],[X2,Y2],0),
    X3 is X1 + 1,
    copia_seguras(Cs),
    subtract(Cs,[[X1,Y1]],Cs1),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(Cs1)),
    member([X3,Y1],Cs1),
    !,
    cria_rota([X3,Y1],[X2,Y2],R1),
    append([[X1,Y1]],R1,R).

cria_rota([X1,Y1],[X2,Y2],R):-
    Y1>1,
    anguloentre([X1,Y1],[X2,Y2],270),
    Y3 is Y1-1,
    copia_seguras(Cs),
    subtract(Cs,[[X1,Y1]],Cs1),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(Cs1)),
    member([X1,Y3],Cs1),
    !,
    cria_rota([X1,Y3],[X2,Y2],R1),
    append([[X1,Y1]],R1,R).

cria_rota([X1,Y1],[X2,Y2],R):-
    Y1<5,
    anguloentre([X1,Y1],[X2,Y2],90),
    Y3 is Y1+1,
    copia_seguras(Cs),
    subtract(Cs,[[X1,Y1]],Cs1),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(Cs1)),
    member([X1,Y3],Cs1),
    !,
    cria_rota([X1,Y3],[X2,Y2],R1),
    append([[X1,Y1]],R1,R).

cria_rota([X1,Y1],[X2,Y2],R):-
    Y1<5,
    anguloentre([X1,Y1],[X2,Y2],90),
    Y3 is Y1+1,
    copia_seguras(Cs),
    subtract(Cs,[[X1,Y1]],Cs1),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(Cs1)),
    not(member([X1,Y3],Cs1)),
    X3 is X1 +1,
    X4 is X1 -1,
    !,
    cria_rota([X3,Y1],[X2,Y2],R1),
    cria_rota([X4,Y1],[X2,Y2],R2),
    length(R1,Tamanho1),
    length(R2,Tamanho2),
    (Tamanho1>Tamanho2,member([X2,Y2],R2),ListaCaminho = R2,!;
    Tamanho1<Tamanho2,member([X2,Y2],R1),ListaCaminho = R1;
    Tamanho1>Tamanho2,not(member([X2,Y2], R2)),member([X2,Y2],R1),ListaCaminho=R1;
    Tamanho1<Tamanho2,not(member([X2,Y2],R1)),member([X2,Y2],R2),ListaCaminho=R2;
    not(member([X2,Y2],R1)),not(member([X2,Y2], R2)),ListaCaminho=[]),
    append([[X1,Y1]],ListaCaminho,R).

cria_rota([X1,Y1],[X2,Y2],R):-
    X1<5,
    anguloentre([X1,Y1],[X2,Y2],0),
    X3 is X1 +1,
    copia_seguras(Cs),
    subtract(Cs,[[X1,Y1]],Cs1),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(Cs1)),
    not(member([X3,Y1],Cs1)),
    Y3 is Y1 +1,
    Y4 is Y1 -1,
    !,
    cria_rota([Y3,Y1],[X2,Y2],R1),
    cria_rota([Y4,Y1],[X2,Y2],R2),
    length(R1,Tamanho1),
    length(R2,Tamanho2),
   (Tamanho1>Tamanho2,member([X2,Y2],R2),ListaCaminho = R2,!;
    Tamanho1<Tamanho2,member([X2,Y2],R1),ListaCaminho = R1;
    Tamanho1>Tamanho2,not(member([X2,Y2], R2)),member([X2,Y2],R1),ListaCaminho=R1;
    Tamanho1<Tamanho2,not(member([X2,Y2],R1)),member([X2,Y2],R2),ListaCaminho=R2;
    not(member([X2,Y2],R1)),not(member([X2,Y2], R2)),ListaCaminho=[]),
    append([[X1,Y1]],ListaCaminho,R).

cria_rota([X1,Y1],[X2,Y2],R):-
    X1>1,
    anguloentre([X1,Y1],[X2,Y2],180),
    X3 is X1 - 1,
    copia_seguras(Cs),
    subtract(Cs,[[X1,Y1]],Cs1),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(Cs1)),
    not(member([X3,Y1],Cs1)),
    Y3 is Y1 +1,
    Y4 is Y1 -1,
    !,
    cria_rota([Y3,Y1],[X2,Y2],R1),
    cria_rota([Y4,Y1],[X2,Y2],R2),
    length(R1,Tamanho1),
    length(R2,Tamanho2),
   (Tamanho1>Tamanho2,member([X2,Y2],R2),ListaCaminho = R2,!;
    Tamanho1<Tamanho2,member([X2,Y2],R1),ListaCaminho = R1;
    Tamanho1>Tamanho2,not(member([X2,Y2], R2)),member([X2,Y2],R1),ListaCaminho=R1;
    Tamanho1<Tamanho2,not(member([X2,Y2],R1)),member([X2,Y2],R2),ListaCaminho=R2;
    not(member([X2,Y2],R1)),not(member([X2,Y2], R2)),ListaCaminho=[]),
    append([[X1,Y1]],ListaCaminho,R).

cria_rota([X1,Y1],[X2,Y2],R):-
    Y1>1,
    anguloentre([X1,Y1],[X2,Y2],270),
    Y3 is Y1 - 1,
    copia_seguras(Cs),
    subtract(Cs,[[X1,Y1]],Cs1),
    retractall(copia_seguras(_)),
    asserta(copia_seguras(Cs1)),
    not(member([X1,Y3],Cs1)),
    X3 is X1 +1,
    X4 is X1 -1,
    !,
    cria_rota([X3,Y1],[X2,Y2],R1),
    cria_rota([X4,Y1],[X2,Y2],R2),
    length(R1,Tamanho1),
    length(R2,Tamanho2),
   (Tamanho1>Tamanho2,member([X2,Y2],R2),ListaCaminho = R2,!;
    Tamanho1<Tamanho2,member([X2,Y2],R1),ListaCaminho = R1;
    Tamanho1>Tamanho2,not(member([X2,Y2], R2)),member([X2,Y2],R1),ListaCaminho=R1;
    Tamanho1<Tamanho2,not(member([X2,Y2],R1)),member([X2,Y2],R2),ListaCaminho=R2;
    not(member([X2,Y2],R1)),not(member([X2,Y2], R2)),ListaCaminho=[]),
    append([[X1,Y1]],ListaCaminho,R).

% Calcula o angulo entre duas coordenadas
anguloentre([X1,Y1],[X2,Y2],Angulo1):-
    (not(X1=X2),not(Y1=Y2),
    Tangente is(Y2-Y1)/(X2-X1),
    Angulo_em_rad is atan(Tangente),
    Angulo is (((truncate(180*Angulo_em_rad/pi)) + 360) mod 360),
    Angulo =<45,
    ((X2>X1,
    Angulo1=0);
    (X2<X1,
    Angulo1=180)));
    (Y1=Y2,
    X2 > X1,
    Angulo1=0),
    !.

anguloentre([X1,Y1],[X2,Y2],Angulo1):-
   (not(X1=X2),not(Y1=Y2),
    Tangente is (Y2-Y1)/(X2-X1),
    Angulo_em_rad is atan(Tangente),
    Angulo is (((truncate(180*Angulo_em_rad/pi)) + 360) mod 360),
    Angulo >45,
    Angulo =< 135,
    ((Y2>Y1,
    Angulo1=90);
    (Y2<Y1,
    Angulo1=270)));
    (X1=X2,
    Y2 > Y1,
    Angulo1=90),
    !.

anguloentre([X1,Y1],[X2,Y2],Angulo1):-
    (not(X1=X2),not(Y1=Y2),
    Tangente is(Y2-Y1)/(X2-X1),
    Angulo_em_rad is atan(Tangente),
    Angulo is (((truncate(180*Angulo_em_rad/pi)) + 360) mod 360),
    Angulo >135,
    Angulo =< 225,
    ((X2>X1,
    Angulo1=0);
    (X2<X1,
    Angulo1=180)));
    (Y1=Y2,
    X2 < X1,
    Angulo1=180),
    !.

anguloentre([X1,Y1],[X2,Y2],Angulo1):-
    (not(X1=X2),not(Y1=Y2),
    Tangente is(Y2-Y1)/(X2-X1),
    Angulo_em_rad is atan(Tangente),
    Angulo is (((truncate(180*Angulo_em_rad/pi)) + 360) mod 360),
    Angulo >225,
    Angulo =< 315,
    ((Y2>Y1,
    Angulo1=90);
     (Y2<Y1,
    Angulo1=270)));
    (X1=X2,
    Y2 < Y1,
    Angulo1=270),
    !.

anguloentre([X1,Y1],[X2,Y2],Angulo1):-
    not(X1=X2),not(Y1=Y2),
    Tangente is (Y2-Y1)/(X2-X1),
    Angulo_em_rad is atan(Tangente),
    Angulo is (((truncate(180*Angulo_em_rad/pi)) + 360) mod 360),
    Angulo >315,
    Angulo =< 360,
    ((X2>X1,
    Angulo1=0);
    (X2<X1;
    Angulo1=180)).


/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */

