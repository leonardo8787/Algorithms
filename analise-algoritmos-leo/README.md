<h2>Introdução à análise de algoritmos</h2>

<strong>Algortimo:</strong> Sequência finita de passos descritos de forma não ambígua que corretamente resolvem um problema.

<strong>Análisar um algoritmo:</strong> Nos permite prever comportamento e desempenho sem que seja necessário implementá-lo em um dispositivo específico.


<h2>Corretude (Algoritmos iterativos)</h2>

Um algortimo está correto quando devolve uma resposta correta para qualquer instância. Então ele está incorreto quando devolve uma resposta errada para alguma instância.
 
<strong>Prova por invariante de laço</strong><p>

<strong>Definição: </strong>Uma invariante de laço é uma afirmação que é verdadeira no início de qualquer iteração do laço. Em geral começam com "antes da t-ésima iteração começar, vale que ..." e envolvem variáveis importantes para o laço. Notação: P(t). São úteis quando nos permitem concluir algo importante após o término do laço. 

<strong>Como provar que uma frase é uma invariante ?</strong><p>

Por definição, basta provar que P(1), P(2), ... , P(T+1) são verdadeiras, onde T é a quantidade de iterações realizadas. P(T) diz algo válido no início da última iteração, mas no decorrer dela as coisas podem mudar. P(T+1) diz algo válido no início de uma iteração que não existe, ou seja, no fim do laço.

<h2>Tempo de Execução</h2>
 
Vários fatores afetam o tempo de execução de um programa, sendo eles: computadores mais/menos potentes, instâncias pequenas/grandes, sistema operacional, linguagem de programação, estrutura de dados, etc.
 
 <strong>Definição:</strong> O tempo de execução de um algoritmo é a quantidade de passos básicos executados por ele sobre uma instância de entrada. O tempo tende a crescer conforme o tamanho da entrada cresce, e por isso usamos uma função nesse tamanho para descrevê-lo: T(n). O tamanho da entrada varia com o problema: Vetor, quantidade de elementos; número, quantidade de bits na representação binária.
 
 Exemplo: cálculo do tempo da buscaLinear(A, n, k)
 
 ~~~
                                           Se há elemento c/ chave       Se não há
 i=1                                         = t                           t
 enquanto i<=n e A[i].chave != k faça        = 5t*pk                       t(n+1)+4tn
  i=i+1                                      = 2t(pk-1)                    2tn
 se i<=n e A[i].chave == k então             = 5t                          5t
  devolve i                                  = t                                     
 devolve -1                                  =                             t
 ~~~

t=tempo de um passo básico.<p>

<strong>Se o elemento existe:</strong> t+5tpk+2t(pk-1)+6t = 7pk+5t<p>
<strong>Se o elemento não existe:</strong> t+t(n+1)+4tn+2tn+6t = 7t<p>
