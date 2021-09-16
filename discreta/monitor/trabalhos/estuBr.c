#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h> // biblioteca para se usar acentos no printf


int main (void)
{
    setlocale(LC_ALL, "Portuguese"); // função da biblioteca locale.h que habilita o programa à usar acentos no printf
   
        
   char var = ' '; // ' ' serve para inicializar a variável var
   
   printf("voce estuda no brasil? digite [s/n] \n");
   
   scanf("%c", &var);
   
   if(var == 's')
   {  
       printf("parabéns  \n");

   }

   else 
   {
     printf("o brasil ainda é um pouco melhor\n");
   
   }


   return EXIT_SUCCESS;
}
