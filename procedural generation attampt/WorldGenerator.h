#pragma once
#include "RandTools.h"
#include <iostream>
#include "Coords.h"
#include <vector>
#include "Room.h"
#include "stringTools.h"
#include "StorageCorridor.h"
#include "StorageLongCorridor.h"
#include "StorageT_Intersection.h"
#include "StorageIntersection.h"
#include "StorageTurn.h"
#include "StorageCloset.h"
#include "StorageSmallUnit.h"
#include "StorageMediumUnit.h"
#include "StorageBigUnit.h"
#include "StorageVehicleUnit.h"
#include "StorageConnectedCorridors.h"
#include "StorageSquareCorridor.h"

class WorldGenerator
{
public:
	Room* getRootRoom() const;




//private:  (for now everything will be public for debugging purpouses)
	bool isRoomInCollision(Room* room);
	Room* m_RoomRoot;
};

