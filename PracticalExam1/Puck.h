#ifndef PUCK_H
#define PUCK_H
#include "PuckEnum.h"
#include <random>	// for rand()

class Puck {
private:
	int m_z;	// The Pucks z position on the board.
	PuckType m_colour;	//the pucks team colour

public:
	//constructor with random number 0-100 for m_z and RED for m_colour
	Puck(int z = rand(), PuckType colour = RED) : m_z(z), m_colour(colour)
	{
		//empty body
	}

	int getZ();

	void setZ(int z);

	PuckType getTeam();

	void setTeam(PuckType teamColour);


	
	// Do not remove this.
	bool operator < ( Puck const & p );
};

#endif