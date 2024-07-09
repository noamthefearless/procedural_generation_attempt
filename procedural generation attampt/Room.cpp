#include "Room.h"





Room::Room(Coords& root, RoomTypes& type, RotationTypes& rotation, int& maxDoors, Door& door)
{
	m_root = root;
	m_type = type;
	addDoor(door);
	m_rotation = rotation;
	m_maxDoors = maxDoors;
}



/*
isCoordInRoom: this function will get a coord and check if it's in the room
input: the coord
output: a true if coord in room and false if not
*/
bool Room::isCoordInRoom(Coords coord) const
{
	vector<Coords> coords = getRoomCoords();
	for (auto i : coords)//going through all coords
	{
		if (i == coord)
		{
			return true;
		}
	}
	return false;
}




/*
addDoor: this function will set a new door
input: the door
output: non
*/
void Room::addDoor(Door& door)
{
	m_doors.push_back(door);
}

/*
getRoot: a getter function for the root
input: non
output: the root coords
*/
Coords Room::getRoot() const
{
	return m_root;
}


/*
getRotation: a getter function for the rotation
input: non
output: the rotation type
*/
RotationTypes Room::getRotation() const
{
	return m_rotation;
}



/*
getType: a getter function for the room type
input: non
output: the type
*/
RoomTypes Room::getType() const
{
	return m_type;
}


/*
getMaxDoors: a getter function for the maxDoors
input: non
output: the max doors
*/
int Room::getMaxDoors() const
{
	return m_maxDoors;
}







