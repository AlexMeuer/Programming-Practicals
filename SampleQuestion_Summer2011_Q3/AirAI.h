#ifndef AIRAI_H
#define AIRAI_H

#include "AI.h"

class AirAI :  public AI {
private:
   int m_airSpeed;
public:
   AirAI(int hitPoints);

   float getDistanceToWayPoint(Position const & p) const;

   int getAirSpeed() const;
         
};

#endif