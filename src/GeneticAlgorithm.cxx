#include "GeneticAlgorithm.h"
#include "GAGenome.h"
#include "GABinaryGenome.h"
#include <algorithm>
#include <time.h>

using namespace std;

GeneticAlgorithm::GeneticAlgorithm(int population, int generations, GAGenome & genome)
{
    this->generations = generations;
    this->population = population;
    this->genomeType = genome;

    vector<GAGenome*> test(population, &genome);
    //organisms = test;

    for(int i = 0; i < population; i++)
    {
        organisms.push_back(genome.clone());
    }

}

void GeneticAlgorithm::evolve()
{

    init();

    //cout << endl;

    for(int i = 0; i < generations; i++)
    {
	nextGen();
    }

    sort(organisms.begin(), organisms.end());

    //cout << "\n\n";

    for(int i = 0; i < population; i++)
    {
        //organisms.at(i)->printGenes();
    }

    //organisms.at(0)->printGenes();
    //organisms.at(0)->crossover(*organisms.at(1),*organisms.at(2),*organisms.at(3),*organisms.at(4));
}

void GeneticAlgorithm::init()
{

    for(int i = 0; i < organisms.size(); i++)
    {
        int seed = rand();
        //cout << seed << endl;
        organisms.at(i)->init();
	//organisms.at(i)->calcFit();
        //organisms.at(i)->printGenes();
    }

    for(int i = 0; i < population; i++)
    {
        //organisms.at(i)->printGenes();
    }

    //sort(organisms.begin(), organisms.end(), [](const GAGenome* a, const GAGenome* b) -> bool
//{
//    return a->fitness() > b->fitness();
//});

    //organisms.at(0)->calcFit();
    //cout << (int) organisms.at(0)->fitness();
    //organisms.at(0)->printGenes();

}

inline void GeneticAlgorithm::nextGen()
{
    for(int i = 0; i < population; i++)
    {
        organisms.at(i)->calcFit();
        avgFit += organisms.at(i)->fitness();
    }

    sort(organisms.begin(), organisms.end(), [](const GAGenome* a, const GAGenome* b) -> bool
{ 
    return a->fitness() > b->fitness(); 
});

    //organisms.at(0)->printGenes();

    avgFit /= population;

    float expectedValueSum = 0.0;

    for(int i = 0; i < population; i++)
    {
        expectedValueSum += (organisms.at(i)->fitness() / avgFit);
    }

    int selected[population] = {};

    for(int i = 0; i < population; i++)
    {
        float r = GeneticAlgorithm::random(0.0, expectedValueSum);
        int count = 0; float sum = 0;
        for(int j = 0; sum <= r && j < population; j++)
        {
            sum += (organisms.at(j)->fitness() / avgFit);
            count = j;
        }

        selected[i] = count;

    }

    temp = organisms;

    for(int i = 0; i < population; i += 2)
    {
        organisms.at(0)->crossover(*organisms.at(selected[i + 1]), *organisms.at(selected[i]), *temp.at(i), *temp.at(i + 1));
    }

    for(int i = 0; i < population; i++)
    {
        cout << "parent genome:                                       ";
        organisms.at(i)->printGenes();
	cout << "child genome(should be different due to crossovers): ";
        temp.at(i)->printGenes();
	cout<<endl;
    }

    organisms = temp;

    for(int i = 0; i < population; i++)
    {
		for(int j = 0; j < 5; j++)
		{
			organisms.at(i)->mutation();
		}
    }


    for(int i = 0; i < population; i++)
    {
	//organisms.at(i)->printGenes();
    }
}

std::string GeneticAlgorithm::stats()
{
    return "hello world";
}

float GeneticAlgorithm::random(float min, float max)
{

    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float r = random * diff;
    return min + r;
}

int GeneticAlgorithm::random(int min, int max)
{
    int random = ((int) rand()) / (int) RAND_MAX;
    int diff = max - min;
    int r = random * diff;
    return min + r;
}

GeneticAlgorithm::~GeneticAlgorithm()
{
}
