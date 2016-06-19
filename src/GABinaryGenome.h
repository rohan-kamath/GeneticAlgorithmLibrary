#ifndef GABINARYGENOME_H
#define GABINARYGENOME_H

#include <string>

#include "GAGenome.h"

using std::string;

class GABinaryGenome : public GAGenome
{
    public:
        //using GAGenome::GAGenome;
	GABinaryGenome(float (*f)(GAGenome&));
	void setSize(int size);
	float getFitness();
	int length();
	int gene(int i);
	void calcFit() override;
	~GABinaryGenome();

    protected:

    private:
	float fit;
        string chromosome;
        int size;
        float (*fitness_ptr)(GAGenome&);
};

#endif // GABINARYGENOME_H
