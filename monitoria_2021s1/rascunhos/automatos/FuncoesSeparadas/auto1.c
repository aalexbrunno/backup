/***************************************************************************
 *   auto1.c                               Version 20210512.104607         *
 *                                                                         *
 *   Convert AFnD to AFD                                                   *
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
 * @file auto1.c
 * @ingroup GroupUnique
 * @brief Converte AFND para AFD
 * @details This program really do a nice job as a template, and template only!
 * @version 20160618.013215
 * @date 2016-06-18
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
    $ gcc auto1.c -o auto1.x -Wall `allegro-config --cflags --libs`
 */


 /*   $gcc auto1.c -o auto1.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1 -DVERSION="0.1.160612.142044"
 *   ou preferencialmente inclua um makefile e use:
 *   $ make auto1.x
 *
 * Modelo de indentacao:
 * Estilo: --style=allman ou -A1
 *
 * Opcoes: -A1 -s4 -k3 -xj -SCNeUpv
 *
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astyle -A1 -s4 -k3 -xj -SCNeUpv exN.c
 */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in exN.h */

#include "auto1.h" /* declaracao de todas as funcoes presentes no codigo e define's */

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
 *    $./auto1.x -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20210512.104607
 * @date 2016-06-18
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    FILE *file;
    t_quintupla *q = NULL;
    t_quintupla *afd = NULL;

    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright and version
     *        -v  verbose
     *        -f  given file name
     */

    opterr = 0;
    while((opt = getopt(argc, argv, "hcnvf:")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'c':
                copyr();
                break;
            case 'n':
                break;
            case 'v':
                verb++;
                break;
            case 'f':
                file = fopen(optarg,"r"); /* abre arquivo com o nome dado apos o -f */
                if(file) /* confere se o arquivo realmente existe */
                {
                    IFDEBUG("Arquivo encontrado!");
                    printf("Nome do arquivo: %s\n", optarg);
                    recebe_afnd(file, &q); /* recebe os dados dentro do arquivo e armazena numa quintupla */
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
    if(q == NULL)  /* caso de nao encontre valor nenhum na quintupla */
    {
        printf("Erro nenhum valor encontrado na quintupla\n");
        return EXIT_FAILURE;
    }
    afd = calcular_afd(q); /* calcula a quintupla traduzida para de AFnD para AFD */
    if(afd != NULL) /* caso AFD exista imprime ela na tela */
        print_quintupla(afd);
    else /* caso a AFD apareca algum erro e nao seja criada */
        printf("Não foi possivel criar AFD\n");
    return EXIT_SUCCESS;
}

/**< recebe entrada de dados da quintupla de um FILE dado */
void recebe_afnd(FILE *file, t_quintupla **cabeca)
{
    IFDEBUG("recebe_afnd()");
    t_quintupla *copia = *cabeca;
    copia = malloc(sizeof(t_quintupla)); /* aloca a memoria para a quintupla copia */

    char c_file[256];   /* para leitura do FILE */
    char *token;        /* para utilizar o strsep e ler os estados finais e delta */
    char *copiatoken;   /* auxiliar no uso do strsep */
    int opt = 0;        /* controle do setor que sera adicionado o dado lido */

    while(fgets(c_file, 256, file) != NULL)         /* le todas as linhas do arquivo */
    {
        if(opt == 1 && strstr(c_file,"#") == NULL)
            copia->K = atoi(c_file);
        if(opt == 2 && strstr(c_file,"#") == NULL)
            copia->A = c_file[0];
        if(opt == 3 && strstr(c_file,"#") == NULL)
            copia->S = atoi(c_file);
        if(opt == 4 && strstr(c_file,"#") == NULL)
        {
            copiatoken = strdup(c_file);
            while((token = strsep(&copiatoken," ")) != NULL)
                inserir_final_st(token,&copia);
        }
        if(opt == 5 && strstr(c_file,"#") == NULL)
        {
            inserir_delta_st(c_file,&copia);
        }
        if(strstr(c_file,"#K")) /* ao encontrar #K proxima linha sera lida como numero de estados */
            opt = 1;
        if(strstr(c_file,"#A")) /* ao encontrar #A proxima linha sera lida como ultima letra do alfabeto */
            opt = 2;
        if(strstr(c_file,"#S")) /* ao encontrar #S proxima linha sera lida como estado inicial */
            opt = 3;
        if(strstr(c_file,"#F")) /* ao encontrar #F proxima linha sera lida como lista de estados finais */
            opt = 4;
        if(strstr(c_file,"#D")) /* ao encontrar #D proxima linha sera lida como lista da funcao de transicao d(ei, le, ef) */
            opt = 5;
    }

    *cabeca = copia; /* passa a nova quintupla copia para a variavel cabeca */

    return;
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

/**< Dado uma quintupla um estado inicial e o teste retorna seus destinos */
t_lef *calcular_estado_f(t_quintupla *q, unsigned short int num ,char *test)
{
    IFDEBUG("calcular_estado_f()");
    t_lef *list = NULL;
    t_lef *t_list = NULL;
    t_delta *delta = q->D;  /* recebe o delta da quintupla */
    int eps;                /* controle de trasicoes com epsilon */

    while(delta != NULL)    /* le toda a lista delta */
    {
        if(delta->ei == num && (strstr(delta->le,test)))    /* se encontra semelhanca entre o valor do delta e o num recebido pela funcao */
        {                                                   /* e tambem entre a letra do alfabeto e o teste */

            inserir_final(delta->ef,&list);     /* insere o valor de destino na list de estados destino */
            eps = delta->ef;                    /* eps recebe o valor do estado destino encontrado */
            while((t_list = calcula_epsilon(q, eps)) != NULL)   /* confere se ha transicoes com epsilon apartir do destino */
            {
                eps = t_list->f;        /* se encontrar novo valor a ser calculado sera o novo destino */
                while(t_list != NULL)   /*caso t_list nao seja nula*/
                {
                    inserir_final(t_list->f, &list); /* adiciona destino a list de estados destino */
                    t_list = t_list->prox;
                }
            }
        }
        delta = delta->prox;
    }
    return list;    /*retorna list de estados destino do num recebido com teste expecifico */
}

/**< calcula quais sao os novos finais dentro dos novos estados criados */
t_lef *calcular_novos_finais(t_quintupla *q, t_list_lef *list)
{
    IFDEBUG("calcular_novos_finais()");
    t_lef *novo = NULL;
    t_lef *copia = NULL;
    t_lef *final = q->F;

    while(final != NULL)    /* enquando a lista de estados finais anterior nao for vazia */
    {
        while(list != NULL) /* enquanto a lista de novos estados nao for vazia */
        {
            copia = list->F;        /* copia para manipular a comparacao */
            while(copia != NULL)    /* enquanto a copia nao for vazia */
            {
                if(final->f == copia->f)                /* confere se algum valor confere com ao da lista de antigos finais */
                    inserir_final(list->ord, &novo);    /* se sim, adiciona a lista dos novos finais */
                copia = copia->prox;
            }
            list = list->prox;
        }
        final = final->prox;
    }
    return novo; /* retorna lista de estados finais */
}
/**< dado uma lista de estados calcula sua lista de destino */
t_lef *calcular_estado(t_quintupla *q, t_lef *ei ,char *test)
{
    IFDEBUG("calcular_estado()");
    t_lef *list = NULL;
    t_lef *t_list = NULL;

    while(ei != NULL) /* enquanto a lista de estados nao for vazia */
    {
        t_list = calcular_estado_f(q, ei->f,test); /* calcula o estado final de um estado */
        while(t_list != NULL) /* enquanto a lista destino nao for vazia */
        {
            inserir_final(t_list->f, &list); /* se ainda nao tiver na lista, insere o destino */
            t_list = t_list->prox;
        }
        ei = ei->prox;
    }
    return list; /* retorna lista estado destino da lista dada */
}

/**< calcula estado destino se tiver transicao em epsilon */
t_lef *calcula_epsilon(t_quintupla *q, unsigned short int num)
{
    IFDEBUG("calcular_epsilon()");
    t_lef *list = NULL;
    t_delta *copia = q->D; /* recebe delta de uma quintupla */

    while(copia!= NULL) /* enquanto copia nao for vazia */
    {
        if(copia->ei == num && (strstr(copia->le,"E"))) /* confere se num tem trasicao com epsilon*/
            inserir_final(copia->ef,&list); /* se tem, adiciona a lista */
        copia = copia->prox;
    }
    return list; /* retorna lista de transicao com epsilon */
}

/**< calcula uma nova lista delta com uma nova lista de estados */
t_delta *novo_delta(t_quintupla *q, t_list_lef *list)
{
    IFDEBUG("novo_delta()");
    t_list_lef *copia = list; /* copia para comparacao */
    t_delta *novo = NULL;
    t_lef *destino = NULL;
    char alfabeto[] = "abcdefghijklmnopqrstuvwxyz"; /* variaveis para calcular os testes com as letras */
    char alf = q->A;                                /* recebe letra final da quintupla */
    char *token;                                    /* ponteiro para a funcao de teste */
    int i = 0;                                      /* para sequenciar as letras */

    while(list != NULL) /* enquanto lista nao for NULL */
    {
        while(alf != alfabeto[i-1]) /* compara se chegou na letra final */
        {
            token = strndup(&alfabeto[i], 1);   /* ponteiro recebe letra */
            i++;                                /* soma em i para proximo ponteiro receber proxima letra */
            destino = calcular_estado(q, list->F,token); /* calcula destino com a determinada letra */
            if(destino != NULL)     /* se existe destino adiciona um delta a lista */
                inserir_delta(
                        ord_novo(copia, list->F),
                        token,
                        ord_novo(copia, destino),
                        &novo
                        );
        }
        i = 0; /* reseta o 0 para comparacao de um novo estado */
        list = list->prox;
    }

    return novo; /* retorna novo dos novos estados */
}

/**< calcula uma *lista* de lista de estados */
t_list_lef *calcular_list_lef(t_quintupla *q, t_lef *list)
{
    IFDEBUG("calcular_list_lef()");
    t_list_lef *ll = NULL;
    t_lef *t_list = NULL;
    char alfabeto[] = "abcdefghijklmnopqrstuvwxyz"; /* variaveis para calcular os testes com as letras */
    char alf = q->A;                                /* recebe letra final da quintupla */
    char *token;                                    /* ponteiro para a funcao de teste */
    int i = 0;                                      /* para sequenciar as letras */

    while(alf != alfabeto[i-1]) /* compara se chegou na letra final */
    {
        token = strndup(&alfabeto[i],1);    /* ponteiro recebe letra */
        i++;                                /* soma em i para proximo ponteiro receber proxima letra */
        t_list = calcular_estado(q, list, token);   /* calcula destino com a determinada letra */
        if(t_list != NULL)      /* se existe destino adiciona a lista na *lista* */
            inserir_list_final(t_list, &ll);
    }

    return ll; /* retorna a lista */
}

/**< recebe as listas quintupla AFnD, novo delta e novo final e monta a nova quintupla AFD*/
t_quintupla *montar_afd(t_quintupla *q, t_delta *delta, t_list_lef *list, t_lef *ef)
{
    IFDEBUG("montar_afd()");
    t_quintupla *novo = NULL;
    t_list_lef *copia = list;
    int i = 0; /* numero de novos estados */

    while(copia != NULL) /* confere quantos estados novos tem */
    {
        i++; /* acrescenta 1 a cada estado encontrado */
        copia = copia->prox;
    }
    novo = malloc(sizeof(t_quintupla)); /* aloca memoria para a nova quintupla*/
    novo->K = i;                        /* K recebe o numero de estados */
    novo->A = q->A;                     /* A recebe letra final da quintupla AFnD */
    novo->S = 0;                        /* S sera o 0 da nova lista */
    novo->F = ef;                       /* F recebe a nova lista de estados finais */
    novo->D = delta;                    /* D recebe a nova lista de delta */

    return novo; /* retorna a quintupla AFD */
}

/**< recebe uma quintupla AFnD e retorna sua AFD correspondente */
t_quintupla *calcular_afd(t_quintupla *q)
{
    IFDEBUG("calcular_afd()");
    t_quintupla *afd = NULL;
    t_delta *n_delta = NULL;
    t_list_lef *base = NULL;
    t_list_lef *ll = NULL;
    t_list_lef *calculo = NULL;
    t_lef *inic = NULL;
    t_lef *n_lef = NULL;

    inserir_final(q->S,&inic);          /* adiciona o estado inicial a lista a ser calculada */
    inserir_list_final(inic, &base);    /* adiciona a base dos novos estados */
    ll = calcular_list_lef(q, inic);    /* calcula os destinos do estados inicial */
    while(ll != NULL)   /* enquanto a lista nao for nula */
    {
        calculo = calcular_list_lef(q,ll->F);   /* calcular os estados finais de cada componente da lista */
        while(calculo != NULL)  /* enquanto a lista nao for nula */
        {
            if(buscar_list(calculo->F,base) == 0)   /* caso o estado final nao exista na lista base */
                inserir_list_final(calculo->F,&ll); /* adiciona a lista "ll" para calcular seus estados finais */
            calculo = calculo->prox;                /* proximo da lista de calculo */
        }
        inserir_list_final(ll->F,&base);    /* adiciona o valor de estado inicial/destino a lista base */
        ll = ll->prox; /* proximo da lista de "ll" */
    }
    n_delta = novo_delta(q, base);          /* calcula o novo delta com a nova lista de estados "base" */
    n_lef = calcular_novos_finais(q,base);  /* calcula a nova lista de estados finais aceitos */
    afd = montar_afd(q,n_delta,base,n_lef); /* monta a quintupla da AFD com os valores calculados anteriormente */

    return afd; /* retorna a quintupla */
}

/**< confere em qual ordem esta o estado na lista dos novos estados */
int ord_novo(t_list_lef *list, t_lef *lef)
{
    IFDEBUG("ord_novo()");
    while(list != NULL) /* enquanto lista nao for NULL */
    {
        if(buscar(list->F,lef) == 1) /* se achar o lista_estado na lista retorna sua ordem */
            return list->ord;
        list = list->prox;
    }

    return -1; /* se nao achar retorna -1 ERRO */
}

/**< confere na lista delta se a transicao existe */
int delta_existe(t_quintupla *q, unsigned short int num ,char *test)
{
    IFDEBUG("delta_existe()");
    t_delta *delta = q->D;
    while(delta != NULL) /* enquanto delta nao for NULL */
    {
        if(delta->ei == num && (strstr(delta->le,test))) /* se existe a trasicao com o num e test dado retorna 1 */
            return 1;
        delta = delta->prox;
    }

    return 0; /* se nao achar transicao retorna 0 */
}

/**< confere se duas listas t_lef tem os mesmo valores */
int buscar(t_lef *est , t_lef *est2)
{
    IFDEBUG("buscar()");
    if(est == NULL || est2 == NULL) /* caso alguma for NULL retorna 0 */
        return 0;
    while(est != NULL && est2 != NULL) /* enquanto as lista nao forem NULL */
    {
        if(est->f != est2->f) /* se encontrar valor diferente retorna 0 */
            return 0;
        est2 = est2->prox;
        est = est->prox;
    }
    if(est == NULL && est2 == NULL) /* se ambas forem NULL retorna 1 */
        return 1;
    else                            /* se nao retorna 0 */
        return 0;
}

/**< confere se existe uma lista t_lef numa lista t_list_lef */
int buscar_list(t_lef *est, t_list_lef *list)
{
    IFDEBUG("buscar_list()");
    if(est == NULL || list == NULL)     /* caso alguma for NULL retorna 0 */
        return 0;
    while(list != NULL)     /* enquanto t_list_lef nao for NULL */
    {
        if(buscar(est,list->F) == 1)    /* se existe semelhanca entre as listar retorna 1 */
            return 1;
        list = list->prox;
    }

    return 0;   /* caso nao tenha semelhanca retorna 0 */
}

/**< junta duas listas t_list_lef */
void juntar_lef_list(t_list_lef *est, t_list_lef **est2)
{
    IFDEBUG("juntar_lef_list()");
    while(est != NULL) /* quanto est nao for NULL */
    {
        if(buscar_list(est->F,(*est2)) == 0) /* se nao existe na lista principal */
            inserir_list_final(est->F,est2); /* adiciona na lista est2 */
        est = est->prox;
    }

    return;
}

/**< remvove um t_lef de uma t_list_lef */
void remover_list_final(t_lef *est , t_list_lef **cabeca)
{
    IFDEBUG("remover_list_final()");
    t_list_lef *copia = *cabeca; /*recebe ponteiro da cabeca */
    t_list_lef *plant = NULL;
    if(est == NULL) /* se est for NULL retorna */
        return;
    while(copia != NULL) /* enquanto copia nao for NULL */
    {
        if(buscar(copia->F,est) != 0) /* se achar o est na lista para o loop */
            break;
        plant = copia;
        copia = copia->prox;
    }
    if(copia == NULL)   /* se nao existe copia retorna */
        return;
    if(plant != NULL)   /* se achou e plant existe retira est da sequencia */
        plant->prox = copia->prox;
    else                /* se plant nao existe cabeca recebe proximo nodo de copia */
        *cabeca = copia->prox;
    free(copia);        /* libera memoria de copia */

    return;
}

/**< inserir um t_lef de uma t_list_lef */
void inserir_list_final(t_lef *est , t_list_lef **cabeca)
{
    IFDEBUG("inserir_list_final()");
    t_list_lef *copia = *cabeca; /* recebe ponteiro da cabeca */
    t_list_lef *plant = NULL;
    if(est == NULL) /* se est for NULL retorna */
        return;
    if(buscar_list(est,(*cabeca)) == 1) /* se ja existe est dentro da t_list_lef retorna */
        return;
    while(copia != NULL) /* enquanto copia nao for NULL */
    {
        if(copia->F == est) /* se copia tiver mesmo ponteiro de est retorna */
            return;
        plant = copia;
        copia = copia->prox;
    }

    copia = malloc(sizeof(t_list_lef)); /* aloca memoria ao novo nodo da lista */
    if(plant != NULL)                   /* se existe lista pega o ultimo ord e soma 1 */
        copia->ord = plant->ord + 1;
    else                                /* caso seja o primeiro recebe 0 */
        copia->ord = 0;
    copia->F = est;                     /* recebe lista est */
    copia->prox = NULL;                 /* proximo nodo NULL */
    if(plant != NULL)                   /* se plant existe adicina ao seu final */
        plant->prox = copia;
    else                                /* se nao cabeca recebe copia */
        *cabeca = copia;

    return;
}

/**< Insere um numero em uma t_lef */
void inserir_final(int num, t_lef **cabeca)
{
    IFDEBUG("inserir_final()");
    t_lef *copia = *cabeca; /* copia recebe cabeca */
    while(copia != NULL) /* enquanto cabeca nao for NULL */
    {
        if(copia->f == num) /* se achar num na list retorna */
            return;
        copia = copia->prox;
    }
    t_lef *aux, *novo = malloc(sizeof(t_lef)); /* aloca memoria para novo nodo */
    novo->f = num; /* recebe num */

    if(*cabeca == NULL)             /* caso cabeca seja NULL, cabeca recebe novo*/
    {
        novo->prox = NULL;
        *cabeca = novo;
    }
    else if(novo->f < (*cabeca)->f) /* caso cabeca tenha valor maior novo vira primeiro membro */
    {
        novo->prox = *cabeca;
        *cabeca = novo;
    }
    else                            /* caso cabeca seja menor */
    {
        aux = *cabeca;
        while(aux->prox && novo->f > aux->prox->f) /* acha o proximo nodo que seja maior que num */
            aux = aux->prox;
        novo->prox = aux->prox;
        aux->prox = novo;
    }

    return;
}

/**< insere um novo nodo a uma t_delta */
void inserir_delta(int EI, char *LE, int EF, t_delta **cabeca)
{
    IFDEBUG("inserir_delta()");
    t_delta *copia = *cabeca; /* recebe cabeca */
    t_delta *plant = NULL;
    while(copia != NULL) /* enquanto copia nao for NULL */
    {
        plant = copia;
        copia = copia->prox;
    }
    copia = malloc(sizeof(t_delta));    /* aloca menoria */
    copia->ei = EI;                     /* recebe estado inicial */
    copia->le = LE;                     /* recebe letra */
    copia->ef = EF;                     /* recebe estado final */
    copia->prox = NULL;                 /* proximo nodo NULL */
    if(plant != NULL)       /* se plant existe copia e proximo nodo */
        plant->prox = copia;
    else                    /* se plant nao existe copia é primeiro nodo */
        *cabeca = copia;

    return;
}

/**< Recebe uma string (linha do file) e passa para lista t_lef da quintupla */
void inserir_final_st(char *palavra, t_quintupla **cabeca)
{
    IFDEBUG("inserir_final_st()");
    t_lef *copia = (*cabeca)->F; /* recebe t_lef da quintupla */
    t_lef *plant = NULL;
    while(copia != NULL) /* enquanto copia for NULL */
    {
        plant = copia;
        copia = copia->prox;
    }
    copia = malloc(sizeof(t_lef));  /* aloca memoria */
    copia->f = atoi(palavra);       /* recebe e passa um char para int */
    copia->prox = NULL;             /* proximo nodo e NULL */
    if(plant != NULL)       /* se plant existe copia e proximo nodo */
        plant->prox = copia;
    else                    /* se plant nao existe copia é primeiro nodo */
        (*cabeca)->F = copia;

    return;
}

/**< Recebe uma string (linha do file) e passa para lista t_delta  da quintupla*/
void inserir_delta_st(char *palavra, t_quintupla **cabeca)
{
    IFDEBUG("inserir_delta_st()");
    t_delta *copia = (*cabeca)->D; /* recebe t_delta da quintupla */
    t_delta *plant = NULL;
    char *token;                   /* para ter uma copia da palavra */
    while(copia != NULL) /* enquanto copia for NULL */
    {
        plant = copia;
        copia = copia->prox;
    }
    copia = malloc(sizeof(t_delta));        /* aloca memoria */
    token = strdup(palavra);
    copia->ei = atoi(strsep(&token," "));   /* recebe primeira parte da palavra e passa pra int */
    copia->le = strsep(&token," ");         /* recebe segunda parte da palavra*/
    copia->ef = atoi(strsep(&token," "));   /* recebe terceira parte da palavra e passa pra int */
    copia->prox = NULL;                     /* proximo nodo e NULL */
    if(plant != NULL)       /* se plant existe copia e proximo nodo */
        plant->prox = copia;
    else                    /* se plant nao existe copia é primeiro nodo */
        (*cabeca)->D = copia;

    return;
}

void imagemAFD(void)
{
  BITMAP *buff;
  PALETTE pal;

  if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
    exit(EXIT_FAILURE);

  set_color_depth(16);
  get_palette(pal);

  // Create a buffer for smooth animation.
  buff = create_bitmap(800,800);

  if(buff == NULL)
  {
    printf("Could not create buffer!\n");
    exit(0);
  }

  circle(buff, 580, 170, 100, CORAMARELO);
  circle(buff, 180, 170, 100, CORBRANCO);
  circle(buff, 380, 600, 100, CORAMARELO);
  textprintf_ex(buff, font, 570, 150, CORVERDE, CORPRETO, "Q1");
  textprintf_ex(buff, font, 180, 150, CORVERDE, CORPRETO, "Q0");
  textprintf_ex(buff, font, 380, 600, CORVERDE, CORPRETO, "Q2");

  textprintf_ex(buff, font, 375, 130, CORVERDE, CORPRETO, "A");
  textprintf_ex(buff, font, 375, 730, CORVERDE, CORPRETO, "B");
  textprintf_ex(buff, font, 180, 375, CORVERDE, CORPRETO, "B");
  textprintf_ex(buff, font, 570, 375, CORVERDE, CORPRETO, "B");
  textprintf_ex(buff, font, 610, 60, CORVERDE, CORPRETO, "A,B");


  textprintf_ex(buff, font, 680, 55, CORVERDE, CORPRETO, "Entrada: A,B");
  textprintf_ex(buff, font, 680, 70, CORVERDE, CORPRETO, "Inicial: Q0");
  textprintf_ex(buff, font, 680, 85, CORVERDE, CORPRETO, "Final: Q1 ou Q2");


  //save_bitmap(IMAGENAME, buff, pal);

  destroy_bitmap(buff);

  allegro_exit();

  //printf("A imagem %s foi salva sem erros!\n", IMAGENAME);

  return;
}

void imagemAFND(void)
{
  BITMAP *buff;
 // BITMAP *buff2;
  PALETTE pal;

  if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
    exit(EXIT_FAILURE);

  set_color_depth(16);
  get_palette(pal);

  // Create a buffer for smooth animation.
  buff = create_bitmap(800,800);

  if(buff == NULL)
  {
    printf("Could not create buffer!\n");
    exit(EXIT_FAILURE);
  }

  circle(buff, 580, 170, 100, CORAMARELO);
  circle(buff, 180, 170, 100, CORBRANCO);
  circle(buff, 380, 600, 100, CORBRANCO);
  textprintf_ex(buff, font, 570, 150, CORVERDE, CORPRETO, "Q1");
  textprintf_ex(buff, font, 180, 150, CORVERDE, CORPRETO, "Q0");
  textprintf_ex(buff, font, 380, 600, CORVERDE, CORPRETO, "Q2");

  textprintf_ex(buff, font, 375, 130, CORVERDE, CORPRETO, "A");
  textprintf_ex(buff, font, 375, 730, CORVERDE, CORPRETO, "B");
  textprintf_ex(buff, font, 180, 375, CORVERDE, CORPRETO, "B");
  textprintf_ex(buff, font, 570, 375, CORVERDE, CORPRETO, "E");
  textprintf_ex(buff, font, 610, 60, CORVERDE, CORPRETO, "A,B");

  textprintf_ex(buff, font, 680, 55, CORVERDE, CORPRETO, "Entrada: A,B");
  textprintf_ex(buff, font, 680, 70, CORVERDE, CORPRETO, "Inicial: Q0");
  textprintf_ex(buff, font, 680, 85, CORVERDE, CORPRETO, "Final: Q1");

  //save_bitmap(IMAGENAME, buff, pal);

  destroy_bitmap(buff);

  allegro_exit();

  //printf("A imagem %s foi salva sem erros!\n", IMAGENAME);

  return;
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160618.013215
 * @date 2016-06-18
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "exN", "Converte AFD, AFND e ER");
    printf("\nUsage: %s [-h|-v]\n", "exN");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    /* add more options here */
    printf("\n\nNote (-n): input data is a NFA (Nondeterministic Finite Automata) 5-tuple to be converted to a DFA (Deterministic Finite Automata) 5-tuple.\n");
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
 * @version 20160618.013215
 * @date 2016-06-18
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
/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */


