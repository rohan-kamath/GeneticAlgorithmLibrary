#include <iostream>
#include "GeneticAlgorithm.h"
#include "GABinaryGenome.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int length = 26;

float fitness(GAGenome & g)
{
    GABinaryGenome & genome = (GABinaryGenome &)g;
    float fitness = 0.0;
    for(int i = 0; i < genome.length(); i++)
    {
	fitness += genome.gene(i);
    }

    return fitness;
}

int main()
{
    GABinaryGenome genome(length, fitness);
    GeneticAlgorithm ga(25, 25, genome);

    ga.evolve();
    cout << ga.stats() << endl;

    return 0;
}
