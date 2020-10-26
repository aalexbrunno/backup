/* *********************************************************************** *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *  Copyright (C) 2020 by Alex Bruno Seabra                                 *
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

#include <stdio.h>
#include <string.h>

int main (void){
	
	
	int i, a = 0,soma =0, b = 0;
	char palavra[300];
	
     printf("digite algum caractere voce pode digitar ate 50 caractere\n\n");
 
     printf("parenteses abrindo '(' vale 1 e parenteses fechando')' vale -1 \n\n");
    
     //limpa o buffer do teclado
	setbuf(stdin, 0);
	
	//ler a string
	fgets(palavra, 300, stdin);
	
	//limpa as casas nao utilizadas na string
	palavra[strlen(palavra)-1] = '\0';
	
	for(i=0; i < 51; i++){
		
		if(palavra[i] == '('){
			
			a++;
			
		}
		
		else if(palavra[i] == ')')
	     {
	     	a--;
			 }	
	
	
	}
	
	soma = a  + soma;
	
	printf("o valor da soma eh: %d ", soma);
	
	
	
	
	return 0;
}


