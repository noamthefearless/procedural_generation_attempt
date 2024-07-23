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


int main()
{
	Coords r, p;
	p.move(NORTH);
	Door d;
	d.facing = NORTH;
	d.firstSide = p;
	p.move(NORTH);
	d.secondSide = p;
	d.leadingTo = nullptr;
	RotationTypes l = STORAGE_INTERSECTION_ROTATION;
	Room* g = new StorageIntersection(r, l, d);

	r.move(SOUTH);
	std::cout << stringTools::deserializeRoom(stringTools::drawRoom(g, r));



	delete g;
	return 0;
}


