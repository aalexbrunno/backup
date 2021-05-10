#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rando(int x);
void copy(int *p1, int *p2, int tam);
int *sort(int *p1, int *tam);

int main(void)
{
    srand(time(NULL));
    int *ptr, *copia;
    int intervalo = 15,i=0;
    int tam = rando(intervalo);
    ptr = calloc(tam,sizeof(int));

    for(i=0;i<tam;i++)
    {
        ptr[i] = rando(intervalo);
        printf("%d ",ptr[i]);
    }
    ptr = sort(ptr, &tam);
    printf("\n");
    printf("resposta:\n");
    for(i=0;i<tam;i++)
    {
        printf("%d ",ptr[i]);
    }

    free(ptr);
    return 0;
}

int rando(int x)
{
    return (rand()%x)+1;
}

void copy(int *p1, int *p2, int tam)
{
    for(int i=0; i<tam;i++)
    {
        p2[i] = p1[i];
    }
}

int *sort(int *p1, int *tam)
{
    int *aux = calloc(*tam,sizeof(int));
    int flag=0,i=0,j=0,auxiliar=0,indice=0;

    copy(p1,aux,*tam);
    for(i=0;i<*tam;i++)
    {
        flag = aux[i];
        for(j=0;j<*tam;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(aux[j]==flag)
            {
                aux[j]=0;
            }
        }
    }
    flag=0;
    for(i=0;i<*tam;i++)
    {
        if(aux[i]==0)
        {
            flag++;
        }
    }
    p1 = calloc(*tam-flag, sizeof(int));
    for(i=0;i<*tam;i++)
    {
        if(aux[i]!=0)
        {
            p1[indice] = aux[i];
            indice++;
        }
    }

    for(i=0;i<*tam-flag;i++)
    {
        for(j=0;j<*tam-flag-1;j++)
        {
            if(p1[j]>p1[j+1])
            {
                auxiliar = p1[j];
                p1[j] = p1[j+1];
                p1[j+1] = auxiliar;
            }
        }
    }
    *tam -=flag;
    free(aux);
    return p1;
}
