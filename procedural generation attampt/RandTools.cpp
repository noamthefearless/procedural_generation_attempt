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
int RandTools::getRandomVal(unsigned int min, unsigned int max)
{
	return rand() % (max - min + 1) + min;
}


bool RandTools::getPrecentage(unsigned int chance, unsigned int precent)
{
	if (chance == 0)
	{
		return false;
	}
	unsigned int result = RandTools::getRandomVal(1, precent);
	return chance >= result;
}















/*
randomizeRotationTypesVec: this function will get a vector of RotationTypes and randomize it
input: the vector
output: the randomized vector
*/
vector<RotationTypes> RandTools::randomizeRotationTypesVec(vector<RotationTypes> vec)
{
	vector<RotationTypes> result;
	int index = 0;
	while (vec.size() != 0)
	{
		index = RandTools::getRandomVal(0, vec.size() - 1);// getting a random index
		result.push_back(vec[index]);// putting it in the new vector
		vec.erase(vec.begin() + index);// removing from next itterations
	}
	return result;


}





/*
randomizeRoomTypesVec: this function will get a vector of RoomTypes and randomize it
input: the vector
output: the randomized vector
*/
vector<RoomTypes> RandTools::randomizeRoomTypesVec(vector<RoomTypes> vec)
{
	vector<RoomTypes> result;
	int index = 0;
	while (vec.size() != 0)
	{
		index = RandTools::getRandomVal(0, vec.size() - 1);// getting a random index
		result.push_back(vec[index]);// putting it in the new vector
		vec.erase(vec.begin() + index);// removing from next itterations
	}
	return result;


}






/*
randomizeCoordsVec: this function will get a vector of Coords and randomize it
input: the vector
output: the randomized vector
*/
vector<Coords> RandTools::randomizeCoordsVec(vector<Coords> vec)
{
	vector<Coords> result;
	int index = 0;
	while (vec.size() != 0)
	{
		index = RandTools::getRandomVal(0, vec.size() - 1);// getting a random index
		result.push_back(vec[index]);// putting it in the new vector
		vec.erase(vec.begin() + index);// removing from next itterations
	}
	return result;


}










