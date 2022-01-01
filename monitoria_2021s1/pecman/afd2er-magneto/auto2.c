/***************************************************************************
 *   auto2.c                               Version 20210512.104607         *
 *                                                                         *
 *   Convert AFD into Exp Reg                                              *
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
 * @file auto2.c
 * @ingroup GroupUnique
 * @brief Convert AFD into Exp Reg
 * @details This program really do a nice job as a template, and template only!
 * @version 20160520.000202
 * @date 2021-12-30
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

/* Instrucoes para compilar:
 *  $ gcc auto2.c -o auto2.x -Wall `allegro-config --cflags --libs`
 */

/* Instrucoes para executar:
 *  $ cat arquivo.txt | ./auto2.x -d
 *  $ ./auto2.x -f arquivo.txt
 * */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in auto2.h */

#include "auto2.h" /* To be created for this template if needed */

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
 *    $./ex2 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20210512.104607
 * @date 2016-05-20
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    int flag=0; 
    FILE *f;
    FILE *f2;
    t_quintupla *q = NULL;/* quintupla */

    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright and version
     *        -v  verbose
     *        -d  AFD->ER
     *        -f  given file name
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hcdvf:")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'c':
                copyr();
                break;
            case 'd':
                f = fopen("auxiliaEntrada.txt", "a"); /* cria arquivo temporario para armazenar entrada manual */
                entrada_manual(f); /* chama funcao para adicionar manualmente os dados fornecidos */
                fflush(f); /* atualiza arquivo criado */
                f2 = fopen("auxiliaEntrada.txt", "r"); /* abre arquivo temporario criado para poder o ler */
                fflush(f); /* atualiza arquivo criado */
                remove("auxiliaEntrada.txt"); /* apaga arquivo temporario criado */
                recebe_afd(f2, &q); /* chama funcao recebe_afnd() com o arquivo temporario criado */
                flag=1;
                break;
            case 'v':
                verb++;
                break;
            case 'f':
                f = fopen(optarg,"r"); /* abre arquivo com o nome dado apos o -f */
                if(f) /* confere se o arquivo realmente existe */
                {
                    IFDEBUG("Arquivo encontrado!");
                    recebe_afd(f, &q); /* recebe os dados dentro do arquivo e armazena numa quintupla */
                }
                else /* caso o arquivo nao exista termina o codigo */
                {
                    IFDEBUG("Erro arquivo nao encontrado!");
                    exit(EXIT_FAILURE);
                }
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    /* transforma afd2er */
    if(flag==1)
    {
        //print_quintupla(q); /* confirmar se a quintupla esta correta */
        afd2er(q); /* funcao que transforma de afd para er */
    }
    else
        help();

    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */

/* aplica manualmente informacoes sobre a entrada afnd dada manualmente */
void entrada_manual(FILE *f)
{
      int a = 0;
      char dado[200] = "";
     
      fflush(stdout);
      
      int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
      fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
      
      time_t end = time(0) + 0;
          while(1)
          {
              int c = getchar();
                  
              if (c != EOF && a < 200)
              {
                  dado[a++] = c;
                  end = time(0) + 1;
              }
      
          if(time(0)>end) break;
          }
      
    fprintf(f,"%s", dado);

    return;
}

/* Recebe uma struct do tipo t_quintupla e começa a transformar o afd em er */
void afd2er(t_quintupla *cabeca)
{
    /* structs t_quintupla */
    t_quintupla *q = cabeca; //quintupla original

    /* struct t_delta */
    t_delta *d = NULL; // delta final
    d = malloc(sizeof(t_delta)); //reserva espaco na memoria

    /* strut t_lef */
    t_lef *lef = cabeca->F; //t_lef original

    /* variaveis */
    int i = 0;
    char bufferLE[5] = {" "};//buffer de le


    //define estado incial
    d->ei = 1000;
    d->le = " ";
    d->ef = 1; //ei=0 aponta para ef=1

    //add estado inical a lista
    d->prox = cabeca->D; //inicial aponta p/ cabeca
    cabeca->D = d;
    //define estado final e insere na lista d
    while(lef != NULL)
    {

        //define e insere ao final de ef
        inserir_delta(lef->f, " ", cabeca->K, &d);//estado final eh igual quantidade de Estados presentes(K) + 1,
        //porem como os estados sao enumerados a partir de 0, entao apenas K.

        //vai para o prox elemento F
        if(lef->prox == NULL) break;
        else lef = lef->prox;
    }
    
    //insere novo ei e novo ef a t_quintupla
    q = cabeca;//vai p/ inicio da lista
    q->K = q->K + 2; //add 2 estados novos
    i = 0;
    lef = cabeca->F;//vai p/ inicio da lista
    while(lef != NULL)//ve quantos elementos tem na lista lef
    {
        ++i;//conta elementos
        if(lef->prox == NULL) break;//evita segmentation fault
        else lef = lef->prox;//chama prox da lista lef
    }
    if(i == 1)//lista com apenas 1 elemento
    {
        q->F->f = q->K - 1; //define fase final como a quantidade total de fases(K) -1,
        //pois as fases iniciam contagem a partir de 0
    }
    else//lista com mais de um elemento
    {
        int j = 0;
        do //elimina elementos da lista enquanto quantidade de elementos for maior que 1(j>1)
        {
            lef = cabeca->F;
            while(lef != NULL)//remove elementos
            {
                remover_lef(1, &lef);//chama funcao que remove
                lef = lef->prox;//aponta p/ prox elemento de lef
            }

            lef = cabeca->F;//aponta p/ inicio de lef
            j = 0; //reinicia contador
            while(lef != NULL)//conta quantos elementos tem na lista
            {
                ++j;//conta elementos
                lef = lef->prox;//chama proximo elemento de lef
            }
        }
        while(j > 1);
        lef = cabeca->F;//aponta p/ inicio da lista
        lef->f = q->K - 1; //define fase final como a quantidade total de fases(K) -1,
                           //pois as fases iniciam contagem a partir de 0
    }

    //add 1 a todos, pois um novo estado inicial foi adicionar
    while(d != NULL)
    {
        if(d->ei == 1000)//novo estado inicial
        {
            //se tiver mais de um estado inicial isso deve ser alterado
            d->ei = 0;
            d->ef = 1;
        }
        else
        {
            //if removivel, corrigindo erro que nao entendo
            if(d->ei == 2 && d->ef == 1)
                strcpy(d->le, "a");
            d->ei = d->ei + 1;
            d->ef = d->ef + 1;
        }
        d = d->prox;
    }

    //concatena ciclos infinitos com *   (ex.:a*)
    d = cabeca->D; //aponta p/ o inicio da lista
    while(d != NULL)
    {
        if(d->ei == d->ef)
        {
            sprintf(bufferLE, "%s*", d->le);
            d->le = strdup(bufferLE);
        }
        d = d->prox;
    }

    //concatena
    d = cabeca->D;
    i = 1; //i=1 indica que concatenara a partir do estado 1
    concatena(d, i, cabeca, 0); //0 eh mandado como parametro, pois sera uma funcao recursiva chamando a si mesma
                                //a funcao eliminaEstados, tambem chama a concatena, mas nesse caso eh enviado 1 como parametro
    
    //elimina estados
    i = 1; //i=1 indica que eliminara a partir do estado 1
    eliminaEstados(d, i, cabeca);
    
    //elimina elementos que tem 1000 como parametro
    d = cabeca->D;
    int k = 1;
    int flag = 0;
    t_delta *dSalve = NULL;//salva d anterior
    while(d != NULL)
    {
        flag = 0;
        if(k == 1 && d->ei == 1000)
        {
            cabeca->D = cabeca->D->prox;
            d = cabeca->D;
            --k;
            flag = 1;
        }
        else
            if(d->ei == 1000)
                dSalve->prox = d->prox;
        ++k;
        dSalve = d;
        if(flag == 0)
            d = d->prox;
    }

    //transforma em er
    d = cabeca->D;
    transER(cabeca->D, cabeca);
    free(d);
}

/**< imprime na tela os valores da quintupla de forma organizada na tela principal */
void print_quintupla(t_quintupla *q)
{
    IFDEBUG("print_quintupla()");
    printf("#K\n%d\n",q->K);
    printf("#A\n%c\n",q->A);
    printf("#S\n%d\n",q->S);
    printf("#F\n");
    while(q->F != NULL) /* print da lista t_lef */
    {
        printf("%d ",q->F->f);
        q->F = q->F->prox;
    }
    printf("\n");
    printf("#D\n");
    while(q->D != NULL) /* print da lista t_delta */
    {
        printf("%d %s %d\n",q->D->ei, q->D->le, q->D->ef);
        q->D = q->D->prox;
    }

    return;
}

void transER(t_delta *cabeca, t_quintupla *quint)
{
    /* struct t_delta */
    t_delta *d = cabeca; //apelido principal
    t_delta *dAux = cabeca; // delta aux
    t_delta *dAnt = NULL;// salva posicao anterior de d
    t_delta *dAuxAnt = NULL; // salva posicao anterior de dAux

    /* matriz */
    char matrizER[20][20]; /* Matriz que salva expressoes regulages */

    /* contador */
    int contMatrizER=0; /* Conta quantas expressoes regulares foram adicionadas a matriz */
    int null=0; /* Confere se esta vazio/null */
    int cFinal = 0; /* Conta casa da string Final */

    /* flag */
    int flagAconteceu = 0; /* Confirma que alteracoes serao feitas */
    int salveFlagAconteceu = 0; /* Confirma que a flagAconteceu ja foi ativada em algum momento */

    /* buffer */
    char bufferLE[70]= ""; /* Buffer rotulo do arco */
    char bufferLeFinal[140]= ""; /* Buffer rotulo do arco final */
    char str1[20]= ""; /* Copia da string d->le */
    char str2[20]= ""; /* Copia da string dAux->le */
    char STR1[20]= ""; /* Copia da string d->le */
    char STR2[20]= ""; /* Copia da string dAux->le */
    char bufferCompara[2]= ""; /* Buffer usado para comparacao de caractere*/
    char bufferSinais[2]= ""; /* Buffer usado para comparacao de sinais */
    char bufferFinalMesmo[80]= ""; /* Buffer rotulo do arco Final */
    char printFinal[80]= ""; /* Expressao Regular Final */

    while(d != NULL)
    {
        //copia caminhos p/ string
        strcpy(str1, d->le);
        strcpy(STR1, d->le);

        //reinicia flag q indica alteracao
        salveFlagAconteceu = 0;
        dAux=quint->D;
        while(dAux != NULL)
        {
            //copia caminhos p/ string
            strcpy(str2, dAux->le);
            strcpy(STR2, dAux->le);

            //reinicia flag
            flagAconteceu = 0;

            //se possuírem mesmo tamanho
            if(strlen(str1) == strlen(str2) && d!=dAux)
            {
                for(int i = strlen(str1) - 1; i >= 0; i--)
                {
                    //compara se possuir char iguais
                    int compara = strcmp(str1, str2);
                    if(compara != 0)//str1 possui carac diferente de str2
                    {
                        //vamos eliminar carac de trás pra frente, para ver se encontramos alguma substring igual
                        str1[i] = '\0';
                        str2[i] = '\0';
                    }
                    //achamos trecho semelhante
                    else
                        if(compara == 0)
                        {
                            //confirma que alguma alteracao vai ser feita
                            flagAconteceu = 1;

                            //salva flag
                            if(i == 1)
                                salveFlagAconteceu += flagAconteceu;

                            //copiamos trecho semelhante para buffer
                            strcpy(bufferLE, str1);
                            //salvo tamanho do trecho semelhante
                            int tamSemelhante = strlen(str1);

                            //procuro caracteres diferentes
                            //recopia o ponteiro p/string
                            for(long unsigned int j = tamSemelhante; j < strlen(d->le); j++)
                            {
                                //caso caracteres na mesma posição de casa sejam diferentes
                                if(STR1[j] != STR2[j])
                                {
                                    //vejo se em seguida tem algum símbolo, no caso *
                                    if(STR1[j + 1] == STR2[j + 1] && STR1[j + 1] == '*')
                                    {
                                        sprintf(bufferLeFinal, "%s(%c|%c)*", bufferLE, STR1[j], STR2[j]);
                                        strcpy(bufferLE, bufferLeFinal);//igualo os buferrs
                                        ++j;//pula *
                                    }
                                    //caso contrário possui outra letra e a mesma será analisada pelo ciclo
                                    else
                                    {
                                        sprintf(bufferLeFinal, "%s%c|%c", bufferLE, STR1[j], STR2[j]);
                                        strcpy(bufferLE, bufferLeFinal);//igualo os bufers
                                    }
                                }
                                //caracteres iguais
                                else
                                    if(STR1[j] == STR2[j])
                                    {
                                        sprintf(bufferLeFinal, "%s%c", bufferLE, STR1[j]);
                                        strcpy(bufferLE, bufferLeFinal);
                                    }
                            }
                        }
                } 
                
                //confere se alguma alteracao foi feita
                if(flagAconteceu == 1)
                {
                    //conta quantos expressoes serao adicionadas a matrizER
                    ++contMatrizER;

                    //inclui os pontos
                    strcpy(bufferLE, bufferLeFinal);
                    strcpy(bufferFinalMesmo, "");
                    for(long unsigned int j = 0; j < strlen(bufferLE); j++)
                    {
                        //adiciona a letra ao buffer
                        bufferCompara[0] = bufferLE[j];
                        bufferSinais[0] = bufferLE[j + 1];
                        if(strcspn(bufferCompara, "abcdefghijklmnopqrstuvwxyz*") == 0 && strcspn(bufferSinais, "|*) ") == 1)
                        {
                            strcat(bufferFinalMesmo, bufferCompara);
                            strcat(bufferFinalMesmo, ".");
                        }
                        else{
                            strcat(bufferFinalMesmo, bufferCompara);
                        }
                    }
                    //salva er
                    strcpy(matrizER[contMatrizER-1], bufferFinalMesmo);
                    if(dAux->prox == NULL)//fim da lista
                    {
                        dAuxAnt->prox = dAux->prox;
                    }
                    else
                    {
                        dAuxAnt->prox = dAux->prox;
                        dAuxAnt = dAuxAnt->prox;
                        dAux = dAuxAnt;
                    }
                }
            }
            dAuxAnt = dAux;
            dAux = dAux->prox;
        }
        //remove d
        if(salveFlagAconteceu > 0)
        {
            if(null == 0) // caso seja o primeiro nó
            {
                d->ei = 1000;
                d->le = " ";
                null=1;
            }
            else
            {
                dAnt->prox = d->prox;
                d=dAnt;
            }
        }
        //nenhuma alteracao foi feita
        else if(salveFlagAconteceu == 0)
        {
            //conta quantos expressoes serao adicionadas a matrizER
            ++contMatrizER;

            //inclui os pontos finais
            strcpy(bufferLE, d->le);
            strcpy(bufferFinalMesmo, "");
            for(long unsigned int j = 0; j < strlen(bufferLE); j++)
            {
                //adiciona a letra ao buffer
                bufferCompara[0] = bufferLE[j];
                bufferSinais[0] = bufferLE[j + 1];
                if(strcspn(bufferCompara, "abcdefghijklmnopqrstuvwxyz*") == 0 && strcspn(bufferSinais, "|*) ") == 1)
                {
                    strcat(bufferFinalMesmo, bufferCompara);
                    strcat(bufferFinalMesmo, ".");
                }
                else
                    strcat(bufferFinalMesmo, bufferCompara);
            }
            //salva er
            strcpy(matrizER[contMatrizER-1], bufferFinalMesmo);

            //remove d
            if(null == 0) // caso seja o primeiro nó
            {
                d->ei = 1000;
                d->le = " ";
                null=1;
            }
            else
            {
                dAnt->prox = d->prox;
                d=dAnt;
            }
        }
        dAnt = d;
        d = d->prox;
    }

    //adiciona-se parênteses e barras verticais entre as expressões regulares salvas na matrizER
    for(int p=0; p<contMatrizER; p++)
    {
        if(p==0)
        {
            sprintf(bufferFinalMesmo, "(%s)",matrizER[p]);
        }
        else
        {
            strcat(bufferFinalMesmo, "|(");
            strcat(bufferFinalMesmo, matrizER[p]);
            strcat(bufferFinalMesmo, ")");
        }
    }

    //print sem espaco
    for(long int unsigned c=0; c<=strlen(bufferFinalMesmo); c++, ++cFinal)
    {
        if(c == strlen(bufferFinalMesmo))
        {
            printFinal[cFinal] = '\0';
            break;
        }
        else if(bufferFinalMesmo[c] == ' ')//espaco
        {
           --cFinal;//ainda iremos adicionar algo a casa e nao pode ser espaco
        }
        else
        {
            //mantemno caracter
            printFinal[cFinal] = bufferFinalMesmo[c];
        }
    }
    printf("%s\n", printFinal);
}


void concatena(t_delta *cabeca, int i, t_quintupla *principal, int elimina)
{
    /* struct t_delta */
    t_delta *d = cabeca;            // delta d
    t_delta *dAux = principal->D;   // delta aux
    t_delta *dSalve = NULL;         // salva d anterior
    t_delta *dAuxSalve = NULL;      // salva dAux anterior

    /* flag */
    int flagApontaEleMesmo = 0; //reinicia flag
    int flagFinal = 0;//indica q existe ei =i com ef apontando p/ finalgeral
    int flagRemoveu = 0; //indica que removeu
    int salveFlagRemoveu = 0; //confere se flagRemoveu ja foi ativada alguma vez, pois ele pode reiniciar durante o ciclo

    /* buffer */
    //armazena elementos p/ inserir
    int inserirEI[10];
    char inserirLE[10][25];
    char *inserirLEtoken;
    int inserirEF[10];

    /* contador */
    int contInserir = 0;

    //percorre d e pesquisa ei =i
    while(d != NULL)
    {
        if(d->ei == i)//encontrou ei =i
        {
            if(d->ei == d->ef)//aponta p/ ele mesmo
                flagApontaEleMesmo = 1;
            if(d->ef == principal->F->f)//aponta p/ FinalGeral
                flagFinal = 1;
        }
        d = d->prox;
    }
    //encontrou ei = i
    if(flagFinal == 1 && flagApontaEleMesmo == 1)
    {
        d = principal->D;//volta p/ inicio

        //pesquiso novamente p/ encontrar o mesmo ei=1
        while(d != NULL)
        {

            if(d->ei == i && d->ef == i) //encontrou d->ei=d->ef=i, (ex1.: 2 (a)* 2) ou (ex2.: 3 (b)*3)
            {
                dAux = principal->D; //volta p/ inicio do aux

                //procuro se existe um dAux->ei == i && dAux->ef == estado final geral
                while(dAux != NULL)
                {
                    //d deve possuir ei=ef, (ex1.: 2 (a)* 2) ou (ex2.: 3 (b)* 3)
                    //dAux deve ter dAux->ei == d->ei && dAux->ef== principal->F->f, (ex1.: 2 " " 4) ou (ex2.: 3 a(a)* 4)
                    if(d->ei == d->ef && dAux->ei == d->ef && dAux->ef == principal->F->f && flagFinal == 1)
                    {
                        //salva p/ inserir novo caminho
                        inserirEI[contInserir] = d->ei;
                        strcpy(inserirLE[contInserir], d->le);
                        strcat(inserirLE[contInserir], dAux->le);
                        inserirEF[contInserir] = principal->F->f;
                        ++contInserir;

                        //nao se pode apagar d ou dAux agr, pois eles ainda serao utilizados
                        //serao apagados em seguida, depois de inserir todos

                        //ativa flag p/indicar que removeu
                        flagRemoveu = 1;
                        salveFlagRemoveu += flagRemoveu;
                    }

                    //chama prox
                    dAuxSalve = dAux; //salve dAux anterior
                    dAux = dAux ->prox;
                }//FIM while dAux != NULL

                //confere se algo foi removido p/ ver se alteracoes sao necessarias
                if(flagRemoveu == 1)
                {
                    dSalve->prox = d->prox;

                    //volta posicao de d
                    d = dSalve;


                    //reinicia flag q indica se houve remocao
                    flagRemoveu = 0;
                }
            }
            dSalve = d;//salva posicao anterior /*e se isso nao acontecesse pq eh a primeira posicao da lista? dSalve = d antes do if aconteceu?*/
            d = d->prox;//chama prox
        }

        if(salveFlagRemoveu > 0)
        {
            //remove dAux
            dAux = cabeca; //mando p/ inicio
            dAuxSalve = dAux; //salva dAux anterior
            while(dAux != NULL)
            {
                d = cabeca; //precisa ser sempre o mesmo d, pois ele eh a referencia
                if(dAux->ei == i && dAux->ef == principal->F->f && flagFinal == 1)
                {
                    dAuxSalve->prox = dAux->prox;
                    dAux = dAuxSalve;
                }
                dAuxSalve = dAux;
                dAux = dAux->prox;
            }

            //insiro novos elementos
            for(int j = 0; j < contInserir; j++)
            {
                d = cabeca; //volta p/ inicio
                inserirLEtoken = strdup(inserirLE[j]);
                inserir_delta(inserirEI[j], inserirLEtoken, inserirEF[j], &d);
            }
        }
    }

    //chama eliminaEstados
    if(i <= principal->F->f - 1 && elimina == 1)
        eliminaEstados(principal->D, i, principal);

    //chama recursividade
    if(i < principal->F->f - 1)
        concatena(principal->D, ++i, principal, 0);
}
void eliminaEstados(t_delta *cabeca, int i, t_quintupla *principal)
{
    /* struct t_delta */
    t_delta *d = cabeca; //apelido principal
    t_delta *dAux = principal->D; // delta aux
    t_delta *dSalve = NULL;//salva d anterior

    /* flags */
    int flagAconteceu = 0; //encontramos ei =i
    int flagApagar = 0;// flag p/ nao apagar a mesma coisa varias vezes
    int flagRemove = 0; //indica que algo foi removido

    /* contadores */
    int contInserir = 0; //contagem p/ inserir
    int contApagarDaux = 0; //contagem p/ apagar

    /* buffer */
    //armazena le, caminho de d->ei ate dAux->ef
    char bufferLE[25] = " ";
    //armazena elementos alterados p/ apagar
    int apagarDAuxei[10];
    char apagarDAuxle[10][25];
    int apagarDAuxef[10];
    //armazena elementos p/ inserir
    int inserirEI[10];
    char inserirLE[10][25];
    char *inserirLEtoken;
    int inserirEF[10];

    //percorre d e ve se encontra ef =i
    d = cabeca;
    while(d != NULL)
    {
        if(d->ef == i)//encontrou ef =i
        {
            flagAconteceu = 1;
            break;
        }
        else
        {
            dSalve = d;
            d = d->prox;
        }
    }

    //ef=i foi encontrado. ef=1 ser eliminado de todos od possiveis ef, mas salvar o caminho ate ele
    if(flagAconteceu == 1)
    {
        //roda d
        while(d != NULL)
        {
            //reinicia flag
            flagRemove = 0;

            //encontrou ef==i
            if(d->ef == i)
            {
                //madnda da dAux p inicio
                dAux = principal->D;

                //reinicia contagem p/ inserir
                contInserir = 0;

                //roda dAux
                while(dAux != NULL)
                {
                    //confere se existe algum dAux->ei=d->ef
                    if(dAux->ei == i)
                    {
                        //salvar dAux p/ apagar posteriormente
                        if(flagApagar == 0) //flag evita tentativa de apagar o mesmo mais de uma vez
                        {
                            apagarDAuxei[contApagarDaux] = dAux->ei;
                            strcpy(apagarDAuxle[contApagarDaux], dAux->le);
                            strcpy(apagarDAuxle[contApagarDaux], dAux->le);
                            apagarDAuxef[contApagarDaux] = dAux->ef;
                            ++contApagarDaux;
                        }
                        //copia caminhos p/ inserir nova linha na lista
                        strcpy(bufferLE, d->le); //copia caminho de d->ei ate i
                        strcat(bufferLE, dAux->le); //concatena caminho de d->ei ate dAux->ef
                        //insere na lista
                        inserirEI[contInserir] = d->ei;
                        strcpy(inserirLE[contInserir], bufferLE);
                        inserirEF[contInserir] = dAux->ef;
                        ++contInserir;
                    }
                    dAux = dAux->prox;
                }

                //apagar d         
                if(d->ei == 0)//primeiro membro da lista
                {
                    d->ei = 1000;
                    d->ef = 1000;
                }
                else
                {
                    dSalve->prox = d->prox;
                    dSalve = dSalve->prox;
                    d = dSalve;
                    flagRemove = 1;
                }

                //inserir novas coisas
                for(int j = 0; j < contInserir; j++)
                {
                    if(inserirEI[j] == 2000)break;
                    inserirLEtoken = strdup(inserirLE[j]);
                    inserir_delta(inserirEI[j], inserirLEtoken, inserirEF[j], &d);
                    inserirEI[j] = 2000;
                }

                //nao precisa add mais a lista de apagar do dAux, pois sempre serao os mesmo
                flagApagar = 1;
            }

            //incia proximo ciclo
            if(flagRemove == 0) //n ha alteracao a ser feita
            {
                dSalve = d;
                d = d->prox;
            }
            else //nosso dSalve  ja esta apontando p/ o proximo
                d = dSalve;
        }

        //apagar dAux
        for(int j = 0; j < contApagarDaux; j++)
        {
            //reinicia flag
            flagRemove = 0;

            //manda p/ inicio da lista
            d = cabeca;

            //procura na lista p/ remover

            while(d != NULL)
            {
                if(d->ei == apagarDAuxei[j] && d->ef == apagarDAuxef[j] && (strcmp(apagarDAuxle[j], d->le) == 0))
                {
                    dSalve->prox = d->prox;
                    d = dSalve;
                    flagRemove = 1;
                }

                if(flagRemove == 0)
                {
                    dSalve = d;
                    d = d->prox;
                }
                else
                    break;
            }
        }
    }

    //chama concatena
    if(i < principal->F->f - 1)
        concatena(principal->D, ++i, principal, 1);
}

void remover_lef(int i, t_lef **cabeca)
{
    /*variaveis*/
    int j = 0;
    t_lef *copia = *cabeca;
    t_lef *plant = NULL;

    while(j < i)
    {
        j++;
        plant = copia;
        copia = copia->prox;
    }
    if(copia == NULL)
        return;
    if(plant != NULL)
        plant->prox = copia->prox;
    else
        *cabeca = copia->prox;
    free(copia);
    return;
}
void inserir_lef(int f, t_lef **cabeca)
{
    t_lef *copia = *cabeca;
    t_lef *plant = NULL;
    while(copia != NULL)
    {
        plant = copia;
        copia = copia->prox;
    }
    copia = malloc(sizeof(t_delta));
    copia->f = f;
    copia->prox = NULL;
    if(plant != NULL)
        plant->prox = copia;
    else
        *cabeca = copia;
    return;
}

void recebe_afd(FILE *file, t_quintupla **cabeca)
{
    t_quintupla *copia = *cabeca;
    copia = malloc(sizeof(t_quintupla));
    char c_file[256];
    char *token;
    char *copiatoken;
    int opt = 0;
    while(fgets(c_file, 256, file) != NULL)
    {
        if(opt == 1 && strstr(c_file, "#") == NULL)
            copia->K = atoi(c_file);
        if(opt == 2 && strstr(c_file, "#") == NULL)
            copia->A = c_file[0];
        if(opt == 3 && strstr(c_file, "#") == NULL)
            copia->S = atoi(c_file);
        if(opt == 4 && strstr(c_file, "#") == NULL)
        {
            copiatoken = strdup(c_file);
            while((token = strsep(&copiatoken, " ")) != NULL)
                inserir_final_st(token, &copia);
        }
        if(opt == 5 && strstr(c_file, "#") == NULL)
            inserir_delta_st(c_file, &copia);
        /* mudar a opcao pra proximas linhas */
        if(strstr(c_file, "#K"))
            opt = 1;
        if(strstr(c_file, "#A"))
            opt = 2;
        if(strstr(c_file, "#S"))
            opt = 3;
        if(strstr(c_file, "#F"))
            opt = 4;
        if(strstr(c_file, "#D"))
            opt = 5;
    }
    *cabeca = copia;
    return;
}

/* -------------------------------------------------------------- */
void inserir_final_st(char *palavra, t_quintupla **cabeca)
{
    t_lef *copia = (*cabeca)->F;
    t_lef *plant = NULL;
    while(copia != NULL)
    {
        plant = copia;
        copia = copia->prox;
    }
    copia = malloc(sizeof(t_lef));
    copia->f = atoi(palavra);
    copia->prox = NULL;
    if(plant != NULL)
        plant->prox = copia;
    else
        (*cabeca)->F = copia;
    return;
}

void inserir_delta_st(char *palavra, t_quintupla **cabeca)
{
    t_delta *copia = (*cabeca)->D;
    t_delta *plant = NULL;
    char *token;
    while(copia != NULL)
    {
        plant = copia;
        copia = copia->prox;
    }
    copia = malloc(sizeof(t_delta));
    token = strdup(palavra);
    copia->ei = atoi(strsep(&token, " "));
    copia->le = strsep(&token, " ");
    copia->ef = atoi(strsep(&token, " "));
    copia->prox = NULL;
    if(plant != NULL)
        plant->prox = copia;
    else
        (*cabeca)->D = copia;
    return;
}

void inserir_delta(int EI, char *LE, int EF, t_delta **cabeca)
{
    t_delta *copia = *cabeca;
    t_delta *plant = NULL;
    while(copia != NULL)
    {
        plant = copia;
        copia = copia->prox;
    }
    copia = malloc(sizeof(t_delta));
    copia->ei = EI;
    copia->le = LE;
    copia->ef = EF;
    copia->prox = NULL;
    if(plant != NULL)
        plant->prox = copia;
    else
        *cabeca = copia;
    return;
}

void remover_delta(int EI, char *LE, int EF, t_delta **cabeca)
{
    t_delta *copia = *cabeca;
    t_delta *plant = NULL;

    while(copia != NULL)
    {
        if(EI == copia->ei && EF == copia->ef && LE == copia->le)
            break;
        plant = copia;
        copia = copia->prox;
    }
    if(copia == NULL)
        return;
    if(plant != NULL)
        plant->prox = copia->prox;
    else
        *cabeca = copia->prox;
    free(copia);
    return;
}
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s v.%s - %s\n", "auto2.c", VERSION, "Convert AFD into Exp Reg");
    printf("\nUsage: %s [-h|-v|-c|-d]\n", "auto2");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    printf("\t-n, --AFD\n\t\tA entrada de dados eh um AFD(Automato Finito Deterministico) a ser convertido para uma ER(Expressao Regular), use $cat entrada.txt | ./auto2.x -d\n");
    printf("\n\nNote (-d): input data is an DFA (Deterministic Finite Automata) 5-tuple to be converted to RE (Regular Expression) string.\n");
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n", "Ruben Carlo Benante", "rcb@beco.cc");
    printf("                   Christopher Coutinho De Lucena Melo\n");
    printf("                   Davi Austregesilo Nepomuceno\n");
    printf("                   Jose Eduardo Oliveira Cavalcanti Lupa\n");
    printf("                   Rodolfo Prazim De Oliveira Barros\n");
    printf("                   Maria Cecilia Galvao Da Silva Jota\n");
    printf("                   Bruno Schwamborn\n");
    printf("                   Lara Vitoria Morais Nogueira\n\n");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "auto2", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */

