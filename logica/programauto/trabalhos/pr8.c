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
#include<math.h>
#include<string.h>
#include<time.h>


int main(void)
{
  int i = 0, j = 0;
  int  matriz[3][3] = {0};
      

   printf("digite valores para a matriz 3x3 \n");

  for(i = 0; i < 3; i++)
  {
        for(j = 0; j < 3;j++)
        {
            scanf("%d", &matriz[i][j]);
        
        
        }

      printf("\n");

  }
 
   printf("\n");
   printf("a sua matriz eh \n");


    for(i = 0; i < 3; i++)
  {
        for(j = 0; j < 3;j++)
        {
            printf(" %d",matriz[i][j]);

        }

      printf("\n");

  }

   
    

    int princi =  (matriz[0][0] * matriz[1][1] * matriz[2][2]) + (matriz[0][1] *  matriz[1][2] *  matriz[2][0]) +  (matriz[1][0] *  matriz[2][1] *  matriz[0][2]);
   
    int secun = (matriz[2][0] * matriz[1][1] * matriz[0][2]) + (matriz[1][0] *  matriz[0][1] *  matriz[2][2]) +  (matriz[2][1] *  matriz[1][2] *  matriz[0][0]);

    
    int det = princi - secun;

    printf("\n");
    printf("o determinante eh  %d\n", det);




  return 0;
}



