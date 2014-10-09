#include "AirAI.h"

AirAI::AirAI(int hitPoints) : m_airSpeed(0), AI(hitPoints) { }    

float AirAI::getDistanceToWayPoint(Position const & p) const {
	Position pos = getPosition();
	return sqrt( ( p.m_x - pos.m_x ) * ( p.m_x - pos.m_x ) + 
		         ( p.m_y - pos.m_y ) * ( p.m_y - pos.m_y ) +
			     ( p.m_z - pos.m_z ) * ( p.m_z - pos.m_z ) );
}

int AirAI::getAirSpeed() const {
	return m_airSpeed;
}
