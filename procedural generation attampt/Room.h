#pragma once
#include "Coords.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

struct Door;










enum RotationTypes
{
	STORAGE_CORRIDOR_FACING_NORTH = 0, STORAGE_CORRIDOR_FACING_EAST = 1, STORAGE_LONG_CORRIDOR_FACING_NORTH = 2,
	STORAGE_LONG_CORRIDOR_FACING_EAST = 3, STORAGE_T_INTERSECTION_FACING_NORTH = 4, STORAGE_T_INTERSECTION_FACING_EAST = 5,
	STORAGE_T_INTERSECTION_FACING_SOUTH = 6, STORAGE_T_INTERSECTION_FACING_WEST = 7, STORAGE_INTERSECTION_ROTATION = 8,
	STORAGE_TURN_FACING_NORTH = 9, STORAGE_TURN_FACING_SOUTH = 10, STORAGE_TURN_FACING_EAST = 11, STORAGE_TURN_FACING_WEST = 12

	

};

enum RoomTypes
{
	STORAGE_CORRIDOR = 0, STORAGE_LONG_CORRIDOR = 1, STORAGE_T_INTERSECTION = 2, STORAGE_INTERSECTION = 3,
	STORAGE_TURN = 4
};



class Room
{
public:
	Room(Coords& root, RoomTypes type, RotationTypes rotation, int maxDoors, Door& door); // c'tor

	bool isCoordInRoom(Coords coord) const;
	void addDoor(Door& door);
	bool isDoorCoord(Coords coord) const;
	vector<Door> getDoorsOfCoord(Coords coord) const;

	virtual vector<Coords> getRoomCoords() const = 0;
	virtual vector<Coords> getDoorCoords() const = 0;


	//getters:
	Coords getRoot() const;
	RoomTypes getType() const;
	RotationTypes getRotation() const;
	int getMaxDoors() const;
	vector<Door> getDoors() const;

protected:


	Coords m_root;
	RoomTypes m_type;
	RotationTypes m_rotation;
	vector<Door> m_doors;
	int m_maxDoors;
};

typedef struct Door
{
	Coords firstSide;
	Coords secondSide;
	Room* leadingTo = nullptr;
	Directions facing;
};





