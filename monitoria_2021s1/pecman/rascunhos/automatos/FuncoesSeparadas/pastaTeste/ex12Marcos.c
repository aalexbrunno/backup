/***************************************************************************
 *   ex12.c                                 Version 20171128.121000      *
 *                                                                         *
 *   Convert AFD into Exp Reg                                              *
 *   Copyright (C) 2016-2017    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.                *
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
 * @file ex12.c
 * @ingroup GroupUnique
 * @brief Convert AFD into Exp Reg
 * @details This program really do a nice job as a template, and template only!
 * @version 20160520.000202
 * @date 2017-11-28
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
 *   $gcc ex12.c -o ex12.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include "ex12Marcos.h" /* library with definitions */

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <assert.h> */ /* Verify assumptions with assert */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* OBSERVACOES DE ERROS/BUGS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!laksdlasldkasdlsaklk!!!!!!!!!!!!!!*/
/* ---------------------------------------------------------------------- 
 * OBS: 2 ERROS: . O VALOR LIXO 65555 QUE APARECE NAO SEI DE ONDE!
 *               . ELE TA ELIMINANDO OS ZEROS DA TRANCISAO DE UMA VEZ!
 * ---------------------------------------------------------------------- */
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
 *    $./ex12 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
int main(int argc, char *argv[])
{
  int opt; /* return from getopt() */

  opterr = 0;
  while((opt = getopt(argc, argv, "vhcf:")) != EOF)
    switch(opt)
    {
      case 'f':
        le_arquivo(optarg);
        break;
      case 'h':
        help();
        break;
      case 'c':
        copyr();
        break;
      case 'v':
        verb++;
        break;
      case '?':
      default:
        printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

  if(verb)
    printf("Verbose level set at: %d\n", verb);

  return EXIT_SUCCESS;
}
void le_arquivo(char *optarg)
{
  arquivo_fonte *basico = NULL;
  FILE *respostas;                /* abre o arquivo texto */
  char *arq;                      /* ponteiro para chamar a strtok */
  char resp[SBUFF];               /* vetor para guardar oq vier do arquivo texto */
  // char *tokens[SBUFF];            /* vetor para guardar os tokens da strtok */
  int n,c = 0;
  /* contador para regular a posicao do vetor tokens */

  respostas = fopen(optarg, "r"); /* !!!!! OPTARG POIS, ELE PODE LÊ QUALQUER ARQUIVO DITO PELO USUARIO !!!!!*/
  /* processo de abertura e armazenamento do conteudo do arquivo texto */
  if(respostas == NULL)
  {
    printf("Erro ao abrir o arquivo\n");
    return;
  }
  n = fread(resp,1,sizeof(resp) - 1,respostas);
  resp[n] = '\0';
  arq = strtok(resp,"\n");
  while(arq != NULL)
  {
    //             tokens[c] = arq;
    insere_linhas(&basico,arq);
    //       printf(" %s\n",tokens[c]);
    arq = strtok(NULL,"\n");
    c++;
  }
  entende_automato(basico);
  free(basico);
}
void entende_automato(arquivo_fonte *basico)
{
  char *estados_finais[SBUFF];
  char *transicoes_caract[SBUFF];
  int tamanho_finais;

  t_lef *finais = NULL; 
  t_lft *transicao = NULL;
  t_lft *auxiliar = NULL;

  arquivo_fonte *pl = basico;
  t_quintupla dados;

  if(strcmp(pl->linhas,"#K") == 0)
  {
    pl = pl -> prox;
    dados.K = atoi(pl -> linhas);
    pl = pl -> prox;
  }
  if(strcmp(pl->linhas,"#A") == 0)
  {
    pl = pl ->prox;
    dados.A = *pl -> linhas;
    pl = pl -> prox;
  }
  /*
     total_retornado = retorna_contador_e_alfabeto(pl -> linhas,alfabeto);
     for(quant_letras = 0;quant_letras <= total_retornado;quant_letras++)
     inserir_alfabeto(&dados,alfabeto[quant_letras]);  */
  if(strcmp(pl -> linhas,"#S") == 0)
  {
    pl = pl -> prox;
    if((atoi(pl -> linhas) >= 0) &&( atoi(pl -> linhas) < dados.K))
    {
      dados.S = atoi(pl -> linhas);
      pl = pl -> prox;
    }
    else
      printf("\nOps!Algo de errado aconteceu com o seu estado inicial, verifique se ele está >= 0 e < K\n");
  }
  if(strcmp(pl->linhas,"#F") == 0)
  {
    pl = pl -> prox;
    tamanho_finais = retorna_estados_finais(estados_finais,pl -> linhas);
    for(int i =0;i < tamanho_finais;i++)
      insere_finais(&finais,atoi(estados_finais[i]));
    pl = pl -> prox;
  }
  if(strcmp(pl -> linhas,"#D") == 0)
  {
    pl = pl -> prox;
    while(pl != NULL)
    {
      tamanho_finais = retorna_estados_finais(transicoes_caract,pl -> linhas);
      insere_transicoes(&transicao,atoi(transicoes_caract[0]),transicoes_caract[1],atoi(transicoes_caract[2]));
      insere_transicoes(&auxiliar,atoi(transicoes_caract[0]),transicoes_caract[1],atoi(transicoes_caract[2]));
      pl = pl -> prox;
    }
  }
  roda_as_buscas(transicao,auxiliar,finais,dados);
  //funcao de debug para a transicao -> imprimir_transicoes(transicao);
}
void roda_as_buscas(t_lft *transicoes,t_lft *auxiliar,t_lef *finais,t_quintupla dados)
{
  int tamanho = 0,menor_estado = 0,pos_do_inicial = 0,pos_do_final = 0;
  char *caractere,*expressao;
  int comeca = 0;

  t_quintupla novos_estados = dados;
  t_lft *novas_transicoes = transicoes;
  /* criacao do novo automato com os 2 estados novos de base, e a transicao ja alterada e com final/inicial alterados */
  tamanho = criar_novas_transicoes(&novas_transicoes,&novos_estados,finais);
  insere_finais(&finais,tamanho);
  identifica_quem_precisa_kline(&novas_transicoes);

  /* procurando qual(s) estado(s) tem menos iteracoes para poder comecar por ele... 
   * Passando para a funcao: novas_transicoes = pra ele procurar ja com a transicao att
   * novos_estados = pra ele ver quem eh o novo estado inicial e ignora-lo
   * dados = pra ele ver quem eh o antigo estado inicial e ignora-lo 
   * Caso nao tem mais nenhum alem desses estados inicais, ai nao os ignora*/
  int i =0;
  while(1)// !unicos_estados_sejam_os_dois_novos(novas_transicoes))
  {
    if(todos_os_inicias_um_tipo_de_numero(novas_transicoes) || todos_os_inicias_2_tipos_sendo_um_o_novo(novas_transicoes))
    {
     // imprimir_transicoes(novas_transicoes);
      junta_expressao(&expressao,novas_transicoes);
      break;
    }
    menor_estado = retorna_o_menor_estado(novas_transicoes,novos_estados);
    /* if(first_time != 1)
       {
       if(menor_estado != menor_anterior)
       {
       contador_anterior = 0;
       elimina_tudo_desse_estado(&novas_transicoes,menor_estado);
       menor_anterior = menor_estado;
       first_time = 1;
       }
       }
       first_time = 0;
       if(contador_anterior == 0)
       menor_anterior = menor_estado;
       contador_anterior++; */


//    printf("menor_estado = %d\n",menor_estado);

    // enquanto nao acabarem os 1 como iniciais...


    while(checagem_final_se_tem_transicao_solta(&novas_transicoes,menor_estado,pos_do_final))
    {
     // imprimir_transicoes(novas_transicoes);
     
      /* realizando as devias buscas */
      pos_do_final = buscar_quando_ele_eh_final_e_retorna_posicao(menor_estado,novas_transicoes);
     // printf("pos_do_final = %d\n",pos_do_final);

      //  na funcao buscar_quando_ele_eh_final, caso nao ache quando o q1 seja final, eliminar o atual inicial: 
      /*  if(pos_do_final == -1) 
          {
          elimina_onde_eh_final(&novas_transicoes,pos_do_final);
          continue;
          }*/
      pos_do_inicial = buscar_quando_ele_eh_inicial_e_retorna_posicao(menor_estado,novas_transicoes);
     // printf("pos_do_inicial = %d\n",pos_do_inicial);

      junta_strings(&caractere,pos_do_final,pos_do_inicial,novas_transicoes);
      //      printf("caractere = %s\n",caractere);

      //     elimina_onde_eh_final(&novas_transicoes,pos_do_final);

      faz_a_nova_transicao(&novas_transicoes,auxiliar,caractere,pos_do_inicial,pos_do_final);

      elimina_onde_eh_inicial(&novas_transicoes,pos_do_inicial);
      comeca = 1;
      //  printf("*****\n");
      //  imprimir_transicoes(novas_transicoes);
      // printf("*****\n");
      //checagem_final_se_tem_transicao_solta(&novas_transicoes,tamanho);

      //imprimir_transicoes(novas_transicoes);

      i++;
    }
    comeca = 0;
  }
  anda_para_colocar_o_OU(auxiliar,expressao);
  free(novas_transicoes);
  free(finais);
  /* Criar 2 novos q para se basear
   *
   * Selecionar os que tem menos iteracoes para elimina-los
   *
   * Rodar duas buscas => pegar um dos estados escolhidos para elimiancao(acima) e achar uma transicao 
   * na qual este estado seja estado final, apos isso, achar uma transicao na qual esse estado seja o inicial,
   * ai so fazer a juncao desses alfabetos, ex: q0 b q1 q1 a q2  , q0 b.a q2
   */
  // }
  }
void anda_para_colocar_o_OU(t_lft *auxiliar,char *expressao)
{
  /*
   * Pega o primeir elemento da expressao.
   * Por onde ele passar coloca o le como 
   * conseguiu terminar? se sim ele recebe |
   * se nao eu mudo pra outro caractere
   * 
   */
}
int todos_os_inicias_2_tipos_sendo_um_o_novo(t_lft *cabeca)
{
  t_lft *pl = cabeca;
  int auxiliar,auxiliar2 = -1;
  int contador_1 = 0,contador_2 = 0;

  auxiliar = pl -> ei;
  while(pl != NULL)
  {
    if(pl -> ei != auxiliar && pl -> ei != auxiliar2)
    {
      contador_1++;
      auxiliar2 = pl -> ei;
    }
    pl = pl -> prox;
  }
  if(contador_1 == 1)
    return 1;
  else
    return 0;
}
void identifica_quem_precisa_kline(t_lft **cabeca)
{
  t_lft *busca = *cabeca;
  t_lft *plant = NULL;
  int contador = 0;

  while(busca != NULL)
  {
    if(busca -> ei == busca -> ef)
      coloca_kline(&busca,contador);

    contador++;
    plant = busca;
    busca = busca -> prox;
  }
  if(plant != NULL)
    plant -> prox = busca;
  else
    *cabeca = busca;
}
void coloca_kline(t_lft **cabeca,int contador)
{
  int i = 0 ;
  char carac[SBUFF];
  t_lft *pl = *cabeca;

  strcpy(carac,pl -> le);
  strcat(carac,"*");
  pl -> le = strdup(carac);
//  printf(" %s\n",pl -> le);
  *cabeca = pl; 
}
void junta_expressao(char **expressao,t_lft *cabeca)
{
  t_lft *pl = cabeca;
  t_lft *pl1 = cabeca;
  char posterior[SBUFF];
  char total[SBUFF];
  char total_sem_E[SBUFF];
  unsigned int i,j = 0,c;
  int compara = 0,contador = 0,pos;
  int primeira_vez = 1;

  int auxiliar = pl -> ei;
  while(pl != NULL)
  {
    if(compara == 1 || pl->ei != auxiliar)
    {
      if(primeira_vez)
      {
        primeira_vez = 0;
        pos = contador;
      }
      compara = 1;
      strcpy(posterior,pl -> le);
      strcat(total,posterior);
  //    printf(" %s\n",total);
      break;
    }
    contador++;
    pl = pl -> prox;
  }
  contador = 0;
  while(pl1 != NULL)//&& contador < pos)
  {
    if(contador != pos)
    {
      strcpy(posterior,pl1 -> le);
      strcat(total,posterior);
    }
    contador++;
    pl1 = pl1 -> prox;
  }
      /*
         strcpy(total,pl -> le);
         pl = pl -> prox;
         while(pl != NULL)
         { 
         strcpy(posterior,pl -> le);
         strcat(total,posterior);
         pl = pl -> prox;
         } */  
      // eliminando o E 
      for(i = 0;i < strlen(total);i++)
      {
        if(total[i] != 'E')
        {
          total_sem_E[j] = total[i];
          j++;
        }
      }
      // invertendo elementos
      *expressao = total_sem_E;
      printf(" expressao = %s\n",*expressao);
      return;  
}
int todos_os_inicias_um_tipo_de_numero(t_lft *cabeca)
{
  t_lft *pl = cabeca;
  int auxiliar;
  int contador_1 = 0,contador_2 = 0;

  auxiliar = pl -> ei;
  while(pl != NULL)
  {
    if(pl -> ei == auxiliar)
      contador_1++;
    contador_2++;
    pl = pl -> prox;
  }
  if(contador_1 == contador_2)
    return 1;
  else
    return 0;
}
int checagem_final_se_tem_transicao_solta(t_lft **cabeca,int menor_estado,int pos_do_final)
{
  t_lft *pl = *cabeca;
  t_lft *pl2 = *cabeca;
  t_lft *plant = NULL;
  int contador = 0,auxiliar = 0;

  //  imprimir_transicoes(pl);
  while(pl != NULL && auxiliar != 1)
  {
    if(!se_esse_ef_esta_como_ei(pl,menor_estado))
    {
      if(pl -> ef == menor_estado)
        break;


      //  auxiliar = 1;

      // teste = pl;
      /*
         if(plant != NULL) // tem anterior 
         plant -> prox = pl -> prox;
         else //eliminando cabeca 
       *cabeca = pl->prox;*/


    }
    else
      contador++;

    plant = pl;
    pl = pl -> prox;
  }
  if(contador == 0)
  {
    if(plant != NULL) // tem anterior 
    {
      plant -> prox = pl -> prox;
    }
    else //eliminando cabeca 
      *cabeca = pl->prox;
    free(pl);
    return 0;
  }
  else
    return 1;
}
int se_esse_ef_esta_como_ei(t_lft *cabeca,int x)
{
  t_lft *pl = cabeca;
  while(pl != NULL)
  {
    //    printf(" linha 396 = %d\n",pl -> ei);
    if(pl -> ei == x)
      return 1;
    pl = pl -> prox;
  }
  return 0;    
}
void elimina_tudo_desse_estado(t_lft **cabeca,int menor_estado)
{
  t_lft *pl = *cabeca;
  t_lft *plant = NULL;

  while(pl != NULL && pl -> ei != menor_estado)  
  {
    plant = pl;
    // printf(" teste = %d\n",pl -> ei);
    pl = pl -> prox;
  }
  if(pl == NULL)// nao achou ou lista vazia 
    return;
  if(plant != NULL) // tem anterior 
    plant -> prox = pl -> prox;
  else //eliminando cabeca 
    *cabeca = pl->prox;
  free(pl);
  return;
}
void elimina_onde_eh_final(t_lft **cabeca,int pos_do_final)
{
  t_lft *pl = *cabeca;
  t_lft *plant = NULL;
  int contador = 0;

  while(pl != NULL && contador != pos_do_final)  
  {
    plant = pl;
    //    printf(" teste = %d\n",pl -> ei);
    contador++;
    pl = pl -> prox;
  }
  if(pl == NULL)// nao achou ou lista vazia 
    return;
  if(plant != NULL) // tem anterior 
    plant -> prox = pl -> prox;
  else //eliminando cabeca 
    *cabeca = pl->prox;
  free(pl);
  return;
}
void elimina_onde_eh_inicial(t_lft **cabeca,int pos_do_inicial)
{
  t_lft *pl = *cabeca;
  t_lft *plant = NULL;
  int contador = 0;

  while(pl != NULL && contador != pos_do_inicial)  
  {
    plant = pl;
    //  printf(" teste = %d\n",pl -> ei);
    contador++;
    pl = pl -> prox;
  }
  if(pl == NULL)// nao achou ou lista vazia 
    return;
  if(plant != NULL) // tem anterior 
    plant -> prox = pl -> prox;
  else //eliminando cabeca 
    *cabeca = pl->prox;
  free(pl);
  return;
}
void faz_a_nova_transicao(t_lft **cabeca,t_lft *transicoes_antigas,char *caractere,int pos_do_inicial,int pos_do_final)
{
  char auxiliar[SBUFF];
  strcpy(auxiliar,caractere);
  t_lft *pl = *cabeca;
  t_lft *plant = NULL;

  t_lft *rodando = *cabeca;
  t_lft *rodando2 = *cabeca;
  t_lft *para_testar = *cabeca;

  int contador = 0,novo_ef = 0,novo_ei = 0;
  while(rodando != NULL)
  {
    if(contador == pos_do_final)
    {
      novo_ei = rodando -> ei;
      break;
    }
    contador++;
    rodando = rodando -> prox;
  }
  contador = 0;
  while(rodando2 != NULL)
  {
    if(contador == pos_do_inicial)
    {
      novo_ef = rodando2 -> ef;
      break;
    }
    contador++;
    rodando2 = rodando2 -> prox;
  }
  while(pl != NULL)
  {
    plant = pl;
    pl = pl->prox;
  }
  if(o_estado_final_principal_eh_o_msm(para_testar,pos_do_inicial)) // ve se esta por exemplo: 1 a 1, 2 b 2, 150 k 150.. 
  {
  //  printf("entrouuu linha 595\n");
    novo_ef = procura_a_prox_ligacao(para_testar,transicoes_antigas,pos_do_inicial);
  }
  pl = malloc(sizeof(t_lft));
  pl-> ei = novo_ei;
  pl -> le = strdup(auxiliar);
  pl-> ef = novo_ef;
  pl -> prox = NULL;
  if(plant != NULL)
    plant -> prox = pl;
  else
    *cabeca = pl;
}
int procura_a_prox_ligacao(t_lft *cabeca,t_lft *transicoes_antigas,int pos_do_final)
{
  t_lft *pl = cabeca;
  t_lft *pl2 = transicoes_antigas;
  int contador = 0;
  int pode_mexer = 0;
  int auxiliar;

  while(pl != NULL)
  {
    if(contador == pos_do_final)
    {
      auxiliar = pl -> ef;
      pode_mexer = 1;
    }
    if(pode_mexer)
    {
      if(pl -> ef != auxiliar)
      {
        if(pl -> ei == auxiliar)
          return pl -> ef;
      }
    }
    contador++;
    pl = pl -> prox;
  }
  while(pl2 != NULL)
  {
    if(pl2 -> ei == auxiliar)
    {
      //      printf("A auxiliar aqui linha 547 : %d\n",auxiliar);
      return transicoes_antigas -> ef;
    }
    pl2 = pl2 -> prox;
  }
  return 0;
}
int o_estado_final_principal_eh_o_msm(t_lft *cabeca,int pos_do_final)
{
  t_lft *pl = cabeca;
  int contador = 0;

  while(pl != NULL)
  {
    //    printf("\npl -> ei = %d pl -> ef = %d\n\n",pl->ei,pl->ef);
    if(contador == pos_do_final)
    {
      //    printf("\n pl -> ei = %d pl -> ef = %d\n\n",pl->ei,pl->ef);
      if(pl -> ei == pl -> ef)
      {
        //    printf("\n\n\n\n pl -> ei = %d pl -> ef = %d\n\n",pl->ei,pl->ef);
        return 1;
      }
      else
        return 0;
    }
    contador++;
    pl = pl -> prox;
  }
  return -1;
}
void junta_strings(char **essa_muda_nova,int pos_do_final,int pos_do_inicial,t_lft *novas_transicoes)
{
  t_lft *pl1 = novas_transicoes;
  t_lft *pl2 = novas_transicoes;
  t_lft *para_testar = novas_transicoes;
  //  char pega_valor1[2] = {};
  //char pega_valor2[2] = {};
  char pega_valor1[SBUFF];
  char pega_valor2[SBUFF];
  char pega_valor3[SBUFF] = {};
  int contador = 0,w = 0,termina = 0,posicao = 0;
  while(pl1 != NULL)
  {
    if(contador == pos_do_final)
    {
      // pega_valor1[0] = *pl1 -> le;
      strcpy(pega_valor1,pl1->le);
   //   printf(" pega_valor1 = %s\n",pega_valor1);
      //    if(o_estado_final_principal_eh_o_msm(para_testar,pos_do_inicial)) // ve se esta por exemplo: 1 a 1, 2 b 2, 150 k 150.. 
      //    strcat(pega_valor1,"*");
      break;
    }
    contador++;
    pl1 = pl1 -> prox;
  }
  contador = 0;
  while(pl2 != NULL)
  {
    if(contador == pos_do_inicial)
    {
      // pega_valor2[0] = *pl2 -> le;
      strcpy(pega_valor2,pl2 -> le);
    //  printf(" pega_valor2 = %s\n",pega_valor2);
      // if(o_estado_final_principal_eh_o_msm(para_testar,pos_do_inicial)) // ve se esta por exemplo: 1 a 1, 2 b 2, 150 k 150.. 
      // strcat(pega_valor2,"*");
      break;
    }
    contador++;
    pl2 = pl2 -> prox;
  }
  for(unsigned int i = 0;i < strlen(pega_valor1);i++)
  {
    if(termina == 1)
      break;
    for(unsigned int j = w;j < strlen(pega_valor2);j++)
    {
    //  printf(" valor_esq = %c valor_dir = %c\n",pega_valor1[i],pega_valor2[j]);
      if(pega_valor1[i] != 'E' && pega_valor2[j] != 'E')
      {
        if(pega_valor1[i] != '*' && pega_valor2[j] != '*')
        {
          if(pega_valor1[i] == pega_valor2[j])
          {
            if(pega_valor1[i + 1] == '*' && pega_valor2[j +1] != '*')
            { 
              strcat(pega_valor3,&pega_valor1[i]);
              w = j + w + 1;
              break;
            }
            if(pega_valor1[i + 1] == '*' && pega_valor2[j + 1] == '*')
            {
              strcat(pega_valor3,&pega_valor1[i]);
              w = j + w + 1;
              break;
              // strcat(pega_valor3,&pega_valor2[j]);
            }
            if(pega_valor1[i +1] != '*' && pega_valor2[j + 1] == '*')
            {
              strcat(pega_valor3,&pega_valor2[j]);
              //      pega_valor1[i] = pega_valor2[j];
              // strcat(pega_valor3,&pega_valor2[j]);
      //        printf("DEBUZAO 734 = %s\n",pega_valor1);
              w = j + w + 1;
              break;
            }
            if(pega_valor1[i + 1] != '*' && pega_valor2[j + 1] != '*')
            {
              strcat(pega_valor3,&pega_valor1[i]);
              strcat(pega_valor3,&pega_valor2[j]);
              w = j + w  +1;
              break;
            }
          }
          else
          {
            strcat(pega_valor3,&pega_valor1[i]);
            strcat(pega_valor3,&pega_valor2[j]);
            w = j + w + 1;
            break;
          }
        }
      }
      else
      {
        if(pega_valor1[i] == 'E') 
        {
          strcat(pega_valor3,"E");
          if(pega_valor1[i + 1] == '\0')
          {
            strcat(pega_valor3,pega_valor2);
            termina = 1;
            //            i++;
            break;
          }
          //continue;
        }
        if(pega_valor2[j] == 'E')
        {
          strcat(pega_valor3,"E");
          if(pega_valor2[j + 1] == '\0')
          {
            strcat(pega_valor3,pega_valor1);
            termina = 1;
            break;
            //          j++;
          }
        }
        break;
      }
    }
  }
//  printf("olha ela = %s\n",pega_valor3);
  strcpy(*essa_muda_nova,pega_valor3); /*
                                          if(pega_valor1[0] != pega_valor2[0])
                                          {
                                          strcat(pega_valor1,pega_valor2);
                                          strcpy(*essa_muda_nova,pega_valor1);
                                          }
                                          else
                                          {
                                          if(pega_valor1[1] == '*')
                                          {
                                          strcpy(*essa_muda_nova,pega_valor1);
  // *essa_muda_nova = pega_valor1;
  }
  else
  {
  if(pega_valor2[1] == '*')
  {
  // *essa_muda_nova = pega_valor2;
  strcpy(*essa_muda_nova,pega_valor2);
  }
  else
  {
  //  *essa_muda_nova = pega_valor1;
  strcpy(*essa_muda_nova,pega_valor1);
  }
  }
  } */
}
int buscar_quando_ele_eh_inicial_e_retorna_posicao(int menor_estado,t_lft *novas_transicoes)
{
  int contador = 0;
  t_lft *pl = novas_transicoes;
  while(pl != NULL)
  {
    if(pl -> ei == menor_estado)
      return contador;
    contador++;
    pl = pl -> prox;
  }
  return -1;
}
int buscar_quando_ele_eh_final_e_retorna_posicao(int menor_estado,t_lft *novas_transicoes)
{
  int contador = 0,contador_de_erros = 0;
  t_lft *pl = novas_transicoes;
  t_lft *pl1 = novas_transicoes;
  while(pl1 != NULL)
  {
    if(pl1 -> ei == menor_estado)
      contador_de_erros++;
    pl1 = pl1 -> prox;
  }
  if(contador_de_erros == 0)
    return -1;
  while(pl != NULL)
  {
    if(pl -> ef == menor_estado)
    {
      //    printf("TENTANDO ACHAR 635 = %d\n",pl -> ef);
      return contador;
    }
    contador++;
    pl = pl -> prox;
  }
  return 0;
}
int retorna_o_menor_estado(t_lft *novas_transicoes,t_quintupla novos_estados)
{
  int i = -1,contador_ant = 0,contador_atual = 0;
  int o_menor,fist_time = 0,auxiliar;

  while(novas_transicoes != NULL)
  {
    // if((novas_transicoes -> ei != dados.S) && (novas_transicoes -> ei != novos_estados.S))
    if(novas_transicoes -> ei != novos_estados.S)
    {
      if(novas_transicoes -> ei != i)
      {
        fist_time++;
        if(fist_time == 2)
          contador_ant = contador_atual;
        if(contador_atual <= contador_ant)
        {
          contador_ant = contador_atual;
          contador_atual = 0;
          o_menor = i;
          if(o_menor == -1)
            auxiliar = novas_transicoes -> ei;
        }
        else
          contador_atual = 0;
        // contador_ant = contador_atual;
        //  contador_atual = 0;
      }
      else
        contador_atual++;
      i = novas_transicoes -> ei;
    }
    novas_transicoes = novas_transicoes -> prox;
  }
  if(o_menor == -1)
    return auxiliar;
  else
    return o_menor;
}
int unicos_estados_sejam_os_dois_novos(t_lft *cabeca)
{
  t_lft *pl = cabeca;
  int i = 0;
  while(pl != NULL)
  {
    i++;
    pl = pl -> prox;
  }
  if(i == 2)
    return 1;
  else
    return 0;
}
int criar_novas_transicoes(t_lft **novas_transicoes,t_quintupla *dados,t_lef *finais)
{
  int tamanho;

  tamanho = buscar_tamanho(*novas_transicoes);
  /* esse de baixo insere o novo estado inicial no inicio da transicao, mas eh melhor fazer no final = poupa processamento */
  //cria_transicao_inicial(novas_transicoes,tamanho + 1,dados);
  cria_transicao_inicial(novas_transicoes,tamanho + 1,dados->S);
  dados->S = tamanho + 1;
  while(finais != NULL)
  {
    cria_transicao_final(novas_transicoes,tamanho + 2,finais -> f);
    finais = finais -> prox;
  }
  return tamanho + 2;
}
int buscar_tamanho(t_lft *cabeca)
{
  t_lft *pl = cabeca;
  int i = 0;
  while(pl != NULL)
  {
    i++;
    pl = pl -> prox;
  }
  return i;
}
void cria_transicao_inicial(t_lft **cabeca, int tamanho,int x)
{
  t_lft *pl = *cabeca;
  t_lft *plant = NULL;
  while(pl != NULL)
  {
    plant = pl;
    pl = pl->prox;
  }
  pl = malloc(sizeof(t_lft));
  pl-> ei = tamanho;
  pl-> le = "E";
  pl-> ef = x;
  pl -> prox = NULL;
  if(plant != NULL)
    plant -> prox = pl;
  else
    *cabeca = pl;
}
/*
   void cria_transicao_inicial(t_lft** head_ref, int new_data,t_quintupla dados) 
   { 
   1. allocate node 
   t_lft* new_node = (t_lft*) malloc(sizeof(t_lft)); 
   2. put in the data  
   new_node->ei = new_data; 
   new_node->le = 'E'; 
   new_node->ef = dados.S; 
   3. Make next of new node as head 
   new_node->prox = (*head_ref); 
   4. move the head to point to the new node 
   (*head_ref)    = new_node; 
   }
   */
void cria_transicao_final(t_lft **cabeca, int tamanho,int x)
{
  t_lft *pl = *cabeca;
  t_lft *plant = NULL;
  while(pl != NULL)
  {
    plant = pl;
    pl = pl->prox;
  }
  pl = malloc(sizeof(t_lft));
  pl-> ei = x;
  pl-> le = "E";
  pl-> ef = tamanho;
  pl -> prox = NULL;
  if(plant != NULL)
    plant -> prox = pl;
  else
    *cabeca = pl;
}



/* Funcao de remocao a ser utilizada dentro da faz_a_nova_transicao */
/*
   void remover(lista **cabeca,lista *r)
   {
   lista *pl = *cabeca;
   lista *plant = NULL;
   if(r == NULL)
   return;
   while(pl != NULL && pl != r)  ate achar r ou fim 
   {
   plant = pl;
   pl = pl -> prox;
   }
   if(pl == NULL) nao achou ou lista vazia 
   return;
   if(plant != NULL)  tem anterior 
   plant -> prox = pl -> prox;
   else  eliminando cabeca 
 *cabeca = pl->prox;
 free(pl);
 return;
 }*/
void imprimir_transicoes(t_lft *cabeca)
{
  t_lft *pl = cabeca;
  while(pl != NULL)
  {
    printf("%d->\n",pl->ei);
    printf("%s->\n",pl->le);
    printf("%d->\n\n",pl->ef);
    pl = pl->prox;
  }
  printf("NULL\n");
}
void insere_transicoes(t_lft **cabeca, int x,char *c,int y)
{
  t_lft *pl = *cabeca;
  t_lft *plant = NULL;
  while(pl != NULL)
  {
    plant = pl;
    pl = pl->prox;
  }
  pl = malloc(sizeof(t_lft));
  pl-> ei = x;
  pl-> le = c;
  pl-> ef = y;
  pl -> prox = NULL;
  if(plant != NULL)
    plant -> prox = pl;
  else
    *cabeca = pl;
}
void insere_finais(t_lef **cabeca, int x)
{
  t_lef *pl = *cabeca;
  t_lef *plant = NULL;
  while(pl != NULL)
  {
    plant = pl;
    pl = pl->prox;
  }
  pl = malloc(sizeof(t_lef));
  pl-> f = x;
  pl -> prox = NULL;
  if(plant != NULL)
    plant -> prox = pl;
  else
    *cabeca = pl;
}
int retorna_estados_finais(char *estados_finais[SBUFF],char *pra_separar)
{
  char *arq;
  int i = 0;

  arq = strtok(pra_separar," ");
  while(arq != NULL)
  {
    estados_finais[i] = arq;
    arq = strtok(NULL," ");
    i++;
  }
  return i;
}
/*
   int retorna_contador_e_alfabeto(char *x,char *tokens2[SBUFF])
   {
   int i,j;
   char *alfabeto_e[MAX_ALFA] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","x","z"};
   for(i = 0; i < MAX_ALFA;i++)
   {
   if(strcmp(x,alfabeto_e[i]) == 0)
   {
   for(j = 0;j <= i;j++)
   {
   tokens2[j] = alfabeto_e[j];
   }
   break;
   }
   }
   return i;
   }
   void inserir_alfabeto(t_quintupla **cabeca, char x)
   {
   t_quintupla *pl = *cabeca;
   t_quintupla *plant = NULL;
   while(pl != NULL)
   {
   plant = pl;
   pl = pl->prox;
   }
   pl = malloc(sizeof(t_quintupla));
   pl-> A = x;
   pl -> prox = NULL;
   if(plant != NULL)
   plant -> prox = pl;
   else
 *cabeca = pl;
 }
 void insere_S(t_quintupla **cabeca, int x)
 {
 t_quintupla *pl = *cabeca;
 t_quintupla *plant = NULL;
 while(pl != NULL)
 {
 plant = pl;
 pl = pl->prox;
 }
 pl = malloc(sizeof(t_quintupla));
 pl -> S = x;
 pl -> prox = NULL;
 if(plant != NULL)
 plant -> prox = pl;
 else
 *cabeca = pl;
 }
 void insere_A(t_quintupla **cabeca, char *x)
 {
 t_quintupla *pl = *cabeca;
 t_quintupla *plant = NULL;
 while(pl != NULL)
 {
 plant = pl;
 pl = pl->prox;
 }
 pl = malloc(sizeof(t_quintupla));
 pl -> A = *x;
 pl -> prox = NULL;
 if(plant != NULL)
 plant -> prox = pl;
 else
 *cabeca = pl;
 }
 void insere_K(t_quintupla **cabeca, int x)
 {
t_quintupla *pl = *cabeca;
t_quintupla *plant = NULL;
while(pl != NULL)
{
  plant = pl;
  pl = pl->prox;
}
pl = malloc(sizeof(t_quintupla));
pl -> K = x;
pl -> prox = NULL;
if(plant != NULL)
  plant -> prox = pl;
  else
  *cabeca = pl;
  }*/
void insere_linhas(arquivo_fonte **cabeca, char *x)
{
  arquivo_fonte *pl = *cabeca;
  arquivo_fonte *plant = NULL;
  while(pl != NULL)
  {
    plant = pl;
    pl = pl->prox;
  }
  pl = malloc(sizeof(arquivo_fonte));
  pl-> linhas = strdup(x);
  pl -> prox = NULL;
  if(plant != NULL)
    plant -> prox = pl;
  else
    *cabeca = pl;
}
char *strdup (const char *s) 
{
  char *d = malloc (strlen (s) + 1);   // Space for length plus nul
  if (d == NULL) return NULL;          // No memory
  strcpy (d,s);                        // Copy the characters
  return d;                            // Return the new string
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
  printf("%s v.%s - %s\n", "ex12", VERSION, "Convert AFD into Exp Reg");
  printf("\nUsage: %s [-h|-v|-c]\n", "ex12");
  printf("\nOptions:\n");
  printf("\t-h,  --help\n\t\tShow this help.\n");
  printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
  printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
  /* add more options here */
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
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void copyr(void)
{
  IFDEBUG("copyr()");
  printf("%s - Version %s\n", "ex12", VERSION);
  printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
  if(verb>3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
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
  return i-4;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=2 sw=2 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20150619.231433      */
