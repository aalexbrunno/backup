

cria_rota(X2,Y2,X2,Y2,[]).

cria_rota(X1,Y1,X2,Y2,[R|Tail]):-
    DX is (X2 - X1),
    DX > 0,
    X3 is (X1 + 1),
    X3 =< X2,
    append([[X3,Y1]],R),
    cria_rota(X3,Y1,X2,Y2,Tail),
    !.

cria_rota(X1,Y1,X2,Y2,[R|Tail]):-
    DX is (X2 - X1),
    DX < 0,
    X3 is (X1 - 1),
    X3 >= X2,
    append([[X3,Y1]],R),
    cria_rota(X3,Y1,X2,Y2,Tail),
    !.

cria_rota(X1,Y1,X2,Y2,[R|Tail]):-
    DY is Y2 - Y1,
    DY > 0,
    Y3 is (Y1 + 1),
    Y3 =< Y2,
    append([[X1,Y3]],R),
    cria_rota(X1,Y3,X2,Y2,Tail),
    !.

cria_rota(X1,Y1,X2,Y2,[R|Tail]):-
    DY is Y2 - Y1,
    DY < 0,
    Y3 is (Y1 - 1),
    Y3 >= Y2,
    append([[X1,Y3]],R),
    cria_rota(X1,Y3,X2,Y2,Tail),
    !.



