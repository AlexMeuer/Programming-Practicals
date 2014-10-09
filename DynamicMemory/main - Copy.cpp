#include <iostream>

using namespace std;

//Function to allocate memory
int * allocateInt() {
	return new int(0);
}

class Player {
private:
	int * m_lives;
public:
	Player() : m_lives(new int(3)) {}
	Player(int lives) : m_lives(new int(lives)) {}
	//Introducing... the DESTRUCTOR
	~Player() { 
		cout << "Destructor called!" << endl;
		delete m_lives;
	}

	int getLives() const { return *m_lives; }
};

//CLASS EXCERCISE
class String {
private:
	char *ptr;	//will point to an array of type char
public:
	String() {
		ptr = new char[1];
		ptr[0] = '\0';	//null character
	}

	String(char *s) : ptr( new char [strlen(s) + 1] ){
		strcpy(ptr, s);	//copy the arguement string into the array
	}

	~String() {
		delete[] ptr;
	}
};

//Dynamic memory examples
int main() {
	//To allocate dynamic memory, we use the new operator.
	//For example:
	/*int * pInt = allocateInt();
	cout << *pInt << endl;
	delete pInt;	//Free the allocated heap memory*/

	/*
	//Ask the user for the array dimensions
	cout << "How many array elements?\n";
	int elements;
	cin >> elements;

	//int intArray[elements];	//cannot use a variable here for array size
	int * intArray = new int[elements];	//when using dynamic memory, array elements are NOT initialised when array is created (unlike in the line above)
	cout << intArray[0] << endl;
	
	//delete intArray;	//INCORRECT	- only deletes the first element
	delete[] intArray;	//CORRECT	- deletes entire array
	*/

	/*
	//Ask the user for the array dimensions
	cout << "How many array elements?\n";
	int elements;
	cin >> elements;

	Player * playerArray = new Player[elements];	//uses default constructor for objects
	cout << playerArray[0].getLives() << endl;
	delete[] playerArray;
	*/


	//new ... delete
	//new[] ... delete[]

	/*
	//Player p;	//gets deconstructed automatically when it goes out of scope	(created on the stack)
	Player* p = new Player(5);	//does not get deconstructed until we explicitly delete it	(created on the heap)

	cout << p->getLives() << endl;	//arrow operator (->) is used when we have a pointer to an object on the heap, the dot operator (.) is used when we have an instance

	delete p;	//if we dont delete p, then it will stay on the heap
	*/


	/*
	//Create an array of type Player on the heap.
	Player* playerArray = new Player[5];
	cout << playerArray[0].getLives();	//SAME...				//accessing specific instance of an object, so using dot operator
	cout << playerArray->getLives();	//...OUTPUT				//accessing a pointer to an object, so using arrow operator
	delete[] playerArray;
	*/

	/*
	//Create an array of type Player* (NB the *)
	//i.e. an array of pointers to type Player
	Player ** ptrPlayerArray = new Player * [5];
	ptrPlayerArray[0] = new Player(3);	//3 lives

	cout << ptrPlayerArray[0]->getLives() << endl;
	//cout << ptrPlayerArray[1]->getLives() << endl;	//crashes the program - we've only initialised the first pointer in the array!

	//delete[] ptrPlayerArray;	//only deletes the pointers, not the objects!

	//delete all the objects first, then delete the array!
	delete ptrPlayerArray[0];
	delete[] ptrPlayerArray;
	*/

	String myString("Gering-ding-ding-ding-dingeringeding!");
	cout << "What does the fox say?\n" << myString;	//will need to overload operator in string class for this to compile and work
}