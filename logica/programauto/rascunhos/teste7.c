#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>



int main(void)
{
    
    
    /*
   {
    int vetor[20] = {0};
    int maior=0;
    int menor=10000;
    int media=0;

    srand(time(NULL));

    printf("valores aleatorios\n");


    for(int i = 0; i < 20; i++)
    {
        vetor[i] = rand() % 10000;

        if(vetor[i] > maior)
            maior = vetor[i];

        if(vetor[i] < menor)
            menor = vetor[i];
    }

    media = (maior + menor) / 2;

    printf("Maior valor: %i\n", maior);
    printf("Menor valor: %i\n", menor);
    printf("Media entre o maior e o menor: %i\n", media);

    return 0;
*/


//char pessoa1[50] = "alex";
//char pessoa2[50] = "bruno";
//char pessoa2[50] = "seabra";

 char a[50] = {0};
 char b[50] = {0};
 char c[50] = {0};
 int i = 0;
// int vetor[1] = {0};
 char vetor[3] = {0};
 
 printf("escreva 10 nomes\n");



scanf(" %[^\n]s", a);
scanf(" %[^\n]s", b);
scanf(" %[^\n]s", c);

char vetor[0] = a[50]; 
char vetor[1] = b[50];
char vetor[2] = c[50];

printf("%s gosta de %s\n", vetor[0]);

// printf("\n");


/* 
 int vetor[10] = {0};
 int j = 0; 
 
 for(j = 0; j < 10; j++)
 {
    scanf("%d", &vetor[j]);    

  }


for(i = 0; i < 10; i++)
{    
    printf("\no resultado eh %d",&vetor[i]);
 
}
 

printf("\n");

*/
 

 





/*

int cont = 0;

 
for(cont = 0; cont < 3; cont++){
     //   scanf("%d", &vetor[cont]);
        scanf(" %s", vetor[cont]);

    }

    //Imprimindo vetor em um laço de repetição
    for(cont = 0; cont < 3; cont++){
        printf("%s", vetor[cont] );
    }

*/





















/*
 
 for(i = 0; i <= 0; i++)
 {
     vetor[i] = rand() % 2;

//      printf("valor de i  eh %d \n",i);
     
      
      switch (vetor[i])
     {
        case 0:
             printf("%s gosta de %s\n",a,b);
             break;
        case 1:
            printf("%s gosta de %s\n",a,c);
            break;
        case 2:
            printf("%s gosta de %s\n",b,c);
            break;
        default:
            printf("entrou no switch mas nao entrou em nenhum dos casos\n");
            break;
     }

 }



*/

 
/*

  switch (vetor[i]) 
  {
      case 0:
          printf("%s gosta de %s",a,b);
          break;
      case 1:
          printf("%s gosta de %s",a,c);
          break;
      case 2:
           printf("%s gosta de %s",b,c);
   
   }

*/


  return 0;  
    
}
