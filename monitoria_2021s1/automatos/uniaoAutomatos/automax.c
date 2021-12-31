/***************************************************************************
 *   automax.c                             Version 20210512.104607         *
 *                                                                         *
 *   Converte AFD, AFND e ER                                               *
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
 * @file automax.c
 * @ingroup GroupUnique
 * @brief Converte AFD, AFND e ER
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

/*
 * Instrucoes para compilar:
 *  $gcc automax.c -o automax.x -Wall `allegro-config --cflags --libs`
 *
 * Modelo de indentacao:
 * Estilo: --style=allman ou -A1
 *
 * Opcoes: -A1 -s4 -k3 -xj -SCNeUpv
 *
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv exN.c
 */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in automax.h */

#include "automax.h" /* To be created for this template if needed */

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
 *    $./automax -h
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
    int convert = 0; /* controle do tipo de conversao */
    int entrada = 1; /* variavel de controle de tipo de entrada 0 - para arquivo e 1 - para entrada manual */
    int r, s = 0; /* variaveis para controle do allegro do AFND 2 AFD */
    
    char name_file[SBUFF]; /* variavel para receber optarg da flag -f */
    char str[SBUFF]; /* variavel para receber a string do ER 2 AFND */
    char entrada1[SBUFF] = "01-teste-AFND.txt";
    char entrada2[SBUFF] = "02-teste-AFND.txt";

    FILE *file; /* arquivo para entrada da optarg */
    FILE *arq = NULL; /* arquivo para a entrada manual do ER 2 AFND */
    FILE *read; /* arquivo usado para entrada da string */
    
    t_quintupla *afnd = NULL;
    t_quintupla *afd = NULL;

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright e versao
     *        -v  verbose
     *        -f  entrada por aquivo
     *
     *        -n  conversao AFND->AFD 
     *        -d  conversao AFD->ER
     *        -e  conversao ER->AFND
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "vhcf:nde")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'c':
                copyr();
                break;
            case 'v':
                verb++;
                break;
            case 'f':
                strncpy(name_file, optarg, SBUFF); /* recebe o nome de um arquivo com maximo de tamanho de SBUFF (256) */
                entrada = 0; /* entrada 0 representa entrada por arquivo */
                break;
            case 'n':
                convert = 1; /* conversao vai ser do tipo AFND - AFD */
                break;
            case 'd':
                convert = 2; /* conversao vai ser do tipo AFD - ER */
                break;
            case 'e':
                convert = 3; /* conversao vai ser do tipo ER - AFND */
                break;
            /*
            * -n : a entrada de dados é uma quíntupla de um AFND que será convertido para AFD.
            * -d : a entrada de dados é uma quíntupla de um AFD que será convertido para uma ER.
            * -e : a entrada de dados é uma _string_ de uma ER que será convertida em um AFND.
            */
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }
    /* ---------------------------------------------- */
    /* ------------------Verbose--------------------- */
    if(verb)
        printf("Verbose level set at: %d\n", verb);
    
    /* ---------------------------------------------- */
    /* ----------------Entrada de dados-------------- */
    if(entrada) /* entrada manual */
    {
        if(convert == 1 || convert == 2)    /* convert 1 e 2 */
            m_recebe_afnd(&afnd);           /* entrada de uma quintupla */
        else
        {
            arq = fopen("temp.txt","a");    /* abre o arquivo */
            scanf("%s", str);               /* entrada do dado manual */
            fprintf(arq,"%s",str);          /* printa no arquivo */
            fflush(arq);                    /* atualiza o arquivo */

            read = fopen("temp.txt","r");   /* abre o arquivo em modo de leitura*/
            le_arquivo(read);               /* tradução do ER para AFND */
            remove("temp.txt");             /* remove o arquivo */
        }
    }
    else /* entrada por arquivo */
    {
        file = fopen(name_file,"r");        /* abre arquivo com name_file recebido */
        if(!file) /* se arquivo nao foi criado termina o codigo */
            exit(EXIT_SUCCESS);
    }
    
    /* ---------------------------------------------- */
    /* -------------------Allegro-------------------- */
    r = strcmp(name_file,entrada1); /* caso a entrada seja a 01, retorna 0 */
    s = strcmp(name_file,entrada2); /* caso a entrada seja a 02, retorna 0 */

    if(r == 0)
    {
        imagemAFND_01(); /* se for, imprime respectiva representacao do AFND */
        imagemAFD_01(); /* se for, imprime respectiva representacao do AFD */
    }

    if(s == 0)
    {
        imagemAFND_02(); /* se for, imprime respectiva representacao do AFND */ 
        imagemAFD_02(); /* se for, imprime respectiva representacao do AFD */  
    }

    /* ---------------------------------------------- */
    /* ------------------Conversao------------------- */
    switch(convert)
    {
        case 1: /* conversao vai ser do tipo AFND - AFD */
            if(entrada == 0) /* entrada por file */
                recebe_afnd(file, &afnd);   /* funcao recebe afnd do arquivo */
            afd = calcular_afd(afnd);       /* funcao retorna a traducao */
            print_quintupla(afd);           /* print afd na tela */
            break;
        case 2: /* conversao vai ser do tipo AFD - ER */
            if(entrada == 0 ) /* entrada por arquivo */
                recebe_afd(file, &afnd); /* recebe AFD */
            afd2er(afnd); /* traduz para ER e imprime */
            break;
        case 3: /* conversao vai ser do tipo ER - AFND */
            if(entrada == 0) /* entrada por arquivo */
                le_arquivo(file);
            break;
        default: /* caso nao tenha conversao imprime a help */
            help();
            return EXIT_FAILURE;
    } 
    
    /* ---------------------------------------------- */
    /* ---------------------------------------------- */

    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/**< Recebe o AFnD de forma manual */
void m_recebe_afnd(t_quintupla **cabeca)
{
    t_quintupla *copia = *cabeca;
    char c_file[SBUFF] = "";
    int opt = 0;        /* controle do setor que sera adicionado o dado lido */
    char *token;        /* para utilizar o strsep e ler os estados finais e delta */
    char *copiatoken;   /* auxiliar no uso do strsep */
    char parada[] = "\n";
    copia = malloc(sizeof(t_quintupla)); /* aloca a memoria para a quintupla copia */

    while(fgets(c_file, sizeof(c_file), stdin) != NULL && strncmp(c_file,parada,1) != 0)
    {
        if(opt == 1 && strstr(c_file,"#") == NULL)
            copia->K = atoi(c_file);                /* pega a string e passa para numero e adiciona no K (numero de estados) */
        if(opt == 2 && strstr(c_file,"#") == NULL)
            copia->A = c_file[0];                   /* pega a letra e adiciona no A (letra final) */
        if(opt == 3 && strstr(c_file,"#") == NULL)
            copia->S = atoi(c_file);                /* pega a string e passa para numero e adiciona no S (estado inicial) */
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

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
/**< Dado uma quintupla um estado inicial e o teste retorna seus destinos */
t_lef *calcular_estado_f(t_quintupla *q, unsigned short int num ,char *test)
{
    t_lef *list = NULL;
    t_lef *t_list = NULL;
    t_delta *delta = q->D;  /* recebe o delta da quintupla */
    
    while(delta != NULL)    /* le toda a lista delta */
    {
        if(delta->ei == num && (strstr(delta->le,test)))/* se encontra semelhanca entre o valor do delta e o num recebido pela funcao */
        {
            inserir_final(delta->ef, &list);            /* insere o destino na list */
            t_list = calcula_est_inic(q, delta->ef);    /* calcula se esse destino tem transicoes com E */
            while(t_list != NULL)                       /* se existe */
            {
                if(t_list->f == delta->ei)  /* se for igual ao destino */
                    t_list = t_list->prox;  /* proximo ponteiro */
                else                        /* se nao for igual */
                {
                    inserir_final(t_list->f, &list); /* insere na list */
                    t_list = t_list->prox;           /* proximo ponteiro */
                }
            }
        }
        delta = delta->prox; /* proximo ponteiro */
    }
    return list;    /*retorna list de estados destino do num recebido com teste expecifico */
}

/* ---------------------------------------------------------------------- */
/**< calcula quais sao os novos finais dentro dos novos estados criados */
t_lef *calcular_novos_finais(t_quintupla *q, t_list_lef *base)
{
    IFDEBUG("calcular_novos_finais()");
    t_lef *novo = NULL;
    t_lef *copia = NULL;
    t_list_lef *list = base;
    t_lef *final = q->F;

    while(final != NULL)    /* enquando a lista de estados finais anterior nao for vazia */
    {
        list = base;
        while(list != NULL) /* enquanto a lista de novos estados nao for vazia */
        {
            copia = list->F;        /* copia para manipular a comparacao */
            while(copia != NULL)    /* enquanto a copia nao for vazia */
            {
                if(final->f == copia->f)                /* confere se algum valor confere com ao da lista de antigos finais */
                {
                    inserir_final(list->ord, &novo);    /* se sim, adiciona a lista dos novos finais */
                    break;
                }
                copia = copia->prox;
            }
            list = list->prox;
        }
        final = final->prox;
    }
    return novo; /* retorna lista de estados finais */
}

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
/**< Calcula uma lista de todos os estados encontrados com a transicao E */
t_lef *calcula_est_inic(t_quintupla *q, unsigned short int num)
{
    t_lef *inic = NULL;
    t_lef *cop = NULL;
    t_lef *n_lef = NULL;

    inserir_final(num, &cop);       /* insere o num numa lista t_lef */
    n_lef = calcula_epsilon(q, num);/* calcula se o num tem transicoes com E */
    while(n_lef != NULL)            /* enquanto existir n_lef */
    {
        inserir_final(n_lef->f,&cop);           /* insere o numero que n_lef atual armazena em cop */
        inic = calcula_epsilon(q, n_lef->f);    /* calcula se esse numero tem transicoes com E */
        while(inic != NULL)                     /* se existir */
        {
            if(buscar_f(cop, inic->f) == 0)     /* confere se esse numero ja existe na lista cop */
                inserir_final(inic->f,&n_lef);  /* caso nao, adiciona a n_lef para ser calculada */
            inic = inic->prox;
        }
        if(buscar_f(cop, n_lef->f)) /* confere se o valor atual da n_lef existe em cop */
            n_lef = n_lef->prox;    /* se nao, passa para o proximo ponteiro da lista */
    }
    return cop; /* retorna a lista com todas as trasicoes com E */
}

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
/**< recebe uma quintupla AFnD e retorna sua AFD correspondente */
t_quintupla *calcular_afd(t_quintupla *q)
{
    t_quintupla *afd = NULL;
    t_delta *n_delta = NULL;
    t_list_lef *base = NULL;
    t_list_lef *ll = NULL;
    t_list_lef *calculo = NULL;
    t_lef *inic = NULL;
    t_lef *n_lef = NULL;

    inic = calcula_est_inic(q, q->S);   /* calcula o estado inicial */
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

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
/**< confere se um numero existe em um t_lef */
int buscar_f(t_lef *est, unsigned short int num)
{
    while(est != NULL) /* enquanto as lista nao forem NULL */
    {
        if(est->f == num) /* se encontrar valor igual retorna 1 */
            return 1;
        est = est->prox;
    }
    return 0; /* se nao retorna 0 */
}

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
/**< remove um t_lef de uma t_list_lef */
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

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------- */
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

/*-----------------------------------------------------------------------*/
/* AFD -> ER */
/*-----------------------------------------------------------------------*/
/* recebe o afd */
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

/*-----------------------------------------------------------------------*/
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

/*-----------------------------------------------------------------------*/
/*  */
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

/*-----------------------------------------------------------------------*/
/* remover do t_delta */
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

/*-----------------------------------------------------------------------*/
/*  */
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

/*-----------------------------------------------------------------------*/
/*  */
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

/*-----------------------------------------------------------------------*/
/* elimina estados */
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

/*-----------------------------------------------------------------------*/
/* transformaçao final para ER */
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
    char bufferLE[70]; /* Buffer rotulo do arco */
    char bufferLeFinal[140]; /* Buffer rotulo do arco final */
    char str1[20]; /* Copia da string d->le */
    char str2[20]; /* Copia da string dAux->le */
    char STR1[20]; /* Copia da string d->le */
    char STR2[20]; /* Copia da string dAux->le */
    char bufferCompara[2]; /* Buffer usado para comparacao de caractere*/
    char bufferSinais[2]; /* Buffer usado para comparacao de sinais */
    char bufferFinalMesmo[80]; /* Buffer rotulo do arco Final */
    char printFinal[80]; /* Expressao Regular Final */

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
            //dAnt->prox = d->prox;
            //d=dAnt;
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

/*-----------------------------------------------------------------------*/
//ER2AFND
/*--------------------------------------------------------------------------*/
//Abre os arquivos e le o arquivo iniciando o processo//

void le_arquivo(FILE *exp_reg){

    char c; //Variável que receberá o caracter da leitura do arquivo de texto.
    char palavra[SBUFF] = ""; //variavel utilizada na chamada do allegro
    int i = 0;
    int j = 0;
    int k = 0; //variavel que realiza o loop auxiliar
    int contagem = 96; //contagem dos caracteres ascii a partir do numero 96 (letra 'a' minuscula)
    int fsize = 0; //Variável que contará a qauntidade de caracteres no arquivo de texto.

    int p1 = 0; //Parêntese aberto. 
    int p2 = 0; //Parêntese fechado.
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
        if (c=='('){
            p1++;
        }
        if(c == ')'){
            p2++;
        }
        k++;

    }
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
    int pesquisa_ef = 0;
    int ei[SBUFF]; //Estados iniciais.
    int cont_ei = 0; //Variável que representará a posição de 'ei'.
    char E = 'E'; //Variável que armazena a letra 'E', a qual simula a letra 'Épsilon'.

    t_quintupla *list_auto = novo_afnd;

    while(linha[i] != '\0'){ //Roda o laço até chegar ao fim da palavra.

        if((linha[i] == '.') || ((linha[i] > 96 && linha[i] < 123) && linha[i+1] == '(') || (linha[i] == ')' && (linha[i+1] > 96 && linha[i+1] < 123))){
            organiza_listas(&list_auto->D, *est, E, *est+1);
            *est += 1;
        }
        if(linha[i] != '\n' && linha[i] != '*' && linha[i] != '.'){ //Caso o caracter lido seja uma letra.
            if(i == 0){
                if(*est != 0){ //Ao entrar nesse 'if', o '*est' terá o mesmo valor dos estados de aceitação.
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

                   
                    if(cont_ei == 0){
                        montar_loop(list_auto, ei[1],*est);
                    }
                   
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

    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();

    return EXIT_SUCCESS;

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


        save_bitmap(IMAGENAME, buff, pal);
        destroy_bitmap(buff);
        allegro_exit();

        printf("Imagem %s salva com sucesso!\n", IMAGENAME);

        return EXIT_SUCCESS;
   
return 0;
}


/* ---------------------------------------------------------------------- */

/**< Cria imagem AFD da entrada 01 */
void imagemAFD_01(void)
{
  BITMAP *buff;
  PALETTE pal;

  if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
    exit(EXIT_FAILURE);

  set_color_depth(16);
  get_palette(pal);

  // Cria buffer
  buff = create_bitmap(800,800);

  if(buff == NULL)
  {
    printf("Nao foi possivel criar buffer!\n");
    exit(0);
  }

  /* Cria circulos */
  circle(buff, 580, 170, 100, CORAMARELO);
  circle(buff, 580, 170, 80, CORAMARELO);
  circle(buff, 180, 170, 100, CORBRANCO);
  circle(buff, 380, 600, 100, CORAMARELO);
  circle(buff, 380, 600, 80, CORAMARELO);

  /* Cria setas e infomacoes na imagem */
  textprintf_ex(buff, font, 570, 150, CORVERDE, CORPRETO, "Q1");
  textprintf_ex(buff, font, 180, 150, CORVERDE, CORPRETO, "Q0");
  textprintf_ex(buff, font, 380, 600, CORVERDE, CORPRETO, "Q2");
  textprintf_ex(buff, font, 70, 150, CORVERDE, CORPRETO, ">");
  textprintf_ex(buff, font, 60, 150, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 50, 150, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 40, 150, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 40, 140, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 40, 130, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 40, 120, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 40, 110, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 40, 100, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 330, 150, CORVERDE, CORPRETO, "------------->");
  textprintf_ex(buff, font, 375, 130, CORVERDE, CORPRETO, "A");
  textprintf_ex(buff, font, 375, 730, CORVERDE, CORPRETO, "B");
  textprintf_ex(buff, font, 180, 375, CORVERDE, CORPRETO, "B");
  textprintf_ex(buff, font, 570, 375, CORVERDE, CORPRETO, "B");
  textprintf_ex(buff, font, 610, 60, CORVERDE, CORPRETO, "A,B");

   textprintf_ex(buff, font, 360, 750, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 360, 760, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 360, 770, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 360, 780, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 370, 780, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 380, 780, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 390, 780, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 390, 770, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 390, 760, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 390, 750, CORVERDE, CORPRETO, "|");

  textprintf_ex(buff, font, 170, 290, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 300, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 310, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 320, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 330, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 340, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 350, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 360, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 370, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 380, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 390, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 400, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 410, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 420, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 430, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 440, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 450, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 460, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 470, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 480, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 490, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 500, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 510, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 520, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 530, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 540, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 550, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 180, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 190, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 200, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 210, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 220, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 230, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 240, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 250, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 260, 550, CORVERDE, CORPRETO, ">");
  textprintf_ex(buff, font, 520, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 530, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 540, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 550, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 560, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 570, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 580, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 580, 540, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 530, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 520, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 510, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 500, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 490, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 480, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 470, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 460, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 450, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 440, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 430, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 420, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 410, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 400, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 390, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 380, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 370, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 360, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 350, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 340, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 330, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 320, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 310, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 300, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 290, CORVERDE, CORPRETO, "ˆ");

  textprintf_ex(buff, font, 580, 50, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 40, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 30, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 590, 30, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 600, 30, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 600, 40, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 600, 50, CORVERDE, CORPRETO, "|");


  textprintf_ex(buff, font, 680, 55, CORVERDE, CORPRETO, "Entrada: A,B");
  textprintf_ex(buff, font, 680, 70, CORVERDE, CORPRETO, "Inicial: Q0");
  textprintf_ex(buff, font, 680, 85, CORVERDE, CORPRETO, "Final: Q1 ou Q2");

  save_bitmap(IMAGENAMEAFD01, buff, pal); // salva imagem

  destroy_bitmap(buff); // destroi

  allegro_exit(); // finaliza allegro

  return;
}

/* ---------------------------------------------------------------------- */

/**< Cria imagem AFND da entrada 01 */
void imagemAFND_01(void)
{
  BITMAP *buff;
  PALETTE pal;

  if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
    exit(EXIT_FAILURE);

  set_color_depth(16);
  get_palette(pal);

  // Cria buffer para animacao
  buff = create_bitmap(800,800);

  if(buff == NULL)
  {
    printf("Nao foi possivel criar buffer!\n");
    exit(EXIT_FAILURE);
  }

  /* cria circulos */
  circle(buff, 580, 170, 100, CORAMARELO);
  circle(buff, 580, 170, 80, CORAMARELO);
  circle(buff, 180, 170, 100, CORBRANCO);
  circle(buff, 380, 600, 100, CORBRANCO);

  /* cria setas e informacoes na imagem */
  textprintf_ex(buff, font, 570, 150, CORVERDE, CORPRETO, "Q1");
  textprintf_ex(buff, font, 180, 150, CORVERDE, CORPRETO, "Q0");
  textprintf_ex(buff, font, 70, 150, CORVERDE, CORPRETO, ">");
  textprintf_ex(buff, font, 60, 150, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 50, 150, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 40, 150, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 40, 140, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 40, 130, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 40, 120, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 40, 110, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 40, 100, CORVERDE, CORPRETO, "|");
  
  textprintf_ex(buff, font, 330, 150, CORVERDE, CORPRETO, "------------->");
  textprintf_ex(buff, font, 380, 600, CORVERDE, CORPRETO, "Q2");
  
  textprintf_ex(buff, font, 375, 130, CORVERDE, CORPRETO, "A");
  textprintf_ex(buff, font, 375, 730, CORVERDE, CORPRETO, "B");
  textprintf_ex(buff, font, 360, 750, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 360, 760, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 360, 770, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 360, 780, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 370, 780, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 380, 780, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 390, 780, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 390, 770, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 390, 760, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 390, 750, CORVERDE, CORPRETO, "|");
  
  textprintf_ex(buff, font, 170, 290, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 300, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 310, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 320, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 330, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 340, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 350, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 360, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 370, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 380, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 390, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 400, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 410, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 420, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 430, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 440, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 450, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 460, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 470, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 480, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 490, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 500, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 510, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 520, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 530, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 540, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 170, 550, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 180, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 190, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 200, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 210, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 220, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 230, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 240, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 250, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 260, 550, CORVERDE, CORPRETO, ">");
  textprintf_ex(buff, font, 520, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 530, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 540, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 550, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 560, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 570, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 580, 550, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 580, 540, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 530, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 520, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 510, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 500, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 490, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 480, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 470, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 460, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 450, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 440, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 430, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 420, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 410, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 400, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 390, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 380, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 370, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 360, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 350, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 340, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 330, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 320, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 310, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 300, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 290, CORVERDE, CORPRETO, "ˆ");

  textprintf_ex(buff, font, 570, 375, CORVERDE, CORPRETO, "E");
  textprintf_ex(buff, font, 180, 375, CORVERDE, CORPRETO, "B");
  textprintf_ex(buff, font, 610, 60, CORVERDE, CORPRETO, "A,B");
  textprintf_ex(buff, font, 580, 50, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 40, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 580, 30, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 590, 30, CORVERDE, CORPRETO, "-");
  textprintf_ex(buff, font, 600, 30, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 600, 40, CORVERDE, CORPRETO, "|");
  textprintf_ex(buff, font, 600, 50, CORVERDE, CORPRETO, "|");
  
  textprintf_ex(buff, font, 680, 55, CORVERDE, CORPRETO, "Entrada: A,B");
  textprintf_ex(buff, font, 680, 70, CORVERDE, CORPRETO, "Inicial: Q0");
  textprintf_ex(buff, font, 680, 85, CORVERDE, CORPRETO, "Final: Q1");


  save_bitmap(IMAGENAMEAFND01, buff, pal); // salva imagem

  destroy_bitmap(buff); // destroi 

  allegro_exit(); // finaliza allegro

  return;
}

/* ---------------------------------------------------------------------- */

/**< Cria imagem AFND da entrada 02 */
void imagemAFND_02(void)
{
    BITMAP *buff;
    PALETTE pal;

    if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
        exit(EXIT_FAILURE);

    set_color_depth(16);
    get_palette(pal);

    // Cria buffer para animacao.
    buff = create_bitmap(800,800);
   
    if(buff == NULL)
    {
        printf("Nao foi possivel criar buffer!\n");
        exit(EXIT_FAILURE);
    }
  
    circle(buff, 580, 170, 100, CORBRANCO);
    circle(buff, 580, 450, 100, CORAMARELO);
    circle(buff, 580, 450, 80, CORAMARELO);
    circle(buff, 180, 170, 100, CORAMARELO);
    circle(buff, 180, 170, 80, CORAMARELO);
    circle(buff, 180, 450, 100, CORBRANCO);
  
    textprintf_ex(buff, font, 570, 150, CORVERDE, CORPRETO, "0");
    textprintf_ex(buff, font, 570, 450, CORVERDE, CORPRETO, "1");
    textprintf_ex(buff, font, 180, 150, CORVERDE, CORPRETO, "3");
    textprintf_ex(buff, font, 180, 450, CORVERDE, CORPRETO, "2");
    textprintf_ex(buff, font, 130, 50, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 130, 40, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 130, 30, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 140, 30, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 150, 30, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 150, 20, CORVERDE, CORPRETO, "C");
    textprintf_ex(buff, font, 160, 30, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 160, 50, CORVERDE, CORPRETO, "V");
    textprintf_ex(buff, font, 160, 40, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 30, CORVERDE, CORPRETO, "|");
  
    textprintf_ex(buff, font, 40, 100, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 40, 110, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 40, 120, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 40, 130, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 50, 130, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 60, 130, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 70, 130, CORVERDE, CORPRETO, ">");
  
    textprintf_ex(buff, font, 330, 150, CORVERDE, CORPRETO, "------------->");
    textprintf_ex(buff, font, 330, 450, CORVERDE, CORPRETO, "<-------------");
    textprintf_ex(buff, font, 330, 480, CORVERDE, CORPRETO, "------------->");
  
    textprintf_ex(buff, font, 375, 130, CORVERDE, CORPRETO, "A");
    textprintf_ex(buff, font, 375, 330, CORVERDE, CORPRETO, "E"); 
    textprintf_ex(buff, font, 375, 425, CORVERDE, CORPRETO, "E");
    textprintf_ex(buff, font, 375, 500, CORVERDE, CORPRETO, "A");
  
    textprintf_ex(buff, font, 300, 370, CORVERDE, CORPRETO, "<");
    textprintf_ex(buff, font, 310, 370, CORVERDE, CORPRETO, "<");
    textprintf_ex(buff, font, 320, 360, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 330, 350, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 340, 340, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 350, 330, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 360, 320, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 370, 310, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 380, 300, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 390, 290, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 400, 280, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 410, 270, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 420, 260, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 430, 250, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 440, 240, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 450, 230, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 460, 220, CORVERDE, CORPRETO, "/");
  
    textprintf_ex(buff, font, 180, 300, CORVERDE, CORPRETO, "C");
    textprintf_ex(buff, font, 160, 340, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 330, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 320, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 310, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 300, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 290, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 280, CORVERDE, CORPRETO, "ˆ");
  
    textprintf_ex(buff, font, 570, 300, CORVERDE, CORPRETO, "B");
    textprintf_ex(buff, font, 550, 340, CORVERDE, CORPRETO, "V");
    textprintf_ex(buff, font, 550, 330, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 320, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 310, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 300, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 290, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 280, CORVERDE, CORPRETO, "|");

    textprintf_ex(buff, font, 550, 50, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 40, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 30, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 560, 30, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 570, 30, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 570, 20, CORVERDE, CORPRETO, "A");
    textprintf_ex(buff, font, 570, 30, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 580, 30, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 580, 40, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 580, 50, CORVERDE, CORPRETO, "V");

    textprintf_ex(buff, font, 550, 560, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 570, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 580, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 560, 580, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 570, 580, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 560, 590, CORVERDE, CORPRETO, "A,B");
    textprintf_ex(buff, font, 580, 580, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 580, 570, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 580, 560, CORVERDE, CORPRETO, "ˆ");

    textprintf_ex(buff, font, 130, 560, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 130, 570, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 130, 580, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 140, 580, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 150, 580, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 150, 590, CORVERDE, CORPRETO, "B");
    textprintf_ex(buff, font, 160, 580, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 160, 570, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 560, CORVERDE, CORPRETO, "ˆ");

    save_bitmap(IMAGENAMEAFND02, buff, pal);

    destroy_bitmap(buff);
  
    allegro_exit(); /* finaliza allegro */
  
    return;
}

/* ---------------------------------------------------------------------- */

/**< Cria imagem AFD da entrada 02 */
void imagemAFD_02(void)
{

    BITMAP *buff;
    PALETTE pal;

    if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
        exit(EXIT_FAILURE);

    set_color_depth(16);
    get_palette(pal);

    // Cria buffer para animacao.
    buff = create_bitmap(800,800);
   
    if(buff == NULL)
    {
        printf("Nao foi possivel criar buffer!\n");
        exit(EXIT_FAILURE);
    }
    
    /* cria circulos e representacao do AFD */
    circle(buff, 580, 170, 100, CORBRANCO);
    circle(buff, 180, 170, 100, CORBRANCO);
    circle(buff, 580, 450, 100, CORAMARELO);
    circle(buff, 580, 450, 80, CORAMARELO); 
    circle(buff, 180, 450, 100, CORAMARELO);
    circle(buff, 180, 450, 80, CORAMARELO); 
  
    textprintf_ex(buff, font, 570, 150, CORVERDE, CORPRETO, "1");
    textprintf_ex(buff, font, 570, 450, CORVERDE, CORPRETO, "2");
    textprintf_ex(buff, font, 180, 150, CORVERDE, CORPRETO, "0");
    textprintf_ex(buff, font, 180, 450, CORVERDE, CORPRETO, "3");
    textprintf_ex(buff, font, 130, 50, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 130, 40, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 130, 30, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 140, 30, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 150, 30, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 150, 20, CORVERDE, CORPRETO, "C");
    textprintf_ex(buff, font, 160, 30, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 160, 50, CORVERDE, CORPRETO, "V");
    textprintf_ex(buff, font, 160, 40, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 30, CORVERDE, CORPRETO, "|");
  
    textprintf_ex(buff, font, 40, 100, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 40, 110, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 40, 120, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 40, 130, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 50, 130, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 60, 130, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 70, 130, CORVERDE, CORPRETO, ">");
  
    textprintf_ex(buff, font, 330, 150, CORVERDE, CORPRETO, "------------->");
    textprintf_ex(buff, font, 330, 450, CORVERDE, CORPRETO, "<-------------");
    textprintf_ex(buff, font, 330, 180, CORVERDE, CORPRETO, "<-------------");
    textprintf_ex(buff, font, 300, 240, CORVERDE, CORPRETO, "<<-------");
    textprintf_ex(buff, font, 370, 240, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 250, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 260, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 270, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 280, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 290, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 300, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 310, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 320, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 330, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 340, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 350, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 360, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 370, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 380, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 370, 390, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 380, 390, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 390, 390, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 400, 390, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 410, 390, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 420, 390, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 430, 390, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 440, 390, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 450, 390, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 460, 390, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 470, 390, CORVERDE, CORPRETO, "-");
  
    textprintf_ex(buff, font, 470, 370, CORVERDE, CORPRETO, "C");
    textprintf_ex(buff, font, 470, 250, CORVERDE, CORPRETO, "B");

    textprintf_ex(buff, font, 375, 130, CORVERDE, CORPRETO, "A");
    textprintf_ex(buff, font, 375, 430, CORVERDE, CORPRETO, "B");
    textprintf_ex(buff, font, 375, 200, CORVERDE, CORPRETO, "C");
  
    textprintf_ex(buff, font, 300, 370, CORVERDE, CORPRETO, "<");
  
    textprintf_ex(buff, font, 310, 370, CORVERDE, CORPRETO, "<");
    textprintf_ex(buff, font, 320, 360, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 330, 350, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 340, 340, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 350, 330, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 360, 320, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 370, 310, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 380, 300, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 390, 290, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 400, 280, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 410, 270, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 420, 260, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 430, 250, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 440, 240, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 450, 230, CORVERDE, CORPRETO, "/");
    textprintf_ex(buff, font, 460, 220, CORVERDE, CORPRETO, "/");
  
    textprintf_ex(buff, font, 180, 300, CORVERDE, CORPRETO, "C");
    textprintf_ex(buff, font, 160, 340, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 330, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 320, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 310, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 300, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 290, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 280, CORVERDE, CORPRETO, "ˆ");
  
    textprintf_ex(buff, font, 570, 300, CORVERDE, CORPRETO, "A");
    textprintf_ex(buff, font, 550, 340, CORVERDE, CORPRETO, "V");
    textprintf_ex(buff, font, 550, 330, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 320, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 310, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 300, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 290, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 280, CORVERDE, CORPRETO, "|");

    textprintf_ex(buff, font, 550, 560, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 570, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 550, 580, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 560, 580, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 570, 580, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 560, 590, CORVERDE, CORPRETO, "A");
    textprintf_ex(buff, font, 580, 580, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 580, 570, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 580, 560, CORVERDE, CORPRETO, "ˆ");

    textprintf_ex(buff, font, 130, 560, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 130, 570, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 130, 580, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 140, 580, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 150, 580, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 150, 590, CORVERDE, CORPRETO, "A,B");
    textprintf_ex(buff, font, 160, 580, CORVERDE, CORPRETO, "-");
    textprintf_ex(buff, font, 160, 570, CORVERDE, CORPRETO, "|");
    textprintf_ex(buff, font, 160, 560, CORVERDE, CORPRETO, "ˆ");

    save_bitmap(IMAGENAMEAFD02, buff, pal); /* salva imagem */

    destroy_bitmap(buff); /* destroi */
  
    allegro_exit(); /* finaliza allegro */

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
    printf("%s - %s\n", "automax.c", "Converte AFND, AFD e ER");
    printf("\nUso: %s [-h|-v]\n", "automax");
    printf("\nObrigatorio: -n, -d ou -e\n");
    printf("\nOpcoes:\n");
    printf("\t-h,  --help\n\t\tMostra esta janela\n");
    printf("\t-c,  --copyright, --version\n\t\tMotra versao e copyright.\n");
    printf("\t-v,  --verbose\n\t\tNivel de verbose (cumulativo).\n");
    printf("\t-f, --arquivo\n\t\tEntrada de dados por meio de um arquivo.\n");
    printf("\t-n, --AFND\n\t\tA entrada de dados eh um AFND(Automato Finito Nao-Deterministico) a ser convertido para um AFD(Automato Finito Deterministico), use $cat entrada.txt | ./auto1.x -n\n");
    printf("\t-d, --AFD\n\t\tA entrada de dados eh um AFD(Automato Finito Deterministico) a ser convertido para um ER (Expressao Regular), use $cat entrada.txt | ./automax.x -d\n");
    printf("\t-e, --ER\n\t\tA entrada de dados eh um ER (Expressao Regular) a ser convertido para um AFND (Automato Finito Nao-Deterministico), use $cat entrada.txt | ./automax.x -e\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n", "Ruben Carlo Benante", "rcb@beco.cc");
    printf("                     Christopher Coutinho De Lucena Melo\n");
    printf("                     Davi Austregesilo Nepomuceno\n");
    printf("                     Jose Eduardo Oliveira Cavalcanti Lupa\n");
    printf("                     Rodolfo Prazim De Oliveira Barros\n");
    printf("                     Maria Cecilia Galvao Da Silva Jota\n");
    printf("                     Bruno Schwamborn\n");
    printf("                     Lara Vitoria Morais Nogueira\n\n");
    
    
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
    printf("%s - Version %s\n", "automax", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */

