#include "GeneticAlgorithm.h"
#include "GAGenome.h"
#include "GABinaryGenome.h"
#include <algorithm>
#include <time.h>
#include <sstream>

using namespace std;

GeneticAlgorithm::GeneticAlgorithm(int population, int generations, GAGenome & genome)
{
    this->generations = generations;
    this->population = population;
    this->genomeType = &genome;

    for(int i = 0; i < population * 2; i++)
    {
        organisms.push_back(genomeType->clone());
    }

}

void GeneticAlgorithm::evolve()
{

    init();

    //cout << endl;

    for(int i = 0; i < generations; i++)
    {
	nextGen();

	sort(organisms.begin(), organisms.end(), [](const GAGenome* a, const GAGenome* b) -> bool
	{
	    return a->fit > b->fit;
	});

        ostringstream ss;
	ss << i + 1;

        statistics += "Best organism in generation ";
        statistics += ss.str();
        statistics += ": ";
        statistics += organisms.at(0)->genes();
        statistics += "\n"; 
    }

    sort(organisms.begin(), organisms.end());

    //cout << "\n\n";

    for(int i = 0; i < population; i++)
    {
        //organisms.at(i)->printGenes();
    }

    /*organisms.at(1)->printGenes();
    organisms.at(2)->printGenes();
    cout<<endl;

    organisms.at(3)->printGenes();
    organisms.at(4)->printGenes();
    organisms.at(0)->crossover(*organisms.at(1),*organisms.at(2),organisms.at(3),organisms.at(4));
    cout<<"\n";
    organisms.at(3)->printGenes();
    organisms.at(4)->printGenes();

    organisms.at(3)->fit = organisms.at(3)->calcFit();
    cout << organisms.at(3)->fit;*/
}

void GeneticAlgorithm::init()
{

    for(int i = 0; i < organisms.size(); i++)
    {
        organisms.at(i)->init();
	//organisms.at(i)->fit = organisms.at(i)->calcFit();
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

void GeneticAlgorithm::nextGen()
{
    for(int i = 0; i < population; i++)
    {
        organisms.at(i)->fit = organisms.at(i)->calcFit();
        avgFit += organisms.at(i)->fit;
    }

    sort(organisms.begin(), organisms.end(), [](const GAGenome* a, const GAGenome* b) -> bool
{ 
    return a->fit > b->fit; 
});

    cout << "Best organism of this generation: ";
    organisms.at(0)->printGenes();

    avgFit /= population;

    float expectedValueSum = 0.0;

    for(int i = 0; i < population; i++)
    {
        expectedValueSum += (organisms.at(i)->fit / avgFit);
    }

    int selected[population] = {};

    for(int i = 0; i < population; i++)
    {
        float r = GeneticAlgorithm::random(0.0, expectedValueSum);
        int count = 0; float sum = 0;
        for(int j = 0; sum <= r && j < population; j++)
        {
            sum += (organisms.at(j)->fit / avgFit);
            count = j;
        }

        selected[i] = count;

    }

    //temp = organisms;

    //organisms.resize(population * 2, genomeType->clone());

    for(int i = 0; i < population / 2; i ++)
    {
        organisms.emplace(organisms.begin(), genomeType->clone());
        organisms.emplace(organisms.begin(), genomeType->clone());

        organisms.at(0)->crossover(*organisms.at(selected[i + 1] + (i + 1) * 2), *organisms.at(selected[i] + (i + 1) * 2), organisms.at(0), organisms.at(1));
    }

    for(int i = 0; i < population; i++)
    {
        organisms.pop_back();
    }

    /*for(int i = 0; i < population; i++)
    {
        cout << "parent genome:                                       ";
        organisms.at(i)->printGenes();
	cout << "child genome(should be different due to crossovers): ";
        temp.at(i)->printGenes();
	cout<<endl;
    }*/

    for(int i = 0; i < population; i++)
    {
        if(random(1, 10) == 3)
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
    return statistics;
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
