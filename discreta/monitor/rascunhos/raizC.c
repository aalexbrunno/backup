#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{

    int i = 0, a =10; 
    float x = 0, r =0;
    
    printf("digite um valor para se tirar a raiz quadrada\n");
    scanf("%f", &r);
    
    printf("digite um palpite de qual resultado sera a raiz do seu numero\n");
    scanf("%f", &x);
    
    
    for(i = 0; i < a; i++)
    {
         x = x - ((x*x - r) / (2*x));   


    }
    
    printf("\n");

    printf("sua raiz e %.2f\n", x);




  return EXIT_SUCCESS;
}
