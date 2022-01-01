#include <stdio.h>
#include <stdlib.h>


int main(void)
{
   
    // parte 1
    
    int vetor[9] = {10,20,30,5,9,60,8,80,90};
   int j = 0, i = 0, k = 0;
  float  Matriz[3][3] = {0}; 
  int flag = 0;


/*
   for(i=0; i < 3; i++)
   {
     
    //    flag = 1;

       for(j=0; j< 3; j++)
        {
              
            
            
           printf("linha %d e coluna %d\n", i, j);
            Matriz[i][j] = vetor[j];
              if(j == 8)
              {    
                  flag = 1;
                  break;
        
              } 
       }
       


        if(flag)
        {
            printf("\n porque nao parou flag  %d linhas %d e colunas %d \n", flag, i, j);
            break;
        }
   
   
   }

*/




// parte 2

for(i = 0; i < 3; i++)
{    for(j = 0; j < 3; j++)
    {   
        for(k = 0; k < 9; k++)
        {
            Matriz[i][k] = vetor[k];
            
            printf("valores passados para a  matriz são %.0f\n", Matriz[i][k]);            
            
            if(k == 8)
            {    
                flag = 1;
                break;
        
            }     
       
        
        }
    
      if(flag)
          break;
    }
   if(flag)
       break;
}



















 /*   
   
  // 10
  // 55
  // 3 por causa dos numeros de cima na declaração
  
 // confirmado que o break sai do laço  
  
  
  flag = 0;

   for(i =0; i < 3; i++)
   {
       
       vetor[i] = 10;
       
        if(i == 0)
        {
           vetor[i] = 55;
        //   flag = 1;
           break;
        }


   //   if(flag)
   //       break;


   }



  for(i = 0; i < 3; i++)
      printf("posicao i = %d os valores do vetor são %d\n", i, vetor[i]);
    
   
    printf("\n\n");
   
   */
  
    

// parte 3

     printf("\n------------------------- Matriz -----------------------------------------\n");
    
     
   
   for(i=0; i < 3; i++)
    {
        for(j=0; j < 3; j++)
        {
            
           printf("%2.0f  ", Matriz[i][j]);
        }

      printf("\n");
    }
   
   
   
   
   
   
   

    return EXIT_SUCCESS;
}
