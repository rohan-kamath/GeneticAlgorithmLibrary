#include "GAGenome.h"
#include <iostream>

GAGenome::GAGenome()
{

}

GAGenome::GAGenome(GAGenome & gen)
{
    *this = gen;
}

GAGenome* GAGenome::clone()
{
    GAGenome* g = new GAGenome();
    g->fitness_ptr = this->fitness_ptr;
    return g;
}

GAGenome::GAGenome(float (*f)(GAGenome&))
{
    this->fitness_ptr = f;
}

float GAGenome::calcFit()
{

}

float GAGenome::fitness() const
{
    return fit;
}

int GAGenome::gene(int i)
{

}

void GAGenome::crossover(GAGenome & p1, GAGenome & p2, GAGenome*& c1, GAGenome*& c2)
{
    
}

void GAGenome::mutation()
{

}

void GAGenome::init()
{

}

std::string GAGenome::genes()
{
    return "";
}

void GAGenome::printGenes()
{

}

void GAGenome::setGene(std::string str)
{

}

inline bool operator> (const GAGenome &lhs, const GAGenome &rhs)
{
    return lhs.fitness() > rhs.fitness();
    
}

GAGenome::~GAGenome()
{

}
