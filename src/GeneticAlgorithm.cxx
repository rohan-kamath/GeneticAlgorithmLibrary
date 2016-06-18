#include "GeneticAlgorithm.h"
#include "GAGenome.h"

GeneticAlgorithm::GeneticAlgorithm(int population, int generations, GAGenome genome)
{
    this->generations = generations;
    this->population = population;

    vector<GAGenome> temp(population, genome);
    organisms = temp;

}

void GeneticAlgorithm::evolve()
{
    //for(int i = 0; i < generations; i++)
    //{
        //TODO
	//choose which will reproduce
	//crossovers

	//organisms.at(i).calcFit();
    //}
}

std::string GeneticAlgorithm::stats()
{
    return "hello world";
}
