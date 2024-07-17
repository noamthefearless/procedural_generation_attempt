#include "RandTools.h"
#include <iostream>
#include "Coords.h"
#include <vector>
#include "Room.h"
#include "stringTools.h"
#include "StorageCorridor.h"


int main()
{
	Coords r, p;
	p.move(SOUTH);
	Door d;
	d.facing = SOUTH;
	d.firstSide = r;
	d.secondSide = p;
	d.leadingTo = nullptr;
	int a = 2;
	RoomTypes u = STORAGE_LONG_CORRIDOR;
	RotationTypes l = STORAGE_CORRIDOR_FACING_EAST;
	Room* g = new StorageCorridor(r, u, l, d);


	r.move(EAST);
	std::cout << stringTools::deserializeRoom(stringTools::drawRoom(g, r));



	delete g;
	return 0;
}


