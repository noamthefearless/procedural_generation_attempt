#include "StorageTurn.h"
/*
default c'tor: calling c'tor of Room class
*/
StorageTurn::StorageTurn(Coords& root, RotationTypes rotation, Door& door)
	: Room(root, STORAGE_TURN, rotation, 2, door)
{

}


/*
getRoomCoords: this function will return the coords for a turn
input: non
output: a vector of the coords
*/
vector<Coords> StorageTurn::getRoomCoords() const
{
	vector<Coords> result;
	Coords coord = m_root;
	Directions direction1, direction2;
	switch (m_rotation)
	{
	case STORAGE_TURN_FACING_NORTH:
		direction1 = NORTH;
		direction2 = WEST;
		break;
	case STORAGE_TURN_FACING_SOUTH:
		direction1 = EAST;
		direction2 = SOUTH;
		break;
	case STORAGE_TURN_FACING_EAST:
		direction1 = NORTH;
		direction2 = EAST;
		break;
	case STORAGE_TURN_FACING_WEST:
		direction1 = WEST;
		direction2 = SOUTH;
		break;
	default:
		break;
	}
	result.push_back(coord);// pushing root

	coord.move(direction1);//going twice in direction one
	result.push_back(coord);

	coord.move(direction1);
	result.push_back(coord);

	coord = m_root;

	coord.move(direction2);//and twice in direction 2
	result.push_back(coord);

	coord.move(direction2);
	result.push_back(coord);

	return result;
}






/*
getDoorCoords: this function will only return the coords where doors are placeable
input: non
output: a vector with the coords
*/
vector<Coords> StorageTurn::getDoorCoords() const
{
	vector<Coords> result = getRoomCoords();
	result.erase(result.begin());// these lines, are erasing indexes 0, one and 3, leac=ving only the doors in 2 and 4
	result.erase(result.begin());
	result.erase(result.begin() + 1);

	return result;
}





