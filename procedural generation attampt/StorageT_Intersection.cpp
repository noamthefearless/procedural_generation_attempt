#include "StorageT_Intersection.h"

/*
default c'tor: calling c'tor of Room class
*/
StorageT_Intersection::StorageT_Intersection(Coords& root, RotationTypes rotation, Door& door)
	: Room(root, STORAGE_T_INTERSECTION, rotation, 3, door)
{

}



/*
getRoomCoords: this function will return the coords for a T intersection
input: non
output: a vector of the coords
*/
vector<Coords> StorageT_Intersection::getRoomCoords() const
{
	vector<Coords> result;
	Directions direction1, direcrtion2, direction3;
	Coords coord = m_root;
	switch (m_rotation)
	{
	case STORAGE_T_INTERSECTION_FACING_NORTH:// getting correct directions for building
		direction1 = SOUTH;
		direcrtion2 = EAST;
		direction3 = WEST;
		break;
	case STORAGE_T_INTERSECTION_FACING_EAST:
		direction1 = WEST;
		direcrtion2 = NORTH;
		direction3 = SOUTH;
		break;
	case STORAGE_T_INTERSECTION_FACING_SOUTH:
		direction1 = NORTH;
		direcrtion2 = EAST;
		direction3 = WEST;
		break;
	case STORAGE_T_INTERSECTION_FACING_WEST:
		direction1 = EAST;
		direcrtion2 = NORTH;
		direction3 = SOUTH;
		break;
	default:
		break;
	}
	result.push_back(m_root);

	coord.move(direction1);// one step out
	result.push_back(coord);

	coord.move(direcrtion2);//and the 2 to its sides
	result.push_back(coord);

	coord.move(direction3, 2);
	result.push_back(coord);
	return result;
}






/*
getDoorCoords: this function will only return the coords where doors are placeable
input: non
output: a vector with the coords
*/
vector<Coords> StorageT_Intersection::getDoorCoords() const
{
	vector<Coords> result = getRoomCoords();
	result.erase(result.begin() + 1);// only the sides of a t intersection are able to have doors
	//this is the middle node, where no doors are allowed
	return result;
}





