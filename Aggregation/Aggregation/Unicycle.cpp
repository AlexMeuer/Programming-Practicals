//implementation for unicycle.h
#include "Unicycle.h"

//Unicycle(int radius)
Unicycle::Unicycle(int radius) : m_wheel(radius), m_spareWheel(radius), m_age(0), m_numOwners(m_age) {
	//m_wheel = Wheel(radius); WRONG!
	//m_spareWheel = radius;	because wheel has constrcutor that takes an int, this is legal. A temp object is created and then assignment is done.
}

//int getRadius() const;
int Unicycle::getRadius() const {
	return m_wheel.getRadius();
}