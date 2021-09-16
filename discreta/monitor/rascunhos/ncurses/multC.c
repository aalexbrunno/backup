#include <stdio.h>
#include "multC.h"

int main()
{
    int linhaA, colunaA, linhaB, colunaB;

    printf("\n Insira a quantidade de linhas da matriz A : ");
    scanf("%d",&linhaA);
    printf("\n Insira a quantidade de colunas da matriz A : ");
    scanf("%d",&colunaA);
    printf("\n Insira a quantidade de linhas da matriz B : ");
    scanf("%d",&linhaB);
    printf("\n Insira a quantidade de colunas da matriz B : ");
    scanf("%d",&colunaB);

    float matrizA[linhaA][colunaA];
    float matrizB[linhaB][colunaB];

    multiplicar(linhaA, colunaA, linhaB, colunaB, matrizA, matrizB);

    return 0;
}
