#include "StorageCorridor.h"


/*
default c'tor: calling c'tor of Room class
*/
StorageCorridor::StorageCorridor(Coords& root, RoomTypes& type, RotationTypes& rotation, int& maxDoors, Door& door)
	: Room(root, type, rotation, maxDoors, door)
{

}



/*
getRoomCoords: this function will return the coords for a storage corridor
input: non
output: a vector of the coords
*/
vector<Coords> StorageCorridor::getRoomCoords() const
{
	vector<Coords> result;
	Coords coord = m_root;
	result.push_back(coord);//pushing the root
	Directions facing;
	switch (m_rotation)
	{
	case STORAGE_CORRIDOR_FACING_NORTH: //mathcing rotation
		facing = NORTH;
		break;
	case STORAGE_CORRIDOR_FACING_EAST:
		facing = EAST;
		break;
	default:
		std::cerr << "debug: error occured, rotation in storage corridor" << std::endl;
		break;
	}

	coord.move(facing);//moving and adding to the result twice. storage corridors are only 3 coordinates
	result.push_back(coord);
	coord.move(facing);
	result.push_back(coord);
	
	//coord.move(WEST);
	//result.push_back(coord);
	//coord.move(WEST);
	//result.push_back(coord);
	//coord.move(SOUTH);
	//result.push_back(coord);
	//coord.move(SOUTH);
	//result.push_back(coord);
	//coord.move(EAST);
	//result.push_back(coord);



	return result;
}






/*
getDoorCoords: this function will only return the coords where doors are placeable
input: non
output: a vector with the coords
*/
vector<Coords> StorageCorridor::getDoorCoords() const
{
	vector<Coords> result = getRoomCoords();
	result.erase(result.begin() + 1);// only the sides of a corridor are able to have doors
	return result;
}






