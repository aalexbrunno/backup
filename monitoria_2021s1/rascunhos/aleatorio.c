#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int *aleat(int a);

int main(void)
{
 
 int a = 10;
 
 printf("digite o alcance dos seus numeros aleatorios\n");
 
 scanf("%d", &a);
 
 int *vetor1 = NULL;

 vetor1 = aleat(a); 

 for(int i = 0; i < a;i++)
 {

    printf("o resultado eh %d \n", vetor1[i]);


 }


 return EXIT_SUCCESS;
 }


int *aleat(int a)
{
    srand(time(NULL));
    int* vetor = (int*)calloc(a, sizeof(int));
    int i=0, j=0, flag = 0, aux=0;

    for(i=0;i<a;i++){
		aux = (rand()%a)+1;
        vetor[i] = aux;

        while(1){
            flag = 1;
            for(j=0;j<a;j++){
                if(vetor[i] == vetor[j] && i != j){
                    vetor[i] = (rand()%a)+1;
                    flag = 0;
                    break;
                }
            }
            if(flag)
                break;
        }
    }

    return vetor;
}
