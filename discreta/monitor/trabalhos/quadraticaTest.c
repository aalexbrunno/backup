#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float raiz (float x);


int main(void) {
    float x;

    raiz(x);


 return 0;
}



float raiz (float x)
{
   float a,b,c;

   printf("vamos calcular as raizes da função quadratica ax^2 + bx + c\n\n");

   printf("digite o valor de a\n");

    scanf("%f",&a);

    printf("digite o valor de b\n");

	scanf("%f",&b);

	printf("por fim digite o valor de c\n");
	scanf("%f",&c);


	int i;
     x = 1;

    float  r;

	r = b * b - 4 * a * c; /* 'r' representa o delta pois o numero do delta a gente tira a raiz  */
    
    printf("\n");

	if(r < 0)
    {
        printf("Delta = %.2f nao calculo delta negativo \n \n", r);
    }
    else if(a == 0)
    {
        printf("A = %.2f nao calculo A igual a zero \n \n", a);
    }
    else   
    {    for(i=1; i < 10; i++)

	    {

	    x = x - (  (x*x - r)/ (2*x));


	    }

	    float x1,x2;

	    x1 = (-b + x) / (2*a);
	    x2 = (-b - x) / (2*a);

        printf("\n");

        printf("o valor de x1 eh %.3f\n", x1);

        printf("o valor de x2 eh %.3f\n\n", x2);
    }
	
    return x;

}





