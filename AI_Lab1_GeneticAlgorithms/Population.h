#pragma once
#include "Chromosome.h"

class Population
{
public:
	Population();
	Population(int numberOfCromosomes, int numberOfGenes, int mutationChance, int crossoverChance, bool keepBest);
	Population(const Population & other);
	~Population();

	int GetNumberOfChromosomes();
	int GetNumberOfGenes();
	int GetMutationChance();
	void SetMutationChance(int chance);
	int GetCrossoverChance();
	void SetCrossoverChance(int chance);
	Chromosome GetChromosome(int index);
	void SetCromosome(int index, Chromosome value);
	bool GetKeepBest();
	void SetKeepBest(bool value);

	void Adapt(Matrix * distances, Matrix * frequencies);
	void Mutate();
	void Crossover();
	Population NewGeneration();

protected:
	//list<Chromosome> chromosomes;
	Chromosome chromosomes[CHROMOSOMES_SIZE];
	int numberOfChromosomes;
	int numberOfGenes;
	int mutationChance;
	int crossoverChance;
	bool keepBest;

private:
	void Initialization();
	void SortByAdaptation();
};

