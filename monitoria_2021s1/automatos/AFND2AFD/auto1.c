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
  *
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

/* ---------------------------------------------------------------------- */

int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    int convert = 0; /* controle do tipo de conversao */
    int entrada = 1; /* variavel de controle de tipo de entrada 0 - para arquivo e 1 - para entrada manual */
    int r, s = 0; /* variaveis para controle do allegro do AFND 2 AFD */
    
    char name_file[SBUFF]; /* variavel para receber optarg da flag -f */
    char entrada1[SBUFF] = "01-teste-AFND.txt"; /* nome de arquivo teste disponivel */
    char entrada2[SBUFF] = "02-teste-AFND.txt"; /* nome de arquivo teste disponivel */
    
    FILE *file; /* arquivo para entrada da optarg */
    
    t_quintupla *afnd = NULL;
    t_quintupla *afd = NULL;

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright and version
     *        -v  verbose
     *        -f  given file name
     *        -n  AFND->AFD conversion
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
                convert = 1; /* conversao vai ser do tipo AFND -> AFD */
                break;
            case 'v':
                verb++;
                break;
            case 'f':
                strncpy(name_file, optarg, SBUFF); /* recebe o nome de um arquivo com maximo de tamanho de SBUFF (256) */
                entrada = 0; /* entrada 0 representa entrada por arquivo */
                break;
            case '?':
                help();
            default:
                help();
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                
                return EXIT_FAILURE;
        }
    
    /* ---------------------------------------------- */
    /* ------------------Verbose--------------------- */
    if(verb)
        printf("Verbose level set at: %d\n", verb);
    
    /* ---------------------------------------------- */
    /* ----------------Entrada de dados-------------- */
    if(entrada) /* entrada */
    {
        if(convert == 1 || convert == 2)    /* convert 1 e 2 */
            m_recebe_afnd(&afnd);           /* entrada de uma quintupla */
    }
    else /* entrada por arquivo */
    {
        file = fopen(name_file,"r"); // abre arquivo para leitura
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
    //IFDEBUG("recebe_afnd()");
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
    //IFDEBUG("print_quintupla()");
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
    //IFDEBUG("calcular_novos_finais()");
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
    //IFDEBUG("calcular_estado()");
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
    //IFDEBUG("calcular_epsilon()");
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
    //IFDEBUG("novo_delta()");
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
    //IFDEBUG("calcular_list_lef()");
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
    //IFDEBUG("montar_afd()");
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
    //IFDEBUG("ord_novo()");
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
    //IFDEBUG("delta_existe()");
    t_delta *delta = q->D;
    while(delta != NULL) /* enquanto delta nao for NULL */
    {
        if(delta->ei == num && (strstr(delta->le,test))) /* se existe a trasicao com o num e test dado retorna 1 */
            return 1;
        delta = delta->prox;
    }
    
    return 0; /* se nao achar transicao retorna 0 */
}

/* ---------------------------------------------------------------------- */
/**< confere se duas listas t_lef tem os mesmo valores */
int buscar(t_lef *est , t_lef *est2)
{
    //IFDEBUG("buscar()");
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
    //IFDEBUG("buscar_list()");
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
    //IFDEBUG("juntar_lef_list()");
    while(est != NULL) /* quanto est nao for NULL */
    {
        if(buscar_list(est->F,(*est2)) == 0) /* se nao existe na lista principal */
            inserir_list_final(est->F,est2); /* adiciona na lista est2 */
        est = est->prox;
    }
    
    return;
}

/* ---------------------------------------------------------------------- */
/**< remvove um t_lef de uma t_list_lef */
void remover_list_final(t_lef *est , t_list_lef **cabeca)
{
    //IFDEBUG("remover_list_final()");
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
    //IFDEBUG("inserir_list_final()");
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
    //IFDEBUG("inserir_final()");
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
    //IFDEBUG("inserir_delta()");
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
    //IFDEBUG("inserir_final_st()");
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
    //IFDEBUG("inserir_delta_st()");
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
    //printf("Nao foi possivel criar buffer!\n");
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
  textprintf_ex(buff, font, 570, 375, CORVERDE, CORPRETO, "A");
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
    //printf("Nao foi possivel criar buffer!\n");
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
   //     printf("Nao foi possivel criar buffer!\n");
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
    printf("%s - %s\n", "auto1.c", "Converte AFND para AFD");
    printf("\nUso: %s [-h|-v]\n", "auto1");
    printf("\nObrigatorio: -n\n");
    printf("\nOpcoes:\n");
    printf("\t-h,  --help\n\t\tMostra esta janela\n");
    printf("\t-c,  --copyright, --version\n\t\tMotra versao e copyright.\n");
    printf("\t-v,  --verbose\n\t\tNivel de verbose (cumulativo).\n");
    printf("\t-f, --arquivo\n\t\tEntrada de dados por meio de um arquivo.\n");
    printf("\t-n, --AFND\n\t\tA entrada de dados eh um AFND(Automato Finido Nao-Deterministico) a ser convertido para um AFD(Automato Finito Deterministico), use $cat entrada.txt | ./auto1.x -n\n");
    printf("\nAuthors:\n\tWritten by %s <%s>\n", "Ruben Carlo Benante","rcb@beco.cc");
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
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "auto1", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */

