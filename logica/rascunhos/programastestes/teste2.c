#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{    

   char pais1[6] = {'b','r','a','s','i','l'};
   char pais2[6] = {0};
   int soma = 0,i =0;
 
   printf("digite onde voce estuda\n"); 
   
   for(i =0;i <=5;i++ ) 
    {
        scanf("%c", &pais2[i]); 
    }   
    
    for(i = 0; i < 6; i++)
    {
       if(pais1[i] != pais2[i])
       {  
         soma += 1;
       }

       else
       {   
       }
     }

   if(soma == 0)
   {
      printf("parabens\n");
   
   }
   else
       printf("eu prefiro estudar no brasil\n");

  return 0;

}
