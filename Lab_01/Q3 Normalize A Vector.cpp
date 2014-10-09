#include<iostream>
using namespace std;

void vectorNormalize(float inputVector[], float resultVector[]);

int main()
{
	float input[4];
	float result[2];

	cout << "Input four floats to be used as 2D vector points:" << endl;
	cin >> input[0] >> input[1] >> input[2] >> input[3];

	vectorNormalize(input, result);

	cout << "Direction Vector is " << result[0] << ", " << result[1] << endl;
	system("Pause");
}


void vectorNormalize(float inputVector[], float resultVector[])
{
	float v1 = (inputVector[2] - inputVector[0]);
	float v2 = (inputVector[3] - inputVector[1]);

	float length = sqrt(pow(v1,2) + pow(v2,2));
	cout << "Length/Magnitude is " << length << endl;

	resultVector[0] = v1 / length;
	resultVector[1] = v2 / length;
}