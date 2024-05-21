#include "Coords.h"



/*
value c'tor: this function will init the x, y, and z values of the coords
*/
Coords::Coords(long long x, long long y, long long z)
{
	m_coordinates.x = x;//initiating
	m_coordinates.y = y;
	m_coordinates.z = z;
}

Coords::Coords(Coords& other)
{
	*this = other;
}


/*
operator =: this function will use = operator to copy Coords
input: the right side coords
output: self assignments
*/
Coords& Coords::operator=(const Coords& other)
{
	if (this == &other) 
	{
		return *this; // self-assignment guard
	}
	this->m_coordinates.x = other.m_coordinates.x;
	this->m_coordinates.y = other.m_coordinates.y;
	this->m_coordinates.z = other.m_coordinates.z;
	return *this;
}


/*
operator ==: this function will use == operator to compare Coords
input: the right side coords
output: a bool
*/
bool Coords::operator==(const Coords& other)
{
	return (this->m_coordinates.x == other.m_coordinates.x && this->m_coordinates.y == other.m_coordinates.y && this->m_coordinates.z == other.m_coordinates.z);
}


/*
getCoords: this function will return the xyz val
input: non
output: the coordinates
*/
xyz Coords::getCoords() const
{
	return m_coordinates;
}


void Coords::move(Directions facing, int steps)
{
	switch (facing)
	{
	case NORTH:
		changeXaxis(steps);
		break;
	case SOUTH:
		changeXaxis(steps * -1);
		break;
	case WEST:
		changeZaxis(steps * -1);
		break;
	case EAST:
		changeZaxis(steps);
		break;
	case UP:
		changeYaxis(steps);
		break;
	case DOWN:
		changeYaxis(steps * -1);
		break;
	default:
		break;
	}
}



/*
changeXaxis: this function will change the X axis
input: the number of steps to add
output: non
*/
void Coords::changeXaxis(int steps)
{
	m_coordinates.x += steps;
}


/*
changeYaxis: this function will change the Y axis
input: the number of steps to add
output: non
*/
void Coords::changeYaxis(int steps)
{
	m_coordinates.y += steps;
}



/*
changeZaxis: this function will change the Z axis
input: the number of steps to add
output: non
*/
void Coords::changeZaxis(int steps)
{
	m_coordinates.z += steps;
}






