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
#include "StorageCloset.h"
#include "StorageSmallUnit.h"
#include "StorageMediumUnit.h"

int main()
{
	Coords r, p;

	Door d;
	d.facing = EAST;
	d.firstSide = p;
	p.move(EAST);
	d.secondSide = p;
	d.leadingTo = nullptr;
	RotationTypes l = STORAGE_MEDIUM_UNIT_FACING_NORTH;
	Room* g = new StorageMediumUnit(r, l, d);

	r.move(NORTH);
	std::cout << stringTools::deserializeRoom(stringTools::drawRoom(g, r));



	delete g;
	return 0;
}


