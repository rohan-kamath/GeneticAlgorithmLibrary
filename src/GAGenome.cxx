#include "GAGenome.h"
#include <iostream>

GAGenome::GAGenome()
{

}

GAGenome::GAGenome(const GAGenome & gen)
{
    *this = gen;
}

GAGenome::GAGenome(float (*f)(GAGenome&))
{
    this->fitness_ptr = f;
}

void GAGenome::calcFit()
{
    GAGenome * gen;
    std::cout << fitness_ptr(*this);
}

void GAGenome::crossover(GAGenome & gen)
{
    
}

void GAGenome::mutation()
{

}

void GAGenome::init()
{

}

GAGenome::~GAGenome()
{

}
