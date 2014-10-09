#include <iostream>
#include "AI.h"
#include "AirAI.h"
#include "LandAI.h"

using namespace std;

void printLandAI(LandAI ai) {
	cout << ai.getLandSpeed() << endl;
}

int main() {
	AI *pAI = new AirAI(100);
	cout << pAI->hitPoints() << endl;
	cout << pAI->getDistanceToWayPoint(Position(10, 10, 10)) << endl;
	//cout << pAI->getAirSpeed();		//wont compile because pAI is pointer to base AI, compiler doesnt know that pAI will hold an AirAI

	system("PAUSE");
	system("CLS");

	LandAI land(100, 3);
	printLandAI( land );
	cout << "First waypoint x: " << land.getWayPoint(0).m_x << endl; 

	system("PAUSE");
	system("CLS");
}