#ifndef GAGENOME_H
#define GAGENOME_H


class GAGenome
{
    public:
        GAGenome(float (*f)(GAGenome&));
        GAGenome();
        GAGenome(const GAGenome&);
        virtual void calcFit();
        virtual void crossover(GAGenome & gen);
        virtual void mutation();
        virtual void init();
        virtual ~GAGenome();

    protected:

    private:
        float (*fitness_ptr)(GAGenome&);
        float fit;
};

#endif // GAGENOME_H
