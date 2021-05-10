%regra 1: o tempo de infusao de nivea foi menor que o tempo de infusao do cha de camomila

%regra 2: bernadete tomou cha preto.

%regra 3: infusao de frutas vermelhas nao foi 2 min.


tudodif(T1,T2) :-
    not(T1 = T2),
    not(T1 = T3),
    not(T3 = T2),
    T1 < T2.




goal(Hs) :-
    length(Hs, 3),
    tudodif(h(nivea,T1,_), Hs),
    member(h(_,T2,camomila), Hs),
    member(h(bernadete,_,cha_preto), Hs),
    member(h(_,T3,frutas_vermelhas), Hs),
    not(T3 = 2),
    member(h(cecilia,_,_), Hs),
    member(h(_,1,_), Hs),
    member(h(_,2,_), Hs),
    member(h(_,3,_), Hs).

    


%tamanho :-
%     T1 < T2.






