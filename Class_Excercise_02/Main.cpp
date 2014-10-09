#include <iostream>
#include "Cylinder.h"

using namespace std;

int main()
{
	Cylinder mCylinder = Cylinder(10, 5);

	cout << "Cylinder" << endl;

	cout << "Surface Area:\t" << mCylinder.getSurfaceArea() << endl;
	cout << "Volume:\t\t" << mCylinder.getVolume() << endl;
	system("pause");
}