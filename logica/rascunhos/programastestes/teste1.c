#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void){
	
/*	
    char pais1[7];	
    char pais2[7] = "brasil";
	int retorno = 0;
    
    printf("escreva o nome do pais onde voce estudou\n");

    setbuf(stdin, 0);

    fgets(pais1, 300, stdin);
    
    pais1[strlen(pais1)-1] = '\0';
    
    strcmp(pais1,pais2);
    
    retorno = strcmp(pais1,pais2);

//    printf("o valor eh %d\n", retorno);

    if( retorno ==0)
        printf("parabens\n");
    else
         printf("eh bom tambem\n ");


*/  
    
      char pais2[6] = {'b','r','a','s','i','l'};
      char pais1[6] = {'b','r','o','s','i','l'};
      int soma = 0;


 //     for(int i = 0; i < 6; i++)
//      {
//          scanf("%c", &pais1[i]);
//      }
/*     for(int i =0; i < 6; i++)
     {
        printf("%c",pais2[i]);
     
     }
     
     printf("\n");
     
      for(int i =0; i < 6; i++)
      {
          printf("%c",pais1[i]);

      }

       printf("\n");
*/

   
     for(int i = 0; i < 6; i++)
     {
        if(pais1[i] == pais2[i])
        {   // printf(" parabens");
             soma += 1;
        }

        else
        {    //printf(" outra opacao");
        }
     }
     printf("%d",soma);
     
//    // char palavrafixa[6] = {'b','r','a','s','i','l'};
      
// /*   
//    char pais[6] = {'g','r','a','s','i','l'};

//    printf("\n");

//    if(pais[6] == 'b','r','a','s','i','l')
//    {    printf(" parabens\n");
//    }
//    else
//    {    printf(" outra opacao\n");
//    }
//  */

         
	return 0;
}


