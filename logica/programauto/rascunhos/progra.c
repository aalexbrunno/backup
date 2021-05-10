#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(void)
{
    int vetor[20] = {0};
    int maior=0;
    int menor=0;
    int media=0;

 //   srand(time(NULL));

    printf("Gerando valores aleatorios\n");
 //   sleep(1);

    for(int i = 0; i < 20; i++)
    {
        vetor[i] = rand() % 10000;

        if(vetor[i] > maior)
            maior = vetor[i];

        if(vetor[i] < menor)
            menor = vetor[i];
    }

    media = (maior + menor) / 2;

    printf("Maior valor: %i\n", maior);
    printf("Menor valor: %i\n", menor);
    printf("Media entre o maior e o menor: %i\n", media);

    return EXIT_SUCCESS;
}
