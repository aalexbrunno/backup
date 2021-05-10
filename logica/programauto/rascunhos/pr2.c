#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void){
  
 int retorno = 0;
    
// do{	
    
    char pais1[7] = {0};	
    char pais2[7] = "brasil";
//	int retorno = 0;
    
    printf("escreva o nome do pais onde voce estudou\n");

    setbuf(stdin, 0);

    fgets(pais1, 300, stdin);
    
    pais1[strlen(pais1)-1] = '\0';
    
    strcmp(pais1,pais2);
    
    retorno = strcmp(pais1,pais2);

//    printf("o valor eh %d\n", retorno);

    if( retorno ==0)
        printf("\nparabens\n");
    else
         printf("eh bom tambem mas eu prefiro estudar no brasil\n ");

// }while(retorno != 0 );


   return EXIT_SUCCESS;
}
    

