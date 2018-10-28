#include "stdafx.h"
#include "Chromosome.h"
#include "Matrix.h"


Chromosome::Chromosome()
{
	//cout << "Cromosome();" << endl;
	//genes = new int[0];
	numberOfGenes = 0;
	adaptation = 0;
}

Chromosome::Chromosome(int numberOfGenes)
{
	//cout << "Cromosome(int);" << endl;
	//genes = new int[numberOfGenes];
	this->numberOfGenes = numberOfGenes;
	adaptation = 0;
	for (int i = 0; i < numberOfGenes; i++)
	{
		genes[i] = 0;
	}
	for (int i = 1; i < numberOfGenes; i++)
	{
		int pos = 0;
		do
			pos = rand() % numberOfGenes;
		while (genes[pos] != 0);
		genes[pos] = i;
	}
}

Chromosome::Chromosome(const Chromosome& other)
{
	////cout << "Cromosome(Chromosome);" << endl;
	//cout << numberOfGenes << ':' << other.GetNumberOfGenes() << endl;
	//if (numberOfGenes == NULL || numberOfGenes < 0)
	//{
	//	numberOfGenes = other.numberOfGenes;
	//	//genes = new int[numberOfGenes];
	//}
	//else if (other.numberOfGenes != numberOfGenes)
	//{
	//	numberOfGenes = other.numberOfGenes;
	//	//genes = new int[numberOfGenes];
	//}
	for (int i = 0; i < numberOfGenes; i++)
	{
		genes[i] = other.genes[i];
	}
	adaptation = other.adaptation;
	cout << endl;
}

Chromosome::~Chromosome()
{

}

int Chromosome::GetGene(int index) const
{
	return genes[index];
}

void Chromosome::SetGene(int index, int value)
{
	genes[index] = value;
}

int Chromosome::GetNumberOfGenes() const
{
	return numberOfGenes;
}

int Chromosome::GetAdaptation() const
{
	return adaptation;
}

void Chromosome::Print() const
{
	cout << "Cromosome adaptation: " << adaptation << endl;
	for (int i = 0, f = 'A'; i < numberOfGenes; i++, f++)
	{
		cout << static_cast<char>(f) << ": " << genes[i] << endl;
	}
}

void Chromosome::Adapt(Matrix* distances, Matrix* frequencies)
{
	adaptation = 0;
	for (int i = 0; i < numberOfGenes; i++)
	{
		for (int j = 0; j < numberOfGenes; j++)
		{
			adaptation += distances->GetValue(genes[i], j) * frequencies->GetValue(i, j);
		}
	}
}

void Chromosome::CrossoverWith(Chromosome& other)
{
	int pos = rand() % numberOfGenes;
	do
	{
		for (int i = 0; i <= pos; i++)
		{
			int tmpGene = genes[i];
			genes[i] = other.GetGene(i);
			other.SetGene(i, tmpGene);
		}
		int rPos = -1;
		for (int i = 0; i < numberOfGenes && pos != -1; i++)
		{
			for (int j = i + 1; j < numberOfGenes && pos != -1; j++)
			{

				if (genes[i] == genes[j])
				{
					if (i == pos)
						rPos = j;
					else
						rPos = i;
				}
			}
		}
		pos = rPos;
	} while (pos >= 0);
}

void Chromosome::Mutate()
{
	int pos0 = 0, pos1 = 0;
	while (pos0 == pos1)
	{
		pos0 = rand() % numberOfGenes;
		pos1 = rand() % numberOfGenes;
	}
	int tmpGene = genes[pos0];
	genes[pos0] = genes[pos1];
	genes[pos1] = tmpGene;
}

void Chromosome::Print()
{
	/*
	cout << "Chromosome adaptation: " << adaptation << endl;
	char factory = 'A';
	for (int i = 0; i < numberOfGenes; i++, factory++)
	{
		cout << factory << ": " << genes[i] << endl;
	}
	*/
	for (int i = 0; i < numberOfGenes; i++)
	{
		cout << genes[i] << ':';
	}
	cout << adaptation << endl;
}

