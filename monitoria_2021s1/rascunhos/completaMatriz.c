#include <stdio.h>
#include <stdlib.h>


int main(void)
{


    int vetor[9] = {0};
    int j = 0, i = 0, k = 0;
    int  Matriz[3][3] = {0};
    int flag = 0;

    
    for(i = 0; i < 9; i++)
    {
        scanf("%d", &vetor[i]);

    }



    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            for(k = 0; k < 9; k++)
            {
                Matriz[i][k] = vetor[k];

                printf("valores passados para a  matriz são %d\n", Matriz[i][k]);

                if(k == 8)
                {
                    flag = 1;
                    break;

                }


            }

            if(flag)
                break;
        }
        if(flag)
            break;
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

