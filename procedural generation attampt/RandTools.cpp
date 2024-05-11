#include "RandTools.h"



/*
setSeed: this funtion will set the seed for all random events.
input: the seed
output: non
*/
void RandTools::setSeed(unsigned long long seed)
{
	srand(seed);
}



/*
getRandomVal: this function will return a random value in a specified scoppe
input: the scope (maximum and minimum values)
output: the random number
*/
int RandTools::getRandomVal(int min, int max)
{
	return rand() % (max - min + 1) + min;
}




