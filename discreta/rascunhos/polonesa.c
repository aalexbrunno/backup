// Este programa simula uma calculadora RPN. O usuário deve
// digitar uma expressão em notação RPN. À medida que a 
// expressão é digitada, o programa exibe o valor da 
// subexpressão corrente (como se fosse o mostrador de uma 
// calculadora). Cada linha digitada deve conter um número, 
// um operador (+, -, *, /), ou um dos seguintes comandos:
//   Q (quit):  para sair do programa,
//   C (clear): para limpar a calculadora,
//   S (stack): para exibir o contéudo da pilha.
// Restrição 1: cada linha deve ter no máximo 100 caracteres.
// Restrição 2: a pilha é limitada a 100 elementos (portanto, 
// não posso garantir o funcionamento se a expressão tiver 
// mais que 100 operandos).



////////////////////////////////////////
// Seção 1: Bibliotecas e tipos de dados
////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h> // preciso de atof
#include <ctype.h>  // preciso de isdigit, toupper etc.

typedef char* string;
typedef enum {FALSE, TRUE} bool;



/////////////////////////////////////////////////////////////
// Seção 2: Pilha (= stack)
// O programa armazena os resultados intermediários em uma 
// pilha de números do tipo double. Essa estrutura está 
// sujeita a duas operações apenas:
//   a operação empilha (= push) acrescenta um novo elemento 
//   ao topo da pilha; 
//   a operação desempilha (= pop) retira um elemento do topo 
//   da pilha.
/////////////////////////////////////////////////////////////

// A pilha residirá no vetor stk[0..stkcount-1], sendo 
// stkcount - 1 o índice do tipo da pilha. As variáveis  
// stk[] e stkcount serão globais.

#define MaxStackSize 100
double stk[MaxStackSize];
int stkcount;

// Operação empilha: coloca element na pilha 
// stk[0..stkcount-1].

void Push( double element)
{
   if (stkcount == MaxStackSize) 
   {   
       printf( "Stack size exceeded.\n");
      exit( EXIT_FAILURE);
   }
   stk[stkcount++] = element;
}

// Operação desempilha: retira o elemento que está 
// no topo da pilha.

double Pop( void)
{
   if (stkcount == 0) {
      printf( "Pop of an empty stack.\n");
      exit( EXIT_FAILURE);
   }
   return stk[--stkcount];
}



//////////////////////////////////////////////////////////
// Seção 3: Código do programa de simulação da calculadora
//////////////////////////////////////////////////////////

void ApplyOperator( char op);
void DisplayStack( void);
string getLine( void);

int main( void)
{
   string line;
   char ch;

   printf( "RPN Calculator Simulation\n");
   stkcount = 0;
   while (TRUE) 
   {
      printf( "> ");
      line = getLine();
      ch = toupper( line[0]);
      switch (ch) 
      {
         case 'Q': return 0;
         case 'C': stkcount = 0; break;
         case 'S': DisplayStack(); break;
         default : if (isdigit( ch)) 
                      Push( atof( line));
                   else
                      ApplyOperator( ch);
                   break;
        }
   }
}


// Esta função aplica o operador op aos dois operandos que 
// estão no topo da pilha stk[]. A função supõe que o 
// usuário não vai tentar divisão por zero.

void ApplyOperator( char op)
{
   double lhs, rhs, result;
   
   rhs = Pop(); // operando direito
   lhs = Pop(); // operando esquerdo
   switch (op) {
      case '+': result = lhs + rhs; break;
      case '-': result = lhs - rhs; break;
      case '*': result = lhs * rhs; break;
      case '/': result = lhs / rhs; break;
      default : printf( "Illegal operator\n"); 
                exit( EXIT_FAILURE);
   }
   printf( "%g\n", result);
   Push( result);
}


// Imprime o conteúdo da pilha stk[0..stkcount-1].

void DisplayStack( void)
{
   int i;
   
   printf( "Stack: ");
   if (stkcount == 0) 
      printf( "empty\n");
   else {
      for (i = 0; i < stkcount; i++) {
         if (i > 0) printf( ", ");
         printf( "%g", stk[i]);
      }
      printf( "\n");
   }
}


// Lê uma linha do teclado e devolve a linha na forma de 
// uma string. A linha deve ter no máximo 100 caracteres.
// Esta função foi inspirada na GetLine da biblioteca 
// simpio de Eric Roberts, mas é bem mais simples que 
// aquela.

string getLine( void)
{
   string line;
   int n, ch;
   
   n = 0;
   line = malloc( 100+1);
   if (line == NULL) exit( EXIT_FAILURE);
   while ((ch = getc( stdin)) != '\n') 
   {

      if (n >= 100) 
      {
         free( line);
         exit( EXIT_FAILURE);
      }
      line[n++] = ch;
   }
   line[n] = '\0';
   return line;
}
