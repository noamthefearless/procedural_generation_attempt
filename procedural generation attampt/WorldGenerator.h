#pragma once
#include "RandTools.h"
#include <iostream>
#include "Coords.h"
#include <vector>
#include "Room.h"
#include "stringTools.h"
#include "StorageCorridor.h"
#include "StorageLongCorridor.h"
#include "StorageT_Intersection.h"
#include "StorageIntersection.h"
#include "StorageTurn.h"
#include "StorageCloset.h"
#include "StorageSmallUnit.h"
#include "StorageMediumUnit.h"
#include "StorageBigUnit.h"
#include "StorageVehicleUnit.h"
#include "StorageConnectedCorridors.h"
#include "StorageSquareCorridor.h"
#include <conio.h>

class WorldGenerator
{
public:
	WorldGenerator(unsigned long long seed);
	~WorldGenerator();


	Room* getRootRoom() const;




//private:  (for now everything will be public for debugging purpouses)

	bool isRoomInCollision(Room* room);
	void clearRooms(Room* currentRoom, std::unordered_set<Room*>& visitedRooms);
	vector<RoomTypes> getRandomizedRoomTypes();
	vector<RotationTypes> getRandomizedRotatinTypes(RoomTypes roomType);
	void setLineOfCoordsInRow(Coords& starterCoord, vector<Coords>& line, Directions direction, int n);
	vector<Coords> getPossibleRootCoords(Coords coord, Directions doorDirection);
	Room* allocateRoom(Coords root, RoomTypes type, RotationTypes rotation, Door door);
	Door getOppositeDoor(Room* room, Door door);
	Directions getOppositeDirection(Directions direction);
	Room* makeValidRoom(Coords voidCoord, RoomTypes type, RotationTypes rotation, Door door);
	Room* makeValidRotation(Coords voidCoord, RoomTypes type, Door door);
	Room* makeValidType(Coords voidCoord, Door door);
	vector<Directions> getFourDirectionsInRandomOreder();
	bool addNewDoorToRoomIfPossible(Room* room);
	void walkInWorld(Room* currentRoom, Coords walkerCoord);




	Room* m_RoomRoot = nullptr;
};





