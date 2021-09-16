/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/***************************************************************************/
/*PROTOTYPE*/
int aleatorio(int n1, int n2, int n3); /*Funcao gera numeros aleatorios*/
int vaquinha_a(int a, int b, int c); /*Funcao A confere entrada e numeros aleatorios*/
int vaquinha_b(int a, int b, int c); /*Funcao B confere entrada e numeros aleatorios*/
int vaquinha_c(int a, int b, int c); /*Acertabilidade entre vaquinha_a e vaquinha_b*/
/***************************************************************************/
/*MAIN*/
int main()
{
    int a; /*Face do dado*/
    int b; /*Porcentagem*/
    int c; /*Temperatura*/
    int caux; /*Auxiliar Aleatorio p/ Temperatura Negativa*/
    int x = 0; /*Resultados iguais*/
    int y = 0; /*Resultados diferentes*/

    printf("Calculando seu resultado\n");
    
    srand(time(NULL)); /*Altera regra p/ gerar numeros aleatorios*/
    
    for(int i =0; i < 10; i++)
    {
     //   srand(time(NULL)); /*Altera regra p/ gerar numeros aleatorios*/

        a = rand() % 6 + 1; /*Valor aleatorio de 1 a 6 para as faces do dado*/
        b = rand() % 101; /*Valor aleatorio de 0 a 100 para a porcentagem*/
        c = rand() % 41; /*Valor aleatorio de -40 a +10 para a temperatura*/

        if(c > 10 /*Os numeros maiores que 10 devem ser negativos*/)
        {
            c *= -1;
        }
        else /*Se for menor 10 ele pode ser negativo ou positivo, logo, esse eh uma formula para deixa-lo positivo ou negativo*/
        {
            caux = rand() % 10; /*gero um novo valor aleatorio*/
            if(caux < 4) c *= -1; /*sera um numero negativo*/
        }
  //      printf("Main: a= %i, b= %i, c=%i -- ", a,b,c);
        /*Confere acertabilidade de vaquinha_a e vaquinha_b*/
        if(vaquinha_c(a, b, c)== 1)/*Resultados iguais*/
        {
            x++;
        }
        else //*Resultados diferentes*/
        {
            y++;
        }

    }

 
    printf("x = %d y= %d \n", x,y);

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
     if(aleatorio(a, b, c) == 1 )  /* modificar apenas essa linha! */
     {return 1;}

     return 0;
 }

 int vaquinha_c(int a, int b, int c)
 {
     printf("a= %i, b= %i\n", vaquinha_a(a,b,c), vaquinha_b(a,b,c));

     if(vaquinha_a(a, b, c) == 1 && vaquinha_b(a, b, c) ==1)
     {
         return 1;
     }
     if(vaquinha_a(a,b,c) ==0 && vaquinha_b(a,b,c) ==0)
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
    int N1, /*Faces do dado*/
        N2, /*Porcentagem*/
        N3, /*Temperatura*/
        N3aux; /*Aux aleatorio*/

    srand(time(NULL)); /*Altera regra p/ gerar numeros aleatorios*/
    N1 = rand() % 6 + 1; /*Valor aleatorio de 1 a 6 para as faces do dado*/
    N2 = rand() % 101; /*Valor aleatorio de 0 a 100 para a porcentagem*/
    N3 = rand() % 41; /*Valor aleatorio de -40 a +10 para a temperatura*/

    if(N3 > 10 /*Os numeros maiores que 10 devem ser negativos*/)
    {
            N3 *= -1;
    }
    else /*Se for menor 10 ele pode ser negativo ou positivo, logo, esse eh uma formula para deixa-lo positivo ou negativo*/
    {
            N3aux = rand() % 10; /*gero um novo valor aleatorio*/
                if(N3aux < 4) N3 *= -1; /*sera um numero negativo*/
    }

    printf("B: A=%i, b=%i, c=%i\n", N1,N2,N3);

    if(n1 == N1 && n2 == N2 && n3 == N3) {return 1;} /*Todos valores da entrada conferem com os aleatorios*/

    return 0; /*Valores de entrada nao conferem com o aleatorio*/

}

/***************************************************************************/
