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

<h2>Referências</h2>

* Projeto de Algoritmos, Nivio Ziviani.
