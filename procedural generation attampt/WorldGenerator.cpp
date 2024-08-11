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
clearRooms: this function will clear all the room in a generated world
input: current room and visited rooms
output: non
*/
void WorldGenerator::clearRooms(Room* currentRoom, std::unordered_set<Room*>& visitedRooms)
{
	if (visitedRooms.find(currentRoom) != visitedRooms.end())// if already visited
	{
		return;
	}

	visitedRooms.insert(currentRoom);// not visited yet, so this room needs to be inserted

	for (auto itt : currentRoom->getDoors())
	{
		clearRooms(itt.leadingTo, visitedRooms);// clearing all rooms
	}


	delete currentRoom;//deleting this room
	return;
}





