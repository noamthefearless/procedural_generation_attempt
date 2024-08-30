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



/*
getRoomCount: this function will return the number of rooms
input: non
output: the room count
*/
int WorldGenerator::getRoomCount() const
{
	return m_roomCount;
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
	if (direction == NORTH)
	{
		return SOUTH;
	}
	if (direction == SOUTH)
	{
		return NORTH;
	}
	if (direction == EAST)
	{
		return WEST;
	}
	if (direction == WEST)
	{
		return EAST;
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
	temp = door.firstSide;
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
	{
		result.push_back((RoomTypes)i);// putting all types in a vec
	}
	return RandTools::randomizeRoomTypesVec(result);// randomizing
}




/*
makeValidRoom:this function will create a specific room if possible
input: the void coord, the type and rotation as well as the opposite door of the void door
output: a room ptr, if a room was made, and null if not
*/
Room* WorldGenerator::makeValidRoom(Coords voidCoord, RoomTypes type, RotationTypes rotation, Door door)
{
	Room* result;
	vector<Coords> rootCoords = getPossibleRootCoords(voidCoord, getOppositeDirection(door.facing));// getting all possible roots

	for (auto itt : rootCoords)
	{
		result = allocateRoom(itt, type, rotation, door);// making demo room
		if (isRoomInCollision(result) == false && result->isDoorCoord(voidCoord))// if the void coord is a door coord, or the room is not in collision
		{
			return result;// this room is valid
		}

		delete result;//if not delete it and try again


	}
	return nullptr;// if not one option worked, return nullptr
}


/*
makeValidRotation: this function will check every rotation for the specific room type
input: the void coord, type, and door
output: a new room ptr if success, and nullptr if not
*/
Room* WorldGenerator::makeValidRotation(Coords voidCoord, RoomTypes type, Door door)
{
	Room* result;
	vector<RotationTypes> rotations = getRandomizedRotatinTypes(type);// getting all rotations randomized
	for (auto itt : rotations)
	{
		result = makeValidRoom(voidCoord, type, itt, door);// checking validity
		if (result != nullptr)
		{
			return result;// if valid
		}
	}
	return nullptr;// non were valid
}



/*
makeValidType: this function will create a room and return it
input : the void coord and the door of the new room 
output: the new room
*/
Room* WorldGenerator::makeValidType(Coords voidCoord, Door door)
{
	Room* result;
	vector<RoomTypes> types = getRandomizedRoomTypes();// getting all types randomized
	for (auto itt : types)
	{
		if (itt == STORAGE_CLOSET)// if closet then there is no reason to continue
		{
			result = new StorageCloset(voidCoord, STORAGE_CLOSET_ROTATION, door);
			return result;
		}
		result = makeValidRotation(voidCoord, itt, door);// checking validity
		if (result != nullptr)
		{
			return result;// if valid
		}
	}
	return nullptr;// non were valid
}



/*
walkInWorld: this function will allow you to walk in the world
input: the starter room and coord
output: non
*/
void WorldGenerator::walkInWorld(Room* currentRoom, Coords walkerCoord)
{

	char command = ' ';
	Directions walkingDirection;
	Coords goingTo;
	do
	{
		system("cls");//temporary - will be replaced with a more sophisticate solution
		std::cout << StringTools::deserializeRoom(StringTools::drawRoom(currentRoom, walkerCoord));
		std::cout << "X: " << walkerCoord.getCoords().x << ", Z: " << walkerCoord.getCoords().z << std::endl;
		command = _getch();// getting the char command
		if (command == 'q' || command == 'w' || command == 'a' || command == 's' || command == 'd')// if valid
		{
			switch (command)
			{
			case 'w':// getting direction from the command
				walkingDirection = NORTH;
				break;
			case 'a':
				walkingDirection = WEST;
				break;
			case 's':
				walkingDirection = SOUTH;
				break;
			case 'd':
				walkingDirection = EAST;
				break;
			default:
				break;
			}
			if (command != 'q')
			{
				goingTo = walkerCoord;
				goingTo.move(walkingDirection);// going to the next coord
				if (currentRoom->isCoordInRoom(goingTo) == true)//if the coord is in the room
				{
					walkerCoord = goingTo;// you can just go to the coord
				}
				else
				{
					if (currentRoom->isDoorExists(walkerCoord, walkingDirection))//check for door
					{
						currentRoom = currentRoom->getRoomThroughDoor(walkerCoord, walkingDirection);//get the door leadingTo
						walkerCoord = goingTo;//and going there
					}
				}
			}

		}




	}while (command != 'q');







}



/*
getFourDirectionsInRandomOreder: this function will simply return all 4 directions in a random order
input: non
output: a vector with 4 directions in a random order
*/
vector<Directions> WorldGenerator::getFourDirectionsInRandomOreder()
{
	vector<Directions> directionsUnsorted, result;
	int index = 0;
	directionsUnsorted.push_back(NORTH);// pushoin all 4 directions
	directionsUnsorted.push_back(SOUTH);
	directionsUnsorted.push_back(EAST);
	directionsUnsorted.push_back(WEST);


	while (directionsUnsorted.size() > 0)
	{
		index = RandTools::getRandomVal(0, directionsUnsorted.size() - 1);// getting direction
		result.push_back(directionsUnsorted[index]);//pushing
		directionsUnsorted.erase(directionsUnsorted.begin() + index);//and erasing for next itteration
	}
	return result;
}




/*
addNewDoorToRoomIfPossible: this function will add a new door to a room if possible
input: the room
output: a bool saying if a door was added
*/
bool WorldGenerator::addNewDoorToRoomIfPossible(Room* room)
{
	vector<Directions> directions = getFourDirectionsInRandomOreder();// getting randomized directions
	Coords checkingCoord;
	vector<Coords> doorCoords = RandTools::randomizeCoordsVec(room->getDoorCoords());//and randomized door coords
	Door doorToAdd, oppositDoor;
	Room* blockingRoom = nullptr;

	for (auto doorCoord : doorCoords)
	{
		for (auto direction : directions)
		{
			checkingCoord = doorCoord;
			checkingCoord.move(direction);// getting the secondSide
			if (room->isDoorExists(doorCoord, direction) == false && room->isCoordInRoom(checkingCoord) == false)// checking door validity
			{
				blockingRoom = room->searchRoom(checkingCoord);// check if there already is a room where the door is leading
				if (blockingRoom == nullptr)// if no
				{
					doorToAdd.firstSide = doorCoord;
					doorToAdd.secondSide = checkingCoord;
					doorToAdd.facing = direction;// make the door
					doorToAdd.leadingTo = makeValidType(doorToAdd.secondSide, getOppositeDoor(room, doorToAdd));//create a new room
					room->addDoor(doorToAdd);//adding a door
					m_roomCount++;
					return true;
				}
				else if (blockingRoom->getMaxDoors() > blockingRoom->getDoors().size() && blockingRoom->isDoorCoord(checkingCoord))// if a room is ther, and it has enaugh place for one door
				{
					doorToAdd.firstSide = doorCoord;//same thing
					doorToAdd.secondSide = checkingCoord;
					doorToAdd.facing = direction;
					doorToAdd.leadingTo = blockingRoom;
					room->addDoor(doorToAdd);//add the door to the room
					oppositDoor = getOppositeDoor(room, doorToAdd);// add the opposite door
					blockingRoom->addDoor(oppositDoor);//to the opposite room
					m_roomCount++;
					return true;
				}
			}
		}
	}


	return false;

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






/*
generateRooms: this function will generate rooms
input: the room to start from and the room that are visited
output: non
*/
void WorldGenerator::generateRooms(Room* currentRoom, std::unordered_set<Room*>& visitedRooms)
{
	vector<Door> roomDoors;
	if (visitedRooms.find(currentRoom) != visitedRooms.end())//checking if visited already
	{
		return;
	}
	visitedRooms.insert(currentRoom);
	int numOfDoorsToAdd = 0, index = 0;

	if (m_roomCount >= ROOM_CAP)//if room cap has been reached
	{
		return;
	}
	if (currentRoom->getDoors().size() < currentRoom->getMaxDoors())//if more doors can be added
	{
		numOfDoorsToAdd = currentRoom->getMaxDoors() - currentRoom->getDoors().size();
		numOfDoorsToAdd = RandTools::getRandomVal(1, numOfDoorsToAdd);// adding doors
	}

	while (numOfDoorsToAdd > 0)
	{
		addNewDoorToRoomIfPossible(currentRoom);//adding doors
		numOfDoorsToAdd--;
	}
	roomDoors = currentRoom->getDoors();
	for (auto itt : roomDoors)
	{
		if (itt.leadingTo->getType() != STORAGE_CLOSET && itt.leadingTo->getDoors().size() == 1)// if possible
		{
			addNewDoorToRoomIfPossible(itt.leadingTo);//add another door through
		}
	}

	system("cls");
	std::cout << "loading - " << (int)(((float)m_roomCount / ROOM_CAP) * 100) << "%" << std::endl;//loading update


	roomDoors = currentRoom->getDoors();
	while (roomDoors.size() != 0)
	{
		index = RandTools::getRandomVal(0, roomDoors.size() - 1);
		generateRooms(roomDoors[index].leadingTo, visitedRooms);//callling this function on all doors, in random order
		roomDoors.erase(roomDoors.begin() + index);

	}

	return;



}




