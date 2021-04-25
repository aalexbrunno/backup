// #funções
#include <stdio.h>
#include <stdlib.h>

// ETAPA 1 - Criar a função

// ETAPA 2 - Declarar o prototipo

// ETAPA 3 - Chamar a função na main

// anatomia da função:            Argumentos
//                 Nome da função   __|__  
//                         |       |     |
//                  int função(int x, int y)
//                   |
//          Tipo de dado retornado  

void soma(int a, int b);
int soma_int(int a, int b);
int *create_array(int vet[]);
float pi();
char to_lower(char l);
void escopo(int *x);

int main(void)
{
    int valor; //    ALERTA DE SPOILER      *p = calloc(10, sizeof(int)), array[10];
    char letra;
    int v =5;
    
    printf("diga uma letra em maiusculo para ser convertida:\n");
    scanf(" %c", &letra);
    printf("Minusculo: %c\n",to_lower(letra));
    
    printf("V: %d\n",v);
    escopo(&v);
    printf("V: %d\n",v);

    soma(1,5);
    printf("1 + 5 = %d\n",soma_int(1,5));  // soma_int(6,3) = 9

    printf("pi = %f\n",pi());
    

    // for(int i=0;i<10;i++) // valor inicial de p
    // {
    //     printf("%d\n",p[i]);
    // }
    
    // p=create_array(vetor);
    
    // for(int i=0;i<10;i++) // valor final de p
    // {
    //     printf("pont: %d\n",p[i]);
    // }

    // vetor = ponteiro
    // matriz = vetor de vetores = ponteiro de ponteiros
    
    //int *p
    //int **p = matriz = vetor de vetores

    return 0;
}

int *create_array(int vet[])
{
    for(int i=0;i<10;i++)
    {
        vet[i] = i;
    }
    // for(int i=0;i<10;i++)
    // {
    //     printf("%d\n",vet[i]);
    // }
    return vet;
}

void soma(int a, int b)
{
    printf("soma eh %d\n",a+b);
}

int soma_int(int a, int b)
{
    return a+b;
}

float pi()
{
    float pi_num = 3.141592;
    return pi_num;
}

char to_lower(char l)
{
    return l+32;
}

void escopo(int *x)
{
    *x+=1;
}