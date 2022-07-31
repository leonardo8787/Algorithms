<h2>Estruturas de dados basicas</h2>

<strong>Súmario</strong>

* Listas Lineares
* Pilhas
* Filas

<h2>Listas Lineares</h2>

Uma das formas mais simples de interligar os elementos de um conjunto é por meio de uma lista. Lista é uma estrutura em que as operações inserir, retirar e localizar são definidas. Listas são estruturas muito flixíveis, porque podem crescer ou diminuir de tamanho durante a execução de um programa, de acordo com a demanda. Itens podem ser acessados, inseridos ou retirados de uma lista. Duas listas podem ser concatenadas para formar uma lista única, assim como uma lista pode ser partida em duas ou mais listas.

Listas são adequadas para aplicações nas quais não é possível prever a demanada por memória, permitindo a manipulação de quantidades imprevisíveis de dados, de formato também imprevisível. Listas são úteis em aplicações tais como manipulação simbólica, gerência de memória, simulação e compiladores. Na manipulação simbólica, os termos de uma górmula podem crescer sem limites. Em simulação dirigida por relógio, pode ser criado um número imprevisível de processos, que têm de ser escalonados para execução de acordo com alguma ordem preferida.

Uma lista linear é uma sequência de zero ou mais itens x1, x2,...,xn, na qual xi é de determinado tipo e n representa o tamanho de lista linear. Sua principal propriedade estrutural envolve as posições relativas dos itens em uma dimensão. Assumindo que n>= 1, x1 é o primeiro item da lista, e xn é o último item da lista. Em geral, xi precede x_i+1 para i=1,2,...,n-1, e xi suceded x_i-1 para i=2,3,...,n, e o elemento xi é dito estar na i-ésima posição da lista.

Para criar um tipo abstrato de dados Lista, é necessário definir um conjunto de operações sobre os objetos do tipo Lista. O conjunto de operações a ser definido depende de cada aplicação, não existindo um conjunto de operações que sejam adequadas a todas as aplicações. Um conjunto de operações necessário à maior parte das aplicações é apresentado a seguir. Outras sugestões para o conjunto de operações podem ser encontradas em Knuth e Aho Hopcroft e Ullman.

 1. Criar uma lista linear vazia.
 2. Inserir um novo item imediatamente após o i-ésimo item.
 3. Retirar o i-ésimo item,
 4. Localizar o i-ésimo item para examinar e/ou alterar o conteúdo de seus componentes.
 5. Combinar duas ou mais listas lineares em uma lista única.
 6. Partir uma lista linear em duas ou mais listas.
 7. Fazer uma cópia da lista linear.
 8. Ordenar os itens da lista em ordem ascendente ou descecndente, de acordo com alguns de seus componentes.
 9. Pesquisar a ocorrência de um item com um valor particular em algum componente.
 
Existem várias estruturas de dados que podem ser usadas para representar listas lineares, cada uma com vantagens e desvantagens particulares. As duas representações mais utilizadas são as implementações por meio de arranjos e de estruturas auto-referenciadas. A implementação mediante cursores pode ser útil em algumas aplicações.

<strong>Implementação de Listas por meio de Arranjos</strong><p>

Em um tipo estruturado arranjo, os itens da lista são armazenados em posições contíguas de memória. Nesse caso, a lista pode ser percorrida em qualquer direção. A inserção de um novo item pode ser realizada após o último item com o custo constante. A inserção de um novo item no meio da lista requer um deslocamento de todos os itens localizados após o ponto de inserção. Da mesma forma, retirar um item do início da lista requer um deslocamento de itens para preencher o espaço deixado vazio.

Figura 3.1 Implementação de uma lista mediante arranjo.
~~~

~~~

A estrutura da lista usando arranjo e uma possível implementação para as nove operações definidas anteriormente para o tipo abstrato de dados Lista são mostrados no <a href="https://github.com/leonardo8787/Algorithms/tree/main/nivio-ziviane-book/2-paradigmas-projeto-algoritmos/codigo/lista_arranjo">software</a>. Na estrutura da lista usando arranjo, o campo item é o principal componente da classe Lista. Os itens são armazenados em um arranjo de tamanho suficiente para armazenar a lista. O campo ultimo da classe Lista contém uma referência para a posição seguinte a do último elemento da lista. O (i+1)-ésimo item da lista está armazenado na i-ésima posição do arranjo,  0<=i<ultimo. O campo pos é utilizado para armazenar a posição corrente na lista. A constante maxTam passada como parâmetro no construtor da classe define o tamanho máximo permitindo para a lista.

A estrutura de dados é encapsulada na classe Lista por meio da utilização do modificador private, enquanto as intefaces dos operadores tornam-se visíveis por meio do modificador public. Assim, podemos modificar tanto a estrutura de dados quanto a implementação das operações sem provocar alterações nos programas que utilizam a classe Lista, desde que as intefaces dos operadores sejam preservadas.

Observe que a operação de criar uma lista vazia é implementada utilizando o construtor da classe que representa o tipo abstrato de dados Lista. Outro aspecto a ressaltar é que a classe Lista é constituída de objetos genéricos. Um objeto genérico em Java é um objeto que pode ser de qualquer tipo. Por exemplo, o tipo de cada item a ser inserido na lista é definido na aplicação no momento de cada inserção. Entretanto, essa liberdade de ter objetos de tipos diferentes em uma mesma lista obriga o usuário da lista a especificar o tipo do objeto a ser retirado. Um objeto genérico é implementado por meio de classe Object.

A implementação de listas por meio da arranjos tem como vantagem a economia de memória, pois os apontadores são implícitos nessa estrutura. Como desvantagens citamos: (i) o custo para inserir ou retirar itens da lista, que pode causar um deslocamento de todos os itens, no pior caso; (ii) em aplicações em que não existe previsão sobre o crescimento da lista, a utilização de arranjos pode exigir a realocação de memória. Essa é uma operação de alto custo em termos de tempo e de memória, pois é preciso alocar uma nova área com mais posições do que a atual e copiar todos os itens para ela.

<h2>Pilhas</h2>

<h2>Filas</h2>

<h2>Referências</h2>
