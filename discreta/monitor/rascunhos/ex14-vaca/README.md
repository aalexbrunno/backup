# Programa da Vaquinha




## Introdução

O algoritmo determina, baseado em 3 variáveis, a, b e c, se uma pessoa ganhou ou não um prêmio, no caso uma "vaquinha".

As variáveis são aleatórias e devem ser sorteadas com as faixas de valores definidas abaixo:

a = um dado de 6 faces, valores inteiros na faixa de [1, 6]
b = uma porcentagem, valores inteiros na faixa de [0, 100]
c = a temperatura do polo norte, valores inteiros na faixa de [-40, +10]


Com esses valores em mãos (sorteados antecipadamente, veja funções srand() e rand() para sorteio), o programa então irá imprimir se a pessoa ganhou ou não.




## A função vaquinha_a(), no exNa.c: 

O primeiro programa foi escrito por um programador muito inexperiente que não conhecia nada de legibilidade de código e simplificação de expressões lógicas (pense em problema de Post, mapas de Karnaugh e simplificação por equivalências tautológicas) e sua relação com tabelas verdade. 


Deste modo, o primeiro programa é de difícil leitura e envolve muitos comandos if-else aninhados.


Complete, no exNa.c, o restante do programa, inclua as bibliotecas necessárias e a função main(), o protótipo e o que mais for necessário para criar um programa completo para que a função vaquinha_a() abaixo dê o resultado esperado.


Atenção: Não altere a função vaquinha_a(). 

Ela apesar de estar mal escrita, é o enunciado do problema e sua resposta está correta (apesar de conter erros de lógica).



/* ----- inicio da vaquinha_a() ----- */

void vaquinha_a(int a, int b, int c)
{
    printf("(funcao A): Voce... ");
    if(a <= 6 && a > 4)
        if(b < 40)
            if(b < c)
                printf("ganhou a vaquinha!\n");
            else
                printf("nao ganhou a vaquinha!\n");
        else
            if(c >= a)
                printf("ganhou a vaquinha!\n");
            else
                printf("nao ganhou a vaquinha!\n");
    else
        if(a == 6)
            printf("ganhou a vaquinha!\n");
        else
            if(a == 4)
                if(c < b)
                    printf("ganhou a vaquinha!\n");
                else
                    printf("nao ganhou a vaquinha!\n");
            else
                printf("nao ganhou a vaquinha!\n");

}

/* ----- fim da vaquinha_a() ----- */




## A função vaquinha_b(), no exNb.c: 


No exNb.c seu objetivo é criar uma função mais simples. A função vaquinha_b() só poderá conter um único par if-else, e dentro da condição deste if() terá que incluir toda a lógica equivalente à função vaquinha_a(). 

Atenção: as respostas de ambas funções "vaquinha" devem ser idênticas para cada trinca (a, b, c) idêntica.

Se a sua função vaquinha_b() não der a mesma resposta que a vaquinha_a(), é a sua função vaquinha_b() que deverá ser ajustada para corresponder à lógica embutida na vaquinha_a(). Novamente: não altere a função vaquinha_a().


O template que você deve usar para a função vaquinha_b() é dado abaixo, para ser incluído no exNb.c em um programa completo que permita rodar e visualizar a resposta:



/* ----- inicio da vaquinha_b() ----- */

void vaquinhab(int a, int b, int c)
{
    printf("(funcao B): Voce... ");
    if(....................................... )  /* modificar apenas essa linha! */
        printf("ganhou a vaquinha!\n");
    else
        printf("nao ganhou a vaquinha!\n");
}

/* ----- fim da vaquinha_b() ----- */




## O programa exNc.c para comparações:


No exNc.c você deverá provar através de experimentação que ambas as funções estão dando o mesmo resultado.


Você criará uma função principal main() que irá sortear a trinca de valores (a, b, c) e irá chamar ambas as funções vaquinha_a() e vaquinha_b() e comparar os resultados (ganhou ou não ganhou).

Você irá realizar 100.000 (cem mil) experimentos (em um laço na função main) e imprimir as estatísticas dos resultados após completar a simulação:


* Total: 100000 iterações
* Funções A e B retornaram o mesmo valor em: X experimentos
* Funções A e B retornaram diferente em: Y experimentos


O seu programa, claro, estará correto apenas se X=100000 e Y=0, ou seja, as funções são equivalentes (pelo menos estatisticamente).


Isso é o princípio da simulação de Monte Carlo (há mais por trás deste tipo de simulação, mas isso já dá uma introdução ao assunto).


Você deve alterar o protótipo das funções para que ao invés de "imprimir" ela deverá retornar VERDADEIRO (valor 1) ou FALSO (valor 0), já que não queremos "ler" o resultado, queremos apenas computar as estatísticas.

O novo protótipo será:

int vaquinha_a(int a, int b, int c);
int vaquinha_b(int a, int b, int c);

E dentro dos if's e else's no lugar de um printf() teremos um return, da forma:

if( ... ganhou... ) ou else...
    return 1; /* ao inves de imprimir printf("ganhou a vaquinha!\n"); */

if( ... perdeu... ) ou else...
    return 0; /* no lugar de printf("nao ganhou a vaquinha!\n"); */
    


    
---

Bom trabalho!
Prof. Dr. Ruben Carlo Benante
2021-07-22


