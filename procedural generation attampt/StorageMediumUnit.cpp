#include "StorageMediumUnit.h"

/*
default c'tor: calling c'tor of Room class
*/
StorageMediumUnit::StorageMediumUnit(Coords& root, RotationTypes rotation, Door& door)
	: Room(root, STORAGE_MEDIUM_UNIT, rotation, 3, door)
{

}


/*
getRoomCoords: this function will return the coords for a medium unit
input: non
output: a vector of the coords
*/
vector<Coords> StorageMediumUnit::getRoomCoords() const
{
	vector<Coords> result;
	Coords coord = m_root;
	Directions direction1, direction2, direction3;

	switch (m_rotation)
	{
	case STORAGE_MEDIUM_UNIT_FACING_NORTH:
		direction1 = NORTH;
		direction2 = SOUTH;
		direction3 = WEST;
		break;
	case STORAGE_MEDIUM_UNIT_FACING_EAST:
		direction1 = EAST;
		direction2 = WEST;
		direction3 = NORTH;
		break;
	default:
		break;
	}

	
	result.push_back(m_root);// this room root is in the bottom left corner, and it only have 4 coords
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


	return result;
}






/*
getDoorCoords: this function will only return the coords where doors are placeable
input: non
output: a vector with the coords
*/
vector<Coords> StorageMediumUnit::getDoorCoords() const
{
	return getRoomCoords();// all coords in a medium unit are door coords
}





