#include "stringTools.h"




/*
sereallizeRoom: this function will turn a string room into a vector of lines
input: the room in string format
output: the ser
*/
vector<string> stringTools::serializeRoom(string room)
{
	vector<string> result;
	string itt = "";
	for (auto i : room)// going thtough string
	{
		if (i == '\n')//end of line
		{
			result.push_back(itt);
			itt = "";//resetting the ittarator
		}
		else
		{
			itt += i;
		}
	}


	return result;
}





/*
desereallizeRoom: this function will turn a vector room into string format
input: the room in vector format
output: string room
*/
string stringTools::deserializeRoom(vector<string> room)
{
	string result = "";
	for (auto itt : room)
	{
		if (itt != "")
		{
			result += itt + "\n";
		}
			

	}
	return result;
}

/*
isWallThere: this function will check if a ceriten coord is the edge of a room from a certien direction
input: the coord, room and the directions
output: a bool;
*/
bool stringTools::isWallThere(Coords coord, Room* coordRoom, Directions direction)
{
	coord.move(direction);
	return !(coordRoom->isCoordInRoom(coord));
}


/*
drawCoord: this function will draw one coord of a room
input: the coord and the room ptr
output: a seriallized string format
*/
vector<string> stringTools::drawCoord(Coords coord, Room* coordRoom, bool isWalker)
{
	vector<string> result;
	vector<Coords> sameLineCoords;
	Coords counterCoord = coord;
	int ghostCoordCount = 0;
	//checking for walls
	bool isRightWall = isWallThere(coord, coordRoom, EAST), isLeftWall = isWallThere(coord, coordRoom, WEST), 
		isUpWall = isWallThere(coord, coordRoom, NORTH), isDownWall = isWallThere(coord, coordRoom, SOUTH);
	string layerUpAndDown = "             ", layerLeftAndRight = "             ";
	if (isRightWall)
	{
		layerUpAndDown = "";
	}



	if (isUpWall)//starting with upper wall
	{
		layerUpAndDown = "-------------";
		if (isRightWall)
		{
			layerUpAndDown[12] = ' ';//setting values
		}
		if (isLeftWall)
		{
			layerUpAndDown[0] = ' ';
		}
	}
	result.push_back(layerUpAndDown);
	if (isRightWall)
	{
		layerLeftAndRight[12] = '|';//setting values for the left and right walls
	}
	if (isLeftWall)
	{
		layerLeftAndRight[0] = '|';
	}
	for (int i = 1; i < 6; i++)
	{
		result.push_back(layerLeftAndRight);
	}

	layerUpAndDown = "             ";
	if (isRightWall)
	{
		layerUpAndDown = "";
	}
	if (isDownWall)//same thing as before for a downWall
	{
		layerUpAndDown = "-------------";
		if (isRightWall)
		{
			layerUpAndDown[12] = ' ';
		}
		if (isLeftWall)
		{
			layerUpAndDown[0] = ' ';
		}
	}
	result.push_back(layerUpAndDown);



	//edit values for doors
	result = stringTools::addCoordDoors(coord, coordRoom, result);
	if (isWalker)
	{
		result[3][6] = '*';
	}

	//add ghostCoords (indentation) if needed
	for (auto itt : coordRoom->getRoomCoords())
	{
		if (coord.getCoords().x == itt.getCoords().x)
		{
			sameLineCoords.push_back(itt);
		}
	}


	if (isLeftWall)
	{
		if (coord.getCoords().z == stringTools::getMostLeftCoord(sameLineCoords).getCoords().z)// adding ghost coords accordingly
		{
			result = stringTools::addingGhostCoords(result, coord.getCoords().z - stringTools::getMostLeftCoord(coordRoom->getRoomCoords()).getCoords().z);
		}
		else
		{
			do
			{
				counterCoord.move(WEST);//looking for last place in room to the left
				ghostCoordCount++;
			} while (coordRoom->isCoordInRoom(counterCoord) == false);
			result = stringTools::addingGhostCoords(result,ghostCoordCount - 1);//its also counting the coord itself
		}
	}



	return result;
}



/*
getMostLeftCoord: this function will find the most left coord and return it
input: the vector of coords
output: the far left coord
*/
Coords stringTools::getMostLeftCoord(vector<Coords> vec)
{
	Coords result;
	if (vec.size() < 1)
	{
		return result;
	}
	result = vec[0];// starting value

	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i].getCoords().z < result.getCoords().z)// looking for lower z value
		{
			result = vec[i];
		}
	}
	return result;
}



/*
addCoordDoors: this function will add doors to a coord in seriallized form
input: the coord, the room and the seriallized room string
output: the new room string with the doors
*/
vector<string> stringTools::addCoordDoors(Coords coord, Room* Room, vector<string> vecStr)
{
	vector<Door> doorsInCoord = Room->getDoorsOfCoord(coord);//getting all of the doors in this coord
	for (auto itt : doorsInCoord)
	{
		if (itt.facing == NORTH || itt.facing == SOUTH)
		{
			vecStr[(vecStr.size() - 1) * itt.facing][5] = 'd';//calculating if the door is facing NORTH or SOUTH
			vecStr[(vecStr.size() - 1) * itt.facing][6] = 'd';
			vecStr[(vecStr.size() - 1) * itt.facing][7] = 'd';
		}
		else
		{
			vecStr[3][12 * (itt.facing - 2)] = 'd';//seeting d marker that will be turned into a space in cleanup
		}
	}
	return vecStr;
}



/*
addingGhostCoords: this function will add a set number of ghost coords to a serriallized string
input: the vector and the number of ghost coords
output: the new vector
*/
vector<string> stringTools::addingGhostCoords(vector<string> vec, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			if (vec[j] != "")
			{
				vec[j] = "             " + vec[j];// adding indent
			}
		}
	}
	return vec;
}








/*
drawRoom: this function will make a snapshot of a room
input: the room ptr
output: a seriallized string of the room pic
*/
vector<string> stringTools::drawRoom(Room* Room, Coords walkerCoord)
{
	vector<Coords> coords = Room->getRoomCoords();// getting coords
	vector<vector<string>> roomPieces;
	vector<string> result, temp;
	string valHolder;
	int currentXval = 0;
	//sorting from order like this: 
	//the coords go from the most top left to the most bottom right, just like in printing 
	std::sort(coords.begin(), coords.end(), [](Coords c1, Coords c2) {
		return (c1.getCoords().x > c2.getCoords().x) || ((c1.getCoords().x == c2.getCoords().x) && 
			c1.getCoords().z < c2.getCoords().z); }// lambda function
	);

	for (auto itt : coords)
	{
		roomPieces.push_back(drawCoord(itt, Room, walkerCoord == itt));// drawing each coord
	}
	currentXval = coords[0].getCoords().x;// starting to connect the X vals
	temp = roomPieces[0];//first serrialized string
	for (int i = 1; i < coords.size(); i++)
	{
		if(coords[i].getCoords().x == currentXval)// the way it works is adding the vectors on the same X level
		{
			temp = stringTools::connectSeriallizedStrings(temp, roomPieces[i]);
		}
		else// if the X level changes, we have 1 layer, and we push it and go to the next layer
		{
			currentXval = coords[i].getCoords().x;
			result.insert(result.end(), temp.begin(), temp.end());// it is easier to just remove it, than to change the algorithem


			temp = roomPieces[i];
		}
	}
	result.insert(result.end(), temp.begin(), temp.end());// it is easier to just remove it, than to change the algorithem



	return stringTools::cleanUpRoomStr(result);
	//return result;
}



/*
cleanUpRoomStr: this function will clean UP a room str and make it look better
input: the seriallized string of the room
output: the room after the cleanup
*/
vector<string> stringTools::cleanUpRoomStr(vector<string> roomStr)
{
	int maxStrSize = roomStr[0].size();
	for (int i = 0; i < roomStr.size(); i++)// finding the maximum size of a row in the room
	{
		if (roomStr[i].size() > maxStrSize)
		{
			maxStrSize = roomStr[i].size();
		}
	}
	for (int i = 0; i < roomStr.size(); i++)// topping off every line that is less than the max size
	{
		while (roomStr[i].size() < maxStrSize)
		{
			roomStr[i] = roomStr[i] + " ";// this way, we have more ways to change the room if we want to in the future
		}
	}


	for (int i = 1; i < roomStr.size() - 1; i++)
	{
		for (int j = 0; j < roomStr[i].size(); j++)// going through every line in the string
		{
			if (roomStr[i][j] == ' ' && (roomStr[i - 1][j] == '|' || roomStr[i + 1][j] == '|'))// checking if a hole is present
			{
		
				if (j == 0 && roomStr[i][j + 1] != '-')// if the hole is there, and its not a wall edge, mark it
				{
					roomStr[i][j] = 'k';
				}
				else if (j == roomStr[i].size() - 1 && roomStr[i][j - 1] != '-')// checing the other side
				{
					roomStr[i][j] = 'k';
				}
			else if (j != 0 && j != roomStr[i].size() - 1 && roomStr[i][j - 1] != '-' && roomStr[i][j + 1] != '-')
				{
					roomStr[i][j] = 'k';// and also if its a central wall.
				}


			}
		}
		
	}


	for (int i = 0; i < roomStr.size(); i++)//and a last loop to change marks
	{
		for (int j = 0; j < roomStr[i].size(); j++)
		{
			if (roomStr[i][j] == 'k')// changing marked holes to walls
			{
				roomStr[i][j] = '|';

			}
			else if (roomStr[i][j] == 'd')
			{
				roomStr[i][j] = ' ';
			}
		}

	}


	return roomStr;
}






/*
connectSeriallizedStrings: this function will connect 2 string vectors of the same size
input: the 2 string vectors
output: the connected vector
*/
vector<string> stringTools::connectSeriallizedStrings(vector<string> s1, vector<string> s2)
{
	int size = s1.size();
	if (s1.size() > s2.size())//if noit same size
	{
		size = s2.size();
	}

	for (int i = 0; i < size; i++)
	{
		s1[i] += s2[i];// adding values
	}
	return s1;
}







/*
makeAsciiRoom: this function will make a room in ascii
input: the width and height of the room
ouptut: the room as an Ascii string
*/
string stringTools::makeAsciiRoom(int width, int height)
{
	string result = "";
	int temp = 0;
	height *= 5;// height multiplier is 5
	height += 1;
	for (int i = 0; i <= height; i++)
	{
		if (i == 0 || i == height)// if first or last row
		{
			result += " ";
			temp = width * 11;
			while (temp > 0)
			{
				result += "-";
				temp--;
			}
		}
		else
		{
			result += "|";// if middle row
			temp = width * 11;
			while (temp > 0)
			{
				result += " ";
				temp--;
			}
			result += "|";
		}
		result += "\n";// end of line
	}
	return result;
}

