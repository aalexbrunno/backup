#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "libABS.h"
#include <stdbool.h>


float normaliza(float x, float maxX, float minX)
{
    float y = 0;

    y = (x - minX) / (maxX - minX);
    
   return y;
}


void aleatorio(int a) 
{
int i = 0;
   
   srand(time(NULL));

   for (i = 0; i < 10; i++ )
   {
       printf("%d ", rand() % a);
   }
   
}

void reverte(char buffer[])
{

 int size = strlen(buffer);
    for(int i = 0; i < size / 2; i++) {
       char tmp = buffer[i]; 
       buffer[i] = buffer[size - i - 1]; 
       buffer[size - i - 1] = tmp; 
    }
   
}

void multMatriz(int **arrayA,int **arrayB, int **arrayC,int linhaA, int colunaA, int linhaB, int colunaB)
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
           printf("%d ", resposta[i][j]);
        }
        printf("\n");
    }
    printf("\n");	
	
}
   
     
void scan_matriz(int **array, int linha, int coluna)
{
    int i,j;
    for(i = 0; i < linha; i++) 
	{
       for(j = 0; j < coluna; j++) 
	    {
            printf("\n\n Informe o valor da %d  Linha e da %d  Coluna da Matriz A: ", i+1, j+1);
            scanf("%d", &array[i][j]);
	    }
        printf("\n");
    }
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


/*----------------------------------  MATRIZ ESPARZA --------------------------  */
void iniciarMatriz(MATRIZ* m, int lin, int col) {
    int i;
    m->linhas = lin;
    m->colunas = col;
    m->A = (PONT*) malloc(lin*sizeof(PONT));

    for(i = 0; i < lin; i++) {
        m->A[i] = NULL;
    }
}

_Bool atribuiMatriz(MATRIZ* m, int lin, int col, float val) {
    if(lin < 0 || lin >= m->linhas || col < 0 || col >= m->colunas)
        return false;

    PONT ant = NULL;
    PONT atual = m->A[lin];

    while(atual != NULL && atual->coluna < col) {
        ant = atual;
        atual = atual->prox;
    }

    if(atual != NULL && atual->coluna == col) {
        if(val == 0) {
            if(ant == NULL) m->A[lin] = atual->prox;
            else ant->prox = atual->prox;
            free(atual);
        } else {
            atual->valor = val;
        }
    } else {
        PONT novo = (PONT) malloc(sizeof(NO));
        novo->coluna = col;
        novo->valor = val;
        novo->prox = atual;

        if(ant == NULL) {
            m->A[lin] = novo;
        } else {
            ant->prox = novo;
        }
    }

    return true;
}

float valorMatriz(MATRIZ* m, int lin, int col) {
    if(lin < 0 || lin >= m->linhas || col < 0 || col >= m->colunas)
        return 0;

    PONT atual = m->A[lin];
    while(atual != NULL && atual->coluna < col) {
        atual = atual->prox;
    }

    if(atual != NULL && atual->coluna == col) {
        return atual->valor;
    }

    return 0;
}

void printMatriz(MATRIZ* m, int lin, int col) {
   int i, j;

   for(i = 0; i < lin; i++) {
   	for(j = 0; j < col; j++) {
	    printf("%.0f ", valorMatriz(m, i, j));
	}
        printf("\n");
   }
}

MATRIZ* coisarMatriz(int linhas, int colunas) {
    MATRIZ* matriz = (MATRIZ*)malloc(sizeof(MATRIZ));
    int linha = 0, coluna = 0, valor = 0;
    int end = 0;
    char comando = ' ';
    int qtd = 0;

    iniciarMatriz(matriz, linhas, colunas);

    while(end != 1) {
        printf("\nQuer inserir um valor? [s/n]\n");
    	scanf(" %c", &comando);

	if(comando == 'n') {
	   end = 1;
	}

	if(qtd == (linhas * colunas) - 1) {
	   end = 1;
	}

	if(comando == 's') {
	    printf("\nQual linha vc quer inserir o valor? (de 0 a %i)\n", (linhas-1));
	    scanf("%d", &linha);

	    printf("\nQual coluna vc quer inserir o valor? (de 0 a %i)\n", colunas-1);
	    scanf("%d", &coluna);

	    if(linha >= linhas || linha < 0 || coluna >= colunas || coluna < 0) {
	    	printf("\nInsira um valor valido\n");
		return NULL;
	    }

	    printf("\nQual valor vc quer inserir na linha %d coluna  %d\n", linha, coluna);
	    scanf("%d", &valor);

	    atribuiMatriz(matriz, linha, coluna, valor);

	    qtd++;
	}
    }

    return matriz;
}

MATRIZ* multiplicacao(MATRIZ* matriz1, MATRIZ* matriz2, int linhasMatriz1, int colunasMatriz1, int linhasMatriz2, int colunasMatriz2) {
    MATRIZ* matriz = (MATRIZ*)malloc(sizeof(MATRIZ));
    int i, j, k;
    int teste;

    if(colunasMatriz1 != linhasMatriz2) {
        printf("\nAs matrizes nao podem ser multiplicadas\n");
	return NULL;
    }

    iniciarMatriz(matriz, linhasMatriz1, colunasMatriz2);

    for(i = 0; i < linhasMatriz1; i++) {
       for(j = 0; j < colunasMatriz2; j++) {
          teste = 0;

	  for(k = 0; k < colunasMatriz1; k++) {
	     teste += (valorMatriz(matriz1, i, k) * valorMatriz(matriz2, k, j));
	  }

	  atribuiMatriz(matriz, i, j, teste);
       }
    }

    return matriz;
}
