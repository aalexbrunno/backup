#include<stdio.h>


int main(void)
{
    int valor=0,x=0;
    char resposta='0';

    printf("voce quer adicionar um valor?\n");
    scanf(" %c",&resposta);
    if(resposta == 's') // se respostar for 's' o bloco de cadigo é executado
    {
        do // faça
        {
            printf("digite o valor:\n");
            scanf("%d",&x);
            valor+=x; //valor = valor+x;

            printf("ainda quer adicionar outro valor?\n");
            scanf(" %c",&resposta);

        } while (resposta=='s'); // enquanto a condição for verdadeira
    }
    

    printf("seu valor final foi: %d\n",valor);

    return 0;    
}