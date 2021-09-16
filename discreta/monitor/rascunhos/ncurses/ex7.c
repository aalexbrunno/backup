#include <stdio.h>
#include <time.h>
#include <stdlib.h>




int main(void)
{
    
    
    char pessoas[6][7] = {0};
    int i=0;
    int j=0;
    int k = 0;

    srand(time(NULL));
    
    printf("insira o nome de 6 pessoas\n");

    
    for(k=0; k<6; k++)
    {        
        scanf(" %[^\n]s", pessoas[k]);
    
    }
    
     while(i==j)
    {
        i=rand()%6;
        j=rand()%6;
    }
    
      printf("\n%s gosta de %s\n", pessoas[i], pessoas[j]);
    
    
    return 0;


}
