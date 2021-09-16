#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int aleatorio(int n1, int n2, int n3); 
int vaquinha_a(int a, int b, int c); 
int vaquinha_b(int a, int b, int c); 
int vaquinha_c(int a, int b, int c); 
/***************************************************************************/

int main()
{
    int a, /*Face do dado*/
        b, /*Porcentagem*/
        c, /*Temperatura*/
        caux, /*Auxiliar Aleatorio p/ Temperatura Negativa*/
        x = 0, /*Resultados iguais*/
        y = 0; /*Resultados diferentes*/

    srand(time(NULL)); 
    
    for(int i =0; i < 100000; i++)
    {
        a = rand() % 6 + 1; 
        b = rand() % 101; 
        c = rand() % 41; 

        if(c > 10 )
        {
            c *= -1;
        }
        else 
        {
            caux = rand() % 10;
            if(caux < 4) c *= -1; 
        }

        if(vaquinha_c(a, b, c)== 1)
        {
            x++;
        }
        else 
        {
            y++;
        }

    }
    printf("x= %i \ny= %i\n", x,y);

    return EXIT_SUCCESS;
}

int vaquinha_a(int a, int b, int c)
{
    if(a <= 6 && a > 4)
        if(b < 40)
            if(b < c)
                {return 1;}
            else
                {return 0;}
        else
            if(c >= a)
                {return 1;}
            else
                {return 0;}
    else
        if(a == 6)
            {return 1;}
        else
            if(a == 4)
                if(c < b)
                    {return 1;}
                else
                    {return 0;}
            else
                {return 0;}

}

int vaquinha_b(int a, int b, int c)
{
    if(aleatorio(a, b, c) == 1 )  
    {return 1;}

    return 0;
}

int vaquinha_c(int a, int b, int c)
{
    if(vaquinha_a(a, b, c) == 1 && vaquinha_b(a, b, c) ==1)
    {
        return 1;
    }
    if(vaquinha_a(a,b,c) ==0 && vaquinha_b(a,b,c) ==0)
    {
        return 1;
    }
    return 0;
}

int aleatorio(int n1, int n2, int n3)
{
    int N1, 
        N2, 
        N3, 
        N3aux; 

    N1 = rand() % 2 + 4; 
    N2 = rand() % 101; 
    N3 = rand() % 41; 

    if(N3 > 10 )
    {
            N3 *= -1;
    }
    else 
    {
            N3aux = rand() % 10; 
                if(N3aux < 4) N3 *= -1;
    }

    if(n1 == N1 && n2 == N2 && n3 == N3) {return 1;} 
    if(n1==6){return 1;}

    return 0;

}


