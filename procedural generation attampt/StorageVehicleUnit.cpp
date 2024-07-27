#include "StorageVehicleUnit.h"

/*
default c'tor: calling c'tor of Room class
*/
StorageVehicleUnit::StorageVehicleUnit(Coords& root, RotationTypes rotation, Door& door)
	: Room(root, STORAGE_VEHICLE_UNIT, rotation, 2, door)
{

}


/*
getRoomCoords: this function will return the coords for a vehicle unit
input: non
output: a vector of the coords
*/
vector<Coords> StorageVehicleUnit::getRoomCoords() const
{
	vector<Coords> result;
	Coords coord = m_root;
	Directions direction1, direction2, direction3;

	switch (m_rotation)
	{
	case STORAGE_VEHICLE_UNIT_FACING_NORTH:
		direction1 = EAST;
		direction2 = WEST;
		direction3 = NORTH;
		break;
	case STORAGE_VEHICLE_UNIT_FACING_EAST:
		direction1 = SOUTH;
		direction2 = NORTH;
		direction3 = EAST;
		break;
	case STORAGE_VEHICLE_UNIT_FACING_SOUTH:
		direction1 = WEST;
		direction2 = EAST;
		direction3 = SOUTH;
		break;
	case STORAGE_VEHICLE_UNIT_FACING_WEST:
		direction1 = NORTH;
		direction2 = SOUTH;
		direction3 = WEST;
		break;
	default:
		break;
	}


	result.push_back(m_root);// the first layer has only 2 coords
	coord.move(direction1, 3);
	result.push_back(coord);

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

	coord.move(direction3);
	result.push_back(coord);

	coord.move(direction2);//fourth and final
	result.push_back(coord);

	coord.move(direction2);
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
vector<Coords> StorageVehicleUnit::getDoorCoords() const
{
	vector<Coords> result, coords = getRoomCoords();
	result.push_back(coords[0]);
	result.push_back(coords[1]);//in this type of room, only the bottom part (the "legs"), can have doors
	return result;
}





