#include "stdafx.h"
#include "CruelWorld.h"


CruelWorld::CruelWorld()
{
	numberOfPopulations = 0;
	numberOfChromosomes = 0;
	Initialization();
}

CruelWorld::CruelWorld(string path, int numberOfPopulations, int numberOfChromosomes)
{
	ifstream input;
	input.open(path);
	int x = 0, size = 0;
	input >> size;
	distances = Matrix(size);
	frequencies = Matrix(size);
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			input >> x;
			distances.SetValue(i, j, x);
		}
	}
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			input >> x;
			frequencies.SetValue(i, j, x);
		}
	}
	this->numberOfChromosomes = numberOfChromosomes;
	this->numberOfPopulations = numberOfPopulations;
	numberOfGenes = size;
	Initialization();
}

CruelWorld::~CruelWorld()
{
}

void CruelWorld::StartGeneticAlgorithm(bool keepBest, int mutationChance, int crossoverChance)
{
	cout << "GA started." << endl;
	populations[0] = Population(numberOfChromosomes, numberOfGenes, mutationChance, crossoverChance, keepBest);
	for(int i = 1; i < numberOfPopulations; i++)
	{
		cout << "-------\n";
		populations[i - 1].Adapt(&distances, &frequencies);
		Population tmp = populations[i - 1].NewGeneration();
		populations[i] = tmp;
		//populations[i].Crossover();
		//populations[i].Mutate();
		cout << "Population " << i << endl;
		populations[i].GetChromosome(0).Print();
	}
}

void CruelWorld::Initialization()
{
	//populations = new Population[numberOfPopulations];
}
