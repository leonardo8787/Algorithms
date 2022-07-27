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



<h2>Referências</h2>

* Projeto de Algoritmos, Nivio Ziviani.
