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

	Door d, b;
	p.move(NORTH, 2);
	d.facing = EAST;
	d.firstSide = p;
	p.move(EAST);
	d.secondSide = p;
	d.leadingTo = nullptr;
	RotationTypes l = STORAGE_CORRIDOR_FACING_NORTH;
	Room* g = new StorageCorridor(r, l, d), *k;
	//vector<Coords> corrds = g->getDoorCoords();

	r.move(NORTH);


	b.firstSide = d.secondSide;
	b.secondSide = d.firstSide;
	b.facing = WEST;
	b.leadingTo = g;

	d.leadingTo = new StorageCorridor(p, STORAGE_CORRIDOR_FACING_EAST, b);
	g->setRoomToNullDoor(d);



	p.move(EAST, 2);
	k = g->searchRoom(p);
	b.firstSide = p;
	b.facing = NORTH;
	p.move(NORTH);
	b.secondSide = p;

	d.firstSide = b.secondSide;
	d.secondSide = b.firstSide;
	d.facing = SOUTH;
	d.leadingTo = k;
	b.leadingTo = new StorageCloset(p, STORAGE_CLOSET_ROTATION, d);
	k->addDoor(b);


	

	std::cout << stringTools::deserializeRoom(stringTools::drawRoom(g, r));
	p.move(SOUTH);
	std::cout << stringTools::deserializeRoom(stringTools::drawRoom(g->searchRoom(p), p));


	p.move(NORTH);
	std::cout << stringTools::deserializeRoom(stringTools::drawRoom(g->searchRoom(p), p));

	delete g->searchRoom(p);
	delete g;
	delete k;
	return 0;
}


