#pragma once
#include <stdio.h>
#include <stdlib.h>
class RandTools
{
public:

	static void setSeed(unsigned long long seed);
	static int getRandomVal(unsigned int min, unsigned int max);
	static bool getPrecentage(unsigned int chance, unsigned int precent = 100);
};

