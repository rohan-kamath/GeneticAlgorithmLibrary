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
        void init();
        void nextGen();
        string stats();
        float random(float min, float max);
        int random(int min, int max);
        virtual ~GeneticAlgorithm();

    protected:

    private:
        int population;
        int generations;
        float avgFit;
        GAGenome * genomeType;
        vector<GAGenome*> organisms;
        vector<GAGenome*> temp;
        string statistics;
};

#endif // GENETICALGORITHM_H
