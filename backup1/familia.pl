
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

irmao(X,Y):-progenitor(P,X),progenitor(P,Y),X\=Y,homem(X).
irma(X,Y):-progenitor(P,X),progenitor(P,Y),X\=Y,mulher(X).

tio(X,Y):-progenitor(P,X),progenitor(P,Z),progenitor(Z,Y),X\=Z,homem(X).
tia(X,Y):-progenitor(P,X),progenitor(P,Z),progenitor(Z,Y),X\=Z,mulher(X).

avo(X,Y):-progenitor(X,Z),progenitor(Z,Y),homem(X).
ava(X,Y):-progenitor(X,Z),progenitor(Z,Y),mulher(X).

neto(X,Y):-progenitor(Y,Z),progenitor(Z,X),homem(X).
neta(X,Y):-progenitor(Y,Z),progenitor(Z,X),mulher(X).

sobrinho(X,Y):-progenitor(W,Y),progenitor(W,Z),progenitor(Z,X),Y\=Z,homem(X).
sobrinha(X,Y):-progenitor(W,Y),progenitor(W,Z),progenitor(Z,X),Y\=Z,mulher(X).

primo(X,Y):-progenitor(P,T),progenitor(P,U),progenitor(T,Y),progenitor(U,X),T\=U,homem(X).
prima(X,Y):-progenitor(P,T),progenitor(P,U),progenitor(T,Y),progenitor(U,X),T\=U,mulher(X).
