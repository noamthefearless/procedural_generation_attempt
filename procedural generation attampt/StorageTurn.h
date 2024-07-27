#pragma once
#include "Room.h"
#include <iostream>
class StorageTurn : public Room
{
public:
	StorageTurn(Coords& root, RotationTypes rotation, Door& door);
	virtual vector<Coords> getRoomCoords() const;
	virtual vector<Coords> getDoorCoords() const;
};

