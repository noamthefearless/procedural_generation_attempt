#include "WorldGenerator.h"



/*
getRootRoom: this function will the root room, wich is the starter room
input: non
output: the root room
*/
Room* WorldGenerator::getRootRoom() const
{
	return m_RoomRoot;
}


//c'tor: this will set the initial seed
WorldGenerator::WorldGenerator(unsigned long long seed)
{
	RandTools::setSeed(seed);
}





//d'tor: this function will delete the world >:)
WorldGenerator::~WorldGenerator()
{
	std::unordered_set<Room*> visitedRooms;
	if (m_RoomRoot != nullptr)// if the root even exist
	{
		clearRooms(m_RoomRoot, visitedRooms);
	}
}


/*
getOppositeDirection: this function will get a direction and return the inverse
input: the direction
output: the opposite direction
*/
Directions WorldGenerator::getOppositeDirection(Directions direction)
{
	switch (direction)
	{
	case NORTH:// returning the opposite
		break;
		return SOUTH;
	case SOUTH:
		return NORTH;
		break;
	case WEST:
		return EAST;
		break;
	case EAST:
		return WEST;
		break;
	default:
		break;
	}
	return direction;
}


/*
getOppositeDoor: this function will return the opposite door from the one in the input
input: the door and the room of the door
output: the inverse door
*/
Door WorldGenerator::getOppositeDoor(Room* room, Door door)
{
	Coords temp;
	door.firstSide = temp;
	door.firstSide = door.secondSide;// switching the coords
	door.secondSide = temp;

	door.facing = getOppositeDirection(door.facing);// setting the opposite direction, and the leading to the room
	door.leadingTo = room;
	return door;
}



/*
getRandomizedRoomTypes: this function will return a random vector of room tpyes
input: non
output: a random vector
*/
vector<RoomTypes> WorldGenerator::getRandomizedRoomTypes()
{
	vector<RoomTypes> result;
	for (int i = 0; i < 12; i++)
	{s
		result.push_back((RoomTypes)i);// putting all types in a vec
	}
	return RandTools::randomizeRoomTypesVec(result);// randomizing
}



/*
setLineOfCoordsInRow: this function will set an n number of coords in a line facing a certien direction in a vector
input: the coord, vector, direction of line and number of nodes in the line
output: non
*/
void WorldGenerator::setLineOfCoordsInRow(Coords& starterCoord, vector<Coords>& line, Directions direction, int n)
{
	while (n > 0)
	{
		line.push_back(starterCoord);
		starterCoord.move(direction);//going in direction
		n -= 1;
	}
	return;
}

/*
allocateRoom: this function will allocate a room according to the type
input: the root, type and rotation and also the door
output: the room ptr
*/
Room* WorldGenerator::allocateRoom(Coords root, RoomTypes type, RotationTypes rotation, Door door)
{
	Room* result = nullptr;
	switch (type)//switching to type
	{
	case STORAGE_CORRIDOR:
		result = new StorageCorridor(root, rotation, door);
		break;
	case STORAGE_LONG_CORRIDOR:
		result = new StorageLongCorridor(root, rotation, door);
		break;
	case STORAGE_T_INTERSECTION:
		result = new StorageT_Intersection(root, rotation, door);
		break;
	case STORAGE_INTERSECTION:
		result = new StorageIntersection(root, rotation, door);
		break;
	case STORAGE_TURN:
		result = new StorageTurn(root, rotation, door);
		break;
	case STORAGE_CLOSET:
		result = new StorageCloset(root, rotation, door);
		break;
	case STORAGE_SMALL_UNIT:
		result = new StorageSmallUnit(root, rotation, door);
		break;
	case STORAGE_MEDIUM_UNIT:
		result = new StorageMediumUnit(root, rotation, door);
		break;
	case STORAGE_BIG_UNIT:
		result = new StorageBigUnit(root, rotation, door);
		break;
	case STORAGE_VEHICLE_UNIT:
		result = new StorageVehicleUnit(root, rotation, door);
		break;
	case STORAGE_CONNECTED_CORRIDORS:
		result = new StorageConnectedCorridors(root, rotation, door);
		break;
	case STORAGE_SQUARE_CORRIDOR:
		result = new StorageSquareCorridor(root, rotation, door);
		break;
	default:
		break;
	}
	return result;
}







/*
getPossibleRootCoords: this function will return the possible root locations when placing a new room
input: the coord and the direction from the null door
output: a random vector with all possible locations
*/
vector<Coords> WorldGenerator::getPossibleRootCoords(Coords coord, Directions doorDirection)
{
	vector<Coords> result;
	Coords temp;
	Directions lineDirection;
	switch (doorDirection)// getting the right direction
	{
	case NORTH:
		lineDirection = EAST;
		break;
	case SOUTH:
		lineDirection = WEST;
		break;
	case WEST:
		lineDirection = NORTH;
		break;
	case EAST:
		lineDirection = SOUTH;
		break;
	default:
		break;
	}
	coord.move(lineDirection, -2);// going to the starter coord
	coord.move(doorDirection, -2);
	temp = coord;

	for (int i = 0; i < 5; i++)
	{
		coord = temp;
		coord.move(lineDirection, i);
		setLineOfCoordsInRow(coord, result, doorDirection, 7);// getting all possible locations within a 7x5 square
	}
	return RandTools::randomizeCoordsVec(result);//random order
}







/*
getRandomizedRotatinTypes: this function will return a vector with the rotation of the room type in a random order
input: the type
output: the vector
*/
vector<RotationTypes> WorldGenerator::getRandomizedRotatinTypes(RoomTypes roomType)
{
	vector<RotationTypes> result;
	switch (roomType)
	{
	case STORAGE_CORRIDOR:
		result.push_back(STORAGE_CORRIDOR_FACING_NORTH);//pushing the correct enums
		result.push_back(STORAGE_CORRIDOR_FACING_EAST);
		break;
	case STORAGE_LONG_CORRIDOR:
		result.push_back(STORAGE_LONG_CORRIDOR_FACING_NORTH);
		result.push_back(STORAGE_LONG_CORRIDOR_FACING_EAST);
		break;
	case STORAGE_T_INTERSECTION:
		result.push_back(STORAGE_T_INTERSECTION_FACING_NORTH);
		result.push_back(STORAGE_T_INTERSECTION_FACING_EAST);
		result.push_back(STORAGE_T_INTERSECTION_FACING_SOUTH);
		result.push_back(STORAGE_T_INTERSECTION_FACING_WEST);
		break;
	case STORAGE_INTERSECTION:
		result.push_back(STORAGE_INTERSECTION_ROTATION);
		break;
	case STORAGE_TURN:
		result.push_back(STORAGE_TURN_FACING_NORTH);
		result.push_back(STORAGE_TURN_FACING_EAST);
		result.push_back(STORAGE_TURN_FACING_SOUTH);
		result.push_back(STORAGE_TURN_FACING_WEST);
		break;
	case STORAGE_CLOSET:
		result.push_back(STORAGE_CLOSET_ROTATION);
		break;
	case STORAGE_SMALL_UNIT:
		result.push_back(STORAGE_SMALL_UNIT_ROTATION);
		break;
	case STORAGE_MEDIUM_UNIT:
		result.push_back(STORAGE_MEDIUM_UNIT_FACING_NORTH);
		result.push_back(STORAGE_MEDIUM_UNIT_FACING_EAST);
		break;
	case STORAGE_BIG_UNIT:
		result.push_back(STORAGE_BIG_UNIT_FACING_NORTH);
		result.push_back(STORAGE_BIG_UNIT_FACING_EAST);
		break;
	case STORAGE_VEHICLE_UNIT:
		result.push_back(STORAGE_VEHICLE_UNIT_FACING_NORTH);
		result.push_back(STORAGE_VEHICLE_UNIT_FACING_EAST);
		result.push_back(STORAGE_VEHICLE_UNIT_FACING_SOUTH);
		result.push_back(STORAGE_VEHICLE_UNIT_FACING_WEST);
		break;
	case STORAGE_CONNECTED_CORRIDORS:
		result.push_back(STORAGE_CONNECTED_CORRIDORS_FACING_NORTH);
		result.push_back(STORAGE_CONNECTED_CORRIDORS_FACING_EAST);
		break;
	case STORAGE_SQUARE_CORRIDOR:	
		result.push_back(STORAGE_SQUARE_CORRIDOR_ROTATION);
		break;
	default:
		break;
	}
	return RandTools::randomizeRotationTypesVec(result);// randomizing and returning the vector
}









/*
isRoomInCollision: this function will check if a room is in collision with other rooms with the coords
input: the room to check for collision
output: a boolean
*/
bool WorldGenerator::isRoomInCollision(Room* room)
{
	vector<Coords> roomCoords = room->getRoomCoords();// getting the room coords
	Room* searchedRoom;
	for (auto itt : roomCoords)// going through the coords
	{
		searchedRoom = m_RoomRoot->searchRoom(itt);// searching for a room in the current coord
		if (searchedRoom != nullptr)// if a room is find
		{
			if (searchedRoom == room)
			{
				return false;// this is the case for searching a room that is already present in the world
			}
			return true;
		}
	}
	return false;
}









/*
clearRooms: this function will clear all the room in a generated world
input: current room and visited rooms
output: non
*/
void WorldGenerator::clearRooms(Room* currentRoom, std::unordered_set<Room*>& visitedRooms)
{
	vector<Door> doors;
	if (visitedRooms.find(currentRoom) != visitedRooms.end())// if already visited
	{
		return;
	}

	visitedRooms.insert(currentRoom);// not visited yet, so this room needs to be inserted
	doors = currentRoom->getDoors();
	for (auto itt : doors)
	{
		clearRooms(itt.leadingTo, visitedRooms);// clearing all rooms
	}


	delete currentRoom;//deleting this room
	return;
}





