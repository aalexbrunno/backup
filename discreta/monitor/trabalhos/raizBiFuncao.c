#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

float raizF(float r);
float calcRaiz(float i, float j, float r);
float absoluto(float r);

int main(void)
{                                                        
  float a = 0, r = 0;

  printf("digite um valor para se tirar a raiz quadrada\n");
  scanf("%f", &r);
    
  a = raizF(r);
   
  printf("o valor da sua raiz quadrada eh %.3f\n",a);
    
  return EXIT_SUCCESS;
}

float raizF(float r)  
{
    float i = 0, j = 0, a = 0, b = 0, faixa = 0, result = 0; 
    
    if(r < 0) /* se o valor for negativo tem que transformar para positivo */
    {
        printf("so eh permitido raiz positiva\n");
        
        r = absoluto(r);
    }
    
    while( i <= r ) /* vamos conseguir a faixa a partir desse laço */
    {
   	    i = 0.25 + i; /* 'i' vai ser a taxa menor */
   	    j = 0.50 + j; /* 'j' vai ser a taxa maior */
   	
   	    a = (i * i) - r; /* f(x) = x^2 - 17 */           /* f(x) = x - sqrt(17)     */
			/* i = 4 */
	    b = (j * j) - r;
			/*j = 4.30 */
	    faixa = a * b; /* se a multiplicação de a x b for um numero negativo encontramos dois numeros para a faixa  */
		 /*f(a) * f(b) = < 0   */   
	    if(faixa < 0)
	    {
		    break;
	    }
                 
    }

    result = calcRaiz(i, j, r);
      
    return result;
}

float calcRaiz(float i, float j, float r)
{
   float x = 0, absoluto = 0, e = 0.001, f = 0;
  
   int cont = 0;
    
   for(cont = 0; cont < 1000; cont++)    
    {
      x = (i + j) / 2; /* vai somar aqueles dois valores 'i' e 'j' da faixa que encontramos e dividir por 2 e vai armazenar em x */
        /* 4.15 */
      f = (x * x ) - r; /* agora x vai ser colocado na função f(x1) = x^2 - r */
        
	  absoluto = fabs(f);
		/*
           se o valor de 'f' da função f(x) for menor que zero esse é o nosso
           resultado da raiz. Caso contrário pega a faixa de sinal negativo para ser meu 
           próxima k

        */		
		if (absoluto < e) /* for menor que nossa margem de erro então o programa para e dá o resultado */
        {   
       
            break;
        }
        else if (f < 0 )  
        {                
            i = x;       /* se 'f' for menor que zero a gente pegar o menor valor da faixa */
       /* 4.15  */
	    }
        
        else 
        {
            j = x; /* se 'f' for positivo a gente pega o maior valor da faixa */
     
		}
    }
    return x;
}

float absoluto(float r)
{
    return r * -1;

}

