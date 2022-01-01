# Programa afnd2afd

## Converte AFND->AFD

### Entrada de Dados ###

O programa aceita como entrada:

Uma quíntupla que pode representar um AFD ou um AFND

A entrada podem vir de duas fontes:

1- Leitura de arquivo (_file_)
2- Leitura da entrada padrão (_stdin_)

#### Opções do sistema (flags)

* -n : a entrada de dados é uma quíntupla de um AFND que será convertido para AFD.
* -f _file_ : faz a entrada de um arquivo.
* -h : mostra o help e termina.
* -v : aumenta a _verbosidade_ (cumulativo).
* -V : mostra a versão e o copyright e termina.

A flag `-f file` é opcional ao usuário. Se existir a entrada é do arquivo indicado na linha de comando. Se não existir esta flag, o programa deverá ler da entrada padrão (_stdin_).

##### Formato da quíntupla (AFND)

A entrada lê uma quíntupla que descreve formalmente um autômato não-determinístico).

- K: Conjunto de estados
    - Tipo: short K;
    - Constrição: 1 <= K <= SHORT\_MAX
    - Exemplo: K=5, então os estados são {q0, ..., q4}
    - Se SHORT\_MAX = 65535, então o maior estado é q65534.
    - Ficam reservados os valores negativos para indicar erro.
- A: Alfabeto
    - Tipo: char A;
    - Constrição: Apenas letras minúsculas de 'a' a 'z'.
    - Exemplo: A='c', então o alfabeto é {a, b, c}
    - A letra maiúscula 'E' fica reservada para indicar palavra vazia.
- S: Estado inicial (único)
    - Tipo: short S;
    - Constrição: 0 <= S < K
    - Exemplo: S=0, então o estado inicial é q0.
    - Reserva-se valores negativos para usar como código de erro.
- F: Conjunto de estados finais
    - Tipo: lista encadeada simples.
    - Conteúdo: números inteiros short referentes a todos estados que são finais.
    - Reservados valores negativos para indicar erros.
- D: Função Delta, a função de transição do autômato
    - Tipo: lista encadeada simples.
    - Conteúdo: mapeamento (estado inicial, símbolo lido, estado final) para cada transição do autômato.
    - Dada a função `d(Ei, Le, Ef)`, se para todo `d(...)` é determinado univocamente o estado final `Ef` a partir do estado inicial `Ei` e do símbolo lido `Le`, e os símbolos lidos não são VAZIO (`ξ`, epsilon, ou `E`) para todo `d(...)`, então a quíntupla é um AFD. Caso contrário trata-se de um AFDN.
    - Ficam reservados valores negativos e NULL para indicar erros ou outras condições de problema.

###### Exemplo de tabela da função de transição de um AFND:

| Ei | Le | Ef |
|----|----|----|
| q0 |  a | q1 |
| q0 |  b | q1 |
| q0 |  ξ | q2 |
| q1 |  a | q1 |
| q1 |  ξ | q0 |
| q2 |  a | q0 |
| q2 |  ξ | q1 |

### Processamento (AFND->AFD)

- Receber a entrada como determinado pelas flags (arquivo ou entrada padrão)
- Converter o AFDN da entrada para um AFD.

### Saída

- Salvar um arquivo de imagem BMP via Allegro, contendo a representação do AFND.
- Imprimir o AFD resultante no mesmo formato explicado acima (quíntupla), na saída padrão (não usar arquivos)
- Salvar um arquivo de imagem BMP via Allegro, contendo a representação do AFD.

### Tarefas

- Renomear arquivos exN.c e exN.h para o número correto do exercício (em 2018s1 temos ex7.c e ex7.h)
- Trabalho em duplas ou triplas
- Criar _milestones_
- Criar _label_ amarelo "tasks" de uso exclusivo do professor
- Criar outros _labels_ para uso do grupo e melhor organização
- Manter discussão sobre estratégias e organização do código nos _issues_
- Trabalhar no _develop_ e atualizar o _master_
- Não fazer _fork_
- Criar página _wiki_ com manual técnico e manual do usuário

## Licença

### Autores

* Prof. Dr. Ruben Carlo Benante
    - Email: <rcb@upe.br>
    - Data da criação: 2016-10-14
    - Data da modificação: 2018-05-04

**Colaboradores**

* Veja lista no arquivo [AUTHORS](AUTHORS)

### Licença pt\_BR ###

ex-afnd-afd : Converte AFND para AFD.

Copyright (C) 2016 Ruben Carlo Benante <rcb@upe.br>

Este programa é software livre; você pode redistribuí-lo e/ou
modificá-lo sob os termos da Licença Pública Geral GNU, conforme
publicada pela Free Software Foundation; a versão 2 da Licença 

Este programa é distribuído na expectativa de ser útil, mas SEM
QUALQUER GARANTIA; sem mesmo a garantia implícita de
COMERCIALIZAÇÃO ou de ADEQUAÇÃO A QUALQUER PROPÓSITO EM
PARTICULAR. Consulte a Licença Pública Geral GNU para obter mais
detalhes.

Você deve ter recebido uma cópia da Licença Pública Geral GNU
junto com este programa; se não, escreva para a Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
02111-1307, USA.

### License en\_US ###

ex-afnd-afd : Converts AFND to AFD.

Copyright (C) 2016 Ruben Carlo Benante <rcb@upe.br>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

