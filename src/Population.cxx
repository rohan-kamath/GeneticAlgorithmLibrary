#include "Population.h"

Population::Population(int popSize)
{
	this->popSize = popSize;
}

int Population::evolve(int generations)
{
	Organism o1('1');
	for(int i = 1; i < generations + 1; i++)
	{
		std::cout<<"Generation: "<<i<<std::endl;
	}
	
	std::cout<<"\nFinal Organism Chromosome: "<<o1.getChromosome()<<std::endl;

	return 0;
}
