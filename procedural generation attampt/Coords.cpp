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
Coords Coords::operator=(const Coords& other)
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


