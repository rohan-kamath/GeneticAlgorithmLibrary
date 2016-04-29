#include "GeneticAlgorithm.h"

int GeneticAlgorithm::start(int generations, int popSize)
{
	this->generations = generations;
	Population population(popSize);
	return population.evolve(generations);
}
