#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




int main(void)
{                               
  int  i = 0, j = 0;


  printf("digite o valor de a");
  

//  scanf("%d", &a);

  for(i = 0; i <= 10; i++)
  {
      
      j++;
 

      
      if( j == 5)
      {  
          
          printf("iteracao i = %d j = %d \n",i, j);
          break;

      }
       
  
  }



  



  return EXIT_SUCCESS;
}




