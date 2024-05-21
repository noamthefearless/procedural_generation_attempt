#include "StorageCorridor.h"


/*
default c'tor: calling c'tor of Room class
*/
StorageCorridor::StorageCorridor(Coords& root, RoomTypes& type, RotationTypes& rotation, int& maxDoors, Door& door)
	: Room(root, type, rotation, maxDoors, door)
{

}






