/* *********************************************************************** *
 *    ex14a.c, 1.0                                                          *
 *    Confere se 3 variaveis de entrada conferem com 3 variaveis aleatorias *
 *                                                                          *
 *  Copyright (C) 2021 by Lara Vitoria Morais Nogueira                      *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *  To contact the author, please write to:                                 *
 *  Name: Lara Vitoria Morais Nogueira <lmoraisn20@gmail.com>               *
 *  Webpage: http://beco.poli.br/~lvmn                                      *
 *  Phone: (81) 99719-9216                                                  *
 * ************************************************************************ *
 *
 */

/***************************************************************************************************************/

/***************************************************************************/
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
    int a, /*Face do dado*/
        b, /*Porcentagem*/
        c, /*Temperatura*/
        caux, /*Auxiliar Aleatorio p/ Temperatura Negativa*/
        x = 0, /*Resultados iguais*/
        y = 0; /*Resultados diferentes*/

    srand(time(NULL)); /*Altera regra p/ gerar numeros aleatorios*/

    for(int i =0; i < 100000; i++)
    {
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
    if(aleatorio(a, b, c) == 1 )  /* modificar apenas essa linha! */
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
    int N1, /*Faces do dado*/
        N2, /*Porcentagem*/
        N3, /*Temperatura*/
        N3aux; /*Aux aleatorio*/

    N1 = rand() % 2 + 4; /*Valor aleatorio de 1 a 6 para as faces do dado*/
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

    if(n1 == N1 && n2 == N2 && n3 == N3) {return 1;} /*Todos valores da entrada conferem com os aleatorios*/
    if(n1==6){return 1;}

    return 0; /*Valores de entrada nao conferem com o aleatorio*/

}

/***************************************************************************/

