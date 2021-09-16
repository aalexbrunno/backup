#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


float raiz(float r, float x);
float absoluto(float x);

int main(void)
{
    float a = 0;
    float x = 0, r =0;
    
    
    printf("digite um valor para se tirar a raiz quadrada\n");
    scanf("%f", &r);

//    printf("digite um palpite de qual resultado sera a raiz do seu numero\n");
//    scanf("%f", &x);
    x = 1;

    a = raiz(r,x);

    


    printf("\n");

    printf("sua raiz e %.5f\n", a);




  return EXIT_SUCCESS;
}


float raiz(float r, float x)
{
    int i = 0, a = 1000;
    float  absolu = 0, aux = 0, erro = 0.00001;
    
    for(i = 0; i < a; i++)
    {
        aux = x;
        x = x - ((x*x - r) / (2*x));
        
        absolu = x - aux;
        
        if(absolu < 0)
        {    
            absolu = absoluto(absolu);

        }   
        if(absolu < erro)
        {
           break;
        }
    
    }
    printf("rodou %d vezes\n", i);
   
    return x;
}

float absoluto(float x) 
{
  
   return x * -1;
}



