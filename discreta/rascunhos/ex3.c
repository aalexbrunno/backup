#include <stdio.h> //biblioteca utilizada podermos usar o printf (quando quero mostrar algo na tela);
#include <stdlib.h> //Para poder usar a função malloc e exit que iremos usar;

typedef struct st_lista 
{
int c;  //o item armazenado do tipo inteiro
struct st_lista *prox; //ponteiro chamado proximo que aponta para uma variável dotipo st_lista; 
}lista; // quandofor declarar uma variável do tipo st_lista eu só precisarei escrever "lista"(facilitar);

// Funções Utilizadas ------------------------------------------------------------------
lista *buscar(lista *cabeca, int x) 
{
    lista *pl=cabeca;
    while(pl!=NULL) 
    {
        if(pl-> c == x)
            return pl;
            pl= pl->prox;
    }
return NULL;
}

void inserir(lista **cabeca, int x)
{
    lista *pl=*cabeca;
    lista *plant=NULL;
        while(pl!=NULL)
        {
            plant=pl;
            pl=pl->prox;
        }
    pl=malloc(sizeof(lista));
    pl->c=x;
    pl->prox=NULL;
        if(plant!=NULL)
            plant->prox=pl;
        else
            *cabeca=pl;
}

void remover(lista **cabeca, lista *r)
{
    lista *pl=*cabeca;
    lista *plant=NULL;
        if(r==NULL)
        return;
    while(pl!=NULL && pl!=r) //ate achar r ou fim
    {
        plant=pl;
        pl=pl->prox;
    }
    if(pl==NULL) //nao achou ou lista vazia
        return;
    if(plant!=NULL) //tem anterior
        plant->prox=pl->prox;
    else //eliminando cabeca
        *cabeca=pl->prox;
        free(pl);
    return;
}

lista *anterior(lista *cabeca, lista *r)
{
    lista *pl=cabeca, *plant=NULL;
    if(r==NULL)
    return NULL;
    while(pl!=NULL && pl!=r)
    {
        plant=pl;
        pl=pl->prox;
    }
    return plant;
}

void imprimir(lista *cabeca)
{
    lista *pl=cabeca;
    while(pl!=NULL)
    {
        printf("%d->",pl->c);
        pl=pl->prox;
    }
    printf("NULL\n");
}


//---------------------------------------------------------------------------------------------

int main(void)
{
    lista *l1=NULL, *b=NULL, *a=NULL;
    printf( "\n-----------------Insere 1, 2 e 3: \n");
    printf("NULL\n");
        inserir(&l1, 1);
        imprimir(l1);
        inserir(&l1, 2);
        imprimir(l1);
        inserir(&l1, 3);
        imprimir(l1);
    printf( "-----------------Busca 2: \n");
    b=buscar(l1, 2);
        if(b!=NULL)
        printf("b->c: %d\n", b->c);
    printf( "-----------------Anterior 2: \n");
    a=anterior(l1, b);
        if(a!=NULL)
        printf("a->c: %d\n", a->c);
    printf( "-----------------Remove 2: \n");
    remover(&l1, b);
        imprimir(l1);
    printf( "\n");
}

