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

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
   int arm[20] = {0};
   int maior =0;
   int menor = 0;
   int i = 0;
   int media = 0;
   int ale = 0; 
   
   
/*   for (i=0; i < 10; i++)
    {
    // gerando valores aleatórios na faixa de 0 a 100
    printf("%d\n ", rand() % 1000);
    
    
    }
   
  */ 
   
   srand(time(NULL));
   for(i = 0; i < 20; i++)
   {
        printf("Numero %d: %d\n",i, rand());
        arm[i] = rand() % 10000;
        
        if(arm[i] > maior) 
           maior = arm[i];
    
       else if(arm[i] < menor)
           menor = arm[i];
   //    printf("Numero %d: %d\n",maior, rand());
   //     printf("Numero %d: %d\n",menor, rand());    
   
   }

   
 //   printf("Numero %d: %d\n",maior, rand());
 //   printf("Numero %d: %d\n",menor, rand());

   media = (menor + maior) / 2;


    printf(" a media eh %d\n", media);
    printf(" menor valor eh %d\n", menor); 
    printf(" maiorr valor eh %d\n", maior);
   
   
   //   printf("o valor %d e",maior );






  return 0;

}
