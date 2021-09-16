:-dynamic([soco/2, caixa/2]).

objetivo(3,4).

parede(0,2).
parede(X,_):-
    X<0.
parede(X,_):-
    X>4.
parede(_,Y):-
    Y<0.
parede(_,Y):-
    Y>4.

livre(X, Y):-
    not(parede(X,Y)).

imprime:-
    soko(SX,SY),
    caixa(CX,CY),
    format('soko(~w,~w) e caixa(~w,~w)\n',[SX,SY,CX,CY]).

start:-
    retractall(soko(_,_)),
    retractall(caixa(_,_)),
    assert(soko(2,2)),
    assert(caixa(1,2)),
    imprime.
%linha de comando para guando chegar ao objetivo
ganhou:-
    caixa(X,Y),
    objet
