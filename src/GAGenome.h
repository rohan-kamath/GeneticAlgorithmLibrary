#ifndef GAGENOME_H
#define GAGENOME_H


class GAGenome
{
    public:
        GAGenome(float (*f)(GAGenome&));
        GAGenome();
        void calcFit();
	//virtual ~GAGenome();

    protected:

    private:
        float (*fitness_ptr)(GAGenome&);
        float fit;
};

#endif // GAGENOME_H
