#pragma once
#include "Room.h"
#include <iostream>
class StorageVehicleUnit : public Room
{
public:
	StorageVehicleUnit(Coords& root, RotationTypes rotation, Door& door);
	virtual vector<Coords> getRoomCoords() const;
	virtual vector<Coords> getDoorCoords() const;
};

