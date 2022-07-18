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
 
 <strong>Exemplo: cálculo do tempo da buscaLinear(A, n, k)</strong>
 
 ~~~
                                           Se há elemento c/ chave       Se não há
 1  i=1                                         = t                           t
 2  enquanto i<=n e A[i].chave != k faça        = 5t*pk                       t(n+1)+4tn
 3   i=i+1                                      = 2t(pk-1)                    2tn
 4  se i<=n e A[i].chave == k então             = 5t                          5t
 5   devolve i                                  = t                                     
 6  devolve -1                                  =                             t
 ~~~

t=tempo de um passo básico.<p>

<strong>Se o elemento existe:</strong> t+5tpk+2t(pk-1)+6t = 7pk+5t<p>
<strong>Se o elemento não existe:</strong> t+t(n+1)+4tn+2tn+6t = 7t<p>

Na linha 3 do pseudocódigo acima, é dada a seguinte expressão:
~~~
enquanto i<=n e A[i].chave != k faça
~~~

Nela é possível retirar os seguintes casos: compara se n é maior que i, operação AND, acesso ao vetor, acesso a chave e operação de diferença. O que soma 5 processos ocorrendo na mesma linha, ou seja, o custo associado é (5t), entretanto não se sabe quantas vezes o processo será repetido, assim é multiplicado a ele o (pk), assim o custo associado a está linha é (5t*pk).

Já a linha 4 não recebe o mesmo valor de custo visto que ela é um IF, ou seja, um operador de decisão, assim o custo associado a ele é (pk=1), portanto o custo da linha 4 é 5t. 

<strong>Outro exemplo de cálculo do tempo</strong>

~~~
BuscaBinaria(A,n,k)
1  esq = 1                                t
2  dir = n                                t
3  enquanto esq < dir faça                tr
4    meio = [(esq+dir)/2]                 4t(r-1)
5    se k>A[meio].chave então             3t(r-1)
6      esq = meio + 1                     2t
7    senão                                2t
8      dir = meio                         2t
9  se A[esq].chave == k então             4t
10   devolve esq                          t
11 devolve -1                             t
~~~

r = quantidade de vezes que o teste da linha 3 executa.

<strong>Custo total:</strong> 10tr-3t

<strong>Resumo</strong><p>

<table>
 <tr>
  <th>Elemento</th>
  <th>Busca Linear</th>
  <th>Busca Binária</th>
 </tr>
 <tr>
  <td>Elem. em A</td>
  <td>7tpk+5t</td>
  <td>10tr-3t</td>
 </tr>
  <tr>
  <td>k=A[1].chave</td>
  <td>12t</td>
  <td>10t[lg n]+17t</td>
 </tr>
  <tr>
  <td>k=A[n/2].chave</td>
  <td>(7tn/2)+5t</td>
  <td>10t[lg n]+17t</td>
 </tr>
  <tr>
  <td>k=A[n].chave</td>
  <td>7tn+5t</td>
  <td>10t[lg n]+17t</td>
 </tr>
  <tr>
  <td>Não há elem. am A</td>
  <td>7tn+8t</td>
  <td>10t[lg n]+17t</td>
 </tr>
</table>

Na busca linear, o tempo depende de onde está o elemento no vetor. Já no caso da busca binária, independentemente de onde esteja o elemento o custo vai ser o mesmo. 

Se T(n) é o tempo de uma entrada qualquer de tamanho n, 
~~~
Tempo no melhor caso   <=   T(n)   <=    Tempo no pior caso 
~~~
Portanto esses tempos nos dão garantias.

* 12t <= Tempo da busca linear <= 7tn+8t
* 10t*lg(n)+7t  <=  Tempo da busca binária  <= 10t*lg(n)+17t

<strong>Análise por casos</strong><p>
 
Definição: O tempo de caso médio de um algoritmo é a média do tempo de execução de todas as instancias de tamanho n. Consideramos algo sobre a distribuição das entradas e fazemos uma análise probabilística. Pode ser tão ruim quanto o pior caso. Análises de caso médio costumam ser mais complicadas.
 
 ~~~
 enquanto i<= e A[i].chave != faça             
 ~~~
              
 o caso médio do algoritmo de busca linear é atribuida pelo calculo médio de seu laço, sendo assim temos P(n/2), portanto o resultado do custo é (7tn+17t)/2.
              
<strong>Bons algoritmos</strong><p>
 
 Definição: Um algoritmo é eficiente se seu tempo de execução no pior caso puder ser descrito por uma função que é limitada superiormente por uma função polinomial no tamanho da entrada.
 
Testando para a busca binária temos:
~~~
 T(n)=10t*lg(n)+17t <= 10tn+17t
~~~
Neste caso a função 10t*lg(n)+17t pode ser limitada por 10t*n+17t visto que n é maior que lg(n), assim a busca binária é eficiente pois o pior caso é polinomial. 
                              
Comparando a busca binária com a busca linear podemos perceber que a busca binária é melhor do que a busca linear visto que a busca binária tem crescimento logaritmico e a busca linear tem crescimento constante.
                              
![comparação de crescimento linear e logaritmico](https://s1.static.brasilescola.uol.com.br/be/e/Untitled-3(47).jpg)

                              
<h2>Notação Assintótica(Big O)</h2>

É uma abstração que nos permite focar no que ocorre com f(n) quando n cresce indefinidamente. 
* A menor ordem não importa. 
* Constantes não importam.

