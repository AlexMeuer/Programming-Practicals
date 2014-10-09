#ifndef AI_H
#define AI_H

#include "Position.h"
#include <cmath>

class AI {
private:
   Position m_pos;
   int m_hitPoints; 
    
public:
   AI();
   AI(int hitPoints);
   
   virtual float getDistanceToWayPoint(Position const & p) const; // = 0;
       
   int hitPoints() const;

   Position const & getPosition() const;
};

#endif