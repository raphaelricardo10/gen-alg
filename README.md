Aluno: Raphael Ricardo Goncalves
Matricula: 20182101572
Turma: 1INF38B

Contexto:

Algoritmo genetico para otimizacao de trajeto do robo ate a saida desviando dos obstaculos.

Todos os metodos utilizados estao comentados em "/SRC/genetic.c".

Todas as funcoes referentes ao robo estao presentes em "/SRC/robot.c".

Cada individuo possui um cromossoma com 10 genes, que podem indicar uma de mudanca de direcao.

O robo nao pode andar na diagonal, somente nas quatro direcoes basicas.

A distancia percorrida de cada individuo e dada pelo somatorio da diferenca de cada ponto pelo
seu anterior, dada pelos seus genes, mais a distancia de percorrida para contornar os
obstaculos.

Para classificacao dos resultados, eu utilizei como avaliacao o inverso da distancia
percorrida de cada individuo da entrada ate a saida, de forma que quanto menor a distancia,
maior a aptidao.

Cada geracao possui um minimo local, que diz o individuo que possui o melhor trajeto.

Existe tambem o minimo global que diz o melhor trajeto encontrado entre as geracoes.