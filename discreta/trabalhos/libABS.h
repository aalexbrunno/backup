#ifndef libABS_biblioteca_h
#define libABS_biblioteca_h

float normaliza(float x, float maxX, float minX);

void aleatorio(int a); 

void reverte(char buffer[]);

void multMatriz(int **arrayA,int **arrayB, int **arrayC,int linhaA, int  colunaA, int linhaB, int colunaB);

void print(int  **resposta, int linha, int coluna);

void scan_matriz(int **array, int linha, int coluna);

int *aleat(int a);

void scan_matriz2(int **array, int linha, int coluna, int *vetor);

/* ---------------- matriz esparsa -------------------------------- */

typedef struct tempNo 
{
    float valor;
    int coluna;
    struct tempNo* prox;
} NO;


typedef NO* PONT;


typedef struct 
{
    PONT* A;
    int linhas;
    int colunas;
} MATRIZ;

void iniciarMatriz(MATRIZ* m, int lin, int col);

_Bool atribuiMatriz(MATRIZ* m, int lin, int col, float val);

float valorMatriz(MATRIZ* m, int lin, int col);

void printMatriz(MATRIZ* m, int lin, int col);

MATRIZ* coisarMatriz(int linhas, int colunas);

MATRIZ* multiplicacao(MATRIZ* matriz1, MATRIZ* matriz2, int linhasMatriz1, int colunasMatriz1, int linhasMatriz2, int colunasMatriz2);


#endif
