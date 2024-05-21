#include "RandTools.h"
#include <iostream>
#include "Coords.h"
#include <vector>
#include "Room.h"


int main()
{
	std::string a = "\n\n\n\t\t -----------\n\t\t|           |\n\t\t|           |\n\t\t|     *     |\n\t\t|           |\n\t\t|           |\n\t\t|           |\n\t\t|           |\n\t\t|     *     |\n\t\t|           |\n\t\t|           |\n\t\t|           |\n\t\t|           |\n\t\t|     *     |\n\t\t|           |\n\t\t|           |\n\t\t -----------";
    std::string b = "\n\n\n\t\t---------------------------------\n\t       |\t\t\t\t |\n\t       |\t\t\t\t |\n\t       |     *          *          *     |\n\t       |\t\t\t\t |\n\t       |\t\t\t\t |\n\t\t---------------------------------";
	Door d, p;
	d.facing = NORTH;
	d.firstSide.move(NORTH);
	p = d;
	d.facing = SOUTH;

	return 0;
}


