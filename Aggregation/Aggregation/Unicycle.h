//header file for unicycle.h
#ifndef UNICYCLE_H
#define UNICYCLE_h

#include "Wheel.h"

class Unicycle {
private:
	Wheel m_wheel;		//NB, Wheel is a property
	Wheel const m_spareWheel;
	int m_age;			//age of this object
	int m_numOwners;	//number of previous owners
public:
	Unicycle(int radius = 0);

	int getRadius() const;
};
#endif