setRote :-
    retractall(rote(_)),
    asserta(rote([])).

cria_rota([X,Y],[X1,Y1],RevList) :-
    setRote,
    verify_dist([X,Y],[X1,Y1]),
    rote(RevList).
    % reverse(L, RevList).

verify_dist([X,Y],[X1,Y1]) :-
    pos(X,X1,Rx1),
    pos(Y,Y1,Ry1),
    neg(X,X1,Rx2),
    neg(Y,Y1,Ry2),
    St is abs(Rx1)+abs(Rx2)+abs(Ry1)+abs(Ry2),
    St =\= 0,
    X2 is X+Rx1+Rx2,
    Y2 is Y+Ry1+Ry2,
    refreshRote([[X2,Y]]),
    refreshRote([[X2,Y2]]),
    verify_dist([X2,Y2],[X1,Y1]),!.
verify_dist([X,Y],[X,Y]).

pos(Ci,Cf,ResP) :-
    Ci < Cf,
    ResP is 1,!.
pos(_,_,0).

neg(Ci,Cf,ResP) :-
    Ci > Cf,
    ResP is -1,!.
neg(_,_,0).

refreshRote(New_coord) :-
    rote(Aux),
    retractall(rote(_)),
    union(Aux,New_coord,New_list),
    asserta(rote(New_list)).
