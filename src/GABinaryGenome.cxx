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

GABinaryGenome::~GABinaryGenome()
{

}