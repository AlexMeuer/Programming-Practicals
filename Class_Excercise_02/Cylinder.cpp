#include "Cylinder.h"

float Cylinder::getSurfaceArea() const
{

	//SA = (2PI * r^2) + (2PI * r * h)
	return (2 * mCircle.getArea()) + (2 * M_PI * mCircle.getRadius() * mHeight);
}

float Cylinder::getVolume() const
{

	//v = PI * r^2 * h
	return  mCircle.getArea() * mHeight;
}