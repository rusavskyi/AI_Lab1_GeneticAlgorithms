#include "stdafx.h"
#include "CruelWorld.h"

int main()
{
	srand(time(NULL));
	CruelWorld cw("data.txt", 10, 10);
	cw.StartGeneticAlgorithm(false, 20, 50);
	return 0;
}
