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

<h2>Referências</h2>

* Ricardo Baeza-Yates
Santiago, Chile, Dezembro de 2003
Barcelona, Espanha, Junho de 2010
