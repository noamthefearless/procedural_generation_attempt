#pragma once
#include "Coords.h"
#include <vector>
#include <string>
using std::string;
using std::vector;



typedef struct Door
{
	Coords firstSide;
	Coords secondSide;
	Directions facing;
};



enum RotationTypes
{
	STORAGE_CORRIDOR_FACING_NORTH = 0, STORAGE_CORRIDOR_FACING_EAST = 1, STORAGE_LONG_CORRIDOR_FACING_NORTH = 2,
	STORAGE_LONG_CORRIDOR_FACING_EAST = 3
	

};

enum RoomTypes
{
	STORAGE_CORRIDOR = 0, STORAGE_LONG_CORRIDOR = 1
};



class Room
{
public:
	Room(Coords root, RoomTypes type, RotationTypes rotation, int maxDoors, Door door); // c'tor

	bool isCoordInRoom(Coords coord) const;

	virtual vector<Coords> getRoomCoords() const = 0;
	virtual vector<Coords> getDoorCoords() const = 0;
	virtual string getRoomAsStr() const = 0;


	//getters:
	Coords getRoot() const;
	RoomTypes getTypr(); const
	RotationTypes getRotation(); const
	int getMaxDoors() const;

protected:


	Coords m_root;
	RoomTypes type;
	RotationTypes rotation;
	vector<Door> m_doors;
	int maxDoors;
};






