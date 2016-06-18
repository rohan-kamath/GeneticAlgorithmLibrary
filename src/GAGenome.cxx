#include "GAGenome.h"

GAGenome::GAGenome()
{

}

GAGenome::GAGenome(float (*f)(GAGenome&))
{
    this->fitness_ptr = f;
}

void GAGenome::calcFit()
{
    GAGenome * gen;
    gen = this;
    fit = (*fitness_ptr)(*gen);
}

