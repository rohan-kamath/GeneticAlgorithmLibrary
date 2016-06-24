#include <iostream>
#include "GeneticAlgorithm.h"
#include "GABinaryGenome.h"
#include <time.h>
#include <cstdlib>

using namespace std;

float fitness(GAGenome & g)
{
    GABinaryGenome & genome = (GABinaryGenome &)g;
    float fitness = 0.0;
    for(int i = 0; i < genome.length(); i++)
    {
	fitness += genome.gene(i);
    }
    //cout << fitness << endl;
    return fitness;
}

int length = 10;

int main()
{

    srand(time(0));

    GABinaryGenome genome(length, fitness);
    GeneticAlgorithm ga(200, 1, genome);

    ga.evolve();
    //cout << ga.stats() << endl;

    return 0;
}
