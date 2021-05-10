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
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


int main(void)
{

 
/*    
    
 char palavra[11] = "alex bruno";
 
 printf("\n");
  
 printf("%s", palavra);
 
 printf("\n");

for(int i  = 0; i < 10; i++)
 {
  //   fgets(palavra2,11,stdin);
     printf("%c", palavra[i]);

 }

 printf("\n");

 
 
 setbuf(stdin, 0);
 
 int palavra2[5] = {0};

 
  fgets(palavra2,5,stdin); 
 
// palavra2[strlen(palavra2)-1] = '\0';

 
// int resultado = (int) palavra2[30];


 //printf("%d", palavra2);
 
 
 
  for(int i  = 0; i < 5; i++)
  {
   //   fgets(palavra2,11,stdin);
      printf("%d", palavra2[i]);

  }
 
 
 
 
 
 printf("\n");
 
*/




//   char str[30] = "2030300 This is test";
   
    
    
   char str[30] = " ";
   fgets(str,30,stdin);
   
   char *ptr;
   long ret;

   ret = strtol(str, &ptr, 10);
   printf("seu numero foi %ld\n", ret);
//   printf("%s", ptr);




/*
   char str[30] = "123456 This is test";
   char *ptr;
   long ret;

   ret = strtol(str, &ptr, 10);
   printf("seu numero foi: ld\n", ret);
//   printf("%s", ptr);

*/
   int cont = 0;

   for(int i = 1; i <= ret; i++)
   {
       if(ret % i == 0)
            cont++;
   }
   
   if(cont == 2)
       printf("o numero %ld eh primo", ret);
   else
       printf("o numero %ld nao eh primo", ret);

    printf("\n");
  
   
   return EXIT_SUCCESS;
}










