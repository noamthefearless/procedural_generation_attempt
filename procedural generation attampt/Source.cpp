#include "RandTools.h"
#include <iostream>
#include "Coords.h"
#include <vector>
#include "Room.h"
#include "stringTools.h"
#include "StorageCorridor.h"
#include "StorageLongCorridor.h"
#include "StorageT_Intersection.h"


int main()
{
	Coords r, p;
	p.move(SOUTH);
	Door d;
	d.facing = SOUTH;
	d.firstSide = r;
	d.secondSide = p;
	d.leadingTo = nullptr;
	RotationTypes l = STORAGE_T_INTERSECTION_FACING_SOUTH;
	Room* g = new StorageT_Intersection(r, l, d);


	
	std::cout << stringTools::deserializeRoom(stringTools::drawRoom(g, r));



	delete g;
	return 0;
}


