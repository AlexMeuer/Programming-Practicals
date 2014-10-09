#include <iostream>
#include <string>
#include <cstdlib>	// for access to the rand() function
#include <ctime>	// for access to time() function
using namespace std;

struct Sprite
{
	string	pathname;
	string	filename;
	short	id;
};
struct Die
{
	private:
		int result;
	public:
		int faceValue();
		void roll();
};
void modifySprite(Sprite &s);
void modifySpriteArray(Sprite s[]);
void printSpriteArray(const Sprite s[]);

enum spriteType{PLAYER, SHIP, BULLET};

struct PairOfDice
{
	private:
		Die dieOne, dieTwo;
		int result[2];
		int *arrayPointer;
	public:
		void roll()
		{
			dieOne.roll();
			dieTwo.roll();
		}
		int* faceValue()
		{
			arrayPointer = &result[0];
			result[0] = dieOne.faceValue();
			result[1] = dieTwo.faceValue();
			return arrayPointer;
		}
};

void main()
{
	//Question 1
	//------------------------------------------------------
	cout << "Question 1" << endl;
	Sprite mySprite;

	modifySprite(mySprite);
	
	cout << "not printing -999 because only a copy  is passed, not the address" << endl;
	//
	cout << mySprite.id << endl;
	system("pause");
	system("cls");

	//Question 2
	//--------------------------------------------------
	cout << "Question 2" << endl;
	Sprite spriteArray[5];
	for(int i = 0; i < 5; i++)
	{
		spriteArray[i].id = i;
	}

	modifySpriteArray(spriteArray);

	cout << "printing -999 this time because address is passed and not a seperate copy" << endl;
	cout << spriteArray[0].id<< endl;
	system("pause");

	printSpriteArray(spriteArray);
	system("pause");
	system("cls");

	//Question 3
	//------------------------------------------------
	cout << "Question 3" << endl;
	cout << "PLAYER:\t" << PLAYER << endl;
	cout << "SHIP:\t" << SHIP << endl;
	cout << "BULLET:\t" << BULLET << endl;
	system("pause");
	system("cls");

	//Question 4
	//------------------------------------------------
	srand(time(0));	//seed random num based on time
	PairOfDice myDice;
	myDice.roll();
	cout << "First die value:\t" << *(myDice.faceValue()) << endl;
	cout << "Second die value:\t" << *(myDice.faceValue() + 1) << endl;
	system("pause");
	system("cls");
}

void modifySprite(Sprite &s)
{
	s.id = -999;
}

void modifySpriteArray(Sprite s[])
{	
	s[0].id = -999;
}

//array should not be modifyable from here, so we pass it as a constant
void printSpriteArray(const Sprite s[])
{
	for(int i = 0; i < 5; i++)
	{
		cout << s[i].id << endl;
	}
}

int Die::faceValue()
{
	return result;
}

void Die::roll()
{
	result = rand() % 6 + 1;
}