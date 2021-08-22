#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SRC/genetic.h"
#include "SRC/robot.h"

int main()
{
    srand(time(NULL));
    rand();

    start_population();
    set_start_variables();

    int distance = 0;
    unsigned long long int gen = 0;
    double random = (double)rand()/(double)RAND_MAX;

    while(gen != MAX_GEN)
    {
        gen++;
        distance = (int)(1/calculate_fitness());
        decode();
        printf("Gen: %lld\tMenor Distancia Local: %d\tMenor Distancia Absoluta: %d\t",
                gen, distance, winner.minor_distance);
        printf("Coordenadas da porta(x,y): (%d,%d)\n", door.p.x, door.p.y);
        if(random <= MUTATION_PROB)
            mutation();
        random = (double)rand()/(double)RAND_MAX;
        fflush(stdin);
    }
    printf("Done!\n");
}


