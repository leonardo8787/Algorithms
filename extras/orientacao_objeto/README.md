<h2>Programação Orientada a Objetos</h2>

<strong>Sumário:</strong>

* Classe
* Herança e Polimorfismo
* Objetos e Tipos Genêricos
* Sobrecarga
* Sobrescrita
* Construtores
* Modificadores de Acesso Public, Private, Protected e Static
* Interfaces 
* Pacotes
* Visibilidade de Pacote
* Classes internas
* O objeto this
* Exceções
* Diferenças entre java e C++
* Ausência de apontadores 
* Atribuição
* Alocação Dinâmica de Memória
* Sobrecarga de operadores 

<h2>Programação Orientada a Objeto</h2>

A programação orientada a objetos naceu porque algumas linguagens procedimentais, como Pascal e C, se mostraram inadequadas para a construção de programas de grande porte. Existem dois tipos de problemas:

 1. Falta de correspondÊncia entre o programa e o mundo real. Esse problema está relacionado com a modelagem do mundo real.Os procedimentos implementam tarefas, enquanto as estruturas de dados armazenam informações, mas a maioria dos objetos do mundo real contém as duas coisas.

 2. Organização interna dos programas. Em linguagens procedimentais os programas são organizados por meio da divisão em procedimentos, mas fica difícil encontrar uma boa solução para o tratamento dos dados. Geralmente os dados são locais para um procedimento particular ou são globais e, portanto, acessíveis por todos os procedimentos. 

A programação orientada a objetos permite que objetos do mundo real que compartilham propriedades (ou atributos) e comportamentos comuns sejam agrupados em classes. Esse estilo de programação é diretamente suportado pelo conceito de classe em Java. Além disso, pode-se também impor restrições de visibilidade aos dados de um programa, evitando assim o problema descrito no parágrafo anterior. Classes e objetos são os conceitos fundamentais nas linguagens orientadas a objeto e serão detalhados na próxima seção.

A linguagem Java possui um grau de orientação a objetos maior do que a linguagem C++, apesar de não ser totalmente orientada a objetos como a linguagem Smalltalk, na qual tudo é objeto. Java não é totalmente orientada a objetos porque, por questões de eficiência, foram mantidos alguns tipos primitivos e suas operações.

<h2>Classe</h2>

O conceito de classe nasceu da necessidade de se criar diversos objetos de um mesmo tipo. Uma classe é uma especificação para um ou mais objetos. Dizemos que um objeto pertence a uma classe ou, mais comumente, que é uma instância de uma classe. O Programa 1.7 apresenta a classe "PainelDeControle". A palavra chave 'class' introduz a classe "PainelDeControle". A palavra chave void é utilizada na definição dos métodos 'ligaForno' e 'desligaForno' para indicar que os métodos não retornam nenhum valor. A seguir aparecem os campos e os métosos da classe.

<strong>Programa 1.7</strong> Classe PainelDeControle
~~~
class PainelDeControle {
  private float temperaturaCorrente;
  private float temperaturaDesejada;
  
  public void ligaForno() {
    //código do método
  }
  
  public void desligaForno() {
    //código do método
  }
}
~~~


A criação de um objeto é chamada de instanciação e o objeto passa a ser uma instância da classe. Após a especificação de uma classe e a criação de alguns objetos daquela classe, outras partes do programa interaem com os métodos dos objetos por meio do operador (.), o qual associa um objeto com um de seus métodos. O comando

~~~
painel.ligaForno();
~~~

diz para o painel1 ligar o forno.

<h2>Herança e Polimorfismo</h2>

A criação de uma classe a partir de uma outra classe é chamada de herança. A classe é derivada ou estendida a partir da classe base usando a palavra chave (ex-tends). A classe estendida tem todas as características da classe base mais alma característica adicional. Em Java, a classe base é chamada de <strong>superclasse</strong> e a classe estendida é chamada de <strong>subclasse</strong>. A herança permite adicionar características a uma classe já existente, sendo m recrso importante para o projeto de programas com muitas classes relacionadas. Assim, a herança é um recurso que torna mais fácil a reutilização de classes a partir de pequenas alterações na classe base.

O Programa 1.8 ilustra o conceito de erança. Por exemplo, uma classe pode ser derivada de uma classe mais geral chamada Empregado e incluir um campo de dados camado velocidadeDeDigitação, que não existe na classe Empregado. Outro exemplo, uma classe Gerente pode também ser derivada da mesma classe Empregado e incluir um campo de dados chamado bonus.

<strong>Programa 1.8</strong> Exemplo de herança e polimorfismo
~~~
class Empregado {
  protected float salario;
  public float salarioMensal () { return saario; }
  public void imprime () { System.out.println("Empregado"); }
}

class Secretaria extends Empregado {
 private int velocidadeDeDigitacao;
 public voi imprime(){ System.out.println("Secretaria"); }
}

class Gerente extends Empregado {
 private float bonus;
 public float salarioMensal(){ return salario + bonus; }
 public void imprime () { System.out.println("Gerente"); }
}

public class Polimorfismo {
 public static void main (String[] args){
  Empregado empregado = new Empregado ();
  Empregado secretaria = new Secretaria ();
  Empregado gerente = new Gerente ();
  empregado.imprime(); secretaria.imprime(); gerente.imprime();
 }
}
~~~

O tratamento de objetos de classes diferentes de uma mesma forma é chamado de polimorfismo. Para isso ser possível as classes diferentes tÊm de ser derivadas da mesma classe base. A classe Polimorfismo no Programa 1.8 ilustra o conceito de polimorfismo. Por exemplo, uma chamada do método imprime para o objeto secretaria faz com que seja chamado o método de impressão da classe Secretaria, enquanto uma chamada idêntica para o objeto gerente chama o método de impressão dentro da classe Gerente. Isso simplifica e torna mais claro o projeto e a codificação de programas.

<h2>Objetos e Tipos Genéricos</h2>

Uma estrutura de dados é genérica quando o tipo dos dados armazenados na estrutura é definido na aplicação quue a utiliza. Uma forma de implementar estruturas de dados genéricas é por meio de objetos genéricos. Um objeto genérrico pode ser de qualquer tipo, isto é, pode armazenar uma referência para um objeto de qualquer classe. Os objetos da casse Object, que é uma superclasse para toda classe definida em Java, possuem essa característica. São os mecanismos de herança e polimorfismo que permitem a implementação de estruturas de dados genéricos.

O programa 1.9 apresenta uma estrutura de dados genérica chamada Lista. O objeto item é definido como um objeto genérico pelo fato de ser uma instância da classe Object. Isso significa que Lista pode ter objetos de classes distintas em cada item. Essa liberdade de ter objetos de classes distintas em uma mesma lista obriga o usuário a ter que especificar o tipo de cada objeto a ser inserido e a ser retirado. 

<strong>Programa 1.9</strong> Definição de estrutura de dados Lista utilizando objetos genéricos
~~~
public class Lista {
 private static class Celula {
  Object item; Celula prox;
 }
 private Celula primeiro, ultimo;
}
~~~

Para evitar que o usuário da lista tenha que declarar o tipo de cada objeto a ser inserido ou retirado da lsta, a Versão 5 da linguagem Java introduziu um mecanismo de definição de um tipo gen[erico. Um tipo genérico consiste na definição de um parÂmetro de tipo que deve ser especificado na aplicação que utiliza a estrutura de dados, fazendo com que os itens armazenados na estrutura de dados sejam todos do mesmo tipo.

O programa 1.10 ilustra a definição da estrutura de dados genérica Lista por meio de especificação do parâmetro de tipo T. Agora o objeto item tem de ser uma instância de um tipo genérico T que será fornecido quando um objeto da classe Lista for instanciado. Por exemplo, para instanciar uma lista de inteiros basta declarar o comando "Lista<Integer> lista = new Lista<Integer>();".

<strong>Programa 1.10</strong> Definição da estrutura de dados Lista utilizando tipos genéricos
~~~
public class Lista<T> {
 private static class Celula<T> {
  T item;
  Celula<T> prox;
 }
 private Celula<T> primeiro, ultimo;
}
~~~

<h2>Sobrecarga</h2>

A sorecarga acontece quando determinado objeto se comporta de diferentes formas. A sobrecarga é um tipo de polimorfismo ad hoc. Na sobrecarga um identificador representa vários métodos com computação distintas. O programa 1.11 apresenta um exemplo de sobrecarga do métdo salarioMensal da classe Gerente mostrada no Programa 1.8, em que um desconto é subtraído de salario+bonus. Note que o método salarioMensal do Programa 1.11 possui uma assinatura diferente da assinatura apresentada no Programa 1.8. Isto é o que caracteriza a sobrecarga de um método.

<strong>Programa 1.11</strong> Método da classe Gerente sobrecarregado
~~~
public float salarioMensal (float desconto) {
 return salario + bonus - desconto;
}
~~~

<strong>Sobrescrita</strong><p>

A ocultação de um método de uma classe mais genérica em uma classe mais específica de sobrescrita. Por exemplo, o método imprime da classe Empregado apresentada no Programa 1.8 foi escrito nas classe Gerente e Secretaria. Para sobrescrever um método em uma subclasse é preciso que ele tenha a mesma assinatura na superclasse.

<h2>Construtores</h2>

A classe ContaBancaria tem um método especial denominado construtor, qe é chamado automaticamente sempre que um novo objeto é criado com o comando new. O construtor tem sempre o mesmo nome da classe. No caso do Programa 1.12, o construtor ContaBancaria tem um parâmetro que é usado para realizar o depósito inicial quando a conta é criada.

<strong>Modificadores de Acesso Public, Private, Protected e Static</strong>

Os modificadores de acesso quais outros métodos podem ser acessar um campo de dados ou um método. Um campo de dados ou um método que seja precedido pelo modificador private pode ser acessado somente por métodos que fazem parte da mesma classe. No caso do Programa 1.12, o campo de dados saldo não pode ser acessado por comandos de main, porque não é um método da classe ContaBancaria.

A classe AplicacaoBancaria do Programa 1.12 tem um papel especial. Note que ela é modificada com o modificador public. Isso indica que a classe é visível externamente ao pacote (package cap1) em que ela foi definida. Álem disso, em cada arquivo de um programa Java só pode existir uma classe modificada por public, e o nome do arquivo  deve ser o mesmo dado à classe. Um campo de dados ou um método que seja precedido pelo modificador public pode ser acessado de outras classes.  No caso do Programa 1.12, todos os métodos da classe ContaBancaria são public e os comandos em main podem usar os métodos deposito, saque e imprime.

Os campos de dados de uma clsse são geralmente feitos private e os métodos são tornados public. Isso protege os dados de serem acidentalmente modificados por outras classes. Qualquer entidade externa que necessite acessar dados de uma classe tem de fazê-lo usando um método da mesma classe.

O modificador protected é utilizado para permitir que somente subcasses de uma classe mais genérica possam acessar os campos de dados precedidos com protected. No Programa 1.8, o campo salario da classe Empregada pode ser acessado a partir das sas subclasses, comofoi feito na classe Gerente. No entento, ele não pode ser acessado a partir do método main da clase Polimorfismo, pois esta classe não é uma subclasse da casse Empregado.

Um campo de dadis ou um método de uma classe declarado como static pertence à classe e não às suas instâncias. Isso significa que somente um campo de dados ou um  método será criado pelo compilador para todas as instâncias. Além disso, os métodos de uma classe que foram declarados static operam somente sobre os campos da classe que também foram declarados static. Se além de static o método for declarado public será possível acessá-lo com o nome da classe e o operador(.). No programa 1.13, o campo de dados total pertence somente à classe A, enquanto o campo de dados media pertence a todas as instÂncias da classe A. Ao final da execução do método main, os valores de a.total e b.total são iguas a 7, enquanto os valores de a.media e b.media são iguais a 55 e 7, respectivamente.

<strong>Programa 1.13</strong> Exemplo de utilização do modificador static.
~~~
class A {
 public static int total;
 public int media;
}

public class B {
 public static void main (String[] args) {
  A a =new A(); a.total = 5; a.media = 5;
  A b =new A(); b.total = 7; b.media = 7;
 }
}
~~~

<h2>Interfaces</h2>

Uma interface em Java é uma classe abstrata que não pode ser instanciada. Os métodos de uma interface devem ser pubic e somente as suas assinaturas são definidas. Uma interface é sempre implementada por outras classes. A interface pode ser utilizada para prover a especificação de um comportamento que seja comum a um conjunto de objetos. Por exemplo, a interface permite que o tipo de chave de um registro seja genérico e possibilite aos usuários dos métodos que manipulem o registro definir o tipo de dados da chave de acordo com suas necessidades.

O programa 1.1 para obter o méximo dee um conjunto de inteiros pode ser alterado para encontrar o máximo de um conjunto de registros contendo uma chave genérica. O programa 1.14 apresenta uma versão generalizada do Programa 1.1. Nota que a comparação entre max e v[i] é realizado pelo método compara, que é quem conhece o tipo de dados da chave de cada registro.

<strong>Programa 1.14</strong> Algoritmo para encontrar o registro de maior chave independente do tipo da chave.
~~~
package cap1;
import java.io.*;
public class Max{
 public static Item max(Item v[], int n){
  Item max = v[0];
  for(int i=1; i<n; i++) if (max.compara(v[i])<0) max = v[i];
  return max;
 }
}
~~~

Para permitir a generalização do tipo de dados da chave é necessário criar a interface Item, conforme ilustra o Programa 1.15. A interface Item apresenta a assinatura do método abstrato compara.

<strong>Programa 1.15</strong> Interface para um Item.
~~~
package cap1;
public nterface Item {
 public int compara(Item it);
}
~~~

A interface Item é implementada pela classe MeuItem apresentada no Programa 1.16. É dentro da classe MeuItem que o tipo de dados da chave é definido e que o método compara é implementado. O método compara é utilizado para comparar dois registros a e b, retornando m valor do que zero se a<b, um valor maior do que zero se a>b, e um valor igual a zero se a=b.

<h2>Pacote</h2>

A linguagem Java permite agrupar as classes e as interfaces em pacotes (do ingles package). Os pacotes são convenientes para organizar e separar as classes de um conjunto de programas de outras bibliotecas de classes. O uso de pacotes evita colisões entre nomes de classes desenvolvidas por uma equipe composta por muitos programadores. Para definir o pacote de uma classe ou de uma interface basta utilizar a palavra package seguida pelo nome do pacote. Por exemplo:

~~~
package cap1;
~~~

A declaração de um pacote deve ser sempre na primeira linha do arquivo fonte. Neste texto foi adotada a convenção de se definir um pacote para cada capítulo. Quando necessário é possível definir subpacotes separados por ".". Por exemplo, para definir o subpacote arranjo do pacote cap3 fazendo:

~~~
package cap3.arranjo;
~~~

A utilização de uma classe definida em outro pacote é realizada através da palavra chave <strong>import</strong>. Por exemplo, para utilizar a estrutura de dados Lista implementada por meio de arranjos utiliza-se o seguinte comando:

~~~
import cap3.arranjo.Lista;
~~~

Para utilizar todas as classes de um pacote basta fazer:

~~~
import cap3.arranjo.*;
~~~

Também é possível utilizar determinada classe de um pacote sem importá-la. Para isso também basta prefixar o nome da classe com o nome do pacote durante a declaração de uma varíavel. Por exemplo:

<h2>Visibilidade de pacote</h2>

Toda classe pertence a um pacote. Se o comando package não é colocado no código fonte, então Java adiciona as classes daquele código fonte no que é chamado de pacote default. Quando um campo (ou método) de uma classe não é prefixado por nenhum dos modificadores private, protexted ou public, diz-se que o campo (ou método) possui visibilidade default ou de pacote, o que significa que qualquer objeto de uma classe do pacote pode acessar diretamente aquele campo (ou método).

<h2>Classes Internas</h2>

A linguagem Java permite realizar aninhamento de classes, isto é, pode-se declarar uma classe dentro da declaração de outra classe. O programa 1.18 ilustra a declaração da classe Celula, que é interna à classe Lista. Classes internas são muito úteis para evitar conflitos de nomes na implementação de estruturas de dados, como apresentado antes.

<strong>Programa 1.18</strong> Declaração de uma classe interna
~~~
public class Lista{
  
  private class Celula{
    
  }
}
~~~

Os campos e métodos declarados na classe externa podem ser diretamente acessados dentro da classe interna, mesmo os declarados como protected ou private. No entanto, o contrário não é verdadeiro. Somente os campos ou métodos públicos da classe interna podem ser acessados na classe externa. As classes externas só podem ser declaradas como públicas ou com visibilidade de pacote (default). Já as classes internas podem também ser qualificadas com os modificadores private, protected e static. O efeito desses modificadores sobre a visibilidade de uma instância da classe interna é o mesmo obtido sobre qualquer atributo da classe externa.

<strong>O objeto this</strong>

Toda instância de uma classe possui uma variável especial chamada this, que contém uma referência para a própria instância. Isso é necessário em algumas situações para resolver questões de ambiguidade. O programa 1.19 ilustra uma situação na qual o uso do objeto this se faz necessário. Note que o parâmetro saldo do método alteraSaldo possui o mesmo nome do campo de instância saldo da classe Conta. Para diferenciá-los é necessário qualificar o campo da instância com o objeto this.

<strong>Exceções</strong>

As exceções são erros ou anomalias que podem ocorrer durante a execução de um programa, tais como a divisão por zero, a indisponibilidade de memória principal

<strong>Programa 1.19</strong> Utilização do objeto this
~~~
public class Conta{
  private double saldo;
  public void alteraSaldo(double saldo){
    this.saldo = saldo;
  }
}
~~~

ou a falta de espaço em disco magnético. Uma exceção deve ser obrigatoriamente representada por um objeto de uma subclasse da classe Throwable. A classe Throwable possui duas subclasses diretas: (i) Exception e (ii) Error. A subclasse Exception será muito utilizada nos capítulos a seguir. Uma abordagem simples para tratar uma exceção é exibir uma mensagem relatando o erro ocorrido e retornar para quem chamou ou finalizar o programa, como ilustra o Programa 1.20. O comando try trata uma exceção que tenha sido disparada em seu interior por um comando throw. A exceção é representada por um objeto que representa a exceção e o envia para ser capturado pelo trecho de código que vai tratar a exceção. O comando catch captura a exceção e fornece o tratamento adequado.

<strong>Programa 1.20</strong> Tratamento da exceção no local onde ela ocorre
~~~
int divisao(int a, int b){
  try{
    if(b==0) throw new Exception ("Divisão por zero");
    return (a/b);
  }
  catch (Exception objeto) {
    System.out.println("Erro:" + objeto.getMessage());
    return (0);
  }
}
~~~

Uma abordagem mais elaborada para tratar uma exceção é separar o local onde a exceção é tratada do local onde ela ocorreu. Essa separação é importante pelo fato de que um trecho de código em um nível mais alto pode possuir mais informações para decidir como melhor tratar a exceção. Nesse caso a exceção não é tratada no local onde ela ocorreu, e esse fato é explicitamente indicado pelo comando throws.

<h2>Convenções de Codificação em Java</h2>

A comunidade de programadores Java adota uma convenção de codificação em que os identificadores associados às classes devem iniciar com letra minúscula. Mais detalhes sobre convenção podem ser obtidos por meio do link: http://java.sun.com/docs/codeconv/html/CodeConvTOC.doc.html

<h2>Diferenças emtre Java e C++</h2>

Esta seção não pretende cobrir todas as diferenças entre Java e C++, mas apenas mostrar as principais características que diferenciam a linguagem Java da linguagem C++.

<strong>Ausência de Apontadores</strong>

<strong>Atribuição</strong>

<strong>Alocação Dinâmica de Memória</strong>

<strong>Parâmetros</strong>

<strong>Operador de Igualdade</strong>

<strong>Sobrecarga de Operadores</strong>

<strong>Tipos Primitivos de Dados</strong>


<h2>Referência</h2>

Projeto de Algoritmos, Nivio Ziviani.

