#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print(int  **resposta, int linha, int coluna);
int *aleat(int a);
void scan_matriz2(int **array, int linha, int coluna, int *vetor);
void multMatriz(int **arrayA,int **arrayB, int **arrayC,int linhaA, /*int  colunaA,*/ int linhaB, int colunaB);


int main(void)
{

//Definição de variaveis
 	int i = 0;
    // int j = 0;
 	int linhaA=0, colunaA=0, linhaB=0, colunaB=0; 
	int **matrizA=NULL, **matrizB=NULL, **matrizC=NULL, *vetor1=NULL, *vetor2=NULL;
    // int x;

//Entrada de dados
	printf("\n Informe a quntidade de linhas da matriz A : ");
	scanf("%d",&linhaA);
	printf("\n Informe a quantidade de colunas da matriz A : ");
	scanf("%d",&colunaA);
	printf("\n Informe a quantidade de linhas da matriz B : ");
	scanf("%d",&linhaB);
	printf("\n Informe a quantidade de colunas da matriz B : ");
	scanf("%d",&colunaB);


// L = 3 e C = 4
	while(colunaA != linhaB)
	{
	    printf(" impossivel multiplicar as matrizes \n ");
	}
 
 	matrizA = calloc(linhaA, sizeof(int *)); 
    matrizB = calloc(linhaB, sizeof(int *));
 	matrizC = calloc(linhaA, sizeof(int *));
	 
	for(i = 0; i < linhaA; i++ ) 
 	{
		matrizA[i] = calloc(colunaA, sizeof(int)); 
  	}

	for(i = 0; i < linhaB; i++ )
 	{
	 	matrizB[i] = calloc(colunaB, sizeof(int));
	}
 
	for(i = 0; i < linhaA; i++ ) 
 	{
 		matrizC[i] = calloc(colunaB, sizeof(int));
  	}


    vetor1 = aleat(linhaA*colunaA); 
    vetor2 = aleat(linhaB*colunaB);  

    scan_matriz2(matrizA, linhaA, colunaA,vetor1);
    scan_matriz2(matrizB, linhaB, colunaB,vetor2);

	multMatriz(matrizA,matrizB,matrizC, linhaA, /*colunaA, */ linhaB, colunaB);
  
 	print(matrizC, linhaA, colunaB);

 	for(i = 0; i < linhaA; i++ ) 
 	{
        free(matrizA[i]);
 	}
    free(matrizA);
	
    for(i = 0; i < linhaB; i++ )
 	{
        free(matrizB[i]);
    }
    free(matrizB);
 	
    for(i = 0; i < linhaA; i++ ) 
 	{
        free(matrizC[i]);
 	}
    free(matrizC);
   
 
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


void scan_matriz2(int **array, int linha, int coluna, int *vetor)
{
    int flag=0, i, j;
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            array[i][j] = vetor[flag];
            flag++;
        }
    }
}


void multMatriz(int **arrayA,int **arrayB, int **arrayC,int linhaA, /*int  colunaA,*/ int linhaB, int colunaB)
{
   	int x = 0;
	int i = 0, j = 0;



        //Processamento e saida em tela  =  PRODUTO DAS MATRIZES
    for(i = 0; i < linhaA; i++)
    {
        for(j = 0; j < colunaB; j++)
        {
            arrayC[i][j] = 0;
            for(x = 0; x < linhaB; x++)
            {
                arrayC[i][j] +=  arrayA[i][x] * arrayB[x][j];
            }
        }
    }
}


void print(int  **resposta, int linha, int coluna)
{
    int i = 0, j = 0;
	
    printf("\n");	
	for(i = 0; i < linha; i++) 
	{
        for(j = 0; j < coluna; j++) 
		{
           printf(" %d ", resposta[i][j]);
        }
        printf("\n");
    }
    printf("\n");	
	
}
   
     





