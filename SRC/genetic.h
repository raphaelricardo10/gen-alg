#ifndef genetic_h
#define genetic_h

#define POP_SIZE 1000
#define CHROMO_SIZE 10
#define MUTATION_PROB 0.1
#define MAX_GEN 200000

struct members
{
    int chromossome[CHROMO_SIZE];
};

struct breeding
{
    int choosen[2];
    struct members parent[2];
    struct members children;
}family;

struct population_data
{
    unsigned long long int gen;
    int size;
    int best_member;
    float absolute_fittest;
    struct members member[POP_SIZE];
}population;

struct population_data next_population;

void start_population();
int selection(double []);
double calculate_fitness();
void crossover();
void mutation();

#endif
