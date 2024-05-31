#include "RandTools.h"
#include <iostream>
#include "Coords.h"
#include <vector>
#include "Room.h"
#include "stringTools.h"


int main()
{
	std::cout << stringTools::deserializeRoom(stringTools::serializeRoom(stringTools::makeAsciiRoom(1, 1)));
	return 0;
}


