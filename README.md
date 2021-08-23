# Genetic Algorithm Implementation
Aluno: Raphael Gonçalves
Turma: 1INF38B
Data: 11/2018

Context:

This is an undergraduate work which consists in modeling a genetic algorithm to a robot that needs to find the exit in a box with random obstacles. The robot cannot walk in diagonal. It can walk only in the 4 basics directions.

All the used genetic algorithms methods commented are in "/SRC/genetic.c".

All the functions related to the robot implementation are in "/SRC/robot.c".

Each individual has a chromosome with 10 genes, indicating a direction change.

The traveled distance of each individual is given by the sum of differences of each point by its previous position, stored in its genes, plus the traveled distance to bypass the obstacles.

In the Classification step, the inverse of distance was utilized to determine the fitness.

Each generation has a local minimum, representing its best individual.

The global minimum is the best path found across all the generations.

Contexto:

Este é um trabalho universitário com o objetivo de modelar um algoritmo genético para um robô que precisa encontrar a saída em uma caixa com obstáculos que aparecem aleatoriamente. O robô nao pode andar na diagonal, somente nas quatro direções básicas.

Todos os métodos do algoritmo genético utilizados estão comentados em "/SRC/genetic.c".
Todas as funções referentes ao robô estão presentes em "/SRC/robot.c".

Cada individuo possui um cromossoma com 10 genes, que podem indicar uma de mudança de direção.

A distancia percorrida de cada individuo e dada pelo somatório da diferença de cada ponto pelo
seu anterior, dada pelos seus genes, mais a distancia de percorrida para contornar os
obstáculos.
Na etapa de Classificação, eu utilizei como avaliação o inverso da distancia
percorrida de cada individuo da entrada ate a saida, de forma que quanto menor a distancia,
maior a aptidão.

Cada geração possui um minimo local, que diz o individuo que possui o melhor trajeto.
Existe também o minimo global que diz o melhor trajeto encontrado entre as gerações.
