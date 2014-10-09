#include <iostream>
using namespace std;

float ToRadians(float degrees);
bool AskLoop();

int main()
{
	float degrees;

	cout << "Q2 Degrees To Radians" << endl;

	do{
		cout << "Input angle in degrees:";
		cin >> degrees;

		cout << "\n" << ToRadians(degrees) << endl;
	}while(AskLoop());

}

float ToRadians(float degrees)
{
	const float pi = acos(-1.0);
	return (degrees * pi / 180);
}

bool AskLoop()
{
	char answer;
	bool looping = false;

	cout << "Again? (y/n)" << endl;

	cin >> answer;

	if(answer == 'y' || answer == 'Y')
		looping = true;

	return looping;
}