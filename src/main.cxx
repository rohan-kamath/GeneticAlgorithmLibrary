#include <iostream>
#include "GeneticAlgorithm.h"
#include "GABinaryGenome.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int length = 10;

float fitness(GAGenome & g)
{
    GABinaryGenome & genome = (GABinaryGenome &)g;
    float fitness = 0.0;
    for(int i = 0; i < genome.length(); i++)
    {
	fitness += genome.gene(i);
    }
    //cout << fitness << endl;

    if(fitness == length)
    {
	return 1000000000.0;
    }

    return fitness + 1;
}

int main()
{

    srand(time(0));

    GABinaryGenome genome(length, fitness);
    GeneticAlgorithm ga(25, 25, genome);

    ga.evolve();
   // cout << ga.stats() << endl;

    return 0;
}
