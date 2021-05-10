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
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)

{

//int a = 10,b = 20;
//int *p;
//int vetor[10] = {0};

/*
p = &a;
//*p = b;

printf("o valor do endero de a eh %p\n", p);
printf("o conteudo de a eh %d\n", *p);


printf("\n");


//printf("o valor eh %li\n", sizeof(vetor)/4); //quando usamos o sizeof desse jeito ele diz o tamanho do vetor
*/


int *p;
p = (int *) calloc(5, sizeof(int));
//*p = 10;

//printf("%d",*p); 

int i =0;

for(i =0; i < 5; i++)
{
    printf("endereco de p%i = %p | valor de p%i = %i\n", i, (p+i),i, *(p+i));
}












return 0;
}





