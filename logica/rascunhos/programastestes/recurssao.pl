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


fat(0,1).
fat(N,F):- N > 0, N1 is N-1,fat(N1,F1),F is N * F1.
