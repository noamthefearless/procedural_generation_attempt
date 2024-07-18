#pragma once
#include "Room.h"
#include <iostream>
class StorageLongCorridor : public Room
{
public:
	StorageLongCorridor(Coords& root, RotationTypes rotation, Door& door);
	virtual vector<Coords> getRoomCoords() const;
	virtual vector<Coords> getDoorCoords() const;
};

