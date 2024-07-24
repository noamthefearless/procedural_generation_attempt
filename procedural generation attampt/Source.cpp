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

int main()
{
	Coords r, p;

	Door d;
	d.facing = NORTH;
	d.firstSide = p;
	p.move(NORTH);
	d.secondSide = p;
	d.leadingTo = nullptr;
	RotationTypes l = STORAGE_CLOSET_ROTATION;
	Room* g = new StorageCloset(r, l, d);

	//r.move(SOUTH);
	std::cout << stringTools::deserializeRoom(stringTools::drawRoom(g, r));



	delete g;
	return 0;
}


