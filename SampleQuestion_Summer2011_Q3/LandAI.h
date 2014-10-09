#include "AI.h"

class LandAI :  public AI {
private:
   int m_landSpeed;
   Position *m_pWayPoints;	
   int m_wayPoints;		

public:
	LandAI(int hitPoints, int wayPoints) : m_landSpeed(0), m_wayPoints(wayPoints), m_pWayPoints(new Position[wayPoints]), AI(hitPoints) {}

	//copy constructor
	LandAI(LandAI const &  copy) {
		m_pWayPoints = new Position[copy.m_wayPoints];
		for(int i = 0; i < copy.m_wayPoints; i++)
		{
			m_pWayPoints[i] = copy.m_pWayPoints[i];
		}
	}

	virtual ~LandAI() { delete [] m_pWayPoints; }

	int getLandSpeed() const {
		return m_landSpeed;
	}

	Position & getWayPoint(int index) const {
		return m_pWayPoints[index];
	}         
};
