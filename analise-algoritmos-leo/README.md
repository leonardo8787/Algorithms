<h2>Introdução à análise de algoritmos</h2>

<strong>Algortimo:</strong> Sequência finita de passos descritos de forma não ambígua que corretamente resolvem um problema.

<strong>Análisar um algoritmo:</strong> Nos permite prever comportamento e desempenho sem que seja necessário implementá-lo em um dispositivo específico.

<h2>Corretude (Algoritmos iterativos)</h2>

Um algortimo está correto quando devolve uma resposta correta para qualquer instância. Então ele está incorreto quando devolve uma resposta errada para alguma instância.
 
<strong>Prova por invariante de laço</strong><p>

<strong>Definição: </strong>Uma invariante de laço é uma afirmação que é verdadeira no início de qualquer iteração do laço. Em geral começam com "antes da t-ésima iteração começar, vale que ..." e envolvem variáveis importantes para o laço. Notação: P(t). São úteis quando nos permitem concluir algo importante após o término do laço. 

<strong>Como provar que uma frase é uma invariante ?</strong><p>

Por definição, basta provar que P(1), P(2), ... , P(T+1) são verdadeiras, onde T é a quantidade de iterações realizadas. P(T) diz algo válido no início da última iteração, mas no decorrer dela as coisas podem mudar. P(T+1) diz algo válido no início de uma iteração que não existe, ou seja, no fim do laço.

 
