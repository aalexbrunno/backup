#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void inverter(char vet[]);
char* inverter2(char vet[]);


int main(void)
{

    // char palavra[] = {"Muito bem feito!"}; 
       
    char palavra[300];

    printf("Qual a palavra deseja que o progrma inverta? ");
    // scanf("%s", palavra);

    fgets(palavra, 300, stdin); // coloquei para pegar espaços

    //limpa as casas nao utilizadas na string
    palavra[strlen(palavra)-1] = '\0';

    
    
    char *p;

    printf("%s\n", palavra);
    //inverter(palavra);


    p = inverter2(palavra);
    printf("%s\n", p);

    return 0;
}


void inverter(char vet[]){
    int i, aux, fim, tam = strlen(vet);

    fim = tam - 1;
    for(i = 0; i < tam/2; i++){
        aux = vet[i];
        vet[i] = vet[fim];
        vet[fim] = aux;
        fim--;
    }
}

char* inverter2(char vet[]){
    int i, fim, tam = strlen(vet);
    char *novo = malloc((tam + 1) * sizeof(char));

    fim = tam - 1;
    for(i = 0; i < tam; i++){
        novo[fim] = vet[i];
        fim--;
    }
    novo[i] = '\0';
    return novo;
}




