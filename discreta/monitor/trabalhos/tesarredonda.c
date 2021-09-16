#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void)
{

   

  float a = 16, b = 6, x = 0;
  //  b = 3;
  
  float n1 = 4.0, n2 = 3.0, result = 0;

  x = a / b; // 16 / 6 res = 2.66 ~ 3
  
  x = round(x);
  
  // eu quero que seja um arredodando normal dando resultado 3
  printf("Resultado 01  inplementado %f\n\n", x);


  
  
  
  result = n1 / n2; // 4 / 3  res = 1.33 ~ 1

  result = floor(result); // arredonda sempre para baixo
  
  
  // Aqui eu quero que o resultado seja 1
  printf("Resultado 02  inplementado: %f\n", result);

  
   n1 = 5;
  result = n1 / n2; //  5 / 3  res = 1.66 ~ 2
  result = ceil(result); // arredonda sempre para cima
  
  // Aqui eu quero que o resultado seja 2
  printf("Resultado 03 inplementado: %f\n", result);


 
   return EXIT_SUCCESS;
}
 
