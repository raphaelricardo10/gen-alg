#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "genetic.h"
#include "robot.h"

void start_population()
{
    population.gen = 0;
    for(int i = 0; i < POP_SIZE; i++)
        for(int j = 0; j < CHROMO_SIZE; j++)
            population.member[i].chromossome[j] = (rand()%LIMIT)+1;
    putchar('\n');
}

double calculate_fitness()
{
    //Fitness based on 1/distance traveled

    int tmp_best_member;
    double fitness[POP_SIZE] = {};
    double local_fittest = 0;

    for(int i = 0; i < POP_SIZE; i++)
    {
        int xdistance = population.member[i].chromossome[0];
        int ydistance = population.member[i].chromossome[1];

        fitness[i] += (double)(xdistance + ydistance);

        for(int j = 2; j < CHROMO_SIZE; j++)
        {
            if(j%2 == 0)
            {
               xdistance = abs(population.member[i].chromossome[j] - population.member[i].chromossome[j-2]);
                fitness[i] += (double)(xdistance + ydistance);
            }
            else
            {
                ydistance = abs(population.member[i].chromossome[j] - population.member[i].chromossome[j-2]);
                fitness[i] += (double)(xdistance + ydistance);
            }
        }
 
        if(CHROMO_SIZE%2 == 0)
        {
            xdistance = abs(door.p.x - population.member[i].chromossome[CHROMO_SIZE-2]);
            ydistance = abs(door.p.y - population.member[i].chromossome[CHROMO_SIZE-1]);

        }
        else
        {
            xdistance = abs(door.p.x - population.member[i].chromossome[CHROMO_SIZE-1]);
            ydistance = abs(door.p.y - population.member[i].chromossome[CHROMO_SIZE-2]);
        }

        fitness[i] += (double)(xdistance + ydistance);
        fitness[i] = 1/fitness[i];     

    }

    for(int i = 0; i < POP_SIZE; i++)   
        if(fitness[i] > local_fittest)
        {
            tmp_best_member = i;
            local_fittest = fitness[i];
        }


    if(local_fittest > population.absolute_fittest)
    {
        population.best_member = tmp_best_member;
        population.absolute_fittest = local_fittest;
    }

    for(int i = 0; i < POP_SIZE; i++)
    {
        family.choosen[0] = selection(fitness);
        family.choosen[1] = selection(fitness);
        crossover(i);
    }

    for(int i = 0; i < POP_SIZE; i++)
        for(int j = 0; j < CHROMO_SIZE; j++)
            population.member[i].chromossome[j] = next_population.member[i].chromossome[j];

    return local_fittest;

}

int selection(double weight[])
{
    //Roulette Wheel Selection
    double sum = 0;
    for(int i = 0; i < POP_SIZE; i++)
        sum += weight[i];
    double value = (double)rand()/(double)RAND_MAX*sum;
    for(int i = 0; i < POP_SIZE; i++)
    {
        value -= weight[i];
        if(value < 0)
            return i;
    }
    return POP_SIZE-1;
}

void crossover(int pos)
{
    //Random single point swap between parents
    int crossover_point = (rand()%(CHROMO_SIZE-2) + 1);

    for(int i = 0; i < CHROMO_SIZE; i++)
    {
        family.parent[0].chromossome[i] = population.member[family.choosen[0]].chromossome[i];
        family.parent[1].chromossome[i] = population.member[family.choosen[1]].chromossome[i];
    }

    for(int i = 0; i < crossover_point; i++)
    {
        family.children.chromossome[i] = family.parent[1].chromossome[i];
    }

    for(int i = --crossover_point; i < CHROMO_SIZE; i++)
    {
        family.children.chromossome[i] = family.parent[0].chromossome[i];
    }

    for(int j = 0; j < CHROMO_SIZE; j++)
        next_population.member[pos].chromossome[j] = family.children.chromossome[j];
}

void mutation()
{
    //Random gene swap mutation
    int mut_member = (rand()%POP_SIZE-1)+1;
    int gene1 = rand()%CHROMO_SIZE;
    int gene2 = rand()%CHROMO_SIZE;
    int old_gene1 = population.member[mut_member].chromossome[gene1];
    int old_gene2 = population.member[mut_member].chromossome[gene2];
    population.member[mut_member].chromossome[gene1] = old_gene2;
    population.member[mut_member].chromossome[gene2] = old_gene1;
}