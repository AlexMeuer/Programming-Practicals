#include "Puck.h"

int Puck::getZ() {
	return m_z;
}

void Puck::setZ(int z) {
	m_z = z;
}

PuckType Puck::getTeam() {
	return m_colour;
}

void Puck::setTeam(PuckType colour) {
	m_colour = colour;
}

// Do not remove.
bool Puck::operator < ( Puck const & p ) {
	return m_z < p.m_z;
}