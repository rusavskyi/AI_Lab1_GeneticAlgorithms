#pragma once
#include "Population.h"
#include "Matrix.h"

class CruelWorld
{
public:
	CruelWorld();
	CruelWorld(string path, int numberOfPopulations, int numberOfChromosomes);
	~CruelWorld();

	void StartGeneticAlgorithm(bool keepBest, int mutationChance, int crossoverChance);

protected:
	int numberOfPopulations;
	int numberOfChromosomes;
	int numberOfGenes;
	Population populations[POPULATIONS_SIZE];
	Matrix distances;
	Matrix frequencies;

private:
	void Initialization();
};

