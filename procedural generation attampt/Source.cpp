#include "RandTools.h"
#include <iostream>
#include "Coords.h"
#include <vector>
#include "Room.h"
#include "stringTools.h"
#include "StorageCorridor.h"
#include "StorageLongCorridor.h"
#include "StorageT_Intersection.h"
#include "StorageIntersection.h"
#include "StorageTurn.h"


int main()
{
	Coords r, p;
	p.move(EAST);
	p.move(EAST);

	Door d;
	d.facing = SOUTH;
	d.firstSide = p;
	p.move(SOUTH);
	d.secondSide = p;
	d.leadingTo = nullptr;
	RotationTypes l = STORAGE_TURN_FACING_SOUTH;
	Room* g = new StorageTurn(r, l, d);

	//r.move(SOUTH);
	std::cout << stringTools::deserializeRoom(stringTools::drawRoom(g, r));



	delete g;
	return 0;
}


