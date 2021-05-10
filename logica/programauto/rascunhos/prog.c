#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
 {
 //  int i = 0;
   int soma = 0;
 //  int cifra=0;
   int num = 0;

   
   
//   for(i =0; i <= 11111; i++)
//   {
       
//       if(i % 2 != 0)
//       {
        //  printf("%d\n", i);
//          soma += i;      
//       }
     //  else 
    //   {//printf("a = %d b = %d\n", a,b);
    //   }

 //  }
 
   
   
   
   
   
   /*   printf("%d\n", soma);
    
    if(soma >=0)
    {   do{
        cifra = soma%10;
        printf("%d",cifra);
        soma /=10;
    }while(soma != 0);

    printf("\n");

    }

   */


    
    
     for(num=0; num<=11111; num++)
     {
         if(num%2 != 0)
             soma+=num;
     }
 
     soma*=(-1);
 
     for(soma; soma!=0; soma/=10)
     {
         if(soma<0)
             soma*=-1;
         printf("%d", soma%10);
     }
 
     printf("\n");
 
    
    
    
    
    /*
    else if(soma <1)
    {
       soma = soma * -1;

    }

    printf("-");

    do {
        cifra = soma % 10;
        printf("%d",cifra);
        soma /= 10;

        }while (soma != 0);
        printf("\n");
*/

  return EXIT_SUCCESS;
 }
