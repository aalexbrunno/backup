/***************************************************************************
 *   exN.pl                                   Version 20210506.215656      *
 *                                                                         *
 *   Harry Potter and the Sorcerers Stone                                  *
 *   Copyright (C) 2021         by Alex Bruno Seabra                       *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Nome Completo                                                         *
 *   Email: email@dominio.ext                                              *
 *   Webpage: http://beco.poli.br/username                                 *
 *   Phone: (81) 00000-0000                                                *
 ***************************************************************************/


/* ---------------------------------------------------------------------- */
% Harry abriu a porta seguinte, os dois mal se atreviam a olhar o que vinha a seguir,
% mas nao havia nada muito assustador ali, apenas uma mesa e sobre ela sete garrafas
% de formatos diferentes.
% — E o de Snape — disse Harry. — O que temos de fazer?
% Ao cruzarem a soleira da porta, imediatamente irromperam chamas atras deles. 
% E nao eram chamas comuns tampouco, eram roxas. 
% Ao mesmo tempo, surgiam chamas pretas na porta adiante. Estavam encurralados.
% — Olhe! — Hermione apanhou um rolo de papel que havia ao lado das garrafas. 
% Harry espiou por cima do seu ombro para ler o papel:
%
% O perigo o aguarda a frente, a seguranca ficou atras,
% Duas de nos o ajudaremos no que quer encontrar,
% Uma dos sete o deixara prosseguir,
% A outra levara de volta quem a beber,
% Duas de nos conterao vinho de urtigas,
% Tres de nos guardam a morte certa,
% Escolha, ou, ficara aqui para sempre,
% E para ajuda-lo, lhe damos quatro pistas:
% 
% 1. por mais dissimulado que seja o veneno,
%    voce sempre encontrara um a esquerda do vinho de urtigas;
% 2. sao diferentes as garrafas de cada extremidade,
%    mas, se voce quiser avancar nenhuma delas e sua amiga;
% 3. Sendo visivel que temos tamanhos diferentes,
%    nem a ana nem a gigante leva a morte no bojo;
% 4. a segunda a esquerda e a segunda a direita
%    sao gemeas ao paladar, embora diferentes a vista.
%
% Hermione deixou escapar um grande suspiro e Harry, perplexo, viu que ela sorria, 
% a ultima coisa que ele tinha vontade de fazer
% — Genial — disse — Isto nao e magica, e logica... 
%
% Alem disso, a descricao da mesa eh a seguinte, 
% da esquerda para a direita, as garrafas sao:
%
% cilindrica, gigante, ana, fina, quadrada, estranha, redonda

/* ---------------------------------------------------------------------- */
% Representa cada poção como um elemento de uma lista
%  Cada elemento da lista e uma bebida, categorizada em:
%  * veneno   : mata quem o bebe
%  * vinho    : horrivel vinho de urtigas
%  * volta    : transporta quem o bebe para a sala anterior
%  * continua : transporta quem o bebe para a proxima sala


/* ---------------------------------------------------------------------- */
% Fatos: os conteudos das garrafas.



garrafa(veneno).
garrafa(vinho).
garrafa(volta).
garrafa(continua).




/* ---------------------------------------------------------------------- */
goal :-
    tab(Cilindrica, Gigante, Ana, Fina, Quadrada, Estranha, Redonda),
    writeln('\nResolucao'),
        writef('_________________________\n'),
        writef('||Cilindrica:   %w\n',[Cilindrica]),
        writef('||Gigante:      %w\n',[Gigante]),
        writef('||Ana:          %w\n',[Ana]),
        writef('||Fina:         %w\n',[Fina]),
        writef('||Quadrada:     %w\n',[Quadrada]),
        writef('||Estranha:     %w\n',[Estranha]),
        writef('||Redonda:      %w\n',[Redonda]),
        writef('||_____________________'),!.



   



/* ---------------------------------------------------------------------- */
tab(Cilindrica, Gigante, Ana, Fina, Quadrada, Estranha, Redonda) :-
    regra1(Cilindrica, Gigante, Ana, Fina, Quadrada, Estranha, Redonda),
    regra2(Cilindrica, Gigante, Ana, Fina, Quadrada, Estranha, Redonda),
    regra3(Cilindrica, Gigante, Ana, Fina, Quadrada, Estranha, Redonda),
    regra4(Cilindrica, Gigante, Ana, Fina, Quadrada, Estranha, Redonda).


/* ---------------------------------------------------------------------- */
% Regra1 O veneno so pode estar ao lado esquerdo do vinho de urtigas

regra1(veneno,veneno,vinho,_,_,_,_).
regra1(_,veneno,veneno,vinho,_,_,_).
regra1(_,_,veneno,veneno,vinho,_,_).
regra1(_,_,_,veneno,veneno,vinho,_).
regra1(_,_,_,_,veneno,veneno,vinho).
regra1(veneno,vinho,_,_,_,_,_).                                        
regra1(_,veneno,vinho,_,_,_,_).
regra1(_,_,veneno,vinho,_,_,_).
regra1(_,_,_,veneno,vinho,_,_).
regra1(_,_,_,_,veneno,vinho,_).                                       
regra1(_,_,_,_,_,veneno,vinho).


/* ---------------------------------------------------------------------- */
% Regra2: Nem a primeira nem a ultima garrafa contem o continuar

regra2(veneno,_,_,_,_,_,volta).
regra2(veneno,_,_,_,_,_,vinho).
regra2(volta,_,_,_,_,_,vinho).


/* ---------------------------------------------------------------------- */
% Regra3: Nem a garrafa Ana nem a garrafa Gigante contem o veneno
 
regra3(_,vinho,continua,_,_,_,_).
regra3(_,vinho,volta,_,_,_,_).
regra3(_,continua,volta,_,_,_,_).
regra3(_,volta,continua,_,_,_,_).


/* ---------------------------------------------------------------------- */
% Regra4: A segunda e a penultima garrafa tem o mesmo conteudo

regra4(_,volta,_,_,_,volta,_).
regra4(_,continua,_,_,_,continua,_).
regra4(_,veneno,_,_,_,veneno,_).
regra4(_,vinho,_,_,_,vinho,_).


/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */

