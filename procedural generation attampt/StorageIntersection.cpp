#include "StorageIntersection.h"
/*
default c'tor: calling c'tor of Room class
*/
StorageIntersection::StorageIntersection(Coords& root, RotationTypes rotation, Door& door)
	: Room(root, STORAGE_INTERSECTION, rotation, 4, door)
{

}


/*
getRoomCoords: this function will return the coords for an intersection
input: non
output: a vector of the coords
*/
vector<Coords> StorageIntersection::getRoomCoords() const
{
	vector<Coords> result;
	Coords coord = m_root;
	result.push_back(m_root);

	coord.move(NORTH);// pushing on all directions from the center
	result.push_back(coord);

	coord.move(SOUTH, 2);
	result.push_back(coord);

	coord.move(NORTH);
	coord.move(EAST);
	result.push_back(coord);

	coord.move(WEST, 2);
	result.push_back(coord);

	return result;
}






/*
getDoorCoords: this function will only return the coords where doors are placeable
input: non
output: a vector with the coords
*/
vector<Coords> StorageIntersection::getDoorCoords() const
{
	vector<Coords> result = getRoomCoords();
	result.erase(result.begin());// only the center cant have any doors, and the center is alwys at index 0
	return result;
}





