#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define PI 3.14159265358979323846

#define Zp 1.23
#define Xp 2.69
#define Fa 2.69


#define Mx 5.62
#define My 5.99
#define Mz 3.68



void questao4();
void questao1();


int main()
{
    
   questao4();
   questao1();

   return EXIT_SUCCESS;
}


void questao4()
{
  float resp = 0;


  resp = 4 * (sqrt(pow(Zp,2)+ pow(Xp, 2))) / (6 - sqrt(pow(Zp, 2)+ pow(Xp, 2)));

  printf("resposta  da quarta questao eh %f \n", resp);

}


void questao1()
{

   float aux = fabs(My/Mx); // fabs é para valor absoluto do tipo float. Se fosse abs iria da errado demais 
//  float aux = My/Mx; 
   

   
   float tetaRad = asin(0.8 * aux);
   float grausTeta = tetaRad * (180 / PI);
   
   printf("\n resposta  da primeira questao eh teta = %f ", grausTeta);
  

}





