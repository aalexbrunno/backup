/***************************************************************************
 *   ex7.pl                                   Version 20210325.132404      *
 *                                                                         *
 *   exercicio 07                                                          *
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
 *   Alex Bruno Seabra                                                     *
 *   Email: aalexbrunno@gmail.com                                          *
 *   Webpage: http://beco.poli.br/aalexbrunno@gmail.com                                          username                                *
 *   Phone: (81) 98735-8802                                                *
 ***************************************************************************/


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief intersecção de listas 
 * @details pega duas listas e faz a intersecção de seus elementos 
 * @return a intersecção dos elementos das duas listas
 */
    
 interseccao([], _, []).
 interseccao([Head|L1tail], L2, L3) :-
         memberchk(Head, L2),
         !,
         L3 = [Head|L3tail],
         interseccao(L1tail, L2, L3tail).
 interseccao([_|L1tail], L2, L3) :-
         interseccao(L1tail, L2, L3).



/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */

