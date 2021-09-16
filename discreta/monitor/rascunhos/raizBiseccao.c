#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


float raiz(float r, float x);


int main(void)
{
    float a = 0, n = 0, f = 0, k = 0, m = 0, absoluto = 0, e = 0.02;
    float x = 0, r =0;
    int i = 0;

    printf("digite um valor para se tirar a raiz quadrada\n");
    scanf("%f", &r);

    printf("digite um palpite de qual resultado sera a raiz do seu numero\n");
    scanf("%f", &x);


    a = raiz(r,x);
    
    k = a - 1;
    m = a + 1;


    for(i = 0; i < 10; i++)    
    {

       // f = n - a;
    
       // k = 4;
      //  m = 4.3;
        
        n = (k + m) / 2; // 4.15
        
      //  printf("%f\n", n);

        f = n - a;
        
       // absoluto = f * -1;
      
	  
	  //  printf("%f\n", f);
      //   printf("%f\n", a);
        
      //  abs(absoluto);
        
        
		absoluto = f;
		
		
		
		if(absoluto < 0)
		{
			
			absoluto = absoluto * -1;
			
			
		}
		
		
		
		
		
		
		
		
		if (absoluto < e)
        {   
            printf(" entrou no 1 errouu %f\n", absoluto);
            break;
        }
        else if (f < 0 )
        {
            k = n;
            printf(" entrou no 2 k %f\n", k);
         //   break;
	    }
        
        else 
        {
            m = n;
            printf(" entrou no 3 m %f\n", m);
		//    break;
		}
        

    }


    printf("\n");

  //  printf("sua raiz e %.2f\n", a);

  printf("sua raiz e %f\n", n);


  return EXIT_SUCCESS;
}


float raiz(float r, float x)
{
    int i = 0, a = 10;


    for(i = 0; i < a; i++)
    {

        x = x - ((x*x - r) / (2*x));


    }




   return x;
}

//float raizBi()

