#include "GABinaryGenome.h"

GABinaryGenome::GABinaryGenome(float (*f)(GAGenome&))
{
	this->fitness_ptr = f;
	chromosome = "";
}

void GABinaryGenome::setSize(int size)
{
	this->size = size;
}

float GABinaryGenome::getFitness()
{
	return fitness_ptr(*this);
}

int GABinaryGenome::length()
{
	return chromosome.length();
}

int GABinaryGenome::gene(int i)
{
	return (int) chromosome.at(i);
}

void GABinaryGenome::calcFit()
{
	fit = getFitness();
}

void GABinaryGenome::crossover(GAGenome & gen)
{
	singlepoint(gen);
}

void GABinaryGenome::singlepoint(GAGenome & gen)
{
	
}

void GABinaryGenome::twopoint(GAGenome & gen)
{

}

void GABinaryGenome::mutation()
{
	
}

void GABinaryGenome::init()
{
	//TODO
}

GABinaryGenome::~GABinaryGenome()
{

}
