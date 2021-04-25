#include<stdio.h>

// programa que recebe a altura da piramide e imprime a mesma

int main(void)
{
    int i=0,j=0,altura=0;

    printf("digite a altura da piramide: \n");
    scanf("%d", &altura);
    printf("\n");

    for(i=0;i<altura;i++) // controla cada camada da piramide
    {
        for(j=0;j<=i;j++) // imprime o corpo da piramide
        {
            printf("%c",'*');
        }
        printf("\n"); // pula para proxima linha
    }
}

