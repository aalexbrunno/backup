#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{

    int **p;
    int i = 0,j = 0,n = 2;
    int tam = 2;
//    scanf("%d",&tam);
    

    
    p = (int **) calloc(tam, sizeof(int *));
    for (i = 0; i < tam; i++){
        p[i] = (int *) calloc(tam,sizeof(int));
        for(j =0; j < tam; j++)
            scanf("%d", &p[i][j]);
    
    }
    
    for(i =0; i < tam; i++)
    {
        free(p[i]);
    }
    free(p);






   return EXIT_SUCCESS;
}
