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
#include <math.h>
#include <stdlib.h>

float raiz (float x);


int main(void) {
    float x;

    raiz(x);


 return 0;
}



float raiz (float x)
{
   float a,b,c;

   printf("vamos calcular as raizes da função quadratica ax^2 + bx + c\n\n");

   printf("digite o valor de a\n");

    scanf("%f",&a);

    printf("digite o valor de b\n");

	scanf("%f",&b);

	printf("por fim digite o valor de c\n");
	scanf("%f",&c);


	int i;
     x = 1;

    float  r;

	r = b * b - 4 * a * c;

	for(i=1; i < 10; i++)

	{

	x = x - (  (x*x - r)/ (2*x));


	}

	float x1,x2;

	x1 = (-b + x) / (2*a);
	x2 = (-b - x) / (2*a);

    printf("o valor de x1 eh %f\n", x1);

    printf("o valor de x2 eh %f", x2);

	return x;

}

