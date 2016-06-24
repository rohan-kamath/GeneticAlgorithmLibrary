#include "GABinaryGenome.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

GABinaryGenome::GABinaryGenome(int length, float (*f)(GAGenome&))
{
	this->fitness_ptr = f;
	this->size = length;
	chromosome = "";
}

GAGenome* GABinaryGenome::clone()
{
	GABinaryGenome* g = new GABinaryGenome(this->size, this->fitness_ptr);
	return g;
}

GABinaryGenome::GABinaryGenome(GAGenome & g)
{
	this->fitness_ptr = g.fitness_ptr;
	this->size = g.size;
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
	if(i < chromosome.size())
	{
		return chromosome.at(i);
	}
	return 0;
}

void GABinaryGenome::calcFit()
{
	fit = getFitness();
	//cout << getFitness() << endl;
}

void GABinaryGenome::crossover(GAGenome& p1, GAGenome& p2, GAGenome& c1, GAGenome& c2)
{
	singlepoint(p1, p2, c1, c2);
}

void GABinaryGenome::singlepoint(GAGenome& p1, GAGenome& p2, GAGenome& c1, GAGenome& c2)
{
	int point = rand() % size;
	string child1str = "";
	string child2str = "";

	for(int i = 0; i < size; i++)
	{
		if(i < point)
		{
			child1str += (char) p1.gene(i);
		}

		else {
			child1str += (char) p2.gene(i);
		}
	}

	for(int i = 0; i < size; i++)
        {
		if(i < point)
		{
			child2str += (char) p2.gene(i);
		}

		else {
			child2str += (char) p1.gene(i);
		}
        }

	/*cout<<"c1 gene bef: ";
	c1.printGenes();
	c1.setGene(child1str);
	cout<<"c1 gene aft: ";
	c1.printGenes();

	cout<<"\n c2 gene bef: ";
	c2.printGenes();
	c2.setGene(child2str);
	cout<<"c2 gene aft: ";
	c2.printGenes();*/
}

void GABinaryGenome::twopoint(GAGenome & gen)
{

}

void GABinaryGenome::mutation()
{
	//cout << "before: ";
	//printGenes();
	int point = (int) rand() % chromosome.size();
	//cout << point << endl;
	string temp = "";
	if(chromosome.at(point) == '1')
	{
		for(int i = 0; i < chromosome.size(); i++)
		{
			if(i == point)
			{
				temp += '0';
			} else {
				temp += (char) chromosome.at(i);
				cout << chromosome.at(i);
			}
		}
	}

        else if(chromosome.at(point) == '0'){
                for(int i = 0; i < chromosome.size(); i++)
                {
                        if(i == point)
                        {
                                temp += '1';
                        } else {
                                temp += (char) chromosome.at(i);
                        }
                }
        }
	//cout << temp << endl;
	//chromosome = temp;

	//cout << "after: ";
	//printGenes();
}

void GABinaryGenome::init()
{
	chromosome = "";
	for(int i = 0; i < size; i++)
	{
		int bin = rand() % 2;
		chromosome += (char) bin;
	}
	//this->printGenes();
}

string GABinaryGenome::genes()
{
	return chromosome;
}

void GABinaryGenome::printGenes()
{
	for(int i = 0; i < size; i++)
	{
		cout << (int) chromosome.at(i) << " ";
	}

	cout << endl;
}

float GABinaryGenome::fitness(int x)
{
	return this->fit;
}

void GABinaryGenome::setGene(string str)
{
	this->chromosome = str;
}

GABinaryGenome::~GABinaryGenome()
{

}
