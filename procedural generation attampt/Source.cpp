#include "RandTools.h"
#include <iostream>
#include "Coords.h"
#include <vector>
#include "Room.h"
#include "stringTools.h"
#include "StorageCorridor.h"
#include "StorageLongCorridor.h"


int main()
{
	Coords r, p;
	p.move(SOUTH);
	Door d;
	d.facing = SOUTH;
	d.firstSide = r;
	d.secondSide = p;
	d.leadingTo = nullptr;
	RotationTypes l = STORAGE_LONG_CORRIDOR_FACING_NORTH;
	Room* g = new StorageLongCorridor(r, l, d);


	r.move(NORTH, 3);
	std::cout << stringTools::deserializeRoom(stringTools::drawRoom(g, r));



	delete g;
	return 0;
}


