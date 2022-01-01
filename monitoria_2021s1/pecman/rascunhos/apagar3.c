#include <stdio.h>
#include <stdlib.h>


int main(void)
{


    int vetor[9] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int j = 0, i = 0;
    int  Matriz[3][3] = {0};
    int flag = 0;


    
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            Matriz[i][j] = vetor[flag];
            flag++;
        }
    }



    printf("\n------------------------- Matriz -----------------------------------\n");


    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)

            printf("%2d ", Matriz[i][j]);

        printf("\n");
    }


    printf("\n---------------------------------------------------------------------\n");

    return EXIT_SUCCESS;
}


