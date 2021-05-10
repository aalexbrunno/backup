#include <stdio.h>
#include <stdlib.h>

//Função principal do programa
int main(void){
  
   int i = 0;
   int a = 0;   
   int j = 0; 
   
   while(i <= 10)
    {
       i++;
       printf("%d. HELLO WORLD WHILE\n",i );

    }
     
    printf("\n");

    do{
       
        printf("%d. HELLO WORLD DO  WHILE\n", a);

        a++;     //a = a + 1;

    }while(a <= 10);

    printf("\n");

    for(j = 0; j <= 10; j++)
    {

       printf("%d. HELLO WORLD FOR\n", j);

    }



    return 0;
}

