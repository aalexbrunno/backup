#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (void)
{
	
/*	
    char palavra1[30];	
    char palavra2[30];
	char palavra3[30];
    char aux;

    printf("escreva o nome do pais onde voce estudou\n");

    setbuf(stdin, 0);



    while(aux != '\n')
    {
        fgets(palavra1, 300, stdin);
        palavra1[strlen(palavra1)-1] = '\0';
        
        
        fgets(palavra2, 300, stdin);
        palavra2[strlen(palavra2)-1] = '\0';
        
        
        fgets(palavra3, 300, stdin);
        palavra3[strlen(palavra3)-1] = '\0';
        
        aux = getchar();

    
    
    }
    
    
//    pais1[strlen(pais1)-1] = '\0';
    
   printf("\n\n");  
   printf("%s \n", palavra1);
   printf("%s \n", palavra2);
   printf("%s \n", palavra3);
  
   */


//codigo para adicionar um livro ao arquivo txt

    FILE *file;
//int  c;
//c=1;
    int a = 1, cont = 0; //variavel que conta as strings


    int codigo;
    char autor[40];
    char titulo[40];
    char ano[40];
    char local[40];
    char cond[30];
    char livro[1000];
    char editora[40];

    file = fopen("livros.txt", "r");

    while(fgets(livro, 1000, file) != NULL)
    {
        printf("%s", livro);
        a++; //variavel que conta a quantidade de livros
    }

    printf("\nCodigo do proximo termo = %d\n", a);

    printf("\n");

    fclose(file);

    while(cond[cont] != 'n')
    {
    
    cont++;
    codigo = a;

//    fflush(stdin);
    setbuf(stdin, 0);
    
    printf("Digite o autor do livro: ");
    fgets(autor, 40, stdin);
//     scanf(livros.txt,"%[^\n]s", autor);
//    scanf("%[^\n]", autor);

    autor[strlen(autor) - 1] = '\0';
    
    printf("Digite o titulo do livro: ");
    fgets(titulo, 40, stdin);
//    scanf(livros.txt,"%[^\n]s", titulo);
    
//    scanf("%[^\n]", titulo);
    titulo[strlen(titulo) - 1] = '\0';

    printf("Digite o ano do livro: ");
   fgets(ano, 40, stdin);
//    scanf(livros.txt,"%[^\n]s", ano);
    
//    scanf("%[^\n]", ano);
    ano[strlen(ano) - 1] = '\0';

    printf("Digite o nome da editora: ");
    fgets(editora,40, stdin);
//    scanf(livros.txt,"%[^\n]s", editora);
    
//    scanf("%[^\n]", editora);
    editora[strlen(editora)-1]= '\0';

    printf("Digite o local de publicacao do livro: ");
    fgets(local, 40, stdin);
    
//   scanf(livros.txt,"%[^\n]s", local);
    
    
//    scanf("40%[^\n]", local);
    local[strlen(local)-1]= '\0';

    file=fopen("livros.txt", "a");

    if (file == NULL)
    {
        printf("\nArquivo não encontrado\n");
        exit(1);
    }
    else
    {
        fprintf(file, "%i; ", codigo);
        
    //    fflush(stdin);
        
        
        fprintf(file, "%s; ", autor);
        
        
        fprintf(file, "%s; ", titulo);
        
        
        fprintf(file, "%s; ", ano);
        
        
        fprintf(file, "%s; ", editora);
        
        
        fprintf(file, "%s\n", local);

        a = a + 1;
    }

    fclose(file);

    printf("deseja fazer mais alguma alteracao? [y/n] ");
    scanf("%c", &cond[cont]);

}

    
   return EXIT_SUCCESS;
}
    


