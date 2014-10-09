#include "Circle.h"

float Circle::getArea() const
{
	//Area = PI*R^2
	return M_PI * (mRadius * mRadius);
}

float Circle::getRadius() const
{
	return mRadius;
}