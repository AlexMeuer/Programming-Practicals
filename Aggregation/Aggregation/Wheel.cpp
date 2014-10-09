//implementation for wheel.h
#include "Wheel.h"

//Wheel(int radius);
Wheel::Wheel(int radius) : m_radius(radius)	{
	//constructor body is empty.
}

//int getRadius() const;
int Wheel::getRadius() const {
	return m_radius;
}