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
#include "StorageConnectedCorridors.h"
#include "StorageSquareCorridor.h"


int main()
{
	Coords r, p;

	Door d;
	d.facing = WEST;
	d.firstSide = p;
	p.move(WEST);
	d.secondSide = p;
	d.leadingTo = nullptr;
	RotationTypes l = STORAGE_SQUARE_CORRIDOR_ROTATION;
	Room* g = new StorageSquareCorridor(r, l, d);
	vector<Coords> corrds = g->getDoorCoords();

	r.move(NORTH);
	std::cout << stringTools::deserializeRoom(stringTools::drawRoom(g, r));



	delete g;
	return 0;
}


