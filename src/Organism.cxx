#include "Organism.h"

Organism::Organism(char chromosome)
{
	this->chromosome = chromosome;
}

char Organism::getChromosome()
{
	return this->chromosome;
}
