#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<stdbool.h>

typedef struct tempNo {
float valor;
int coluna;
struct tempNo* prox;
} NO;

typedef NO* PONT;

typedef struct {
PONT* A;
int linhas;
int colunas;
} MATRIZ;

void inicializarMatriz(MATRIZ* m, int lin, int col) 
{
	int i;
	m->linhas = lin;
	m->colunas = col;
	m->A = (PONT*) malloc(lin*sizeof(PONT));
	for (i=0;i<lin;i++) 
		m->A[i] = NULL;
}

bool AtribuiMatriz(MATRIZ* m,int lin, int col, float val) 
{
	if (lin<0 || lin >= m->linhas ||col<0 || col >= m->colunas) return false;
	PONT ant = NULL;
	PONT atual = m->A[lin];
	while (atual != NULL && atual->coluna<col)
	{
		ant = atual;
		atual = atual->prox;
	}
	if (atual != NULL && atual->coluna == col)
	{
		if (val == 0) 
		{
			if (ant==NULL) m->A[lin] = atual->prox;
			else ant->prox = atual->prox;
			free(atual);
		}
		else atual->valor = val;
	}
	else if (val != 0) 
	{
		PONT novo = (PONT) malloc(sizeof(NO));
		novo->coluna = col;
		novo->valor = val;
		novo->prox = atual;
		if(ant == NULL) 
			m->A[lin] = novo;
		else 
			ant->prox = novo;
	}
	return true;
}

float ValorMatriz(MATRIZ* m, int lin, int col) 
{
	if (lin<0 || lin>=m->linhas || col<0 ||col >= m->colunas) 
		return 0;
	PONT atual = m->A[lin];
	while (atual != NULL && atual->coluna < col)
		atual = atual->prox;
	if (atual !=NULL && atual->coluna == col)
		return atual->valor;
	return 0;
}

int main(void)
{	
	int linhaA, linhaB, colunaA, colunaB;
    int aux = 0;

	printf("Declare a quantidade de linhas para a matriz A: ");
    scanf("%d", &linhaA);

    printf("Declare a quantidade de colunas para a matriz A: ");
    scanf("%d", &colunaA);

    printf("Declare a quantidade de linhas para a matriz B: ");
    scanf("%d", &linhaB);

    printf("Declare a quantidade de colunas para a matriz B: ");
    scanf("%d", &colunaB);
	
	if(colunaA==linhaB)
	{
		int i, j, quant; // i e j para criacao de ciclos for, e quant para a quant de itens a se inserir na matriz
		int linha, coluna; // variaveis usadas para inserir valores na matriz
		float valor;
		char matriz; // saber se vai inserir na matriz A ou B
//		MATRIZ matrizA[linhaA][colunaA];
//		MATRIZ matrizB[linhaB][colunaB];
//		MATRIZ matrizC[linhaA][colunaB];
		
        
        MATRIZ *matrizA = (MATRIZ *)malloc(sizeof(MATRIZ));
        MATRIZ *matrizB = (MATRIZ *)malloc(sizeof(MATRIZ));
        MATRIZ *matrizC = (MATRIZ *)malloc(sizeof(MATRIZ));
        
        
        
        int soma; 

		
   //     inicializarMatriz(MATRIZ* m, int lin, int col)
        
        
        inicializarMatriz(matrizA, linhaA, colunaA);
		inicializarMatriz(matrizB, linhaB, colunaB);
        
		
        
        printf("Quantos itens deseja adicionar na matriz A e B? ");
    	scanf("%d", &quant);

		for(i = 0; i < quant; i++)
		{
			printf("A qual matriz deseja adicionar?(A ou B): ");
			scanf(" %c", &matriz);
			printf("Digite a linha que deseja colocar: ");
			scanf("%d", &linha);
			printf("Digite a coluna que deseja colocar: ");
			scanf("%d", &coluna);
			printf("Digite o valor que deseja colocar: ");
			scanf("%f", &valor);

			if(matriz == 'A')
			{
				AtribuiMatriz(matrizA, linha-1, coluna-1, valor);
				//printf("numero: %f\n", ValorMatriz(matrizA, linha, coluna));
				printf("numero: %f\n", ValorMatriz(matrizA, linha-1, coluna-1));
			}
			if(matriz == 'B')
			{
				AtribuiMatriz(matrizB, linha-1, coluna-1, valor);
				printf("numero: %f\n", ValorMatriz(matrizB, linha-1, coluna-1));	
			}
			printf("\n");
		}


		// teste printa matrizes
		printf("---------------------------- Matriz A ---------------------------------\n\n");
		for(i = 0; i < linhaA; i++)
        {
            for(j = 0; j < colunaA; j++)
            {
                printf("%6.f", ValorMatriz(matrizA, i, j));
            }
            printf("\n\n");
        }

    	printf("---------------------------- Matriz B ---------------------------------\n\n");
        for(i = 0; i < linhaB; i++)
        {
            for(j = 0; j < colunaB; j++)
            {
                printf("%6.f", ValorMatriz(matrizB, i, j));
            }
            printf("\n\n");
        }

		

        inicializarMatriz(matrizC, linhaA, colunaB);

		// apos criado as matriz, verificado que podem multiplicar e inserido valores vamos multiplicar-las
		printf("----------------------- Matriz multiplicada ----------------------------\n\n");
		for(i = 0; i < linhaA; i++)
        {
            for(j = 0; j < colunaB; j++)
            {
              //  matrizC[i][j] = 0;
			//	 AtribuiMatriz(matrizC, i, j, aux);
                
                soma=0;
                for(int x = 0; x < colunaA; x++)
                {
				   soma = soma + (ValorMatriz(matrizA, i, x) * ValorMatriz(matrizB, x, j));
                }
              //  matrizC[i][j] = soma;
                
                AtribuiMatriz(matrizC, i, j, soma);
              //  soma = 0;
            }
        }

		for(i = 0; i < linhaA; i++)
        {
            for(j = 0; j < colunaB; j++)
            {
            //   printf("%6.f", matrizC[i][j]);
             printf("%6.f  ", ValorMatriz(matrizC, i, j));
            
            
            }
            printf("\n\n");
        }

		free(matrizA);
		free(matrizB);
	    free(matrizC);
    
    }
	else
		printf("As matrizes nao podem ser multiplicadas.\n");



	return 0;
}
