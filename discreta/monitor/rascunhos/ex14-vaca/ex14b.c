
/*******************************************************************************************************/
/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/***************************************************************************/
/*PROTOTYPE*/
int aleatorio(int n1, int n2, int n3);
/***************************************************************************/
/*MAIN*/
int main()
{
    void vaquinha_b(int a, int b, int c);

    int A, /*Numero da face dado*/
        B, /*Numero da porcentagem*/
        C; /*Numero da temperatura*/

    printf("Digite um valor aletorio de 1 a 6: ");
    scanf("%i", &A);

    printf("Digite um valor aletorio de 0 a 100: ");
    scanf("%i", &B);

    printf("Digite um valor aletorio de -40 a +10: ");
    scanf("%i", &C);

    vaquinha_b(A, B, C);

    return EXIT_SUCCESS;
}
/***************************************************************************/
/*FUNCOES*/
void vaquinha_b(int a, int b, int c)
{
        printf("(funcao B): Voce... ");
        if(aleatorio(a, b, c) == 1 )  /* modificar apenas essa linha! */
        printf("ganhou a vaquinha!\n");
        else
        printf("nao ganhou a vaquinha!\n");
}

int aleatorio(int n1, int n2, int n3)
{
    int N1, /*Faces Dados*/
        N2, /*Porcentagem*/
        N3, /*Temperatura*/
        N3aux; /*Aux aleatorio*/

    srand(time(NULL)); /*Altera regra p/ gerar numeros aleatorios*/
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

