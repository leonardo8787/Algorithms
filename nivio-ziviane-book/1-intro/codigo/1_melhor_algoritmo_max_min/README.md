<h1>Algoritmo de busca de máximo e mínimo</h1>

Este algoritmo é mais eficiente que os outros, da mesma família assintótica, visto que compara os elementos do vetor em duplas, colocando os maiores num subconjunto e os menores em outro subconjunto a um custo de (n/2)² comparações. O máximo obtido do subconjunto que contém os maiores elementos à um custo de (n/2) - 1 comparações. Por fim o mínimo do subconjunto é encontrado a um custo de (n/2)-1 comparações, semelhante ao maior. Assim o custo mínimo do software é de 3n/2-2, já o pior e o melhor caso são iguais, sendo eles 3n/2-2 comparações. 
