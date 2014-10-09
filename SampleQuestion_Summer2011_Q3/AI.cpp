#include "AI.h"

AI::AI() {}

AI::AI(int hitPoints) : m_hitPoints(hitPoints) { }    
   
float AI::getDistanceToWayPoint(Position const & p) const {
	// Ignore y-component as default behaviour
	return sqrt( ( p.m_x - m_pos.m_x ) * ( p.m_x - m_pos.m_x ) + 
		          ( p.m_z - m_pos.m_z ) * ( p.m_z - m_pos.m_z ) );
}
       
int AI::hitPoints() const {
	return m_hitPoints;
}

Position const & AI::getPosition() const {
	return m_pos;
}
