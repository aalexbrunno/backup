
%autor Alex Bruno Seabra
% Árvore genealogica ex1 primeiro programa em prolog.

homem(thiago).
homem(nitinho).
homem(lucas).
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
mulher(vania).
mulher(marlene).
mulher(vitoria).
mulher(carol).




casado(paulo,mabel).
casado(sandro,ana).
casado(valdemar,athalis).
casado(yure,maria).
casado(mabel, paulo).
casado(ana,sandro).
casado(maria, yure).
casado(athalis,valdemar).
casado(nitinho,vania).
casado(vania,nitinho).
casado(thiago,marlene).
casado(marlene,thiago).

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
progenitor(marlene,alexandre).
progenitor(marlene,vania).
progenitor(thiago,vania).
progenitor(nitinho,lucas).
progenitor(nitinho,vitoria).
progenitor(nitinho,carol).
progenitor(vania,lucas).
progenitor(vania,vitoria).
progenitor(vania,carol).
progenitor(thiago,alexandre).





diferente(X,Y):-X\=Y.

%pai(X,Y):-progenitor(X,Y),homem(X).
%mae(X,Y):-progenitor(X,Y),mulher(X).

pai(X,Y) :-
    homem(X),
    progenitor(X,Y).


mae(X,Y) :-
    mulher(X),
    progenitor(X,Y).

%filho(X,Y):-progenitor(Y,X),homem(X).
%filha(X,Y):-progenitor(Y,X),mulher(X).

filho(X,Y) :-
    homem(X),
    progenitor(Y,X).

filha(X,Y) :-
    mulher(X),
    progenitor(Y,X).


%irmao(X,Y):-progenitor(P,X),progenitor(P,Y),X\=Y,homem(X).
%irma(X,Y):-progenitor(P,X),progenitor(P,Y),X\=Y,mulher(X).

irmao(X,Y) :-
    homem(X),
    pai(Z,X),
    pai(Z,Y),
    diferente(X,Y).

irma(X,Y) :-
     mulher(X),
     pai(Z,X),
     pai(Z,Y),
     diferente(X,Y).

%tio(X,Y):-progenitor(P,X),progenitor(P,Z),progenitor(Z,Y),X\=Z,homem(X);casado(X,Z),progenitor(P,Z),progenitor(P,T),progenitor(T,Y),Z\=T.
%tia(X,Y):-progenitor(P,X),progenitor(P,T),progenitor(T,Y),X\=T,mulher(X);casada(X,Z),progenitor(P,Z),progenitor(P,T),progenitor(T,Y),Z\=T.

%tio(X,Y):-irmao(X,A),progenitor(A,Y).
%tia(X,Y):-irma(X,A),progenitor(A,Y).

%tio(X,Y) :-
%    homem(X),
%    progenitor(Z,Y),
%    irmao(X,Z).
    %; homem(X),
    %progenitor(Z,Y),
    %irma(X,Z).

%tia(X,Y) :-
%    mulher(X),
%    progenitor(Z,Y),
%    irma(X,Z).
    %; mulher(X),
    %progenitor(Z,Y),
    %irma(X,Z).

tio(X,Y) :-
     homem(X),
     progenitor(Z,Y),
     irmao(X,Z);
     homem(X),
     casado(X,Z),
     irmao(Z,T),
     progenitor(T,Y),
     diferente(Z,T).

 
 
 
 tia(X,Y) :-
    mulher(X),
    progenitor(Z,Y),
    irma(X,Z);
    mulher(X),
    casado(X,Z),
    irmao(Z,T),
    progenitor(T,Y),
    diferente(Z,T).




%avoo(X,Y):-progenitor(X,Z),progenitor(Z,Y),homem(X).
%avoa(X,Y):-progenitor(X,Z),progenitor(Z,Y),mulher(X).

 avoo(X,Y) :-
    homem(X),
    progenitor(X,Z),
    progenitor(Z,Y).
     

 avoa(X,Y) :-
     mulher(X),
     progenitor(X,Z),
    progenitor(Z,Y).



 %neto(X,Y):-progenitor(Y,Z),progenitor(Z,X),homem(X).
 %neta(X,Y):-progenitor(Y,Z),progenitor(Z,X),mulher(X).

neto(X,Y) :-
    homem(X),
    progenitor(Y,Z),
    progenitor(Z,X).

neta(X,Y) :-
    mulher(X),
    progenitor(Y,Z),
    progenitor(Z,X).



%sobrinho(X,Y):-progenitor(W,Y),progenitor(W,Z),progenitor(Z,X),Y\=Z,homem(X).
%sobrinha(X,Y):-progenitor(W,Y),progenitor(W,Z),progenitor(Z,X),Y\=Z,mulher(X).


% sobrinho(X,Y) :-
%     homem(X),
%     irmao(Y,Z),
%     progenitor(Z,X),
%     diferente(Y,Z);
%     homem(X),
%     irma(Y,Z),
%     progenitor(Z,X),
%     diferente(Y,Z).

% sobrinha(X,Y) :-
%     mulher(X),
%     irmao(Y,Z),
%     progenitor(Z,X),
%     diferente(Y,Z);
%     mulher(X),
%     irma(Y,Z),
%     progenitor(Z,X),
%     diferente(Y,Z).


sobrinho(X,Y) :-
    homem(X),
    irmao(Y,Z),
    progenitor(Z,X),
    diferente(Y,Z);
    homem(X),
    casado(Y,Z),
    irmao(Z,T),
    progenitor(T,X),
    diferente(Z,T).




sobrinha(X,Y) :-
     mulher(X),
     irmao(Y,Z),
     progenitor(Z,X),
     diferente(Y,Z);
     mulher(X),
     casado(Y,Z),
     irmao(Z,T),
     progenitor(T,X),
     diferente(Z,T).


 %primo(X,Y):-progenitor(P,T),progenitor(P,U),progenitor(T,Y),progenitor(U,X),T\=U,homem(X).
 %prima(X,Y):-progenitor(P,T),progenitor(P,U),progenitor(T,Y),progenitor(U,X),T\=U,mulher(X).
                                                                              
 %primo(X,Y) :-
 %    homem(X),
 %   progenitor(T,Y),
 %   progenitor(U,X),
 %   irmao(T,U),
 %   diferente(T,U).

 % prima(X,Y) :-
 % mulher(X),
 % progenitor(T,Y),
 % progenitor(U,X),
 % irmao(T,U),
 % diferente(T,U).

     % primo(X,Y) :-
     %homem(X),
     %irmao(T,U),
     %progenitor(T,Y),
     %progenitor(U,X),
     %diferente(T,U). 
 
  % prima(X,Y) :-
  %  mulher(X),
  %  irmao(T,U),
  %  progenitor(T,Y),
  %  progenitor(U,X),
  %  diferente(T,U).




  % prima(X,Y) :-
  %   mulher(X),
  %  avoo(Z, X),
  %  avoo(Z, Y),
  %  diferente(X, Y),
  %  not(irma(X, Y)),
  %  not(irmao(X,Y)).
 
     
  %primo(X,Y) :-
  %  homem(X),
  %  avoo(Z, X),
  %  avoo(Z, Y),
  %  diferente(X, Y),
  %  not(irmao(X, Y)),
  %  not(irma(X,Y)).
  
  % prima(X, Y):-
  %  X \= Y,
  %  mulher(X),
  %  not(irmao(X, Y)),
  %  !,
  %  tio(Z, X),
  %  tia(Z, X),
  %  !,
  %  progenitor(Z, Y).



 prima(X, Y):-
	X \= Y,
	mulher(X),
	not(irmao(X, Y)),
	not(irma(X,Y)),
    !,
	(tio(Z, X);
	tia(Z, X)),
	progenitor(Z, Y).
    %	!.
 
 
 
 
 
 
 
 
 
 
 
 % primo(X, Y):-
 %   X =/= Y,
 %   homem(X),
 %   not(irmao(X, Y)),
 %   not(irma(X, Y)),
 %    !,
 %   tio(Z, X);
 %   tia(Z, X),
 %   progenitor(Z, Y)
 %   !.

 
 
 
 
 
 
 
 
 
 
 
 
 %prima(X,Y) :-
 %  mulher(X),
 %  irmao(T,U),
 %  progenitor(T,X),
 %  progenitor(U,Y),
 %  diferente(X,Y).


 %primo(X,Y) :-
 %  homem(X),
 %  irmao(T,U),
 %  progenitor(T,X),
 %  progenitor(U,Y),
 %  diferente(X,Y).



