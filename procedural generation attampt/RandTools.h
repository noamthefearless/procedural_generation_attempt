#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Room.h"
class RandTools
{
public:

	static void setSeed(unsigned long long seed);
	static int getRandomVal(unsigned int min, unsigned int max);
	static bool getPrecentage(unsigned int chance, unsigned int precent = 100);
	static vector<Coords> randomizeCoordsVec(vector<Coords> vec);
	static vector<RoomTypes> randomizeRoomTypesVec(vector<RoomTypes> vec);
	static vector<RotationTypes> randomizeRotationTypesVec(vector<RotationTypes> vec);


};


