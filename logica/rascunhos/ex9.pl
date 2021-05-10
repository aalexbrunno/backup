/* *********************************************************************** *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *  Copyright (C) 2021 by Alex Bruno Seabra                                 *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *  To contact the author, please write to:                                 *
 *  Name: Alex Bruno Seabra <aalexbrunno@gmail.com>                         *
 *  Webpage: http://beco.poli.br/~username                                  *
 *  Phone: (81) 98735-8802                                                  *
 * ************************************************************************ *
 * 
 */

                         %Texto

/* tres mulheres Amanda,  Kelly e Jussara pintaram suas mãos e usaram um acessorio no ultimo sábado
quando foram sair com as amigas. */

% mulheres: Amanda,Kelly e Jussara.
% cor do esmalte: rosa, azul,vermelho.
% acessorio: anel, pulsera, relógio.




%regra 1: Uma das garotas pintou as unhas com esmalte cor de rosa e usou um anel.
%regra 2: Amanda usou esmalte vermelho para pintar as unhas.
%regra 3: jussara usou um relógio moderno como acessorio.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Fatos
esmalte(azul).
esmalte(rosa).
esmalte(vermelho).
nome(amanda).
nome(jussara).
nome(kelly).
acessorio(anel).
acessorio(pulsera).
acessorio(relogio).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Inferencia:
goal :-
        tudodiferente(Amanda,AmaEsmalte,AmaAcessorio,Jussara,JusEsmalte,JusAcessorio,Kelly,KelEsmalte,KelAcessorio),
        tab(Amanda,AmaEsmalte,AmaAcessorio,Jussara,JusEsmalte,JusAcessorio,Kelly,KelEsmalte,KelAcessorio),
        writeln('\nResultado'),
        writef('%w %w %w\n',[Amanda,AmaEsmalte,AmaAcessorio]),
        writef('%w %w %w\n',[Jussara,JusEsmalte,JusAcessorio]),
        writef('%w %w %w\n',[Kelly,KelEsmalte,KelAcessorio]),!.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% testa uma solucao para todas as regras
tab(Amanda,AmaEsmalte,AmaAcessorio,Jussara,JusEsmalte,JusAcessorio,Kelly,KelEsmalte,KelAcessorio) :-
        regra1(Amanda,AmaEsmalte,AmaAcessorio,Jussara,JusEsmalte,JusAcessorio,Kelly,KelEsmalte,KelAcessorio),
        regra2(Amanda,AmaEsmalte,AmaAcessorio,Jussara,JusEsmalte,JusAcessorio,Kelly,KelEsmalte,KelAcessorio),
        regra3(Amanda,AmaEsmalte,AmaAcessorio,Jussara,JusEsmalte,JusAcessorio,Kelly,KelEsmalte,KelAcessorio).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% pega um de cada, fixa as variaveis numa possivel solucao com tudo diferente
tudodiferente(Amanda,AmaEsmalte,AmaAcessorio,Jussara,JusEsmalte,JusAcessorio,Kelly,KelEsmalte,KelAcessorio) :-
       nome(Amanda),
       nome(Jussara),
       not(Amanda=Jussara),
       nome(Kelly),
       not(Amanda=Kelly),
       not(Jussara=Kelly),
       esmalte(AmaEsmalte),
       esmalte(JusEsmalte),
       not(AmaEsmalte=JusEsmalte),
       esmalte(KelEsmalte),
       not(AmaEsmalte=KelEsmalte),
       not(JusEsmalte=KelEsmalte),
       acessorio(AmaAcessorio),
       acessorio(JusAcessorio),
       not(AmaAcessorio=JusAcessorio),
       acessorio(KelAcessorio),
       not(AmaAcessorio=KelAcessorio),
       not(JusAcessorio=KelAcessorio).
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%regra 1: Uma das garotas pintou as unhas com esmalte cor de rosa e usou um anel.
regra1(_, rosa,anel, _,_,_, _, _, _).
        
regra1(_, _,_, _,rosa,anel, _,_,_).

regra1(_, _,_, _,_,_, _,rosa,anel).


%regra 2: Amanda usou esmalte vermelho para pintar as unhas.
regra2(amanda,vermelho,_, _,_,_, _,_,_).


%regra 3: jussara usou um relógio moderno como acessorio.
regra3(_, _,_,jussara,_,relogio, _,_,_).


/*
 as regras para resolução de outra revista

 nome(carlos).
 nome(luis).
 nome(paulo).

 profissao(medico).
 profissao(engenheiro).
 profissao(advogado).

 esposa(lucia).
 esposa(patricia).
 esposa(maria).

 
 
 
 %regra1: o médico é casado com Maria.
 
 regra1(_,medico,maria,_,_,_,_,_,_).
 regra1(_,_,_,_,medico,maria,_,_,_).
 regra1(_,_,_,_,_,_,_,medico,maria).

 %regra2: paulo é advogado.
 
 regra2(_,_,_,_,_,_,paulo,advogado,_).

 
 %regra3: patricia não é casada com paulo.
 regra3(carlos,_,patricia,_,_,_,_,_,_).
 regra3(_,_,_,luis,_,patricia,_,_,_).

 %regra4: Carlos não é médico.
  regra4(carlos,engenheiro,_,_,_,_,_,_,_).
  regra4(carlos,advogado,_,_,_,_,_,_,_).




 */
 




