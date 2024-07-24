#include "StorageBigUnit.h"

/*
default c'tor: calling c'tor of Room class
*/
StorageBigUnit::StorageBigUnit(Coords& root, RotationTypes rotation, Door& door)
	: Room(root, STORAGE_BIG_UNIT, rotation, 4, door)
{

}


/*
getRoomCoords: this function will return the coords for a big unit
input: non
output: a vector of the coords
*/
vector<Coords> StorageBigUnit::getRoomCoords() const
{
	vector<Coords> result;
	Coords coord = m_root;
	Directions direction1, direction2, direction3;

	switch (m_rotation)
	{
	case STORAGE_BIG_UNIT_FACING_NORTH:
		direction1 = NORTH;
		direction2 = SOUTH;
		direction3 = WEST;
		break;
	case STORAGE_BIG_UNIT_FACING_EAST:
		direction1 = EAST;
		direction2 = WEST;
		direction3 = NORTH;
		break;
	default:
		break;
	}


	result.push_back(m_root);// this room root is in the bottom left corner, and it only have 12 coords
	coord.move(direction1);
	result.push_back(coord);

	coord.move(direction1);
	result.push_back(coord);

	coord.move(direction1);
	result.push_back(coord);// building first layer

	coord.move(direction3);
	result.push_back(coord);

	coord.move(direction2);
	result.push_back(coord);

	coord.move(direction2);
	result.push_back(coord);

	coord.move(direction2);//and second layer
	result.push_back(coord);

	coord.move(direction3);
	result.push_back(coord);

	coord.move(direction1);
	result.push_back(coord);

	coord.move(direction1);
	result.push_back(coord);

	coord.move(direction1);
	result.push_back(coord);// building third layer

	return result;
}






/*
getDoorCoords: this function will only return the coords where doors are placeable
input: non
output: a vector with the coords
*/
vector<Coords> StorageBigUnit::getDoorCoords() const
{
	vector<Coords> result = getRoomCoords();
	result.erase(result.begin() + 5);
	result.erase(result.begin() + 5);// erasing the middle coords
	return result;
}





