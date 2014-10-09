//source file with main function

//no need to #include Wheel.h (Why?) ANSWER: Unicycle.h includes wheel.h and we're not directly referenceing wheel class here
#include "Unicycle.h"
#include "UnicycleManager.h"
#include <iostream>

using namespace std;

int main() {
	//make an instance of UnicycleManager
	UnicycleManager manager;

	//make an instance of unicycle
	Unicycle cycle(10);
	cout << cycle.getRadius() << endl;
	system("pause");

	//make an array of unicycles
	Unicycle cycleArray[] = { Unicycle(1), Unicycle(2) };
	//this is also valid
	Unicycle cycleArray2[] = { 1, 2 };	//does same as above, looks messier, generally dont do it

	cout << cycleArray2[0].getRadius();
}