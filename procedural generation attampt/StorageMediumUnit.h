#pragma once
#include "Room.h"
#include <iostream>
class StorageMediumUnit : public Room
{
public:
	StorageMediumUnit(Coords& root, RotationTypes rotation, Door& door);
	virtual vector<Coords> getRoomCoords() const;
	virtual vector<Coords> getDoorCoords() const;
};

