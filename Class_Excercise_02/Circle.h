#ifndef CIRCLE_H
#define CIRLCE_H

#define _USE_MATH_DEFINES
#include<cmath>

using namespace std;

class Circle
{
private:
	float mRadius;

public:
	Circle(float radius = 0) : mRadius(radius)
	{
		//empty
	}

	float getArea() const;
	float getRadius() const;
};
#endif