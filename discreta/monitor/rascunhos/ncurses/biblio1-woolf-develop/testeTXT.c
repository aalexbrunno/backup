#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
//codigo para adicionar um livro ao arquivo txt

FILE *file;
//int  c;
//c=1;
int a = 1; //variavel que conta as strings


int codigo, cont = 0;
char autor[40];
char titulo[40];
char ano[40];
char local[40];
char cond;
char livro[1000];
char editora[40];

file = fopen("livros03.txt", "r");

while(fgets(livro, 210, file) != NULL)
{
    printf("%s", livro);
    a++; //variavel que conta a quantidade de livros
}

printf("\nCodigo do proximo termo = %d\n", a);

printf("\n");

fclose(file);

while(cond != 'n')
{

codigo = a;

printf("Digite o autor do livro: ");
//fgets(autor, 40, stdin);
scanf("%40[^\n]", autor);
scanf("%c");
autor[strlen(autor) - 1] = '\0';

printf("Digite o titulo do livro: ");
//fgets(titulo, 40, stdin);
scanf("%40[^\n]", titulo);
scanf("%c");
titulo[strlen(titulo) - 1] = '\0';

printf("Digite o ano do livro: ");
//fgets(ano, 40, stdin);
scanf("%40[^\n]", ano);
scanf("%c");
ano[strlen(ano) - 1] = '\0';

printf("Digite o nome da editora: ");
//fgets(editora,40, stdin);
scanf("%40[^\n]", editora);
scanf("%c");
editora[strlen(editora)-1]= '\0';

printf("Digite o local de publicacao do livro: ");
//fgets(local, 40, stdin);
scanf("%40[^\n]", local);
scanf("%c");
local[strlen(local)-1]= '\0';

file=fopen("livros.txt", "a");

if (file == NULL)
{
    printf("\nArquivo não encontrado\n");
    exit(1);
}
else{
        fprintf(file, "%i; ", codigo);
        fprintf(file, "%s; ", autor);
        fprintf(file, "%s; ", titulo);
        fprintf(file, "%s; ", ano);
        fprintf(file, "%s; ", editora);
        fprintf(file, "%s\n", local);

        a = a + 1;
}

fclose(file);

printf("deseja fazer mais alguma alteracao? [y/n] ");
//scanf("%c", &cond[1]);
scanf("%c", &cond);
}

return 0;
}
