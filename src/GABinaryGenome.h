#ifndef GABINARYGENOME_H
#define GABINARYGENOME_H

#include <string>

#include "GAGenome.h"

using std::string;

class GABinaryGenome : public GAGenome
{
    public:
        //using GAGenome::GAGenome;
	GABinaryGenome(int length, float (*f)(GAGenome&));
	GABinaryGenome(GAGenome & g);
        void setSize(int size);
	float getFitness();
	int length();
	int gene(int i) override;
	float calcFit() override;
	void crossover(GAGenome& p1, GAGenome& p2, GAGenome*& c1, GAGenome*& c2) override;
	void mutation() override;
        void init() override;
        void setGene(string str) override;
        string genes() override;
        void printGenes() override;
	~GABinaryGenome();

	float fit;

        virtual GAGenome* clone();

	int size;
	float (*fitness_ptr)(GAGenome&);
    protected:

    private:
        string chromosome;
        void singlepoint(GAGenome& p1, GAGenome& p2, GAGenome*& c1, GAGenome*& c2);
        void twopoint(GAGenome & gen);
};

#endif // GABINARYGENOME_H
