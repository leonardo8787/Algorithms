<h2>Paradigmas de Projetos de Algoritmos</h2>

<strong>Introdução</strong>

O objetivo deste capítulo é apresentar os principais paradigmas e técnicas de projeto de algoritmos, a saber: indução, recursividade, algoritmos tentativa e erro, divisão e conquista, balanceamento, programação dinâmica, algoritmos gulosos e algoritmos aproximados. Na apresentação dos tópicos, será apontado ao longo do texto onde cada paradigma é empregado.

* Indução
* Recursividade
* Algoritmos tentativa e erro
* Divisão e Conquista
* Balanceamento
* Programação Dinâmica
* Algoritmos gulosos
* Algoritmos aproximados

<h2>Indução</h2>

A indução matemática é uma técnica muito poderosa para provar asserções sobre os números naturais. A técnica funciona como segue. Seja T um teorema que desejamos provar, suponhamos que T tenha como parâmetros um número natural n. Em vez de tentar provar diretamente que T é válido para todos os valores de n, basta provar as duas condições a seguir:

1. T é válido para n=1.
2. Para todo n>1, se T é válido para n-1, então T é válido para n.

A condição 1 é usualmente simples de provar, e é chamada de passo base. Na maioria das vezes, provar a condição 2 é mais fácil do que provar o teorema diretamente, uma vez que podemos usar a asserção de que T é válida para n-1. Essa afirmativa é chamada de hipótese de indução ou passo indutivo.

Por que as duas condições são sufucuentes ? As condições 1 e 2 implicam que T é válido para n=2. Se T é válido para n=2, então a condição 2 implica que T também é válido para n=3, e assim por diante. O princípio da indução é basico e, por isso, é colocado como um axioma na definição dos números naturais.

<strong>OBS:</strong> Este é um assunto com uma carga de demonstrações muito grande, por isso deixo o link de um material para auxiliar no estudo de indução.

<h2>Recursividade</h2>

Um método que chama a si mesmo, direta ou indiretamente, é dito recursivo. O uso da recursividade geralmente permite uma descrição mais clara e concisa dos algoritmos, especialmente quando o problema a ser resolvido é recursivo por natureza ou utiliza estruturas recursivas, tais como as árvores.

<strong>Exemplo:</strong> Considere a árvore binária de pesquisa mostrada na Figura 2.1. <strong>árvore binária de pesquisa</strong> é uma árvore binária em que todo nó interno contém um registro com a seguinte propriedade: todos os registros com chaves menores estão na subárvore esquerda e todos os registros com chaves maiores estão na subárvore direita.

![Figura 2.1](https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/400px-Binary_search_tree.svg.png)

O programa 2.1 mostra a estrutura de dados para a árvore da Figura 2.1.

~~~
private static class No {
  Object reg;
  No esq, dir;
}
~~~

Vamos considerar um algoritmo para percorrer todos os registros que compõem a árvore. Existe mais de uma ordem de caminhamento em árvores, mas a mais utilizada para árvores de pesquisa é a chamada ordem de caminhamento central. Esse caminhamento é melhor expresso em termos recursivos, a seber: 

1. caminha na subárvore esquerda na ordem central;
2. visita a raiz;
3. caminha na subárvore direita na ordem central.

O programa 2.2 mostra o método central da classe ArvoreBinaria apresentada no Programa 2.1, o qual implementa o caminhamento central de forma recursiva. No caminhamento central, os nós são visitados em ordem lexicográfica das chaves. Percorrer a árvore da Figura 2.1 usando caminhamento central recupera as chaves na ordem 1,2,3,4,5,6 e 7.

~~~
private void central (No p){
  if (p != null) {
    central (p.esq);
    System.out.println(p.reg.toString);
    central(p.dir);
  }
}
~~~

Quando o método central é chamado com o valor do objeto de referência p referenciado o nó raiz da árvore, o primeiro comando verifica a condição de terminação, perguntando se p != null. Se for diferente de null, então central é chamado recursivamente seguindo a referência ao filho à esquerda, até encontrar uma referência null. Quando encontra p==null, o método simplesmente retorna para quem chamou, no caso central, e o comando seguinte é executado, imprimindo o valor de chave que rotula o nó. No caso de ser a primeira vez que p==null, o valor 1 é impresso, e central é chamado recursivamente, seguindo a referência ao filho à direita.

<h2>Como implementar Recursividade</h2>

Um compilador implementa um método recursivo por meio de uma <strong>pilha</strong>, na qual são armazenados os dados usados em cada chamada de um método que ainda não terminou de processar. Todos os dados não globais são para a pilha, pois o estado corrente da computação deve ser registrado para que possa ser recuperado de uma nova ativação de um método recursivo, quando a ativação anterior deverá prosseguir.

No caso do caminhamento central para árvores binárias apresentado no programa 2.2, para cada chamada recursiva ao método central o valor de p e o endereço de retorno da chamada recursiva são armazenados na pilha, por meio de um operador semelhante ao operador empilha. Quando encontra p == null, o método retorna para quem chamou, utilizando o endereço de retorno que está no topo da pilha, por meio de um operador igual ao operador desempilha.

Como todo método repetitivo, métodos recursivos introduzem a possíbilidade de iterações quem podem não terminar, implicando a necessidade de se considerar o problema de <strong>terminação</strong>. Uma exigência fundamental é que a chamada recursiva a um método P esteja sujeita a uma condição B, a qual se torna não satisfeita em algum momento da computação. Wirth(1976) apresenta um esquema para métodos recursivos como sendo uma composição C de comandos Si e P, a saber:

~~~
 P = if B then C[Si, P]
~~~

A Técnica básica para demonstrar que uma repetição termina é definir uma função f(x), na qual x é o conjunto de variáveis do programa, tal que:

1. F(x) <= 0 implica a condição de terminações;
2. F(x) é decrementado a cada iteração.

Uma forma simples de garantir a terminação é associar um parâmetro n para P (no caso por valor) a chamada P recursivamente com n-1. Logo, a substituição da condição B por n>0 garante a terminação, o que pode ser formalmente expresso por:

~~~
 P = if n>0 then P[Si, P(n-1)]
~~~

Concluindo, na prática é necessário garantir que o nível mais profundo de recursão seja não apenas feito, mas também possa ser mantido pequeno, pois, na ocasião de cada ativação recursiva de um método P, uma parcela de memória é necessária para acomodar variáveis a cada chamada. Assim, um aspecto importante para manter o tamanho da pilha pequeno é o balanceamento, uma técnica básica para um bom projeto de algoritmos.

<h2>Quando não usar recursividade</h2>

Algoritmos recursivos são apropriados quandoo problema a ser resolvido ou os dados a serem tratados são definidos em termos recursivos. Entretanto, isso não garante, para tais definições de natureza recursiva, que um algoritmo recursivo seja o melhor caminho para resolver o problema. Os problemas nos quais o uso de algoritmos recursivos deve ser evitado podem ser caracterizados pelo esquema:

~~~
 P = if B then(S,P)
~~~

Programas recursivos correspondem ao módulo anterior dos algoritmos recursivos, são facilmente transformáveis em uma versão não recursiva, a saber:

~~~
 P = (X=Xo; while B do S)
~~~

<strong>Exemplo:</strong> Considere o cálculo dos números de Fibonacci definidos pela seguinte equação de recorrência:

~~~
f(0)=0, f(1)=1;
f(n)=f(n-1)+f(n-2), para n>=2.
~~~

Esses números são assim chamados por terem sido introduzidos por Fibonnaci, matemático italiano no século XII, em publicação de 1202, na qual relacionou a sequência de números produzidos pela recorrência acima com a velocidade de reprodução de coelhos. A sequência inicia com 0,1,1,2,3,5,8,13,21,34,55,..., e possui inúmeras aplicações na matemática, teoria de jogos e ciência da computação. A solução da equação de Fibonacci foi apresentada por Moivre:

<p align = "center">
    <img src="https://ih1.redbubble.net/image.449104528.2396/farp,small,wall_texture,product,750x1000.u2.jpg" width="200"></img>

em que Φ = (1+sqrt(5))/2 = 1,618 é a razão de ouro. Como (-Φ)^(-n) é pequeno quando n é grande (0<Φ^(-1)<1), então o valor de f(n) é aproximadamente Φ^(n)/sqrt(5), que é O(Φ^(n)). Entretanto, a equação é de pouca utilidade prática para o cálculo exato de f(n), pois, quando n cresce, o grau de precisão necessária para calcular os valores de sqrt(5) e Φ fica muito alto.

O método recursivo obtido diretamente na equação de Fibonacci pode ser visto no Programa 2.3. O programa é extremamente ineficiente porque recalcula o mesmo valor várias vezes. 

Programa 2.3 Método recursivo para calcular a sequência de Fibonacci
~~~
if (n<2) return n;
else return (fibRec (n-1) + fibRec (n-2));
~~~

Se considerarmos que a medida de complexidade de tempo f(n) é o número de adições, e o número de chamadas recursivas é O(Φ^n), o número de chamadas colocadas na pilha de recursão é linear, pois equivale a um caminho na árvore de recursividade que vai do nó raiz até um nó folha. Como a árvore de recursividade tem O(Φ^n) nós, e esse caminho tem comprimento igual a altura da árvore, então a complexidade de espaço para calcular f(n) pelo programa 2.3 é O(log Φ^n) = O(n), pois cada chamada recursiva é empilhada e esse número é O(n).

O programa 2.4 apresenta uma versão iterativa para calcular f(n), de acordo com o esquema 2.3.

Programa 2.4 Método iterativo para calcular números de Fibonacci.
~~~
int i=0, f=0;
for(int k=1; k<=n;k++){
  f=i+f;
  i=f-i;
}
~~~

O programa 2.4 tem complexidade de tempo O(n) e complexidade de espaço O(1). Tabela de comparação das estruturas 2.1:

  <table>
   <tr>
    <th>n</th>
    <th>10</th>
    <th>20</th>
    <th>30</th>
    <th>50</th>
    <th>100</th>
   </tr>
    <tr>
    <td>fibRec</td>
    <td>8 ms</td>
    <td>1 s</td>
    <td>2 min</td>
    <td>21 dias</td>
    <td>10^9 anos</td>
   </tr>
    <tr>
    <td>MfibIter</td>
    <td>1/6 ms</td>
    <td>1/3 ms</td>
    <td>1/2 ms</td>
    <td>3/4 ms</td>
    <td>1,5 ms</td>
   </tr>
  </table>
  
 <h2>Algoritmos Tentativa e Erro</h2>
 
 A recursividade pode ser usada para resolver problemas cuja solução é tentar todas as alternativas possíveis. A idéia para algoritmos <strong>tentativa e erro</strong> é decompor o processo em um número finito de subtarefas parciais que devem ser exploradas exaustivamente. O processo geral pode ser visto como um processo de pesquisa ou tentativa que gradualmente constrói e percorre uma árvore de subtarefas conforme mostrado na Figura 2.2. Os algoritmos tentativa e erro não seguem regra fixa de computação, e funcionam da seguinte maneira:
 
<p align = "center">
    <img src="https://algoritmosempython.com.br/images/algoritmos-python/estruturas-dados/Arvore.png" width="200"></img>
    
* Passos em direção à solução final são tentados e registrados;
* Caso esses passos tomados não levem à solução final, eles podem ser retirados e apagados do registro.

Muitas vezes, a pesquisa na árvore de soluções cresce rapidamente; outras vezes, exponencialmente. Nesses casos, a pesquisa na árvore tem de usar <strong>algoritmos aproximados ou heurísticas</strong>, que não garantem a solução ótimo, mas são rápidos. 

<strong>Exemplo:</strong> Passeio do cavalo no tabuleiro de xadrez.

Um caminho para resolver o problema é considerar a possibilidade de realizar o próximo movimento ou verificar que ele não é possível. O Programa 2.5 apresenta um primeiro refinamento do algoritmo que tenta um próximo movimento.

Programa 2.5 Tenta um próximo movimento
~~~
do {
  inicializa seleção de movimentos;
  if (aceitável) {
    registra movimento;
    if (tabuleiro não está cheio) {
      tenta novo movimento; // Chamada recursiva para tentar
      if (não sucedido) apaga registro anterior;
    }
  } while (movimento não sucedido e não acabaram candidatos a movimento);
}
~~~

O tabuleiro pode ser representado por uma matriz n*n. A situação de cada posição do tabuleiro pode ser representada por um inteiro para recordar a história das ocupações:

* t[x,y] = 0 campo <x,y> não visitado,
* t[x,y] = i campo <x,y> visitado no i-ésimo movimento, 1<=i<=n^2.

As regras do xadrez para os movientos do cavalo podem ser vistas na Figura 2.3. A partir de um ponto de partida x,y existem oito pontos de destino possíveis: o primeiro ponto é obtido somando 2 à abscissa x e 1 à ordenada y, o segundo somando 1 à abscissa x e 2 à ordenada y, e assim sucessivamente.

<p align = "center">
    <img src="https://www.soxadrez.com.br/conteudos/movimentos/figuras/tabcavalo.gif" width="200"></img>

O software que resolve o movimento do cavalo pelo tabuleiro é encontrado na pasta código neste repositório.

<h2>Divisão e Conquista</h2>

O paradigma <strong>divisão e conquista</strong> consiste em dividir o problema a ser resolvido em partes menores, encontrar soluções para as partes e então combinar as soluções obtidas em uma solução global. O uso do paradigma para resolver problemas nos quais os subproblemas são versões menores do problema original geralmente leva a solução eficientes e elegantes, em especial quando é utilizado recursivamente.

Para ilustrar a técnica, vamos retomar o problema de encontrar simultaneamente o maior e o menor elemento de um vetor de inteiros, v[0..n-1], n>=1, apresentando uma versão recursiva para a solução do problema.

<strong>Exemplo:</strong> Considere o algoritmo para obter o maior e o menor elemento de um vetor de inteiros v[0..n-1], n>= 1.  <a href="https://github.com/leonardo8787/Algorithms/tree/main/nivio-ziviane-book/2-paradigmas-projeto-algoritmos/codigo/max_mim_recursivo">Clique aqui para ver o código</a>.

Os parâmetros linf e lsup são inteiros, 0<= linf <= lsup <= n-1. O vetor maxMin definido localmente no método maxMin4 é utilizado para retornar nas posições 0 e 1 o maior e o menor elemento do vetor v, respectivamente. O efeito produzido a cada chamada de maxMin4 é o de atribuir as variáveis maxMin[0] e maxMin[1] o maior elemento e o menor elemento em v[linf], v[linf+1], ..., v[lsup], respectivamente.

Seja T(n) uma função de complexidade tal que T(n) é o número de comparações entre os elementos de v, se v contiver n elementos. Logo:

~~~
T(n)=1,                          para n <= 2,
T(n)=T([n/2])+T([n/2])+2,        para n > 2.
~~~

Quando n=2^i, para algum inteiro positivo i, então:

~~~
colar imagem aqui
~~~

Adicionando lado a lado, obtemos:

~~~
colar imagem aqui
~~~

Logo, T(n)=3n/2-2 para o melhor caso, o pior caso e o caso médio.

De acordo com os métodos vistos anteriormente, o algoritmo anterior é ótimo, tendo o mesmo tipo de comportamento do algoritmo MaxMin3 do programa 1.4. Entretanto, na prática, o algoritmo acima deve ser pior do que os algoritmos MaxMin2 e MaxMin3 dos Programas 1.3 e 1.4, respectivamente, podendo até ser pior do que o algoritmo MaxMin1 do Programa 1.2. Conforme vimos anteriormente, na implementação da versão recursiva, a cada chamada para o método maxMin4 o compilador salva em uma estrutura de dados os valores de linf, lsup, maxMin[0] e maxMin[1], além do endereço de retorno da chamada para o método. Além disso, uma comparação adicional é necessária a cada chamada recursiva para verificar se lsup - linf <= 1. Outra observação relevante sobre a implementação acima é que n deve ser menor do que a metade do maior inteiro que pode ser representado pelo compilador a ser utilizado, porque o comando

~~~
 meio = (linf + lsup)/2
~~~

pode provocar overflow na operação linf + lsup.

A técnica divisão e conquista é utilizada para resolver diversos problemas ao longo do livro. Por exemplo, o algoritmo Quicksort para ordenar um conjunto de elementos usa recursividade e divisão e conquista. O Quicksort é um dos algoritmos mais elegantes que existem, além de ser o mais rápido para a maioria das aplicações práticas existentes.

Uma vez que equações de recorrência ocorrem na análise da complexidade de algoritmos recursivos do tipo divisão e conquista, vamos considerar a solução para o caso geral. O teorema apresentado a seguir é denominado teorema mestre em Cormen(2001).

<strong>Teorema Mestre: </strong>Sejam a>=1 e b>1 constantes, f(n) uma funções assintoticamente positiva e T(n) uma medida de complexidade definida sobre os inteiros. A solução da equação de recorrência:

~~~
 T(n)=aT(n/b)+f(n)
~~~

para b uma potência de n é:

~~~
colar imagem aqui
~~~

Falar mais sobre o teorema mestre aqui...

<h2>Balanceamento</h2>

O exemplo usado para ilustrar a técnica divisão e conquista divide o problema em subproblemas de mesmo tamanho. Este é um aspecto importante no projeto de algoritmos: procurar sempre manter o balanceamento na subdivisão de um problema em partes menores. Cabe ressaltar que divisão e conquista não pe a única técnica em que balanceamento é útil. Para ilustrar o princípio do balanceamento, vamos apresentar um exemplo de ordenação e que o contraste entre o efeito de dividir o problema em subproblemas desiguais e o efeito de dividir em subproblemas iguais fique claro.

Considere novamente o exemplo de problema de ordenação apresentado na página 21. O algoritmo seleciona o menor elemento do conjunto v[0..n-1] e então troca este elemento com o primeiro elemento v[0]. O processo é repetido com os n-1 elementos, resultando no segundo maior elemento, que é repetido com o segundo elemento v[1]. Repetindo o processo para n-2, n-3, ..., 2 ordena a sequência. O algoritmo leva à equação de recorrência:

~~~
 T(n) = T(n-1)+n-1 , T(1)=0,
~~~

para o número de comparações realizadas entre os elementos a serem ordenados.

Como vimos anteriormente, um caminho possível para resolver a equação acima é procurar substituir os termos T(k), k<n, no lado direito da equação até que todos os termos T(k), k>1 tenham sido substituídos por fórmulas contendo apenas T(1). No caso da equação acima temos:

~~~
colar imagem aqui
~~~

Adicionando lado a lado, obtemos:

~~~
  T(n) = T(1) + 1 + 2+ ... + n - 1 = n(n-1)/2
~~~

Logo, o algoritmo é O(n²).

Embora o algoritmo possaser visto como uma aplicação recursiva de divisão e conquista, ele não é eficiente para valores grandes de n. Para se obter um algoritmo de prdenação assintoticamente eficiente, é necessário conseguir um balanceamento. Em vez de dividir um problema de tamanho n em dois subproblemas, um de tamanho 1 e outro de tamanho n-1, o ideal é dividir o problema em dois subproblemas de tamanhos aproximadamente iguais.

<strong>Exemplo:</strong> A operação de unir dois arquivos ordenados gerando um terceiro arquivo ordenado é denominada intercalação (merge). Essa operação consiste em colocar no terceiro arquivo o menor elemento entre os menores dos dois arquivos iniciais, desconsiderando esse mesmo elemento nos passos posteriores. Esse processo deve ser repetido até que todos os elementos dos arquivos de entrada sejam escolhidos.

Essa ideia pode ser utilizada para construir um algoritmo de ordenação. O processo é o seguinte: dividir recursivamente o vetor a ser ordenado em dois vetores até obter n vetores de um único elemento. Aplicar o algoritmo de intercalação tendo como entrada dois vetores de um elemento e formando um vetor ordenado de dois elementos. Repetir esse processo formando vetores ordenados cada vez maiores até que todo o vetor esteja ordenado. Na literatura, esse método é conhecido como <strong>Mergesort.</strong>

Para saber mais sobre mergesort acesse o site: https://www.geeksforgeeks.org/merge-sort/ ou vâ para o diretório que trata sobre estruturas de dados básicas.

O algoritmo mergesort tem O(n*log n).

<h2>Programação Dinâmica</h2>

Recursividade é uma técnica muito útil quando o problmea a ser resolvido pode ser dividido em subproblemas a um custo não muito grande e os subproblemas podem ser mantidos pequenos. Por exemplo, quando a soma dos tamanhos dos subproblemas é O(n), então é possível que o algoritmo recursivo tenha complexidade polinomial. Em contrapartida, quando a divisão de um problema de tamanho n resulta em n subproblemas de tamanho n-1, então é provável que o algoritmo recursivo tenha complexidade exponencial.

Quando o algoritmo recursivo tem complexidade exponencial, a técnica de programação dinâmica pode levar a um algoritmo mais eficiente. A programação dinâmica calcula a solução para todos os subproblemas, partindo dos subproblemas menores para os maiores, armazenando os resultados em uma tabela. A vantagem do método está no fato de que uma vez que um subproblema é resolvido, a resposta é armazenada em uma tabela e o subproblema nunca mais é recalculado.

Aho, Hopcroft e Ullman (1974) ilustram a técnica de programação dinâmica por meio de um exemplo sobre a avaliação do produto de n matrizes

~~~
  M = M1 * M2 * ... * Mn
~~~

em que cada Mi é uma matriz com d_i-1 linhas e di colunas. A ordem na qual as matrizes são multiplicadas pode ter um efeito enorme no número total de operações de adição e multiplicação neccessárias para obter M, conforme se verifica no exemplo a seguir.

<strong>Exemplo:</strong> Considere o produto de uma matriz p*q por outra matriz q*r cujo algoritmo requer O(prq) operações. O algoritmo é resolvido <a href="https://github.com/leonardo8787/Algorithms/tree/main/nivio-ziviane-book/2-paradigmas-projeto-algoritmos/codigo/ordem_mult_matriz">aqui</a>.

<h2>Referências</h2>

* Projeto de Algoritmos, Nivio Ziviani.
