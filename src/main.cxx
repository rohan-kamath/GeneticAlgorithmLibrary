#include <iostream>
#include "GeneticAlgorithm.h"
#include "GABinaryGenome.h"

using namespace std;

float fitness(GAGenome & g)
{
    /*GABinaryGenome & genome = (GABinaryGenome &)g;
    float fitness = 0.0;
    /*for(int i = 0; i < genome.length(); i++)
    {
	fitness += genome.gene(i);
    }*/
    cout << "in the function pointer" << endl;
    return 0.0;
}

int length = 10;

int main()
{
    GABinaryGenome genome(fitness);
    GeneticAlgorithm ga(100, 50, genome);

    genome.calcFit();

    

    vector<GAGenome*> test(1, &genome);
    test[0]->calcFit();

    return 0;
}
