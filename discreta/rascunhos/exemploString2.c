#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	
	int i = 0, n = 0, j = 0;
	char origem[100], destino[100];
	
	printf("digite uma string \n");
	
    /* poderia ter usada a função fgets também*/
    
      fgets(origem, 100, stdin);

//	scanf("%[^\n]s", origem);
	
	n = strlen(origem);
    
	for(i = 2; i < n; i++)
	{
		destino[j] = origem[i];
	
		printf("i = %d e j = %d  letra passada = %c letra recebida = %c \n",i, j, origem[i], destino[j] );
        
		j++;  
	}
	
	i++;
	destino[i] = '\0';
	
	printf("\n%s\n", origem);
	
	printf("%s\n", destino);
	
	return EXIT_SUCCESS;
}







