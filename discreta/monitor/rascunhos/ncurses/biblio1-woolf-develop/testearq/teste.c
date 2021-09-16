#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split(char* string);

int main(void)
{
    char* string = "1;Stephen Hawking;A Brief History of Time: From the Big-Bang to Black Holes;Bantam;London;1988;1;9780553380163;2";

    split(string);
}

void split(char* string)
{
    char* index = (char*)malloc(strlen(string) * sizeof(char));
    char* autor = (char*)malloc(strlen(string) * sizeof(char));
    char* titulo = (char*)malloc(strlen(string) * sizeof(char));
    char* editora = (char*)malloc(strlen(string) * sizeof(char));
    char* local = (char*)malloc(strlen(string) * sizeof(char));
    char* ano = (char*)malloc(strlen(string) * sizeof(char));
    char* edicao = (char*)malloc(strlen(string) * sizeof(char));
    char* isbn = (char*)malloc(strlen(string) * sizeof(char));
    char* quantidade = (char*)malloc(strlen(string) * sizeof(char));
    int count = 0;
    int separatorCount = 0;

    for(int i = 0; i < (int)strlen(string); i++)
    {
        if(string[i] == ';') {
            separatorCount++;
            count = 0;
        }
        else {
            switch(separatorCount)
            {
                case 0:
                    index[count] = string[i];
                    count++;
                    break;
                case 1:
                    autor[count] = string[i];
                    count++;
                    break;
                case 2:
                    titulo[count] = string[i];
                    count++;
                    break;
                case 3:
                    editora[count] = string[i];
                    count++;
                    break;
                case 4:
                    local[count] = string[i];
                    count++;
                    break;
                case 5:
                    ano[count] = string[i];
                    count++;
                    break;
                case 6:
                    edicao[count] = string[i];
                    count++;
                    break;
                case 7:
                    isbn[count] = string[i];
                    count++;
                    break;
                case 8:
                    quantidade[count] = string[i];
                    count++;
                    break;
                default:
                    count = 0;
                    break;
            }
        }
    }

    index[strlen(index) + 1] = '\0';
    autor[strlen(autor) + 1] = '\0';
    titulo[strlen(titulo) + 1] = '\0';
    editora[strlen(editora) + 1] = '\0';
    local[strlen(local) + 1] = '\0';
    ano[strlen(ano) + 1] = '\0';
    edicao[strlen(edicao) + 1] = '\0';
    isbn[strlen(isbn) + 1] = '\0';
    quantidade[strlen(quantidade) + 1] = '\0';

    printf("\nindex: %s\n", index);
    printf("\nautor: %s\n", autor);
    printf("\ntitulo: %s\n", titulo);
    printf("\neditora: %s\n", editora);
    printf("\nlocal: %s\n", local);
    printf("\nano: %s\n", ano);
    printf("\nedicao: %s\n", edicao);
    printf("\nisbn: %s\n", isbn);
    printf("\nquantidade: %s\n", quantidade);

    free(index);
    free(autor);
    free(titulo);
    free(editora);
    free(local);
    free(ano);
    free(edicao);
    free(isbn);
    free(quantidade);
}

