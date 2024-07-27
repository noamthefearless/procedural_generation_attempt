#pragma once
#include "Room.h"
#include <iostream>
class StorageSmallUnit : public Room
{
public:
	StorageSmallUnit(Coords& root, RotationTypes rotation, Door& door);
	virtual vector<Coords> getRoomCoords() const;
	virtual vector<Coords> getDoorCoords() const;
};

