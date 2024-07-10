#pragma once
#include <vector>
#include <string>
#include "Coords.h"
#include "Room.h"
#include <map>;
#include <algorithm>
using std::vector;
using std::map;
using std::string;
class stringTools
{
public:
	static vector<string> serializeRoom(string room);
	static string deserializeRoom(vector<string> room);
	static string makeAsciiRoom(int width, int height);
	static bool isWallThere(Coords coord, Room* coordRoom, Directions direction);

	static vector<string> drawCoord(Coords coord, Room* coordRoom);
	static vector<string> drawRoom(Room* Room);
	static vector<string> connectSeriallizedStrings(vector<string> s1, vector<string> s2);



};

