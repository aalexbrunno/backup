
/*
start :-
    random_permutation([as,rei,rainha,valete],Lista), %  random_permutation predicato do prolog que permuta aleatoriamente os elementos de uma lista
    nth1(1,Lista,Elemento1), % nth1 predicato do prolog acessa os elementos de uma lista através dos indices que nesse caso  o indice comeca em 1  
    nth1(2,Lista,Elemento2), % o indice representa a posicao das cartas na lista [as,rei,rainha, valete]
    nth1(3,Lista,Elemento3), % ele armazena em uma variavel chamada  Elemento o valor correspondente ao indice que tem na lista que foi permutada aleatoriamente
    nth1(4,Lista,Elemento4),
    write('|'),
    write(Elemento1), % agora printa as variaveis para poder ver a nova ordem
    write('|'),
    write(Elemento2),
    write('|'),
    nl,
    write('|'),
    write(Elemento3),
    write('|'),
    write(Elemento4),
    write('|'),
    nl,
    sleep(3), % faz o programa esperar 3 segundos antes de iniciar o proximo comando
    cls, % comando que limpa a tela
    write('digite com numeros de 1 a 4 em qual posicao estao essas cartas respectivamente: As, Rei, Rainha, Valete'),
    nl,
    read(Numb), % recebe do usuario um numero correspondete a ordem exigida
    nth1(Numb,Lista,Elem1), % esse numero fica como indice pra acessar o valor correspondete na Lista permultada e guarda na variavel Elem1
    write(Elem1), % printa a variavel Elem1 para poder ver o que ela recebeu devido ao indice inserido
    nl,
    read(Numb2),
    nth1(Numb2,Lista,Elem2),
    write(Elem2),
    nl,
    read(Numb3),
    nth1(Numb3,Lista,Elem3),
    write(Elem3),
    nl,
    read(Numb4),
    nth1(Numb4,Lista,Elem4),
    write(Elem4),
    nl,
    (Elem1 = as, %ver se a variavel digitada pelo usuario é igual a As 
     Elem2 = rei,
     Elem3 = rainha,
     Elem4 = valete,
     write('voce ganhou ganhou'), % se tudo for satisfeito o usuario ganhou
     !);
     write('perdeu'). %caso contrario perdeu
     
cls :- write('\e[H\e[2J'). %predicato de limpar a tela

*/

elementos(as,1).
elementos(rei,2).
elementos(rainha,3).
elementos(valete,4).

random_elements(L,Rand_list,GabaritoFinal) :-
    random_permutation(L,Rand_list),
    nth1(Index1,Rand_list,as),
    nth1(Index2,Rand_list,rei),
    nth1(Index3,Rand_list,rainha),
    nth1(Index4,Rand_list,valete),
    append([Index1], [], Gabarito1),
    append([Index2], Gabarito1, Gabarito2),
    append([Index3], Gabarito2, Gabarito3),
    append([Index4], Gabarito3, Gabarito4),
    reverse(Gabarito4, GabaritoFinal).

% valete, rainha, as, rei
% -----------------------
% |  valete  |  rainha  |
% -----------------------
% |    as    |   rei    |
% -----------------------
%
print_elements([E1,E2,E3,E4],Level) :-
    horizontalSep,nl,
    verticalSep,
    elementVerify(E1),
    verticalSep,
    elementVerify(E2),
    verticalSep,nl,
    horizontalSep,nl,
    verticalSep,
    elementVerify(E3),
    verticalSep,
    elementVerify(E4),
    verticalSep,nl,
    horizontalSep,nl,
    sleep(Level),
    cls.

chooseLevel(Level) :-
    cls,
    write('*******************'),nl,
    write('* Jogo da memoria *'),nl,
    write('*******************'),nl,nl,
    write('escolha o nivel de dificuldade:'),nl,
    write('3. Facil'),nl,
    write('2. Medio'),nl,
    write('1. Dificil'),nl,
    read(Level),
    sleep(1),
    cls.

repete :-
    nl,nl,
    write('Quer jogar de novo? (y/n)'),nl,
    read(Resp),
    execute(Resp).

execute(R) :-
    R == 'y',
    start.

execute(_).

jogo(L,N,Lvazia,Resposta):-
    N1 is N+1,
    N1=<4,
    nth1(N1,L,Elem),
    write('escreva a posicao do(a): '),write(Elem),nl,
    read(Chute),
    append([Chute],Lvazia,NewList),
    jogo(L,N1,NewList,Resposta).

jogo(_,4,Lvazia,Resposta) :-
    append([],Lvazia,Resposta).

result(Resultado,Gabarito) :-
    reverse(Resultado,Resultado2),
    Resultado2 == Gabarito,nl,
    write('Acertou!').

result(_,_) :-
    nl,
    write('Errou!').

elementVerify(E) :-
    E == as,
    write('    as    ').

elementVerify(E) :-
    E == rei,
    write('   rei    ').

elementVerify(E) :-
    E == rainha,
    write('  rainha  ').

elementVerify(E) :-
    E == valete,
    write('  valete  ').

verticalSep :-
    write('|').

horizontalSep :-
    write('-----------------------').

cls :- write('\e[H\e[2J').

start:-
    chooseLevel(Level),
    random_elements([as,rei,rainha,valete],Rand_list,Gabarito),
    print_elements(Rand_list,Level),
    jogo([as,rei,rainha,valete],0,[],Resultado),
    result(Resultado,Gabarito),
    repete.



% compara(Chute,L) :-
%     nth1(Chute, L, Elem),
%     elementos(Elem,Num),
%     Num == Chute.






