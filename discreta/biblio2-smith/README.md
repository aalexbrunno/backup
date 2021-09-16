# Sistema de Controle para Biblioteca Pessoal

## Introdução 

* Este exercício tem 2 versões:
    * A versão mais simples, v1.0, consiste em controlar apenas os livros. (disciplina Programação I)
    * A versão completa, v2.0, consiste em controlar livros e clientes. (disciplina Programação II)

Vamos analisar ambos os casos abaixo.

## Versão 1.0: controle de livros caseiros


### Banco de Dados

Os livros serão armazenados em um banco de dados em texto puro.

* Nome do arquivo: livros.txt

#### Formato interno do banco de dados

Os dados serão armazenados em linha, uma linha para cada livro, os campos sendo separados por ponto-e-vírgula (;).
A ordem dos campos é:

```
Código;Autor;Título;Editora;Local;Ano;Edição;ISBN
```

Ao entrar com dados nos campos, cuide para que o usuário não digite o ponto-e-vírgula. Os campos são descritos abaixo:

Campos obrigatórios:

* Código: um número inteiro identificador do livro, que se incrementa automaticamente a cada inserção de livro novo. O usuário não tem como alterar ou escolher este número.
* Autor: Nome do autor em ordem normal (Primeiro Segundo Sobrenome...). Não permita ponto-e-vírgula.
* Título: O título completo do livro. Todos caracteres são aceitos, exceto, obviamente, o caracter de ponto-e-vírgula, como em todos campos.
* Ano: O ano de publicação do livro.
* Editora: O nome da editora que publicou o livro.
* Local: A cidade da publicação.

Campos opcionais:

* Edição: A edição do livro, numérica: 1, 2, 3, etc.
* ISBN: O código ISBN de 13 dígitos

Uma vez entrado os dados do livro, o mesmo será salvo no arquivo texto "livro.txt".

Exemplo com todos campos (primeira edição, ISBN-10):

```
1;Stephen Hawking;A Brief History of Time: From the Big-Bang to Black Holes;Bantam;London;1988;1;9780553380163
```

Exemplo sem os campos opcionais (note que ficam dois ";" ao final) para marcar os campos em branco:

```
1;Stephen Hawking;A Brief History of Time: From the Big-Bang to Black Holes;Bantam;London;1988;;
```

Exemplo de um banco de dados com 3 livros:

```
1;Stephen Hawking;A Brief History of Time: From the Big-Bang to Black Holes;Bantam;London;1988;1;9780553380163
2;John Craig Wheeler;Cosmic Catastrophes: Exploding Stars, Black Holes, and Mapping the Universe;Cambridge;New York;2007;;
3;Chris Impey;Einstein’s Monsters: the Life and Times of Black Holes;Deutch Bib;Berlin;2019;;
```

#### Operações no banco de dados:

O banco de dados é um simples arquivo texto, e esse formato é a melhor opção para bancos de dados pequenos, onde se pode interferir diretamente em seu conteúdo com um editor como o vi. Também apresenta outras facilidades, como por exemplo facilidade de debug nas operações com arquivos. Estes são alguns dos "prós" de se utilizar formato texto em projetos. Recomendo fortemente utilizar textos a não ser que a aplicação atinja um número tão grande de dados que possa atrapalhar a performance do programa.

Entre os "contras" está o fato de gastar mais espaço em disco e não ser tão veloz. Porém, note com atenção, esses "contras" não são relevantes se a base de dados não é gigantesca. Perde-se também algumas facilidades nas funções de gravação de "registros" binários em C, que facilita bastante a gravação e leitura de arquivos diretamente para `structs`. Mas isso é recompensado pela facilidade de acesso aos dados em um arquivo texto.

Entre as operações a serem implementadas estão:

* Adicionar um livro
* Consultar um livro
* Alterar um livro
* Remover um livro

Cada uma dessas operações devem ter o layout de tela montado em janelas (WINDOW) separadas usando a biblioteca ncurses. Vejamos cada uma:

#### Telas

As telas terão um *framework* em comum assim divididas:

* Linha superior: título com o nome do software
* Segunda linha: nome da tela atual
* Metade superior: operação
* Metade inferior: resultados
* Linha de Status: a penúltima linha, reservada para mensagens do sistema
* Linha de Atalhos: a última linha, com indicações dos atalhos associados às teclas de função ou outras

Em todas as telas deve-se ficar visível as opções:

* F1: help, vai para tela de help. Pressionada novamente, volta para a tela anterior com toda informações idêntica a como estava ao sair para o help.
* F4 ou tecla "q": quit, sair do programa. Se na tela 01, com dados parcialmente adicionados, avisar que os dados serão perdidos. Nas outras telas não há necessidade de aviso.
* F5/F6: avançar para outras telas

Outros atalhos podem mudar conforme desejado, mas esses acima devem ser fixos em todas as telas.


##### Tela 00: Help

Nesta tela se mostrará um texto explicativo de como o sistema funciona.

O texto deve ser longo o suficiente para que possa ser implementada "rolagem de tela", na qual o usuário tecla as setas para cima/baixo para ler o texto.


##### Tela 01: Adicionar novo livro

A Tela 01 será dividida ao meio. Na parte superior o usuário poderá digitar os dados do livro. A parte inferior mostrará a entrada *BibTeX* (hot, ou seja, conforme for sendo digitada), e a forma que se faz a referência bibliográfica no estillo *abbr*.

Linha de atalhos: A linha inferior terá indicações das funções associadas às teclas de F1 a F8 (ou conforme necessário).

Como opções, há que se ter a opção de salvar o livro já digitado.

Avisar que os dados serão perdidos se o usuário tentar sair do programa.

Manter os dados parcialmente digitados intactos caso o usuário mude de tela e volte sem salvar, possibilitando a navegação sem perda de dados.

Linha de Status: A linha imediatamente acima à linha inferior será reservada para mensagens.

Ao salvar o livro, indicar na linha de status que foi salvo com sucesso, e zerar todos os campos.

* Banco de dados:

Um livro adicionado novo é colocado ao final do arquivo texto, e seu código é atribuído automaticamente pelo incremento do último valor.


##### Tela 02: Buscar por um livro

A Tela 02 permitirá, na metade de cima, que o usuário digite palavras chaves em qualquer campo, e ao teclar um atalho configurado (alguma tecla de função), a metade inferior mostrará uma lista de livros para se navegar, no formato bibliográfico estilo *abbr*.

As palavras chaves podem ser buscadas como uma operação lógica de um conectivo "AND" ou de um conectivo "OR", isto é: o usuário poderá optar por fechar em um livro que tem TODAS as palavras digitadas em todos os campos, ou buscar livros que tenham QUAISQUER das palavras digitadas.

Essa opção pode ser implementada como um atalho de uma tecla de função.

Na metade inferior, o usuário poderá navegar com as setas e escolher dentre as soluções apresentadas um único livro que poderá levar para as telas 03 e 04.

Atenção: as telas 03 e 04 só podem ser acessadas a partir da escolha de um livro na tela 02.

* Banco de dados:

Deve-se minimizar a quantidade de operações em disco. É boa prática abrir o arquivo (função fopen), fazer a operação e fechar o arquivo (função fclose) imediatamente, sem incluir nenhum código desnecessário entre a abertura e o fechamento do arquivo.

Limite os resultados a busca a 10 livros na memória (com um vetor de 10 strings), mas indique ao usuário que existema mais que 10 livros caso isso ocorrer, pois o mesmo poderá pedir para ler as próximas 10 entradas.

##### Tela 03: Retificar um livro

Nesta tela o livro buscado (na tela 02) é mostrado na metade superior, e a metade inferior vem preenchida permitindo alteração.

Ao final da edição o usuário pode optar por salvar a alteração feita ou descartar a mesma, mantendo a original.

* Banco de dados:

Busque a linha em que o livro original está armazenado e escreva por cima (sobrescreva) a linha do livro novo. Ao final da operação o banco de dados continuará com o mesmo número de linhas (as linhas também são chamadas de "registros", onde cada registro representa um livro).

##### Tela 04: Apagar um livro

O livro escolhido na Tela 02 (tela de busca) será trazido para esta tela e mostrado todas as suas informações. Será pedido para o usuário confirmar se deseja realmente apagar o livro.

Se sim, o livro será marcado para remoção (mas não será imediatamente apagado).

* Banco de dados:

Apagar uma linha em um arquivo exige muito do HD. Não existe um procedimento de "remover" uma linha de modo que as linhas de baixo "subam" para tomar seu lugar. Para realmente apagar uma linha é preciso buscar essa linha, e começar a "copiar" uma a uma as linhas de baixo, uma posição para cima.

É custoso e para arquivos grandes pode se tornar inviável.

Uma solução largamente utilizada em banco de dados é ao invés de "apagar" a linha, apenas marcar com um indicador que aquele livro não existe mais. No nosso sistema de biblioteca faremos isso apagando o código do livro na primeira coluna e trocando seu número pela letra maiúscula "D". Desta forma, se apagarmos o livro 2 do banco de dados do nosso exemplo, o resultado no arquivo texto seria:

```
1;Stephen Hawking;A Brief History of Time: From the Big-Bang to Black Holes;Bantam;London;1988;1;9780553380163
D;John Craig Wheeler;Cosmic Catastrophes: Exploding Stars, Black Holes, and Mapping the Universe;Cambridge;New York;2007;;
3;Chris Impey;Einstein’s Monsters: the Life and Times of Black Holes;Deutch Bib;Berlin;2019;;
```
Isso torna a opção de apagar super rápida e simples (basta "alterar" o registro). Porém, como você deve perceber, traz alguns inconvenientes:

* O código 2 não está mais em uso e poderia ser reutilizado para outro livro.
* O mesmo vale para a posição 2, ou seja, a linha 2 no arquivo, que não está mais em uso e poderia ser reutilizada.
* O arquivo não "diminui" de tamanho, não importa quantos livros se apaguem.
* Deve-se ter um modo de realmente "apagar" as linhas quando se desejar. Essa operação é chamada "purge".

No exercício dado como versão 1, esses problemas não serão abordados, mas se desejarem, será considerado como tarefa extra que pode ser uma bonificação para seu grupo.




## Versão 2.0: Controle de empréstimos de livros


A primeira versão trata apenas do cadastro dos livros de um amante da leitura caseiro, em um arquivo texto chamado "livros.txt", com seus registros por linhas, e seus campos separados por ponto-e-vírgulas.

A versão 2.0 incluirá toda a primeira parte, chamado módulo "livro", com um campo extra de "quantidade", e incluirá o módulo "cliente" que iremos discutir abaixo.


### Banco de Dados

Os arquivos serão em texto puro, e serão divididos em 3:

* livros.txt : os livros, conforme explicado abaixo.
* clientes.txt : arquivo com dados dos clientes.
* emprestou.txt : arquivo relacional, contendo uma relação entre um cliente e os livros que emprestou, indexada por clientes.
* emprestado.txt : arquivo relacional, contendo uma relação entre livros e clientes, indexada por livros.

Há também um arquivo chamado config.txt que será tratado no final, mas não é considerado parte do "banco de dados relacional".

#### Formato interno do banco de dados

* livros.txt : registros por linha, campos separados por ponto-e-vírgula, como definido abaixo:

```
CódLivro;Autor;Título;Editora;Local;Ano;Edição;ISBN;Quantidade
```

O último campo, "Quantidade", indicará quantos exemplares do livro existem em estoque. Sabendo que um livro pode ter mais de um exemplar muda algumas operações sobre eles, que devem ser consideradas.


* clientes.txt : registros por linha, campos separados por ponto-e-vírgula, como definido abaixo:

```
CódCliente;Nome;Telefone;Email;Aniversário
```

O aniversário é opcional, e fica registrado em branco se a linha terminar com ";".

* emprestou.txt : entenda como "o cliente emprestou livros". Os registros por linha, campos separados por ponto-e-vírgula, como definido abaixo.

Este arquivo tem um formato especial, chamado em teoria de banco de dados como "banco de dados relacional". O primeiro campo é chamado de "chave", e por ele se faz buscas.

Neste arquivo, queremos buscar, dado um cliente, quais livros ele emprestou. Assim, a chave de acesso, ou primeiro campo, é o código do cliente.

```
CódCliente;CódLivro1;DataRetirada1;CódLivro2;DataRetirada2;CódLivro3;DataRetirada3;CódLivro...
```

No nosso banco de dados o cliente poderá emprestar um número "ilimitado" de livros. Ao ler a linha para a memória, será lido em uma lista dinâmica, de modo que não haja restrição de limites. A restrição só será tratada se a função "malloc" falhar ao tentar alocar memória para um próximo nodo da lista.

Para encontrar a lista de livros que o cliente deve, basta estar de posse do código do cliente e fazer uma leitura corrida neste arquivo até encontrar a sua linha. O campo sendo considerado "chave" implica que não haverá duplicidade, ou seja, não pode ser registrado o mesmo clientes em duas linhas distintas.

Nota: o cliente só pode emprestar um único exemplar de um mesmo livro. Esta restrição facilitará gerenciar o sistema, mas deve-se pensar em como isso afetaria o mesmo caso não houvesse a restrição.


* emprestado.txt : entenda como "um exemplar do livro está emprestado para um cliente". Os registros por linha, campos separados por ponto-e-vírgula, como definido abaixo.

Neste arquivo a chave é o código do livro, ou seja, é o primeiro campo e é único (não tem duplicidade). Assim pode-se, a partir de um livro, encontrar quem está de posse do mesmo.

```
CódLivro;CódCliente1;CódCliente2;CódCliente3...
```

O livro pode ter tantos clientes quantos forem seus exemplares, e não mais que isso. Não há limites para o número de exemplares de livros que a biblioteca poderia comprar.

Um livro que não está emprestado estaria registrado em sua linha como:

```
CódLivro
```

Ou também, não estaria nem constando do arquivo. Se uma busca no arquivo emprestado.txt falhar, deve-se assumir que o livro não está emprestado.



#### Operações no banco de dados:


Suponha nosso banco de dados com 3 livros, como acima, porém com o primeiro livro com 2 exemplares:

* livros.txt: formato : CódLivro;Autor;Título;Editora;Local;Ano;Edição;ISBN;Quantidade

```
1;Stephen Hawking;A Brief History of Time: From the Big-Bang to Black Holes;Bantam;London;1988;1;9780553380163;2
2;John Craig Wheeler;Cosmic Catastrophes: Exploding Stars, Black Holes, and Mapping the Universe;Cambridge;New York;2007;;;1
3;Chris Impey;Einstein’s Monsters: the Life and Times of Black Holes;Deutch Bib;Berlin;2019;;;1
```

Suponha que temos 3 clientes cadastrados, dois dos quais sem aniversário marcado:

* clientes.txt: formato: CódCliente;Nome;Telefone;Email;Aniversário

```
1;Jorge Anderscore;81987654567;jorgea@fui.pr;
2;Marta Duarte;11998877665;morta@primavera.org;19901130
3;Charles Toquito;77932742220;toquito@degaule.fr;
```

Suponha agora que o estado do sistema considere que

* Jorge tem emprestado um dos livros do Hawking a mais de 7 dias e está atrasado, e também pegou o livro do Wheeler
* Marta está com o outro livro do Hawking, pegou hoje (segunda feira, 2021-07-26).
* Charles não pegou nenhum livro ainda, mas está chegando na biblioteca para pegar algo para ler.

A situação atual é:

* emprestou.txt: formato: CódCliente;CódLivro1;DataRetirada1;CódLivro2;DataRetirada2;CódLivro3;DataRetirada3;CódLivro...

```
1;1;20210716;2;20210722
2;1;20210726
```

* emprestado.txt: formato : CódLivro;CódCliente1;CódCliente2;CódCliente3...

```
1;1;2
2;1
```

Neste momento, chega Charles e pede para emprestar o livro do Wheeler, que só tem um exemplar e já está emprestado.
O sistema então acusa da impossibilidade, e Charles então decide emprestar o livro de Hawking, que ainda tem um disponível.

Após o empréstimo, os arquivos alterados são:


* emprestou.txt:

```
1;1;20210716;2;20210722
2;1;20210726
3;1;20210726
```

* emprestado.txt:

```
1;1;2
2;1
3;1
```


Repare que uma única operação alterou vários arquivos. Cada operação deve ser pensada sobre como ela influencia o sistema como um todo. Desde a inclusão de novos livros, ou mesmo a remoção de um cliente. Todos arquivos afetados devem sempre ser atualizados e estarem consistentes.



As leituras dos dados dos arquivos para a memória ocorrerão sempre em listas ligadas, com isso evitando limites.

* Livros
* Clientes
* Empréstimos (com chave cliente, emprestou.txt)
* Emprestimos (com chave livro, emprestado.txt
* Resultados das buscas
* Etc.



#### Telas

O sistema contará com as seguintes telas:


##### Telas de Livros

* Tela 01: inclusão de livro.
    * Deve mostrar o campo de número de exemplares (quantidade).

* Tela 02: consulta de livro.
    * Deve indicar o número de exemplares
    * Deve indicar o estoque disponível para retirada

* Tela 03: alteração de livro.
    * Deve permitir adicionar um novo exemplar

* Tela 04: remoção de livro.
    * Cuidado, uma vez removido, o livro não sai apenas do arquivo "livros.txt"

##### Telas de Clientes

* Tela 05: adição de novo cliente.
    * Pegar os dados pessoais e adicionar novo cliente

* Tela 06: consulta de cliente
    * Consultar por código, por nome, ou qualquer outro campo
    * Ao encontrar o cliente, mostrar os livros que ele tem emprestado
    * Avisar se um determinado livro está atrasado. Prazo de devolução de 07 dias.
    * Permitir mudar para outra tela com o cliente consultado. 

* Tela 07: alteração de um cliente
    * Esta tela deve ser preenchida pela Tela 06, de consulta.
    * Nesta tela pode-se alterar os dados pessoais
    * Permitir dar baixa num livro (devolver).

* Tela 08: apagar os dados de um cliente
    * Só chegar nessa tela através da Tela 06 de consulta
    * Uma vez aqui, confirmar se deseja mesmo apagar o cliente
    * Manter a consistência com todos os arquivos do banco de dados após apagar o cliente
    * Confirmar se os livros devem ser devolvidos ao estoque ou se os livros serão considerados perdidos e sem retorno

##### Telas Gerais

* Tela 00: Help
    * Mostrar pelo menos uma página de explicação para cada uma das telas do sistema

* Tela 09: Operações avançadas
    * Nesta tela existirão opções para configuração do sistema.
    * Essas opções de configuração serão salvas num arquivo chamado "config.txt" com o seguinte formato:
   
Cada linha é um registro contendo o nome de uma opção e o seu valor. Exemplo:

```
consulta=and
busca=binaria
purge=manual
```

Essas três opções serão discutidas agora. Outras opções podem ser adicionadas como se desejar, mas essas três acima são obrigatórias.

* Opção de consulta: valores: and/or

Na tela de consulta, pode-se optar por fazer uma busca com "AND" de todas palavras fornecidas ou "OR" de quaisquer das palavras fornecidas. Se o usuário desejar mudar o padrão, poderá na Tela 09 alterar. A alteração na tela 09 é permanente, mas isso não impede do usuário ter a opção de fazer uma busca com AND ou OR para apenas aquela busca atual, portanto devem ter opções para isso nas telas 02 ou 06.

* Opção de busca: valores: binaria/linear

A busca em um arquivo é normalmente linear. A busca linear é lenta para arquivos grandes. Uma opção é montar uma árvore de busca. Para cada nó da árvore, se o objeto buscado é "menor" que o nó atual, move-se para o ramo da esquerda, caso contário, move-se para o ramo da direita.

* Opção de purge: valores: manual/automatico

Se a opção de purge estiver em manual (o recomendado), um item removido é apenas marcado com a letra "D" no local do seu código (em livros.txt ou clientes.txt) e claro as tabelas relacionais (emprestou.txt e emprestado.txt) devem ser atualizadas e limpas de acordo.

Se a opção de purge estiver em automatico, então não só o item é marcado com D, mas é rodada uma rotina para limpar todos registros marcados com D e excluí-los permanentemente dos arquivos.

Na Tela 09, além da opção de alterar a configuração do purge, também deve haver a opção de "rodar o purge agora?" para o caso manual, ou seja, se o usuário quiser manter a opção manual mas quiser executar o purge naquele momento.


* Tela 10: Copyright e Créditos
    * A tela que mostra os envolvidos na produção do sistema
    * Mostrar email de contato

* Tela 11: Licensa
    * Mostrar o texto padrão da licensa de software GNU/GPL versão 2.0

### Compilar o Codigo

Para compilar o codigo do Sistema de Bibliotecas do grupo Smith, utilize o seguinte comando:
```gcc -Wall -Wextra -g -pedantic ex11.c -o ex11.x -lform -lncurses```

### Orientação

* Autor: Prof. Dr. Ruben Carlo Benante
* Email: rcb@upe.br
* Data: 2021-07-26
* Licensa: GNU/GPL v2.0

