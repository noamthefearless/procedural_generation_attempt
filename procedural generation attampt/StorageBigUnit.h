#pragma once
#include "Room.h"
#include <iostream>
class StorageBigUnit : public Room
{
public:
	StorageBigUnit(Coords& root, RotationTypes rotation, Door& door);
	virtual vector<Coords> getRoomCoords() const;
	virtual vector<Coords> getDoorCoords() const;
};

