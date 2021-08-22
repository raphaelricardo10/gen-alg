Aluno: Raphael Gonçalves
Turma: 1INF38B

Contexto:

Algoritmo genético para otimização de trajeto do robô ate a saida desviando dos obstáculos.

Todos os métodos do algoritmo genético utilizados estão comentados em "/SRC/genetic.c".

Todas as funções referentes ao robô estão presentes em "/SRC/robot.c".

Cada individuo possui um cromossoma com 10 genes, que podem indicar uma de mudança de direção.

O robô nao pode andar na diagonal, somente nas quatro direções básicas.

A distancia percorrida de cada individuo e dada pelo somatório da diferença de cada ponto pelo
seu anterior, dada pelos seus genes, mais a distancia de percorrida para contornar os
obstáculos.

Para classificação dos resultados, eu utilizei como avaliação o inverso da distancia
percorrida de cada individuo da entrada ate a saida, de forma que quanto menor a distancia,
maior a aptidão.

Cada geração possui um minimo local, que diz o individuo que possui o melhor trajeto.

Existe também o minimo global que diz o melhor trajeto encontrado entre as geraçõess.