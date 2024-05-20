#pragma once

typedef struct xyz
{
	long long x = 0;
	long long y = 0;
	long long z = 0;
};

enum Directions
{
	NORTH = 0, SOUTH = 1, WEST = 2, EAST = 3
};


class Coords
{
public:
	Coords() = default;
	Coords(long long x, long long y, long long z);// specific c'tor
	Coords(Coords& other);// copy c'tor

	Coords operator=(const Coords& other); // = operator
	bool operator==(const Coords& other); // = 

	void move(const int steps = 1, Directions facing); // move



private:
	void changeXaxis(int steps); // changes the X axis
	void changeYaxis(int steps); // changes the Y axis
	void changeZaxis(int steps); // changes the Z axis
	xyz m_coordinates;
};

