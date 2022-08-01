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
<h2>Referência</h2>

Projeto de Algoritmos, Nivio Ziviani.

