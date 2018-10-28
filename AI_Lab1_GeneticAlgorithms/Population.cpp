#include "stdafx.h"
#include "Population.h"


Population::Population()
{
	numberOfChromosomes = 0;
	numberOfGenes = 0;
	crossoverChance = 0;
	mutationChance = 0;
	keepBest = false;
	Initialization();
}

Population::Population(int numberOfCromosomes, int numberOfGenes, int mutationChance, int crossoverChance,
	bool keepBest)
{
	this->numberOfChromosomes = numberOfCromosomes;
	this->numberOfGenes = numberOfGenes;
	this->mutationChance = mutationChance;
	this->crossoverChance = crossoverChance;
	this->keepBest = keepBest;
	Initialization();
}


Population::Population(const Population& other)
{
	numberOfChromosomes = other.numberOfChromosomes;
	numberOfGenes = other.numberOfGenes;
	mutationChance = other.mutationChance;
	crossoverChance = other.crossoverChance;
	keepBest = other.keepBest;
	//chromosomes = new Chromosome[numberOfChromosomes];
	for (int i = 0; i < numberOfChromosomes; i++)
	{
		chromosomes[i] = other.chromosomes[i];
		/*chromosomes[i].Print();
		cout << "^\n";
		other.chromosomes[i].Print();
		cout << "__\n";*/
	}
	for (int i = 0; i < numberOfChromosomes; i++)
	{
		chromosomes[i].Print();
	}
}

Population::~Population()
{

}

int Population::GetNumberOfChromosomes()
{
	return numberOfChromosomes;
}

int Population::GetNumberOfGenes()
{
	return numberOfGenes;
}

int Population::GetMutationChance()
{
	return mutationChance;
}

void Population::SetMutationChance(int chance)
{
	mutationChance = chance;
}

int Population::GetCrossoverChance()
{
	return crossoverChance;
}

void Population::SetCrossoverChance(int chance)
{
	crossoverChance = chance;
}

Chromosome Population::GetChromosome(int index)
{
	return chromosomes[index];
}

void Population::SetCromosome(int index, Chromosome value)
{
	chromosomes[index] = Chromosome(value);
}

bool Population::GetKeepBest()
{
	return keepBest;
}

void Population::SetKeepBest(bool value)
{
	keepBest = value;
}

void Population::Adapt(Matrix* distances, Matrix* frequencies)
{
	cout << "Adaptation started." << endl;
	for (int i = 0; i < numberOfChromosomes; i++)
	{
		cout << i << " ";
		chromosomes[i].Adapt(distances, frequencies);
	}
	cout << endl;
	SortByAdaptation();
}

void Population::Mutate()
{
	cout << "Mutation started.\n";
	for (int i = 0; i < numberOfChromosomes; i++)
	{
		if (keepBest && i == 0) i++;
		cout << i << " ";
		if (mutationChance > rand() % 100 + 1) 
		{
			chromosomes[i].Mutate();
			cout << '.';
		}
		chromosomes[i].Print();
	}
	cout << endl;
}

void Population::Crossover()
{
	cout << "Crossover started.\n";
	int pos = 0;
	for (int i = 0; i < numberOfChromosomes; i++)
	{
		if (keepBest && i == 0) i++;
		cout << i;
		if (crossoverChance > rand() % 100 + 1)
		{
			do
			{
				pos = rand() % numberOfChromosomes;
			} while (pos == i && (!keepBest || keepBest && pos == 0));
			chromosomes[i].CrossoverWith(chromosomes[pos]);
			cout << 'x' << pos;
		}
		cout << ' ';
	}
	cout << endl;
	for(int i = 0; i < numberOfChromosomes; i++)
	{
		chromosomes[i].Print();
	}
}

// Selection
Population Population::NewGeneration()
{
	cout << "New generation breading..." << endl;
	Population res(numberOfChromosomes, numberOfGenes, mutationChance, crossoverChance, keepBest);
	for (int i = 0; i < numberOfChromosomes; i++)
	{
		cout << i << " ";
		if (keepBest && i == 0)
			res.chromosomes[i] = Chromosome(chromosomes[0]);
		else
		{
			int pos;
			do
			{
				pos = rand() % numberOfChromosomes;
			} while (pos == i && (!keepBest || keepBest && pos == 0));
			res.chromosomes[i] = Chromosome(chromosomes[i].GetAdaptation() < chromosomes[pos].GetAdaptation() ? chromosomes[i] : chromosomes[pos]);
			cout << chromosomes[i].GetAdaptation() << 'v' << chromosomes[pos].GetAdaptation() << '>' << res.chromosomes[i].GetAdaptation() << endl;
		}
	}
	cout << endl;
	return res;
}

void Population::Initialization()
{
	//chromosomes = new Chromosome[numberOfChromosomes];
	for (int i = 0; i < numberOfChromosomes; i++)
	{
		chromosomes[i] = Chromosome(numberOfGenes);
	}
}

void Population::SortByAdaptation()
{
	for (int i = 0; i < numberOfChromosomes; i++)
	{
		int best = i;
		for (int j = i; j < numberOfChromosomes; j++)
		{
			if (chromosomes[j].GetAdaptation() < chromosomes[best].GetAdaptation())
				best = j;
		}
		if (i != best)
		{
			Chromosome tmpChromosome(chromosomes[i]);
			chromosomes[i] = Chromosome(chromosomes[best]);
			chromosomes[best] = Chromosome(tmpChromosome);
		}
	}
	cout << "Best after sort: ";
	chromosomes[0].Print();
	for (int i = 0; i < numberOfChromosomes; i++)
	{
		cout << chromosomes[i].GetAdaptation() << ' ';
	}
	cout << endl;
}
