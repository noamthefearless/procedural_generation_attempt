#include "StorageSquareCorridor.h"


/*
default c'tor: calling c'tor of Room class
*/
StorageSquareCorridor::StorageSquareCorridor(Coords& root, RotationTypes rotation, Door& door)
	: Room(root, STORAGE_SQUARE_CORRIDOR, rotation, 3, door)
{

}



/*
getRoomCoords: this function will return the coords for a storage square corridor
input: non
output: a vector of the coords
*/
vector<Coords> StorageSquareCorridor::getRoomCoords() const
{
	vector<Coords> result;
	Coords coord = m_root;
	result.push_back(coord);// going in a circle

	coord.move(EAST);
	result.push_back(coord);

	coord.move(EAST);
	result.push_back(coord);

	coord.move(NORTH);
	result.push_back(coord);

	coord.move(NORTH);
	result.push_back(coord);

	coord.move(WEST);
	result.push_back(coord);

	coord.move(WEST);
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
vector<Coords> StorageSquareCorridor::getDoorCoords() const
{
	vector<Coords> result, coords = getRoomCoords();

	result.push_back(coords[0]);// pushing only the door coords
	result.push_back(coords[2]);
	result.push_back(coords[4]);
	result.push_back(coords[6]);




	return result;
}






