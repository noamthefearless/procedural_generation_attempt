#include "StorageSmallUnit.h"
/*
default c'tor: calling c'tor of Room class
*/
StorageSmallUnit::StorageSmallUnit(Coords& root, RotationTypes rotation, Door& door)
	: Room(root, STORAGE_SMALL_UNIT, rotation, 2, door)
{

}


/*
getRoomCoords: this function will return the coords for a small unit
input: non
output: a vector of the coords
*/
vector<Coords> StorageSmallUnit::getRoomCoords() const
{
	vector<Coords> result;
	Coords coord = m_root;
	result.push_back(m_root);// this room root is in the bottom left corner, and it only have 4 coords

	coord.move(NORTH);
	result.push_back(coord);

	coord.move(EAST);
	result.push_back(coord);

	coord.move(SOUTH);
	result.push_back(coord);


	return result;
}






/*
getDoorCoords: this function will only return the coords where doors are placeable
input: non
output: a vector with the coords
*/
vector<Coords> StorageSmallUnit::getDoorCoords() const
{
	return getRoomCoords();// all coords in a small unit are door coords
}





