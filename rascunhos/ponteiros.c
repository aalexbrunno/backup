#include <stdio.h>

typedef struct
{
    char *nome;
    int custo;
    int preco;
    int id;
} dados;

void imprime_produto (dados produto);
void atualiza_produto (dados *produto, char *string, int p, int c, int i);

int main()
{
    dados salgadinho;
    dados biscoito;
    char *string = "Cheetos";
    
    imprime_produto(salgadinho);
    atualiza_produto(&salgadinho, string, 5, 1, 465846);
    imprime_produto(salgadinho);
    //string = "Treloso";
    //atualiza_produto(&biscoito, string, 2, 1, 124145);
    //imprime_produto(biscoito);
    
    return 0;
    
}

void imprime_produto (dados produto)
{
    printf("PRODUTO = %s\n", produto.nome);
    printf("-Custo: %d\n", produto.custo);
    printf("-Preco: %d\n", produto.preco);
    printf("-ID: %d\n\n", produto.id);
    
    return;
}

void atualiza_produto (dados *produto, char *string, int p, int c, int i)
{
    dados *handler = produto;
    
    handler->nome = string;
    handler->preco = p;
    handler->custo = c;
    handler->id = i;
    
    return;
}

