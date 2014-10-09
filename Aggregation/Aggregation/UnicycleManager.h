#ifndef UNICYCLEMANAGER_H
#define UNICYCLEMANAGER_H

#include "Unicycle.h"

class UnicycleManager {
private:
	Unicycle m_cycleArray[5];
public:
	UnicycleManager();

	//return the radius of the unicycle at this index
	int getRadius(int index) const;
};
#endif