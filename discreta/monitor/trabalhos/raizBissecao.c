#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




int main(void)
{                                                         // a precisão estava em e = 0.0002
    float a = 0, n = 0, f = 0, k = 0, m = 0, absoluto = 0, e = 0.0002, v = 0, b = 0, faixa = 0;
    float x = 0, r =0, j = 0.25;
    float i = 0;


    printf("digite um valor para se tirar a raiz quadrada\n");
    scanf("%f", &r);


    v = r;
    
  
  
 
 
 



   while( i <= r )
   {
   	
   		i = 0.50 + i;
   		j = 0.25 + j;
   	
   	 	a = (i * i) - r;
			
		b = (j * j) - r;
			
		faixa = a * b; 
		    
		if(faixa < 0)
		{
		    	break;
		}
		    
   
   }

//   printf("a faixa eh %f pois %f x %f", faixa, a, b);




	if (a < 0)
	{
		k = i;
    	m = j;
	
	 //  printf("\n entrou no 1 IF iteracoes i = %f j = %.2f  k = %f e m = %f \n ", i, j, k, m);
	
	}
	else
	{
		m = i;
        k = j;
	
	 //   printf("\n entrou no 2 IF iteracoes i = %f j = %.2f k = %f e m = %f \n ", i, j, k, m);
	}

    
	
	
	for(i = 0; i < 20; i++)    
    {

        
        n = (k + m) / 2; // 4.15
        
        f = (n * n) - v;
        
      //  abs(absoluto);
        
        
		absoluto = f;
		
		
		
		if(absoluto < 0)
		{
			
			absoluto = absoluto * -1;
			
			
		}
		
		
		
		
		
		
		
		
		if (absoluto < e)
        {   
       //     printf(" entrou no 1 errouu %f\n", absoluto);
            break;
        }
        else if (f < 0 )
        {
            k = n;
        //    printf(" entrou no 2 k %f\n", k);
         //   break;
	    }
        
        else 
        {
            m = n;
        //    printf(" entrou no 3 m %f\n", m);
		//    break;
		}
        

    }


    printf("\n");

  printf("sua raiz quadrada eh %.3f\n", n);


  return EXIT_SUCCESS;
}




