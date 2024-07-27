#include "StorageCloset.h"
/*
default c'tor: calling c'tor of Room class
*/
StorageCloset::StorageCloset(Coords& root, RotationTypes rotation, Door& door)
	: Room(root, STORAGE_CLOSET, rotation, 1, door)
{

}


/*
getRoomCoords: this function will return the coords for a closet
input: non
output: a vector of the coords
*/
vector<Coords> StorageCloset::getRoomCoords() const
{
	vector<Coords> result;
	result.push_back(m_root);// a closet is only one coordinate
	return result;
}






/*
getDoorCoords: this function will only return the coords where doors are placeable
input: non
output: a vector with the coords
*/
vector<Coords> StorageCloset::getDoorCoords() const
{
	return getRoomCoords();
}





