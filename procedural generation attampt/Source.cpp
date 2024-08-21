#include "WorldGenerator.h"
#include <iostream>


int main()
{
	//1723994599
	unsigned long long seed = 5;
	WorldGenerator w(seed);
	Coords coord1, coord2;
	vector<Coords> vc1;
	Door door;
	coord2.move(EAST, 2);
	door.facing = EAST;
	door.firstSide = coord2;
	coord2.move(EAST);
	door.secondSide = coord2;
	w.m_RoomRoot = new StorageCorridor(coord1, STORAGE_CORRIDOR_FACING_EAST, door);
	door.leadingTo = w.makeValidType(coord2, w.getOppositeDoor(w.m_RoomRoot, door));
	w.m_RoomRoot->setRoomToNullDoor(door);
	w.addNewDoorToRoomIfPossible(w.m_RoomRoot);
	w.addNewDoorToRoomIfPossible(w.m_RoomRoot->getDoors()[0].leadingTo);
	w.addNewDoorToRoomIfPossible(w.m_RoomRoot->getDoors()[1].leadingTo);
	w.addNewDoorToRoomIfPossible(w.m_RoomRoot->getDoors()[0].leadingTo);
	w.addNewDoorToRoomIfPossible(w.m_RoomRoot->getDoors()[0].leadingTo->getDoors()[1].leadingTo);



	
	w.walkInWorld(w.m_RoomRoot, w.m_RoomRoot->getRoot());
	//std::cout  << StringTools::deserializeRoom(StringTools::drawRoom(w.m_RoomRoot, w.m_RoomRoot->getRoot()));
	//std::cout << StringTools::deserializeRoom(StringTools::drawRoom(w.m_RoomRoot->getDoors()[0].leadingTo, w.m_RoomRoot->getDoors()[0].leadingTo->getRoot()));
	//std::cout << StringTools::deserializeRoom(StringTools::drawRoom(w.m_RoomRoot->getDoors()[1].leadingTo, w.m_RoomRoot->getDoors()[1].leadingTo->getRoot()));

	return 0;
}


