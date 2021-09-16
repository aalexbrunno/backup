#include "multC.c"


int multiplicar(int lA, int cA, int lB, int cB, float matA[lA][cA], float matB[lB][cB])
 {
     float matC[lB][cB];
     float val = 0;
     int i, j, x;
     if(cA == lB)
     {
         for(i = 0; i < lA; i++)
         {
             for(j = 0; j < cA; j++)
             {
                 printf("\n\n Insira o valor da linha %d e da coluna %d pertencente a Matriz A: ", i+1, j+1);
                 scanf("%f", &matA[i][j]);
             }
             printf("\n");
         }
         for(i = 0; i < lB; i++)
         {
             for(j = 0; j < cB; j++)
             {
                 printf("\n\n Insira o valor da linha %d e da coluna %d pertencente a Matriz B: ", i+1, j+1);
                 scanf("%f", &matB[i][j]);
             }
             printf("\n");
         }

         printf("------------------- Matriz A -------------------\n\n");
         for(i = 0; i < lA; i++)
         {
             for(j = 0; j < cA; j++)
             {
                 printf("%6.f", matA[i][j]);
             }
             printf("\n\n");
         }

         printf("------------------ Matriz B --------------------\n\n");
         for(i = 0; i < lB; i++)
         {
             for(j = 0; j < cB; j++)
             {
                 printf("%6.f", matB[i][j]);
             }
             printf("\n\n");
         }

         printf("------------- Produto das Matrizes --------------\n\n");

         //multiplicacao das matrizes dadas
         for(i = 0; i < lA; i++)
         {
             for(j = 0; j < cB; j++)
             {
                 matC[i][j] = 0;
                 for(x = 0; x < lB; x++)
                 {
                     val +=  matA[i][x] * matB[x][j];
                 }
                 matC[i][j] = val;
                 val = 0;
             }
         }

         for(i = 0; i < lA; i++)
         {
             for(j = 0; j < cB; j++)
             {
                 printf("%6.f", matC[i][j]);
             }
             printf("\n\n");
         }
         printf("\n\n");
     }
     else
     {
         printf("\n\n Nao eh possivel multiplicar as matrizes informadas ");
     }
     return (matC[i][j]);
 }

