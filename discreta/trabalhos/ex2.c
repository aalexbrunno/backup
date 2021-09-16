#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libABS.h"

int main (void)
{
   int a = 0;
   printf("digite um numero limite para serem gerados os numeros alatorios\n");
   scanf("%d", &a);
   
   aleatorio(a);
   return 0;
}

