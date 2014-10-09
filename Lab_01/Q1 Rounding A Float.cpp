#include <iostream>

using namespace std;

int RoundNumber(float num);
bool AskLoop();

int main()
{
	float number;

	cout << "Q1 Rounding A Float" << endl;

	//allow more than one number to be inputted
	do{
		cout << "\nInput a number to round:" << endl << "Float:";	//ask for input

		cin >> number;	//input number to variable

		cout << "Rounded: " << RoundNumber(number) << endl;	//output rounded number

		cout << "\n";	//skip a line

	}while(AskLoop());
}

int RoundNumber(float num)
{
	int roundedNum;

	roundedNum = floor(num + 0.5f);

	return roundedNum;
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