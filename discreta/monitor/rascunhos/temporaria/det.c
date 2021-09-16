#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int matriz[3][3];
    int i, a, b, c, d, e, f, g, h, k, j, determinante, pri, sec;
    int *p0 = &matriz[0][0];//a
    int *p1 = &matriz[0][1];//b
    int *p2 = &matriz[0][2];//c
    int *p3 = &matriz[1][0];//d
    int *p4 = &matriz[1][1];//e
    int *p5 = &matriz[1][2];//f
    int *p6 = &matriz[2][0];//g
    int *p7 = &matriz[2][1];//h
    int *p8 = &matriz[2][2];//k

    srand(time(NULL));

    for(i = 0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            matriz[i][j]=rand() %10;
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

     a=*p0;
     b=*p1;
     c=*p2;
     d=*p3;
     e=*p4;
     f=*p5;
     g=*p6;
     h=*p7;
     k=*p8;

  /*printf("\n%i ", *p0);
    printf("%i ", *p1);
    printf("%i \n", *p2);
    printf("%i ", *p3);
    printf("%i ", *p4);
    printf("%i \n", *p5);
    printf("%i ", *p6);
    printf("%i ", *p7);
    printf("%i \n\n", p8);*/

    // determinante = (c*e*g)+(a*f*h)+(b*d*k)+(a*e*k)+(b*f*g)+(c*d*h);
    pri = (a * e * k) + (b * f * g) + (d * h * c);
    sec = (g * e * c) + (d * b * k) + (h * f * a);
	
	determinante = pri - sec;
    
	printf("\nDeterminante = %i\n\n", determinante);

    return 0;
}
