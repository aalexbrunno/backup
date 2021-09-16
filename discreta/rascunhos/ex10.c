#include <stdio.h>    
#include <stdlib.h>   
#include <stdbool.h>
#include "libABS.h" 

int main(void)
{
    MATRIZ* matriz1;
    int linhasMatriz1, colunasMatriz1;
    MATRIZ* matriz2;
    int linhasMatriz2, colunasMatriz2;

    MATRIZ* matrizMultiplicada;

    printf("\nQuantas linhas vai ter a primeira matriz?\n");
    scanf("%d", &linhasMatriz1);

    printf("\nQuantas colunas vai ter a primeira matriz?\n");
    scanf("%d", &colunasMatriz1);

    matriz1 = coisarMatriz(linhasMatriz1, colunasMatriz1);

    if(matriz1 != NULL) {
       printf("\nQuantas linhas vai ter a segunda matriz?\n");
       scanf("%d", &linhasMatriz2);

       printf("\nQuantas colunas vai ter a segunda matriz?\n");
       scanf("%d", &colunasMatriz2);

       matriz2 = coisarMatriz(linhasMatriz2, colunasMatriz2);
    }

    if(matriz1 != NULL && matriz2 != NULL) {
       matrizMultiplicada = multiplicacao(matriz1, matriz2, linhasMatriz1, colunasMatriz1, linhasMatriz2, colunasMatriz2);

       if(matrizMultiplicada != NULL)
       	  printMatriz(matrizMultiplicada, linhasMatriz1, colunasMatriz2);
    }

    return EXIT_SUCCESS;
}

