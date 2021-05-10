
goal(Hs) :-
    length(Hs, 3),
    member(h(_,rosa,anel), Hs),
    member(h(amanda,vermelho,_), Hs),
    member(h(jussara,_,relogio), Hs),
    member(h(_,rosa,_), Hs),
    member(h(_,azul,_), Hs),
    member(h(_,_,pulsera), Hs),
    member(h(kelly,_,_), Hs),!.

