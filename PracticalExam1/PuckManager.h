#ifndef PUCKMANAGER_H
#define PUCKMANAGER_H

#include <algorithm>
#include "Puck.h"

class PuckManager {
private:
	int m_pucks;	// The total number of pucks in the array.
	Puck * m_puckArray;

	void sortByZValue() ;

public:
	PuckManager(int numPucks);

	int getScore();
	PuckType getWinner();
	

};

#endif