#ifndef CYLINDER_H
#define CYLINDER_H

#include "Circle.h"

class Cylinder
{
private:
	float mHeight;
	Circle mCircle;

public:
	Cylinder(float height = 0, float radius = 0) : mHeight(height), mCircle(radius)
	{
		//empty
	}

	float getSurfaceArea() const;
	float getVolume() const;
};
#endif