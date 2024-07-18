#include "Room.h"





Room::Room(Coords& root, RoomTypes type, RotationTypes rotation, int maxDoors, Door& door)
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
isDoorCoord: this function will check a coord if its a door coord
input: a coord to check
output: a bool
*/
bool Room::isDoorCoord(Coords coord) const
{
	vector<Coords> doors = getDoorCoords();//getting doors
	for (auto itt : doors)
	{
		if (coord == itt)//if coord door
		{
			return true;
		}
	}
	return false;
}

/*
getDoorsOfCoords: this function will return all doors of a specific coord
input: the coord
output: the doors of the coord
*/
vector<Door> Room::getDoorsOfCoord(Coords coord) const
{
	vector<Door> result, allDoors;
	if (isDoorCoord(coord) == false)//checking if its even a door coord
	{
		return result;
	}
	allDoors = getDoors();
	for (auto itt : allDoors)
	{
		if (itt.firstSide == coord || itt.secondSide == coord)// if one of the sides of the door is the coord
		{
			result.push_back(itt);
		}
	}
	return result;


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


/*
getDoor: a getter function for the doors
input: non
output: the Doors
*/
vector<Door> Room::getDoors() const
{
	return m_doors;
}





