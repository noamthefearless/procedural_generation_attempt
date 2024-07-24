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
#include "StorageBigUnit.h"
#include "StorageVehicleUnit.h"

int main()
{
	Coords r, p;

	Door d;
	p.move(NORTH, 3);
	d.facing = NORTH;
	d.firstSide = p;
	p.move(NORTH);
	d.secondSide = p;
	d.leadingTo = nullptr;
	RotationTypes l = STORAGE_VEHICLE_UNIT_FACING_WEST;
	Room* g = new StorageVehicleUnit(r, l, d);


	vector<Coords> corrds = g->getDoorCoords();

	//r.move(NORTH);
	std::cout << stringTools::deserializeRoom(stringTools::drawRoom(g, r));



	delete g;
	return 0;
}


