
% h(Nacionalidade, Animal de estimação, Cigarro, Bebida, Cor)

goal(Hs) :-
   length(Hs, 5),
   Hs = [h(noruegues,_,_,_,_)|_],
   member(h(ingles,_,_,_,vermelho),Hs),
   member(h(sueco,cachorro,_,_,_),Hs),
   member(h(dinamarques,_,_,cha,_),Hs),
   next(h(_,_,_,_,verde), h(_,_,_,_,branca), Hs),
   member(h(_,_,_,cafe,verde),Hs),
   member(h(_,passaros,pall_mall,_,_),Hs),
   member(h(_,_,dunhill,_,amarela),Hs),
   Hs = [_,_,h(_,_,_,leite,_),_,_],
   next(h(_,_,blends,_,_), h(_,gato,_,_,_), Hs),
   next(h(_,_,dunhill,_,_), h(_,cavalo,_,_,_), Hs), 
   member(h(_,_,bluemaster,cerveja,_),Hs),
   member(h(alemao,_,prince,_,_),Hs),
   next(h(noruegues,_,_,_,_), h(_,_,_,_,azul), Hs),
   next(h(_,_,blends,_,_), h(_,_,_,agua,_), Hs),
   member(h(_,peixe,_,_,_), Hs),!.
   
   
   
   next(A, B, Ls) :- append(_, [A,B|_], Ls).
   next(A, B, Ls) :- append(_, [B,A|_], Ls).


