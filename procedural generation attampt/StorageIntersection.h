#pragma once
#include "Room.h"
#include <iostream>
class StorageIntersection : public Room
{
public:
	StorageIntersection(Coords& root, RotationTypes rotation, Door& door);
	virtual vector<Coords> getRoomCoords() const;
	virtual vector<Coords> getDoorCoords() const;
};

