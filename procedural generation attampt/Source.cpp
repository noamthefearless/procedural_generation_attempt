#include "WorldGenerator.h"
#include <iostream>


int main()
{
	WorldGenerator w(2132131);
	Coords coord1, coord2;
	vector<Coords> vc1;
	w.setLineOfCoordsInRow(coord1, vc1, EAST, 5);


	return 0;
}


