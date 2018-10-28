#pragma once
#include <list>
class Matrix;

class Chromosome
{
public:
	Chromosome();
	Chromosome(int numberOfGenes);
	Chromosome(const Chromosome & other);
	~Chromosome();

	int GetGene(int index) const;
	void SetGene(int index, int value);
	int GetNumberOfGenes() const;
	int GetAdaptation() const;

	void Print() const;
	void Adapt(Matrix * distances, Matrix * frequencies);
	void CrossoverWith(Chromosome & other);
	void Mutate();
	void Print();

protected:
	//list<int> genes;
	int genes[GENES_SIZE];
	int numberOfGenes;
	float adaptation;
};

