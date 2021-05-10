% Árvore genealogica ex1 primeiro programa em prolog.

 homem(paulo).
 homem(yure).
 homem(alexandre).
 homem(alex).
 homem(valdemar).
 mulher(bruna).
 mulher(athalis).
 mulher(beline).
 mulher(caroli).
 mulher(ana).
 mulher(mabel).
 mulher(maria).
 mulher(yume).

casado(paulo,mabel).
 casado(sandro,ana).
 casado(valdemar,athalis).
 casado(yure,maria).
 casada(mabel, paulo).
 casada(ana,sandro).
 casada(maria, yure).
 casada(athalis,valdemar).

progenitor(paulo,ana).
progenitor(paulo,valdemar).
progenitor(paulo,yure).
progenitor(mabel,ana).
progenitor(mabel,valdemar).
progenitor(mabel,yure).
progenitor(alexandre,bruna).
progenitor(alexandre,alex).
progenitor(ana,bruna).
progenitor(ana,alex).
progenitor(valdemar,beline).
progenitor(valdemar,caroli).
progenitor(athalis,beline).
progenitor(athalis,caroli).
progenitor(yure,yume).
progenitor(maria,yume).

pai(X,Y):-progenitor(X,Y),homem(X).
mae(X,Y):-progenitor(X,Y),mulher(X).

filho(X,Y):-progenitor(Y,X),homem(X).
filha(X,Y):-progenitor(Y,X),mulher(X).

irmao(X,Y):-progenitor(P,X),progenitor(P,Y),X\=Y,homem(X).
irma(X,Y):-progenitor(P,X),progenitor(P,Y),X\=Y,mulher(X).






