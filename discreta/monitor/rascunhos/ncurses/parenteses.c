#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>


int main()
{
    int cont = 0;
    int i = 0;
//    char menos, mais;
//    menos = ')';
//    mais = '(';
    char leitura[200];
    
     //limpa o buffer do teclado
	setbuf(stdin, 0);
    

	//ler a string
	fgets(leitura, 200, stdin);

    //limpa as casas nao utilizadas na string
	leitura[strlen(leitura)-1] = '\0';
    
    
    
   for(cont = 0; cont < 50;cont++) 
    {

    

        if (leitura[cont] == ')'){
        //    printf("foi retirado um");
            i--;
        }
        else if (leitura[cont] == '('){
      //      printf("foi adicionado um");
            i++;
        }

    }
    
   
    printf("\n");
    
    printf("O somatório final deu %d\n", i);

 return 0;
}
