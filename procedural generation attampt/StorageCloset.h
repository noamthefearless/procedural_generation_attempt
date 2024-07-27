#pragma once
#include "Room.h"
#include <iostream>
class StorageCloset : public Room
{
public:
	StorageCloset(Coords& root, RotationTypes rotation, Door& door);
	virtual vector<Coords> getRoomCoords() const;
	virtual vector<Coords> getDoorCoords() const;
};

