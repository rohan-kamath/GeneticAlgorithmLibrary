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

GAGenome::~GAGenome()
{

}
