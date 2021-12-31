# Programa er2afnd #

## Converte uma Expressao Regular para AFND ##

### Entrada de Dados ###

Uma _string_ contendo uma expressão regular. A string é formada pelos seguintes caracteres e somente estes:

- a-z : símbolos do alfabeto (letras minúsculas)
- ξ   : símbolo vazio (epsilon, letra E maiúscula)
- |   : disjunção (OU)
- .   : conjunção (E) (explicitar obrigatoriamente. Não aceite _strings_ com conjunção implícita, exemplo: _ab_. Deve ser _a.b_)
- *   : estrela de Kleene (repete o símbolo anterior zero ou mais vezes)
- ()  : parênteses (muda a prioridade de execução das operações. Exemplo: `a|b.a ≠ (a|b).a`, ou então `a.b*.b ≠ (a.b)*.b`

A entrada será de uma única linha com uma _string_ (não são aceitas _strings_ em múltiplas linhas).

### Processamento ###

- Elaborar arvore sintatica
- Cria automatos atomicos
- Faz as operacoes de conjuncao, concatenacao e estrela de Klenee

### Saída ###

- Uma quintupla que representa a AFND

#### Formato da saída

- K: Conjunto de estados
    - Tipo: unsigned short K;
    - Constrição: 1 <= K <= USHORT\_MAX
    - Exemplo: K=5, então os estados são {q0, ..., q4}
    - Se USHORT\_MAX = 65535, então o maior estado é q65534.
- A: Alfabeto
    - Tipo: char A;
    - Constrição: Apenas letras minúsculas de 'a' a 'z'.
    - Exemplo: A='c', então o alfabeto é {a, b, c}
- S: Estado inicial (único)
    - Tipo: unsigned short S;
    - Constrição: 0 <= S < K
    - Exemplo: S=0, então o estado inicial é q0.
- F: Conjunto de estados finais
    - Tipo: lista encadeada simples.
    - Conteúdo: números inteiros unsigned short referentes a todos estados que são finais.
- D: Função Delta, a função de transição do autômato
    - Tipo: lista encadeada simples.
    - Conteúdo: mapeamento (estado inicial, símbolo lido, estado final) para cada transição do autômato.

#### Exemplo de tabela da função de transição:

| Ei | Le | Ef |
|----|----|----|
| q0 |  a | q1 |
| q0 |  b | q1 |
| q1 |  a | q1 |
| q1 |  b | q0 |

### Tarefas

- Renomear arquivos exN.c e exN.h para o número correto do exercício (em 2018s1 temos ex9.c e ex9.h)
- Trabalho em duplas ou triplas
- Criar _milestones_
- Criar _label_ amarelo "tasks" de uso exclusivo do professor
- Criar outros _labels_ para uso do grupo e melhor organização
- Manter discussão sobre estratégias e organização do código nos _issues_
- Trabalhar no _develop_ e atualizar o _master_
- Não fazer _fork_
- Criar página _wiki_ com manual técnico e manual do usuário

## Licença ##

### Autores ###

* Prof. Dr. Ruben Carlo Benante
    - Email: <rcb@upe.br>
    - Data da criação: 2016-05-20

**Colaboradores**

* Veja lista no arquivo [AUTHORS](AUTHORS)

### Licença pt\_BR ###

afd2er : um programa para converter ER em AFND.

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

afd2er: a program to convert a Regular Expression into a Finite Deterministic Automata.

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

