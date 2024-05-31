#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;
class stringTools
{
public:
	static vector<string> serializeRoom(string room);
	static string deserializeRoom(vector<string> room);
	static string makeAsciiRoom(int width, int height);




};

