#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	
	int i = 0, n = 0, j = 0;
	char origem[50], destino[50];
	
	
	printf("digite uma string \n");
	
//	fgets(palavra1, 50, stdin);
	
	scanf("%[^\n]s", origem);
	
	printf("\n%s\n", origem);
	
	n = strlen(origem);
    
 //   printf("\nvalor de n = %d\n", n);
    
//	setbuf(stdin, NULL);
	
	for(i = 0; i < n; i++)
	{
		
		
		origem[i] = destino[i];
//		j++;	
		
	}
	
//	i++;
	destino[i] = '\0';
	

    
    
    //	printf("\n");
	
//    setbuf(stdin, NULL);	
	
	printf("\n%s\n", origem);
	
	printf("%s\n", destino);
	
	return 0;
}







