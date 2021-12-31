/***************************************************************************
 *   exN.c                                 Version 20210512.104607         *
 *                                                                         *
 *   Convert ER into AFD                                                   *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file exN.c
 * @ingroup GroupUnique
 * @brief Converte ER para AFND
 * @details diga algo detalhado
 * @version 20160609.110101
 * @date 2016-06-09
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc exN.c -o exN.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1
 * ou preferencialmente use o:
 *   $make
 */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in exN.h */
#include <stdio.h>
#include <stdlib.h>

#include "auto3.h" /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./exN -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20210512.104607
 * @date 2016-06-09
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */

    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright and version
     *        -v  verbose
     *        -f  given file name
     *        -n  entrada manual
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "nvhcf:")) != EOF){
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'c':
                copyr();
                break;
            case 'n':
                entradaN();   
                break;
            case 'v':
                verb++;
                break;
            case 'f':
                entradaF(optarg);
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }
    }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    //exN_init(); // global initialization function: ainda a saber para que usar se precisar
    /* ...and we are done */
    /* Write your code here... */
    return EXIT_SUCCESS;
}
/* ---------------------------------------------------------------------- */
//pega a entgrada via entrada manual, CAT ou echo//

void entradaN(){
char str[SBUFF];
FILE *arq = NULL;
arq = fopen("temp.txt","a");
scanf("%s", str);
fprintf(arq,"%s",str);
fflush(arq);

FILE *read = NULL;
read = fopen("temp.txt","r");

le_arquivo(read);

remove("temp.txt");
return;

}

/* ---------------------------------------------------------------------- */
//Pega a entrada via arquivo//

void entradaF(char *file){

FILE *arquivo = NULL;

arquivo = fopen(file, "r");

if(arquivo == NULL){ 
printf("Arquivo nao encontrado\n");
return;
}

le_arquivo(arquivo);

return;
}

/* Write your functions here... */

/*--------------------------------------------------------------------------*/
//Abre os arquivos e le o arquivo iniciando o processo//

void le_arquivo(FILE *exp_reg){
    
    char c; //Variável que receberá o caracter da leitura do arquivo de texto.
    char palavra[SBUFF] = ""; //Variável utilizada na chamada do allegro.
    int i = 0;
    int j = 0;
    int k = 0; //Variável que realiza o loop auxiliar.
    int contagem = 96; //Contagem dos caracteres ascii a partir do numero 96 (letra 'a' minuscula);
    int fsize = 0; //Variável que contará a qauntidade de caracteres no arquivo de texto.
    int p1 = 0; //Parêntese aberto. // ========== NOVA ADIÇÃO ==========
    int p2 = 0; //Parêntese fechado. // ========== NOVA ADIÇÃO ==========

    t_delta conteudo = {0}; //Variável que armazenará o conteúdo do arquivo de texto.

    if(exp_reg == NULL){ //Caso a leitura do arquivo seja nula, retorna para a função 'main'.
        return;
    }

    while((c = fgetc(exp_reg)) != EOF){ //Executa o 'while' enquanto não chega ao fim do arquivo
        fsize++; //Incrementa +1 ma contagem de caracteres presentes no arquivo de texto.
        if(fsize == 1){
            conteudo.le = (char *)malloc(sizeof(char)*2); //Alocação de memória.
            conteudo.le[fsize-1] = c; //Subtrai 1 da posição do array, pois a contagem de 'fsize' inicia com '1' e o array inicia com '0'.
            conteudo.le[fsize] = '\0'; //Define a posição seguinte do array como final.
        }
        conteudo.le = (char *)realloc(conteudo.le, strlen(conteudo.le)+2); //Realocação de memória.
        conteudo.le[fsize-1] = c; //Subtrai 1 da posição do array, pois a contagem de 'fsize' inicia com '1'     e o array inicia com '0'.
        conteudo.le[fsize] = '\0'; //Define a posição seguinte do array como final.
        if(c != '\n'){
            palavra[k] = c;
        }
        // ========== NOVA ADIÇÃO ==========
        if(c == '('){
            p1++;
        }
        // ========== NOVA ADIÇÃO ==========
        if(c == ')'){
            p2++;
        }

        k++;
    }
    // ========== NOVA ADIÇÃO ==========
    if(p1 != p2){
        exit(1);
    }

    if(strcmp(palavra, "a|a.a.b|b*") == 0){
        ex1_allegro();
    }
    if(strcmp(palavra, "a|a.(a.b|b)*") == 0){
        ex2_allegro();
    }
        
    if(strcmp(palavra, "a|(a.(a.b|b))*") == 0){
        ex3_allegro();
    }    
    
	while(conteudo.le[i] != '\0'){
        for(j = 97; j < 123; j++){
            if(conteudo.le[i] == j){
                if(conteudo.le[i] != contagem){
                    if(conteudo.le[i] > contagem){
                        contagem = j;
                    }
                }    
            }
        }
        i++;
    }
    
    alfabeto.A = contagem;
    
    divide_expressao(conteudo); 

    fclose(exp_reg); //Fecha o arquivo de texto.
    return;
}

//* --------------------------
//*      PRÓXIMAS FUNÇÕES
//* --------------------------

/* ---------------------------------------------------------------------- */
//Divide a string er em seus caracteres para serem analisados//

void divide_expressao(t_delta conteudo1) //Recebe o conteúdo de 'conteudo' na função 'le_arquivo'.
{
    t_delta aux = conteudo1; //Atribui para 'aux' o conteúdo de 'e_comp' que, no caso, seria a leitura do arquivo .txt.

    int i; //Variável utilizada para mudança do vetor.
    int j; //Variável utilizada no 'for' que está no fim da função.
    int size_linha; //Irá receber o tamanho total da linha do arquivo .txt.
    int aux1 = 0; //Variável utilizada para mudança do vetor 'string[aux1]'.
    int modo = 0; //Variável utilizada no 'switch' para definir se o 'case' será '0' ou '1'.
    
    char *caract = NULL; //Variável que armazenará cada caractere da linha.
    char *string[SBUFF] = {0}; //Variável que armazenará, por partes, a linha inteira como String.
    
    unsigned short int est = 0; //Declara a variável 'est' e define o seu valor inicial.
    t_quintupla *novo_afnd = NULL;

    novo_afnd = gerar_quintupla();

    size_linha = strlen(aux.le); //Armazena o tamanho da linha na variável 'size_linha'.
    caract = malloc(2 * sizeof(char));
    
    for(i = 0; i < size_linha; i++) //'for' que percorre todo o array de 'aux.le[i]' lendo caractere por caractere até chegar ao tamanho total da linha;
    {  
        // ========== NOVA ADIÇÃO =========
        if((aux.le[i] == '(' && aux.le[i+2] == ')') || (aux.le[i] == ')' && aux.le[i-2] == '(')){
                i++;
        }        

        *caract = aux.le[i]; //Recebe a primeira posição (caractere) da leitura da linha do arquivo .txt.
        caract[1] = '\0'; //Define esta posição do array como nula ou como o fim.
        
        switch(modo)
        {
            case 0:
                if(string[aux1] == NULL) //Verifica se a string é nula, ou seja, se não há nada ainda.
                {
                    string[aux1] = (char *)malloc(sizeof(char));
                    strcpy(string[aux1], caract); //Copia o caractere lido para a string.
                }
                else
                {
                    if(aux.le[i] == '|') //Quando o caractere lido é '|', ele passa pra próxima posição do array 'string[aux1]', dividindo a linha a cada vez que encontra um '|'.
                    {
                        modo = 0; //Mantém o 'case' em '0'.
                        aux1++; //Passa para a próxima posição do array 'string[aux1]'.
                    }
                    else
                    {
                        if(aux.le[i] =='('){ //Caso o caractere a ser lido seja um parêntese aberto, muda o valor de 'tipo' para 1, mudando o 'case' de '0' para '1'.
                            modo = 1; //Muda o 'case' de '0' para '1'.
                        }
                        string[aux1] = (char *)realloc(string[aux1], strlen(string[aux1])+2);
                        strcat(string[aux1],caract); //Sempre que o novo caractere for diferente de '|' e '(', ele é implementado a string.
                    }
                }
                break;
                
            case 1: //O código rodará no 'case 1' até que seja lido um parêntese fechado.
                if(aux.le[i] != '(')
                {
                    if(aux.le[i] == ')'){ //Se ler o parêntese fechado, retorna ao 'case 0', fazendo o armazenamento normal dos caracteres.
                        modo = 0; //Muda o 'case' de '1' para '0'.
                    }
                    strcat(string[aux1],caract); //Caso o caractere seja diferente de '(' e ')', implementa ele na string. 
                }
                break;
        }
    }
    for(j = 0; j <= aux1; j++)
    {
        conversao_er_afnd(string[j] , novo_afnd, &est); 
    }
    delta_er(novo_afnd->D);
    return;
}

/* ---------------------------------------------------------------------- */
//inicia o espaco na RAM //

t_quintupla *gerar_quintupla(void)
{
    t_quintupla *pl =NULL;

    pl = malloc(sizeof(t_quintupla));

    pl->D = NULL;
    
    return pl;
}
/* ---------------------------------------------------------------------- */
//responsavel pela parte geral da converssao//

void conversao_er_afnd(char linha[SBUFF], t_quintupla *novo_afnd, unsigned short int *est){
    
    int i = 0; //Variável que representará a posição de 'linha'.
    
    int cont_aux;
    int ascii;
    int est_aux;
    int contagem = 0;
    int estrela = 0;
    int pesquisa_ef = 0; // ========== NOVA ADIÇÃO ==========

    int ei[SBUFF]; //Estados iniciais.
    int cont_ei = 0; //Variável que representará a posição de 'ei'.
    char E = 'E'; //Variável que armazena a letra 'E', a qual simula a letra 'Épsilon'.

    t_quintupla *list_auto = novo_afnd;

    while(linha[i] != '\0'){ //Roda o laço até chegar ao fim da palavra.
        
        // ========== ALTERAÇÃO ==========
        if((linha[i] == '.') || ((linha[i] > 96 && linha[i] < 123) && linha[i+1] == '(') || (linha[i] == ')' && (linha[i+1] > 96 && linha[i+1] < 123))){
            organiza_listas(&list_auto->D, *est, E, *est+1);
            *est += 1;
        }
        if(linha[i] != '\n' && linha[i] != '*' && linha[i] != '.'){ //Caso o caracter lido seja uma letra.
            if(i == 0){
				if(*est != 0){ //Ao entrar nesse 'if', o '*est' terá o mesmo valor dos estados de aceitação.
                    
                    // ========== NOVA ADIÇÃO ==========
                    pesquisa_ef = buscar_ef(F, *est);
                    if(pesquisa_ef == 0){
                        inserir_ef(&F, *est);
                    }

                }
                *est += 1;
                organiza_listas(&list_auto->D, 0, E, *est);
            }

            if(linha[i+1] == '*'){
                estrela = 1;
                if(linha[i] == ')'){
                    organiza_listas(&list_auto->D, *est, E, *est+1);
                    *est += 1;
                    
                    // ========== NOVA ADIÇÃO ==========
                    if(cont_ei == 0){
                        montar_loop(list_auto, ei[1],*est);
                    }
                    // ========== NOVA ADIÇÃO ==========
                    else{
                        montar_loop(list_auto, ei[cont_ei],*est);
                    }    
                }
                else{
                    montar_estrela(novo_afnd, linha[i], est);
                }
            }
            else{
                if(linha[i] == '(' || linha[i] == ')'){
                    if(linha[i] == ')'){
                        cont_ei -= 1;
                    }
                    else{
                        organiza_listas(&list_auto->D, *est, E, *est+1);
                        cont_ei += 1;
                        ei[cont_ei] = *est;
                        *est += 1;
                    }
                }     
                else{
                    if(linha[i] == '|'){
                        organiza_listas(&list_auto->D, ei[cont_ei], E, *est+1);
                        *est += 1;
                    }
                    else{
                        organiza_listas(&list_auto->D, *est, linha[i], *est+1);
                        *est += 1;
                        if(linha[i+1] == '|'){
                            cont_aux = i+1;
                            while(linha[cont_aux] != '\0'){
                                ascii = linha[cont_aux];
                                if(ascii > 96 && ascii < 123){
                                    contagem++;
                                }
                                cont_aux++;
                            }
                            est_aux = (contagem*2)+1;
                            organiza_listas(&list_auto->D, *est, E, *est+est_aux);
                        }      
                    }
                }
            }        
        }
        i++;    
    }
    if(estrela != 1){
        conj_est.K = *est+1;
    }
    i = 0;
}
/* ---------------------------------------------------------------------- */
//FUNCAO DE ORGANIZAR AS LISTAS
void organiza_listas(t_delta **cabeca, unsigned short int i, char a, unsigned short int f)
{ 
     
	t_delta *pl = *cabeca;
    t_delta *plant = NULL;
  
    while(pl != NULL)
    {
	    plant = pl;
        pl = pl->prox;
    }

	pl = malloc(sizeof(t_delta));
	
    pl->ei = i; //Coleta o valor de 'i' e o coloca na lista dos Estados Iniciais.
    pl->le = malloc(sizeof(char));
	
    *pl->le = a; //Coleta o valor de 'a' e o coloca na lista de Leitura.
    pl->le[1] = '\0';

    pl->ef = f;  //Coleta o valor de 'f' e o coloca na lista dos Estados Finas.
    pl->prox = NULL;

    if(plant != NULL)
	{
        plant->prox = pl;
    }
    
    else
    {
        *cabeca = pl;
    }
    return;
}

/* ---------------------------------------------------------------------- */


void montar_estrela(t_quintupla *quint, char c, unsigned short int *est)
{
    t_quintupla *list_quint = quint;
    unsigned short int aux;
    char E = 'E'; 
    
    aux = *est; // Auxiliar para salvar o estado que vai fazer o loop
   

    organiza_listas(&list_quint->D, *est, E, *est+1);
    *est += 1;
    organiza_listas(&list_quint->D, *est, c, *est+1);
    *est+= 1;
    montar_loop(list_quint, aux, *est);
    *est+= 1;
    
    return;
}
/* ---------------------------------------------------------------------- */
// FUNCAO MONTAR LOOP
void montar_loop(t_quintupla *quint, unsigned short int inicio, unsigned short int fim)
{
    t_quintupla *list_auto = quint;
    char c = 'E';
    //inserir_ef(&F, fim+1);
    conj_est.K = fim+2;

    organiza_listas(&list_auto->D, fim, c, fim+1); 
    organiza_listas(&list_auto->D, fim, c, inicio+1);
    organiza_listas(&list_auto->D, inicio, c, fim+1);
    
    return;
}

/* ---------------------------------------------------------------------- */
// FUNCAO DELTA
void delta_er(t_delta *cabeca){
    
    t_delta *pl = cabeca;
    
    inserir_ef(&F, conj_est.K-1);
    
    printf("#K\n");
    printf("%d\n", conj_est.K);
    printf("#A\n");
    printf("%c\n", alfabeto.A);
    printf("#S\n");
    printf("0\n");
    printf("#F\n");
    imprimir_ef();
    printf("#D\n");
            

    while(pl != NULL){
        printf("%u %s %u\n", pl->ei, pl->le, pl->ef);
        //if(pl->prox != NULL){
            //printf("\n");
        //}
        pl = pl->prox;
    }

    return;
}

/* ---------------------------------------------------------------------- */
//Poes a informacoe de estados finais em uma lista

void inserir_ef(t_lef **cabeca, int x){

    t_lef *pl = *cabeca;
    t_lef *plant = NULL;
    while(pl != NULL){
        plant = pl;
        pl = pl->prox;
    }
    pl=malloc(sizeof(t_lef));
    pl->f = x;
    pl->prox = NULL;
    if(plant != NULL){
        plant->prox = pl;
    }
    else{
        *cabeca = pl;
    }
}

/* ---------------------------------------------------------------------- */
//os estados finais

void imprimir_ef(){
    t_lef *pl = F;
    //t_lef *pl = cabeca;
    
    while(pl != NULL){
        printf("%d", pl->f);
        if(pl->prox != NULL){
            printf(" ");
        }    
        pl = pl->prox;
    }    
printf("\n");
}

int buscar_ef(t_lef *cabeca, int x){
    
    t_lef *pl = cabeca;
    while(pl != NULL){
        if(pl ->f == x){
            return 1;
        }
        pl = pl->prox;
    }
    return 0;
}    
/* ---------------------------------------------------------------------- */
//ALLEGRO//

int ex1_allegro(void){
    BITMAP *buff;
    PALETTE pal;

    if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0){
        exit(EXIT_FAILURE);
    }
    set_color_depth(16);
    get_palette(pal);

    // Create a buffer for smooth animation.
    buff = create_bitmap(320,240);
    if(buff == NULL)
    {
        printf("Could not create buffer!\n");
        exit(EXIT_FAILURE);
    }

  	textprintf_ex(buff, font, 115, 5, CORVERDE, CORPRETO, "a|a.a.b|b*"); //Texto (x e y)
	
	textprintf_ex(buff, font, INIT_POS_X, INIT_POS_Y_1-2, CORBRANCO, CORPRETO, "-->");
	textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1+2, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1+8, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1+16, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1+24, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1+32, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1+40, CORBRANCO, CORPRETO, "|");
	
	
	circle(buff, INIT_POS_X+42, INIT_POS_Y_1, TAM_CIRC, CORBRANCO);
	textprintf_ex(buff, font, INIT_POS_X+39, INIT_POS_Y_1-3, CORBRANCO, CORPRETO, "1");
	textprintf_ex(buff, font, INIT_POS_X+57, INIT_POS_Y_1-15, CORBRANCO, CORPRETO, "a");
	textprintf_ex(buff, font, INIT_POS_X+56, INIT_POS_Y_1-3, CORBRANCO, CORPRETO, "->");
	
	circlefill(buff, INIT_POS_X+82, INIT_POS_Y_1, TAM_CIRC, CORCINZA);
	textprintf_ex(buff, font, INIT_POS_X+79, INIT_POS_Y_1-3, CORPRETO, CORCINZA, "2");
//---------------------------------------------------------------------------------------------
	
	textprintf_ex(buff, font, INIT_POS_X-14, INIT_POS_Y_3-39, CORBRANCO, CORPRETO, "E");
	textprintf_ex(buff, font, INIT_POS_X-14, INIT_POS_Y_2-30, CORBRANCO, CORPRETO, "E");
		
	circle(buff, INIT_POS_X, INIT_POS_Y_2, TAM_CIRC, CORBRANCO); //Circulo (x, y e tamanho)
	textprintf_ex(buff, font, INIT_POS_X-3, 117, CORBRANCO, CORPRETO, "0"); //Texto (x e y)
	textprintf_ex(buff, font, INIT_POS_X+16, 105, CORBRANCO, CORPRETO, "E");
	textprintf_ex(buff, font, INIT_POS_X+16, 117, CORBRANCO, CORPRETO, "->"); //Texto (x e y)
  
	circle(buff, INIT_POS_X+42, INIT_POS_Y_2, TAM_CIRC, CORBRANCO);
	textprintf_ex(buff, font, INIT_POS_X+39, 117, CORBRANCO, CORPRETO, "3");
	textprintf_ex(buff, font, INIT_POS_X+57, 105, CORBRANCO, CORPRETO, "a");
	textprintf_ex(buff, font, INIT_POS_X+56, 117, CORBRANCO, CORPRETO, "->");

	circle(buff, INIT_POS_X+82, INIT_POS_Y_2, TAM_CIRC, CORBRANCO);
	textprintf_ex(buff, font, INIT_POS_X+79, 117, CORBRANCO, CORPRETO, "4");
	textprintf_ex(buff, font, INIT_POS_X+97, 105, CORBRANCO, CORPRETO, "E");
	textprintf_ex(buff, font, INIT_POS_X+96, 117, CORBRANCO, CORPRETO, "->");
  
	circle(buff, INIT_POS_X+122, INIT_POS_Y_2, TAM_CIRC, CORBRANCO);
	textprintf_ex(buff, font, INIT_POS_X+119, 117, CORBRANCO, CORPRETO, "5");
	textprintf_ex(buff, font, INIT_POS_X+137, 105, CORBRANCO, CORPRETO, "a");
	textprintf_ex(buff, font, INIT_POS_X+136, 117, CORBRANCO, CORPRETO, "->");
  	
	circle(buff, INIT_POS_X+162, INIT_POS_Y_2, TAM_CIRC, CORBRANCO);
	textprintf_ex(buff, font, INIT_POS_X+159, 117, CORBRANCO, CORPRETO, "6");
	textprintf_ex(buff, font, INIT_POS_X+177, 105, CORBRANCO, CORPRETO, "E");
	textprintf_ex(buff, font, INIT_POS_X+176, 117, CORBRANCO, CORPRETO, "->");

	circle(buff, INIT_POS_X+202, INIT_POS_Y_2, TAM_CIRC, CORBRANCO);
	textprintf_ex(buff, font, INIT_POS_X+199, 117, CORBRANCO, CORPRETO, "7");
	textprintf_ex(buff, font, INIT_POS_X+217, 105, CORBRANCO, CORPRETO, "b");
	textprintf_ex(buff, font, INIT_POS_X+216, 117, CORBRANCO, CORPRETO, "->");
  
	circlefill(buff, INIT_POS_X+242, INIT_POS_Y_2, TAM_CIRC, CORCINZA);
	textprintf_ex(buff, font, INIT_POS_X+239, 117, CORPRETO, CORCINZA, "8");  	
//---------------------------------------------------------------------------------------------

	textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_2+16, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_2+22, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_2+30, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_2+38, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_2+46, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_2+54, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X, INIT_POS_Y_2+57, CORBRANCO, CORPRETO, "-->");


	circle(buff, INIT_POS_X+42, INIT_POS_Y_3, TAM_CIRC, CORBRANCO);
	textprintf_ex(buff, font, INIT_POS_X+97, INIT_POS_Y_3-39, CORBRANCO, CORPRETO, "E");
	textprintf_ex(buff, font, INIT_POS_X+43, INIT_POS_Y_3-30, CORBRANCO, CORPRETO, "---------------");
	textprintf_ex(buff, font, INIT_POS_X+39, INIT_POS_Y_3-23, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+157, INIT_POS_Y_3-25, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+159, INIT_POS_Y_3-20, CORBRANCO, CORPRETO, "v");
	
	textprintf_ex(buff, font, INIT_POS_X+39, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "9");
	textprintf_ex(buff, font, INIT_POS_X+57, INIT_POS_Y_3-15, CORBRANCO, CORPRETO, "E");
	textprintf_ex(buff, font, INIT_POS_X+56, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "->");
	
	textprintf_ex(buff, font, INIT_POS_X+97, INIT_POS_Y_3+36, CORBRANCO, CORPRETO, "E");
	textprintf_ex(buff, font, INIT_POS_X+85, INIT_POS_Y_3+26, CORBRANCO, CORPRETO, "-----");
	textprintf_ex(buff, font, INIT_POS_X+77, INIT_POS_Y_3+22, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+77, INIT_POS_Y_3+16, CORBRANCO, CORPRETO, "^");
	textprintf_ex(buff, font, INIT_POS_X+119, INIT_POS_Y_3+18, CORBRANCO, CORPRETO, "|");
	
	circle(buff, INIT_POS_X+82, INIT_POS_Y_3, TAM_CIRC, CORBRANCO);
	textprintf_ex(buff, font, INIT_POS_X+75, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "10");
	textprintf_ex(buff, font, INIT_POS_X+97, INIT_POS_Y_3-15, CORBRANCO, CORPRETO, "b");
	textprintf_ex(buff, font, INIT_POS_X+96, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "->");
	
	circle(buff, INIT_POS_X+122, INIT_POS_Y_3, TAM_CIRC, CORBRANCO);
	textprintf_ex(buff, font, INIT_POS_X+115, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "11");
	textprintf_ex(buff, font, INIT_POS_X+137, INIT_POS_Y_3-15, CORBRANCO, CORPRETO, "E");
	textprintf_ex(buff, font, INIT_POS_X+136, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "->");
	
	circlefill(buff, INIT_POS_X+162, INIT_POS_Y_3, TAM_CIRC, CORCINZA);
	textprintf_ex(buff, font, INIT_POS_X+155, INIT_POS_Y_3-3, CORPRETO, CORCINZA, "12");


  	save_bitmap(IMAGENAME_EX1, buff, pal);
  	destroy_bitmap(buff);
  	allegro_exit();
  
  	return EXIT_SUCCESS;
}

int ex2_allegro(void){
      BITMAP *buff;
  PALETTE pal;

  if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
    exit(EXIT_FAILURE);

  set_color_depth(16);
  get_palette(pal);

  // Create a buffer for smooth animation.
  buff = create_bitmap(450,300);
  if(buff == NULL)
  {
    printf("Could not create buffer!\n");
    exit(EXIT_FAILURE);
  }

	textprintf_ex(buff, font, 170, 5, CORVERDE, CORPRETO, "a|a.(a.b|b)*"); //Texto (x e y)

//circulos -------------------------------------------------------------------------

	circle(buff, INIT_POS_X-7, INIT_POS_Y_3, TAM_CIRC, CORBRANCO); //Circulo 0
	circle(buff, INIT_POS_X+40, INIT_POS_Y_1, TAM_CIRC, CORBRANCO); //Circulo 1	
	circlefill(buff, INIT_POS_X+85, INIT_POS_Y_1, TAM_CIRC, CORCINZA); //Circulo 2	
	circle(buff, INIT_POS_X+40, INIT_POS_Y_3, TAM_CIRC, CORBRANCO); //Circulo 3
	circle(buff, INIT_POS_X+85, INIT_POS_Y_3, TAM_CIRC, CORBRANCO); //Circulo 4
	circle(buff, INIT_POS_X+130, INIT_POS_Y_3, TAM_CIRC, CORBRANCO); //Circulo 5
	circle(buff, INIT_POS_X+175, INIT_POS_Y_2, TAM_CIRC, CORBRANCO); //Circulo 6
	circle(buff, INIT_POS_X+220, INIT_POS_Y_2, TAM_CIRC, CORBRANCO); //Circulo 7
	circle(buff, INIT_POS_X+265, INIT_POS_Y_2, TAM_CIRC, CORBRANCO); //Circulo 8
	circle(buff, INIT_POS_X+310, INIT_POS_Y_2, TAM_CIRC, CORBRANCO); //Circulo 9
	circle(buff, INIT_POS_X+175, INIT_POS_Y_4, TAM_CIRC, CORBRANCO); //Circulo 10
	circle(buff, INIT_POS_X+220, INIT_POS_Y_4, TAM_CIRC, CORBRANCO); //Circulo 11
	circle(buff, INIT_POS_X+355, INIT_POS_Y_3, TAM_CIRC, CORBRANCO); //Circulo 12
	circlefill(buff, INIT_POS_X+400, INIT_POS_Y_3, TAM_CIRC, CORCINZA); //Circulo 13

//numeros ---------------------------------------------------------------------------

	textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "0");// circulo 0
	textprintf_ex(buff, font, INIT_POS_X+38, INIT_POS_Y_1-3, CORBRANCO, CORPRETO, "1");// circulo 1
	textprintf_ex(buff, font, INIT_POS_X+82, INIT_POS_Y_1-3, CORPRETO, CORCINZA, "2");// circulo 2
	textprintf_ex(buff, font, INIT_POS_X+38, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "3");//circulo 3
	textprintf_ex(buff, font, INIT_POS_X+82, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "4");// circulo 4
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "5");//circulo 5
	textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_2-3, CORBRANCO, CORPRETO, "6");//circulo 6
	textprintf_ex(buff, font, INIT_POS_X+217, INIT_POS_Y_2-3, CORBRANCO, CORPRETO, "7");// circulo 7
	textprintf_ex(buff, font, INIT_POS_X+262, INIT_POS_Y_2-3, CORBRANCO, CORPRETO, "8");// circulo 8
	textprintf_ex(buff, font, INIT_POS_X+307, INIT_POS_Y_2-3, CORBRANCO, CORPRETO, "9");// circulo 9
	textprintf_ex(buff, font, INIT_POS_X+169, INIT_POS_Y_4-3, CORBRANCO, CORPRETO, "10");// circulo 10
	textprintf_ex(buff, font, INIT_POS_X+214, INIT_POS_Y_4-3, CORBRANCO, CORPRETO, "11");// circulo 11
	textprintf_ex(buff, font, INIT_POS_X+349, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "12");// circulo 12
	textprintf_ex(buff, font, INIT_POS_X+394, INIT_POS_Y_3-3, CORPRETO, CORCINZA, "13");// circulo 13


// setas ------------------------------------------------------------------------------


// letras -----------------------------------------------------------------------------

	textprintf_ex(buff, font, INIT_POS_X+10, INIT_POS_Y_1+30, CORBRANCO, CORPRETO, "E"); //0->1
	textprintf_ex(buff, font, INIT_POS_X+58, INIT_POS_Y_1-13, CORBRANCO, CORPRETO, "a"); //1->2
	textprintf_ex(buff, font, INIT_POS_X+16, INIT_POS_Y_3-13, CORBRANCO, CORPRETO, "E"); //0->3
	textprintf_ex(buff, font, INIT_POS_X+58, INIT_POS_Y_3-13, CORBRANCO, CORPRETO, "a"); //3->4
	textprintf_ex(buff, font, INIT_POS_X+103, INIT_POS_Y_3-13, CORBRANCO, CORPRETO, "E");//4->5
	textprintf_ex(buff, font, INIT_POS_X+147, INIT_POS_Y_2+40, CORBRANCO, CORPRETO, "E");//5->6
	textprintf_ex(buff, font, INIT_POS_X+192, INIT_POS_Y_2-13, CORBRANCO, CORPRETO, "a");//6->7
	textprintf_ex(buff, font, INIT_POS_X+238, INIT_POS_Y_2-13, CORBRANCO, CORPRETO, "E");//7->8
	textprintf_ex(buff, font, INIT_POS_X+282, INIT_POS_Y_2-13, CORBRANCO, CORPRETO, "b");//8->9
	textprintf_ex(buff, font, INIT_POS_X+328, INIT_POS_Y_3-42, CORBRANCO, CORPRETO, "E");//9->12
	textprintf_ex(buff, font, INIT_POS_X+192, INIT_POS_Y_4-13, CORBRANCO, CORPRETO, "b");//10->11
	textprintf_ex(buff, font, INIT_POS_X+147, INIT_POS_Y_3+10, CORBRANCO, CORPRETO, "E");//5->10
	textprintf_ex(buff, font, INIT_POS_X+265, INIT_POS_Y_1+10, CORBRANCO, CORPRETO, "E");//12->6
	textprintf_ex(buff, font, INIT_POS_X+373, INIT_POS_Y_3-12, CORBRANCO, CORPRETO, "E");//12->13
	textprintf_ex(buff, font, INIT_POS_X+265, INIT_POS_Y_1-23, CORBRANCO, CORPRETO, "E");//5->13
	textprintf_ex(buff, font, INIT_POS_X+297, INIT_POS_Y_4-13, CORBRANCO, CORPRETO, "E");//11->13
	//*/

	//0 -> 1
    textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1-2, CORBRANCO, CORPRETO, "-->");
    textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+2, CORBRANCO, CORPRETO, "|");
    textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+8, CORBRANCO, CORPRETO, "|");
    textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+16, CORBRANCO, CORPRETO, "|");
    textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+24, CORBRANCO, CORPRETO, "|");
    textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+32, CORBRANCO, CORPRETO, "|");
    textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+40, CORBRANCO, CORPRETO, "|");
    textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+48, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+56, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+64, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+72, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+80, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+88, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+96, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X-10, INIT_POS_Y_1+100, CORBRANCO, CORPRETO, "|");
	
	textprintf_ex(buff, font, INIT_POS_X+55, INIT_POS_Y_1-3, CORBRANCO, CORPRETO, "->"); //1->2
	textprintf_ex(buff, font, INIT_POS_X+8, INIT_POS_Y_3-2, CORBRANCO, CORPRETO, "->"); //0->3
	textprintf_ex(buff, font, INIT_POS_X+55, INIT_POS_Y_3-2, CORBRANCO, CORPRETO, "->"); //3->4
	textprintf_ex(buff, font, INIT_POS_X+102, INIT_POS_Y_3-2, CORBRANCO, CORPRETO, "->"); //4->5
	textprintf_ex(buff, font, INIT_POS_X+190, INIT_POS_Y_2-2, CORBRANCO, CORPRETO, "->"); //6->7
	textprintf_ex(buff, font, INIT_POS_X+237, INIT_POS_Y_2-2, CORBRANCO, CORPRETO, "->"); //7->8
	textprintf_ex(buff, font, INIT_POS_X+280, INIT_POS_Y_2-2, CORBRANCO, CORPRETO, "->"); //8->9
	//+47
	

	
	//5 -> 6
	textprintf_ex(buff, font, INIT_POS_X+134, INIT_POS_Y_1-11, CORBRANCO, CORPRETO, "---------------------------------");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1-8, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1+8, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1+16, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1+24, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1+32, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1+40, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1+48, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1+56, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1+64, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1+72, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1+80, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1+88, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+395, INIT_POS_Y_1+96, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+396, INIT_POS_Y_1+100, CORBRANCO, CORPRETO, "v");
	
	
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1-8, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+8, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+16, CORBRANCO, CORPRETO, "|");
	
	
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+24, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+32, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+40, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+48, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+56, CORBRANCO, CORPRETO, "|");
	
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+64, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+72, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+80, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+88, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+96, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_1+100, CORBRANCO, CORPRETO, "|");

	
	//5 -> 10
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_3+13, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_3+21, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_3+29, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_3+37, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+134, INIT_POS_Y_3+39, CORBRANCO, CORPRETO, "-->");
	

	
	textprintf_ex(buff, font, INIT_POS_X+190, INIT_POS_Y_4-2, CORBRANCO, CORPRETO, "->"); //10->11
	textprintf_ex(buff, font, INIT_POS_X+370, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "->"); //12->13
	
	textprintf_ex(buff, font, INIT_POS_X+237, INIT_POS_Y_4-1, CORBRANCO, CORPRETO, "--------------"); //11->12	
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-26, CORBRANCO, CORPRETO, "^");
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-20, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-12, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-4, CORBRANCO, CORPRETO, "|");
	
	
	textprintf_ex(buff, font, INIT_POS_X+175, INIT_POS_Y_1+25, CORBRANCO, CORPRETO, "-----------------------"); //12->6
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-60, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-68, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-76, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-84, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-92, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-100, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-108, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-116, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-124, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+350, INIT_POS_Y_4-132, CORBRANCO, CORPRETO, "|");
	
	textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_2-22, CORBRANCO, CORPRETO, "v");
	textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_2-30, CORBRANCO, CORPRETO, "|");
	
	//5->6
	textprintf_ex(buff, font, INIT_POS_X+147, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "---");
	textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_2+16, CORBRANCO, CORPRETO, "^");
	textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_2+22, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_2+30, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_2+38, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_2+46, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_2+54, CORBRANCO, CORPRETO, "|");

	//9->12
	textprintf_ex(buff, font, INIT_POS_X+307, INIT_POS_Y_2+14, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+307, INIT_POS_Y_2+22, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+307, INIT_POS_Y_2+30, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+307, INIT_POS_Y_2+38, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+307, INIT_POS_Y_2+46, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+307, INIT_POS_Y_2+54, CORBRANCO, CORPRETO, "|");
	textprintf_ex(buff, font, INIT_POS_X+309, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "--->");

    save_bitmap(IMAGENAME_EX2, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();
    return 0;
}

int ex3_allegro(void){
    BITMAP *buff;
  PALETTE pal;

  if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
    exit(EXIT_FAILURE);

  set_color_depth(16);
  get_palette(pal);

  // Create a buffer for smooth animation.
  buff = create_bitmap(500,300);
  if(buff == NULL)
  {
    printf("Could not create buffer!\n");
    exit(EXIT_FAILURE);
  }

textprintf_ex(buff, font, 115, 5, CORVERDE, CORPRETO, "a|(a.(a.b|b))*"); //Texto (x e y)

//circulos -------------------------------------------------------------------------

circle(buff, INIT_POS_X, INIT_POS_Y_2, TAM_CIRC, CORBRANCO); //Circulo 0
circle(buff, INIT_POS_X+40, INIT_POS_Y_1, TAM_CIRC, CORBRANCO); //Circulo 1
circlefill(buff, INIT_POS_X+85, INIT_POS_Y_1, TAM_CIRC, CORCINZA);//circulo 2
circle(buff, INIT_POS_X+40, INIT_POS_Y_3, TAM_CIRC, CORBRANCO); //Circulo 3
circle(buff, INIT_POS_X+85, INIT_POS_Y_3, TAM_CIRC, CORBRANCO); //Circulo 4
circle(buff, INIT_POS_X+130, INIT_POS_Y_3, TAM_CIRC, CORBRANCO); //Circulo 5-
circle(buff, INIT_POS_X+175, INIT_POS_Y_3, TAM_CIRC, CORBRANCO); //Circulo 6
circle(buff, INIT_POS_X+220, INIT_POS_Y_2, TAM_CIRC, CORBRANCO); //Circulo 7
circle(buff, INIT_POS_X+265, INIT_POS_Y_2, TAM_CIRC, CORBRANCO); //Circulo 8
circle(buff, INIT_POS_X+310, INIT_POS_Y_2, TAM_CIRC, CORBRANCO); //Circulo 9
circle(buff, INIT_POS_X+355, INIT_POS_Y_2, TAM_CIRC, CORBRANCO); //Circulo 10
circle(buff, INIT_POS_X+220, INIT_POS_Y_4, TAM_CIRC, CORBRANCO); //Circulo 11
circle(buff, INIT_POS_X+265, INIT_POS_Y_4, TAM_CIRC, CORBRANCO); //Circulo 12
circle(buff, INIT_POS_X+400, INIT_POS_Y_3, TAM_CIRC, CORBRANCO); //Circulo 13
circlefill(buff, INIT_POS_X+445, INIT_POS_Y_3, TAM_CIRC, CORCINZA);//circulo 14

//numeros ---------------------------------------------------------------------------

textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_2-3, CORBRANCO, CORPRETO, "0");// circulo 0
textprintf_ex(buff, font, INIT_POS_X+38, INIT_POS_Y_1-3, CORBRANCO, CORPRETO, "1");// circulo 1
textprintf_ex(buff, font, INIT_POS_X+82, INIT_POS_Y_1-3, CORPRETO, CORCINZA, "2");// circulo 2
textprintf_ex(buff, font, INIT_POS_X+38, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "3");//circulo 3
textprintf_ex(buff, font, INIT_POS_X+82, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "4");// circulo 4
textprintf_ex(buff, font, INIT_POS_X+127, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "5");//circulo 5
textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "6");//circulo 6
textprintf_ex(buff, font, INIT_POS_X+217, INIT_POS_Y_2-3, CORBRANCO, CORPRETO, "7");// circulo 7
textprintf_ex(buff, font, INIT_POS_X+262, INIT_POS_Y_2-3, CORBRANCO, CORPRETO, "8");// circulo 8
textprintf_ex(buff, font, INIT_POS_X+307, INIT_POS_Y_2-3, CORBRANCO, CORPRETO, "9");// circulo 9
textprintf_ex(buff, font, INIT_POS_X+349, INIT_POS_Y_2-3, CORBRANCO, CORPRETO, "10");// circulo 10
textprintf_ex(buff, font, INIT_POS_X+214, INIT_POS_Y_4-3, CORBRANCO, CORPRETO, "11");// circulo 11
textprintf_ex(buff, font, INIT_POS_X+259, INIT_POS_Y_4-3, CORBRANCO, CORPRETO, "12");// circulo 12
textprintf_ex(buff, font, INIT_POS_X+394, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "13");// circulo 13
textprintf_ex(buff, font, INIT_POS_X+439, INIT_POS_Y_3-3, CORPRETO, CORCINZA, "14");// circulo 14

// setas ------------------------------------------------------------------------------
// seta 1
textprintf_ex(buff, font, INIT_POS_X, INIT_POS_Y_1-2, CORBRANCO, CORPRETO, "-->");
textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1+2, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1+8, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1+16, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1+24, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1+32, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_1+40, CORBRANCO, CORPRETO, "|");
// seta 2
textprintf_ex(buff, font, INIT_POS_X, INIT_POS_Y_3+1, CORBRANCO, CORPRETO, "-->");
textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_3-9, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_3-17, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_3-25, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_3-33, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X-3, INIT_POS_Y_3-41, CORBRANCO, CORPRETO, "|");

//seta 3
textprintf_ex(buff, font, INIT_POS_X+50, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "-->");
// seta 4
textprintf_ex(buff, font, INIT_POS_X+95, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "-->");
// seta 5
textprintf_ex(buff, font, INIT_POS_X+142, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "-->");
//seta 6
textprintf_ex(buff, font, INIT_POS_X+175, INIT_POS_Y_2+2, CORBRANCO, CORPRETO, "--->");
textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_3-20, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_3-26, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_3-32, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_3-38, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_3-44, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+172, INIT_POS_Y_3-50, CORBRANCO, CORPRETO, "|");
//seta 7
textprintf_ex(buff, font, INIT_POS_X+230, INIT_POS_Y_2-3, CORBRANCO, CORPRETO, "-->");
//seta 8
textprintf_ex(buff, font, INIT_POS_X+274, INIT_POS_Y_2-3, CORBRANCO, CORPRETO, "-->");

//seta 9
textprintf_ex(buff, font, INIT_POS_X+321, INIT_POS_Y_2-3, CORBRANCO, CORPRETO, "-->");
//seta 10
textprintf_ex(buff, font, INIT_POS_X+375, INIT_POS_Y_2, CORBRANCO, CORPRETO, "----");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3-22, CORBRANCO, CORPRETO, "v");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3-26, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3-32, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3-38, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3-44, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3-50, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3-54, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_2+3, CORBRANCO, CORPRETO, "|");
//seta 11
textprintf_ex(buff, font, INIT_POS_X+175, INIT_POS_Y_3+20, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+175, INIT_POS_Y_3+26, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+175, INIT_POS_Y_3+32, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+175, INIT_POS_Y_3+38, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+175, INIT_POS_Y_4, CORBRANCO, CORPRETO, "---->");

//seta 15
textprintf_ex(buff, font, INIT_POS_X+84, INIT_POS_Y_3+20, CORBRANCO, CORPRETO, "^");
textprintf_ex(buff, font, INIT_POS_X+84, INIT_POS_Y_3+26, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+84, INIT_POS_Y_3+32, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+84, INIT_POS_Y_3+38, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+84, INIT_POS_Y_3+44, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+84, INIT_POS_Y_3+50, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+84, INIT_POS_Y_3+56, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+84, INIT_POS_Y_3+62, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3-2424, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3+26, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3+32, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3+38, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3+44, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3+50, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3+56, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+400, INIT_POS_Y_3+62, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+84, INIT_POS_Y_3+62, CORBRANCO, CORPRETO, "----------------------------------------");
//seta 16
textprintf_ex(buff, font, INIT_POS_X+265, INIT_POS_Y_4-24, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+265, INIT_POS_Y_4-30, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+265, INIT_POS_Y_4-36, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+268, INIT_POS_Y_4-36, CORBRANCO, CORPRETO, "-------------->");
//seta 14
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_1+18, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_1+24, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_1+30, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_1+36, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_1+42,CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_1+54, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_1+60, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_1+66, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_1+72, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_1+78, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_1+84, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_1+90, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+445, INIT_POS_Y_1+18, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+445, INIT_POS_Y_1+24, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+445, INIT_POS_Y_1+30, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+445, INIT_POS_Y_1+36, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+445, INIT_POS_Y_1+42,CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+445, INIT_POS_Y_1+54, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+445, INIT_POS_Y_1+60, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+445, INIT_POS_Y_1+66, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+445, INIT_POS_Y_1+72, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+445, INIT_POS_Y_1+78, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+445, INIT_POS_Y_1+84, CORBRANCO, CORPRETO, "|");
textprintf_ex(buff, font, INIT_POS_X+445, INIT_POS_Y_1+90, CORBRANCO, CORPRETO, "v");
textprintf_ex(buff, font, INIT_POS_X+34, INIT_POS_Y_2-47, CORBRANCO, CORPRETO, "----------------------------------------------------");
//seta 12
textprintf_ex(buff, font, INIT_POS_X+230, INIT_POS_Y_4-3, CORBRANCO, CORPRETO, "-->");

//seta 13
textprintf_ex(buff, font, INIT_POS_X+411, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "-->");
//seta 15

//seta 16
textprintf_ex(buff, font, INIT_POS_X+411, INIT_POS_Y_3-3, CORBRANCO, CORPRETO, "-->");
// letras -----------------------------------------------------------------------------

textprintf_ex(buff, font, INIT_POS_X+12, INIT_POS_Y_1+16, CORBRANCO, CORPRETO, "E"); //1
textprintf_ex(buff, font, INIT_POS_X+58, INIT_POS_Y_1-13, CORBRANCO, CORPRETO, "a"); //2
textprintf_ex(buff, font, INIT_POS_X+16, INIT_POS_Y_3-30, CORBRANCO, CORPRETO, "E"); //3
textprintf_ex(buff, font, INIT_POS_X+58, INIT_POS_Y_3-13, CORBRANCO, CORPRETO, "E"); //4
textprintf_ex(buff, font, INIT_POS_X+103, INIT_POS_Y_3-13, CORBRANCO, CORPRETO, "a");//5
textprintf_ex(buff, font, INIT_POS_X+150, INIT_POS_Y_3-13, CORBRANCO, CORPRETO, "E");//6
textprintf_ex(buff, font, INIT_POS_X+188, INIT_POS_Y_3-41, CORBRANCO, CORPRETO, "E");//7
textprintf_ex(buff, font, INIT_POS_X+238, INIT_POS_Y_2-13, CORBRANCO, CORPRETO, "a");//8
textprintf_ex(buff, font, INIT_POS_X+282, INIT_POS_Y_2-13, CORBRANCO, CORPRETO, "E");//9
textprintf_ex(buff, font, INIT_POS_X+329, INIT_POS_Y_2-13, CORBRANCO, CORPRETO, "b");//10
textprintf_ex(buff, font, INIT_POS_X+238, INIT_POS_Y_4-13, CORBRANCO, CORPRETO, "b");//11
textprintf_ex(buff, font, INIT_POS_X+190, INIT_POS_Y_3+17, CORBRANCO, CORPRETO, "E");//12
textprintf_ex(buff, font, INIT_POS_X+372, INIT_POS_Y_3-38, CORBRANCO, CORPRETO, "E");//13
textprintf_ex(buff, font, INIT_POS_X+419, INIT_POS_Y_3-13, CORBRANCO, CORPRETO, "E");//14
textprintf_ex(buff, font, INIT_POS_X+238, INIT_POS_Y_2-55, CORBRANCO, CORPRETO, "E");//15
textprintf_ex(buff, font, INIT_POS_X+238, INIT_POS_Y_4+28, CORBRANCO, CORPRETO, "E");//16


        save_bitmap(IMAGENAME_EX3, buff, pal);
        destroy_bitmap(buff);
        allegro_exit();
    
    return 0;
}

/* ---------------------------------------------------------------------- */

/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160609.110101
 * @date 2016-06-09
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s v.%s - %s\n", "exN", VERSION, "Convert AFD into Exp Reg");
    printf("\nUsage: %s [-h|-v|-c|-f|-n]\n", "exN");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    /* add more options here */
    printf("\t-n, --STDIN\n\t\tManual input.\n");
    printf("\n\nNote (-e): input data is a RE (Regular Expression) string to be converted to a NFA (Nondeterministic Finite Automata) 5-tuple.\n");
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160609.110101
 * @date 2016-06-09
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "exN", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
/*
void exN_init(void)
{
    IFDEBUG("exN_init()");
    //initialization
    return;
}
*/
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function does bla bla bla
 * @details It works by doing first a bla, followed by two bla's, giving
 * bla bla bla
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @return The returned value @a r means rhit
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x==funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @warning   Be carefull with blu
 * @deprecated This function will be deactivated in version +33
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @todo Need to change its output format to conform POSIX
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 * @copyright Only if not the same as the whole file
 *
 */

int funcexample(int i, int *o, int *z)
{
    IFDEBUG("funcexample()");
    i += *z;
    *o = (*z)++;
    return i - 4;
}


/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */

