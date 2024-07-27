#include "StorageConnectedCorridors.h"


/*
default c'tor: calling c'tor of Room class
*/
StorageConnectedCorridors::StorageConnectedCorridors(Coords& root, RotationTypes rotation, Door& door)
	: Room(root, STORAGE_CONNECTED_CORRIDORS, rotation, 4, door)
{

}



/*
getRoomCoords: this function will return the coords for a storage connected corridor
input: non
output: a vector of the coords
*/
vector<Coords> StorageConnectedCorridors::getRoomCoords() const
{
	vector<Coords> result;
	Coords coord = m_root;
	Directions direction1, direction2;
	switch (m_rotation)
	{
	case STORAGE_CONNECTED_CORRIDORS_FACING_NORTH: //mathcing rotation
		direction1 = NORTH;
		direction2 = EAST;
		break;
	case STORAGE_CONNECTED_CORRIDORS_FACING_EAST:
		direction1 = EAST;
		direction2 = NORTH;
		break;
	default:
		break;
	}
	result.push_back(coord);//pushing the root
	
	coord.move(direction2);
	result.push_back(coord);

	coord.move(direction2, -2);
	result.push_back(coord);// first the connection part

	coord.move(direction1);
	result.push_back(coord);

	coord.move(direction1, -2);
	result.push_back(coord);

	coord.move(direction2, 2);
	result.push_back(coord);

	coord.move(direction1, 2);
	result.push_back(coord);
	return result;
}






/*
getDoorCoords: this function will only return the coords where doors are placeable
input: non
output: a vector with the coords
*/
vector<Coords> StorageConnectedCorridors::getDoorCoords() const
{
	vector<Coords> result = getRoomCoords();
	result.erase(result.begin());
	result.erase(result.begin());
	result.erase(result.begin());

	return result;
}






