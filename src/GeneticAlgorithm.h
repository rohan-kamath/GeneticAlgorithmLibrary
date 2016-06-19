#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <string>
#include <vector>
#include <memory>
#include "GAGenome.h"
#include <iostream>

using std::string;
using std::vector;

class GeneticAlgorithm
{
    public:
        GeneticAlgorithm(int population, int generations, GAGenome & genome);
        void evolve();
        string stats();

    protected:

    private:
        int population;
        int generations;

        vector<GAGenome*> organisms;
};

#endif // GENETICALGORITHM_H
