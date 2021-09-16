#include <stdio.h>
#include <stdlib.h>

#include "libABS.h"

int main(void)
{

//Definição de variaveis
 	int i = 0;
    // int j = 0;
 	int linhaA=0, colunaA=0, linhaB=0, colunaB=0;
	int **matrizA=NULL, **matrizB=NULL, **matrizC=NULL;
    // int x;

//Entrada de dados
	printf("\n Informe a quntidade de linhas da matriz A : ");
	scanf("%d",&linhaA);
	printf("\n Informe a quantidade de colunas da matriz A : ");
	scanf("%d",&colunaA);
	printf("\n Informe a quntidade de linhas da matriz B : ");
	scanf("%d",&linhaB);
	printf("\n Informe a quantidade de colunas da matriz B : ");
	scanf("%d",&colunaB);


// L = 3 e C = 4
	while(colunaA != linhaB)
	{
	    printf(" impossivel multiplicar as matrizes \n ");
	}

 	matrizA = calloc(linhaA, sizeof(int *));
    matrizB = calloc(linhaB, sizeof(int *));
 	matrizC = calloc(linhaA, sizeof(int *));

	for(i = 0; i < linhaA; i++ )
 	{
		matrizA[i] = calloc(colunaA, sizeof(int));
  	}

	for(i = 0; i < linhaB; i++ )
 	{
	 	matrizB[i] = calloc(colunaB, sizeof(int));
	}

	for(i = 0; i < linhaA; i++ )
 	{
 		matrizC[i] = calloc(colunaB, sizeof(int));
  	}
    scan_matriz(matrizA, linhaA, colunaA);
    scan_matriz(matrizB, linhaB, colunaB);

	multMatriz(matrizA,matrizB,matrizC, linhaA, colunaA, linhaB, colunaB);

 	print(matrizC, linhaA, colunaB);

 	for(i = 0; i < linhaA; i++ )
 	{
        free(matrizA[i]);
 	}
    free(matrizA);

    for(i = 0; i < linhaB; i++ )
 	{
        free(matrizB[i]);
    }
    free(matrizB);

    for(i = 0; i < linhaA; i++ )
 	{
        free(matrizC[i]);
 	}
    free(matrizC);


    }

