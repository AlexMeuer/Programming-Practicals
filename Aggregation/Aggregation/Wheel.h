#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
private:
	int m_radius;
public:
	Wheel(int radius = 0);	//adding value makes default constructor

	int getRadius() const;
};
#endif