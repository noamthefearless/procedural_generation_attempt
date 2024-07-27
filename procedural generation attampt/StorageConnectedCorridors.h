#pragma once
#include "Room.h"
#include <iostream>
class StorageConnectedCorridors : public Room
{
public:
	StorageConnectedCorridors(Coords& root, RotationTypes rotation, Door& door);
	virtual vector<Coords> getRoomCoords() const;
	virtual vector<Coords> getDoorCoords() const;
};

