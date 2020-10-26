#include <stdio.h>
#include <math.h>

int f(int x);
int main(void) {

int x;
printf(" %d", f(x));

  return 0;
}

	
int f(int x){

int fib, a = 0, b = 1, i = 0, soma = 0;
	
	
	while (i<4000000)
       {
		i++;
        fib = a + b;
        a = b;
        b = fib;
        if(fib > 4000000)
            break;
        else if(fib%2 == 0)  
	        soma += fib;}
	
//	 printf ("o resultado eh: %d",soma);    	
	return soma;
}
