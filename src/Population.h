#ifndef POPULATION_H
#define POPULATION_H

#include "Organism.h"
#include <iostream>

class Population
{
	private:
	 int popSize;

	public:
	 Population(int popSize);
	 int evolve(int generations);
};

#endif 
