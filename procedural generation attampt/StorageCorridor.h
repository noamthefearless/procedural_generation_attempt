#pragma once
#include "Room.h"
#include <iostream>
class StorageCorridor : public Room
{
public:
	StorageCorridor(Coords& root, RotationTypes rotation, Door& door);
	virtual vector<Coords> getRoomCoords() const;
	virtual vector<Coords> getDoorCoords() const;
};

