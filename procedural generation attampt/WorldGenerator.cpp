#include "WorldGenerator.h"



/*
getRootRoom: this function will the root room, wich is the starter room
input: non
output: the root room
*/
Room* WorldGenerator::getRootRoom() const
{
	return m_RoomRoot;
}


//c'tor: this will set the initial seed
WorldGenerator::WorldGenerator(unsigned long long seed)
{
	RandTools::setSeed(seed);
}





//d'tor: this function will delete the world >:)
WorldGenerator::~WorldGenerator()
{
	std::unordered_set<Room*> visitedRooms;
	if (m_RoomRoot != nullptr)// if the root even exist
	{
		clearRooms(m_RoomRoot, visitedRooms);
	}
}





/*
isRoomInCollision: this function will check if a room is in collision with other rooms with the coords
input: the room to check for collision
output: a boolean
*/
bool WorldGenerator::isRoomInCollision(Room* room)
{
	vector<Coords> roomCoords = room->getRoomCoords();// getting the room coords
	Room* searchedRoom;
	for (auto itt : roomCoords)// going through the coords
	{
		searchedRoom = m_RoomRoot->searchRoom(itt);// searching for a room in the current coord
		if (searchedRoom != nullptr)// if a room is find
		{
			if (searchedRoom == room)
			{
				return false;// this is the case for searching a room that is already present in the world
			}
			return true;
		}
	}
	return false;
}









/*
clearRooms: this function will clear all the room in a generated world
input: current room and visited rooms
output: non
*/
void WorldGenerator::clearRooms(Room* currentRoom, std::unordered_set<Room*>& visitedRooms)
{
	vector<Door> doors;
	if (visitedRooms.find(currentRoom) != visitedRooms.end())// if already visited
	{
		return;
	}

	visitedRooms.insert(currentRoom);// not visited yet, so this room needs to be inserted
	doors = currentRoom->getDoors();
	for (auto itt : doors)
	{
		clearRooms(itt.leadingTo, visitedRooms);// clearing all rooms
	}


	delete currentRoom;//deleting this room
	return;
}





