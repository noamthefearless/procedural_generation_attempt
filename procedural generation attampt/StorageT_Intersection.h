#pragma once
#include "Room.h"
#include <iostream>
class StorageT_Intersection : public Room
{
public:
	StorageT_Intersection(Coords& root, RotationTypes rotation, Door& door);
	virtual vector<Coords> getRoomCoords() const;
	virtual vector<Coords> getDoorCoords() const;
};

