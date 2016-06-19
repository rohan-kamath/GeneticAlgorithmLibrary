#include "GeneticAlgorithm.h"
#include "GAGenome.h"
#include "GABinaryGenome.h"

using namespace std;

GeneticAlgorithm::GeneticAlgorithm(int population, int generations, GAGenome & genome)
{
    this->generations = generations;
    this->population = population;

    vector<GAGenome*> test(population, &genome);
    organisms = test;
}

void GeneticAlgorithm::evolve()
{
    for(int i = 0; i < organisms.size(); i++)
    {
        //TODO
	//choose which will reproduce
	//crossovers
	organisms.at(i)->calcFit();
    }
}

std::string GeneticAlgorithm::stats()
{
    return "hello world";
}
