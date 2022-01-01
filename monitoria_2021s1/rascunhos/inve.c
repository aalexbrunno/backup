// programa que lê uma string e retorta ela invertida
//#include <libceci.h>
//#include <libceci.c>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//declaração da função
void contrario(char palavra[]);

int main(void){

char palavra[300];

printf("Qual a palavra deseja que o progrma inverta? ");
// scanf("%s", palavra);

fgets(palavra, 300, stdin); // coloquei para pegar espaços

//limpa as casas nao utilizadas na string
palavra[strlen(palavra)-1] = '\0';



contrario(palavra);

printf("a palavra invertida fica : %s\n", palavra);
return 0;
}


void contrario(char palavra[])
{
        int c;
        char contrario;
        int tam = strlen(palavra);

  for(c=0 ; c < (tam/2) ; c++)//loop que muda os caracteres de posicao
  {
  contrario = palavra[c];
  palavra[c] = palavra[tam-c-1];
  palavra[tam-c-1] = contrario;
  }
}
