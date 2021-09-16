#include <stdio.h>
#include <stdlib.h>
#include "libABS.h"

int main(void)
{

  float result = 0;
  
  float a = 0, b = 0, c = 0;

  printf("digite o valor que voce quer normalizar\n");
  scanf("%f", &a);

  printf("digite o valor Maximo da normalizacao\n");
  scanf("%f", &b); 
 
  printf("digite o valor minimo da normalizacao\n");
  scanf("%f", &c); 
  
  result = normaliza(a, b, c);
  
  printf("resultado eh %.2f \n", result);
   
   return 0;

}
