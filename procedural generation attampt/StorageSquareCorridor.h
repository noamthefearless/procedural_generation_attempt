#pragma once
#include "Room.h"
#include <iostream>
class StorageSquareCorridor : public Room
{
public:
	StorageSquareCorridor(Coords& root, RotationTypes rotation, Door& door);
	virtual vector<Coords> getRoomCoords() const;
	virtual vector<Coords> getDoorCoords() const;
};

