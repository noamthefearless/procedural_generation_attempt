#pragma once
#include <stdio.h>
#include <stdlib.h>
class RandTools
{
public:

	static void setSeed(unsigned long long seed);
	static int getRandomVal(int min, int max);

};

