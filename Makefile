FLAGS = -g
OUTPUT = genetic_algorithm
SRC = SRC/robot.c SRC/genetic.c
MAIN = main.c

all:
	gcc $(FLAGS) -o $(OUTPUT) $(SRC) $(MAIN)

run:
	make all
	./$(OUTPUT)