#ifndef GAGENOME_H
#define GAGENOME_H

#include <string>

class GAGenome
{
    public:
        GAGenome(float (*f)(GAGenome&));
        GAGenome();
        GAGenome(GAGenome&);
        virtual void calcFit();
        virtual float fitness() const;
	virtual float fitness(int x);
        virtual int gene(int i);
        virtual void crossover(GAGenome& p1, GAGenome& p2, GAGenome& c1, GAGenome& c2);
        virtual void mutation();
        virtual void init();
        virtual void setGene(std::string str);
        virtual std::string genes();
        virtual void printGenes();
        //friend bool operator> (const GAGenome& lhs, const GAGenome& rhs);
        virtual ~GAGenome();

        virtual GAGenome* clone();

	int size;
	float (*fitness_ptr)(GAGenome&);
    protected:

    private:
        float fit;
};

#endif // GAGENOME_H
