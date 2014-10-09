#include "UnicycleManager.h"

UnicycleManager::UnicycleManager() {
	//empty
}

int UnicycleManager::getRadius(int index) {
	index = ( index < 0 || index > 4) ? 0 : index;	//if index less than 0 or greater than for, then assign 0 to it. like a short if/else statement
	return cycleArray[index].getRadius();
}