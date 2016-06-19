#include <iostream>
#include "GeneticAlgorithm.h"
#include "GABinaryGenome.h"

using namespace std;

float fitness(GAGenome & g)
{
    GABinaryGenome & genome = (GABinaryGenome &)g;
    float fitness = 0.0;
    for(int i = 0; i < genome.length(); i++)
    {
	fitness += genome.gene(i);
    }
    cout << "in the function pointer" << endl;
    return fitness;
}

int length = 10;

int main()
{
    GABinaryGenome genome(fitness);
    GeneticAlgorithm ga(100, 100, genome);

    ga.evolve();
    //cout << ga.stats() << endl;

    return 0;
}
