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
setRoomToNullDoor: this funciton will set a lead value of a new room to a nulldoor
input: the door with the updated leadingTo val
output: non
*/
void Room::setRoomToNullDoor(Door& door)
{
	for (int i = 0; i < m_doors.size(); i++)
	{
		//checking if the doors are identical, and if the current one is a nulldoor
		if (m_doors[i].firstSide == door.firstSide && m_doors[i].secondSide == door.secondSide && m_doors[i].facing == door.facing && m_doors[i].leadingTo == nullptr)
		{
			m_doors[i].leadingTo = door.leadingTo;
			return;
		}
	}
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
getRoomThroughDoor: this funtion will get a room that a door is pointing at
input: the door coord and its direction to find the door itself
output; the room ptr or a null if no door was found
*/
Room* Room::getRoomThroughDoor(Coords doorCoord, Directions facing)
{
	vector<Door> doors;
	doors = getDoors();// getting all doors
	for (auto itt : doors)
	{
		if (itt.firstSide == doorCoord && itt.facing == facing)//if matches
		{
			return itt.leadingTo;//get the leading room
		}
	}
	return nullptr;//non were found
}




/*
isDoorExists: this function will check if a door exists
input: the coord, and the direction of the door
output: a bool with true if exists
*/
bool Room::isDoorExists(Coords doorCoord, Directions facing)
{
	vector<Coords> doorCoords = getDoorCoords();
	vector<Door> doors = getDoors();
	if (std::find(doorCoords.begin(), doorCoords.end(), doorCoord) == doorCoords.end())// checking if the coord is eve a door coord
	{
		return false;
	}

	for (auto itt : doors)// going through the doors
	{
		if (itt.firstSide == doorCoord && itt.facing == facing)// if on the same coord and facing the same way
		{
			return true;//then exists
		}
	}
	return false;
}



/*
searchRoom: this function will search for a room with the findRoomUsingCoord helper function
input: the coord to search for
output: the room if exists
*/
Room* Room::searchRoom(Coords& coord)
{
	std::unordered_set<Room*> visitedRooms;
	return findRoomUsingCoord(coord, visitedRooms);
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







/*
findRoomUsingCoord: this function will search for a room recursivly
input: the coord to look in and the room that are already visited in previous itterations
output: the room ptr or nullptr if not found
*/
Room* Room::findRoomUsingCoord(Coords& coord, std::unordered_set<Room*>& visitedRooms)
{
	Room* result;
	if (visitedRooms.find(this) != visitedRooms.end())// if already visited
	{
		return nullptr;
	}

	visitedRooms.insert(this);// not visited yet, so this room needs to be inserted

	if (isCoordInRoom(coord))// this is the correct room
	{
		return this;
	}

	for (auto itt : m_doors)
	{
		if (itt.leadingTo != nullptr)// if the door leads somewhere
		{
			result = itt.leadingTo->findRoomUsingCoord(coord, visitedRooms);//search there too
			if (result != nullptr)// if the true result has been returned then pass it along
			{
				return result;
			}

		}

	}

	return nullptr;//nothing was found...
}








