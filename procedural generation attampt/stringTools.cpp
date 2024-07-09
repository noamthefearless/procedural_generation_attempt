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
		result += itt + "\n";

	}
	return result;
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

