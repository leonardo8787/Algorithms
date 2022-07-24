<h1>O que são algoritmos?</h1>

Al-Khorezmi nunca pensou que seu apelido, que significa "um nativo de Khorezmi", seria a origem de palavras mais importantes do que ele mesmo, como álgebra, logaritmo e algoritmo. Graças a esse pouco conhecido matemático árabe do século IX, hoje temos conhecimento de conceitos tão básicos quanto o número Zero da Índia ou boa parte da matemática desenvolvida na Grécia.

E sobre algoritmos? Algoritmos e estruturas de dados formam o núcleo da ciência da computação, sendo os componentes básicos de qualquer software. Ao mesmo tempo, aprender como programar está intimamente ligado a algoritmos, já que um algoritmo é a abstração de um programa. Logo, aprender algoritmos é crucial para qualquer pessoa que deseja desenvolver software de qualidade.

Paradigmas de programação estão naturalmente associados a técnicas de projeto e disciplinas introdutórias de ciência da computação são usualmente disciplinas de introdução a algoritmos. Inicialmente, a concepção de algoritmos necessita apenas de técnicas básicas de programação. Quando a complexidade dos problemas e sua análise tornam-se importantes, como no caso deste livro, algoritmos requerem lógica, matemática discreta e alguma fundamentação teórica do tipo teoria de autmatos e linguagens formais.

Entretanto, aprender algoritmos não é fácil, uma vez que precisamos ter a combinação correta de conhecimentos matemáticos e de bom senso. Citando Knuth, a melhor teoria e inspirada na prática e a melhor prática é inspirada na teoria. O balanceamento entre teoria e prática é sempre uma tarefa difícil.

<h2>Medida de tempo de execução de um programa</h2>

O projeto de algoritmos é fortemente influenciado pelo estudo de seus comportamentos. Depois que um problema é analisado e decisões de projeto são finalizadas, o algoritmo tem de ser implementado em um computador. Neste momento, o projetista deve estudar as várias opções de algoritmos a serem utilizados, em que os aspectos de tempo de execução e espaço ocupado são considerações importantes. Muitos desses algoritmos são encontrados em áreas tais como pesquisa operacional, otimização, teoria dos grafos, estatística, probabilidade, entre otras.

Na área de análise de algoritmos, existem dois tipos de problema bem distintos, conforme apontou Knuth(Matemático).

(i) <strong>Análise de um algortimo particular:</strong> Qual é o custo de usar um dado algoritmo para resolver um problema específico? Neste caso, características importantes do algortimo em questão devem ser investigadas. Geralmente faz-se uma análise do número de vezes que cada parte do algoritmo deve ser executada, seguida do estudo da quantidade de memória necessária.

(ii) <strong>Análise de uma classe de algortimos:</strong> Qual é o algoritmo de menor custo passível para resolver um problema particular? Neste caso, toda uma faília de algoritmos para resolver um problema específico é investigada com o objetivo de identificar um que seja o melhor possível. Isso significa colocar limites para a complexidade computacional dos algoritmos pertencentes à classe.

Em muitos casos podem existir vários algortimos para resolver o mesmo problema, sendo necessário escolher o melhor. Se a mesma medida de custo é usada para todos os algortitmos, então é possível dizer qual é o melhor.

O custo de utilização de um algoritmo pode ser definido por várias maneiras, uma delas é mediante a execução de um computador real, sendo o tempo de execução medido diretamente. Entretanto, este método de medida trás imprecissões, visto que máquinas diferentes vão se comportar de maneiras diferentes, a partir de suas configurações de hardware, um exemplo disso é colocar um programa com uma determinada quantia de memória RAM para executar um programa e outro computador com uma quantidade de RAM menor, assim com um programa pesado o computador mais robusto, em termos de memória, vai se sobressair. No entanto tal medida não condiz com a realidade. O ideal é medir diretamente num computador o tempo de execução de um algoritmo apenas quando os algoritmos a serem analisados pertençam a mesma familia de custo computacional, assim por meio de várias execuções vai ser possível notar qual o melhor programa para determinada tarefa.

Ilustrando todos esses conceitos vistos acima, considere o algoritmo para encontrar o maior elemento de um vetor de inteiros v[0 ... n-1], n >= 1, implementado em C++. Seja "f" uma função de complexidade tal que f(n) é o número de comparações entre os elementos de v, se v contiver n elementos. Logo,

<p align = "center">
    f(n)=n-1, para n > 0
</p>

~~~
#ifndef MAX_H_
#define MAX_H_
namespace cap1 {
  class Max {
  public:
    static int max (int v[], int n);
  };
  int Max::max (int v[], int n) {
    int max = v[0];
    for (int i=1; i<n; i++){
      if(max < v[i]){
        max = v[i];
      }
    }
  }
  return max;
}
~~~

Qualquer algoritmo para encontrar o maior elemento de um conjunto com n elementos, n>=1, faz pelo menos n-1 comparações.

A medida do custo de custo de execução de um algoritmo depende principalmente do tamanho da entrada dos dados. Por isso, é comum considerar o tempo de execução de um programa como uma função do tamanho da entrada. Entretanto, para alguns algoritmos, o custo de execução é uma função da entrada particular dos dados, não apenas do tamanho da entrada. Como há a possibilidade do vetor estar ordenado no princípio da execução, assim o custo do software será menor,tendo isso em vista deve haver três possibilidades de custo para um algoritmo, sendo eles o melhor caso, o caso médio e o pior caso, que se trata da maior execução que o software enfrentará.

O caso médio (ou caso esperado) corresponde à média dos tempos de execução de todas as entradas de tamanho n. Na análise do caso esperado, uma distribuição de probabilidades sobre o conjunto de entradas de tamanho n é suposta, e o custo médio é obitido com base nessa distribuição. Por essa razão, a análise do caso médio é geralmente muito mais difícil de obter do que as análises do melhor e do pior caso. É comum supor uma distribuição de probabilidades em que todas as entradas possíveis são igualmente prováveis. Entretanto, na prática isso nem sempre é verdade. Por isso, a análise do caso esperado dos algoritmos a serem estudados só será apresentada quando esta fizer sentido.

 <strong>Um caso de melhora de um algoritmo:</strong> Algoritmo de busca 1.1
 
 <p align = "center">
    <strong>melhor caso : f(n)=1</strong>
</p>


<p align = "center">
    <strong>pior caso   : f(n)=n</strong>
</p>


<p align = "center">
    <strong>caso médio  : f(n)=(n+1)/2</strong>
</p>
 
 ~~~
 #ifndef MAXMIN1_H_
 #define MAXMIN1_H_
 
 namespace cap1 {
    class MaxMin1 {
       public:
        static int *maxMin1(int v[], int n);
    };
    int* MaxMin::maxMin1(int v[], int n){
        int max=v[0], min=v[0];
        for(int i=1; i<n; i++){
            if(v[i] > max) max = v[i];
            if(v[i] < max) max = v[i];
        }
        int *maxMin=new int[2];
        maxMin[0] = max;
        maxMin[1] = min;
        return maxMin;
    }
 }
 
 #endif
 ~~~
 
 O programa pode ser facilmente melhorado. Basta observar que a comparação v[i] < min somente é necessária quando o resultado da comparação v[i] > max é falso. Uma nova versão do algoritmo pode ser vista no programa abaixo. Nessa implementação, os casos de execução são:
 
 
<p align = "center">
    <strong>melhor caso : f(n)=n-1</strong>
</p>


<p align = "center">
    <strong>pior caso   : f(n)=2(n-1)</strong>
</p>


<p align = "center">
    <strong>caso médio  : f(n)=3n/2-3/2</strong>
</p>

O melhor caso ocorre quando os elementos de v estão em ordem rescente. O pior caso ocorre quando os elementos de v estão em ordem decrescente. No caso médio, v[i] é maior do que max a metade das vezes. Logo,

<p align = "center">
    <strong>f(n) = n-1 + (n-1)/2 </strong>
</p>
<p align = "center">
    <strong>f(n) = 3n/2 - 3/2 </strong>
</p>
 
 Algoritmo de busca 1.2
 
 ~~~
 
 #ifndef MAXMIN1_H_
 #define MAXMIN1_H_
 
 namespace cap1 {
    class MaxMin1 {
       public:
        static int *maxMin1(int v[], int n);
    };
    int* MaxMin::maxMin1(int v[], int n){
        int max=v[0], min=v[0];
        for(int i=1; i<n; i++){
            if(v[i] > max) max = v[i];
            else if(v[i] < max) max = v[i];
        }
        int *maxMin=new int[2];
        maxMin[0] = max;
        maxMin[1] = min;
        return maxMin;
    }
 }
 
 #endif
 ~~~

O segundo algoritmo é melhor pelo fato de o custo de execução ter um leve declínio graças ao 'else' dentro do 'for', ele implica num menor custo mínimo e/ou médio de execução do algoritmo.

Considerando o número de comparações realizadas, existe a possibilidade de obter um algoritmo mais eficiente para este problema ? A resposta é sim. Considerando o seguinte algoritmo:

1) Compare os elementos de v aos pares, separando-os em dois subconjuntos de acordo com o resultado da comparação, colocando os maiores em um subconjunto e os menores no outro, conforme mostrado no código 1.1 , a um custo de (n/2)² comparações.
2) O máximo é obitido do subconjunto que contém os maiores elementos, a um custo de (n/2)-1 comparações.
3) O mínimo é obtido do subconjunto que contém os menores elementos, a um custo de (n/2)-1 comparações.

Implementação 1.4, melhor para obter máximo e mínimo.

~~~
 #ifndef MAXMIN1_H_
 #define MAXMIN1_H_
 
 namespace cap1 {
    class MaxMin1 {
       public:
        static int *maxMin3(int v[], int n);
    };
    int* MaxMin::maxMin1(int v[], int n){
        int max, min, FimDoAnel;
        if((n%2)>0){v[n]=v[n-1]; FimDoAnel=n;}
        else FimDoAnel=n-1;
        if(v[0]>v[1]){ max=v[0]; min=v[1]}
        else { max=v[1]; min=v[0];}
        int i=2;
        while(i<FimDoAnel){
            if(v[i]>v[i+1]){
                if(v[i] > max) max=v[i];
                if(v[i-1] < min) min=v[i+1];
            }
            else {
                if(v[i] < min) min = v[i];
                if(v[i-1] > max) max = v[i+1];
            }
            i=i+2;
        }
        int *maxMin = new int[2];
        maxMin[0] = max; maxMin[1] = min;
        return maxMin;
    }
 }
 
 #endif
~~~

Os elementos de v são comparados dois a dois, os elementos maiores  são comparados com max e os elementos menores são comparados com min. Quando n é ímpar, o elemento que está na posição v[n-1] é duplicado na posição v[n] para evitar um tratamento de exceção. Para issa implementação,

<p align = "center">
    <strong>f(n) = n/2 + (n-2)/2 + (n-2)/2 </strong>
</p>
<p align = "center">
    <strong>f(n) = 3n/2 - 2 </strong>
</p>

<strong>Comparação de algoritmos para obter o máximo e o mínimo de uma sequência</strong>

<table>
 <tr>
  <th>Algoritmos</th>
  <th>Melhor caso</th>
  <th>Pior caso</th>
  <th>Caso médio</th>
 </tr>
  <tr>
      <td>MaxMin 1</td>
  <th>2(n-1)</th>
  <th>n-1</th>
  <th>3n/2 - 2</th>
 </tr>
  <tr>
      <td>MaxMin 2</td>
  <td>2(n-1)</td>
  <td>2(n-1)</td>
  <td>3n/2 - 2</td>
 </tr>
  <tr>
       <td>MaxMin 3</td>
  <td>2(n-1)</td>
  <td>3n/2 - 3/2</td>
  <td>3n/2 - 2</td>
 </tr>
</table>

<h2>Comportamento Assintótico de Funções</h2>

Uma função f(n) domina assintoticamente outra função g(n) se existem duas constantes positivas 'c' e 'm' tais que, para n >= m, temos |g(n)| <= c*|f(n)|.

![domínio assintótico de uma função sobre outra](
https://th.bing.com/th/id/R.cf5ceaa0088f6eaccaba71e18015149b?rik=6w%2fIJrETQWVL5A&riu=http%3a%2f%2fwww.wdz.eng.br%2fWDK%2fDominioAssintotico.jpg&ehk=rIg5YpUz6BgHSxMxI02XouWJO1diV4XzJxZBj5vejPU%3d&risl=&pid=ImgRaw&r=0)

<strong>Definição notação Big O</strong>

Usamos a notação big-Θ para limitar de forma assintótica o crescimento do tempo de execução com fatores constantes acima e abaixo. Algumas vezes, vamos querer limitar somente acima. Por exemplo, embora o tempo de execução do pior caso da busca binária seja (log_2 n), seria incorreto dizer que a busca binária é executada em O(log_2 n) em todos os casos. E se encontrarmos o valor procurado no primeiro chute? Então o programa é executado em O(1). O tempo de execução da busca binária nunca é pior que O(log_2 n), mas algumas vezes ele é melhor.

Seria conveniente ter uma forma de notação assintótica que diga "o tempo de execução cresce no máximo até um determinado valor, mas poderia crescer mais devagar". A notação "big-O" serve para essas ocasiões. Se um tempo de execução é O(f(n)), então para um f(n) suficientemente grande , o tempo de execução é no máximo k f(n)k⋅f(n)k, para alguma constante k. Veja como pensar em um tempo de execução que é O(f(n)):

![big O](https://i.stack.imgur.com/WcBRI.png)

Dizemos que o tempo de execução é "big-O de f(n)" ou apenas "O de f(n)" Usamos a notação big-O para limites assintóticos superiores, uma vez que ela limita o crescimento do tempo de execução superior para valores sufientemente grandes de entrada. Agora temos uma forma de caracterizar o tempo de execução da busca binária em todos os casos. Podemos dizer que o tempo de execução da busca binária é sempre O(log_2 n). Podemos fazer uma afirmação mais forte sobre o tempo de execução no pior caso: ele é O(log_2 n). No entanto, se quisermos cobrir todos os casos, a afirmação mais forte que podemos fazer é que a busca binária executa em tempo O(log_2 n).

<strong>Definição notação small O</strong>

Little O (o ()) descreve o limite superior excluindo o limite exato.

<strong>Definação notação Ômega</strong>

Assim como na Notação O, estamos interessados em inferir o crescimento do tempo/espaço de execução de um determinado algoritmo. No entanto, ao invés de olharmos para uma função que é o limite superior do algoritmo estudado, estamos olhando o limite inferior. Essa é a grande diferença. Assim, quando uma função f(n) é limitada inferiormente por outra função g(n), dizemos que a complexidade de tempo/espaço de f(n) é Ω( g(n) ). Ou seja, com limite inferior em g(n). E o que isto significa na prática? Significa que a função f(n) nunca será mais rápida (menor) do que a função g(n). Esta é a interpretação da Notação Ω.  Assim como apresentado na imagem acima onde cg(n) é o limite inferior de f(n). Um exemplo prático disso seria qualquer algoritmo de ordenação. No geral, os melhores algoritmos de ordenação tem complexidade média em O(n log n). No entanto, podemos afirmar também que qualquer algoritmo de ordenação será Ω(n), pois até hoje não há uma solução de ordenação que no mínimo, não seja obrigada a visitar todos os n elementos a serem ordenados ao menos uma vez. Logo, limitados inferiormente por Ω(n). Nunca mais rápidos ou eficientes do que isto. De forma muito parecida com a definição formal da Notação O, a Notação ômega trabalha com os limites de uma função em relação à outra. Neste caso, o limite inferior. Podemos interpretar então como: a função f(n) cresce no mínimo na ordem de g(n) para qualquer valor da entrada n que seja maior ou igual a n0. 

<strong>Definação notação Theta</strong>

Quando falamos em Notação Θ, estamos falando simultaneamente das notações O e Ω, pois a Notação Theta descreve o comportamento assintótico de funções definindo ao mesmo tempo um limite superior e um limite inferior para a execução de um determinado algoritmo. 

![](https://notesformsc.org/wp-content/uploads/2018/07/Theta-Notation.png)

Por exemplo na figura acima temos um algoritmo representado pela função f(n) sendo analisado e temos que ele é Θ( g(n) ), pois a função g(n) limita f(n) por cima e por baixo por apenas deslocando a função g(n) através das constantes c1 e c2. Iremos compreender isto melhor neste artigo. Mas até aqui, o importante é entender que Θ( g(n) ) é a interseção entre O( g(n) ) e Ω( g(n) ). Vamos tomar como exemplo o algoritmo Merge Sort. O pior caso de sua execução é tanto O(n log n) quanto Ω(n log n). Logo, podemos afirmar ele é Θ(n log n). No entanto, nós podemos afirmar também que este algoritmo é O(n²), uma vez que n² é assintoticamente maior (está acima) do que n log n. Por outro lado, não podemos dizer que ele seja Ω(n²). Logo, ele não é Θ(n²). Ou seja, n² é um limite superior mas não um limite inferior, portante não satisfaz a notação Θ.

A notação theta  é uma espécie de junção das notações O e ômega. Ao invés de utilizarmos uma constante c1, agora utilizaremos duas constantes: c1 e c2. Essas constantes mostram como apenas deslocando a curva no gráfico conseguimos ver que uma função é ao mesmo tempo os limites superiores e inferiores da função estuda. Formalmente falando, temos que:

<h3>Resumo</h3>

* <strong>Big O:</strong> Descreve o limite superior da complexidade.
* <strong>Omega Ω:</strong> Descreve o limite inferior da complexidade.
* <strong>Theta Θ:</strong> Descreve o limite exato da complexidade.
* <strong>Little O:</strong> Descreve o limite superior excluindo o limite exato.

![relações de complexidade](https://www.freecodecamp.org/portuguese/news/content/images/2021/12/1_O-dcXbYXojkAPEnDuVZMvA.png)

<h3>Comparação de complexidade entre Big Os típicas</h3>

Quando tentamos descobrir a Big O para uma função g(n) específica, nos preocupamos apenas com o termo dominante da função. O termo dominante é o termo que cresce mais rápido. Por exemplo, n² cresce mais rápido que n. Assim, se tivermos algo como g(n)=n²+5n+6, teremos uma big O(n²). Se você já fez cálculo no passado, isso é muito semelhante a achar o atalho para encontrar limites para polinômios fracionários, onde você só se importa com o termo dominante para numeradores e denominadores no fim.

![](https://www.freecodecamp.org/portuguese/news/content/images/2021/12/0_MPwgKd4lgXACfuNt.png)

Mas qual função cresce mais rápido do que as outras ? Existem, de fato, algumas regras.

![](https://www.freecodecamp.org/portuguese/news/content/images/2021/12/1_KfZYFUT2OKfjekJlCeYvuQ.jpeg)

<strong>O(1) tem a menor complexidade</strong><p>
Geralmente chamado de "tempo constante", se você pode criar um algoritmo para resolver o problema em O(1), isso é normalmente o melhor que você pode conseguir. Em alguns cenários, a comlexidade ode passar de O(1), então podemos analisá-la encontrando sua contrapartida O(1/g(n)). Po exemplo, O(1/n) é mais complexo do que O(1/n²).

<strong>O(log(n)) é mais complexo do que O(1), mas menos complexo do que polinômios</strong><p>
Como a complexidade geralmente está associada a algoritmos de dividir e conquistar, O(log(n)) costuma ser uma complexidade boa que você pode alcançar em algoritmos de ordenação. O(log(n)) é menos complexo que O(sqrt(n)) costuma ser uma complexidade boa que você pode alcançar em algoritmos de ordenação. O(log(n)) é menos complexo que O(sqrt(n)), pois a função da raiz quadrada pode ser considerada um polinômio, onde o expoente é 0,5.

<strong>A complexidade dos polinômios aumenta de acordo com o aumento do expoente</strong><p>
Por exemplo, O(n^5) é mais complexo que O(n^4). Devido à simplicidade disso, passamos por vários exemplos de polinômios nas seções anteriores.

<strong>Exponenciais têm maior complexidade do que polinômios, contanto que os coeficientes sejam múltiplos positivos de n</strong><p>
O(2^n) é mais complexo que O(n^99), mas O(2^n) é, de fato, menos complexo que O(1). 

<strong>Fatoriais têm complexidade maior do que exponenciais</strong>
Se tiver interesse no motivo para isso, consulte a função gama, que é uma extensão analítica de um fatorial. Uma pequena prova disso é que fatoriais e exponenciais têm o mesmo número de multiplicações, mas os números que são multiplicados crescem para os fatoriais, mas permanecem constantes para os exponenciais.

<h2>Complexidade de espaço e de tempo</h2>
Até o momento, só discutimos a complexidade de tempo dos algoritmos. Ou seja, só nos preocupamos com o tempo que leva para o programa completar a tarefa. O que também importa é o espaço que o programa leva para completar a tarefa. A complexidade de espaço é relacionada com o quanto de memória o programa usará e, portanto, também é um fator importante a ser analisado.

A complexidade de espaço funciona de modo semelhante à complexidade de tempo. Por exemplo, a selection sort tem uma complexidade de espaço de O(1), porque ela somente armazena um valor mínimo e seu índice para comparação, o espaço máximo usado não aumenta com o tamanho da entrada.

Alguns algoritmos, como a bucket sort, tem uma complexidade de espaço de O(n), mas pode reduzir a complexidade de tempo para O(1). A bucket sort ordena o array criando uma lista ordenada de todos os elementos possíveis no array, depois incrementa o contador sempre que um elemento é encontrado. No fim, o array ordenado serão os elementos da lista ordenada repetidos por suas contagens.

<strong>Bucket Sort Visualized</strong>

![](https://www.freecodecamp.org/portuguese/news/content/images/2021/12/1_GfLWx2TXS55unwqZ5-X26w.png)

Nem sempre um algoritmo irá iterar muitas vezes para poder encontrar uma resposta para um cálculo computacional, as vezes em uma única iteração o algoritmo já encontra a resposta a que procura, outras vezes é necessário um grande número de iterações, abaixo é mostrado um cheatsheet dos custos que envolvem alguns algoritmos famosos no mundo da computação:

![](https://www.freecodecamp.org/portuguese/news/content/images/2021/12/0_XZsrnwao98R3dGTB.png)

Finalmente, podemos classificar as funções da mais complexa para a menos complexa.

![](https://www.freecodecamp.org/portuguese/news/content/images/2021/12/1_NHVggTVMGjGOe7SxtSgIpQ.png)

<h2>Classes de comportamento assintótico</h2>

Se f é uma função de complexidade para um algoritmo F, então O(f) é considerada a complexidade assintótica ou o comportamento assintótico do algoritmo F. Igualmente, se g é uma função para um algoritmo G, então O(G) é considerada a complexidade assintótica do algoritmo G. A relação de dominação assintótica permite comparar funções de complexidade. Entretanto, se as funções f e g dominam assintoticamente uma à outra, então os algoritmos associados são equivalentes. Nesses casos, o comportamento assintóticonão não serve para comparar os algoritmos. Por exemplo, dois algoritmos F e G aplicados à mesma classe de problemas, sendo que F leva três vezes o tempo de G ao ser executado, isto é, f(n)=3*g(n),sendo que O(f(n))=O(g(n)). Logo, o comportamento assintótico não serve para comparar os algoritmos F e G, porque eles diferem por uma constante.

Programas podem ser avaliados por meio da comparação de suas funções de complexidade, negligenciando as constantes desses, entretanto, as constantes de proporcionalidade em cada caso podem alterar essa consideração. Por exemplo, é possível que um programa leve 100n unidades de tempo para ser executado, enquanto outro leve 2n² unidades de tempo. Quando dos dois programas é melhor?

A resposta a essa pergunta depende do tamanho do problema a ser executado. Para problemas de tamanho n<50, o programa com tempo de execução 2n² é melhor do que o programa com tempo de execução 100n. Para problemas com entrada de dados pequena é preferível usar o programa cujo tempo de execução é O(n²). Entretanto, quando n cresce, o programa com tempo O(n²) leva muito mais tempo que o programa O(n).

A maioria dos algoritmos possui um parâmetro que afeta o tempo de execução de forma mais significativa, usualmente o número de itens a ser processado. Esse parâmetro pode ser o número de registros de um arquivo a ser ordenado ou o número de nós de um grafo. As principais classes de problemas possuem as funções de complexidade descritas a seguir.

1.

2.

3.

4.

5.

6.

7.

8.




<h2>Técnicas de análise de algoritmos</h2>

<h2>Referências</h2>

* Ricardo Baeza-Yates
Santiago, Chile, Dezembro de 2003
Barcelona, Espanha, Junho de 2010

* Projeto de Algoritmos, Nívio Ziviani

* blog freecodecamp
