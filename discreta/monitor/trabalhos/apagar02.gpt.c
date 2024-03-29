/* algoritmo funcao_quadratica */

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

typedef short int boolean;
#ifndef TRUE
 #define TRUE 1
#endif
#ifndef FALSE
 #define FALSE 0
#endif

int idx = 0;
char** allocated = NULL;
void collect(char* str) {
  allocated = (char**) realloc((void*)allocated, sizeof(char**)*(idx+1));
  if(!allocated) {
    fprintf(stderr, "Erro ao alocar memória. Abordando...\n");
  }
  allocated[idx++] = str;
}
void cleanup() {
  int i;
  for(i = 0; i < idx; i++) {
    free(allocated[i]);
  }
  free(allocated);
}

void matrix_cpy(void *src, void* dest, int type, int size) {
   int i;
   int *ds,*dd;
   double *fs,*fd;
   char *cs,*cd;
   char **css,**cdd;
   boolean *bs,*bd;
   switch(type) {
     case 'i':
       ds = (int*) src;
       dd = (int*) dest;
       for(i = 0; i < size; i++) dd[i] = ds[i];
       break;
     case 'f':
       fs = (double*) src;
       fd = (double*) dest;
       for(i = 0; i < size; i++) fd[i] = fs[i];
       break;
     case 'c':
       cs = (char*) src;
       cd = (char*) dest;
       for(i = 0; i < size; i++) cd[i] = cs[i];
       break;
     case 's':
       css = (char**) src;
       cdd = (char**) dest;
       for(i = 0; i < size; i++) cdd[i] = css[i];
       break;
     case 'b':
       bs = (boolean*) src;
       bd = (boolean*) dest;
       for(i = 0; i < size; i++) bd[i] = bs[i];
       break;
     default:
       fprintf(stderr, "bug: tipo nao suportado: %c\n", type);
       exit(1);
   }
}
void matrix_init(void *matrix, int type, int size) {
   int i;
   int *d;
   double* f;
   char* c;
   char** s;
   boolean* b;
   switch(type) {
     case 'i':
       d = (int*) matrix;
       for(i = 0; i < size; i++) d[i] = 0;
       break;
     case 'f':
       f = (double*) matrix;
       for(i = 0; i < size; i++) f[i] = 0;
       break;
     case 'c':
       c = (char*) matrix;
       for(i = 0; i < size; i++) c[i] = 0;
       break;
     case 's':
       s = (char**) matrix;
       for(i = 0; i < size; i++) s[i] = 0;
       break;
     case 'b':
       b = (boolean*) matrix;
       for(i = 0; i < size; i++) b[i] = 0;
       break;
     default:
       fprintf(stderr, "bug: tipo nao suportado: %c\n", type);
       exit(1);
   }
}
void imprima(char* format, ...) {
   va_list args;
   va_start(args, format);
   int d;
   double f;
   int c;
   char* s;
   int b;
   while(*format) {
     switch(*format) {
       case 'd':
         d = va_arg(args, int);
         printf("%d", d); 
         break;
       case 'f':
         f = va_arg(args, double);
         printf("%.2f", f);
         break;
       case 'c':
         c = va_arg(args, int);
         printf("%c", c);
         break;
       case 's':
         s = va_arg(args, char*);
         if(!s) {
           printf("(nulo)");
         } else {
           printf("%s", s);
         }
         break;
       case 'b':
         b = va_arg(args, int);
         if(b) {
           printf("verdadeiro");
         } else {
           printf("falso");
         }
         break;
       default:
         fprintf(stderr, "bug: modificador nao suportado: %c\n", *format);
         exit(1);
     }
     format++;
   }
   va_end(args);
   printf("\n");
}

int leia_inteiro() {
   int i = 0;
   scanf("%d", &i);
   return i;
}
char leia_caractere() {
   char c = 0;
   scanf("%c", &c);
   return c;
}
double leia_real() {
   double f = 0;
   scanf("%lf", &f);
   return f;
}
char* leia_literal() {
   char *lit = NULL;
   size_t  len = 0;
   int read;
   if((read = getline(&lit, &len, stdin)) == -1) {
     fprintf(stderr, "Erro ao ler dados da entrada\n");
     exit(1);
   }
   lit[strlen(lit)-1] = 0;
   collect(lit);
   return lit;
}
boolean leia_logico() {
   char* logico;
   logico = leia_literal();
   if(strcmp("falso",logico) == 0) {
      return FALSE;
   } else if(strcmp("0",logico) == 0) {
      return FALSE;
   }
   return TRUE;
}
int str_strlen(char* str) {
   if(str == 0) {
     return 0;
   }
   return strlen(str);
}
boolean str_comp(char* left, char* right) {
   if (!left && !right) {
      return TRUE;
   }
   if (!left || !right) {
      return FALSE;
   }
   if(str_strlen(left) != str_strlen(right)) {
     return FALSE;
   }
   if((str_strlen(left)==0) && (str_strlen(right)==0)) {
     return TRUE;
   }
   return (strcmp(left, right)==0);
}
char* return_literal(char* str) {
  char* lit = NULL;
  lit = (char*) malloc(sizeof(char)*(str_strlen(str)+1));
  strcpy(lit, str);
  collect(lit);
  return lit;
}

double _raiz(double _x);
double _x = 0;

int main(void) {
   _raiz(_x);
   cleanup();
   return EXIT_SUCCESS;
}
double _raiz(double _x) {
   int _i = 0;
   double _r = 0;
   double _a = 0;
   double _b = 0;
   double _c = 0;
   double _x1 = 0;
   double _x2 = 0;
   imprima("s", "vamos calcular as raizes da funcao quadratica ax^2 + bx + c\n\n");
   imprima("s", "digite o valor de a\n");
   _a = leia_real();
   imprima("s", "digite o valor de b\n");
   _b = leia_real();
   imprima("s", "por fim digite o valor de c\n");
   _c = leia_real();
   _x = 1;
   _r = ((_b*_b)-((4*_a)*_c));
   if(((_r>=0)&(_a!=0))) {
      while((_i!=10)) {
         _i = (_i+1);
         _x = (_x-(((_x*_x)-_r)/(2*_x)));
      }
      _x1 = (((-_b)+_x)/(2*_a));
      _x2 = (((-_b)-_x)/(2*_a));
      imprima("sf", "o valor de x1 eh:", _x1);
      imprima("sf", "o valor de x2 eh:", _x2);
   } else {
      imprima("s", "nao calculo discriminante negativo ou A igual a zero \n");
      imprima("sf", "o valor do seu Delta foi : ", _r);
      imprima("sf", "o valor do seu A foi : ", _a);
   }
   
   return _x;
}
